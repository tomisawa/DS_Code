//
//  a9-1a.c
//  chap9
//
//  Created by Masaki Tomisawa on 2022/12/25.
//  Copyright (c) 2022 TOMISAWA Masaki. All rights reserved.
//

// The differences from the textbook algorithm 9.1 are as follows.
// Both level and array X[] start at 0.

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
// For the BT_subsetsum() in a9-1.c,
// all variables except level are static global variables.
//
static int s, *X, *Y, n;
void BT_subsetsum(int level) {
  if (level >= n) { // leaf nodes
    int sum = 0;
    for (int i = 0; i < n; i++) { sum += Y[i] * X[i]; }
    if (sum == s) {
      printf("ANS \t");
      PrintM(Y, n);

      // Select one of (A), (B) and (C), and comment out the remaining two.
      longjmp(env, 1); // (A)
      // return; // (B)
      // exit(0); // (C)
    }
  } else {// internal nodes
    Y[level] = 0; BT_subsetsum(level + 1);
    Y[level] = 1; BT_subsetsum(level + 1);
  }
  if (level == 0) { printf("All searches are completed.\n"); } // root node
}

int main(void) {
  int D[] = { 1, 14, 6, 9 };

  s = 15;
  n = COUNTOF(D);
  X = D;
  Y = (int *)calloc(n, sizeof(int));
  
  // Select one of (A), (B) and (C), and comment out the remaining two.
  if (!setjmp(env)) { BT_subsetsum(0); } // (A)
  //  BT_subsetsum(0); // (B)
  // (C)

  printf("\nEnd of main() execution\n");
  return 0;
}
