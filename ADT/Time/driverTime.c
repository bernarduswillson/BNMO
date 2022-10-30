#include "time.c"

int main(){
    TIME T;
    CreateTime(&T, 1, 0, 1);
    long x = TIMEToMenit(T);
    // printf("%ld\n", x);
    T = MenitToTIME(1442+1440+360);
    TulisTIME(T);
}