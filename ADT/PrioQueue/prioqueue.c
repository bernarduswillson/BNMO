#include <stdio.h>
#include <stdlib.h>

#include "prioqueue.h"
#include "prioqueuetime.h"


/* ********* Prototype ********* */
boolean IsQueueEmpty (Queue Q)
{
/* Mengirim true jika Q kosong: lihat definisi di atas */
    return (Head(Q)==Nil && Tail(Q)==Nil);
}


boolean IsQueueFull (Queue Q)
{
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxEl */
    //kamus
    int hitung;
    //Algoritma
        hitung = ((Tail(Q)-Head(Q)+MaxEl(Q)) % MaxEl(Q)) + 1;
    return (hitung == MaxEl(Q));
}


int NBQueueElmt (Queue Q){
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */
    //Kamus
    int count;
    //Algoritma
    if (IsQueueEmpty(Q))
    {
        count = 0;
    }
    else 
    {
        count = ((Tail(Q) - Head(Q) + MaxEl(Q)) % MaxEl(Q) + 1);
    }
    return (count);
}


/* *** Kreator *** */
void CreateEmpty (Queue * Q, int Max)
{
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max+1 */
/* atau : jika alokasi gagal, Q kosong dg MaxEl=0 */
/* Proses : Melakukan alokasi, membuat sebuah Q kosong */
     //Kamus
    //Algoritma
    (*Q).T = (infotypeQueue *) malloc ((Max+1) * sizeof (infotypeQueue));
    if ((*Q).T != NULL)
    {
        MaxEl(*Q) = Max;
        Head(*Q) = Nil;
        Tail(*Q) = Nil;
    } 
    else //Alokasi gagal
    {
        MaxEl(*Q) = 0;
    }
}


/* *** Destruktor *** */
void DeAlokasiQueue(Queue * Q)
{
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxEl(Q) diset 0 */
    //Kamus
   //Algoritma
    MaxEl(*Q) = 0;
    free((*Q).T);
}


/* *** Primitif Add/Delete *** */
void AddQueue (Queue * Q, infotypeQueue X)
{
/* Proses: Menambahkan X pada Q dengan aturan priority queue, terurut mengecil berdasarkan prio */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X menjadi TAIL yang baru, TAIL "maju" dengan mekanisme circular buffer;
        elemen baru disisipkan pada posisi yang tepat sesuai dengan prioritas */
    //Kamus
    int indeks;
    infotypeQueue temp;
    //Algoritma
    if (IsQueueEmpty(*Q))
    {
        Head(*Q)=1;
        Tail(*Q)=1;
        InfoTail(*Q)=X;

    } 
    else
    {
        Tail(*Q) = Tail(*Q) + 1;
        InfoTail(*Q) = X;
        indeks = Tail(*Q);
        while (( TGT(Prio(Elmt(*Q,indeks)), Prio(Elmt(*Q,indeks-1)))) && (indeks-1!=0)){
            temp = Elmt(*Q,indeks);
            Elmt(*Q,indeks) = Elmt(*Q,indeks-1);
            Elmt(*Q,indeks-1)=temp;
            indeks = indeks - 1;
        }
    }
}


void Del (Queue * Q, infotypeQueue * X)
{
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "maju";
        Q mungkin kosong */
    //Kamus Lokal
    int indeks;
    //Algoritma
    *X = InfoHead(*Q);
    if ((!IsQueueEmpty(*Q)) && (Head(*Q) == Tail(*Q))) { /* Satu elemen */
        Head (*Q) = Nil;
        Tail(*Q) = Nil;
    } else {
        indeks = 1;
        do {
            Elmt(*Q,indeks) = Elmt(*Q,indeks+1); 
            indeks = indeks + 1;
        } while (indeks != Tail(*Q));
    }   Tail(*Q) = Tail(*Q) - 1;
}

/* Operasi Tambahan */
void showDeliveryQueue (Queue Q)
{
/* Mencetak isi queue Q ke layar */
/* I.S. Q terdefinisi, mungkin kosong */
/* F.S. Q tercetak ke layar dengan format:
Waiting Cust
<jumlah-1>
...
<jumlah-n>
#
*/
    printf("List Makanan di Perjalanan");
    printf("(nama - waktu sisa delivery)");
    for (int i = 0; i < NBQueueElmt(Q); i++){
        printf("%d. ", i+1);
        DisplayWord(NAMA(Elmt(Q, i)));
        printf(" - ");
        TulisTIME1(PENGIRIMAN(Elmt(Q,i)));
    }
}

void Delivery(Queue *Q, PrioQueueTime *inv){
    infotype X;
    
    if (TIMEToMenit(Prio(InfoHead(*Q)))==0){
        Del(Q, &X);
        Enqueue(inv, X);
    }
}
