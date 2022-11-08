//
//  main.c
//  List
//
//  Created by 冨澤眞樹 on 2022/11/08.
//  Copyright (C) 2022 Masaki Tomisawa. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main(void) {
  Record *head;

  // Converting an Array to a List Structure
  int data[] = { 1, 2, 3 };
  head = MakeList(data, sizeof(data) / sizeof(data[0]));
  PrintList(head);
  head = FreeList(head);

  // Algorithm 2.2
  head = Cons(NULL, 3);
  head = Cons(head, 2);
  head = Cons(head, 1);
  PrintList(head);
  FreeList(head);

  // The first argument of the cons function is the cons function.
  head = Cons(Cons(Cons(NULL, 3), 2), 1 );
  PrintList(head);
  FreeList(head);

  head = Cons(Cons(Cons(NULL, 3), 2), 1);
  PrintList(head);
  PrintList(Find(head, 2));
  printf("%d\n",Car(Find(head, 2)));
}
