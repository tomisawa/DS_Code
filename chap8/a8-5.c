//
//  a8-5.c
//  chap8
//
//  Created by Masaki Tomisawa on 2022/12/09.
//  Copyrightv(C) 2022 Masaki Tomisawa. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

#define N_COFFEE 5 // Number of coffee types
#define W        5 // Weight

#define COUNTOF(array) (sizeof(array) / sizeof(array[0]))

typedef struct {
  int  Id;
  char Name[100];
  int  w;
  int  v;
} CofeeTable;

typedef struct {
  int v;
  int s[N_COFFEE + 1]; // s[0] is NOT used.
} Table;

void ClearTable(Table T[][W + 1]) {
  for (int i = 0; i <= N_COFFEE; i++) {
    for (int j = 0; j <= W; j++) {
      T[i][j].v = 0;
      for (int k = 0; k <= N_COFFEE; k++) {
        T[i][j].s[k] = 0;
      }
    }
  }
}

void PrintTable(Table T[][W + 1]) {
  for (int i = 1; i <= N_COFFEE; i++) {
    for (int j = 1; j <= W; j++) {
      printf("\nT[%d][%d].v=%4d\t", i, j, T[i][j].v);
      for (int k = 1; k <= N_COFFEE; k++) {
        printf("%d", T[i][j].s[k]);
      }
    }
    printf("\n");
  }
}

int ReadTable(CofeeTable Table[]) {
  FILE *fp;
  const char *fname = "table81.cvs";
  if ((fp = fopen(fname, "r")) == NULL) {
    printf("Not open %s\n", fname);
    exit(EXIT_FAILURE);
  }

  int i = 1; // Start with Table[1].
  // Read a CSV file.
  while ((fscanf(fp, "%d,%[^,],%d,%d", &(Table[i].Id), Table[i].Name,
                 &(Table[i].w), &(Table[i].v))) != EOF) {
    i = i + 1;
  }
  fclose(fp);
  return i - 1;
}

void PrintCoffeeTable(CofeeTable T[], int size) {
  for (int i = 1; i <= size; i++) {
    printf("%d, %-12s, %d[kg], %d[YEN]\n",
           T[i].Id,
           T[i].Name,
           T[i].w,
           T[i].v);
  }
  printf("\n");
}

void Knapsack(CofeeTable T81[], Table T[][W + 1]) {
  Table T1, T2;
  ClearTable(T);
  for (int i = 1; i <= N_COFFEE; i++) {
    for (int j = 1; j <= W; j++) {
      T[i][j] = T[i - 1][j];
      if (j >= T81[i].w) {
        T1 = T[i - 1][j - T81[i].w];
        T2 = T[i - 1][j];
        if (T1.v + T81[i].v > T2.v) {
          T1.v = T1.v + T81[i].v;
          T1.s[i] = 1;
          T[i][j] = T1;
        }
      }
    }
  }
}

int main(void) {
  CofeeTable T81[N_COFFEE + 1]; // T81[0] is NOT used.
  Table T[N_COFFEE + 1][W + 1];

  int n = ReadTable(T81);
  PrintCoffeeTable(T81, n);

  Knapsack(T81, T);
  PrintTable(T);

  return 0;
}
