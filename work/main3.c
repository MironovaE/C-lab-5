
#include "task3.h"


int main()
{
	char instr[L] = { 0 };
	char outstr[L] = { 0 };
	FILE *fpInput = fopen("input.txt", "rt");
	FILE *fpOutput = fopen("output.txt", "wt");
	if (fpInput == NULL || fpOutput == NULL)
	{
		puts("File open error!");
		return 1;
	}
	while (fgets(instr, L, fpInput) != NULL)
	{
		fputs(mixLine(instr, outstr), fpOutput);
		fputc('\n', fpOutput);
	}
	if (fclose(fpInput) || fclose(fpOutput))
	{
		printf("File close error!!");
		return 1;
	}
		

	return 0;
}