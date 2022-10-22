
#ifndef SIMULATOR_H
#define SIMULATOR_H

#include "point.c"
#include "wordmachine.c"
#include "charmachine.c"
#include "queue.c"
#include "boolean.h"

typedef struct {
    // char idUser;
    Word idUser;
    POINT P;
    // Queue Q;
}Simulator;

#define Nama(S) (S).idUser   //Nama pengguna
#define Lokasi(S) (S).P     //Lokasi simulator
// #define Inventory(S) (S).Q  //Inventory simulator

// void CreateSimulator(Simulator *S, char nama, POINT P/*, Queue Q*/ );

void CreateSimulator(Simulator *S, Word nama, POINT P/*, Queue Q*/ );

void MoveSimulator(Simulator *S, int x);
// x = 1 --> NORTH
// x = 2 --> EAST
// x = 3 --> SOUTH 
// x = 4 --> WEST

void BacaSimulator(Simulator *S);

void DisplayNama(Simulator S);

void DisplayLokasi(Simulator S);

void DisplaySimulator(Simulator S);


#endif