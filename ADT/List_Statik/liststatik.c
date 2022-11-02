#include <stdio.h>
#include "../Boolean/boolean.h"
#include "liststatik.h"

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create List kosong  */
void CreateListStatik(ListStatik *l) {
    IdxType i;
    for (i = IDX_MIN; i < CAPACITY; i++) {
        ELMT(*l, i) = MARK;
    }
}
/* I.S. l sembarang */
/* F.S. Terbentuk List l kosong dengan kapasitas CAPACITY */
/* Proses: Inisialisasi semua elemen List l dengan MARK */

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int listLength(ListStatik l) {
    IdxType i;
    int count = 0;
    for (i = IDX_MIN; i < CAPACITY; i++) {
        if (ELMT(l, i) != MARK) {
            count++;
        }
    }
    return count;
}
/* Mengirimkan banyaknya elemen efektif List */
/* Mengirimkan nol jika List kosong */  

/* *** Selektor INDEKS *** */
IdxType getFirstIdx(ListStatik l) {
    IdxType i;
    for (i = IDX_MIN; i < CAPACITY; i++) {
        if (ELMT(l, i) != MARK) {
            return i;
        }
    }
}
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l pertama */

IdxType getLastIdx(ListStatik l) {
    IdxType i;
    for (i = CAPACITY - 1; i >= IDX_MIN; i--) {
        if (ELMT(l, i) != MARK) {
            return i;
        }
    }
}
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l terakhir */

/* ********** Test Indeks yang valid ********** */
boolean isIdxValid(ListStatik l, IdxType i) {
    return (i >= IDX_MIN && i < CAPACITY);
}
/* Mengirimkan true jika i adalah indeks yang valid utk kapasitas List l */
/* yaitu antara indeks yang terdefinisi utk container*/

boolean isIdxEff(ListStatik l, IdxType i) {
    return (i >= IDX_MIN && i < listLength(l));
}
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk List l */
/* yaitu antara 0..length(l)-1 */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test List kosong *** */
boolean isEmpty(ListStatik l) {
    return (listLength(l) == 0);
}
/* Mengirimkan true jika List l kosong, mengirimkan false jika tidak */
/* *** Test List penuh *** */

boolean isFull(ListStatik l) {
    return (listLength(l) == CAPACITY);
}
/* Mengirimkan true jika List l penuh, mengirimkan false jika tidak */

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi List dari pembacaan *** */
void readList(ListStatik *l) {
    int n;
    IdxType i;
    CreateListStatik(l);
    scanf("%d", &n);
    while (n < 0 || n > CAPACITY) {
        scanf("%d", &n);
    }
    for (i = IDX_MIN; i < n; i++){
        scanf("%d", &ELMT(*l, i));
    }
}
/* I.S. l sembarang */
/* F.S. List l terdefinisi */
/* Proses: membaca banyaknya elemen l dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya n */
/*    Pembacaan diulangi sampai didapat n yang benar yaitu 0 <= n <= CAPACITY */
/*    Jika n tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < n <= CAPACITY; Lakukan n kali: 
          Baca elemen mulai dari indeks 0 satu per satu diakhiri enter */
/*    Jika n = 0; hanya terbentuk List kosong */

void printList(ListStatik l) {
    IdxType i;
    if (isEmpty(l)) {
        printf("[]");
    } 
    else {
        printf("[");
        for (i = IDX_MIN; i < listLength(l) - 1; i++) {
            printf("%d,", ELMT(l, i));
        }
        printf("%d]", ELMT(l, i));
    }
}
/* Proses : Menuliskan isi List dengan traversal, List ditulis di antara kurung 
   siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan 
   karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. l boleh kosong */
/* F.S. Jika l tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika List kosong : menulis [] */

/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika List : Penjumlahan, pengurangan, perkalian, ... *** */
ListStatik plusMinusList(ListStatik l1, ListStatik l2, boolean plus) {
    ListStatik l3;
    IdxType i;
    CreateListStatik(&l3);
    if (plus) {
        for (i = IDX_MIN; i < listLength(l1); i++) {
            ELMT(l3, i) = ELMT(l1, i) + ELMT(l2, i);
        }
    } 
    else {
        for (i = IDX_MIN; i < listLength(l1); i++) {
            ELMT(l3, i) = ELMT(l1, i) - ELMT(l2, i);
        }
    }
    return l3;
}
/* Prekondisi : l1 dan l2 berukuran sama dan tidak kosong */
/* Jika plus = true, mengirimkan  l1+l2, yaitu setiap elemen l1 dan l2 pada 
       indeks yang sama dijumlahkan */
/* Jika plus = false, mengirimkan l1-l2, yaitu setiap elemen l1 dikurangi 
       elemen l2 pada indeks yang sama */

/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan List: *** */
boolean isListEqual(ListStatik l1, ListStatik l2) {
    IdxType i;
    if (listLength(l1) != listLength(l2)) {
        return false;
    } 
    else {
        for (i = IDX_MIN; i < listLength(l1); i++) {
            if (ELMT(l1, i) != ELMT(l2, i)) {
                return false;
            }
        }
        return true;
    }
}
/* Mengirimkan true jika l1 sama dengan l2 yaitu jika ukuran l1 = l2 dan semua 
   elemennya sama */

/* ********** SEARCHING ********** */
/* ***  Perhatian : List boleh kosong!! *** */
int indexOf(ListStatik l, ElType val) {
    IdxType i;
    for (i = IDX_MIN; i < listLength(l); i++) {
        if (ELMT(l, i) == val) {
            return i;
        }
    }
    return IDX_UNDEF;
}
/* Search apakah ada elemen List l yang bernilai val */
/* Jika ada, menghasilkan indeks i terkecil, dengan ELMT(l,i) = val */
/* Jika tidak ada atau jika l kosong, mengirimkan IDX_UNDEF */
/* Skema Searching yang digunakan bebas */

/* ********** NILAI EKSTREM ********** */
void extremeValues(ListStatik l, ElType *max, ElType *min) {
    IdxType i;
    *max = l.contents[IDX_MIN];
    *min = l.contents[IDX_MIN];
    for (i = IDX_MIN; i < listLength(l); i++) {
        if (ELMT(l, i) > *max) {
            *max = ELMT(l, i);
        }
        if (ELMT(l, i) < *min) {
            *min = ELMT(l, i);
        }
    }
}
/* I.S. List l tidak kosong */
/* F.S. Max berisi nilai terbesar dalam l;
        Min berisi nilai terkecil dalam l */

/* ********** MENAMBAH ELEMEN ********** */
/* *** Menambahkan elemen terakhir *** */
void insertFirst(ListStatik *l, ElType val) {
    IdxType i;
    if (!isFull(*l)) {
        for (i = listLength(*l); i > IDX_MIN; i--) {
            ELMT(*l, i) = ELMT(*l, i-1);
        }
        ELMT(*l, IDX_MIN) = val;
    }
}
/* Proses: Menambahkan val sebagai elemen pertama List */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen pertama l yang baru */
/* *** Menambahkan elemen pada index tertentu *** */

void insertAt(ListStatik *l, ElType val, IdxType idx) {
    IdxType i;
    if (!isFull(*l) && isIdxValid(*l, idx)) {
        for (i = listLength(*l); i > idx; i--) {
            ELMT(*l, i) = ELMT(*l, i-1);
        }
        ELMT(*l, idx) = val;
    }
}
/* Proses: Menambahkan val sebagai elemen pada index idx List */
/* I.S. List l tidak kosong dan tidak penuh, idx merupakan index yang valid di l */
/* F.S. val adalah elemen yang disisipkan pada index idx l */
/* *** Menambahkan elemen terakhir *** */

void insertLast(ListStatik *l, ElType val) {
    if (!isFull(*l)) {
        ELMT(*l, listLength(*l)) = val;
    }
}
/* Proses: Menambahkan val sebagai elemen terakhir List */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */

/* ********** MENGHAPUS ELEMEN ********** */
/* *** Menghapus elemen pertama *** */
void deleteFirst(ListStatik *l, ElType *val) {
    IdxType i;
    if (!isEmpty(*l)) {
        *val = ELMT(*l, IDX_MIN);
        for (i = IDX_MIN; i < listLength(*l) - 1; i++) {
            ELMT(*l, i) = ELMT(*l, i+1);
        }
        ELMT(*l, listLength(*l) - 1) = MARK;
    }
}
/* Proses : Menghapus elemen pertama List */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen pertama l sebelum penghapusan, */
/*      Banyaknya elemen List berkurang satu */
/*      List l mungkin menjadi kosong */
/* *** Menghapus elemen pada index tertentu *** */

void deleteAt(ListStatik *l, ElType *val, IdxType idx) {
    IdxType i;
    if (!isEmpty(*l) && isIdxValid(*l, idx)) {
        *val = ELMT(*l, idx);
        for (i = idx; i < listLength(*l) - 1; i++) {
            ELMT(*l, i) = ELMT(*l, i+1);
        }
        ELMT(*l, listLength(*l) - 1) = MARK;
    }
}
/* Proses : Menghapus elemen pada index idx List */
/* I.S. List tidak kosong, idx adalah index yang valid di l */
/* F.S. val adalah nilai elemen pada index idx l sebelum penghapusan, */
/*      Banyaknya elemen List berkurang satu */
/*      List l mungkin menjadi kosong */
/* *** Menghapus elemen terakhir *** */

void deleteLast(ListStatik *l, ElType *val) {
    if (!isEmpty(*l)) {
        *val = ELMT(*l, listLength(*l) - 1);
        ELMT(*l, listLength(*l) - 1) = MARK;
    }
}
/* Proses : Menghapus elemen terakhir List */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
/*      Banyaknya elemen List berkurang satu */
/*      List l mungkin menjadi kosong */

/* ********** SORTING ********** */
void sortList(ListStatik *l, boolean asc) {
    IdxType i, j;
    ElType temp;
    for (i = IDX_MIN; i < listLength(*l) - 1; i++) {
        for (j = i + 1; j < listLength(*l); j++) {
            if (asc) {
                if (ELMT(*l, i) > ELMT(*l, j)) {
                    temp = ELMT(*l, i);
                    ELMT(*l, i) = ELMT(*l, j);
                    ELMT(*l, j) = temp;
                }
            } 
            else {
                if (ELMT(*l, i) < ELMT(*l, j)) {
                    temp = ELMT(*l, i);
                    ELMT(*l, i) = ELMT(*l, j);
                    ELMT(*l, j) = temp;
                }
            }
        }
    }
}
/* I.S. l boleh kosong */
/* F.S. Jika asc = true, l terurut membesar */
/*      Jika asc = false, l terurut mengecil */
/* Proses : Mengurutkan l dengan salah satu algoritma sorting,
   algoritma bebas */