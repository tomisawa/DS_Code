//
//  initData.c
//  DS_Code
//
//  Created by tomy on 2022/11/14.
//  Copyright (c) 2022 Masaki Tomisawa. All rights reserved.
//

#include "initData.h"

static void setData(int *D, int size) {
  for (int i = 0; i < size; i++) {
    D[i] = i;
  }
}

// Fisher-Yates shuffle Algorithm
static void shuffle(int *D, int size) {
  for (int i = 0; i < size; i++) {
    int j = rand() % size;
    int t = D[i];
    D[i] = D[j];
    D[j] = t;
  }
}

// The same value does not exist
int initData(int *D, int size) {
  setData(D, size);
  shuffle(D, size);
  return size;
}

void PrintD(int *D, int size) {
  for (int i = 0; i < size; i++) printf("%02d  ", D[i]);
  printf("\n\n");
}
