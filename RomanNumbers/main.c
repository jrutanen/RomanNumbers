/**
* \brief Main function for the roman calculator application
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
#include <stdlib.h>
#include "ui.h"
#include "roman_calculator.h"

int main() {
	while(true)
	{
		char *firstNbr;
		firstNbr = malloc(sizeof(firstNbr[0]) * 100);
		char *secondNbr;
		secondNbr = malloc(sizeof(secondNbr[0]) * 100);
		char *operator;
		operator = malloc(sizeof(char) * 2);
		char *result;
		result = malloc(sizeof(result[0]) * 100);

		//Ask for user input
  		readUserInput(firstNbr, secondNbr, operator);
		calculate(firstNbr, secondNbr, operator[0], result);
		displayResult(result);

		free(firstNbr);
		free(secondNbr);
		free(operator);
		free(result);
	}
}