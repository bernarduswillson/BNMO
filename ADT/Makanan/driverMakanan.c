#include <stdio.h>
#include <stdlib.h>
#include "makanan.c"
#include "../PrioQueue/prioqueuetime.c"
#include "../PrioQueue/prioqueue.c"
#include "../Mesin_Kata/wordmachine.c"
#include "../Mesin_Karakter/charmachine.c"
#include "../Time/time.c"

// int mmain(){
//     Makanan m;
//     listMakanan l;
//     TIME kedaluwarsa, pengiriman;
//     int id;
//     Word nama, lokasi;
    
//     l.content = (Makanan*) malloc (2*sizeof(Makanan));
//     CAPACITY(l) = 2;
//     l.nEff = 0;
//     LASTIDX(l) = IDX_UNDEF;
//     printf("Masukan ID, nama, waktu kedaluwarsa, lokasi aksi, dan waktu pengiriman\n");
    
//     for(int i = 0; i<CAPACITY(l); i++){
//         scanf("%d %s %d %d %s %d %d", &ID(m), NAMA(m), &Hour(KEDALUWARSA(m)), &Minute(KEDALUWARSA(m)), AKSI(m), &Hour(PENGIRIMAN(m)), &Minute(PENGIRIMAN(m)));
//         MAKANAN(l, i) = m;
//         LASTIDX(l)++;
//         l.nEff++;
//     }

//     catalog(l);
//     return 0;
// }

int main(){
    listMakanan l;
    createMakanan(&l);
    catalog(l);
    catalog(BUY);
    catalog(CHOP);
    catalog(MIX);

    return 0;
}