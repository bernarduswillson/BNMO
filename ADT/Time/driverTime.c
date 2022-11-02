#include "time.c"
#include "../Mesin_Karakter/charmachine.c"
#include "../Mesin_Kata/wordmachine.c"

int main(){
    // STARTWORDFILE("tesConfigTime.txt");
    TIME T,T2;
    CreateTime(&T,0,0,59);
    TulisTIME2(T);
    printf("\n");
    int x=0;
    while(x<10){
        STARTWORD1();
        T = NextMenit(T);
        TulisTIME2(T);
        printf("\n");
        x++;
    }
    // BacaTIME(&T);
    // ADVNEWLINE1();
    // BacaTIME(&T2);
    // CreateTime(&T, 1, 0, 1);
    // long x = TIMEToMenit(T);
    // printf("%ld\n", x);
    // T = MenitToTIME(1442+1440+360);
    // TulisTIME1(T);
    // printf("\n");
    // TulisTIME2(T);
    // printf("\n");
    // TulisTIME1(T2);
}