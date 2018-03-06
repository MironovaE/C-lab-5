#include <stdio.h>
#include "task1.h"
#define LENGHT 3000

int main()
{
	char string[LENGHT] = { '\0' };
	char randomized[LENGHT] = { '\0' };
	puts("Enter the string to randomize [<3000 chars]:");
	fgets(string, LENGHT, stdin);
	printf("%s\n\n", randomWords(string, randomized));

	return 0;
}
