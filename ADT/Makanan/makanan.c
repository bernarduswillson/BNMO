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
        listMakanan *BUY;
        listMakanan *FRY;
        listMakanan *BOIL; 
        listMakanan *MIX;
        listMakanan *CHOP;
        STARTWORDFILE("../../Config/makanan.txt");
        int size;
        WordToInt(&size);
        CAPACITY(*l) = size;
        createListMakanan(l, size);
        createListMakanan(BUY, size);
        createListMakanan(FRY, size);
        createListMakanan(BOIL, size);
        createListMakanan(MIX, size);
        createListMakanan(CHOP, size);
        for(int i = 0; i < size; i++){
            ADVNEWLINE1();
            int id;
            WordToInt(&id);
            ID(MAKANAN(*l, i)) = id;
            ADVNEWLINE2();
            Word nama = currentWord;
            NAMA(MAKANAN(*l, i)) = nama;
            ADVNEWLINE1();
            TIME kedaluarsa;
            BacaTIME(&kedaluarsa);
            KEDALUWARSA(MAKANAN(*l, i)) = kedaluarsa;
            ADVNEWLINE1();
            TIME pengiriman;
            BacaTIME(&pengiriman);
            PENGIRIMAN(MAKANAN(*l, i)) = pengiriman;
            ADVNEWLINE1();
            Word aksi = currentWord;
            AKSI(MAKANAN(*l, i)) = aksi;
            char aksii;
            WordToStr(&aksii);
            if (aksii == "Buy"){
                int indeks = LASTIDX(*BUY);
                ID(MAKANAN(*BUY, indeks)) = id;
                NAMA(MAKANAN(*BUY, indeks)) = nama;
                KEDALUWARSA(MAKANAN(*BUY, indeks)) = kedaluarsa;
                PENGIRIMAN(MAKANAN(*BUY, indeks)) = pengiriman;
                AKSI(MAKANAN(*BUY, indeks)) = aksi;
                LASTIDX(*BUY)++;
            }
            else if (aksii == "Fry"){
                int indeks = LASTIDX(*FRY);
                ID(MAKANAN(*FRY, indeks)) = id;
                NAMA(MAKANAN(*FRY, indeks)) = nama;
                KEDALUWARSA(MAKANAN(*FRY, indeks)) = kedaluarsa;
                PENGIRIMAN(MAKANAN(*FRY, indeks)) = pengiriman;
                AKSI(MAKANAN(*FRY, indeks)) = aksi;
                LASTIDX(*FRY)++;
            }
            else if (aksii == "Boil"){
                int indeks = LASTIDX(*BOIL);
                ID(MAKANAN(*BOIL, indeks)) = id;
                NAMA(MAKANAN(*BOIL, indeks)) = nama;
                KEDALUWARSA(MAKANAN(*BOIL, indeks)) = kedaluarsa;
                PENGIRIMAN(MAKANAN(*BOIL, indeks)) = pengiriman;
                AKSI(MAKANAN(*BOIL, indeks)) = aksi;
                LASTIDX(*BOIL)++;
            }
            else if (aksii == "Mix"){
                int indeks = LASTIDX(*MIX);
                ID(MAKANAN(*MIX, indeks)) = id;
                NAMA(MAKANAN(*MIX, indeks)) = nama;
                KEDALUWARSA(MAKANAN(*MIX, indeks)) = kedaluarsa;
                PENGIRIMAN(MAKANAN(*MIX, indeks)) = pengiriman;
                AKSI(MAKANAN(*MIX, indeks)) = aksi;
                LASTIDX(*MIX)++;
            }
            else if (aksii == "Chop"){
                int indeks = LASTIDX(*CHOP);
                ID(MAKANAN(*CHOP, indeks)) = id;
                NAMA(MAKANAN(*CHOP, indeks)) = nama;
                KEDALUWARSA(MAKANAN(*CHOP, indeks)) = kedaluarsa;
                PENGIRIMAN(MAKANAN(*CHOP, indeks)) = pengiriman;
                AKSI(MAKANAN(*CHOP, indeks)) = aksi;
                LASTIDX(*CHOP)++;
            }
        }
    }


void catalog(listMakanan l){
    printf("List Makanan\n");
    printf("(nama - durasi kedaluwarsa - aksi yang diperlukan - delivery time)\n");
    for (int i = 0; i<CAPACITY(l); i++){
        printf("%d. ", i+1);
        DisplayWord(NAMA(MAKANAN(l, i)));
        printf("- ");

        TulisTIME1(KEDALUWARSA(MAKANAN(l, i)));
        printf("- ");
        DisplayWord(AKSI(MAKANAN(l,i)));
        if((Hour(PENGIRIMAN(MAKANAN(l, i))) == 0) && (Minute(PENGIRIMAN(MAKANAN(l, i))) == 0)){
            // TulisTIME1(PENGIRIMAN(MAKANAN(l, i)));
            printf("- 0");
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
            printf("    %d. ( ", i+1);
            DisplayWord(NAMA(MAKANAN(b, i)));
            TulisTIME1(PENGIRIMAN(MAKANAN(b, i)));
            printf(")\n");
        }
        printf("\nKetik 0 untuk exit\n");
        printf("\nEnter Command: ");
        scanf("%d", &pilihan);
        if ((pilihan<0)||(pilihan>=CAPACITY(b))){
            printf("Pilih dari list makanan atau pilih 0 untuk exit.");
        }else if(pilihan>0){
            printf("Berhasil memesan " );
            DisplayWord(NAMA(MAKANAN(b, pilihan-1)));
            printf(", ");
            DisplayWord(NAMA(MAKANAN(b, pilihan-1)));
            printf("akan diantar dalam ");
            TulisTIME1(PENGIRIMAN(MAKANAN(b, pilihan-1)));
            printf(".");
            AddQueue(q, (infotypeQueue) MAKANAN(b, pilihan-1));
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
                Enqueue(inv, (infotype) MAKANAN(f, pilihan-1));
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
            printf("    %d.", i+1);
            DisplayWord(NAMA(MAKANAN(b, i)));
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
                DisplayWord(NAMA(MAKANAN(b, pilihan-1)));
                printf(" selesai dibuat dan sudah masuk ke inventory.");
                Enqueue(inv, (infotype) MAKANAN(b, pilihan-1));
            }else{
                printf("Gagal membuat ");
                DisplayWord(NAMA(MAKANAN(b, pilihan-1)));
                printf("karena kamu tidak memiliki bahan berikut: ");
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
            printf("    %d. ", i+1);
            DisplayWord(NAMA(MAKANAN(m, i)));
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
                DisplayWord(NAMA(MAKANAN(m, pilihan-1)));
                printf(" selesai dibuat dan sudah masuk ke inventory.");
                Enqueue(inv, (infotype) MAKANAN(m, pilihan-1));
            }else{
                printf("Gagal membuat ");
                DisplayWord(NAMA(MAKANAN(m, pilihan-1)));
                printf("karena kamu tidak memiliki bahan berikut: ");
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
            printf("    %d. ", i+1);
            DisplayWord(NAMA(MAKANAN(c, i)));
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
                DisplayWord(NAMA(MAKANAN(c, pilihan-1)));
                printf(" selesai dibuat dan sudah masuk ke inventory.");
                Enqueue(inv, (infotype) MAKANAN(c, pilihan-1));
            }else{
                printf("Gagal membuat ");
                DisplayWord(NAMA(MAKANAN(c, pilihan-1)));
                printf("karena kamu tidak memiliki bahan berikut: ");
                PrintPrioQueueTime(child);
            }
        }
    }
}