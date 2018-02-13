#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

//������������� ������� �������� (������������� �������� � ����� 
//����� �� ����������� ������� � ���������� ��������)
char *mixChars(char *in, char *out)
{
	strcpy(out, in);	//�������� ������� ������ � ��������
	srand(time(NULL));
	int i, k;
	char buf;	//�������� ����������
	int n; //������ �����
	//��������� ������ �����
	for (n = 0; out[n] != ' ' && out[n] != '\0' && out[n] != '\n' && out[n] != '.' && out[n] != ','; n++);
	//��������� �������������
	for (i = 2; i < n - 1; i++)
	{
		k = (rand() % (i-1)) + 1;	//����� ����� (����� ���������� �������)
		buf = out[i];
		out[i] = out[k];
		out[k] = buf;
	}
	return out;
}

char *mixLine(char *instr, char * outstr)	//������������� ��� ����� ������
{
	for (int i = 0; instr[i] != '\n' && instr[i] != '\0'; i++)
	{
		if (instr[i] != ' ' && (i == 0 || instr[i - 1] == ' '))
		{
			mixChars(&(instr[i]), &(outstr[i]));
		}
		else if (instr[i] == ' ')
		{
			outstr[i] = instr[i];
		}
	}
	outstr[strlen(instr)] = '\0';
	return outstr;
}
