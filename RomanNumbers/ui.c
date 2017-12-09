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
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "ui.h"

void readUserInput(char* numberOne, char* numberTwo, char* operator)
{
	printf("This is calculator for Roman values. Give value 1 operator and value 2.\n");
	printf("For example: IV + V or V * V, you need to have space between the value and the operator\n");
	char userInput[100];

	bool validInput = false;

	while (!validInput)
	{
		printf("Calculation: ");
		fgets(userInput, 100, stdin);
		//remove \n from the end of the string
		userInput[strlen(userInput) - 1] = '\0';
		validInput = checkInput(userInput);
	}

	//valid input received, write values to memory
	//initilize strings to empty string
	numberOne[0] = '\0';
	numberTwo[0] = '\0';
	operator[0] = '\0';
	char *input = NULL;
	char *nextValue = NULL;
	char whitespace[] = { ' ' };
	input = strtok_s(userInput, whitespace, &nextValue);
	int index = 0;
	while (input != NULL)
	{
		switch (index)
		{
			case 0:
				strcpy_s(numberOne, 99 * sizeof(char), input);
				break;
			case 1:
				strcpy_s(operator, 2 * sizeof(char), input);
				break;
			case 2:
				strcpy_s(numberTwo, 99 * sizeof(char), input);
				break;
		}
		input = strtok_s(NULL, whitespace, &nextValue);
		index++;
	}
}

void displayResult(char * result)
{
	printf("Result is: %s\n", result);
}

bool checkInput(char * userInput)
{
	char *input = NULL;
	char *nextInput = NULL;
	char whitespace[] = { ' ' };
	char tempInput[100];
	//copy user input (immutable) to local string
	strcpy_s(tempInput, 100 * sizeof(char), userInput);

	//go through values separated by white spaces and check that
	//they match the expected values
	input = strtok_s(tempInput, whitespace, &nextInput);
	
	int indexOfInput = 0;
	while (input != NULL)
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
		input = strtok_s(NULL, whitespace, &nextInput);
		indexOfInput++;
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
