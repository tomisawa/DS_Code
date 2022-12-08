//
//  main.c
//  DSA09
//
//  Created by 冨澤眞樹 on 2019/11/20.
//  Copyright © 2019 Masaki Tomisawa. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define COUNTOF(array) (sizeof(array) / sizeof(array[0]))

typedef struct {
  int  Id;
  char Name[100];
  int  Score;
} ScoreTable;

void PrintScoreTable(ScoreTable Table[], int size) {
  for (int i = 0; i < size; i++) {
    printf("%d %s %d\n", Table[i].Id, Table[i].Name, Table[i].Score);
  }
  printf("\n");
}

int ScoreRead(ScoreTable Table[]) {
  FILE *fp;
  const char *fname = "tokuten.csv";
  if ((fp = fopen(fname, "r")) == NULL) {
    printf("Not open %s\n", fname);
    exit(EXIT_FAILURE);
  }

  int i = 0;
  while ((fscanf(fp, "%d,%[^,],%d", &(Table[i].Id), Table[i].Name,
                 &(Table[i].Score))) != EOF) {
    i = i + 1;
  }
  fclose(fp);
  return i;
}

void PrintD(ScoreTable D[], int D_SIZE) {
  for (int i = 0; i < D_SIZE; i++) {
    printf("%2d  ", D[i].Id);
    printf("%s  ", D[i].Name);
    printf("%2d  \n", D[i].Score);
  }
  printf("\n");
}

void PrintE(ScoreTable D[], int start, int end) {
  for (int i = start; i <= end; i++) {
    printf("%2d  ", D[i].Id);
    printf("%s  ", D[i].Name);
    printf("%2d  \n", D[i].Score);
  }
  printf("\n");
}

// Algorithm 7.4
void Merge74(ScoreTable D[], int left, int mid, int right, ScoreTable M[]) {
  printf("\tMerge(%d,%d,%d)\n", left, mid, right);
  int x = left;
  int y = mid + 1;
  for (int i = 0; i <= right - left; i++) {
    if (x == mid + 1) {
      M[i] = D[y];
      y = y + 1;
    } else if (y == right + 1) {
      M[i] = D[x];
      x = x + 1;
    } else if (D[x].Score <= D[y].Score) {
      M[i] = D[x];
      x = x + 1;
    } else {
      M[i] = D[y];
      y = y + 1;
    }
  }
  for (int i = left; i <= right; i = i + 1) { D[i] = M[i - left]; }
  PrintE(D, left, right);
}

// Algorithm 7.3
void Mergesort73(ScoreTable D[], int left, int right, ScoreTable M[]) {
  //  int mid = (left + right - 1) / 2; //
  int mid = (left + right) / 2; //

  printf("MergeSort(%d,%d,%d)\n", left, mid, right);
  //  PrintE(D, left, right);
  if (left < mid) { Mergesort73(D, left, mid, M); }
  if (mid + 1 < right) { Mergesort73(D, mid + 1, right, M); }
  Merge74(D, left, mid, right, M);
}

int main(int argc, const char *argv[]) {
  ScoreTable D[100];
  int size = ScoreRead(D);
  ScoreTable *M = (ScoreTable *)malloc(sizeof(ScoreTable) * 100 + 2);

  printf("size=%d\n", size);

  PrintScoreTable(D, size);

  Mergesort73(D, 0, size - 1, M);

  PrintScoreTable(D, size);

  return 0;
}
