

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

void STARTWORD1(){
    START();
    IgnoreBlanks();
    if(currentChar==MARK){
        EndWord = true;
    }else{
        EndWord = false;
        CopyWord1();
    }

}

void STARTWORD2(){
    START();
    IgnoreBlanks();
    if(currentChar==MARK){
        EndWord = true;
    }else{
        EndWord = false;
        CopyWord2();
    }

}

void ADVWORD1(){
    IgnoreBlanks();
    if(currentChar==MARK){
        EndWord = true;
    }
    else{
        CopyWord1();
        IgnoreBlanks();
    }
}

void ADVWORD2(){
    if(currentChar==MARK){
        EndWord = true;
    }
    else{
        CopyWord2();
        IgnoreBlanks();
    }
}

void CopyWord1(){
    int i=0;
    while ((currentChar!=MARK && currentChar!= BLANK && i<NMax)){
        currentWord.TabWord[i] = currentChar;
        ADV();
        i++;
    }
    currentWord.Length = i;   
}

void CopyWord2(){
    int i=0;
    while ((currentChar!=MARK && i<NMax)){
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
        CopyWord1();
    }
}

void ADVNEWLINE1(){
    Word EMPTY = {"", 0};
    currentWord = EMPTY;
    if(currentChar == MARK){
        EndWord = false;
        ADV();
        CopyWord1();
    }
}

void ADVNEWLINE2(){
    Word EMPTY = {"", 0};
    currentWord = EMPTY;
    if(currentChar == MARK){
        EndWord = false;
        ADV();
        CopyWord2();
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

void DisplayWord(Word currentWord){
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