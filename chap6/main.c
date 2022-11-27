//
//  main.c
//  DSA07
//
//  Created by Masaki Tomisawa on 2022/11/27.
//  Copyrightv(C) 2022 Masaki Tomisawa. All rights reserved.
//

#include <stdio.h>
#define COUNTOF(array) (sizeof(array) / sizeof(array[0]))

void PrintD(int D[], int size) {
  for (int i = 0; i < size; i++) { printf("%2d  ", i); }
  printf("\n");
  for (int i = 0; i < size; i++) { printf("%2d  ", D[i]); }
  printf("\n\n");
}

void swap(int *a, int *b) {
  int temp;
  temp = *a;
  *a = *b;
  *b = temp;
}

//
// This function is not very good.
// The use of <= and> = in conditional expressions is subtle.
//
int Partition(int D[], int left, int right) {
  int i, j, k;

  k = left;
  swap(&D[k], &D[right]);
  i = left;
  j = right - 1;
  while (i <= j) {
    while (D[i] < D[right]) { i = i + 1; }
    while (D[j] >= D[right] && j >= i) { j = j - 1; }
    if (i < j) {
      swap(&D[i], &D[j]);
    }
  }
  swap(&D[i], &D[right]);
  return i;
}

void QuickSort(int D[], int left, int right) {
  if (left < right) {
    int pivot_index = Partition(D, left, right);
    QuickSort(D, left, pivot_index - 1);
    QuickSort(D, pivot_index + 1, right);
  }
}

int main(void) {
  //  int D[] = { 17, 39, 1, 9, 5, 24, 2, 11, 23, 6  };
  //  int D[] = { 39, 19, 93, 82, 14, 66, 40, 34 };
  //  int D[] = { 31, 23, 71, 41, 21, 39, 35, 28 };
  //  int D[] = { 0, 1, 2, 3, 4, 5 };
  int D[] = { 5, 4, 3, 2, 1, 0 };
  const int D_SIZE = COUNTOF(D);

  PrintD(D, D_SIZE);
  QuickSort(D, 0, D_SIZE - 1);
  PrintD(D, D_SIZE);

  return 0;
}
