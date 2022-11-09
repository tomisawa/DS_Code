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

    // Using the Insert()
    head = insertFirst(NULL, 3);
    head = insertFirst(head, 2);
    head = insertFirst(head, 1);
    printList(head);
    head = deleteFirst(head);
    printList(head);
    freeList(head); // Free the entire list

    // Use the return value of Insert()
    head = insertFirst(insertFirst(insertFirst(NULL, 6), 5), 4);
    printList(head); // (4 5 6)
    printList(Find(head, 5)); // (5 6)
    printList(Find(head, 2)); // Empty
    printList(head); // (4 5 6)

    // getFirst()
    printf("%d\n", getFirst(head)); // 4
    printList(head); // (4 5 6)

    // getFirst(), deleteFirst()
    printf("%d\n", getFirst(head = deleteFirst(head))); // 4
    printList(head); // (5 6)

    printf("%d\n", getFirst(head = deleteFirst(head))); // 5
    printList(head); // (6)

    printList(head = deleteFirst(head)); // Empty
}
