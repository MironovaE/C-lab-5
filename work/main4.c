#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include "task1.h"

#define LENGHT 3000

int main()
{
	srand(time(NULL));
	char stin[LENGHT] = { '\0' };
	char stout[LENGHT] = { '\0' };

	FILE * fin = fopen("in.txt", "r");
	FILE * fout = fopen("out.txt", "w+");
	if (fin == NULL || fout == NULL)
	{
		puts("The files openning is failed!\n");
		return 1;
	}
	else
	{
		while (fgets(stin, LENGHT, fin) != NULL)
			fprintf(fout, "%s\n", randomWords(stin, stout));
		fclose(fin);
		fclose(fout);
	}
	return 0;
}