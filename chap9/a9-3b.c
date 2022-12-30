//
//  a9-3c.c
//  chap9
//
//  Created by Masaki Tomisawa on 2022/12/30.
//  Copyright (c) 2022 TOMISAWA Masaki. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define COUNTOF(array) (sizeof(array) / sizeof(array[0]))

typedef struct {
  int  Id;
  char Name[100];
  int  w;
  int  p;
  int  v;
} PTable;

// About read data, the follows is static global variable
static  PTable *T91;
static int n; // Number of paintings

void ReadPTable(char *fname) {
  FILE *fp;
  if((fp = fopen(fname, "r")) == NULL ) {
    printf("Not open %s\n", fname);
    exit(EXIT_FAILURE);
  }

  //  The first row is the number of data.
  fscanf(fp, "%d", &n);
  T91 = (PTable *)calloc(n, sizeof(*T91) * n);

  // Read the second and subsequent lines of data
  int i = 0;
  while((fscanf(fp, "%d,%[^,],%d,%d", &(T91[i].Id), T91[i].Name, &(T91[i].w),
                &(T91[i].p))) != EOF ) {
    T91[i].v = T91[i].p / T91[i].w;
    i = i + 1;
  }
  fclose(fp);
  if( i != n ) {
    printf("The number of data read is wrong.\n");
    exit(EXIT_FAILURE);
  }
}

void PrintPTable(void) {
  for( int i = 0; i < n; i++ ) {
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

// About BB_01knapsack(), the follows is static global variable.
static int *X;  // Contents of the knapsack
static int *ZX; // Incumbent solution
static int  z;  // Incumbent value
static int  c;  // Knapsack capacity

int Vmax(int level) {
  int Vmax = 0;
  for( int i = level; i < n; i++ ) { if( T91[i].v > Vmax ) { Vmax = T91[i].v; } }
  return Vmax;
}

void Calc_wv(int *w, int *v)
{
  for( int i = 0; i < n; i++ ) {
    *w += T91[i].w * X[i];
    *v += T91[i].p * X[i];
  }
}
#define CheckA (w > c)
#define CheckB (w == c)
#define CheckC (v + (c - w) * Vmax(level) < z)

void BB_01knapsack(int level) {
  int w = 0, v = 0;
  Calc_wv(&w, &v);
  
  if( level >= n ) {
    if((w <= c) && (v > z)) {
      z = v;
      memcpy(ZX, X, sizeof(*ZX) * n);
      printf("leaf node; level=%d,w=%d,v=%d,z=%d\n", level, w, v, z);
    }
  } else {
    printf("internal node; level=%d,w=%d,v=%d,z=%d\n", level, w, v, z);
    if( !CheckA ) {
      if( CheckB ) {
        if( v > z ) {
          z = v;
          memcpy(ZX, X, sizeof(*ZX) * n);
          printf("\tmax z=%d\n", z);
        }
      } else if( !CheckC ) {
        X[level] = 1; BB_01knapsack(level + 1);
        X[level] = 0; BB_01knapsack(level + 1);
      }
    }
  }
}

int main(void) {
  ReadPTable("knap5.csv");
  PrintPTable();

  X = (int *)calloc(n, sizeof(*X));
  ZX = (int *)calloc(n, sizeof(*ZX));
  z = 0;
  c = 4;
  BB_01knapsack(0);

  int w = 0, v = 0;
  Calc_wv(&w, &v);
  printf("\n");
  for( int i = 0; i < n; i++ ) { printf("%d", ZX[i]); }
  printf("\tPrice=%d\tWeight=%d\n", v, w);

  free(T91);
  free(X);
  free(ZX);
}
