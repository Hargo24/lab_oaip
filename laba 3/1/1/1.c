#include <stdio.h>
#include <math.h>

int main(void) {

	int n;
	printf("Введите размер массива: ");
	while (scanf_s("%d", &n) != 1 || n <= 0) {
		printf("Некорректный размер массива, введите целое положительное число: ");
		while (getchar() != '\n');
	}

	double array[10000];
	printf("Введите элементы массива: ");
	for (int i = 0; i < n; i++) {
		while (scanf_s("%lf", &array[i]) != 1) {
			printf("Неккоректный ввод, введите вещественное число: ");
			while (getchar() != '\n');
		}
	}
	
	int max = array[0];
	int sum = 0;
	int last_p_i = 0	;
	
	for (int i = 0; i < n; i++) 
	{
		if (array[i] > max) {
			max = array[i];
		}
		if (array[i] > 0) {
			last_p_i = i;
		}
	}
	
	for (int i = 0; last_p_i > i; i++) {
		sum += array[i];
	}

	printf("Максимальный элемент массива: %d\n", max);
	printf("Сумма элементов массива до последнего положительного элемента: %d\n", sum);

	return 0;
 }