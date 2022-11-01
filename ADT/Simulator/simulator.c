
#include <stdio.h>
#include "simulator.h"


void CreateSimulator(Simulator *S, Word nama,POINT P, PrioQueueTime Q){
    Nama(*S) = nama;
    Lokasi(*S) = P;
    Inventory(*S) = Q;
}

void BacaSimulator(Simulator *S){
    POINT P;
    PrioQueueTime Q;
    printf("Input Username :");
    STARTWORD1();
    // Nama(*S) = currentWord;
    Kolom(P) = 0;
    Baris(P) = 0;    
    // Lokasi(*S) = P;
    // Inventory(*S) = Q;
    CreateSimulator(S,currentWord,P,Q);
}

// void MoveSimulator(Simulator *S, int x){
//     switch (x){
//     case 1: //NORTH
//         Baris(Lokasi(*S)) --;
//         break;
//     case 2: //EAST
//         Kolom(Lokasi(*S)) ++;
//         break;
//     case 3: //SOUTH
//         Baris(Lokasi(*S)) ++;
//         break;
//     case 4: //WEST
//         Kolom(Lokasi(*S)) --;
//         break;
    
//     default:
//         break;
//     }
// }

void DisplaySimulator(Simulator S){
    // printf("Nama Pengguna :");
    // DisplayNama(S);

    // printf("Lokasi :");
    // DisplayLokasi(S);
    DisplayNama(S);
    printf(" berada di posisi:");
    DisplayLokasi(S);
    // printf("\n");
}

void DisplayNama(Simulator S){
    printf("%s", Nama(S));
}

void DisplayLokasi(Simulator S){
    printf("(%d,%d)\n", Baris(Lokasi(S)), Kolom(Lokasi(S)));
}