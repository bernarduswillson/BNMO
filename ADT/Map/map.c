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

boolean isCommandValid(Word command){

    if(command.TabWord == "MOVE_NORTH" ||command.TabWord == "MOVE_SOUTH" ||command.TabWord == "MOVE_EAST" ||command.TabWord == "MOVE_WEST"){
        return true;
    }else{
        return false;
    }
}


void moveSim(MAP *m, int x){
    if(x == 1){
        for (int i = 0; i < ROW_EFF(*m); i++) {
            for (int j = 0; j < COL_EFF(*m); j++) {
                if(ELMT(*m, i, j) == 'S'){
                    ELMT(*m, i, j) = ' ';
                    ELMT(*m, i-1, j) = 'S';
                    break;
                }
            }
        }
    }else if(x == 2){
        for (int i = 0; i < ROW_EFF(*m); i++) {
            for (int j = 0; j < COL_EFF(*m); j++) {
                if(ELMT(*m, i, j) == 'S'){
                    ELMT(*m, i, j) = ' ';
                    ELMT(*m, i+1, j) = 'S';
                    break;
                }
            }
        }
    }else if(x==3){
        for (int i = 0; i < ROW_EFF(*m); i++) {
            for (int j = 0; j < COL_EFF(*m); j++) {
                if(ELMT(*m, i, j) == 'S'){
                    ELMT(*m, i, j) = ' ';
                    ELMT(*m, i, j+1) = 'S';
                    break;
                }
            }
        }
    }else if(x==4){
        for (int i = 0; i < ROW_EFF(*m); i++) {
            for (int j = 0; j < COL_EFF(*m); j++) {
                if(ELMT(*m, i, j) == 'S'){
                    ELMT(*m, i, j) = ' ';
                    ELMT(*m, i, j-1) = 'S';
                    break;
                }
            }
        }
    }else{
        printf("Command is not valid!\n");
    }
    // if(isCommandValid(x)){
    //     if(x == "MOVE_NORTH"){
    //         for (int i = 0; i < ROW_EFF(*m); i++) {
    //             for (int j = 0; j < COL_EFF(*m); j++) {
    //                 if(ELMT(*m, i, j) == 'S'){
    //                     ELMT(*m, i, j) = ' ';
    //                     ELMT(*m, i-1, j) = 'S';
    //                 }
    //             }
    //         }
    //     }else if(x == "MOVE_SOUTH"){
    //         for (int i = 0; i < ROW_EFF(*m); i++) {
    //             for (int j = 0; j < COL_EFF(*m); j++) {
    //                 if(ELMT(*m, i, j) == 'S'){
    //                     ELMT(*m, i, j) = ' ';
    //                     ELMT(*m, i+1, j) = 'S';
    //                 }
    //             }
    //         }
    //     }else if(x == "MOVE_EAST"){
    //         for (int i = 0; i < ROW_EFF(*m); i++) {
    //             for (int j = 0; j < COL_EFF(*m); j++) {
    //                 if(ELMT(*m, i, j) == 'S'){
    //                     ELMT(*m, i, j) = ' ';
    //                     ELMT(*m, i, j+1) = 'S';
    //                 }
    //             }
    //         }
    //     }else if(x == "MOVE_WEST"){
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