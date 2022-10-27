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
#define LINE_WIDTH 66

int main() {
    int tree[] = {
        0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 1, 2, 3, 4, 5
    };

    PrintHeap(tree, sizeof(tree) / sizeof(int), LINE_WIDTH);

    return 0;
}

//
// Output of this program
//               1----------------------------------2
//       3------------------4               5------------------6
//  7----------8       9----------1    2----------3       4----------5
//
//Program ended with exit code: 0
