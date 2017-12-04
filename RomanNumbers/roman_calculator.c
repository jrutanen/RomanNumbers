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

char convertIntToRoman(int nbr)
{
	char roman;
	switch (nbr)
	{
	case 1:
		roman = 'I';
		break;
	case 5:
		roman = 'V';
		break;
	case 10:
		roman = 'X';
		break;
	case 50:
		roman = 'L';
		break;
	case 100:
		roman = 'C';
		break;
	case 500:
		roman = 'D';
		break;
	case 1000:
		roman = 'M';
		break;
	default:
		break;
	}
	return roman;
}

void convertInt(int number, char* romanNumber, int buffersize)
{
	int romanValues[7] = { 1000, 500, 100, 50, 10, 5, 1 };
	int romanValuesCount[7] = { 0, 0, 0, 0, 0, 0, 0 };
	int index = 0;
	size_t nbrOfElements = sizeof(romanValues) / sizeof(romanValues[0]);
	int tempNbr = number;

	//calculate number of different roman numbers
	for (int i = 0; i < nbrOfElements; i++)
	{
		romanValuesCount[i] = tempNbr / romanValues[i];
		tempNbr -= romanValuesCount[i] * romanValues[i];
	}

	//create string for whole roman number
	for (int i = 0; i < nbrOfElements; i++)
	{
		//IV
		if (number % 5 == 4 && i == 6 && romanValuesCount[i + 1] != 0)
		{
			romanNumber[index] = 'I';
			index++;
			romanNumber[index] = 'V';
			index++;
			break;
		}
		//IX
		if (number % 10 == 9 && i == 5 && romanValuesCount[i + 1] != 0)
		{
			romanNumber[index] = 'I';
			index++;
			romanNumber[index] = 'X';
			index++;
			break;
		}
		//XC
		if (number % 100 >= 90 && i == 2 && romanValuesCount[i + 1] != 0)
		{
			romanNumber[index] = 'X';
			index++;
			romanNumber[index] = 'C';
			index++;
			romanValuesCount[i + 1] = 0;
			romanValuesCount[i + 2] = 0;
			continue;
		}
		//CM
		if (number % 1000 >= 10 && i == 0 && romanValuesCount[i + 1] != 0)
		{
			romanNumber[index] = 'C';
			index++;
			romanNumber[index] = 'M';
			index++;
			romanValuesCount[i + 1] = 0;
			romanValuesCount[i + 2] = 0;
			continue;
		}

		for (int j = 0; j < romanValuesCount[i]; j++)
		{
			romanNumber[index] = convertIntToRoman(romanValues[i]);
			index++;
		}
	}
	romanNumber[index] = '\0';
}

void readUserInput()
{
	
}