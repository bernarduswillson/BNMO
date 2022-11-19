#include <stdio.h>
#include "ADT/Utility/inisiasi.c"
#include "ADT/Simulator/simulator.c"
#include "ADT/Time/time.c"
#include "ADT/Map/map.c"
#include "ADT/Mesin_Kata/wordmachine.c"
#include "ADT/Mesin_Karakter/charmachine.c"
#include "ADT/Stack/stack.c"
#include "ADT/Utility/notif.c"

int main() {
    // startMenu();
    STARTWORD1();
    int a;
    WordToInt(&a);
    if (a == 1) {
        Stack U;
        Stack R;
        Simulator S;
        BacaSimulator(&S);
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
                displayMap(m);
                printf("\n");
            }
            else if (p==36331){
                displayStack(R);
                redo(&U, &R, &S, &T, &m);
                DisplaySimulator(S);
                TulisTIME2(T);
                displayMap(m);
                printf("\n");
            }
            else{
                QueueN n;
                moveSim(&m, p, &S, &T, &n, &U, &R);
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