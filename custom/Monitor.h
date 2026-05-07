#ifndef ___WAYNE__UART__FUNCTION___
#define  ___WAYNE__UART__FUNCTION___

#include "AvnetTypedef.h"

#define MONITOR_LINE_MAX_LENGTH 	32

///////////////////////////////////////////////////////////////////////////////
// Monitor command structure.
///////////////////////////////////////////////////////////////////////////////

typedef struct tasgSMONITORCOMMAND
{
    // The command name.
    PCHAR szName;

    // Command arguments list.
    PCHAR szArgumentList;

    // Command help
    PCHAR szHelp;

    // The command callback function
    void  (*fnFunction)(PCHAR szArguments);

} SMONITORCOMMAND, *PSMONITORCOMMAND;


void MonitorInit(void);
void UartReciveAndAck(UCHAR ch);
BOOL MonitorRegisterFunctions(PSMONITORCOMMAND psList);

#endif


