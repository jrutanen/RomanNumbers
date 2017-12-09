/**
* \brief Functions to convert roman numbers to arabic numbers
*        and vice versa
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

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "roman_calculator.h"

int convertRomanToInt(char romanNbr)
{
	int decimal = 0;
	char roman = toupper(romanNbr);
	switch (romanNbr)
	{
	case 'I':
		decimal = 1;
		break;
	case 'V':
		decimal = 5;
		break;
	case 'X':
		decimal = 10;
		break;
	case 'L':
		decimal = 50;
		break;
	case 'C':
		decimal = 100;
		break;
	case 'D':
		decimal = 500;
		break;
	case 'M':
		decimal = 1000;
		break;
	default:
		break;
	}
	return decimal;
}

int convertRoman(char* romanNumber)
{
	int number = 0;
	int a = 0;
	int b = 0;
	int numberLenght = strlen(romanNumber) - 1;
	for (int i = numberLenght; i >= 0; i--)
	{
		a = convertRomanToInt(romanNumber[i]);
		if (i < numberLenght)
		{
			b = convertRomanToInt(romanNumber[i + 1]);
		}
		if (b > a)
		{
			a = -a;
		}
		number += a;
	}
	return number;
}

void convertInt(int number, int maxSize, char *romanNumber)
{
	//initilize string
	romanNumber[0] = '\0';

	//calculate number of different roman numbers
	//create string for whole roman number
	int destBufferSize = maxSize;

	if (number / 1000 > 0)
	{
		strcat_s(romanNumber, destBufferSize, romanNumbers[number / 1000][0]);
		number -= (number / 1000) * 1000;
	}
	if (number / 100 > 0)
	{
		strcat_s(romanNumber, destBufferSize, romanNumbers[number / 100][1]);
		number -= (number / 100) * 100;
	}
	if (number / 10 > 0)
	{
		strcat_s(romanNumber, destBufferSize, romanNumbers[number / 10][2]);
		number -= (number / 10) * 10;
	}
	if (number > 0)
	{
		strcat_s(romanNumber, destBufferSize, romanNumbers[number][3]);
	}
}

int calculateResult(int numberOne, int numberTwo, char operator)
{
	switch (operator)
	{
		case '+':
			return (numberOne + numberTwo);
		case '-':
			return (numberOne - numberTwo);
		case '*':
			return (numberOne * numberTwo);
		case '/':
			return (numberOne / numberTwo);
		case '^':
			return (numberOne ^ numberTwo);
		case '%':
			return (numberOne % numberTwo);
		default:
			break;
	}
	return 0;
}

void calculate(char* numberOne, char* numberTwo, char operator, char* result)
{
	//initilize result string to empty string
	result[0] = '\0';
	int maxSize = 100;
	int calcResult = calculateResult(convertRoman(numberOne), convertRoman(numberTwo), operator);
//	char *resultInRoman;
//	resultInRoman = malloc(sizeOf(resultInRoman[0]) * 100);
	convertInt(calcResult, maxSize, result);
//	strcpy_s(result, 99 * sizeof(char), resultInRoman);
}