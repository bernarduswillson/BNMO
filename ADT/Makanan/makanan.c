#include <stdio.h>
#include "makanan.h"

void createListMakanan(listMakanan *l, int size)
    {
        CAPACITY(*l) = size;
        CONTENT(*l) = (Makanan *) malloc(size * sizeof(Makanan));
        LASTIDX(*l) = IDX_UNDEF;
    }

void createMakanan(listMakanan *l)
    {
        STARTWORDFILE("../../Config/makanan.txt");
        int size;
        WordToInt(&size);
        CAPACITY(*l) = size;
        createListMakanan(l, size);
        for(int i = 0; i < size; i++){
            ADVNEWLINE1();
            int id;
            WordToInt(&id);
            ID(MAKANAN(*l, i)) = id;
            ADVNEWLINE2();
            NAMA(MAKANAN(*l, i)) = currentWord;
            ADVNEWLINE1();
            TIME kedaluarsa;
            BacaTIME(&kedaluarsa);
            KEDALUWARSA(MAKANAN(*l, i)) = kedaluarsa;
            ADVNEWLINE1();
            TIME pengiriman;
            BacaTIME(&pengiriman);
            PENGIRIMAN(MAKANAN(*l, i)) = pengiriman;
            ADVNEWLINE1();
            AKSI(MAKANAN(*l, i)) = currentWord;
        }
    }


void catalog(listMakanan l){
    printf("List Makanan\n");
    printf("(nama - durasi kedaluwarsa - aksi yang diperlukan - delivery time)\n");
    for (int i = 0; i<CAPACITY(l); i++){
        printf("%d. %s - ", i+1, NAMA(MAKANAN(l, i)));
        TulisTIME1(KEDALUWARSA(MAKANAN(l, i)));
        printf("- %s ", AKSI(MAKANAN(l, i)));
        if((Hour(PENGIRIMAN(MAKANAN(l, i))) == 0) && (Minute(PENGIRIMAN(MAKANAN(l, i))) == 0)){
            TulisTIME1(PENGIRIMAN(MAKANAN(l, i)));
        } else {
            printf("- ");
            TulisTIME1(PENGIRIMAN(MAKANAN(l, i)));
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