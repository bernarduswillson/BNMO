#include <stdio.h>
#include "map.h"


void createMap(int nRows, int nCols, MAP *m){
    ROW_EFF(*m) = nRows;
    COL_EFF(*m) = nCols;
    for (int i = 0; i < nRows; i++) {
        for (int j = 0; j < nCols; j++) {
            ELMT(*m, i, j) = 0;
        }
    }
}

void readMap(MAP *m, int nRow, int nCol){
    createMap(nRow, nCol, m);
    for (int i=0;i<nRow;i++) {
        for (int j=0;j<nCol;j++) {
            if(currentWord.TabWord[j]=='#'){
                ELMT(*m, i, j) = ' ';
            }else{
                ELMT(*m, i, j) = currentWord.TabWord[j];
            }
        }
        ADVNEWLINE1();
    }
}

void displayMap(MAP m){
    for(int i=0;i<COL_EFF(m)+2;i++){
        if(i!=COL_EFF(m)+1){
            printf("* ");
        }else{
            printf("*\n");
        }
    }
    for (int i = 0; i < ROW_EFF(m); i++) {
        printf("* ");
        for (int j = 0; j < COL_EFF(m); j++) {
            printf("%c ", ELMT(m, i, j));
        }
        printf("*\n");
    }
    for(int i=0;i<COL_EFF(m)+2;i++){
        if(i!=COL_EFF(m)+1){
            printf("* ");
        }else{
            printf("*\n");
        }
    }
}


boolean isCommandValid(int x){
    int north = -1860003584;
    int south = -1859953284;
    int east = -1045004210;
    int west = -1044985810;

    if(x == north ||x == south ||x == east ||x == west){
        return true;
    }else{
        return false;
    }
}


void moveSim(MAP *m, int x, POINT *P){
    int north = -1860003584;
    int south = -1859953284;
    int east = -1045004210;
    int west = -1044985810;
    if(isCommandValid(x)){
        switch (x){
        case -1860003584:
            if (ELMT(*m, Baris(*P)-1, Kolom(*P)) == ' '){
                ELMT(*m,Baris(*P),Kolom(*P)) = ' ';
                ELMT(*m,(Baris(*P)-1),Kolom(*P)) = 'S';
                Baris(*P) = Baris(*P)-1;
                break;
            }
            else{
                printf("You can't move there!\n");
                break;
            }
        case -1859953284:
            if (ELMT(*m, Baris(*P)+1, Kolom(*P)) == ' '){
                ELMT(*m,Baris(*P),Kolom(*P)) = ' ';
                ELMT(*m,(Baris(*P)+1),Kolom(*P)) = 'S';
                Baris(*P) = Baris(*P)+1;
                break;
            }
            else{
                printf("You can't move there!\n");
                break;
            }
        case -1045004210:
            if (ELMT(*m, Baris(*P), Kolom(*P)+1) == ' '){
                ELMT(*m,Baris(*P),Kolom(*P)) = ' ';
                ELMT(*m,Baris(*P),(Kolom(*P)+1)) = 'S';
                Kolom(*P) = Kolom(*P)+1;
                break;
            }
            else{
                printf("You can't move there!\n");
                break;
            }
        case -1044985810:
            if (ELMT(*m, Baris(*P), Kolom(*P)-1) == ' '){
                ELMT(*m,Baris(*P),Kolom(*P)) = ' ';
                ELMT(*m,Baris(*P),(Kolom(*P)-1)) = 'S';
                Kolom(*P) = Kolom(*P)-1;
                break;
            }
            else{
                printf("You can't move there!\n");
                break;
            }
        default:
            printf("Command is not valid!\n");
            break;
        }
    }
    
}