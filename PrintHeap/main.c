//
//  main.c
//  PrintHeap
//
//  Created by tomisawa masaki on 2020/10/23.
//  Copyright (C) 2020 tomisawa. All rights reserved.
//

#include <stdio.h>
#include <math.h>
#include "PrintHeap.h"
#define LINE_WIDTH 70

int main() {
  int tree[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 1, 2, 3, 4, 5 ,6,7,8 ,9};
  PrintHeap(tree, sizeof(tree)/sizeof(int), LINE_WIDTH);

  return 0;
}
