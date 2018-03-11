#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "task2.h"

int main()
{
	char arr[N][M];
	clock_t now;
	while (1)
	{
		srand(time(NULL));
		clearMatrix(arr);	//«аполнение двумерного массива пробелами и прописывание в конце каждой строки '\0' 		 
		fillMatrix(arr);	//«аполнение левой верхней части массива звЄздочками в случайном пор€дке 
		setMatrix(arr);		//копирование элементов в другие области матрицы
		printMatrix(arr);	//ѕечать матрицы 

		now = clock();
		while (clock() < now + CLOCKS_PER_SEC);
	}
	return 0;
}