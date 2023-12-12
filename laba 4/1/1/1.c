#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main() {

    int n, m;
    printf("Введите размер матрицы: ");
    while (scanf_s("%d", &n) != 1 || n <= 1) {
        printf("Некорректный размер матрицы, ведите целое положительное число: ");
        while (getchar() != '\n');
    }
    int matrix[100][100];

    printf("1 - случайный ввод элементов\n2 - ввод элементов на клавиатуре\n");
    while (scanf_s("%d", &m) != 1 || 0 >= m >= 3) {
        printf("Некорректный ввод, попробуйте еще раз: ");
        while (getchar() != '\n');
    }

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

    int sum = 0;
    for (int i = 0; i < n; i++) {
        int has_negative = 0;
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] < 0) {
                has_negative = 1;
                break;
            }
        }
        if (!has_negative) {
            for (int j = 0; j < n; j++) {
                sum += matrix[i][j];
            }
        }
    }
    printf("Сумма элементов в строках без отрицательных элементов: %d\n", sum);

    int min_sum = INT_MAX;
    for (int d = -n + 1; d < n; d++) {
        int diag_sum = 0;
        for (int i = 0; i < n; i++) {
            int j = i + d;
            if (j >= 0 && j < n) {
                diag_sum += matrix[i][j];
            }
        }
        if (diag_sum < min_sum) {
            min_sum = diag_sum;
        }
    }
    printf("Минимум среди сумм элементов диагоналей, параллельных главной диагонали матрицы: %d\n", min_sum);

    return 0;
}
