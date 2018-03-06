#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "task2.h"

#define M 24

void clearMatrix(char (* arr)[M])
{
	int i, j;
	for (i = 0; i < M; i++)
		for (j = 0; j < M; j++)
			arr[i][j] = ' ';
}

void fillMatrix(char (* arr)[M])
{
	int i, j;
	srand(time(NULL));
	for (i = 0; i < M / 2; i++)
		for (j = 0; j < M / 2; j++)
		{
			if (rand() % 2)
				arr[i][j] = '*';
		}
}

void setMatrix(char (* arr)[M])
{
	int i, j, k, l;
	for (i = 0, l = (M / 2 - 1); i < M / 2; i++, l--)
	{
		for (j = 0, k = (M / 2 - 1); j < M / 2; j++, k--)
		{
			arr[i][k + M / 2] = arr[i][j]; //right top 
			arr[l + M / 2][j] = arr[i][j]; //left bottom 
			arr[l + M / 2][k + M / 2] = arr[i][j]; //right bottom
		}
	}
}

void printMatrix(char(*arr)[M])
{
	int i, j;
	for (i = 0; i < M; i++)
	{
		for (j = 0; j < M; j++)
		{
			putchar(arr[i][j]);
			putchar('.');
		}
			putchar('\n');
	}
}