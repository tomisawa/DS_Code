//
//  main.c
//  DS_Code
//
//  Created by tomy on 2022/11/13.
//  Copyright (c) 2022 Masaki Tomisawa. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

#include "initData.h"

void swap(int *a, int *b) {
  int temp;

  temp = *a;
  *a = *b;
  *b = temp;
  return;
}

// Algorithm 5.1
void SelectionSort(int D[], int size) {
  int max, max_index;

  for (int i = size - 1; i > 0; i = i - 1) {
    max_index = 0;  // D [0] is the initial maximum value．.
    max = D[max_index];

    for (int j = 1; j <= i; j = j + 1) {
      if (D[j] >= max) {
        max_index = j;
        max = D[max_index];
      }
    }

    swap(&D[max_index], &D[i]);
  }

  return;
}

// Algorithm 5.2
void InsertionSort(int D[], int size) {
  for (int i = 1; i < size; i = i + 1) {
    int x = D[i];
    int j = i;

    while (D[j - 1] > x && j > 0) {
      D[j] = D[j - 1];
      j = j - 1;
    }
    D[j] = x;
  }

  return;
}

int main(void) {
  int D[21];
  int size;

  size = sizeof(D) / sizeof(D[0]);

  initData(D, size);
  PrintD(D, size);
  InsertionSort(D, size);
  PrintD(D, size);

  initData(D, size);
  PrintD(D, size);
  SelectionSort(D, size);
  PrintD(D, size);
}
