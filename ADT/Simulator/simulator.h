#ifndef SIMULATOR_H
#define SIMULATOR_H

#include "../Point/point.h"
#include "../Mesin_Kata/wordmachine.h"
#include "../Mesin_Karakter/charmachine.h"
// #include "../PrioQueue/prioqueuetime.h"
#include "../Boolean/boolean.h"
#include "../Time/time.h"
#include "../Tree/tree.h"
// #include "../Makanan/makanan.h"
#define IDX_UNDEF -1

typedef int address;   /* indeks tabel */

typedef struct
{
   int id;
   Word nama;
   TIME kedaluwarsa;
   Word aksi;
   TIME pengiriman;
} Makanan;

typedef struct
{
    Makanan *content;        
    int capacity;
    int nEff;
    int lastIdx;
} listMakanan;

typedef Makanan infotypeQueue;
typedef Makanan infotype; /* elemen karakter */

typedef struct { 
    infotypeQueue T[50];   /* tabel penyimpan elemen */
    address HEAD;  /* alamat penghapusan */
    address TAIL;  /* alamat penambahan */
    int MaxEl;     /* Max elemen queue */
    } Queue;

typedef struct {
    infotype T[50];   /* tabel penyimpan elemen */
    address HEAD;  /* alamat penghapusan */
    address TAIL;  /* alamat penambahan */
    int MaxEl;     /* Max elemen queue */
} PrioQueueTime;

typedef struct {
    Word idUser;
    POINT P;
    PrioQueueTime Q;
}Simulator;
/* Contoh deklarasi variabel bertype Queue : */
/* Versi I : tabel dinamik, Head dan Tail eksplisit, ukuran disimpan */
// typedef struct { infotypeQueue T[100];   /* tabel penyimpan elemen */
//                  address HEAD;  /* alamat penghapusan */
//                  address TAIL;  /* alamat penambahan */
//                  int MaxEl;     /* Max elemen queue */
//                } Queue;


#define Nama(S) (S).idUser   //Nama pengguna
#define Lokasi(S) (S).P     //Lokasi simulator
#define Inventory(S) (S).Q  //Inventory simulator


#define Time(e)     KEDALUWARSA(e)
#define InfoNama(e) NAMA(e)
#define InfoId(e)   ID(e)
#define Head(Q)     (Q).HEAD
#define Tail(Q)     (Q).TAIL
#define InfoHead(Q) (Q).T[(Q).HEAD]
#define InfoTail(Q) (Q).T[(Q).TAIL]
#define MaxEl(Q)    (Q).MaxEl
#define Elmt(Q,i)   (Q).T[(i)]

#define Prio(e)     PENGIRIMAN(e)
//#define Sabar(e)    (e).sabar /* Tambahan infotypeQueue */
//#define Jumlah(e)   (e).jumlah /* Tambahan infotypeQueue */
#define Kepala(Q)     (Q).HEAD
#define Ekor(Q)     (Q).TAIL
#define InfoKepala(Q) (Q).T[(Q).HEAD]
#define InfoEkor(Q) (Q).T[(Q).TAIL]
#define MaxElmt(Q)    (Q).MaxEl
#define Elment(Q,i)   (Q).T[(i)]

#define ID(m) (m).id
#define NAMA(m) (m).nama
#define KEDALUWARSA(m) (m).kedaluwarsa
#define AKSI(m) (m).aksi
#define PENGIRIMAN(m) (m).pengiriman

#define LASTIDX(l) (l).lastIdx
#define MAKANAN(l, i) (l).content[i]
#define CAPACITY(l) (l).capacity
#define CONTENT(l) (l).content

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



///////////////////////////////////////////////////////////////////////////////
#define Nil 0
/* Konstanta untuk mendefinisikan address tak terdefinisi */

// typedef struct PrioQueueTime PrioQueueTime;
// typedef struct
// {
//    int id;
//    Word nama;
//    TIME kedaluwarsa;
//    Word aksi;
//    TIME pengiriman;
// } Makanan;

/* Definisi elemen dan address */
// typedef Makanan infotype; /* elemen karakter */
// typedef int address;   /* indeks tabel */

/* Contoh deklarasi variabel bertype PrioQueueTime : */
/* Versi I : tabel dinamik, Head dan Tail eksplisit, ukuran disimpan */
// typedef struct {
//     infotype * T;   /* tabel penyimpan elemen */
//     address HEAD;  /* alamat penghapusan */
//     address TAIL;  /* alamat penambahan */
//     int MaxEl;     /* Max elemen queue */
// } PrioQueueTime;
/* Definisi PrioQueueTime kosong: HEAD=Nil; TAIL=Nil. */
/* Catatan implementasi: T[0] tidak pernah dipakai */

/* ********* AKSES (Selektor) ********* */
/* Jika e adalah infotype dan Q adalah PrioQueueTime, maka akses elemen : */


/* ********* Prototype ********* */
boolean IsEmpty (PrioQueueTime Q);
/* Mengirim true jika Q kosong: lihat definisi di atas */
boolean IsFull (PrioQueueTime Q);
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxEl */
boolean IsMember(PrioQueueTime Q, int id);
/* true jika makanan dengan id 'id' ada di inventory */
int NBElmt (PrioQueueTime Q);
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */

/* *** Kreator *** */
void MakeEmpty (PrioQueueTime * Q, int Max);
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max+1 */
/* atau : jika alokasi gagal, Q kosong dg MaxEl=0 */
/* Proses : Melakukan alokasi, membuat sebuah Q kosong */

/* *** Destruktor *** */
void DeAlokasi(PrioQueueTime * Q);
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxEl(Q) diset 0 */

/* *** Primitif Add/Delete *** */
void Enqueue (PrioQueueTime * Q, infotype X);
/* Proses: Menambahkan X pada Q dengan aturan priority queue, terurut membesar berdasarkan time */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X disisipkan pada posisi yang tepat sesuai dengan prioritas,
        TAIL "maju" dengan mekanisme circular buffer; */
void Dequeue (PrioQueueTime * Q, infotype * X);
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer;
        Q mungkin kosong */

void DequeueID (PrioQueueTime * Q, infotype * X, int id);

/* Operasi Tambahan */
void PrintPrioQueueTime (PrioQueueTime Q);
/* Mencetak isi queue Q ke layar */
/* I.S. Q terdefinisi, mungkin kosong */
/* F.S. Q tercetak ke layar dengan format:
<time-1> <elemen-1>
...
<time-n> <elemen-n>
#
*/
void Kedaluwarsa(PrioQueueTime *inv);
void waitKedaluwarsa(PrioQueueTime *inv, int min);


/////////////////////////////////////////////////////////////////////////////////////////////
#define Nil 0
/* Konstanta untuk mendefinisikan address tak terdefinisi */

/* Definisi elemen dan address */
// typedef Makanan infotypeQueue;
// typedef int address;   /* indeks tabel */
// /* Contoh deklarasi variabel bertype Queue : */
// /* Versi I : tabel dinamik, Head dan Tail eksplisit, ukuran disimpan */
// typedef struct { infotypeQueue T[100];   /* tabel penyimpan elemen */
//                  address HEAD;  /* alamat penghapusan */
//                  address TAIL;  /* alamat penambahan */
//                  int MaxEl;     /* Max elemen queue */
//                } Queue;
/* Definisi Queue kosong: HEAD=Nil; TAIL=Nil. */
/* Catatan implementasi: T[0] tidak pernah dipakai */

/* ********* AKSES (Selektor) ********* */
/* Jika e adalah infotypeQueue dan Q adalah Queue, maka akses elemen : */


/* ********* Prototype ********* */
boolean IsQueueEmpty (Queue Q);
/* Mengirim true jika Q kosong: lihat definisi di atas */

boolean IsQueueFull (Queue Q);
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxEl */

int NBQueueElmt (Queue Q);
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */

/* *** Kreator *** */
void CreateEmpty (Queue * Q, int Max);
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max+1 */
/* atau : jika alokasi gagal, Q kosong dg MaxEl=0 */
/* Proses : Melakukan alokasi, membuat sebuah Q kosong */

/* *** Destruktor *** */
void DeAlokasiQueue(Queue * Q);
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxEl(Q) diset 0 */

/* *** Primitif Add/Delete *** */
void AddQueue (Queue * Q, infotypeQueue X);
/* Proses: Menambahkan X pada Q dengan aturan priority queue, terurut mengecil berdasarkan prio */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X menjadi TAIL yang baru, TAIL "maju" dengan mekanisme circular buffer;
        elemen baru disisipkan pada posisi yang tepat sesuai dengan prioritas */
void Del (Queue * Q, infotypeQueue * X);
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer;
        Q mungkin kosong */

/* Operasi Tambahan */
void showDeliveryQueue (Queue Q);
/* Mencetak isi queue Q ke layar */
/* I.S. Q terdefinisi, mungkin kosong */
/* F.S. Q tercetak ke layar dengan format:
<prio-1> <elemen-1>
...
<prio-n> <elemen-n>
#
*/

void Delivery(Queue *Q, PrioQueueTime *inv);
/* Masukin makanan ke inventory kalo delivery timenya udah 0*/

void waitDelivery(Queue *Q, PrioQueueTime *inv, int min);



//////////////////////////////////////////////////////////////////////////////////////////////////

// typedef PrioQueueTime PrioQueueTime;

// typedef struct
// {
//     Makanan *content;        
//     int capacity;
//     int nEff;
//     int lastIdx;
// } listMakanan;

// extern PrioQueueTime inv; 

/*----Selektor----*/


    //void readMakanan(); (jadinya digabung sama createMakanan)
    //Baca file makanan, buat listMakanan pake createListMakanan, manggil fungsi createMakanan buat bikin semua
    //makanan yang ada di file terus masukin ke listMakanan lewat addMakanan
    //I.S:
    //sembarang
    //F.S:
    //terbentuk listMakanan l dengan isi semua makanan sesuai bacaan dari file

void createListMakanan(listMakanan *l, int size);
    //Buat listMakanan kosong, sizenya baca dari file, lastIdx awal IDX_UNDEF
    //I.S:
    //sembarang, size dari baca file
    //F.S:
    //terbentuk listMakanan l kosong dengan ukuran size

void createMakanan(listMakanan *l, listMakanan *BUY, listMakanan *FRY, listMakanan *BOIL, listMakanan *MIX, listMakanan *CHOP); 
    //Baca file dari makanan, masukin ke variabel, trs bikin variabel makanan.
    //Buat makanan baru, isinya id, nama, waktu kedaluwarsa, lokasi aksi, waktu pengiriman
    //Masukin makanan yang baru dibikin ke listMakanan
    //I.S:
    //sembarang
    //F.S:
    //terbentuk listMakanan l dengan isi semua makanan sesuai bacaan dari file

void addMakanan(Makanan *m, listMakanan *l);
    //Masukin makanan ke listMakanan
    //I.S:
    //Makanan m dan listMakanan l terdefinisi
    //F.S:
    //m dimasukan ke l

void catalog(listMakanan l);
    //print semua makanan yang ada di listMakanan, harus udah manggil readMakanan sebelumnya,
    //list bisa kosong kalo file yang dibaca kosong
    //I.S:
    //sembarang
    //F.S:
    //display semua makanan yang ada di listMakanan l

void buy(listMakanan b, Queue *q);
    //beli makanan yang ada di listMakanan, masukin ke inventory.
    //lokasi harus pas (Makanan.lokasi harus "BUY")
    //I.S:
    //listMakanan ada isinya, Inventory i terdefinisi, Makanan m memiliki aksi di buy
    //F.S:
    //masukin Makanan m ke delivery queue (belum tau gimana) 

void fry(listMakanan l, listMakanan f, PrioQueueTime *inv, ListOfTree t);
    //Cek makanan yang di inventory bisa buat makanan m atau ngga, kalau bisa
    //goreng makanan yang ada di inventory, makanan yang lama dihapus
    //hasil makanan yang digoreng (m) masukin ke inventory
    //lokasi harus pas
    //I.S:
    //listMakanan ada isinya, Inventory i terdefinisi, Makanan m memiliki aksi di fry
    //F.S:
    //masukin m ke i, waktu nambah 1 menit

void boil(listMakanan l, listMakanan b, PrioQueueTime *inv, ListOfTree t);
    //Cek makanan yang di inventory bisa buat makanan m atau ngga, kalau bisa
    //rebus makanan yang ada di inventory, makanan yang lama dihapus
    //hasil makanan yang direbus masukin ke inventory
    //lokasi harus pas
    //I.S:
    //listMakanan ada isinya, Inventory i terdefinisi, Makanan m memiliki aksi di boil
    //F.S:
    //masukin m ke i, waktu nambah 1 menit

void mix(listMakanan l, listMakanan m, PrioQueueTime *inv, ListOfTree t);
    //Cek makanan yang di inventory bisa buat makanan m atau ngga, kalau bisa
    //campur makanan yang ada di inventory, makanan yang lama dihapus
    //hasil makanan yang dicampur masukin ke inventory
    //lokasi harus pas
    //I.S:
    //listMakanan ada isinya, Inventory i terdefinisi, Makanan m memiliki aksi di mix
    //F.S:
    //masukin m ke i, waktu nambah 1 menit

void chop(listMakanan l, listMakanan f, PrioQueueTime *inv, ListOfTree t);
    //Cek makanan yang di inventory bisa buat makanan m atau ngga, kalau bisa
    //potong makanan yang ada di inventory, makanan yang lama dihapus
    //hasil makanan yang dipotong masukin ke inventory
    //lokasi harus pas
    //I.S:
    //listMakanan ada isinya, Inventory i terdefinisi, Makanan m memiliki aksi di mix
    //F.S:
    //masukin m ke i, waktu nambah 1 menit

#endif