#include <stdio.h>
#include <stdlib.h>
#include "../Boolean/boolean.h"
#include "stack.h"

/* ************ Prototype ************ */
/* *** Konstruktor/Kreator *** */
void CreateEmptyStack(Stack *S) {
    Top(*S) = NilStack;
}
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl */
/* jadi indeksnya antara 0.. MaxEl */
/* Ciri stack kosong : TOP bernilai Nil */
// gameState CreateState(Simulator S, Queue q, TIME time, MAP m)
gameState CreateState(Simulator S, TIME time, MAP m)
{
    gameState *g;
    g = (gameState*) malloc (sizeof(gameState));
    SIM(*g) = S;
    // QUEUE(*g) = q;
    TIme(*g) = time;
    Map(*g) = m;


    return *g;
}
/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsStackEmpty(Stack S) {
    return (Top(S) == NilStack);
}
/* Mengirim true jika Stack kosong: lihat definisi di atas */

boolean IsStackFull(Stack S) {
    return (Top(S) == MaxNEl-1);
}
/* Mengirim true jika tabel penampung nilai elemen stack penuh */

/* ************ Menambahkan sebuah elemen ke Stack ************ */
// void Push(Stack *S, Simulator Sim, Queue q, TIME time, MAP m)
void Push(Stack *S, Simulator Sim, TIME time, MAP m)
 {
    // gameState g = CreateState(Sim, q, time, m);
    gameState g = CreateState(Sim, time, m);
    Top(*S)++;
    InfoTop(*S) = g;
}
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */

/* ************ Menghapus sebuah elemen Stack ************ */
// void Pop(Stack *S, Simulator *Sim, Queue *q, TIME *time, MAP *m)
void Pop(Stack *S, Simulator *Sim, TIME *time, MAP *m)
 {
    gameState g = InfoTop(*S);
    *Sim = SIM(g);
    // *q = QUEUE(g);
    *time = TIme(g);
    *m = Map(g);
    Top(*S)--;
}
/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */

// void undo(Stack *U, Stack *R, Simulator *Sim, Queue *q, TIME *time, MAP *m)
void undo(Stack *U, Stack *R, Simulator *Sim, TIME *time, MAP *m)
{
    Simulator prevStateSim;
    // Queue prevStateQueue;
    TIME prevStateTime;
    MAP prevStateMap;
    // Push(R, *Sim, *q, *time, *m);
    Push(R, *Sim, *time, *m);
    // Pop(U, &prevStateSim, &prevStateQueue, &prevStateTime, &prevStateMap);
    Pop(U, &prevStateSim, &prevStateTime, &prevStateMap);
    *Sim = prevStateSim;
    // *q = prevStateQueue;
    *time = prevStateTime;
    *m = prevStateMap;
}

// void redo(Stack *U, Stack *R, Simulator *Sim, Queue *q, TIME *time, MAP *m)
void redo(Stack *U, Stack *R, Simulator *Sim, TIME *time, MAP *m)
{
    Simulator prevStateSim;
    // Queue prevStateQueue;
    TIME prevStateTime;
    MAP prevStateMap;
    // Push(U, *Sim, *q, *time);
    // Pop(R, &prevStateSim, &prevStateQueue, &prevStateTime, *m);
    Push(U, *Sim, *time, *m);
    // Pop(U, &prevStateSim, &prevStateQueue, &prevStateTime, &prevStateMap);
    Pop(R, &prevStateSim, &prevStateTime, &prevStateMap);
    *Sim = prevStateSim;
    // *q = prevStateQueue;
    *time = prevStateTime;
    *m = prevStateMap;
}

void displayStack(Stack S){
    gameState g;
    
    for (int i = Top(S); i>=0; i--){
        g = S.T[i];
        DisplayLokasi(SIM(g));
        printf(" - ");
        TulisTIME1(TIme(g));
        printf("\n");

    }
}