/*
NIM : 13521021
Nama : Bernardus Willson
Tanggal : 7 September 2022
Topik praktikum : time
Deskripsi : membuat file time.c
*/
#include "time.h"
#include <stdio.h>
#include <math.h>

boolean IsTIMEValid (int H, int M, int S) {
    return ((H>=0 && H<24) && (M>=0 && M<60) && (S>=0 && S<60));
}

void CreateTime (TIME * T, int HH, int MM, int SS) {
    Hour(*T) = HH;
    Minute(*T) = MM;
    Second(*T) = SS;
}

void BacaTIME (TIME * T) {
    int H, M, S;
    scanf("%d %d %d", &H, &M, &S);
    while (!IsTIMEValid(H, M, S)) {
        printf("Jam tidak valid\n");
        scanf("%d %d %d", &H, &M, &S);
    }
    CreateTime(T, H, M, S);
}

void TulisTIME (TIME T) {
    printf("%02d:%02d:%02d", Hour(T), Minute(T), Second(T));
}

long TIMEToDetik (TIME T) {
    return ((Hour(T)*3600 + Minute(T)*60 + Second(T)));
}

TIME DetikToTIME (long N) {
    TIME T;
    N = (N+86400) % 86400;
    CreateTime(&T, N/3600, (N%3600)/60, N%60);
    return T;
}

boolean TEQ (TIME T1, TIME T2) {
    return (TIMEToDetik(T1) == TIMEToDetik(T2));
}

boolean TNEQ (TIME T1, TIME T2) {
    return (!TEQ(T1,T2));
}

boolean TLT (TIME T1, TIME T2) {
    return (TIMEToDetik(T1) < TIMEToDetik(T2));
}

boolean TGT (TIME T1, TIME T2) {
    return (TIMEToDetik(T1) > TIMEToDetik(T2));
}

TIME NextDetik (TIME T) {
    return (DetikToTIME(TIMEToDetik(T)+1));
}

TIME NextNDetik (TIME T, int N) {
    return (DetikToTIME(TIMEToDetik(T)+N));
}

TIME PrevDetik (TIME T) {
    return (DetikToTIME(TIMEToDetik(T)-1));
}

TIME PrevNDetik (TIME T, int N) {
    return (DetikToTIME(TIMEToDetik(T)-N));
}

long Durasi (TIME TAw, TIME TAkh) {
    if (TIMEToDetik(TAw) > TIMEToDetik(TAkh)) {
        return (86400 + TIMEToDetik(TAkh) - TIMEToDetik(TAw));
    }
    else {
        return (TIMEToDetik(TAkh)-TIMEToDetik(TAw));
    }
}