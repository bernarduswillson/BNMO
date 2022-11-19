#include <stdio.h>
#include "ADT/Utility/inisiasi.c"
#include "ADT/Simulator/simulator.c"
#include "ADT/Time/time.c"
#include "ADT/Map/map.c"
#include "ADT/Mesin_Kata/wordmachine.c"
#include "ADT/Mesin_Karakter/charmachine.c"
#include "ADT/Stack/stack.c"
#include "ADT/Utility/notif.c"
#include "ADT/Tree/tree.c"
// #include "ADT/Makanan/makanan.c"
// #include "ADT/PrioQueue/prioqueuetime.c"
// #include "ADT/PrioQueue/prioqueue.c"


int main() {
    // startMenu();
    STARTWORD1();
    int a;
    WordToInt(&a);
    if (a == 1) {
        Stack U;
        Stack R;
        Simulator S;
        listMakanan l, BUY, FRY, BOIL, MIX, CHOP;
        Queue q;
        CreateEmpty(&q, 50);
        STARTWORDFILE("Config/resep.txt");
        int x;
        int n = 0;
        WordToInt(&x);
        ADVNEWLINE1();
        ListOfTree tree;
        createListTree(&tree, x);
        createMakanan(&l, &BUY, &FRY, &BOIL, &MIX, &CHOP);
        catalog(l);
        BacaSimulator(&S);
        Enqueue(&S, MAKANAN(l, 1));
        Enqueue(&S, MAKANAN(l, 0));
        printf("Num elmt = %d\n", NBElmt(Inventory(S)));
        PrintPrioQueueTime(S);
        printf("\n");
        DisplaySimulator(S);
        TIME T;
        CreateTime(&T,0,0,0);
        TulisTIME2(T);
        printf("Notifikasi: -\n");
        STARTWORDFILE("Config/map.txt");
        MAP m;
        int row,col;
        WordToInt(&row);
        ADVWORD1();
        WordToInt(&col);
        ADVNEWLINE1();
        readMap(&m,row,col);
        displayMap(m);
        printf("\n");
        boolean y = true;
        while(y) {
            QueueN n;
            int x = 0;
            printf("Enter Command: ");
            STARTWORD2();
            int p;
            WordToInt(&p);
            printf("\n");
            if (p==40231){
                displayStack(U);
                undo(&U, &R, &S, &T, &m);
                DisplaySimulator(S);
                TulisTIME2(T);
                printf("Notifikasi: ");
                displayNotif(n);
                displayMap(m);
                printf("\n");
            }
            else if (p==36331){
                displayStack(R);
                redo(&U, &R, &S, &T, &m);
                DisplaySimulator(S);
                TulisTIME2(T);
                printf("Notifikasi: ");
                displayNotif(n);
                displayMap(m);
                printf("\n");
            }
            else{
                moveSim(&m, p, &S, &T, &n, &U, &R, &q, tree, l, BUY, FRY, BOIL, MIX, CHOP);
                DisplaySimulator(S);
                TulisTIME2(T);
                printf("Notifikasi: ");
                displayNotif(n);
                displayMap(m);
                printf("\n");
            }
            y++;
        }

    }
    else if (a == 2) {
        printf("Terima kasih telah bermain!\n");
        exit(0);
    }
    else {
        printf("Input tidak valid\n");
    }
    return 0;
}