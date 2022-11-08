//
//  main1.c, not main.c
//  chap4
//
//  Created by TOMISAWA, Masaki on 2022/11/08.
//  Copyright (C) 2022 Masaki Tomisawa. All rights reserved.
//

#include <math.h>
#include <stdio.h>
#include "initarray.h"

// The following macros are not very good.
// It is not good to include local variables in macros.
// Macros have both advantages and disadvantages.
#define TEST(F)                                \
    if ((x = Test2(F, 0, size - 1, a)) >= 0) { \
        printf("OK %d\n", x);                  \
    }

#define FIND(F)                                        \
    if ((i = F(x, 0, size, a)) >= 0) {                 \
        printf("Find D[%d] in BinarySearch3() \n", i); \
    } else {                                           \
        printf("Not Found in BinarySearch3() \n");     \
    }

/////////////////////////////////////////////////////////

// Iterative Binary Search Algorithm
// The arguments are different from the BinarySearch2().
int BinarySearch3(int x, int left, int right, int D[]) {
    int mid;

    while (left <= right) {
        mid = (left + right) / 2;

        if (D[mid] == x) {
            return mid;
        } else if (D[mid] < x) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

// Recursive Binary Search Algorithm
int BinarySearch4(int x, int left, int right, int D[]) {
    if (left <= right) {
        int mid = (left + right) / 2;

        if (D[mid] == x) {
            return mid;
        }

        if (D[mid] < x) {
            return BinarySearch4(x, mid + 1, right, D);
        } else {
            return BinarySearch4(x, left, mid - 1, D);
        }
    }

    return -1;
}

// Test all the data
int Test2(int (*f)(int, int, int, int []), int left, int right, int D[]) {
    int i;

    // i <= right, not i < right
    for (i = left; i <= right; i++) {
        if (i != f(D[i], 0, right, D)) {
            printf("Error i=%d\n", i);
            return -1;
        }
    }

    return i;
}

int main(void) {
    int a[1000];
    int x, i;
    const int size = sizeof a / sizeof a[0];

    InitPrime();
    InitArray(a, size);

#ifdef DEBUG

    for (int i = 0; i < size; i++) {
        printf("%d\n", a[i]);
    }

#endif

    TEST(BinarySearch3);
    TEST(BinarySearch4);

    while (1) {
        printf("Imput Data=");
        scanf("%d", &x);

        FIND(BinarySearch3);
        FIND(BinarySearch4);
    }

    return 0;
}
