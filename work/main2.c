#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "task2.h"


int main()
{
	char arr[M][M] = {0};
	int flag = 0;

	while (1)
	{
		clearMatrix(arr);
		fillMatrix(arr);
		setMatrix(arr);
		if (flag == 0)
		{
			flag = 1;
			printMatrix(arr);
		}
		else if (flag == 1)
		{
			clrScr();
			printMatrix(arr);
		}
		wait(2);
	}

	return 0;
}
