//
//  mergesort.c
//  DSA09
//
//  Created by TOMISAWA Masaki on 2020/12/03.
//  Copyright （C) 2020 Masaki Tomisawa. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define COUNTOF(array) (sizeof(array) / sizeof(array[0]))

void PrintD(int D[], int D_SIZE) {
  for (int i = 0; i < D_SIZE; i++) {
    printf("%2d  ", D[i]);
  }
  printf("\n");
}

void PrintRange(int D[], int left, int right) {
  for (int i = left; i <= right; i++) {
    printf("%2d  ", D[i]);
  }
  printf("\n");
}

void Merge2(int D[], int left, int mid, int right, int M[]) {
  #ifdef DEBUG
  printf("\tMerge(%d,%d,%d)\n", left, mid, right);
  PrintRange(D, left, right);
  #endif /* ifdef DEBUG */
  for (int i = 0; i < mid - left + 1; i++) { M[i] = D[left + i]; }
  M[mid - left + 1] = INT_MAX;
  for (int j = 0; j < right - mid; j++) { M[mid - left + 2 + j] = D[mid + 1 + j];
  }
  M[right - left + 2] = INT_MAX;

  int l = 0; int r = mid - left + 2;
  for (int k = left; k <= right; k++) {
    if (M[l] <= M[r]) { D[k] = M[l++]; }
    else { D[k] = M[r++]; }
  }
}

void Mergesort2(int D[], int left, int right, int M[]) {
  if (left < right) {
    int mid = (left + right)  / 2;

    #ifdef DEBUG
    printf("MergeSort(%d,%d,%d)\n", left, mid, right);
    PrintRange(D, left, mid);
    PrintRange(D, mid + 1, right);
    #endif /* ifdef DEBUG */

    Mergesort2(D, left, mid, M);
    Mergesort2(D, mid + 1, right, M);
    Merge2(D, left, mid, right, M);
  }
}

int main(int argc, const char *argv[]) {
  int D[] = { 17, 39, 1, 9, 5, 24, 2, 11, 23, 6 };
  int M[COUNTOF(D) + 2];

  int size = COUNTOF(D);

  PrintD(D, size);
  printf("\n");

  Mergesort2(D, 0, size - 1, M);

  PrintD(D, size);
  printf("\n");

  return 0;
}
