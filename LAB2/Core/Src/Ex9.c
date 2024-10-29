/*
 * Ex1.c
 *
 *  Created on: Oct 28, 2024
 *      Author: Admin
 */


#include "Ex9.h"

#define DIGIT0 0
#define DIGIT1 1
#define DIGIT2 2
#define DIGIT3 3

int status;
const int MAX_LED = 4;
int index_led = 0;
int index_led_matrix = 0;
int led_buffer[4] = {0,1,2,3};
int hour, minute, second;
uint8_t matrix_buffer [8] = {0x00, 0xFC, 0xFE, 0x33,0x33, 0xFE, 0xFC, 0x00};
void SegLedDisplay(int num){
	switch(num){
			case 0:
				HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, RESET);
				HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, RESET);
				HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, RESET);
				HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, RESET);
				HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, RESET);
				HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, RESET);
				HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, SET);
				break;
			case 1:
				HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, SET);
				HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, RESET);
				HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, RESET);
				HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, SET);
				HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, SET);
				HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, SET);
				HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, SET);
				break;
			case 2:
				HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, RESET);
				HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, RESET);
				HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, SET);
				HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, RESET);
				HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, RESET);
				HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, SET);
				HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, RESET);
				break;
			case 3:
				HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, RESET);
				HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, RESET);
				HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, RESET);
				HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, RESET);
				HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, SET);
				HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, SET);
				HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, RESET);
				break;
			case 4:
				HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, SET);
				HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, RESET);
				HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, RESET);
				HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, SET);
				HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, SET);
				HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, RESET);
				HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, RESET);
				break;
			case 5:
				HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, RESET);
				HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, SET);
				HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, RESET);
				HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, RESET);
				HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, SET);
				HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, RESET);
				HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, RESET);
				break;
			case 6:
				HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, RESET);
				HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, SET);
				HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, RESET);
				HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, RESET);
				HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, RESET);
				HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, RESET);
				HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, RESET);
				break;
			case 7:
				HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, RESET);
				HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, RESET);
				HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, RESET);
				HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, SET);
				HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, SET);
				HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, SET);
				HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, SET);
				break;
			case 8:
				HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, RESET);
				HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, RESET);
				HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, RESET);
				HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, RESET);
				HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, RESET);
				HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, RESET);
				HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, RESET);
				break;
			case 9:
				HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, RESET);
				HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, RESET);
				HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, RESET);
				HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, RESET);
				HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, SET);
				HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, RESET);
				HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, RESET);
			case 11:
				HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin,	SET);
				HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, SET);
				HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, SET);
				HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, SET);
				HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, SET);
				HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, SET);
				HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, SET);
	}
}

void Ex5Init(){
	hour = 15;
	minute = 8;
	second = 50;
}

void DotToggle(){
	HAL_GPIO_TogglePin(DOT_GPIO_Port, DOT_Pin);
}

void clear7SEG(){
	HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
	HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
	HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
	HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, SET);
}
void update7SEG(int index){
	switch (index) {
		case 0:
			clear7SEG();
			SegLedDisplay(led_buffer[index]);
			HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, RESET);

			break;
		case 1:

			clear7SEG();
			SegLedDisplay(led_buffer[index]);
			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, RESET);
			break;
		case 2:
			clear7SEG();
			SegLedDisplay(led_buffer[index]);
			HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, RESET);

			break;
		case 3:
			clear7SEG();
			SegLedDisplay(led_buffer[index]);
			HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, RESET);

			break;

	}
}
void ClockBufferUpdate(){
	if ((0 <= hour) && (hour <= 9)){
		led_buffer[0] = 0;
		led_buffer[1] = hour;
	}
	else {
		led_buffer[0] = hour / 10;
		led_buffer[1] = hour % 10;
	}
	if ((0 <= minute) && (minute <= 9)){
		led_buffer[2] = 0;
		led_buffer[3] = minute;
	}
	else {
		led_buffer[2] = minute / 10;
		led_buffer[3] = minute % 10;
	}

}

void decodeLed(uint8_t _8bit_led_){
	uint16_t ROW[8] = {ROW0_Pin, ROW1_Pin, ROW2_Pin, ROW3_Pin,
						ROW4_Pin, ROW5_Pin, ROW6_Pin, ROW7_Pin };
	for (int i = 0; i < 8; ++i){
		if((_8bit_led_) & (1 << (i))){
			HAL_GPIO_WritePin(ROW0_GPIO_Port, ROW[i], RESET);
		}
		else {
			HAL_GPIO_WritePin(ROW0_GPIO_Port, ROW[i], SET);
		}
	}
}
void LEDMatrixUpdate(int index){
	HAL_GPIO_WritePin(ENM0_GPIO_Port, ENM0_Pin | ENM1_Pin | ENM2_Pin | ENM3_Pin
							|ENM4_Pin | ENM5_Pin | ENM6_Pin | ENM7_Pin	, SET);
    decodeLed(matrix_buffer[index]);
    switch (index) {
        case 0:
            HAL_GPIO_WritePin(ENM0_GPIO_Port, ENM0_Pin, RESET);
            break;
        case 1:
        	HAL_GPIO_WritePin(ENM1_GPIO_Port, ENM1_Pin, RESET);
            break;
        case 2:
        	HAL_GPIO_WritePin(ENM2_GPIO_Port, ENM2_Pin, RESET);
            break;
        case 3:
        	HAL_GPIO_WritePin(ENM3_GPIO_Port, ENM3_Pin, RESET);
            break;
        case 4:
        	HAL_GPIO_WritePin(ENM4_GPIO_Port, ENM4_Pin, RESET);
            break;
        case 5:
        	HAL_GPIO_WritePin(ENM5_GPIO_Port, ENM5_Pin, RESET);
            break;
        case 6:
        	HAL_GPIO_WritePin(ENM6_GPIO_Port, ENM6_Pin, RESET);
            break;
        case 7:
        	HAL_GPIO_WritePin(ENM7_GPIO_Port, ENM7_Pin, RESET);
            break;
        default:
            break;
    }
}


void Ex5(){
	second++;
	if (second >= 60){
		second = 0;
		minute++;
	}
	if (minute >= 60){
		minute = 0;
		hour++;
	}
	if (hour >= 24){
		hour = 0;
	}
	ClockBufferUpdate();
}
