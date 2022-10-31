#include "../Mesin_Kata/wordmachine.c"
#include "../Mesin_Karakter/charmachine.c"

boolean isSamaStr(char *str1, char *str2){
    int i=0;
    boolean sama = true;
    while (str1[i]!='\0' && str2[i]!='\0' && sama){
        if(str1[i]!=str2[i]){
            sama = false;
        }
        i++;
    }
    // if(str1[i]!='\0' || str2[i]!='\0'){
    //     sama = false;
    // }
    return sama;
}

int main(){
    printf("====================================\n");
    printf("COBA INPUT 1 KATA\n");
    printf("Input 1 kata: ");
    STARTWORD1();
    printf("Kata yang diinput: ");
    DisplayWord();
    printf("\n");
    printf("====================================\n");
    printf("COBA INPUT 2 KATA\n");
    printf("Input 2 kata: ");
    STARTWORD1();
    printf("Kata yang diinput: ");
    DisplayWord();
    ADVWORD1();
    DisplayWord();
    printf("\n");
    printf("====================================\n");
    printf("COBA INPUT FILE\n");


    STARTWORDFILE("../../Config/makanan.txt");
    int jumlah;
    WordToInt(&jumlah);

    for (int i=0; i<jumlah; i++){
        printf("\nMAKANAN %d\n", i+1);
        ADVNEWLINE1();
        int p;
        WordToInt(&p);
        printf("ID          :%d \n", p);
        ADVNEWLINE2();
        // char y[currentWord.Length];
        // WordToStr(y);
        printf("NAMA        :");
        DisplayWord();
        printf("\n");
        ADVNEWLINE1();
        int a,b,c;
        WordToInt(&a);
        ADVWORD1();
        WordToInt(&b);
        ADVWORD1();
        WordToInt(&c);
        printf("KADALUARSA  :%d %d %d\n", a,b,c);
        ADVNEWLINE1();
        int d,e,f;
        WordToInt(&d);
        ADVWORD1();
        WordToInt(&e);
        ADVWORD1();
        WordToInt(&f);
        printf("PENGIRIMAN  :%d %d %d\n", d,e,f);
        ADVNEWLINE1();
        // char g[3];
        // WordToStr(g);
        printf("AKSI        :");    
        DisplayWord();
        printf("\n");
        // DisplayWord();
    }
}