#include <stdio.h>
#include <stdlib.h>

int main() {
	srand(time(NULL));
	int n, m;
	printf("Введите размер матрицы: ");
	while (scanf_s("%d", &n) != 1 || n <= 0) {
		printf("Некорректный размер массива, введите целое положительное число: ");
		while (getchar() != '\n');
	}

	int matrix[100][100];
	printf("1 - случайный ввод элементов\n2 - ввод элементов на клавиатуре\n");
	scanf_s("%d", &m);

	if (m == 1) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				matrix[i][j] = (rand() % 201) - 100;
				printf("Элемент [%d][%d]: %d\n", i, j, matrix[i][j]);
			}
		}
	}

	if (m == 2) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				printf("Элемент[%d][%d]: ", i, j);
			scanf_s("%d", &matrix[i][j]);
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) 
			printf("%d ", matrix[i][j]);
			printf("\n");
	}
	int t;
	if (n % 2)
	{
		t = n / 2 + 1;
	}
	else
	{
		t = n / 2;
	}
	int min = matrix[0][(n/2)];
	for (int i = 0; i < t; i++) {
		for (int j = n / 2; j < n; j++) {
			if (matrix[i][j] < min) {
				min = matrix[i][j];
			}
		}
	}

	printf("Минимальный элемент во 2-ой области матрицы: %d\n", min);

	return 0;
}