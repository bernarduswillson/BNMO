/* Nama : Afnan Edsa Ramadhan*/
/* NIM : 13521011*/
/* Tanggal :28 September 2022*/

#include "wordmachine.h"
#include "charmachine.h"
#include <stdio.h>

boolean EndWord;
Word currentWord;

void IgnoreBlanks(){
    while (currentChar==BLANK){
        ADV();
    }
    
}

void STARTWORD(){
    START();
    IgnoreBlanks();
    if(currentChar==MARK){
        EndWord = true;
    }else{
        EndWord = false;
        CopyWord();
    }

}

void ADVWORD(){
    IgnoreBlanks();
    if(currentChar==MARK){
        EndWord = true;
    }else{
        CopyWord();
        IgnoreBlanks();
    }
}

void CopyWord(){
    int i=0;
    while ((currentChar!=MARK && currentChar!=BLANK && i<NMax)){
        currentWord.TabWord[i] = currentChar;
        ADV();
        i++;
    }
    currentWord.Length = i;
    
}