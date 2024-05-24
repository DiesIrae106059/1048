#include"lr.h"
#include<stdio.h>
#define K 3
#define ROWS 3
#define COLS 3
#define MAX_LENGTH 100
void selectionSort(int arr[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            int min_row = i;
            int min_col = j;

            for (int k = i; k < ROWS; k++) {
                int start_col = (k == i) ? j : 0;
                for (int l = start_col; l < COLS; l++) {
                    if (arr[k][l] < arr[min_row][min_col]) {
                        min_row = k;
                        min_col = l;
                    }
                }
            }

            int temp = arr[i][j];
            arr[i][j] = arr[min_row][min_col];
            arr[min_row][min_col] = temp;
        }
    }
}

void printArray(int arr[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

void swap(int matrix[K][K], int row, int col) {
    for (int i = 0; i < K; i++) {
        int temp = matrix[row][i];
        matrix[row][i] = matrix[i][col];
        matrix[i][col] = temp;
    }
}
void removeLongestWord(char *str) {
    int max_len = 0;
    int max_len_index = 0;
    int curr_len = 0;
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] != ' ') {
            curr_len++;
        } else {
            if (curr_len > max_len) {
                max_len = curr_len;
                max_len_index = i - curr_len;
            }
            curr_len = 0;
        }
        i++;
    }

    if (curr_len > max_len) {
        max_len = curr_len;
        max_len_index = i - curr_len;
    }

    for (int j = max_len_index; j < MAX_LENGTH && str[j] != '\0'; j++) {
        str[j] = str[j + max_len];
    }
}
struct Person {
    char name[50];
    int age;
    float salary;
};
unsigned int swapNibbles(unsigned int n) {
    return ((n & 0xF) << 4) | ((n & 0xF0) >> 4); // Меняем местами младшую и старшую тетрады
}
int lab1(){
    float v;
int g,H,t;
printf("Введите H и t: ");
scanf("%d%d",&H,&t);
g=10;
v=((g*t*t)-(2*H))/(2*t);
printf("v= %f",v);
}
int lab11() {
    float v;
    int g,H,t;
    printf("Введите H и t: ");
    scanf("%d%d",&H,&t);
    g=10;
    v=((g*t*t)-(2*H))/(2*t);
    printf("v= %f",v);
}

int lab2(){
    int x, N;
double sum = 0;
double pow_x = 1.0; // начальное значение для x^i
printf("Введите значение x: ");
scanf("%d", &x);
printf("Введите количество элементов N: ");
scanf("%d", &N);
for (int i = 1; i <= N; i++) {
pow_x *= x; // умножаем x на самого себя, i раз
double term = (double)i / pow_x;
sum += term;
}
printf("Сумма первых %d элементов ряда: %f\n", N, sum);
return 0;
}
int lab21() {
    int x, N;
    double sum = 0;
    double pow_x = 1.0; // начальное значение для x^i
    printf("Введите значение x: ");
    scanf("%d", &x);
    printf("Введите количество элементов N: ");
    scanf("%d", &N);
    int i = 1;
    do {
        pow_x *= x; // умножаем x на самого себя, i раз
        double term = (double)i / pow_x;
        sum += term;
        i++;
    } while (i <= N);
    printf("Сумма первых %d элементов ряда: %f\n", N, sum);
    return 0;
}
int lab3(){int isOdd(int num) {
    return (num % 2 != 0);

}
    char str[1000];
    int words = 0;
    int i = 0;
    int count = 0;
    int inWord = 0;
    printf("Введите строку: ");
    fgets(str, sizeof(str), stdin);
    while(str[i] != '\0') {
        if (((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))) {
            if (!inWord) {
                inWord = 1;
                count = 1;
            } else {
                count++;
            }

        } else {
            if (inWord) {
                if (isOdd(count)) {
                    words++;
                }
                inWord = 0;

            }
        }
        i++;
    }
    if (isOdd(count)) {
        words++;
    }
    printf("Количество слов с нечетным количеством букв: %d\n", words);
    return 0;
}

int lab4() {
    char str[MAX_LENGTH];

    printf("Введите строку: ");
    fgets(str, MAX_LENGTH, stdin);

    removeLongestWord(str);

    printf("Строка после удаления самого длинного слова: %s\n", str);

    return 0;
}
int lab41() {
    char str[100];
    printf("Введите строку: ");
    fgets(str, sizeof(str), stdin);

    int maxLen = 0, currentLen = 0, maxPos = 0, i = 0, start = 0;

    while (str[i] != '\0') {
        if (str[i] == ' ' || str[i] == '\n') {
            if (currentLen > maxLen) {
                maxLen = currentLen;
                maxPos = start;
            }
            currentLen = 0;
            start = i + 1;
        } else {
            currentLen++;
        }
        i++;
    }

    if (currentLen > maxLen) {
        maxLen = currentLen;
        maxPos = start;
    }

    for (i = maxPos; i < maxPos + maxLen; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] -= 32;
        } else if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] += 32;
        }
    }

    printf("Измененная строка: %s\n", str);

    return 0;
}
int lab5() {
    int arr[10];
    int positive_count = 0, negative_count = 0;

    printf("Введите 10 целых чисел: ");
    for(int i = 0; i < 10; i++) {
        scanf("%d", &arr[i]);
        if(arr[i] > 0) {
            positive_count++;
        } else if(arr[i] < 0) {
            negative_count++;
        }
    }

    if(negative_count < positive_count) {
        for(int i = 0; i < 10; i++) {
            if(arr[i] < 0) {
                arr[i] = 0;
            }
        }
    } else {
        for(int i = 0; i < 10; i++) {
            if(arr[i] > 0) {
                arr[i] = 0;
            }
        }
    }
    printf("Результат: ");
    for(int i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
int lab51() {
    struct Person person1 = {"Иван Иванов", 35, 45000.0f};
    struct Person person2 = {"Мария Смирнова", 28, 52000.0f};
    struct Person person3 = {"Алексей Петров", 40, 60000.0f};

    printf("Имя: %s\nВозраст: %d\nЗарплата: %.2f\n\n", person1.name, person1.age, person1.salary);
    printf("Имя: %s\nВозраст: %d\nЗарплата: %.2f\n\n", person2.name, person2.age, person2.salary);
    printf("Имя: %s\nВозраст: %d\nЗарплата: %.2f\n", person3.name, person3.age, person3.salary);

    return 0;
}
int lab6() {
    int matrix[K][K];

    // Ввод матрицы с клавиатуры
    printf("Введите элементы матрицы (%dx%d):\n", K, K);
    for (int i = 0; i < K; i++) {
        for (int j = 0; j < K; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    int maxElement = matrix[0][0];
    int maxRow = 0, maxCol = 0;

    for (int i = 0; i < K; i++) {
        for (int j = 0; j < K; j++) {
            if (matrix[i][j] > maxElement) {
                maxElement = matrix[i][j];
                maxRow = i;
                maxCol = j;
            }
        }
    }

    swap(matrix, maxRow, maxCol);

    printf("\nМатрица после:\n");
    for (int i = 0; i < K; i++) {
        for (int j = 0; j < K; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}
int lab61() {
    int arr[ROWS][COLS] = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};

    printf("Original array:\n");
    printArray(arr);

    selectionSort(arr);

    printf("\nSorted array:\n");
    printArray(arr);

    return 0;
}
int lab7() {
    unsigned int N = 145; // Пример длинного целого числа

    printf("Исходное число: %d\n", N);

    unsigned int result = swapNibbles(N);

    printf("Число после замены тетрад: %d\n", result);

    return 0;
}



