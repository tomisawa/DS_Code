//
//  product.c
//  chap7
//
//  Created by Masaki Tomisawa on 2022/12/08.
//  Copyrightv(C) 2022 Masaki Tomisawa. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define COUNTOF(array) (sizeof(array) / sizeof(array[0]))

// Algorithm 7.1
int BasicProduct(int X[], int Y[], int n)
{
  int sum = 0, power = 1;
  for (int i = 0; i < n; i++) {
    int s = 0, p = power;
    for (int j = 0; j < n; j++) {
      s = s + p * X[i] * Y[j];
      p = p * 10;
    }
    sum = sum + s;
    power = power * 10;
  }
  return sum;
}

// Algorithm 7.2
int Product(int X[], int Y[], int n)
{
  if (n == 1) { return X[0] * Y[0]; }

  int h = n / 2;

  int *X12 = (int *)malloc(sizeof(int) * h);
  int *Y12 = (int *)malloc(sizeof(int) * h);
  for (int i = 0; i < h; i++) {
    X12[i] = X[i] + X[h + i];
    Y12[i] = Y[i] + Y[h + i];
  }

  int c = Product(&X[0], &Y[0], h);
  int b = Product(X12, Y12, h);
  int a = Product(&X[h], &Y[h], n - h);

  free(X12);
  free(Y12);

  return a *
         (int)pow(10, (float)n) + (b - (a + c)) * (int)pow(10, (float)n / 2) + c;
}

int main(int argc, const char *argv[])
{
  int X[] = { 4, 3, 2, 1 };
  int Y[] = { 8, 7, 6, 5 };
  int size = COUNTOF(X);
  if ((size & (size - 1))) {
    printf("Size is not a power of 2. \n");
    exit(0);
  }

  printf("Basicproduct=%d\n", BasicProduct(X, Y, size));
  printf("Product=%d\n", Product(X, Y, size));

  return 0;
}
