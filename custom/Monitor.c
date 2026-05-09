#include "Monitor.h"
#include "fsl_debug_console.h"
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include "fsl_lpuart.h"

#define TERM_PORT_NUM	0	//Define the UART Port number that is to be the terminal

#define UART_RECIVE_INT_ON		TRUE
#define UART_RECIVE_INT_OFF		FALSE
#define UART_SEND_INT_ON		TRUE
#define UART_SEND_INT_OFF		FALSE


//////////////////////////////////////////////////////////////////////////////
//																			//
//						Uart Function Define									//
//																			//
//////////////////////////////////////////////////////////////////////////////

static UCHAR m_u8ReciveChar=0;
static CHAR m_szReciveBuf[MONITOR_LINE_MAX_LENGTH];
static UCHAR m_u8SpecialSimpleBuf[4];
static UINT m_u8ReciveCount=0;
static BOOL m_bLineOverflow = FALSE;
static BOOL m_bLastWasCr = FALSE;

#define MONITOR_RX_RING_BUFFER_SIZE 128U
static UCHAR s_u8RxRingBuffer[MONITOR_RX_RING_BUFFER_SIZE];
static volatile uint16_t s_u16RxRingHead = 0;
static volatile uint16_t s_u16RxRingTail = 0;
static volatile uint32_t s_u32RxOverflowCount = 0;

#define MAX_FUNCTION_LIST	200
static UINT uiMonitorListCount;
static PSMONITORCOMMAND sMonitorFunctionList[MAX_FUNCTION_LIST];


//////////////////////////////////////////////////////////////////////////////
//																			//
//						Extern Function List 									//
//																			//
//////////////////////////////////////////////////////////////////////////////

uint8_t demoRingBuffer[DEMO_RING_BUFFER_SIZE];
volatile uint16_t txIndex; /* Index of the data to send out. */
volatile uint16_t rxIndex; /* Index of the memory to save new arrived data. */


void DEMO_LPUART_IRQHandler(void)
{
    uint8_t data;

    /* If new data arrived. */
    if ((kLPUART_RxDataRegFullFlag)&LPUART_GetStatusFlags(DEMO_LPUART))
    {
        data = LPUART_ReadByte(DEMO_LPUART);

        uint16_t nextHead = (uint16_t)((s_u16RxRingHead + 1U) % MONITOR_RX_RING_BUFFER_SIZE);
        if (nextHead == s_u16RxRingTail)
        {
            s_u32RxOverflowCount++;
        }
        else
        {
            s_u8RxRingBuffer[s_u16RxRingHead] = data;
            s_u16RxRingHead = nextHead;
        }

    }

    SDK_ISR_EXIT_BARRIER;
}



extern SMONITORCOMMAND sMonitorFuncList[];

void MonitorInit(void)
{
	uiMonitorListCount = 0;
	m_u8ReciveCount = 0;
	m_bLineOverflow = FALSE;
	m_bLastWasCr = FALSE;
	m_szReciveBuf[0] = '\0';
	s_u16RxRingHead = 0;
	s_u16RxRingTail = 0;
	s_u32RxOverflowCount = 0;
	MonitorRegisterFunctions(sMonitorFuncList);
}

BOOL MonitorRegisterFunctions(PSMONITORCOMMAND psList )
{
 	// Check if there are still free enteries.
	if ( uiMonitorListCount ==MAX_FUNCTION_LIST )
	{
 	    // No more commands lists.
	    return FALSE;
	}

	// Add new commands list. From this point all commands from this list
	// are avaliable to the user.
	sMonitorFunctionList[ uiMonitorListCount++ ] = psList;
	
    return TRUE;
}

void UartSend(const char* str,int nLen)
{
	int i=0;
	for(i=0;i<nLen;i++)
	{
		PUTCHAR(str[i]);
	}
}

static BOOL MonitorPopRxByte(UCHAR *pCh)
{
    if (pCh == NULL)
    {
        return FALSE;
    }

    if (s_u16RxRingTail == s_u16RxRingHead)
    {
        return FALSE;
    }

    *pCh = s_u8RxRingBuffer[s_u16RxRingTail];
    s_u16RxRingTail = (uint16_t)((s_u16RxRingTail + 1U) % MONITOR_RX_RING_BUFFER_SIZE);

    return TRUE;
}

static void MonitorResetLine(void)
{
    m_u8ReciveCount = 0;
    m_bLineOverflow = FALSE;
    m_szReciveBuf[0] = '\0';
}

void MonitorProcess(void)
{
    UCHAR ch = 0;

    if (s_u32RxOverflowCount != 0U)
    {
        s_u32RxOverflowCount = 0;
        s_u16RxRingTail = s_u16RxRingHead;
        MonitorResetLine();
        UartSend("\r\nUART RX overflow.\r\n", 21);
    }

    while (MonitorPopRxByte(&ch))
    {
        UartReciveAndAck(ch);
    }
}


//////////////////////////////////////////////////////////////////////////////
//
//								function
//
//  							MonitorParseAndExec
//
//	desc
//
//  The function parses the input string and executes the command
//
//////////////////////////////////////////////////////////////////////////////

BOOL
MonitorParseAndExec(PCHAR szCommand,BOOL bRun)
{
	UINT i;

	BOOL bFound = FALSE;
	BOOL bCommandExist = FALSE;
	size_t argLen = 0;

	// Comand name string
	CHAR szName[64];
	CHAR szCommandName[64];

	// Gets the command name.
	if (szCommand == NULL || sscanf( szCommand, " %63s", szName ) != 1)
		{
		return FALSE;
		}
	// Search for the command in all lists.
	for ( i = 0; i < uiMonitorListCount && bFound == FALSE; i++ )
		{
		PSMONITORCOMMAND psCmd = sMonitorFunctionList[i];

		for ( psCmd = sMonitorFunctionList[i];
					psCmd->szName != NULL;
					psCmd++ )
			{
			if (sscanf( psCmd->szName, " %63s", szCommandName ) != 1)
				{
				continue;
				}

			// Search for command in list.
			if ( strcmp( szName, szCommandName ) == 0 )
				{
				bRun=TRUE;
				szCommand += strlen(szName);

				// Skip leading white-spaces
				while( *szCommand == ' ' || *szCommand == '\t' )
					{
					szCommand++;
					}

				// Remove trailing white-spaces
				argLen = strlen(szCommand);
				while( argLen > 0U && (szCommand[argLen - 1U] == ' ' || szCommand[argLen - 1U] == '\t' ||
						              szCommand[argLen - 1U] == '\r' || szCommand[argLen - 1U] == '\n') )
					{
					szCommand[--argLen] = '\0';
					}

				if(bRun && psCmd->fnFunction != NULL)
					{
					// Run command.
					psCmd->fnFunction( szCommand );
//					HostEventSet(PO_MOINTOR,EVENT_STATUS_COMPLETE);
					}

				// Command was found and run.
				bFound = TRUE;
				bCommandExist = TRUE;

				break;
				}
			else
				{
				bCommandExist =FALSE;
				}
			}
		}
	if(bCommandExist == FALSE)
		printf("No such command exist.\r\n");
	return bCommandExist;
}

void UartReciveAndAck(UCHAR ch)
{
	m_u8ReciveChar = ch;//GETCHAR();
	if(m_u8ReciveChar == '\n' && m_bLastWasCr)
		{
		m_bLastWasCr = FALSE;
		return;
		}
	m_bLastWasCr = (m_u8ReciveChar == '\r') ? TRUE : FALSE;

	if(m_u8ReciveChar == '\r' || m_u8ReciveChar == '\n')	// Press Enter
		{

		m_u8SpecialSimpleBuf[0] = '\r';
		m_u8SpecialSimpleBuf[1] = '\n';

//		uart_putchar(TERM_PORT_NUM, m_u8SpecialSimpleBuf[0]);  //Send the received character to terminal
//		uart_putchar(TERM_PORT_NUM, m_u8SpecialSimpleBuf[1]);  //Send the received character to terminal
		UartSend((const char*)m_u8SpecialSimpleBuf,2);
		if(m_bLineOverflow)
			{
			UartSend("Command too long.\r\n", 19);
			}
		else if(m_u8ReciveCount > 0)
			{
			m_szReciveBuf[m_u8ReciveCount] = '\0';
			MonitorParseAndExec(m_szReciveBuf,FALSE);
			}
		
		MonitorResetLine();
		}
	else if(m_u8ReciveChar == '\b' || m_u8ReciveChar == 0x7f)	// BackSpace
		{
		m_bLastWasCr = FALSE;
		if(m_u8ReciveCount == 0)
			{
//			UART_RECIVE(&m_u8ReciveChar,1);
			return;
			}
		m_u8ReciveCount--;
		m_szReciveBuf[m_u8ReciveCount] = '\0';
		m_u8SpecialSimpleBuf[0] = '\b';
		m_u8SpecialSimpleBuf[1] = ' ';
		m_u8SpecialSimpleBuf[2] = '\b';
		
		UartSend((const char*)m_u8SpecialSimpleBuf,3);
		}
	else		// Recive Char
		{
		m_bLastWasCr = FALSE;
		if(m_bLineOverflow)
			{
			return;
			}
		if(m_u8ReciveCount >= (MONITOR_LINE_MAX_LENGTH - 1U))
			{
			m_bLineOverflow = TRUE;
			return;
			}
		m_szReciveBuf[m_u8ReciveCount++] = (CHAR)m_u8ReciveChar;
		m_szReciveBuf[m_u8ReciveCount] = '\0';
		UartSend((const char*)&m_szReciveBuf[m_u8ReciveCount-1U],1);
		}
}



