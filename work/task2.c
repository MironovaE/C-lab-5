#include "task2.h"
#include <string.h>

void clearMatrix(char *arr[])	//���������� ���������� �������(�������) ���������
{
	for (int i = 0; i < SIZE - 1; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			arr[i][j] = ' ';
		}
		arr[i][strlen(arr[i])] = '\0';
	}
}

void fillMatrix(char *arr[])	//���������� �������� ������ ��������� ������� �����������
{
	int h = SIZE / 2;
	int w = SIZE / 2 - 1;




}

void setMatrix(char(*arr)[M])	//����������� ��������� � ������ ������� �������
{

}

void printMatrix(char(*arr)[M])	//������ �������
{

}
*/