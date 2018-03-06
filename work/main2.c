#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "task2.h"

#define M 24

int main()
{
	char kaleidoscope[M][M] = { '\0' };
	clock_t now;

	while (1) 
	{
		clearMatrix(kaleidoscope);
		fillMatrix(kaleidoscope);
		setMatrix(kaleidoscope);
		system("cls");
		printMatrix(kaleidoscope);
		
		now = clock();
		while (clock() < (now + CLOCKS_PER_SEC));
	}

	return 0;
}