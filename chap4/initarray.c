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
static int p = 2;

void InitPrime(void) {
    p = 2;
}

// GetPrime returns a prime number on each call
static int GetPrime() {
    if (p == 2) {
        p = 3;
        return 2;
    }

    while (1) {
        int  isDivisible = 0;

        for (int i = 3; i <= sqrt(p); i += 2) {
            if (p % i == 0) {
                 isDivisible = 1;
                break;
            }
        }

        p += 2;

        if ( isDivisible == 0) {
            return p - 2;
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
