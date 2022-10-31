#include "map.c"
#include "../Mesin_Karakter/charmachine.c"
#include "../Mesin_Kata/wordmachine.c"
#include "../Point/point.c"

int main() {
    POINT P;
    CreatePoint(&P,0,0);
    TulisPOINT(P);
    printf("afsfa\n");

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
        STARTWORD();
        int p;
        WordToInt(&p);
        // scanf("%d", &x);
        moveSim(&m, p,&P);
        displayMap(m);
        y++;
    }

    return 0;
}