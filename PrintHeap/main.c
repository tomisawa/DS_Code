//
//  main.c
//  PrintHeap
//
//  Created by tomisawa masaki on 2022/10/27.
//  Copyright (C) 2022 Masaki, TOMISAWA. All rights reserved.
//

#include <math.h>
#include <stdio.h>
#include "PrintHeap.h"
#define LINE_WIDTH 90

int main() {
    int tree[] = {
        0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 1, 2, 3, 4, 5, 6, 7, 8, 9, 8, 7,
        6, 5, 4, 3, 2, 1, 0, 9, 8, 7
    };

    PrintHeap(tree, sizeof(tree) / sizeof(int), LINE_WIDTH);

    return 0;
}
//
// Output of this program
//
//                                            0
//                      1----------------------------------------------2
//          3------------------------4                     5------------------------6
//    7------------8           9------------1        2------------3           4------------5
// 6------7     8------9    8------7     6------5 4------3     2------1    0------9     8------7
//
//Program ended with exit code: 0
