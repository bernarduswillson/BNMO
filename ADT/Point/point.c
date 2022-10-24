#include "point.h"
#include <stdio.h>
#include <math.h>

/* *** DEFINISI PROTOTIPE PRIMITIF *** */
/* *** Konstruktor membentuk POINT *** */
void CreatePoint (POINT *P, float X, float Y) {
    Kolom(*P) = X;
    Baris(*P) = Y;
}
/* Membentuk sebuah POINT dari komponen-komponennya */

/* *** KELOMPOK Interaksi dengan I/O device, BACA/TULIS  *** */
void BacaPOINT (POINT *P) {
    float X, Y;
    scanf("%f %f", &X, &Y);
    CreatePoint(P, X, Y);
}
/* Membaca nilai Kolom dan Baris dari keyboard dan membentuk 
   POINT P berdasarkan dari nilai Kolom dan Baris tersebut */
/* Komponen X dan Y dibaca dalam 1 baris, dipisahkan 1 buah spasi */
/* Contoh: 1 2 
   akan membentuk POINT <1,2> */
/* I.S. Sembarang */
/* F.S. P terdefinisi */

void TulisPOINT (POINT P) {
    printf("(%.2f,%.2f)", Kolom(P), Baris(P));
}
/* Nilai P ditulis ke layar dengan format "(X,Y)" 
   tanpa spasi, enter, atau karakter lain di depan, belakang, 
   atau di antaranya 
   Output X dan Y harus dituliskan dalam bilangan riil dengan 2 angka di belakang koma.
*/
/* I.S. P terdefinisi */
/* F.S. P tertulis di layar dengan format "(X,Y)" */                

/* *** Kelompok operasi relasional terhadap POINT *** */
boolean EQ (POINT P1, POINT P2) {
    return ((Kolom(P1) == Kolom(P2)) && (Baris(P1) == Baris(P2)));
}
/* Mengirimkan true jika P1 = P2 : Kolom dan Barisnya sama */

boolean NEQ (POINT P1, POINT P2) {
    return ((Kolom(P1) != Kolom(P2)) || (Baris(P1) != Baris(P2)));
}
/* Mengirimkan true jika P1 tidak sama dengan P2 */

/* *** Kelompok menentukan di mana P berada *** */
boolean IsOrigin (POINT P) {
    return ((Kolom(P) == 0) && Baris(P) == 0);
}
/* Menghasilkan true jika P adalah titik origin */

boolean IsOnSbX (POINT P) {
    return (Baris(P) == 0);
}
/* Menghasilkan true jika P terletak Pada sumbu X */

boolean IsOnSbY (POINT P) {
    return (Kolom(P) == 0);
}
/* Menghasilkan true jika P terletak pada sumbu Y */

int Kuadran (POINT P) {
    if ((Kolom(P) > 0) && (Baris(P) > 0)) {
        return 1;
    }
    else if ((Kolom(P) < 0) && (Baris(P) > 0)) {
        return 2;
    }
    else if ((Kolom(P) < 0) && (Baris(P) < 0)) {
        return 3;
    }
    else if ((Kolom(P) > 0) && (Baris(P) < 0)) {
        return 4;
    }
}
/* Menghasilkan kuadran dari P: 1, 2, 3, atau 4 */
/* Prekondisi : P bukan titik origin, */
/*              dan P tidak terletak di salah satu sumbu */

/* *** KELOMPOK OPERASI LAIN TERHADAP TYPE *** */ 
POINT NextX (POINT P) {
    CreatePoint(&P, Kolom(P)+1, Baris(P));
    return P;
}
/* Mengirim salinan P dengan Kolom ditambah satu */   

POINT NextY (POINT P) {
    CreatePoint(&P, Kolom(P), Baris(P)+1);
    return P;
}
/* Mengirim salinan P dengan Baris ditambah satu */

POINT PlusDelta (POINT P, float deltaX, float deltaY) {
    CreatePoint(&P, Kolom(P) + deltaX, Baris(P) + deltaY);
    return P;
}
/* Mengirim salinan P yang Kolomnya adalah Kolom(P) + deltaX dan Barisnya adalah Baris(P) + deltaY */

POINT MirrorOf (POINT P, boolean SbX) {
    if (SbX) {
        CreatePoint(&P, Kolom(P), -Baris(P));
        return P;
    }
    else {
        CreatePoint(&P, -Kolom(P), Baris(P));
        return P;
    }
}
/* Menghasilkan salinan P yang dicerminkan terhadap salah satu sumbu */
/* Jika SbX bernilai true, maka dicerminkan terhadap sumbu X */
/* Jika SbX bernilai false, maka dicerminkan terhadap sumbu Y */

float Jarak0 (POINT P) {
    return sqrt((Kolom(P)*Kolom(P))+(Baris(P)*Baris(P)));
}
/* Menghitung jarak P ke (0,0) */

float Panjang (POINT P1, POINT P2) {
    return sqrt(((Kolom(P1) - Kolom(P2)) * (Kolom(P1) - Kolom(P2))) + ((Baris(P1) - Baris(P2)) * (Baris(P1) - Baris(P2))));
}
/* Menghitung panjang garis yang dibentuk P1 dan P2 */
/* Perhatikanlah bahwa di sini spec fungsi kurang baik sebab menyangkut ADT Garis. */
/* Tuliskan spec fungsi yang lebih tepat. */

void Geser (POINT *P, float deltaX, float deltaY) {
    CreatePoint(P, Kolom(*P)+deltaX, Baris(*P)+deltaY);
}
/* I.S. P terdefinisi */
/* F.S. P digeser, Kolomnya sebesar deltaX dan Barisnya sebesar deltaY */

void GeserKeSbX (POINT *P) {
    CreatePoint(P, Kolom(*P), 0);
}
/* I.S. P terdefinisi */
/* F.S. P berada pada sumbu X dengan Kolom sama dengan Kolom semula. */
/* Proses : P digeser ke sumbu X. */
/* Contoh : Jika koBaris semula (9,9), maka menjadi (9,0) */

void GeserKeSbY (POINT *P) {
    CreatePoint(P, 0, Baris(*P));
}
/* I.S. P terdefinisi*/
/* F.S. P berada pada sumbu Y dengan Baris yang sama dengan semula. */
/* Proses : P digeser ke sumbu Y. */
/* Contoh : Jika koBaris semula (9,9), maka menjadi (0,9) */

void Mirror (POINT *P, boolean SbX) {
    if (SbX && Baris(*P)!=0) {
        CreatePoint(P, Kolom(*P), -Baris(*P));
    }
    else if (!SbX && Kolom(*P)!=0){
        CreatePoint(P, -Kolom(*P), Baris(*P));
    }
}
/* I.S. P terdefinisi */
/* F.S. P dicerminkan tergantung nilai SbX atau SbY */
/* Jika SbX true maka dicerminkan terhadap sumbu X */
/* Jika SbX false maka dicerminkan terhadap sumbu Y */

void Putar (POINT *P, float Sudut) {
    float X, Y, Radian;
    Radian = Sudut * 3.14159265358979323846 / 180;
    X = cos(Radian) * Kolom(*P) + sin(Radian) * Baris(*P);
    Y = -sin(Radian) * Kolom(*P) + cos(Radian) * Baris(*P);
    CreatePoint(P, X, Y);
}
/* I.S. P terdefinisi */
/* F.S. P digeser sebesar Sudut derajat dengan sumbu titik (0,0) */
