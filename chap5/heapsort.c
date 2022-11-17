//
//  heapsort.c
//  DS_Code
//
//  Created by tomy on 2022/11/17.
//  Copyright (c) 2022 Masaki Tomisawa. All rights reserved.
//
// Algorithm 5.3a PushHeap(int T[], int *size, int x)
// Algorithm 5.4a DeleteMaxinum(int T[], int *size)
// Algorihtm 5.5  HeapSort(int D[], int T[], int size)
//
// T[]を外に出すか，閉じ込めるか？
#include <stdio.h>

#define COUNTOF(array) (sizeof(array) / sizeof(array[0]))

// Since T[0] is not used, print from T[1] to T[size].
// Data is only two digits.
void PrintT(int T[], int size) {
    printf("Index:");
    for (int i = 1; i <= size; i++) {
        printf("%2d  ", i);
    }

    printf("\n");
    printf("Data :");

    for (int i = 1; i <= size; i++) {
        printf("%2d  ", T[i]);
    }

    printf("\n\n");
}

void swap(int *a, int *b) {
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
    return;
}

// Algorithm 5.3
void PushHeap(int T[], int *size, int x) {
    *size = *size + 1;
    T[*size] = x;
    int k = *size;

    while (T[k] > T[k / 2] && k > 1) {
        swap(&T[k], &T[k / 2]);
        k = k / 2;
    }
}

// Algorithm 5.4
int  DeleteMaxinum(int T[], int *size) {
    int max, k, big;

    max = T[1];
    T[1] = T[*size];
    T[*size] = 0;
    *size = *size - 1;
    k = 1;

    while (2 * k <= *size) {
        if (2 * k == *size) {
            if (T[k] < T[2 * k]) {
                swap(&T[k], &T[2 * k]);
                k = 2 * k;
            } else {
                break;
            }
        } else {
            if (T[2 * k] > T[2 * k + 1]) {
                big = 2 * k;
            } else {
                big = 2 * k + 1;
            }

            if (T[k] < T[big]) {
                swap(&T[k], &T[big]);
                k = big;
            } else {
                break;
            }
        }
    }
    return max;
}

int main(void) {
    int D[] = {
        39, 23, 24, 17, 6, 1, 2, 9, 11, 5, 31
    };
    const int D_SIZE = COUNTOF(D); // D[0]..D[D_SIZE-1]

    int T[] = {
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
    };                                               // T[0] is unused.
    const int T_SIZE = COUNTOF(T) - 1; // T[1]..T[T_SIZE-1]

    PrintT(T, T_SIZE);

    // Algorihtm 5.5 /////////////////////////////////
    int size = 0;

    for (int i = 0; i < D_SIZE; i++) {
        PushHeap(T, &size, D[i]);
    }

    PrintT(T, size);// Fig.5.8(d)

    for (int i = D_SIZE - 1; i >= 0; i = i - 1) {
        D[i] = DeleteMaxinum(T, &size);
    }

    // ///////////////////////////////////////////////
    for (int i = 0; i < D_SIZE; i++) {
        printf("%2d  ", i);
    }

    printf("\n");

    for (int i = 0; i < D_SIZE; i++) {
        printf("%2d  ", D[i]);
    }

    printf("\n\n");
}
