#define _CRT_SECURE_NO_WARNINGS
#include<conio.h>
#include <time.h>
#include "mylib.h"

int main() {
    boolean Mass = FALSE;
    char* name[8];
    float times = 0.0;
    int n = 8, i = 0, num, wait;
    int* list[101];
    double* listTime;
    listTime = (double*)malloc(n * sizeof(double));
    for (i = 0; i < n - 1; i++) {
        listTime[i] = 0.0;
    }
    setlocale(LC_ALL, "Rus");
    RAND_MAX;
    name[n - 1] = "Выход";
    name[0] = "время выполнения сортировок";
    name[1] = "1) Пузырёк";
    name[2] = "2) Улучшенный пузырёк";
    name[3] = "3) Сортировка Шелла ";
    name[4] = "4) Поиск минимального";
    name[5] = "5) Сортировка слиянием";
    name[6] = "6) Сортировка вставками";
    do {
        num = Menu(name, n, 0, 0, listTime);
        switch (num) {
        case 0: {
            printf("\nВремя выполнения: \n\n");
            for (i = 1; i < n - 1; i++) {
                if (listTime[i] == 0) {
                    printf("%d - алгоритм не проверен:(\n", i);
                }
                else {
                    printf("%d - %f секунд\n", i, listTime[i]);
                }
            }
            printf("\n\nЧтобы продолжить работу, нажмите любую клавишу");
            wait = _getch();
            break;
        }
        case 1: {
            int* a;
            int i, n;
            printf("\nВведите количество элементов массива: ");
            scanf_s("%d", &n);
            a = (int*)malloc(n * sizeof(int));
            RandomNumList(a, n);
            clock_t time_begin = clock();
            pusirek(a, n);
            clock_t time_end = clock();
            times = (double)(time_end - time_begin) / CLOCKS_PER_SEC;
            listTime[1] = times;
            printf("\nВремя выполнения: %f секунд\n", times);
            printf("\n\nЧтобы продолжить работу, нажмите любую клавишу...");
            wait = _getch();
            free(a);
            break;
        }
        case 2: {
            int* a;
            int i, n;
            printf("\nВведите количество элементов массива: ");
            scanf_s("%d", &n);
            a = (int*)malloc(n * sizeof(int));
            RandomNumList(a, n);
            clock_t time_begin = clock();
            ul_pusir(a, n);
            clock_t time_end = clock();
            times = (double)(time_end - time_begin) / CLOCKS_PER_SEC;
            listTime[2] = times;
            printf("\nВремя выполнения: %f секунд\n", times);
            printf("\n\nЧтобы продолжить работу, нажмите любую клавишу...");
            wait = _getch();
            free(a);
            break;
        }
        case 3: {
            int* a;
            int i, n;
            printf("\nВведите количество элементов массива: ");
            scanf_s("%d", &n);
            a = (int*)malloc(n * sizeof(int));
            RandomNumList(a, n);
            clock_t time_begin = clock();
            Shell(a, n);
            clock_t time_end = clock();
            times = (double)(time_end - time_begin) / CLOCKS_PER_SEC;
            listTime[3] = times;
            printf("\nВремя выполнения: %f секунд\n", times);
            printf("\n\nЧтобы продолжить работу, нажмите любую клавишу...");
            wait = _getch();
            free(a);
            break;
        }
        case 4: {
            int* a;
            int i, n;
            printf("\nВведите количество элементов массива: ");
            scanf_s("%d", &n);
            a = (int*)malloc(n * sizeof(int));
            RandomNumList(a, n);
            clock_t time_begin = clock();
            mini(a, n);
            clock_t time_end = clock();
            times = (double)(time_end - time_begin) / CLOCKS_PER_SEC;
            listTime[4] = times;
            printf("\nВремя выполнения: %f секунд\n", times);
            printf("\n\nЧтобы продолжить работу, нажмите любую клавишу...");
            wait = _getch();
            free(a);
            break;
        }
        case 5: {
            int* a;
            int i, n;
            printf("\nВведите количество элементов массива: ");
            scanf_s("%d", &n);
            a = (int*)malloc(n * sizeof(int));
            RandomNumList(a, n);
            clock_t time_begin = clock();
            slian(a, n);
            clock_t time_end = clock();
            times = (double)(time_end - time_begin) / CLOCKS_PER_SEC;
            listTime[5] = times;
            printf("\nВремя выполнения: %f секунд\n", times);
            printf("\n\nЧтобы продолжить работу, нажмите любую клавишу...");
            wait = _getch();
            free(a);
            break;
        }
        case 6: {
            int* a;
            int i, n;
            printf("\nВведите количество элементов массива: ");
            scanf_s("%d", &n);
            a = (int*)malloc(n * sizeof(int));
RandomNumList(a, n);
clock_t time_begin = clock();
vstavki(a, n, 1);
clock_t time_end = clock();
times = (double)(time_end - time_begin) / CLOCKS_PER_SEC;
listTime[6] = times;
printf("\nВремя выполнения: %f секунд\n", times);
printf("\n\nЧтобы продолжить работу, нажмите любую клавишу...");
wait = _getch();
free(a);
break;
    }
    }
  } while (num != n - 1);
  printf("\n\nТест меню закончен успешно");
}
