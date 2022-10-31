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

// boolean isCommandValid(Word command){
//     char north[] = {'M','O','V','E',' ','N','O','R','T','H'};
//     char south[] = {'M','O','V','E',' ','S','O','U','T','H'};
//     char east[] = {'M','O','V','E',' ','E','A','S','T'};
//     char west[] = {'M','O','V','E',' ','W','E','S','T'};

//     if(command.TabWord == north ||command.TabWord == south ||command.TabWord == east ||command.TabWord == west){
//         return true;
//     }else{
//         return false;
//     }
// }

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
            ELMT(*m,Baris(*P),Kolom(*P)) = ' ';
            ELMT(*m,(Baris(*P)-1),Kolom(*P)) = 'S';
            break;
        case -1859953284:
            ELMT(*m,Baris(*P),Kolom(*P)) = ' ';
            ELMT(*m,(Baris(*P)+1),Kolom(*P)) = 'S';
            break;
        case -1045004210:
            ELMT(*m,Baris(*P),Kolom(*P)) = ' ';
            ELMT(*m,Baris(*P),(Kolom(*P)+1)) = 'S';
            break;
        case -1044985810:
            ELMT(*m,Baris(*P),Kolom(*P)) = ' ';
            ELMT(*m,Baris(*P),(Kolom(*P)-1)) = 'S';
            break;
        default:
            printf("Command is not valid!\n");
            break;
        }
    //     if(x == north){
    //         for (int i = 0; i < ROW_EFF(*m); i++) {
    //             for (int j = 0; j < COL_EFF(*m); j++) {
    //                 if(ELMT(*m, i, j) == 'S'){
    //                     ELMT(*m, i, j) = ' ';
    //                     ELMT(*m, i-1, j) = 'S';
    //                 }
    //             }
    //         }
    //     }else if(x == south){
    //         for (int i = 0; i < ROW_EFF(*m); i++) {
    //             for (int j = 0; j < COL_EFF(*m); j++) {
    //                 if(ELMT(*m, i, j) == 'S'){
    //                     ELMT(*m, i, j) = ' ';
    //                     ELMT(*m, i+1, j) = 'S';
    //                 }
    //             }
    //         }
    //     }else if(x == east){
    //         for (int i = 0; i < ROW_EFF(*m); i++) {
    //             for (int j = 0; j < COL_EFF(*m); j++) {
    //                 if(ELMT(*m, i, j) == 'S'){
    //                     ELMT(*m, i, j) = ' ';
    //                     ELMT(*m, i, j+1) = 'S';
    //                 }
    //             }
    //         }
    //     }else if(x == west){
    //         for (int i = 0; i < ROW_EFF(*m); i++) {
    //             for (int j = 0; j < COL_EFF(*m); j++) {
    //                 if(ELMT(*m, i, j) == 'S'){
    //                     ELMT(*m, i, j) = ' ';
    //                     ELMT(*m, i, j-1) = 'S';
    //                 }
    //             }
    //         }
    //     }
    // }else{
    //     printf("Command is not valid!\n");
    // }
}