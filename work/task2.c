#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "task2.h"

void wait(int sec)
{
	clock_t now;
	now = clock() + sec * CLOCKS_PER_SEC;
	while (clock() < now) {}
}

void clrScr()
{
	for (int i = 0; i<30; i++)
		printf("\n");
}

void clearMatrix(char(*arr)[M])
{
	for (int i = 0; i < M; i++)
		for (int j = 0; j < M; j++)
			arr[i][j] = ' ';
}

void fillMatrix(char(*arr)[M])
{
	srand(time(0));
	int count = (M*M) / 8, k=0;

	for (int k = 0; k < count-1; k++)
	{
		int i=rand() % (M/2);
		int j = rand() % (M/2);
		arr[i][j] = '*';
	}
}
	
void setMatrix(char(*arr)[M])
{
	for (int i = 0; i < M / 2; i++)    
		for (int j = M / 2; j < M; j++)
			arr[i][j] = arr[i][M - j - 1];

	for (int i = M / 2; i < M; i++)    
		for (int j = 0; j < M; j++)
			arr[i][j] = arr[M - i - 1][j];

}

void printMatrix(char(*arr)[M])
{
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < M; j++)
			printf("%c", arr[i][j]);
		printf("\n");
	}
}
