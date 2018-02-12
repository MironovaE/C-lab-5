#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>
#include "task1.h"
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

	FILE *fp;
	char *in[SIZEM];	//������ ���������� �� ������ �������
	char *out[SIZEM];	//������ ���������� �� ������ ��������

	fp = fopen(fin, "r");
	if (fp == NULL) //�������� ������� ����� � ��� ��������
	{
		printf("error open file in\n");
		return -1;
	}
	int i;	//������� ����������� �����
	for (i = 0; i < SIZEM; i++)
	{
		char *stroka;	//��������� �� ������
		stroka = (char*)malloc(LSTR * sizeof(char));	//�������� ������ ��� ������ � ���������� ����� � ���������		
		in[i] = fgets(stroka, LSTR, fp);	//������ ����� ������ �� �����
											//stroka[strlen(stroka)] = '\0';

											//�������� �� ����� ����� ��� ������ ������
		if (in[i] == NULL)
		{
			// ���������, ��� ������ ���������: �������� ���� ��� ��� ������ ������
			if (feof(fp) != 0)
			{
				//���� ���� ����������, ������� ��������� � ���������� ������ � ������� �� ������������ �����
				//printf("read end file in\n");
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
	//�������� �����
	//printf("close file in\n");
	if (fclose(fp) == EOF)
	{
		printf("error close file in\n");
	}
	//��������� �������� ����
	fp = fopen(fout, "w");
	if (fp == NULL)
	{
		//printf("error open file out\n");
		return -1;
	}

	//����� ������ ���������� �� ������ out. ������� ������� ���������� ��� �������������
	int len;
	for (int j = 0; j < i; j++)
	{
		char *stroka;	//��������� �� ������
		stroka = (char*)malloc(LSTR * sizeof(char));
		out[j] = stroka;
		if (in[j][0] != '\n')
		{
			randomWords(in[j], out[j]);//������� ��������� �� ������ ��� �������������
			len = strlen(out[j]);
			out[j][len] = '\n';
			out[j][len + 1] = '\0';
		}
		else
		{
			out[j][0] = '\n';
			out[j][1] = '\0';
		}
		fwrite(out[j], sizeof(char), strlen(out[j]), fp);
		//fputc('\n', fp);
	}
	//��������� �������� ����
	if (fclose(fp) == EOF)
	{
		printf("error close file out\n");
	}
	return 0;
}