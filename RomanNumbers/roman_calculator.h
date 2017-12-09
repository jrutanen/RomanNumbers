/**
* \brief Tests to verify the roman numbers functions
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
#ifndef ROMAN_CALCULATOR_H
#define ROMAN_CALCULATOR_H

#include <stdbool.h>

///Table to contain the roman numbers for different arabic values
static char * romanNumbers[10][4] = {
	// x10^3     x10^2     x10       x1
	{ '\0',     '\0',     '\0',     '\0'     }, //0
	{ "M\0",    "C\0",    "X\0",    "I\0"    }, //1
	{ "MM\0",   "CC\0",   "XX\0",   "II\0"   }, //2
	{ "MMM\0",  "CCC\0",  "XXX\0",  "III\0"  }, //3
	{ "MMMM\0", "CD\0",   "XL\0",   "IV\0"   }, //4
	{ '\0',     "D\0",    "L\0",    "V\0"    }, //5
	{ '\0',     "DC\0",   "LX\0",   "VI\0"   }, //6
	{ '\0',     "DCC\0",  "LXX\0",  "VII\0"  }, //7
	{ '\0',     "DCCC\0", "LXXX\0", "VIII\0" }, //8
	{ '\0',     "CM\0",   "XC\0",   "IX\0"   }  //9
};

/**
* Converts single roman numeral to arabic numeral
*
* @param[in]  char	romanNumber single roman numeral
* \return     int	arabic value of the roman numeral
*/
int convertRomanToInt(char romanNbr);


/**
* Converts roman number to arabic number
*
* @param[in]  char*	romanNumber as a string
* \return     int	arabic value of the roman number
*/
int convertRoman(char* romanNumber);

/**
* Converts arabic number to a roman number
*
* @param[out]  char*	romanNumber string for the romanNumber
* @param[in]   int   	number      arabic number to be converted
* @param[in]   int   	maxSize     max length of the  romanNumber string
*/
void convertInt(int number, int maxSize, char* romanNumber);

/**
* reads two roman numbers as user input
*
* @param[out] int*	numberOne
* @param[out] int*  numberTwo
* @param[out] char* operator, operation user wants to perform (*, /, +, -)
*/
void readUserInput(int* numberOne, int* numberTwo, char* operator);

/**
* reads two roman numbers as user input
*
* @param[out] char*	operator, operation to perform (*, /, +, -)
* @param[in]  int	numberOne
* @param[in]  int   numberTwo
* \return     int   result of the calculation
*/
int calculateResult(int numberOne, int numberTwo, char* operator);

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

#endif //ROMAN_CALCULATOR_H