//
//  list.h
//  List
//
//  Created by 冨澤眞樹 on 2022/11/08.
//  Copyright (C) 2022 Masaki Tomisawa. All rights reserved.
//

#ifndef list_h
#define list_h

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Record {
  int data;
  struct Record *next;
} Record;

void PrintList(Record *);
Record * MakeList(int [], int);
Record * Cons(Record *, int);
Record * FreeList(Record *);
Record * Cdr(Record *);
int Car(Record *);
Record * Find(Record *, int);
Record * Delete(Record *, Record *);

#endif /* list_h */
