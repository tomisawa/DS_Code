//
//  main.c
//  DSA07
//
//  Created by Masaki Tomisawa on 2022/11/27.
//  Copyrightv(C) 2022 Masaki Tomisawa. All rights reserved.
//

#include <stdio.h>

#include "initData.h"

#define COUNTOF(array) (sizeof(array) / sizeof(array[0]))
int QuickSortCount;
int PartitionCount;

void PrintData(int D[], int size) {
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

  //  printf("input kijun:");
  //  scanf("%d",&k);
  PartitionCount++;
  swap(&D[k], &D[right]);
  i = left;
  j = right - 1;
  while (i <= j) {
    while (D[i] < D[right]) { i = i + 1;  }
    while (D[j] >= D[right] && j >= i) { j = j - 1; }
    if (i < j) { swap(&D[i], &D[j]); }
  }
  swap(&D[i], &D[right]);
  return i;
}

int Partition2(int D[], int left, int right) {
  PartitionCount++;
  int i = left;
  for (int j = left + 1; j <= right; j++) {
    if (D[j] <= D[left]) {
      i = i + 1;
      swap(&D[j], &D[i]);
    }
  }
  swap(&D[i], &D[left]);
  return i;
}

void QuickSort(int D[], int left, int right) {
  printf("QuickSort(%d,%d) ", left, right);
  if (left < right) {
    QuickSortCount++;
    for (int i = left; i < right; i++) {
      printf("%d ", D[i]);
    }
    printf("%d\n", D[right]);

    int pivot = (rand() % (right - left + 1)) + left;
    printf("index=%d\n", pivot);

    swap(&D[left], &D[pivot]);

    int pivot_index = Partition2(D, left, right);
    printf("\tpivot_index=%d\n", pivot_index);
    QuickSort(D, left, pivot_index - 1);
    QuickSort(D, pivot_index + 1, right);
  }
  else { printf("is left >= right\n"); }
}

int main(void) {
  //  int D[] = { 17, 39, 1, 9, 5, 24, 2, 11, 23, 6  };
  int D[] = { 39, 19, 93, 82, 14, 66, 40, 34 };

  //  int D[] = { 31, 23, 71, 41, 21, 39, 35, 28 };
  //    int D[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8 };
  //    int D[] = { 8, 7, 6, 5, 4, 3, 2, 1, 0 };
  //  int size, D[3000];
  //  size = sizeof(D) / sizeof(D[0]);
  //  initData(D, size);

  const int D_SIZE = COUNTOF(D);
  PartitionCount = 0;
  QuickSortCount = 0;
  PrintD(D, D_SIZE);
  QuickSort(D, 0, D_SIZE - 1);
  PrintD(D, D_SIZE);
  printf("Partition =%d\n", PartitionCount);
  printf("QuickSortCount =%d\n", QuickSortCount);
  printf("Cost %d\n", PartitionCount * QuickSortCount);
  return 0;
}
