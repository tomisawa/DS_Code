//
//  main.c
//  DS_Code
//
//  Created by tomy on 2022/10/26.
//  Copyright (c) 2022 Masaki Tomisawa. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#define PRINT(f, n, a) printf(#f "(%d) = %d\n", n, f(n, a))

void initA(int n, int *A) {
  srand(1);
  for (int i = 0; i < n; i++) A[i] = rand() % 100;
}

// Algorithm 3.2
int sum(int n, int *A) {
  int sum = 0;
  for (int i = 0; i < n; i++) sum += A[i];
  return sum;
}

// Algorithm 3.3
int rsum1(int n, int *A) {
  if (n == 1) return A[0];
  return rsum1(n - 1, A) + A[n - 1];
}

// Algorithm 3.4
int rsum2(int n, int *A) {
  if (n == 1)
    return A[0];
  else {
    int x = rsum2(n / 2, A);
    int y = rsum2(n - n / 2, &A[n / 2]);
    return x + y;
  }
}

#define NDATA 23

int main() {
  int A[NDATA];
  int N = sizeof(A) / sizeof(A[0]);
  initA(N, A);
  PRINT(sum, N, A);
  PRINT(rsum1, N, A);
  PRINT(rsum2, N, A);
}
