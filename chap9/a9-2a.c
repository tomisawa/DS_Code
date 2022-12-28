//
//  a9-2a.c
//  chap9
//
//  Created by Masaki Tomisawa on 2022/12/25.
//  Copyright (c) 2022 TOMISAWA Masaki. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <setjmp.h>

jmp_buf env;

#define COUNTOF(array) (sizeof(array) / sizeof(array[0]))

void PrintM(int M[], int n) {
  for (int i = 0; i < n; i++) { printf("%d\t", M[i]); }
  printf("\n");
}

//
// BB in BB_subsetsum() is an abbreviation for Branch and Bound.
//
static int s, *X, *Y, n;
void BB_subsetsum(int level) {
  if (level >= n) { //
    int sum = 0;
    for (int i = 0; i < n; i++) { sum += Y[i] * X[i]; }
    printf("sum=%d\n", sum);
    if (sum == s) {
      // printf("ANS \t");
      PrintM(Y, n);

      // Select one of (A), (B) and (C), and comment out the remaining two.
      longjmp(env, 1); // (A)
      // return; // (B)
      // exit(0); // (C)
    }
  } else {
    // Calculate the upper and lower bounds.
    int upper = 0, lower = 0;
    for (int i = 0; i < n; i++) {
      if (i < level) {
        lower += Y[i] * X[i]; upper = lower;
      } else { upper += X[i]; }
    }
    //
    printf("lower=%d,upper=%d\n", lower, upper);
    if ((lower <= s) && (upper >= s)) {
      Y[level] = 0; BB_subsetsum(level + 1);
      Y[level] = 1; BB_subsetsum(level + 1);
    }
  }
  if (level == 0) { printf("All searches are completed.\n"); }
}

int main(void) {
  int D[] = { 3, 14, 6, 9 };

  s = 12;
  n = COUNTOF(D);
  X = D;
  Y = (int *)calloc(n, sizeof(int));
  // Select one of (A), (B) and (C), and comment out the remaining two.
  if (!setjmp(env)) { BB_subsetsum(0); } // (A)
  //  BT_subsetsum(0); // (B)
  // (C)

  printf("\nEnd of main() execution\n");
  return 0;
}
