#include <stdio.h>
#include <string.h>
#include <stdlib.h>  //��� rand() & strcmp
#include <ctype.h> //��� isspace()
#include <time.h>
#include "task1.h"
#define ATT_NUM 100
#define IN 1
#define OUT 0

char *randomWords(char *in, char *out)
{
	//������ ������ ���������� �� char, 
	//� ������� ������� ������ ������ �������� ������� �����:
	char *p_in[S] = { NULL };

	int str = strlen(in);
	if (in[str - 1] == '\n')
		in[str - 1] = '\0';

	int i = 0;
	int flag = OUT; // ���� � �����, �� OUT=1  //���� ��� �����, �� OUT=0
	int count = 0;


	while (in[i])
	{
		if (!isspace(in[i]) && flag == OUT)
		{
			flag = IN;  //� �����
			p_in[count] = &(in[i]);
			count++;
		}
		else if (isspace(in[i]) && flag == IN)
			flag = OUT;  //����� �� �����
		i++;
	}



	do
	{
		char *p = NULL;
		char *outT = out;

		//	
		// ������������ ���������� � ������� ��������� �������:

		char *tmp = NULL;
		int randomNumber = 0;
		int c = count; //current count
		while (c > 1)
		{
			randomNumber = rand() % c;
			if (randomNumber != c - 1)
			{
				tmp = p_in[c - 1];
				p_in[c - 1] = p_in[randomNumber];
				p_in[randomNumber] = tmp;
			}
			c--;
		}

		//
		//

		for (i = 0; i<count; i++)
		{
			p = p_in[i];
			while (*p != ' ' && *p != '\0')
				*outT++ = *p++;
			if (i < count - 1)
				*outT++ = ' ';
		}
		*outT = '\0';

	} while (strcmp(out, in) == 0 && count > 1);

	return out;
}

/*
*	���� ����� ������� ������ �� ��������.
*	� �������� ������� ��� ��������� ����� ����
*	������� ��������� ����� �� ���������� stdlib.h - strcmp:
*
*	strcmp (<������ 1>, <������ 2>);
*
*	��� ������� �����:
*	- �������� ������ ����, ���� <������ 1>  ������, ��� <������ 2>
*	- 0, ���� <������ 1>  � <������ 2> �����
*	- �������� ������ ����, ���� <������ 1>  ������, ��� <������ 2>
*
*/