#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "task3.h"

#define SIZE 5000

int main()
{
	char stin[SIZE] = { '\0' };
	char stout[SIZE] = { '\0' };

	srand(time(NULL));

	FILE *fin = fopen("in.txt", "r");
	FILE *fout = fopen("out.txt", "w");

	if (fin == NULL || fout == NULL)
		puts("The files opening is failed!");
	else
	{
		while (fgets(stin, SIZE, fin) != NULL)
			fprintf(fout, "%s\n", mixLine(stin, stout));
		fclose(fin);
		fclose(fout);
		puts("Success!\n");
	}
	return 0;
}