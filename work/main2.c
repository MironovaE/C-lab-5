#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "task2.h"

//#define SIZE 51





int main()
{
	char arr[SIZE][SIZE];
	clearMatrix(arr);	//���������� ���������� ������� ��������� � ������������ � ����� ������ ������ '\0' 
	fillMatrix(arr);	//���������� ����� ������� ����� ������� ���������� � ��������� �������



	return 0;
}