#include <stdio.h>
#include <stdlib.h>
#include "makanan.c"
#include "inventory.h"

int main(){
    Makanan m;
    listMakanan l;
    Time kedaluwarsa, pengiriman;
    int id;
    Word nama, lokasi;
    
    l.content = (Makanan*) malloc (2*sizeof(Makanan));
    CAPACITY(l) = 2;
    l.nEff = 0;
    LASTIDX(l) = IDX_UNDEF;
    printf("Masukan ID, nama, waktu kedaluwarsa, lokasi aksi, dan waktu pengiriman\n");
    
    for(int i = 0; i<CAPACITY(l); i++){
        scanf("%d %s %d %d %s %d %d", &ID(m), NAMA(m), &KEDALUWARSA(m).jam, &KEDALUWARSA(m).menit, LOKASI(m), &PENGIRIMAN(m).jam, &PENGIRIMAN(m).menit);
        MAKANAN(l, i) = m;
        LASTIDX(l)++;
        l.nEff++;
    }

    catalog(l);
    return 0;
}