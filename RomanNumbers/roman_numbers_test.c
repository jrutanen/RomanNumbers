/**
* \brief Tests to verifty the roman numbers functions
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
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "roman_calculator.h"
#include "ui.h"

///Test that the covertRoman function works as expected
static void test_convertRoman()
{
	char *testNumber = "VI";
	assert(convertRoman("VI") == 6);
	assert(convertRoman("IV") == 4);
	assert(convertRoman("IX") == 9);
	assert(convertRoman("XL") == 40);
	assert(convertRoman("LXXXIX") == 89);

	printf("test_convertRoman passed\n");
}

///Test that the covertRomanToInt function works as expected
static void test_convertRomanToInt()
{
	assert(convertRomanToInt('I') == 1);
	assert(convertRomanToInt('V') == 5);
	assert(convertRomanToInt('X') == 10);
	assert(convertRomanToInt('L') == 50);
	assert(convertRomanToInt('C') == 100);
	assert(convertRomanToInt('D') == 500);
	assert(convertRomanToInt('M') == 1000);
	printf("test_convertRomanToInt passed\n");
}

///Test that the covertIntToRoman function works as expected
static void test_convertIntToRoman()
{
	char result[100];
	//length of the string reserved for the roman number
	int maxLength = 100;
	result[99] = '\0';

	char * expectedResult = NULL;

	convertInt(6, maxLength, result);
	realloc(expectedResult, sizeof(char) * 100);
	expectedResult = "VI\0";
	assert(strcmp(expectedResult, result) == 0);
	convertInt(4, maxLength, result);
	expectedResult = "IV\0";
	assert(strcmp(expectedResult, result) == 0);
	convertInt(40, maxLength, result);
	expectedResult = "XL\0";
	assert(strcmp(expectedResult, result) == 0);
	convertInt(89, maxLength, result);
	expectedResult = "LXXXIX\0";
	assert(strcmp(expectedResult, result) == 0);
	convertInt(1593, maxLength, result);
	expectedResult = "MDXCIII\0";
	assert(strcmp(expectedResult, result) == 0);
	convertInt(199, maxLength, result);
	expectedResult = "CXCIX\0";
	assert(strcmp(expectedResult, result) == 0);
	convertInt(499, maxLength, result);
	expectedResult = "CDXCIX\0";
	assert(strcmp(expectedResult, result) == 0);
	
	printf("test_convertIntToRoman passed\n");	
}

static void test_isValidRomanNumber()
{
	char * input = NULL;
	realloc(input, sizeof(char) * 100);
	input = "ABC\0";
	assert(isValidRomanNumber(input) == false);
	input = "XIVCDMG\0";
	assert(isValidRomanNumber(input) == false);
	input = "XIVCDM\0";
	assert(isValidRomanNumber(input) == true);
	input = "MDCLXVI\0";
	assert(isValidRomanNumber(input) == true);
	input = "-IX\0";
	assert(isValidRomanNumber(input) == false);

	printf("test_isValidRomanNumber passed\n");
}
static void test_isValidOperator()
{
	char * input = NULL;
	realloc(input, sizeof(char) * 100);
	input = "+\0";
	assert(isValidOperator(input) == true);
	input = "-\0";
	assert(isValidOperator(input) == true);
	input = "*\0";
	assert(isValidOperator(input) == true);
	input = "/\0";
	assert(isValidOperator(input) == true);
	input = "^\0";
	assert(isValidOperator(input) == true);
	input = "%\0";
	assert(isValidOperator(input) == true);
	input = "x\0";
	assert(isValidOperator(input) == false);
	input = "**\0";
	assert(isValidOperator(input) == false);

	printf("test_isValidOperator passed\n");
}

static void test_checkInput()
{
	char * input = NULL;
	realloc(input, sizeof(char) * 100);
	input = "12 + IX\0";
	assert(checkInput(input) == false);
	input = "I - II\0";
	assert(checkInput(input) == true);
	input = "II * GX\0";
	assert(checkInput(input) == false);
	input = "IV / IV\0";
	assert(checkInput(input) == true);
	input = "IX^LX\0";
	assert(checkInput(input) == false);

	printf("test_checkInput passed\n");

}
int main() {
	test_convertRomanToInt();
	test_convertRoman();
	test_convertIntToRoman();
	test_isValidOperator();
	test_isValidRomanNumber();
	test_checkInput();
}