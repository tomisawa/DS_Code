//
//  BinaryTree.c
//  chpa9
//
//  Created by Masaki Tomisawa on 2022/12/15.
//  Copyright (c) 2022 TOMISAWA Masaki. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <setjmp.h>
jmp_buf env;

#define COUNTOF(array) (sizeof(array) / sizeof(array[0]))

void PrintM(int M[], int n)
{
  int sum = 0;
  for (int i = 1; i <= n; i++) {
    printf("%1d", M[i]);
    sum += M[i];
  }
  printf("\n");
}

int BinaryTree(int level, int Y[], const int b, const int n)
{
  if (level > n) {
    int sum = 0;
    for (int i = 1; i <= n; i++) { sum += Y[i]; }
    if (sum == b) {
      PrintM(Y, n);
      // longjmp(env, 1);
    }
  } else {
    Y[level] = 0; BinaryTree(level + 1, Y, b,  n);
    Y[level] = 1; BinaryTree(level + 1, Y, b,  n);
  }
  if (level == 1) { return -1; }
  return 0;
}

int main(void)
{
  int Y[] = { 0, 0, 0, 0 };      // Y[0] is not used.
  int size = COUNTOF(Y);
  int yes;
  BinaryTree(1, Y, 2, size - 1); // n is size-1.
  //  if (!setjmp(env)) yes = BinaryTree(1, Y, 2, size - 1); // n is size-1.
  //  if (yes != 0) { printf("NO\n"); } else { printf("YES\n"); }

  return 0;
}
