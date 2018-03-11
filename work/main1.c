#include <stdio.h>
#include <string.h>
#include "task1.h"
#define SIZEM 100

int main()
{
	char in[SIZEM] = { 0 };
	char out[SIZEM] = { 0 };

	printf("Please, enter a line:\n");
	fgets(in, SIZEM - 1, stdin);
	if (in[strlen(in) - 1] == '\n')
	{
		in[strlen(in) - 1] = '\0';
	}
	randomWords(in, out);
	printf("%s\n", out);

	return 0;
}