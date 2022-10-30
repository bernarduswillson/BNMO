
#include "time.h"
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
    scanf("%d %d %d", &D, &H, &M);
    while (!IsTIMEValid(D, H, M)) {
        printf("Jam tidak valid\n");
        scanf("%d %d %d", &D, &H, &M);
    }
    CreateTime(T, D, H, M);
}

void TulisTIME (TIME T) {
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

// long Durasi (TIME TAw, TIME TAkh) {
//     if (TIMEToMenit(TAw) > TIMEToMenit(TAkh)) {
//         return (86400 + TIMEToMenit(TAkh) - TIMEToMenit(TAw));
//     }
//     else {
//         return (TIMEToMenit(TAkh)-TIMEToMenit(TAw));
//     }
// }