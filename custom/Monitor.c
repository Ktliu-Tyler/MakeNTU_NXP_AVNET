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
static UCHAR m_u8ReciveCount=0;

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

        UartReciveAndAck(data);

    }

    SDK_ISR_EXIT_BARRIER;
}



extern SMONITORCOMMAND sMonitorFuncList[];

void MonitorInit(void)
{
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

void UartSend(char* str,int nLen)
{
	int i=0;
	for(i=0;i<nLen;i++)
	{
		PUTCHAR(str[i]);
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

	// Comand name string
	CHAR szName[64];
	CHAR szCommandName[64];

	// Gets the command name.
	sscanf( szCommand, "%s", szName );
	// Search for the command in all lists.
	for ( i = 0; i < uiMonitorListCount && bFound == FALSE; i++ )
		{
		PSMONITORCOMMAND psCmd = sMonitorFunctionList[i];

		for ( psCmd = sMonitorFunctionList[i];
					psCmd->szName != NULL;
					psCmd++ )
			{
			sscanf( psCmd->szName, "%s", szCommandName );

			// Search for command in list.
			if ( strcmp( szName, szCommandName ) == 0 )
				{
				PCHAR szCommandEnd;
				bRun=TRUE;
				szCommand += strlen(szName);

				// Skip leading white-spaces
				while( *szCommand == ' ' || *szCommand == '\t' )
					{
					szCommand++;
					}

				szCommandEnd = szCommand + strlen(szCommand) - 1;

				// Remove trailing white-spaces
				while( *szCommandEnd == ' ' || *szCommandEnd == '\t' )
					{
					// Did we reach the beginning of the string?
					if ( szCommandEnd <= szCommand )
						{
						break;
						}

					*szCommandEnd = '\0';
					szCommandEnd--;
					}

				if(bRun)
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
	if(m_u8ReciveChar == 0x0d)	// Press Enter
		{

		if(m_u8ReciveCount > 0)
			{
			m_szReciveBuf[m_u8ReciveCount++] = '\0';
			m_szReciveBuf[m_u8ReciveCount++] = '\r';
			m_szReciveBuf[m_u8ReciveCount++] = '\n';
			}
		m_u8SpecialSimpleBuf[0] = '\r';
		m_u8SpecialSimpleBuf[1] = '\n';

//		uart_putchar(TERM_PORT_NUM, m_u8SpecialSimpleBuf[0]);  //Send the received character to terminal
//		uart_putchar(TERM_PORT_NUM, m_u8SpecialSimpleBuf[1]);  //Send the received character to terminal
		UartSend((char*)m_u8SpecialSimpleBuf,2);
		if(m_u8ReciveCount > 0)
			{
			MonitorParseAndExec(m_szReciveBuf,FALSE);
			}
		
		m_u8ReciveCount =0;
		}
	else if(m_u8ReciveChar == '\b')	// BackSpace
		{
		if(m_u8ReciveCount == 0)
			{
//			UART_RECIVE(&m_u8ReciveChar,1);
			return;
			}
		if(m_u8ReciveCount == 0)
			m_szReciveBuf[m_u8ReciveCount] = '\0';
		else
			m_szReciveBuf[m_u8ReciveCount--] = '\0';		
		m_u8SpecialSimpleBuf[0] ='\b';
		m_u8SpecialSimpleBuf[1] = ' ';
		m_u8SpecialSimpleBuf[3] = '\b';
		m_u8SpecialSimpleBuf[4] = '\b';
		
		UartSend((char*)m_u8SpecialSimpleBuf,4);
		}
	else		// Recive Char
		{
		m_szReciveBuf[m_u8ReciveCount++] = (CHAR)m_u8ReciveChar;
		m_szReciveBuf[m_u8ReciveCount] = '\0';
		UartSend((char*)&m_szReciveBuf[m_u8ReciveCount-1],1);
		}
}



