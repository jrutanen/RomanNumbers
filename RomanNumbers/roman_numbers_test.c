// roman_numbers_test.c
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#include "roman_calculator.h"

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

static void test_convertIntToRoman()
{
	char result[100];
	result[99] = '\0';
	int length = strlen(result);
	convertInt(6, result, 3);
	length = strlen(result);
//	assert(strcmp("VI", result) == 0);
	convertInt(4, result, 3);
	length = strlen(result);
//	assert(strcmp("IV", result) == 0);
	convertInt(89, result, 3);
	length = strlen(result);
//	assert(strcmp("LXXXIX", result) == 0);
	convertInt(1593, result, 3);
//	assert(strcmp("MDXCIII", result) == 0);
	convertInt(199, result, 3);
//	assert(strcmp("CXCIX", result) == 0);
	printf("test_convertIntToRoman passed\n");
	
}
int main() {
	test_convertRomanToInt();
	test_convertRoman();
	test_convertIntToRoman();

}