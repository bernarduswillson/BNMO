#include "time.c"
#include "../Mesin_Karakter/charmachine.c"
#include "../Mesin_Kata/wordmachine.c"

int main(){
    STARTWORDFILE("tesConfigTime.txt");
    TIME T,T2;
    BacaTIME(&T);
    ADVNEWLINE1();
    BacaTIME(&T2);
    // CreateTime(&T, 1, 0, 1);
    // long x = TIMEToMenit(T);
    // printf("%ld\n", x);
    // T = MenitToTIME(1442+1440+360);
    TulisTIME1(T);
    printf("\n");
    TulisTIME2(T);
    printf("\n");
    TulisTIME1(T2);
}