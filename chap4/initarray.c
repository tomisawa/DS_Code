//
//  initarray.c
//  chap4
//
//  Created by TOMISAWA, Masaki on 2022/10/30.
//  Copyright (C) 2022 Masaki Tomisawa. All rights reserved.
//

#include <assert.h>
#include <math.h>
#include "initarray.h"

// GetPrime returns a prime number on each call
static int GetPrime() {
    static int i = 1; // !! static !!
    int j, flag;

    if (i == 1) {
        i = 3;
        return 2;
    }

    while (1) {
        flag = 0;

        for (j = 3; j <= sqrt(i); j += 2) {
            if (i % j == 0) {
                flag = 1;
                break;
            }
        }

        i += 2;

        if (flag == 0) {
            return i - 2;
        }
    }
    return -1; // Something is wrong.
}

// Initialize array with prime numbers
void InitArray(int a[], int size) {
    for (int i = 0; i < size; i++) {
        a[i] = GetPrime();
        assert(a[i] >= 2);
    }
}
