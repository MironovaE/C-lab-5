#include "task2.h"
#include <stdio.h>
#include <stdlib.h>  //��� rand()
#define SPACE ' '

void clearMatrix(char(*arr)[M]) // ������� ������� (���������� ������� ���������)
{
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			arr[i][j] = SPACE;
}

void fillMatrix(char(*arr)[M])  // ���������� �������� ������ ��������� ������� ��������� '*'
{
	int squaresNumber = M * N / 8;  // ���������� ������ � ���������
	int fillNumber = 0; //����������� ������ ���������
	int i = 0, j = 0;
	while (fillNumber < squaresNumber)
	{
		i = rand() % (N / 2);  //��������� ���������� '*' �� �
		j = rand() % (M / 2);  //��������� ���������� '*' �� y
		if (arr[i][j] = SPACE)
		{
			arr[i][j] = '*';
			fillNumber++;
		}
	}
}

void setMatrix(char(*arr)[M])  // ����������� ��������� �� �������� ������ ��������� � ������ ������� �������
{
	int lines = (N / 2);
	int columns = (M / 2);
	for (int i = 0; i < lines; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			arr[N - 1 - i][j] = arr[i][j];
			arr[i][M - 1 - j] = arr[i][j];
			arr[N - 1 - i][M - 1 - j] = arr[i][j];
		}
	}
}

void printMatrix(char(*arr)[M])  // ������ �������
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
			putchar(arr[i][j]);
		if (i != (N - 1))
			putchar('\n');
	}
}