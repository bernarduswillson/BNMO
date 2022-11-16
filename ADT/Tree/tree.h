#ifndef TREE_H
#define TREE_H


#include "../Boolean/boolean.h"
#include "../Makanan/makanan.h"
#include "../Mesin_Kata/wordmachine.h"

typedef struct node{
    int id;
    int numOfChild;
    struct node *next;
    struct node *child;
}node;
typedef struct node node;

typedef struct{
    node *root;
}Tree;

typedef struct{
    int size;
    Tree TabTree[100];
}ListOfTree;

#define IDD(t) ((t)->id)
#define Next(t) ((t)->next)
#define Child(t) ((t)->child)
#define numChild(t) ((t)->numOfChild)
#define Root(t) ((t).root)
#define Size(t) ((t).size)
#define TabTree(l,i) ((l).TabTree[i])

// typedef struct tree Tree;

node *new_node(int id);

node *add_sibling(node *, int id);

node *add_child(node *, int id);

void createTree(Tree *T, int id);

void createListTree(ListOfTree *L, int size);

void display_tree(node *n);






// typedef struct node *tree;

// typedef struct {
//     tree *TabTree;
//     int Size;
// }ListOfTree;

// typedef struct node {
//     int value;
//     ListOfTree content[];
// } node;



// #define r(t) ((t)->right)
// #define left(t) ((t)->left)
// #define value(t) ((t)->value)

// tree newTree(int value, int size);
// void freeTree(tree t);
// void printTree(tree t);
// int treeSize(tree t);
// int treeHeight(tree t);
// int treeSum(tree t);
// int treeMax(tree t);
// int treeMin(tree t);
// int treeDepth(tree t, int value);
// int treeCount(tree t, int value);
// int treeCountLeaves(tree t);
// int treeCountNodes(tree t);
// int treeCountFullNodes(tree t);
// int treeCountHalfNodes(tree t);
// int treeCountOddNodes(tree t);
// int treeCountEvenNodes(tree t);
// int treeCountPositiveNodes(tree t);
// int treeCountNegativeNodes(tree t);
// int treeCountZeroNodes(tree t);
// int treeCountNonZeroNodes(tree t);
// int treeCountNonPositiveNodes(tree t);
// int treeCountNonNegativeNodes(tree t);
// int treeCountNonOddNodes(tree t);
// int treeCountNonEvenNodes(tree t);
// int treeCountNonFullNodes(tree t);
// int treeCountNonHalfNodes(tree t);
// int treeCountNonLeaves(tree t);
// int treeCountNonNodes(tree t);
// int treeCountNonPositiveLeaves(tree t);
// int treeCountNonNegativeLeaves(tree t);
// int treeCountNonOddLeaves(tree t);
// int treeCountNonEvenLeaves(tree t);
// int treeCountNonFullLeaves(tree t);
// int treeCountNonHalfLeaves(tree t);
// int treeCountNonPositiveNodes(tree t);
// int treeCountNonNegativeNodes(tree t);
// int treeCountNonOddNodes(tree t);
// int treeCountNonEvenNodes(tree t);





#endif