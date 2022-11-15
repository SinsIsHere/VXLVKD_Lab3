/*
 * button.c
 *
 *  Created on: Nov 15, 2022
 *      Author: BIN
 */

#include "button.h"

int KeyReg0_MODE = NORMAL_STATE;
int KeyReg1_MODE = NORMAL_STATE;
int KeyReg2_MODE = NORMAL_STATE;
int KeyReg3_MODE = NORMAL_STATE;

int KeyReg0_TIME = NORMAL_STATE;
int KeyReg1_TIME = NORMAL_STATE;
int KeyReg2_TIME = NORMAL_STATE;
int KeyReg3_TIME = NORMAL_STATE;

int KeyReg0_SET = NORMAL_STATE;
int KeyReg1_SET = NORMAL_STATE;
int KeyReg2_SET = NORMAL_STATE;
int KeyReg3_SET = NORMAL_STATE;

int MODE_flag = 0;
int TIME_flag = 0;
int SET_flag = 0;

int MODE_PRESSED() {
	if (MODE_flag == 1) {
		MODE_flag = 0;
		return 1;
	}
	return 0;
}

int TIME_PRESSED() {
	if (TIME_flag == 1) {
		TIME_flag = 0;
		return 1;
	}
	return 0;
}

int SET_PRESSED() {
	if (SET_flag == 1) {
		SET_flag = 0;
		return 1;
	}
	return 0;
}





void getKeyInputMODE() {
	KeyReg0_MODE = KeyReg1_MODE;
	KeyReg1_MODE = KeyReg2_MODE;
	KeyReg2_MODE = HAL_GPIO_ReadPin(BUTTON_MODE_GPIO_Port, BUTTON_MODE_Pin);

	if ((KeyReg0_MODE == KeyReg1_MODE) && (KeyReg1_MODE == KeyReg2_MODE)) {
		if (KeyReg3_MODE != KeyReg2_MODE) {
			KeyReg3_MODE = KeyReg2_MODE;
			if (KeyReg2_MODE == NORMAL_STATE) {
				MODE_flag = 1;
			}
		}
	}
}

void getKeyInputTIME() {
	KeyReg0_TIME = KeyReg1_TIME;
	KeyReg1_TIME = KeyReg2_TIME;
	KeyReg2_TIME = HAL_GPIO_ReadPin(BUTTON_TIME_GPIO_Port, BUTTON_TIME_Pin);

	if ((KeyReg0_TIME == KeyReg1_TIME) && (KeyReg1_TIME == KeyReg2_TIME)) {
		if (KeyReg3_TIME != KeyReg2_TIME) {
			KeyReg3_TIME = KeyReg2_TIME;
			if (KeyReg2_TIME == NORMAL_STATE) {
				TIME_flag = 1;
			}
		}
	}
}

void getKeyInputSET() {
	KeyReg0_SET = KeyReg1_SET;
	KeyReg1_SET = KeyReg2_SET;
	KeyReg2_SET = HAL_GPIO_ReadPin(BUTTON_SET_GPIO_Port, BUTTON_SET_Pin);

	if ((KeyReg0_SET == KeyReg1_SET) && (KeyReg1_SET == KeyReg2_SET)) {
		if (KeyReg3_SET != KeyReg2_SET) {
			KeyReg3_SET = KeyReg2_SET;
			if (KeyReg2_SET == NORMAL_STATE) {
				SET_flag = 1;
			}
		}
	}
}
