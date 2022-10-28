

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

void StopWord(){
    END();
}

void STARTWORDFILE(char *namaFile){
    STARTFILE(namaFile);
    IgnoreBlanks();
    if (currentChar == MARK){
        EndWord = true;
    }
    else{
        EndWord = false;
        CopyWord();
    }
}

void ADVNEWLINE(){

    if(currentChar == MARK){
        EndWord = false;
        ADV();
        CopyWord();
    }
}

void WordToInt(int *x){
    int cc=1;
    *x=0;
    int len = currentWord.Length-1;
    for(int i=len;i>=0;i--){
        *x = *x + (int)(currentWord.TabWord[i]-48)*cc;
        cc*=10;
    }
}

void DisplayWord(){
    for(int i=0;i<currentWord.Length;i++){
        printf("%c", currentWord.TabWord[i]);
    }
    printf(" ");
}

void WordToStr(char y[currentWord.Length]){

    for(int i=0;i<currentWord.Length;i++){
        y[i] = currentWord.TabWord[i];
    }
    
}