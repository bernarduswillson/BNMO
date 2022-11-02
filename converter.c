#include <stdio.h>
#include "ADT/Mesin_Karakter/charmachine.c"
#include "ADT/Mesin_Kata/wordmachine.c"

int main() {
    int x;
    STARTWORD2();
    WordToInt(&x);
    printf("%d",x);
}