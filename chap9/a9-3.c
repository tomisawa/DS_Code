//
//  a9-3.c
//  chap9
//
//  Created by Masaki Tomisawa on 2022/12/25.
//  Copyright (c) 2022 TOMISAWA Masaki. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define COUNTOF(array) (sizeof(array) / sizeof(array[0]))
#define N_PAINTING 4 // Number of Painting

typedef struct {
  int  Id;
  char Name[100];
  int  w;
  int  p;
  int  v;
} PTable;

//  global variable.
PTable T91[N_PAINTING + 1]; // Problem No.T91[0] is not used.
const int n = N_PAINTING;   // Problem size
int X[N_PAINTING + 1];      // Working. X[0] is not used.
int ZX[N_PAINTING + 1];     // Provisional solution. ZX[0] is not used.
int z;                      // Value of provisional solution
int c;                      // Knapsack capacity

int ReadPTable(void) {
  FILE *fp;
  const char *fname = "knap2.cvs";

  if ((fp = fopen(fname, "r")) == NULL) {
    printf("Not open %s\n", fname);
    exit(EXIT_FAILURE);
  }

  int i = 1;
  while ((fscanf(fp, "%d,%[^,],%d,%d", &(T91[i].Id), T91[i].Name, &(T91[i].w),
                 &(T91[i].p))) != EOF) {
    T91[i].v = T91[i].p / T91[i].w;
    i = i + 1;
  }
  fclose(fp);
  return i - 1;
}

void PrintPTable(void) {
  for (int i = 1; i <= n; i++) {
    printf("(%d) P-%d, %2s, %2d[kg], %2d[YEN],%2d[YEN/Kg]\n",
           i,
           T91[i].Id,
           T91[i].Name,
           T91[i].w,
           T91[i].p,
           T91[i].v);
  }
  printf("\n");
}

void ClearX(int X[]) {
  for (int i = 0; i <= n; i++) { X[i] = 0; }
}

int SumW(int X[]) {
  int sum = 0;

  for (int i = 1; i <= n; i++) { sum += T91[i].w * X[i]; }
  return sum;
}

int SumP(int X[]) {
  int sum = 0;

  for (int i = 1; i <= n; i++) { sum += T91[i].p * X[i]; }
  return sum;
}

int Vmax(int level) {
  int Vmax = 0;

  for (int i = level; i <= n; i++) { if (T91[i].v > Vmax) { Vmax = T91[i].v; } }
  return Vmax;
}

#define CheckA (w > c)
#define CheckB (w == c)
#define CheckC (v + (c - w) * Vmax(level) < z)

void BB_01knapsack(int level) {
  int w = SumW(X);
  int v = SumP(X);

  if (level > n) {
    if ((w <= c) && (v > z)) {
      z = v;
      memcpy(ZX, X, sizeof(int) * (n + 1)); // for (int i = 1; i <= n; i++)
                                            // ZX[i] = X[i];
    }
  } else {
    if (!CheckA) {
      if (CheckB) {
        if (v > z) {
          z = v;
          memcpy(ZX, X, sizeof(int) * (n + 1)); // for (int i = 1; i <= n; i++)
                                                // ZX[i] = X[i];
        }
      } else if (!CheckC) {
        X[level] = 1; BB_01knapsack(level + 1);
        X[level] = 0; BB_01knapsack(level + 1);
      }
    }
  }
}

int main(int argc, const char *argv[]) {
  //  int X[N_PAINTING + 1];
  if (ReadPTable() != n) {
    printf("Error\n");
    exit(0);
  }
  PrintPTable();

  ClearX(X); ClearX(ZX);
  z = 0; c = 10;
  BB_01knapsack(1);

  int sump = 0, sumw = 0;
  for (int i = 1; i <= n; i++) {
    sump += ZX[i] * T91[i].p;
    sumw += ZX[i] * T91[i].w;
  }
  printf("\n");
  for (int i = 1; i <= n; i++) { printf("%d", ZX[i]); }
  printf("\tPrice=%d\tWeight=%d\n", sump, sumw);

  return 0;
}
