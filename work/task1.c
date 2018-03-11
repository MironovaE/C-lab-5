#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "task1.h"
#define SIZE 1000
#define IN 1
#define OUT 0

int flag = OUT;

char * randomWords(char * in, char *out) // функци€, измен€юща€ пор€док слов из in и записывающую их в out
{
	char *buf[SIZE]; //массив указателей дл€ входной строки
	int i = 0;//счетчик элементов
	int	j = 0; //счетчик количества слов в in
	int	count = 0;//счетчик индекса элемента
	int cn = 0; // "буква слова" в одном элементе в массиве указателей 

	word(in, buf, &i, &j, &count);
	mixWord(buf, out, &j, &count);
	
	while (j)	//  счетчик количества слов в out
	{
		
		if (buf[count][cn] != '\0' && buf[count][cn] != ' ' && flag == OUT)//вне слова
		{
			out[i] = buf[count][cn];
			i++;		// счетчик элементов в out
			cn++;		// счетчик элементов count в buf
			flag = IN;	//вошли в слово
		}
		else if (buf[count][cn] != '\0' && buf[count][cn] != ' ' && flag == IN)// в слове (заполнение слова)
		{
			out[i] = buf[count][cn];
			i++;
			cn++;
		}
		else if ((buf[count][cn] == '\0' || buf[count][cn] == ' ') && flag == IN && (j > 1))// вне слова (после слова, когда встречаем пробел, а строка еще не закончилась)
		{
			out[i] = ' ';
			i++;
			j--;
			cn = 0;
			count++;
			flag = OUT; // вышли из слова
		}
		else if ((buf[count][cn] == '\0' || buf[count][cn] == ' ') && (j == 1))//вне слова(после слова, когда встречаем пробел или \0, а строка уже закончилась)
		{
			out[i] = '\0';
			j--;
			flag = OUT; // вышли из слова
		}
	}
	return out;
}


void word(char *in, char **buf, int * i, int *j, int *count) //нахождение слова и запись адреса первых символов каждого слова
{
	while (in[*i])
	{
		if (in[*i] != ' ' && flag == OUT)//вошли в слово
		{
			buf[*j] = &in[*i];
			(*j)++;		// счетчик элементов в buf и счетчик количества слов в in
			flag = IN;	
		}
		else if (in[*i] == ' ' && flag == IN)// вышли из слова
		{
			flag = OUT; 
			(*count)++;	//счетчик индекса элемента
		}
		(*i)++;
	}
	flag = OUT;
	(*i) = 0;
}

	void mixWord(char **buf, char *out, int *j, int *count)//перемешивание слов
	{
		int cn = 0;// рандомный элемент
		srand(time(0));
		
		for (int i = 0; i <= *count; i++)
		{
			int cn = i + rand() % (*j - i);
			out = buf[i];//buf[i] - пор€дковый элемент
			buf[i] = buf[cn];
			buf[cn] = out;
		}
		(*count) = 0;//счетчик индекса элемента (в данном случае, сколько всего элементов)
	}