#include <stdio.h>
#include <stdlib.h>		/*Included the necessary libraries*/
#include <string.h>
#include <ctype.h>

float pop(char userString,float number2,float number1); /*The prototype for the pop function is included*/

int main(int argc, char *argv[]) /*argc and argv are included so you can perform command line input*/
{
	int i;	/*Declared necessary variables*/
	int j = 0;
	char * userString; 
	float stack[100];
	userString = argv[1];
	int stringCount = strlen(userString);
	for(i=0;i<stringCount;i++) /*For loop performs for the size of the string*/
	{							/*If it is a digit, store in the stack. If not, perform the pop function*/
		if(isdigit(userString[i])) 
		{
			stack[j]= userString[i] - '0'; /*Gets rid of the ASCII value*/
			j++;
		}
		else
		{
			stack[j-2] = pop(userString[i],stack[j-1],stack[j-2]);
			j--;
		}
	}
	for(i=0;i<j;i++) /*for loop is performed to print out the stack to two decimal points*/
	{
		printf("%.2f",stack[i]);
	}
	printf("\n");
	return 0;
}

float pop(char userString,float number2,float number1)
{
	float temp;
	if(userString == '-') /*The pop function goes through and performs operations of the two previous numbers depending on what symbol was inputted*/
	{
		temp = number1-number2;

	}
	else if(userString == '+')
	{
		temp = number1+number2;
	}
	else if(userString == '*')
	{
		temp = number1*number2;
	}
	else if(userString == '/')
	{
		temp = number1/number2;
	}
	return temp; /*Return the value of the operation on the two numbers*/
}
