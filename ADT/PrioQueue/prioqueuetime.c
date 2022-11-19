// #include <stdio.h>
// #include <stdlib.h>
// #include "../Boolean/boolean.h"
// #include "prioqueuetime.h"

// /* ********* Prototype ********* */
// boolean IsEmpty(PrioQueueTime Q) {
//     return (Head(Q) == Nil && Tail(Q) == Nil);
// }
// /* Mengirim true jika Q kosong */

// boolean IsFull(PrioQueueTime Q) {
//     return (MaxEl(Q) == NBElmt(Q));
// }
// /* Mengirim true jika tabel penampung elemen Q sudah penuh */
// /* yaitu mengandung elemen sebanyak MaxEl */

// boolean IsMember(PrioQueueTime Q, int id){
//     address p;
//     p = Head(Q);
//     while (p!=Tail(Q)+1){
//         if (InfoId(Elmt(Q, p))==id){
//             return true;
//         }
//         p++;
//     }
//     return false;
// }

// int NBElmt(PrioQueueTime Q) {    
//     if (IsEmpty(Q)) {
//         return 0;
//     }
//     else if (Tail(Q) >= Head(Q)) {
//         return Tail(Q) - Head(Q) + 1;
//     }
//     else {
//         return MaxEl(Q) - Head(Q) + Tail(Q) + 1;
//     }
// }
// /* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */

// /* *** Kreator *** */
// void MakeEmpty(PrioQueueTime *Q, int Max) {
//     (*Q).T = (infotype *)malloc((Max) * sizeof(infotype));
//     if ((*Q).T == NULL) {
//         MaxEl(*Q) = 0;
//     }
//     else {
//         MaxEl(*Q) = Max;
//         Head(*Q) = Nil;
//         Tail(*Q) = Nil;
//     }
// }
// /* I.S. sembarang */
// /* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
// /* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max+1 */
// /* atau : jika alokasi gagal, Q kosong dg MaxEl=0 */
// /* Proses : Melakukan alokasi, membuat sebuah Q kosong */

// /* *** Destruktor *** */
// void DeAlokasi(PrioQueueTime *Q) {
//     MaxEl(*Q) = 0;
//     Head(*Q) = Nil;
//     Tail(*Q) = Nil;
//     free((*Q).T);
// }
// /* Proses: Mengembalikan memori Q */
// /* I.S. Q pernah dialokasi */
// /* F.S. Q menjadi tidak terdefinisi lagi, MaxEl(Q) diset 0 */

// /* *** Primitif Add/Delete *** */
// void Enqueue(PrioQueueTime *Q, infotype X) {
//     boolean found;
//     int idx;
//     int i, j;
//     infotype temp;
//     if (IsEmpty(*Q)) {
//         Head(*Q) = 0;
//         Tail(*Q) = 0;
//         InfoTail(*Q) = X;
//     }
//     else {
//         Tail(*Q) = Tail(*Q) == MaxEl(*Q) - 1 ? 0 : Tail(*Q) + 1;
//         InfoTail(*Q) = X;
//         i = Tail(*Q);
//         j = i == 0 ? MaxEl(*Q) - 1 : i - 1;
//         while ((i != Head(*Q)) /*&& (Time(Elmt(*Q, i)) < (Time(Elmt(*Q, j))))   pake compare time*/) {
//             temp = Elmt(*Q, i);
//             Elmt(*Q, i) = Elmt(*Q, j);
//             Elmt(*Q, j) = temp;
//             i = j;
//             j = i == 0 ? MaxEl(*Q) - 1 : i - 1;
//         }
//     }
// }
// /* Proses: Menambahkan X pada Q dengan aturan priority queue, terurut membesar berdasarkan time */
// /* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
// /* F.S. X disisipkan pada posisi yang tepat sesuai dengan prioritas,
//         TAIL "maju" dengan mekanisme circular buffer; */

// void Dequeue(PrioQueueTime *Q, infotype *X) {
//     if (NBElmt(*Q) == 1) {
//         *X = InfoHead(*Q);
//         Head(*Q) = Nil;
//         Tail(*Q) = Nil;
//     }
//     else {
//         *X = InfoHead(*Q);
//         Head(*Q) = (Head(*Q) == MaxEl(*Q) - 1) ? 0 : Head(*Q) + 1;
//     }
// }

// void DequeueID(PrioQueueTime *Q, infotype *X, int id) {
//     boolean found;
//     int idx;
    
//     if (NBElmt(*Q) == 1) {
//         if (ID(InfoHead(*Q))==id){
//             *X = InfoHead(*Q);
//             Head(*Q) = Nil;
//             Tail(*Q) = Nil;
//         }
//     }
//     else {
//         idx = (int) Head(*Q);
//         found = false;
//         while (!false&&(idx<NBElmt(*Q))){
//             if (ID(Elmt(*Q, idx))==id){
//                 *X = Elmt(*Q, idx);
//                 found = true;
//                 if (idx==Head(*Q)){
//                     Head(*Q)++;
//                 }else{
//                     idx %= NBElmt(*Q);
//                     while (idx<(int) Tail(*Q)){
//                         Elmt(*Q, idx) = Elmt(*Q, (idx+1)%NBElmt(*Q)); 
//                     idx++;                    
//                     }
//                 }
//             }
//             idx++;
//         }
//     }
// }
// /* Proses: Menghapus X pada Q dengan aturan FIFO */
// /* I.S. Q tidak mungkin kosong */
// /* F.S. X = nilai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer;
//         Q mungkin kosong */

// /* Operasi Tambahan */
// void PrintPrioQueueTime(PrioQueueTime Q) {
//     infotype val;
//     PrioQueueTime temp;
//     temp = Q;
//     if (!IsEmpty(Q)) {
//         while (!IsEmpty(temp)) {
//             Dequeue(&temp, &val);
//             printf("%d %c\n", Time(val), InfoNama(val));
//         }
//     }
//     printf("#\n");
// }
// /* Mencetak isi queue Q ke layar */
// /* I.S. Q terdefinisi, mungkin kosong */
// /* F.S. Q tercetak ke layar dengan format:
// <time-1> <elemen-1>
// ...
// <time-n> <elemen-n>
// #
// */
// void Kedaluwarsa(PrioQueueTime *inv){
//     for (int i = Head(*inv); i<= Tail(*inv); i++){
//         Time(Elmt(*inv, i)) = PrevMenit(Time(Elmt(*inv, i)));
//     }
// }

// void waitKedaluwarsa(PrioQueueTime *inv, int min){
//     for (int i = Head(*inv); i<= Tail(*inv); i++){
//         Time(Elmt(*inv, i)) = PrevNMenit(Time(Elmt(*inv, i)), min);
//     }
// }