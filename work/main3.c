#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>

//������������� ������� �������� (������������� �������� � ����� �����)
char *mixChars(char *in, char *out)
{
	strcpy(out, in);	//�������� ������� ������ � ��������
	srand(time(NULL));
	int i, k;
	char buf;	//�������� ����������
	int n; //������ �����
	//��������� ������ �����
	for (n = 0; out[n] != ' ' && out[n] != '\0' && out[n] != '\n'; n++);
	//��������� �������������
	for (i = 0; i < n - 1; i++)
	{
		k = i + rand() % (n - i-1);	//����� ����� (����� ���������� �������)
		buf = out[i];
		out[i] = out[k];
		out[k] = buf;
	}
	return out;
}

int main()
{
	char in[] = "HomeWork\0";
	char out[128] = { 0 };
	mixChars(in, out);
	printf("%s\n", in);
	printf("%s\n", out);
	return 0;
}


