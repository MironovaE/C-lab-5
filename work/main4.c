#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "task1.h"
#define _CRT_SECURE_NO_WARNINGS
#define N 128

int main() {
	FILE *fp, *inp;
	inp = fopen("reading.txt", "rt");
	fp = fopen("letter.txt", "wt");
	if (inp == NULL)
	{
		puts("File not found!");
		return 1;
	}
	char in[N][N] = { 0 };
	char out[N][N] = { 0 };
	char *str[N] = { 0 };
	int i = 0;
	while (fgets(in[i], N, inp))
	{
		str[i] = in + i;
		if (in[i][strlen(in[i]) - 1] == '\n')
			in[i][strlen(in[i]) - 1] = '\0';
		i++;
	}
	int j = i;
	for (int i = 0; i < j; i++)
	{
		randomWords(in[i], out[i]);
		fputs(out[i], fp);
		if (i < j - 1)
			fputs("\n", fp);
	}
	return 0;
}