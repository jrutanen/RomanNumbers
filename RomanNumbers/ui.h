/**
* \brief Functions to handle user input and output for Roman calculator
*
* \author (last to touch it) $Author: Jani $
*
* \version $Revision: 0.1 $
*
* \date $Date: 2017/12/09 $
*
* Contact: https://github.com/jrutanen
*
* Created on: Sat Dec 9 2017
*/
#pragma once
#ifndef UI_H
#define UI_H

#include <stdbool.h>

/**
* reads two roman numbers as user input
*
* @param[out] int*	numberOne
* @param[out] int*  numberTwo
* @param[out] char* operator, operation user wants to perform (*, /, +, -)
*/
void readUserInput(char* numberOne, char* numberTwo, char* operator);

/**
* Displays result on the screen
*
* @param[in] char*	result
*/
void displayResult(char* result);


/**
* Control validity of the user input. Input needs to be in following format:
* <romanNumber> <operator> <romanNumber>
* Function checks valid letters for roman numbers and checks that the operator
* is valid (*, /, +, -, ^, %)
*
* @param[in]  char*	user input
* \return     bool  True if input is valid, false otherwise
*/
bool checkInput(char* userInput);

/**
* * Function checks valid letters for the operator (*, /, +, -, ^, %)
*
* @param[in]  char*	user input
* \return     bool  True if input is valid, false otherwise
*/
bool isValidOperator(char * operator);

/**
* * Function checks valid letters for the roman number (I, V, X, L, C, D, M)
*
* @param[in]  char*	user input
* \return     bool  True if input is valid, false otherwise
*/
bool isValidRomanNumber(char* romanNumber);

#endif //UI_H