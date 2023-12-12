#include <stdio.h>
#include <stdlib.h>

int main() {
	srand(time(NULL));
	int n, m;

	printf("Введите размер матрицы: ");
	while (scanf_s("%d", &n) != 1 || n <= 1) {
		printf("Некорректный размер матрицы, введите целое положительное число: ");
		while (getchar() != '\n');
	}
	int matrix[100][100];

	printf("1 - случайный ввод элементов\n2 - ввод элементов на клавиатуре\n");
	scanf_s("%d", &m);

	if (m == 1) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				matrix[i][j] = (rand() % 201) - 200;
				printf("Элемент [%d][%d]: %d\n", i, j, matrix[i][j]);
			}
		}
	}
	if (m == 2) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				printf("Элемент [%d][%d]: ", i, j);
				scanf_s("%d", &matrix[i][j]);
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) 
			printf("%d ", matrix[i][j]);
		printf("\n");
	}
	int col = -1;
	int avg = 0;
	for (int j = 0; j < m; j++) {
		int i = 0;
		for (i = 0; i < n; i++) 
		{
			if (matrix[i][j] >= 0)
			{
				break;
			}
		}
			if (i == n) {
				col = j;
				break;
			}
	}
	if (col != -1)
	{
		for (int i = 0; i < n; i++) {
			avg += matrix[i][col];
		}
		avg /= n;
		printf("Среднее арифметическое: %d\n", avg);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				matrix[i][j] -= avg;
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++)
				printf("%d ", matrix[i][j]);
			printf("\n");
		}
	} 
	else {
		printf("Столбец с отрицательными элементами не найден\n");
	}
	return 0;
}