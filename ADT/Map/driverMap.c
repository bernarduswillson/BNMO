#include "map.c"
#include "../Mesin_Karakter/charmachine.c"
#include "../Mesin_Kata/wordmachine.c"
#include "../Point/point.c"
#include "../Simulator/simulator.c"

int main() {
    Simulator S;
    BacaSimulator(&S);
    DisplaySimulator(S);

    STARTWORDFILE("../../Config/map.txt");

    MAP m;
    int row,col;
    WordToInt(&row);
    ADVWORD1();
    WordToInt(&col);
    ADVNEWLINE1();
    readMap(&m,row,col);
    displayMap(m);

    printf("TES GESER SIMULATOR\n");
    int x=0;
    int y=0;

    while(y<5){
        STARTWORD2();
        int p;
        WordToInt(&p);
        // scanf("%d", &x);
        moveSim(&m, p,&S);
        displayMap(m);
        DisplayLokasi(S);
        // TulisPOINT(P);
        printf("\n");
        y++;
    }
    DisplaySimulator(S);

    return 0;
}