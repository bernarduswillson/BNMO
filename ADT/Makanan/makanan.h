#ifndef __MAKANAN_H__
#define __MAKANAN_H__

#include "../Boolean/boolean.h"
#include "../Mesin_Kata/wordmachine.h"
#include "../PrioQueue/prioqueuetime.h"
#include "../PrioQueue/prioqueue.h"
#include "../Time/time.h"
#include "../Tree/tree.h"

#define IDX_UNDEF -1

typedef struct
{
    Makanan *content;        
    int capacity;
    int nEff;
    int lastIdx;
} listMakanan;

extern PrioQueueTime inv; 

/*----Selektor----*/
#define ID(m) (m).id
#define NAMA(m) (m).nama
#define KEDALUWARSA(m) (m).kedaluwarsa
#define AKSI(m) (m).aksi
#define PENGIRIMAN(m) (m).pengiriman

#define LASTIDX(l) (l).lastIdx
#define MAKANAN(l, i) (l).content[i]
#define CAPACITY(l) (l).capacity
#define CONTENT(l) (l).content

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

void createMakanan(listMakanan *l); 
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

void boil(listMakanan b, PrioQueueTime *inv);
    //Cek makanan yang di inventory bisa buat makanan m atau ngga, kalau bisa
    //rebus makanan yang ada di inventory, makanan yang lama dihapus
    //hasil makanan yang direbus masukin ke inventory
    //lokasi harus pas
    //I.S:
    //listMakanan ada isinya, Inventory i terdefinisi, Makanan m memiliki aksi di boil
    //F.S:
    //masukin m ke i, waktu nambah 1 menit

void mix(listMakanan m, PrioQueueTime *inv);
    //Cek makanan yang di inventory bisa buat makanan m atau ngga, kalau bisa
    //campur makanan yang ada di inventory, makanan yang lama dihapus
    //hasil makanan yang dicampur masukin ke inventory
    //lokasi harus pas
    //I.S:
    //listMakanan ada isinya, Inventory i terdefinisi, Makanan m memiliki aksi di mix
    //F.S:
    //masukin m ke i, waktu nambah 1 menit

void chop(listMakanan c, PrioQueueTime *inv);
    //Cek makanan yang di inventory bisa buat makanan m atau ngga, kalau bisa
    //potong makanan yang ada di inventory, makanan yang lama dihapus
    //hasil makanan yang dipotong masukin ke inventory
    //lokasi harus pas
    //I.S:
    //listMakanan ada isinya, Inventory i terdefinisi, Makanan m memiliki aksi di mix
    //F.S:
    //masukin m ke i, waktu nambah 1 menit

#endif