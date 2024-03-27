#include<locale.h>
#include<stdio.h>
#include<stdlib.h>
#include <windows.h>
#include <wincon.h>

void clear() {
    COORD topLeft = { 0, 0 };
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO screen;
    DWORD written;

    GetConsoleScreenBufferInfo(console, &screen);
    FillConsoleOutputCharacterA(
        console, ' ', screen.dwSize.X * screen.dwSize.Y, topLeft, &written
    );
    FillConsoleOutputAttribute(
        console, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE,
        screen.dwSize.X * screen.dwSize.Y, topLeft, &written
    );
    SetConsoleCursorPosition(console, topLeft);
}

int Menu(char** name, int n, int x, int y, double* TimeList) {
    int num = 0;
    int i;
    int code;

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | BACKGROUND_BLUE);
    do {
        clear();
        for (i = 0; i < n; i++) {
            if (i == num) {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
                printf("%s\n", name[i]);
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | BACKGROUND_BLUE);
            }
            else {
                printf("%s \n", name[i]);
            }
        }
        code = _getch();
        if (code == 224) {
            code = _getch();
        }
        if (code == 0x48) {
            num--;
            if (num < 0) {
                num = n - 1;
            }
        }
        if (code == 0x50) {
            num++;
            if (num == n) {
                num = 0;
            }
        }
    } while (code != 13);
    return num;
}

void slin(int* a, int k, int* first, int nf, int* second, int ns) {
    int i;
    first[nf] = abs(first[nf - 1]);
    if (ns > 0) {
        first[nf] += abs(second[ns - 1]);
    }
    second[ns] = first[nf];

    int p = 0, q = 0, count = 0;
    while (count < nf + ns) {
        if (first[p] < second[q]) {
            a[k + count] = first[p++];
        }
        else {
            a[k + count] = second[q++];
        }

        count++;
    }
}

void slian(int* a, int n) {
    int d, k, nf, ns, i;
    int* first, * second;
    first = (int*)malloc(n * sizeof(int));
    second = (int*)malloc((n / 2 + 1) * sizeof(int));
    d = 1;
    while (d < n) {
        k = 0;
        while (k < n) {
            nf = 0;
            while ((nf < d) && (nf + k < n)) {
                first[nf] = a[k + nf]; nf++;
            }
            ns = 0;
            while ((ns < d) && (ns + k + d < n)) {
                second[ns] = a[k + d + ns]; ns++;
            }
            slin(a, k, first, nf, second, ns);
            k += 2 * d;
        }
        d *= 2;
    }
}
void pusirek(int* a, int n) {
    int f, j, i, t, l;
    l = n - 1;
    do {
        f = 0;
        for (i = 0; i < l; i++) {
            if (a[i] > a[i + 1]) {
                t = a[i];
                a[i] = a[i + 1];
                a[i + 1] = t;
                f = 1;
            }
        }
        l -= 1;
    } while (f == 1);
}
void ul_pusir(int* a, int n) {
    int i, f, l, t;
    int start = 0;
    l = n - 1;
    do {
        f = 0;
        for (i = start; i < l; i++) {
            if (a[i] > a[i + 1]) {
                t = a[i];
                a[i] = a[i + 1];
                a[i + 1] = t;
                f = 1;
            }
        }
        l = l - 1;
        if (f == 1)
            f = 0;
        for (i = l; i > start; i--) {
            if (a[i] < a[i - 1]) {
                t = a[i];
                a[i] = a[i - 1];
                a[i - 1] = t;
                f = 1;
            }
        }
        start++;
    } while (f == 1);
}
void mini(int* a, int n) {
    int j, i, min, l, t;
    for (i = 0; i < n - 1; i++) {
        min = a[i];
        l = i;
        for (int j = i + 1; j < n; j++) {
            if (a[l] > a[j])
                l = j;
        }
        t = a[l];
        a[l] = a[i];
        a[i] = t;
    }
}
void Shell(int* a, int n) {
    int i, f, l, t;
    int d = n;
    l = n;
    do {
        d = (d + 1) / 2;
        f = 0;
        for (i = 0; i < l - d; i++) {
            if (a[i] > a[i + d]) {
                t = a[i];
                a[i] = a[i + d];
                a[i + d] = t;
                f = 1;
            }
        }
        if ((d == 1) && (f == 1)) {
            l--;
        }
    } while ((d != 1) || (f == 1));
}
void vstavki(int* a, int n, int k) {
    int i, j, t;
    for (i = k; i < n; i++)
    {
        t = a[i];
        j = i - 1;
        while ((j >= 0) && (t < a[j])) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = t;
    }
}
void RandomNumList(int* list, int n) {
    int i;
    srand(10);
    for (i = 0; i < n; i++) {
        list[i] = rand() % n;
    }

    printf("\n\n");
}
