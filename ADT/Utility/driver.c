#include "inisiasi.c"
#include "../Mesin_Kata/wordmachine.c"
#include "../Mesin_Karakter/charmachine.c"

int main() {
    startMenu();
    STARTWORD1();
    checkInput(currentWord);
    return 0;
}