#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "task2.h"

//#define SIZE 51





int main()
{
	char arr[SIZE][SIZE];
	while (1)
	{
		
		clearMatrix(arr);	//���������� ���������� ������� ��������� � ������������ � ����� ������ ������ '\0' 
		//srand(time(NULL));
		//fillMatrix(arr);	//���������� ����� ������� ����� ������� ���������� � ��������� �������
		for (int i = 0; i < SIZE; i++)
		{
			printf("%s\n", arr[i]);
		}


	}
	return 0;
}