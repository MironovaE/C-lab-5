#define _CRT_SECURE_NO_WARNINGS
#include "task2.h"
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#define ITER 50
void clearMatrix(char(*arr)[M])	//заполнение двумерного массива (матрицы) пробелами 
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			arr[i][j] = ' ';
		}
		arr[i][N] = '\0';
	}
}

void fillMatrix(char(*arr)[M])	//заполнение верхнего левого квадранта матрицы звездочками 
{
	int h = N / 2;
	int w = N / 2;
	for (int i = 0, j = 0, iter = 0; iter < ITER; iter++)
	{
		i = rand() % w;
		j = rand() % h;
		arr[j][i] = '*';
	}
}

void setMatrix(char(*arr)[M])	//копирование элементов в другие области матрицы
{
	for (int i = 0; i < N / 2; i++)
	{
		for (int j = N - 1, x = 0; x < N / 2; j--, x++)
		{
			arr[i][j] = arr[i][x];
		}
	}
	for (int i = 0, j = N - 1; i < (N / 2); i++, j--)
	{
		strcpy(arr[j], arr[i]);
	}
}

void printMatrix(char(*arr)[M])	//печать матрицы
{
	for (int i = 0; i < N; i++)
	{
		printf("%s\n", arr[i]);
	}
}