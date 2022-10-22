
#ifndef SIMULATOR_H
#define SIMULATOR_H

#include "../Point/point.c"
#include "../Mesin_Kata/wordmachine.c"
#include "../Mesin_Karakter/charmachine.c"
#include "../PrioQueue/prioqueuetime.h"
#include "../Boolean/boolean.h"

typedef struct {
    char *idUser;
    POINT P;
    PrioQueueTime Q;
}Simulator;

#define Nama(S) (S).idUser   //Nama pengguna
#define Lokasi(S) (S).P     //Lokasi simulator
#define Inventory(S) (S).Q  //Inventory simulator

void CreateSimulator(Simulator *S, POINT P, PrioQueueTime Q);

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