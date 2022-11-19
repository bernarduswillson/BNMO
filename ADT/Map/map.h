#ifndef MAP_H
#define MAP_H

#include "../Boolean/boolean.h"
#include "../Mesin_Kata/wordmachine.h"
#include "../Simulator/simulator.h"
#include "../Point/point.h"
#include "../Time/time.h"
#include "../Utility/notif.h"
#include "../Stack/stack.h"

#define ROW_CAP 50
#define COL_CAP 50

typedef int IdxType; /* Index baris, kolom */
typedef int ElType;
typedef struct
{
   ElType mem[ROW_CAP][COL_CAP];
   int rowEff; /* banyaknya/ukuran baris yg terdefinisi */
   int colEff; /* banyaknya/ukuran kolom yg terdefinisi */
} MAP;


void createMap(int nRows, int nCols, MAP *m);
/* Membentuk sebuah Matrix "kosong" yang siap diisi berukuran nRow x nCol di "ujung kiri" memori */
/* I.S. nRow dan nCol adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks m sesuai dengan definisi di atas terbentuk */

/* *** Selektor *** */
#define ROW_EFF(M) (M).rowEff
#define COL_EFF(M) (M).colEff
#define ELMT(M, i, j) (M).mem[(i)][(j)]

void readMap(MAP *m, int nRow, int nCol);

void displayMap(MAP m);

// void moveSim(MAP *m, Word command);
void moveSim(MAP *m, int x, Simulator *S, TIME *T, QueueN *notif, Stack *U, Stack *R, Queue *q, ListOfTree tree, listMakanan l, listMakanan BUY, listMakanan FRY, listMakanan BOIL, listMakanan MIX, listMakanan CHOP);

// boolean isCommandValid(Word command);
boolean isCommandValid(int x);


#endif