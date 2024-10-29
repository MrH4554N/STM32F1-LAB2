/*
 * Ex9.h
 *
 *  Created on: Oct 29, 2024
 *      Author: Admin
 */

#ifndef INC_EX9_H_
#define INC_EX9_H_

#include "main.h"
extern int index_led;
extern int hour, minute, second;
extern int index_led_matrix;

void DotToggle();
void update7SEG(int index);
void ClockBufferUpdate();
void LEDMatrixUpdate(int index);

void Ex5Init();
void Ex5();
#endif /* INC_EX9_H_ */
