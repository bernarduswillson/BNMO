/* Nama : Afnan Edsa Ramadhan*/
/* NIM : 13521011*/
/* Tanggal :7 September 2022*/

#include "point.h"
#include <stdio.h>
#include <math.h>


void CreatePoint (POINT * P, float X, float Y){
    Kolom(*P) = X; 
    Baris(*P) = Y;    
}
                                             
void BacaPOINT (POINT * P){
    float X,Y;
    scanf("%f %f", &X, &Y );
    while(X==(-0) || Y==(-0)){
        scanf("%f %f", &X, &Y );
    }
    CreatePoint(P, X, Y);
}

void TulisPOINT (POINT P){
    printf("(%.0f,%.0f)\n", Baris(P),Kolom(P));
}             

boolean EQ (POINT P1, POINT P2){
    return (Kolom(P1)==Kolom(P2) && Baris(P1)==Baris(P2));
}

boolean NEQ (POINT P1, POINT P2){
    return (Kolom(P1)!=Kolom(P2) || Baris(P1)!=Baris(P2));
}

boolean IsOrigin (POINT P){
    return ((Kolom(P) == 0) && (Baris(P) == 0));
}

boolean IsOnSbX (POINT P){
    return (Baris(P) == 0);
}

boolean IsOnSbY (POINT P){
    return (Kolom(P) == 0);
}

int Kuadran (POINT P){
    if(Kolom(P)>0 && Baris(P)>0){
        return 1;
    } else if (Kolom(P)<0 && Baris(P)>0){
        return 2;
    } else if (Kolom(P)<0 && Baris(P)<0){
        return 3;
    } else if (Kolom(P)>0 && Baris(P)<0){
        return 4;
    }
}

POINT NextX (POINT P){
    POINT pt;
    CreatePoint(&pt, Kolom(P)+1, Baris(P));
    return pt;
}

POINT NextY (POINT P){
    POINT pt;
    CreatePoint(&pt, Kolom(P), Baris(P)+1);
    return pt;
}

POINT PlusDelta (POINT P, float deltaX, float deltaY){
    POINT pt;
    CreatePoint(&pt, Kolom(P)+deltaX, Baris(P)+deltaY);
    return pt;
}

POINT MirrorOf (POINT P, boolean SbX){
    POINT pt;
    if (SbX){
        Baris(P) = Baris(P)*(-1);
        CreatePoint(&pt, Kolom(P), Baris(P));
    }else{
        Kolom(P) = Kolom(P)*(-1);
        CreatePoint(&pt, Kolom(P), Baris(P));
    }
    return pt;
}

float Jarak0 (POINT P){
    float a, b, c;
    a = Kolom(P)*Kolom(P);
    b = Baris(P)*Baris(P);
    c = sqrt(a+b);
    return c;
}

float Panjang (POINT P1, POINT P2){
    float a, b, c;
    a = Kolom(P1) - Kolom(P2);
    b = Baris(P1) - Baris(P2);
    c = sqrt((a*a)+(b*b));
    return c;
}

void Geser (POINT *P, float deltaX, float deltaY){
    Kolom(*P)+=deltaX;
    Baris(*P)+=deltaY;
}

void GeserKeSbX (POINT *P){
    if (Baris(*P)!=0){
        Baris(*P)= 0;
    }
}

void GeserKeSbY (POINT *P){
    if (Kolom(*P)!=0){
        Kolom(*P)= 0;
    }
}

void Mirror (POINT *P, boolean SbX){
    if (SbX){
        Baris(*P) = Baris(*P)*(-1);
    }else{
        Kolom(*P) = Kolom(*P)*(-1);
    }
}

void Putar (POINT *P, float Sudut){
    float rad,X,Y;
    rad = (Sudut*3.14159)/180;
    X = (Kolom(*P)*cos(rad) + Baris(*P)*sin(rad));
    Y = (Baris(*P)*cos(rad) - Kolom(*P)*sin(rad));

    Kolom(*P) = X;
    Baris(*P) = Y;

}
