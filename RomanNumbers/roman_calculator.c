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

void convertInt(int number, int maxSize, char* romanNumber)
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

void readUserInput(int* numberOne, int* numberTwo, char* operator)
{
	printf("This is calculator for Roman values. Give value 1 operator and value 2.\n");
	printf("For example: IV + V or V * V\n");
	char userInput[100];

	bool validInput = false;

	while(!validInput)
	{
		printf("For example: IV + V or V * V\n");
		gets(userInput);
		validInput = checkInput(userInput);
	}
}

int calculateResult(int numberOne, int numberTwo, char* operator)
{

}

bool checkInput(char * userInput)
{
	char * input;
	char **context = NULL;
	input = strtok_s(userInput, ' ', context);
	int indexOfInput = 0;
	while(input != NULL)
	{
		//second value should be operator
		if (indexOfInput == 1)
		{
			if (!isValidOperator(input))
			{
				return false;
			}
		}
		//first and third values should be roman numbers
		else
		{
			if (!isValidRomanNumber(input))
			{
				return false;
			}
		}
	}
	return true;
}

bool isValidRomanNumber(char * romanNumber)
{
	int numberLength = strlen(romanNumber);

	for (int i = 0; i < numberLength; i++)
	{
		if (romanNumber[i] == 'I' || romanNumber[i] == 'V' || romanNumber[i] == 'X' \
			|| romanNumber[i] == 'L' || romanNumber[i] == 'C' || romanNumber[i] == 'D' \
			|| romanNumber[i] == 'M')
		{
			//do nothing
		}
		else
		{
			return false;
		}
	}
	return true;
}

bool isValidOperator(char * operator)
{
	if (strlen(operator) > 1)
	{
		return false;
	}

    if (operator[0] == '+' || operator[0] == '-' || operator[0] == '/' \
	    || operator[0] == '*' || operator[0] == '^' || operator[0] == '%')
	{
		return true;
	}
	return false;
}
