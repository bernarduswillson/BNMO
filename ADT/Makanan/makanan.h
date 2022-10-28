#ifndef MAKANAN_H
#define MAKANAN_H

#include "../Boolean/boolean.h"
#include "../Time/time.h"
#include "../Mesin_Kata/wordmachine.h"
#include "../List_Dinamis/listdinamis.h"

typedef struct {
    int id;
    char nama[50];
    Time kedaluwarsa;
    char lokasi;
    Time pengiriman;
} Makanan;

typedef struct {
    Makanan* content;        //Nanti pake listdinamis, masih bingung
    int capacity;
    int nEff;
    int lastIdx;
} listMakanan;

/*----Selektor----*/
#define ID(m) (m).id
#define NAMA(m) (m).nama
#define KEDALUWARSA(m) (m).kedaluwarsa
#define LOKASI(m) (m).lokasi
#define PENGIRIMAN(m) (m).pengiriman

#define LASTIDX(l) (l).lastIdx
#define MAKANAN(l, i) (l).content[i]

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

void createMakanan(/*file?*/, listMakanan *l); 
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

void buy(listMakanan l, Inventory *i, Makanan m);
    //beli makanan yang ada di listMakanan, masukin ke inventory.
    //lokasi harus pas (Makanan.lokasi harus "BUY")
    //I.S:
    //listMakanan ada isinya, Inventory i terdefinisi, Makanan m memiliki aksi di buy
    //F.S:
    //masukin Makanan m ke delivery queue (belum tau gimana) 

void fry(listMakanan l, Inventory *i, Makanan m);
    //Cek makanan yang di inventory bisa buat makanan m atau ngga, kalau bisa
    //goreng makanan yang ada di inventory, makanan yang lama dihapus
    //hasil makanan yang digoreng (m) masukin ke inventory
    //lokasi harus pas
    //I.S:
    //listMakanan ada isinya, Inventory i terdefinisi, Makanan m memiliki aksi di fry
    //F.S:
    //masukin m ke i, waktu nambah 1 menit

void boil(listMakanan l, Inventory *i);
    //Cek makanan yang di inventory bisa buat makanan m atau ngga, kalau bisa
    //rebus makanan yang ada di inventory, makanan yang lama dihapus
    //hasil makanan yang direbus masukin ke inventory
    //lokasi harus pas
    //I.S:
    //listMakanan ada isinya, Inventory i terdefinisi, Makanan m memiliki aksi di boil
    //F.S:
    //masukin m ke i, waktu nambah 1 menit

void mix(listMakanan l, Inventory *i);
    //Cek makanan yang di inventory bisa buat makanan m atau ngga, kalau bisa
    //campur makanan yang ada di inventory, makanan yang lama dihapus
    //hasil makanan yang dicampur masukin ke inventory
    //lokasi harus pas
    //I.S:
    //listMakanan ada isinya, Inventory i terdefinisi, Makanan m memiliki aksi di mix
    //F.S:
    //masukin m ke i, waktu nambah 1 menit

void chop(listMakanan l, Inventory *i);
    //Cek makanan yang di inventory bisa buat makanan m atau ngga, kalau bisa
    //potong makanan yang ada di inventory, makanan yang lama dihapus
    //hasil makanan yang dipotong masukin ke inventory
    //lokasi harus pas
    //I.S:
    //listMakanan ada isinya, Inventory i terdefinisi, Makanan m memiliki aksi di mix
    //F.S:
    //masukin m ke i, waktu nambah 1 menit

#endif