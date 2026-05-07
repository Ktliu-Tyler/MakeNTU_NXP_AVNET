/*
 * servo.h — Dual servo driver (GPIO software PWM)
 *
 * Active outputs:
 *   Pitch servo -> P1_12
 *   Yaw servo   -> P1_13
 */

#ifndef _SERVO_H_
#define _SERVO_H_

#include <stdint.h>

void Servo_Init(void);
void Servo_SetPitch(uint32_t angle);   /* 0 – 180 degrees */
void Servo_SetYaw  (uint32_t angle);   /* 0 – 180 degrees */

#endif /* _SERVO_H_ */
