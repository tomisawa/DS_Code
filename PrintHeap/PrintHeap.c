//
//  PrintHeap.c
//  PrintHeap
//
//  Created by tomisawa on 2022/10/26.
//  Copyright (c) 2022 Masaki Tomisawa. All rights reserved.
//

#include <math.h>
#include <stdlib.h>
#include "PrintHeap.h"

#define PARENT(i) ((i - 1) / 2)
#define LM 1
void PrintHeap(int heap[], int hsize, int width) {
    int *p_pos = calloc(hsize, sizeof(int));
    int pos = 0, level = 0, left_margin = LM;

    for (int node = 0, h = 1; node < hsize; node++, h++) {
        char c;

        float offset = (width / pow(2, level + 1) + 1);

        if (node == 0) { // root node
            c = ' ';
            pos = p_pos[PARENT(node)] + offset;
        } else if (node % 2) { // left node
            c = ' ';
            pos = p_pos[PARENT(node)] - offset;
        } else { // right node
            c = '-';
            pos = p_pos[PARENT(node)] + offset;
        }

        for (int i = 0; i < pos - left_margin; i++) {
            printf("%c", c);
        }

        printf("%d", heap[node]);

        p_pos[node] = left_margin = pos + 1; // last reference node

        if (h == pow(2, level)) {
            printf("\n");
            level++;
            left_margin = LM;
            h = 0;
        }
    }

    printf("\n");
    free(p_pos);
    return;
}
