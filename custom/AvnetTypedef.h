/*
 * AvnetTypedef.h
 *
 *  Created on: Nov 5, 2012
 *      Author: 914428
 */

#ifndef AVNETTYPEDEF_H_
#define AVNETTYPEDEF_H_

typedef char* PCHAR;
typedef char BOOL;
typedef char CHAR;
typedef unsigned char UCHAR;
typedef unsigned int UINT;


#define TRUE	1
#define FALSE	0

#define printf PRINTF

#define DEMO_LPUART            LPUART4
#define DEMO_LPUART_CLK_FREQ   CLOCK_GetLPFlexCommClkFreq(4u)
#define DEMO_LPUART_IRQn       LP_FLEXCOMM4_IRQn
#define DEMO_LPUART_IRQHandler LP_FLEXCOMM4_IRQHandler

#define DEMO_RING_BUFFER_SIZE 16

#endif /* AVNETTYPEDEF_H_ */
