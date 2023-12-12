#include <stdio.h>

int main() {

	int n;
	printf("Введите количество элементов в массиве: ");
	while (scanf_s("%d", &n) != 1 || n <= 0) {
		printf("Некорректный размер массива, введите целое положительное число: ");
		while (getchar() != '\n');
	}

	int arr[100000];
	printf("Введите элементы массива: ");
	for (int i = 0; i < n; i++) {
		while (scanf_s("%d", &arr[i]) != 1) {
			printf("Неккоректный ввод, введите еще раз: ");
			while (getchar() != '\n');
		}
	}

	int second_size = n;
	for (int i = 0; i < n; i++) {
		if (arr[i] < 0) {
			second_size++;
		}
	}

	for (int i = 0; i < n; i++) {
		if (arr[i] < 0) {
			for (int j = n; j > i; j--) {
				arr[j] = arr[j - 1];
			}
			i++;
			n++;
		}
	}

		printf("Новый массив: \n");
		for (int i = 0; i < second_size; i++) {
			printf("%d ", arr[i]);
		}
		printf("\n");

		return 0;
}