#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    setvbuf(stdin, NULL, _IONBF, 0);
    setvbuf(stdout, NULL, _IONBF, 0);

    clock_t start, end;
    int i, j, r;
    int n = 10000; // размер матрицы

    // Динамическое выделение памяти для матриц
    int** a = (int**)malloc(n * sizeof(int*));
    int** b = (int**)malloc(n * sizeof(int*));
    int** c = (int**)malloc(n * sizeof(int*));

    for (i = 0; i < n; i++) {
        a[i] = (int*)malloc(n * sizeof(int));
        b[i] = (int*)malloc(n * sizeof(int));
        c[i] = (int*)malloc(n * sizeof(int));
    }

    srand(time(NULL)); // инициализируем параметры генератора случайных чисел

    // Заполнение матрицы a случайными числами
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            a[i][j] = rand() % 100 + 1;
        }
    }

    // Заполнение матрицы b случайными числами
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            b[i][j] = rand() % 100 + 1;
        }
    }

    // Перемножение матриц
    start = clock();
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            int elem_c = 0;
            for (r = 0; r < n; r++) {
                elem_c += a[i][r] * b[r][j];
            }
            c[i][j] = elem_c;
        }
    }
    end = clock();

    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("%f", time_spent);

    for (i = 0; i < n; i++) {
        free(a[i]);
        free(b[i]);
        free(c[i]);
    }
    free(a);
    free(b);
    free(c);

    return 0;
}
