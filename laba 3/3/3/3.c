#include <stdio.h>

void sort(int* arr, int size, int ascending) {
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if ((ascending && arr[j] > arr[j + 1]) || (!ascending && arr[j] < arr[j + 1])) {
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

int main() {

	int n, m, i, j, k;
	int a[1000], b[1000], c[1000];

	printf("Введите количество элементов в первом массиве: ");
	while (scanf_s("%d", &n) != 1 || n <= 0) {
		printf("Некорректный размер массива, введите целое положительное число: ");
		while (getchar() != '\n');
	}

	printf("Введите элементы первого массива: \n");
	for (i = 0; i < n; i++) {
		while (scanf_s("%d", &a[i]) != 1) {
			printf("Неккоректный ввод, введите еще раз: ");
			while (getchar() != '\n');
		}
	}

	sort(a, n, 1);

	printf("Отсортированный массив: ");
	for (i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}

	printf("\nВведите количество элементов во втором массиве: ");
	while (scanf_s("%d", &m) != 1 || m <= 0) {
		printf("Некорректный размер массива, введите целое положительное число: ");
		while (getchar() != '\n');
	}


	printf("Введите элементы второго массива: \n");
	for (i = 0; i < m; i++) {
		while (scanf_s("%d", &b[i]) != 1) {
			printf("Неккоректный ввод, введите еще раз: ");
			while (getchar() != '\n');
		}
	}

	sort(b, m, 0);

	printf("Отсортированный второй массив: ");
	for (i = 0; i < m; i++) {
		printf("%d ", b[i]);
	}

	i = 0;
	j = m - 1;
	k = 0;

	while (i < n && j >= 0) {
		if (a[i] < b[j]) {
			c[k] = a[i];
			i++;
		} else {
			c[k] = b[j];
			j--;
		}
		k++;
	}

	while (i < n) {
		c[k] = a[i];
		i++;
		k++;
	}

	while (j >= 0) {
		c[k] = b[j];
		j--;
		k++;
	}

	printf("\nРезультрующий массив: \n");
	for (i = 0; i < n + m; i++) {
		printf("%d ", c[i]);
	}

	return 0;
}