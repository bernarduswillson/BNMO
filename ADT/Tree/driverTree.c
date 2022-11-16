#include "tree.c"
#include "../Mesin_Kata/wordmachine.c"
#include "../Mesin_Karakter/charmachine.c"

int main(){


    STARTWORDFILE("../../Config/resep.txt");
    int x;
    int n = 0;
    int child[2];
    WordToInt(&x);
    ADVNEWLINE1();
    ListOfTree T;
    createListTree(&T, x);

    node ** childfun;

    childfun = searchChild(40, T);
    printf("Dari fungsi\n");
    for (int i = 0; i<banyakChild(40, T); i++){
        printf("%d\n", IDD(childfun[i]));
    }
    //     display_tree(Root(TabTree(T,i)));
    //     printf("\n");
    // }
    // int N, id, child, idchild;
    
    // scanf("%d", &N);
    // for (int i = 0; i<N; i++){
    //     scanf("%d %d", &id, &child);
    //     tree T = newTree(id, child);
    //     printTree(T);
    //     printf("\n");
    // }
    // return 0;
}