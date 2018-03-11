#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS
#include "task3.h"
#define IN 1
#define OUT 0

char *mixChars(char *in, char *out)
{
	out[0] = 0;
	int i = 0, j = 0;   //счетчики
	int letters = 0;    //счетчик букв в слове 
	int k = 0;     //рандомна€ буква
	char tmp = NULL;
	while (in[letters] != ' ' && in[letters] != '\0')
	{
		letters++;
	}
	for (i = 0; i < letters; i++)
	{
		out[i] = in[i];
	}
	if (letters < 4)	//перва€ и последн€€ буква неизменны 
	{
		out[i] = '\0';
		return out;
	}
	else
	{
		letters--;
		do {
			for (j = 1; j < letters; j++)
			{
				k = rand() % letters;
				if (k == 0)
					k = 1;
				tmp = out[j];
				out[j] = out[k];
				out[k] = tmp;
			}
		} while (strcmp(in, out) == 0);
		out[i] = '\0';
		return out;
	}
}
char *mixLine(char *instr, char *outstr)
{
	*outstr =  0 ;
	int k = 0; // элемент массива
	int flag = OUT;

	if (instr[strlen(instr) - 1] == '\n')
		 instr[strlen(instr) - 1] = '\0';
	
	while (k < strlen(instr))
	{
		if (instr[k] != ' ' && flag == OUT)
		{
			flag = IN;
			mixChars(instr + k, outstr + k);
		}
		else if (instr[k] == ' ' && flag == IN)
		{
			flag = OUT;
			outstr[k] = ' ';
		}
		k++;
	}
	return outstr;
}
