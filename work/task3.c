#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include "task3.h"

#define IN 1
#define OUT 0
#define N 50

char * mixLine(char * instr, char * outstr)
{
	int i, j, k, size, wsize, status;
	char word[N] = { '\0' };
	char wrod[N] = { '\0' };
	int entry, letters;

	size = strlen(instr);

	for (i = 0, j = 0, letters = 0, status = OUT; i <= size; i++)
	{
		if (isalpha(instr[i]) && status == OUT)
		{
			status = IN;
			word[letters] = instr[i];
			entry = i;
			letters++;
		}
		else if (isalpha(instr[i]) && status == IN)
		{
			word[letters] = instr[i];
			letters++;
		}
		else if (!isalpha(instr[i]) && status == IN)
		{
			status = OUT;
			mixChars(word, wrod);
			wsize = strlen(wrod);

			for (j = entry, k = 0; k < wsize; j++, k++)
				outstr[j] = wrod[k];

			for (k = 0; k <= wsize; k++)
				word[k] = wrod[k] = '\0';
			letters = 0;
		}
		if (!isalpha(instr[i]) && status == OUT)
		{
			outstr[j] = instr[i];
			j++;
		}
	}
	outstr[j] = '\0';
	return outstr;
}

char *mixChars(char *in, char *out)
{
	char swap;
	int i, charnum;
	int size = strlen(in);
	for (i = 0; i <= size; i++)
		out[i] = in[i];

	if (size <= 3)
		return out;

	for (i = 1; i < size - 1; i++)
	{
		charnum = rand() % (size - 2) + 1;
		swap = out[i];
		out[i] = out[charnum];
		out[charnum] = swap;
	}
	return out;
}