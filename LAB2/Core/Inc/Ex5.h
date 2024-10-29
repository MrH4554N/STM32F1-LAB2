/*
 * Ex5.h
 *
 *  Created on: Oct 29, 2024
 *      Author: Admin
 */

#ifndef INC_EX5_H_
#define INC_EX5_H_

#include "main.h"
extern int index_led;
extern int hour, minute, second;

void DotToggle();
void update7SEG(int index);
void ClockBufferUpdate();

void Ex5Init();
void Ex5();

#endif /* INC_EX5_H_ */
