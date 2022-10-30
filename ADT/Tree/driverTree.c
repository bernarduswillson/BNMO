#include "tree.c"

int main(){
    int N, id, child, idchild;
    
    scanf("%d", &N);
    for (int i = 0; i<N; i++){
        scanf("%d %d", &id, &child);
        tree T = newTree(id, child);
        printTree(T);
        printf("\n");
    }
    return 0;
}