#include <stdio.h>
#include <stdlib.h>
#include "tree.h"


node * new_node(int id){
    node *new_node = malloc(sizeof(node));
    if(new_node) {
        Next(new_node) = NULL;
        Child(new_node) = NULL;
        IDD(new_node)= id;
    }
    return new_node;
}

node * add_sibling(node * n, int id)
{
    if(n==NULL){
        return NULL;
    }
    while(Next(n)){
        n = Next(n);
    }
    return (Next(n) = new_node(id));
}

node * add_child(node * n, int id){
    if(n==NULL){
        return NULL;
    }
    if(Child(n)){
        return add_sibling(Child(n), id);
    }else{
        return (Child(n) = new_node(id));
    }
}

void createTree(Tree *T, int id){
    Root(*T) = new_node(id);
}

void createListTree(ListOfTree *L, int size){
    Size(*L) = size;
    printf("Size: %d\n", Size(*L));
    for(int i=0;i<Size(*L);i++){
        int x;
        WordToInt(&x);
        Tree t;
        createTree(&t,x);
        TabTree(*L,i) = t;
        ADVWORD1();
        int child;
        WordToInt(&child);
        for(int j=0;j<child;j++){
            ADVWORD1();
            int z=0;
            WordToInt(&z);
            add_child(Root(TabTree(*L,i)),z);
        }
        ADVNEWLINE1();
    }
}

void display_tree(node *n){
    if(n==NULL){
        return;
    }
    printf("%d ", IDD(n));
    display_tree(Next(n));
    display_tree(Child(n));
}






// tree newTree(int value, int size) {
//     int val, childsize;
//     tree t;
    
//     tree T = (tree) malloc(sizeof(node));
//     value(T) = value;
//     T.ListOfTree = (tree*) malloc (size*sizeof(tree));
//     for (int i = 0; i < size; i++) {
//         scanf("%d", &val);
//         searchTree(&t, val);
//         T.ListOfTree[i] = t;
//     }
//     return T;
// }

// void printTree(tree T) {
//     if (T != NULL) {
//         printf("%d ", value(T));
//         for (int i = 0; i < T.ListOfTree.size; i++){
//             printTree(T.ListOfTree[i]);
//         }
//     }
// }

// int main() {
//     tree T = newTree(1, newTree(2, newTree(4, NULL, NULL), newTree(5, NULL, NULL)), newTree(3, newTree(6, NULL, NULL), newTree(7, NULL, NULL)));
//     printTree(T);
//     return 0;
// }
/*
void freeTree(tree T) {
    if (T != NULL) {
        freeTree(left(T));
        freeTree(right(T));
        free(T);
    }
}

int treeSize(tree T) {
    if (T == NULL) {
        return 0;
    } else {
        return 1 + treeSize(left(T)) + treeSize(right(T));
    }
}

int treeHeight(tree T) {
    if (T == NULL) {
        return 0;
    } else {
        int leftHeight = treeHeight(left(T));
        int rightHeight = treeHeight(right(T));
        if (leftHeight > rightHeight) {
            return 1 + leftHeight;
        } else {
            return 1 + rightHeight;
        }
    }
}

boolean isTreeEqual(tree T1, tree T2) {
    if (T1 == NULL && T2 == NULL) {
        return true;
    } else if (T1 == NULL || T2 == NULL) {
        return false;
    } else {
        return (value(T1) == value(T2)) && isTreeEqual(left(T1), left(T2)) && isTreeEqual(right(T1), right(T2));
    }
}


*/