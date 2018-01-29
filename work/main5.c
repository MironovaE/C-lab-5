#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LENNAME 128
#define SIZE 32

int main()
{
	int namber = 0;
	char *young;	//��������� �� ������ ��������
	char *old;	//��������� �� ������ �������
	int inAge = 0;	//�������� �������
	int youngAge;	//����� ������� �������
	int oldAge;	//����� ��������� �������
	char arr[SIZE][LENNAME] = { 0 };	//������ ����� ��� �������� ���
	printf("Enter the number of relatives: ");	//������� ���������� �������������
	scanf("%d", &namber);	//����������� ����� ���������� �������������
	for (int i = 0; i < namber; i++)
	{		
		while (1)
		{
			printf("Enter the name of the relative and his age (in the format: \"name age\")\n");
			if (scanf("%s %d", arr[i], &inAge) != 2)
			{
				printf("Input is not valid!!\n");
				if (ferror(stdin) || feof(stdin))
				{
					clearerr(stdin);
				}
				else
					rewind(stdin);
				continue;
			}
			else
				break;
		}
		
		if (i == 0)
		{
			young = &(arr[i]);
			old = &(arr[i]);
			youngAge = inAge;
			oldAge = inAge;
		}
		else
		{
			if (inAge > oldAge)
			{
				old = &(arr[i]);
				oldAge = inAge;
			}
			else if (inAge < youngAge)
			{
				young = &(arr[i]);
				youngAge = inAge;
			}
		}
	}
	printf("The youngest: \"%s\" has an age: %d\n", young, youngAge);
	printf("The oldest: \"%s\" has an age: %d\n", old, oldAge);
	return 0;

}