#include <stdio.h>
#include "notif.h"

void CreateQueue(QueueN *q) {
    IDX_HEAD(*q) = IDX_UNDEF;
    IDX_TAIL(*q) = IDX_UNDEF;
}

boolean isEmpty(QueueN q) {
    return (IDX_HEAD(q) == IDX_UNDEF && IDX_TAIL(q) == IDX_UNDEF);
}

boolean isFull(QueueN q) {
    return (IDX_HEAD(q) == 0) && (IDX_TAIL(q) == CAPACITY-1);
}

int length(QueueN q) {
    if (isEmpty(q)) {
        return 0;
    }
    else if (IDX_TAIL(q) >= IDX_HEAD(q)) {
        return IDX_TAIL(q) - IDX_HEAD(q) + 1;
    }
    else {
        return CAPACITY - IDX_HEAD(q) + IDX_TAIL(q) + 1;
    }
}

void enqueue(QueueN *q, ElTypeN val) {
    if (isEmpty(*q)) {
        IDX_HEAD(*q) = 0;
        IDX_TAIL(*q) = 0;
    }
    else if (IDX_TAIL(*q) == CAPACITY - 1) {
        IDX_TAIL(*q) = 0;
    }
    else {
        IDX_TAIL(*q)++;
    }
    TAIL(*q) = val;
}

void dequeue(QueueN *q, ElTypeN *val) {
    *val = HEAD(*q);
    if (IDX_HEAD(*q) == IDX_TAIL(*q)) {
        IDX_HEAD(*q) = IDX_UNDEF;
        IDX_TAIL(*q) = IDX_UNDEF;
    }
    else {
        IDX_HEAD(*q) = (IDX_HEAD(*q) + 1) % CAPACITY;
    }
}

void displayNotif(QueueN q) {
    int x;
    if (isEmpty(q)) {
        printf("-\n");
    }
    else {
        while (!isEmpty(q)) {
            dequeue(&q, &x);
            if (x==0) {
                printf("command tidak valid");
            }
            if (x==1) {
                printf("anda tidak bisa jalan ke sana");
            }
            else if (x==2) {
                printf("tidak ada telepon di sekitar anda");
            }
            else if (x==3) {
                printf("tidak ada tempat mixing di sekitar anda");
            }
            else if (x==4) {
                printf("tidak ada tempat menggoreng di sekitar anda");
            }
            else if (x==5) {
                printf("tidak ada tempat memotong di sekitar anda");
            }
            else if (x==6) {
                printf("tidak ada tempat merebus di sekitar anda");
            }
            if (!isEmpty(q)) {
                printf(", ");
            }
            else {
                printf(".\n");
            }
        }
    }
}