

#include "../Mesin_Kata/wordmachine.h"
#include "../Mesin_Karakter/charmachine.h"
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