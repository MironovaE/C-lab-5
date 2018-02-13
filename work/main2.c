/*
��������� ������������, ��������� �� ����� �����������, 
������������ �� ����������� ������������� ��������� �*�.
����������� ����������� � ��������� ���������� �������, � ����� 
��� �����, � ����������� ���������� � ��������� ��� �����.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "task2.h"

int main()
{
	srand(time(0));
	char arr[N][M] = { '\0' };

	while (1)
	{
		clearMatrix(arr);  //���������� ���������� ������� (�������) ���������
		fillMatrix(arr);  //���������� �������� ������ ��������� ������� ��������� '*'
		setMatrix(arr);  //����������� ��������� � ������ ������� �������
		printMatrix(arr);  //������ �������

		printf("\n\n\n\n");

		clock_t now;
		now = clock();
		while (clock() < (now + CLOCKS_PER_SEC))  //��������� ��������
			;
	}

	return 0;
}