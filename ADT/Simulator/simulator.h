
#ifndef SIMULATOR_H
#define SIMULATOR_H

#include "../Point/point.h"
#include "../Mesin_Kata/wordmachine.h"
#include "../Mesin_Karakter/charmachine.h"
// #include "../PrioQueue/prioqueuetime.h"
#include "../Boolean/boolean.h"

typedef int address;   /* indeks tabel */
typedef struct {
    // infotype * T;   /* tabel penyimpan elemen */
    address HEAD;  /* alamat penghapusan */
    address TAIL;  /* alamat penambahan */
    int MaxEl;     /* Max elemen queue */
} PrioQueueTime;

typedef struct {
    Word idUser;
    POINT P;
    PrioQueueTime Q;
}Simulator;



#define Nama(S) (S).idUser   //Nama pengguna
#define Lokasi(S) (S).P     //Lokasi simulator
#define Inventory(S) (S).Q  //Inventory simulator

void CreateSimulator(Simulator *S,Word nama, POINT P, PrioQueueTime Q);

// void MoveSimulator(Simulator *S, int x);
// x = 1 --> NORTH
// x = 2 --> EAST
// x = 3 --> SOUTH 
// x = 4 --> WEST

void BacaSimulator(Simulator *S);

void DisplayNama(Simulator S);

void DisplayLokasi(Simulator S);

void DisplaySimulator(Simulator S);


#endif