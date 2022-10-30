#include <stdio.h>
#include "makanan.h"

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

void catalog(listMakanan l){
    printf("List Makanan\n");
    printf("(nama - durasi kedaluwarsa - aksi yang diperlukan - delivery time\n");
    for (int i = 0; i<CAPACITY(l); i++){
        printf("%d. %s - ", i+1, NAMA(MAKANAN(l, i)));
        if (Hour(KEDALUWARSA(MAKANAN(l, i)))>0){
            printf("%d jam ", Hour(KEDALUWARSA(MAKANAN(l, i))));
        }
        if (Minute(KEDALUWARSA(MAKANAN(l, i)))>0){
            printf("%d menit ", Minute(KEDALUWARSA(MAKANAN(l, i))));
        }
        if ((Hour(KEDALUWARSA(MAKANAN(l, i)))==0)&&(Minute(KEDALUWARSA(MAKANAN(l, i)))==0)){
            printf("0 ");
        }
        printf("- %s - ", AKSI(MAKANAN(l, i)));
        if (Hour(PENGIRIMAN(MAKANAN(l, i)))>0){
            printf("%d jam ", Hour(PENGIRIMAN(MAKANAN(l, i))));
        }
        if (Minute(PENGIRIMAN(MAKANAN(l, i)))>0){
            printf("%d menit", Minute(PENGIRIMAN(MAKANAN(l, i))));
        }if ((Hour(PENGIRIMAN(MAKANAN(l, i)))==0)&&(Minute(PENGIRIMAN(MAKANAN(l, i)))==0)){
            printf("0 ");
        }
        printf("\n");
    }
}

void buy(listMakanan l, PrioQueueTime *i, Makanan m);
    //beli makanan yang ada di listMakanan, masukin ke inventory.
    //lokasi harus pas (Makanan.lokasi harus "BUY")
    //I.S:
    //listMakanan ada isinya, Inventory i terdefinisi, Makanan m memiliki aksi di buy
    //F.S:
    //masukin Makanan m ke delivery queue (belum tau gimana) 

void fry(listMakanan l, PrioQueueTime *i, Makanan m);
    //Cek makanan yang di inventory bisa buat makanan m atau ngga, kalau bisa
    //goreng makanan yang ada di inventory, makanan yang lama dihapus
    //hasil makanan yang digoreng (m) masukin ke inventory
    //lokasi harus pas
    //I.S:
    //listMakanan ada isinya, Inventory i terdefinisi, Makanan m memiliki aksi di fry
    //F.S:
    //masukin m ke i, waktu nambah 1 menit

void boil(listMakanan l, PrioQueueTime *i);
    //Cek makanan yang di inventory bisa buat makanan m atau ngga, kalau bisa
    //rebus makanan yang ada di inventory, makanan yang lama dihapus
    //hasil makanan yang direbus masukin ke inventory
    //lokasi harus pas
    //I.S:
    //listMakanan ada isinya, Inventory i terdefinisi, Makanan m memiliki aksi di boil
    //F.S:
    //masukin m ke i, waktu nambah 1 menit

void mix(listMakanan l, PrioQueueTime *i);
    //Cek makanan yang di inventory bisa buat makanan m atau ngga, kalau bisa
    //campur makanan yang ada di inventory, makanan yang lama dihapus
    //hasil makanan yang dicampur masukin ke inventory
    //lokasi harus pas
    //I.S:
    //listMakanan ada isinya, Inventory i terdefinisi, Makanan m memiliki aksi di mix
    //F.S:
    //masukin m ke i, waktu nambah 1 menit

void chop(listMakanan l, PrioQueueTime *i);
    //Cek makanan yang di inventory bisa buat makanan m atau ngga, kalau bisa
    //potong makanan yang ada di inventory, makanan yang lama dihapus
    //hasil makanan yang dipotong masukin ke inventory
    //lokasi harus pas
    //I.S:
    //listMakanan ada isinya, Inventory i terdefinisi, Makanan m memiliki aksi di mix
    //F.S:
    //masukin m ke i, waktu nambah 1 menit