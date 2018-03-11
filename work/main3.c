#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "task3.h"
#define _CRT_SECURE_NO_WARNINGS
#define N 100

int main()
{
	char instr[N] = { 0 };
	char outstr[N] = { 0 };

	FILE *fp, *in;
	in = fopen("reading.txt", "rt");
	fp = fopen("letter.txt", "wt");
	if (in == NULL)
	{
		puts("File not found!\n");
		return 1;
	}

	while (fgets(instr, N, in) != NULL)
	fprintf(fp, "%s\n", mixLine(instr, outstr));

	return 0;
}