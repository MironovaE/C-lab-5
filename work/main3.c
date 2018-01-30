#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>
#define SIZEM 128
#define LSTR 512


int main(int argc, char * argv[])
{
	char fin[256] = { 0 };
	char fout[256] = { 0 };

	switch (argc)
	{
	case 2:
	{
		strcpy(fin, argv[1]);
		strcpy(fout, argv[1]);
		break;
	}
	case 3:
	{
		strcpy(fin, argv[1]);
		strcpy(fout, argv[2]);
		break;
	}
	default:
	{
		strcpy(fin, "test.txt");
		strcpy(fout, "test1.txt");
		break;

	}
	}

	FILE *mf;
	char *str[SIZEM];	//������ ���������� �� ������	
	mf = fopen(fin, "r");
	if (mf == NULL) //�������� ������� ����� � ��� ��������
	{
		printf("error open file in\n");
		return -1;
	}
	int i;	//������� ����������� �����
	for (i = 0; i < SIZEM; i++)
	{
		char *stroka;	//��������� �� ������
		stroka = (char*)malloc(LSTR * sizeof(char));	//�������� ������ ��� ������ � ���������� ����� � ���������		
		str[i] = fgets(stroka, LSTR, mf);	//������ ����� ������ �� �����
		stroka[strlen(stroka) - 1] = '\0';
		//�������� �� ����� ����� ��� ������ ������
		if (str[i] == NULL)
		{
			// ���������, ��� ������ ���������: �������� ���� ��� ��� ������ ������
			if (feof(mf) != 0)
			{
				//���� ���� ����������, ������� ��������� � ���������� ������ � ������� �� ������������ �����
				printf("read end file in\n");
				break;
			}
			else
			{
				//���� ��� ������ ��������� ������, ������� ��������� �� ������ � ������� �� ������������ �����
				printf("err read file in\n");
				break;
			}
		}
	} 
	char in[] = "HomeWork Helloy goodbui\0";
	char out[128];
	mixLine(in, out);
	printf("%s\n", in);
	printf("%s\n", out);
	return 0;
}


