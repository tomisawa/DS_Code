//
//  list.h
//  List
//
//  Created by 冨澤眞樹 on 2022/11/08.
//  Copyright (C) 2022 Masaki Tomisawa. All rights reserved.
//

#ifndef list_h
#define list_h

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Record {
    int data;
    struct Record *next;
} Record;

void printList(Record *);
Record *freeList(Record *);
Record *insertFirst(Record *, int);
Record *deleteFirst(Record *);
int getFirst(Record *);
Record *Find(Record *, int);

#endif /* list_h */
