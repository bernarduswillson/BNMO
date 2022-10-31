#include "ADT/Utility/inisiasi.c"
#include "ADT/Mesin_Kata/wordmachine.c"
#include "ADT/Mesin_Karakter/charmachine.c"

int main() {
    startMenu();
    STARTWORD();
    checkInput(currentWord);
    return 0;
}