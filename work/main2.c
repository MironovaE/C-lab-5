#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "task2.h"

int main()
{
	char arr[N][M];
	clock_t now;
	while (1)
	{
		srand(time(NULL));
		clearMatrix(arr);	//���������� ���������� ������� ��������� � ������������ � ����� ������ ������ '\0' 		 
		fillMatrix(arr);	//���������� ����� ������� ����� ������� ���������� � ��������� ������� 
		setMatrix(arr);		//����������� ��������� � ������ ������� �������
		printMatrix(arr);	//������ ������� 

		now = clock();
		while (clock() < now + CLOCKS_PER_SEC);
	}
	return 0;
}