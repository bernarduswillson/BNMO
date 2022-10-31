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

void buy(listMakanan b, Queue *q){
    int pilihan;

    pilihan = -1;
    while (pilihan!=0){
        printf("=====================");
        printf("=        BUY        =");
        printf("=====================");
        printf("List Bahan Makanan:");
        for (int i = 0; i<CAPACITY(b); i++){
            printf("    %d. %s ( ", i+1, NAMA(MAKANAN(b, i)));
            TulisTIME1(PENGIRIMAN(MAKANAN(b, i)));
            printf(")\n");
        }
        printf("\nKetik 0 untuk exit\n");
        printf("\nEnter Command: ");
        scanf("%d", &pilihan);
        if ((pilihan<0)||(pilihan>=CAPACITY(b))){
            printf("Pilih dari list makanan atau pilih 0 untuk exit.");
        }else if(pilihan>0){
            printf("Berhasil memesan %s, %s akan diantar dalam ", NAMA(MAKANAN(b, pilihan-1)), NAMA(MAKANAN(b, pilihan-1)));
            TulisTIME1(PENGIRIMAN(MAKANAN(b, pilihan-1)));
            printf(".");
            Add(q, MAKANAN(b, pilihan-1));
        }
    }
}

void fry(listMakanan f, PrioQueueTime *inv){
    PrioQueueTime child;
    boolean available;
    int pilihan;

    pilihan = -1;
    while (pilihan!=0){
        printf("=====================");
        printf("=        FRY        =");
        printf("=====================");
        printf("List Bahan Makanan yang Bisa Dibuat:");
        for (int i = 0; i<CAPACITY(f); i++){
            printf("    %d. %s", i+1, NAMA(MAKANAN(f, i)));
        }
        printf("\nKetik 0 untuk exit\n");
        printf("\nEnter Command: ");
        scanf("%d", &pilihan);
        if ((pilihan<0)||(pilihan>=CAPACITY(f))){
            printf("Pilih dari list makanan atau pilih 0 untuk exit.");
        }else if(pilihan>0){
            //cari child MAKANAN(f, pilihan-1) dari resep, masukin ke listMakanan child
            //cek semua makanan di child ada di inventory atau ngga
            //cara ceknya periksa HEAD(child) ada di inv atau ngga, kalau ada di dequeue
            //kalau setelah di cek, childnya kosong, berarti available = true
            if (available){
                printf("%s selesai dibuat dan sudah masuk ke inventory.");
                Enqueue(inv, MAKANAN(f, pilihan-1));
            }else{
                printf("Gagal membuat %s karena kamu tidak memiliki bahan berikut: ");
                PrintPrioQueueTime(child);
            }
        }
    }
}

void boil(listMakanan b, PrioQueueTime *inv){
    PrioQueueTime child;
    boolean available;
    int pilihan;

    pilihan = -1;
    while (pilihan!=0){
        printf("======================");
        printf("=        BOIL        =");
        printf("======================");
        printf("List Bahan Makanan yang Bisa Dibuat:");
        for (int i = 0; i<CAPACITY(b); i++){
            printf("    %d. %s", i+1, NAMA(MAKANAN(b, i)));
        }
        printf("\nKetik 0 untuk exit\n");
        printf("\nEnter Command: ");
        scanf("%d", &pilihan);
        if ((pilihan<0)||(pilihan>=CAPACITY(b))){
            printf("Pilih dari list makanan atau pilih 0 untuk exit.");
        }else if(pilihan>0){
            //cari child MAKANAN(b, pilihan-1) dari resep, masukin ke listMakanan child
            //cek semua makanan di child ada di inventory atau ngga
            //cara ceknya periksa HEAD(child) ada di inv atau ngga, kalau ada di dequeue
            //kalau setelah di cek, childnya kosong, berarti available = true
            if (available){
                printf("%s selesai dibuat dan sudah masuk ke inventory.");
                Enqueue(inv, MAKANAN(b, pilihan-1));
            }else{
                printf("Gagal membuat %s karena kamu tidak memiliki bahan berikut: ");
                PrintPrioQueueTime(child);
            }
        }
    }
}

void mix(listMakanan m, PrioQueueTime *inv){
    PrioQueueTime child;
    boolean available;
    int pilihan;

    pilihan = -1;
    while (pilihan!=0){
        printf("=======================");
        printf("=         MIX         =");
        printf("=======================");
        printf("List Bahan Makanan yang Bisa Dibuat:");
        for (int i = 0; i<CAPACITY(m); i++){
            printf("    %d. %s", i+1, NAMA(MAKANAN(m, i)));
        }
        printf("\nKetik 0 untuk exit\n");
        printf("\nEnter Command: ");
        scanf("%d", &pilihan);
        if ((pilihan<0)||(pilihan>=CAPACITY(m))){
            printf("Pilih dari list makanan atau pilih 0 untuk exit.");
        }else if(pilihan>0){
            //cari child MAKANAN(m, pilihan-1) dari resep, masukin ke listMakanan child
            //cek semua makanan di child ada di inventory atau ngga
            //cara ceknya periksa HEAD(child) ada di inv atau ngga, kalau ada di dequeue
            //kalau setelah di cek, childnya kosong, berarti available = true
            if (available){
                printf("%s selesai dibuat dan sudah masuk ke inventory.");
                Enqueue(inv, MAKANAN(m, pilihan-1));
            }else{
                printf("Gagal membuat %s karena kamu tidak memiliki bahan berikut: ");
                PrintPrioQueueTime(child);
            }
        }
    }
}


void chop(listMakanan c, PrioQueueTime *inv){
    PrioQueueTime child;
    boolean available;
    int pilihan;

    pilihan = -1;
    while (pilihan!=0){
        printf("======================");
        printf("=        CHOP        =");
        printf("======================");
        printf("List Bahan Makanan yang Bisa Dibuat:");
        for (int i = 0; i<CAPACITY(c); i++){
            printf("    %d. %s", i+1, NAMA(MAKANAN(c, i)));
        }
        printf("\nKetik 0 untuk exit\n");
        printf("\nEnter Command: ");
        scanf("%d", &pilihan);
        if ((pilihan<0)||(pilihan>=CAPACITY(c))){
            printf("Pilih dari list makanan atau pilih 0 untuk exit.");
        }else if(pilihan>0){
            //cari child MAKANAN(c, pilihan-1) dari resep, masukin ke listMakanan child
            //cek semua makanan di child ada di inventory atau ngga
            //cara ceknya periksa HEAD(child) ada di inv atau ngga, kalau ada di dequeue
            //kalau setelah di cek, childnya kosong, berarti available = true
            if (available){
                printf("%s selesai dibuat dan sudah masuk ke inventory.");
                Enqueue(inv, MAKANAN(c, pilihan-1));
            }else{
                printf("Gagal membuat %s karena kamu tidak memiliki bahan berikut: ");
                PrintPrioQueueTime(child);
            }
        }
    }
}