/* Nama : Afnan Edsa Ramadhan*/
/* NIM : 13521011*/
/* Tanggal :4 Oktober 2022*/

#include <stdio.h>
#include "queue.h"

void CreateQueue(Queue *q){
    IDX_HEAD(*q) = IDX_UNDEF;
    IDX_TAIL(*q) = IDX_UNDEF;
}

boolean isEmpty(Queue q){
    return ((IDX_HEAD(q) == IDX_UNDEF) && (IDX_TAIL(q)==IDX_UNDEF));
}

boolean isFull(Queue q){
    return ((IDX_TAIL(q)==CAPACITY-1) && (IDX_HEAD(q)==0));
}

int length(Queue q){
    int count=1;
    if(isEmpty(q)){
        return 0;
    }else{
        int i =IDX_HEAD(q);
        while (i!=IDX_TAIL(q)){
            if(i==CAPACITY){
                i=0;
            }else{
                count+=1;
                i++;
            }
        }
        return count;  
    }
}

void enqueue(Queue *q, ElType val){
    // if(isEmpty(*q)){
    //     IDX_HEAD(*q) = 0;
    //     IDX_TAIL(*q) = 0;
    // }else{
    //     if(IDX_TAIL(*q)==CAPACITY-1){
    //         for(int i=IDX_HEAD(*q);i<=IDX_TAIL(*q);i++){
    //             (*q).buffer[i-IDX_HEAD(*q)] = (*q).buffer[i];
    //         }
    //         IDX_TAIL(*q) -= IDX_HEAD(*q);
    //         IDX_HEAD(*q) = 0;
    //     }
    //     IDX_TAIL(*q)++;
    // }
    // TAIL(*q) = val;
    if (isEmpty(*q)){
        IDX_HEAD(*q) = 0;
        IDX_TAIL(*q) = 0;
        TAIL(*q) = val;
    }else{
        IDX_TAIL(*q) = (IDX_TAIL(*q) + 1) % (CAPACITY);
        TAIL(*q) = val;
    }
    
}

void dequeue(Queue *q, ElType *val){
    *val = HEAD(*q);
    if (IDX_HEAD(*q) == IDX_TAIL(*q)){
        IDX_HEAD(*q) = IDX_UNDEF;
        IDX_TAIL(*q) = IDX_UNDEF;
    }else{
        IDX_HEAD(*q)++;
    }
}

void displayQueue(Queue q){
    
    if(isEmpty(q)){
        printf("[]\n");
    }else{
        printf("[");
        int i = IDX_HEAD(q);
        printf("%d",q.buffer[i]);
        while (i!=IDX_TAIL(q)){
            if(i!=IDX_TAIL(q)){
                printf(",");
            }
            if(i==CAPACITY-1){
                i=0;
            }else{
                i++;
            }
            printf("%d",q.buffer[i]); 
        }
        printf("]\n");
    }
    
}