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

//
// Predict the output of printList()
//
int main(void) {
    Record *head;

    // Using the insert()
    head = insertFirst(NULL, 3);
    head = insertFirst(head, 2);
    head = insertFirst(head, 1);
    printList(head);
    freeList(head); // Free the entire list

    // Use the return value of InsertFirst()
    head = insertFirst(insertFirst(insertFirst(NULL, 6), 5), 4);
    printList(head);
    freeList(head);

    // Combining insertFirst() and deleteFirst()
    head = deleteFirst(insertFirst(insertFirst(insertFirst(NULL, 6), 5), 4));
    printList(head);
    freeList(head);
    head = insertFirst(deleteFirst(insertFirst(insertFirst(NULL, 6), 5)), 4);
    printList(head);
    freeList(head);


    // Using the getDta()
    head = insertFirst(deleteFirst(insertFirst(insertFirst(NULL, 9), 8)), 7);
    printf("%d\n", getData(head));
    freeList(head);

    // Using the findRecord()
    head = insertFirst(insertFirst(insertFirst(NULL, 6), 5), 4);
    printList(head);
    printList(findRecord(head, 5));
    printf("%d\n", getData(findRecord(head, 5)));
    printList(findRecord(head, 2));
    printList(head);
    freeList(head);
}
