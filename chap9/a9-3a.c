//
//  a9-3.c
//  chap9
//
//  Created by Masaki Tomisawa on 2022/12/29.
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

//  static global variable.
static  PTable T91[N_PAINTING];

int ReadPTable(char *fname) {
  FILE *fp;
  // const char *fname = "knap2.cvs";
  if((fp = fopen(fname, "r")) == NULL ) {
    printf("Not open %s\n", fname);
    exit(EXIT_FAILURE);
  }

  int i = 0;
  while((fscanf(fp, "%d,%[^,],%d,%d", &(T91[i].Id), T91[i].Name, &(T91[i].w),
                &(T91[i].p))) != EOF ) {
    T91[i].v = T91[i].p / T91[i].w;
    i = i + 1;
  }
  fclose(fp);
  return i;
}

void PrintPTable(void) {
  for( int i = 0; i < COUNTOF(T91); i++ ) {
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

//  static global variable.
static int     n;  // Problem size
static int    *X;  // [N_PAINTING];
static int    *ZX; // [N_PAINTING];
static int     z;  // Value of provisional solution
static int     c;  // Knapsack capacity

void SumWP(int *w, int *v) {
  *w = *v = 0;
  for( int i = 0; i < n; i++ ) {
    *w += T91[i].w * X[i];
    *v += T91[i].p * X[i];
  }
}

int Vmax(int level) {
  int Vmax = 0;
  for( int i = level; i < n; i++ ) { if( T91[i].v > Vmax ) { Vmax = T91[i].v; } }
  return Vmax;
}

#define CheckA (w > c)
#define CheckB (w == c)
#define CheckC (v + (c - w) * Vmax(level) < z)

void BB_01knapsack(int level) {
  int w, v;
  SumWP(&w, &v);
  
  if( level >= n ) {
    if((w <= c) && (v > z)) {
      z = v;
      memcpy(ZX, X, sizeof(ZX) * n);
      printf("leaf level=%d,w=%d,v=%d,z=%d\n",level, w,v,z);
    }
  } else {
    printf("level=%d,w=%d,v=%d,z=%d\n",level,w,v,z);
    if( !CheckA ) {
      if( CheckB ) {
        if( v > z ) {
          z = v;
          memcpy(ZX, X, sizeof(ZX) * n);
          printf("max z=%d\n",z);
        }
      } else if( !CheckC ) {
        X[level] = 1; BB_01knapsack(level + 1);
        X[level] = 0; BB_01knapsack(level + 1);
      }
    }
  }
}

int main(void) {
  n = ReadPTable("knap2.cvs");
  PrintPTable();

  X = (int *)calloc(n, sizeof(int));
  ZX = (int *)calloc(n, sizeof(int));
  z = 0;
  c = 10;
  BB_01knapsack(0);

  int sump = 0, sumw = 0;
  for( int i = 0; i < n; i++ ) {
    sump += ZX[i] * T91[i].p;
    sumw += ZX[i] * T91[i].w;
  }
  printf("\n");
  for( int i = 0; i < n; i++ ) { printf("%d", ZX[i]); }
  printf("\tPrice=%d\tWeight=%d\n", sump, sumw);
}
