#include <stdio.h>
#include "ADT/Utility/inisiasi.c"
#include "ADT/Simulator/simulator.c"
#include "ADT/Time/time.c"
#include "ADT/Map/map.c"

int main() {
    startMenu();
    STARTWORD1();
    int a;
    WordToInt(&a);
    if (a == 1) {
        Simulator S;
        BacaSimulator(&S);
        printf("\n");
        DisplaySimulator(S);
        TIME T;
        CreateTime(&T,0,1,23);
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
            printf("Enter Command: ");
            STARTWORD2();
            int p;
            WordToInt(&p);
            printf("\n");
            moveSim(&m, p, &S, &T);
            DisplaySimulator(S);
            TulisTIME2(T);
            printf("Notifikasi: -\n");
            displayMap(m);
            printf("\n");
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