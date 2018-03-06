#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include "task1.h"

#define IN 1
#define OUT 0
#define SIZE 100

char * randomWords(char * in, char *out)
{
	srand(time(0));
	int status = OUT;
	int i, j, k;
	int words = 0;
	char * pointers[SIZE], * swap;

	for (i = 0; in[i] != '\0'; i++)
	{
		if (!isspace(in[i]) && status == OUT)
		{
			status = IN;
			pointers[words] = &in[i];
			words++;
		}
		else if (isspace(in[i]) && status == IN)
			status = OUT;
	}

	for (i = 0, j = 0; i < words; i++)
	{
		j = (rand() % words - 1) + 1;
		if (j != i)
		{
			swap = pointers[i];
			pointers[i] = pointers[j];
			pointers[j] = swap;
		}
	}
	
	for (i = 0, j = 0; i < words; i++)
	{
		for (k = 0; !isspace(pointers[i][k]) && pointers[i][k] != '\0' && pointers[i][k] != '\n'; j++, k++)
			out[j] = pointers[i][k];
		out[j++] = ' ';
		out[j] = ' ';
	}

	out[j] = '\0';

	return out;
}
