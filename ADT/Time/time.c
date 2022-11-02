#include "time.h"
#include "../Mesin_Kata/wordmachine.h"
#include <stdio.h>
#include <math.h>

boolean IsTIMEValid (int D, int H, int M) {
    return ((H>=0 && H<24) && (M>=0 && M<60));
}

void CreateTime (TIME * T,int DD, int HH, int MM) {
    Day(*T) = DD;
    Hour(*T) = HH;
    Minute(*T) = MM;
}

void BacaTIME (TIME * T) {
    int D, H, M;
    WordToInt(&D);
    ADVWORD1();
    WordToInt(&H);
    ADVWORD1();
    WordToInt(&M);
    // scanf("%d %d %d", &D, &H, &M);
    CreateTime(T, D, H, M);
}

void TulisTIME1 (TIME T) {
    if(Day(T)!=0) {
        printf("%d hari ", Day(T));
    }
    if(Hour(T)!=0) {
        printf("%d jam ", Hour(T));
    }
    if(Minute(T)!=0) {
        printf("%d menit ", Minute(T));
    }
}

void TulisTIME2 (TIME T) {
    if(Day(T)!=0) {
        printf("%.2d.", Day(T));
    }
    // if(Hour(T)!=0) {
        printf("%.2d.", Hour(T));
    // }
    // if(Minute(T)!=0) {
        printf("%.2d", Minute(T));
    // }
}

long TIMEToMenit (TIME T) {
    return (Day(T)*1440 + Hour(T)*60 + Minute(T));
}

TIME MenitToTIME (long N) {
    TIME T;
    int D, H, M;
    D = N/1440;
    N = N%1440;
    H = N/60;
    N = N%60;
    M = N;
    
    CreateTime(&T, D, H, M);
    return T;
}

boolean TEQ (TIME T1, TIME T2) {
    return (TIMEToMenit(T1) == TIMEToMenit(T2));
}

boolean TNEQ (TIME T1, TIME T2) {
    return (!TEQ(T1,T2));
}

boolean TLT (TIME T1, TIME T2) {
    return (TIMEToMenit(T1) < TIMEToMenit(T2));
}

boolean TGT (TIME T1, TIME T2) {
    return (TIMEToMenit(T1) > TIMEToMenit(T2));
}

TIME NextMenit (TIME T) {
    return (MenitToTIME(TIMEToMenit(T)+1));
}

TIME NextNMenit (TIME T, int N) {
    return (MenitToTIME(TIMEToMenit(T)+N));
}

TIME PrevMenit (TIME T) {
    return (MenitToTIME(TIMEToMenit(T)-1));
}

TIME PrevNMenit (TIME T, int N) {
    return (MenitToTIME(TIMEToMenit(T)-N));
}

void AddAllTIME (TIME *T1, TIME *T2, TIME *T3){
    *T1 = NextMenit(*T1);
    *T2 = PrevMenit(*T2);
    *T3 = PrevMenit(*T3);
}

void AddAllNTIME (TIME *T1, TIME *T2, TIME *T3, int N){
    *T1 = NextNMenit(*T1,N);
    *T2 = PrevNMenit(*T2,N);
    *T3 = PrevNMenit(*T3,N);
}
long Durasi (TIME TAw, TIME TAkh) {
    if (TIMEToMenit(TAw) > TIMEToMenit(TAkh)) {
        return (86400 + TIMEToMenit(TAkh) - TIMEToMenit(TAw));
    }
    else {
        return (TIMEToMenit(TAkh)-TIMEToMenit(TAw));
    }
}