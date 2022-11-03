//
//  main.c
//  chap4
//
//  Created by TOMISAWA, Masaki on 2022/10/30.
//  Copyright (C) 2022 Masaki Tomisawa. All rights reserved.
//

#include <math.h>
#include <stdio.h>
#include "initarray.h"

// Algorithm 4.1
int LinearSearch(int x, int D[], int size) {
    int i = 0;

    while (i < size) {
        if (x == D[i]) {
            printf("Find D[%d] in LinearSearch()\n", i);
            return i;
        } else {
            i = i + 1;
        }
    }
    printf("Not Found in LinearSearch()\n");
    return -1;
}

// Algorithm 4.1 for-loop version
// found : i, not found : -1
int LinearSearch2(int x, int D[], int size) {
    for (int i = 0; i < size; i++) {
        if (x == D[i]) {
            return i;
        }
    }

    return -1;
}

// Algorithm 4.2
int BinarySearch(int x, int D[], int size) {
    int left, right, mid;

    left = 0;
    right = size - 1;
    mid = (left + right) / 2;

    while (left < right) {
        if (D[mid] == x) {
            printf("Find D[%d] in BinarySearch() \n", mid);
            return mid;
        } else if (D[mid] < x) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }

        mid = (left + right) / 2;
    }

    if (D[mid] == x) {
        printf("Find D[%d] in BinarySearch()\n", mid);
        return mid;
    } else {
        printf("Not Found in BinarySearch()\n");
        return -1;
    }
}

// How does it compare to Algorithm 4.2 ?
int BinarySearch2(int x, int D[], int size) {
    int left, right, mid;

    left = 0;
    right = size - 1;

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

// Test all the data
int Test(int (*f)(int, int [], int), int D[], int size) {
    int i;

    for (i = 0; i < size; i++) {
        if (i != f(D[i], D, size)) {
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

//    InitPrime();
    InitArray(a, size);

  #ifdef DEBUG

    for (int i = 0; i < size; i++) {
        printf("%d\n", a[i]);
    }

  #endif

    if ((x = Test(LinearSearch2, a, size)) >= 0) {
        printf("OK %d\n", x);
    }

    if ((x = Test(BinarySearch2, a, size)) >= 0) {
        printf("OK %d\n", x);
    }

    while (1) {
        printf("Imput Data=");
        scanf("%d", &x);

        LinearSearch(x, a, size);

        if ((i = LinearSearch2(x, a, size)) >= 0) {
            printf("Find D[%d] in LinearSearch2()\n", i);
        } else {
            printf("Not Found in LinearSearch2()\n");
        }

        BinarySearch(x, a, size);

        if ((i = BinarySearch2(x, a, size)) >= 0) {
            printf("Find D[%d] in BinarySearch2() \n", i);
        } else {
            printf("Not Found in BinarySearch2() \n");
        }
    }
    return 0;
}
