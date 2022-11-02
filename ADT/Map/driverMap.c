#include "map.c"
#include "../Mesin_Karakter/charmachine.c"
#include "../Mesin_Kata/wordmachine.c"
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
    boolean y = true;

    while(y){
        STARTWORD2();
        int p;
        WordToInt(&p);
        printf("\n");
        moveSim(&m, p, &S);
        DisplaySimulator(S);
        displayMap(m);
        printf("\n");
        y++;
    }
    // // DisplaySimulator(S);

    return 0;
}