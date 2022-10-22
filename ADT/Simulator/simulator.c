
#include <stdio.h>
#include "simulator.h"

// void CreateSimulator(Simulator *S, char nama, POINT P/*, Queue Q*/ ){
//     Nama(*S) = nama;
//     Lokasi(*S) = P;
//     // Inventory(*S) = Q;
// }

void CreateSimulator(Simulator *S, Word nama, POINT P/*, Queue Q*/ ){
    Nama(*S) = nama;
    Lokasi(*S) = P;
    // Inventory(*S) = Q;
}

void BacaSimulator(Simulator *S){
    POINT P;
    
    // char nama[100];
    printf("Masukkan Nama Pengguna : ");
    STARTWORD();

    // Nama(*S) = nama;
    Kolom(P) = 0;
    Baris(P) = 0;    
    CreateSimulator(S, currentWord, P);
    ADVWORD();
}

void MoveSimulator(Simulator *S, int x){
    switch (x){
    case 1: //NORTH
        Baris(Lokasi(*S)) --;
        break;
    case 2: //EAST
        Kolom(Lokasi(*S)) ++;
        break;
    case 3: //SOUTH
        Baris(Lokasi(*S)) ++;
        break;
    case 4: //WEST
        Kolom(Lokasi(*S)) --;
        break;
    
    default:
        break;
    }
}

void DisplaySimulator(Simulator S){
    printf("Nama Pengguna :");
    DisplayNama(S);

    printf("Lokasi :");
    DisplayLokasi(S);
}

void DisplayNama(Simulator S){
    for(int i=0;i<Nama(S).Length;i++){
        printf("%c", Nama(S).TabWord[i]);
    }
    printf("\n");
}

void DisplayLokasi(Simulator S){
    printf("(%.0f,%.0f)\n", Baris(Lokasi(S)), Kolom(Lokasi(S)));
}