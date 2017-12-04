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

void convertIntToRoman(int number, char* romanNumber, int buffersize)
{
	int one = 0;
	int five = 0;
	int ten = 0;
	int fifty = 0;
	int hundred = 0;
	int fivehundred = 0;
	int thousand = 0;

	int x = number;
	while (x > 0)
	{
		if (x / 1000 > 0)
		{
			thousand = x / 1000;
			x -= thousand * 1000;
			continue;
		}
		if (x / 500 > 0)
		{
			fivehundred = x / 500;
			x -= fivehundred * 500;
			continue;
		}
		if (x / 100 > 0)
		{
			hundred = x / 100;
			x -= hundred * 100;
			continue;
		}
		if (x / 50 > 0)
		{
			fifty = x / 50;
			x -= fifty * 50;
			continue;
		}
		if (x / 10 > 0)
		{
			ten = x / 10;
			x -= ten * 10;
			continue;
		}
		if (x / 5 > 0)
		{
			five = x / 5;
			x -= five * 5;
			continue;
		}
		one = x;
	}
}

void readUserInput()
{
	
}