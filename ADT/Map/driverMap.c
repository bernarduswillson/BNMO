#include "map.c"
#include "../Mesin_Karakter/charmachine.c"
#include "../Mesin_Kata/wordmachine.c"

int main(){
    STARTWORDFILE("../../Config/map.txt");
    // STARTWORDFILE("tesConfigMap.txt");
    MAP m;
    int row,col;
    WordToInt(&row);
    ADVWORD1();
    WordToInt(&col);
    ADVNEWLINE1();
    readMap(&m,row,col);
    displayMap(m);

    printf("TES GESER SIMULATOR\n");
    int x=0,y=0;
    // STARTWORD();
    // char p[currentWord.Length];
    // WordToStr(p);
    // DisplayWord();
    // moveSim(&m,p);

    while(y<5){
        scanf("%d", &x);
        moveSim(&m, x);
        y++;
    }
    displayMap(m);
}