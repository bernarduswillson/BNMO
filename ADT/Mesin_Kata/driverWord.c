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
    STARTWORD();
    printf("Kata yang diinput: ");
    DisplayWord();
    printf("\n");
    printf("====================================\n");
    printf("COBA INPUT 2 KATA\n");
    printf("Input 2 kata: ");
    STARTWORD();
    printf("Kata yang diinput: ");
    DisplayWord();
    ADVWORD();
    DisplayWord();
    printf("\n");
    printf("====================================\n");
    printf("COBA INPUT FILE\n");


    STARTWORDFILE("../../Config/makanan.txt");
    int jumlah;
    WordToInt(&jumlah);

    for (int i=0; i<jumlah; i++){
        printf("\nMAKANAN %d\n", i+1);
        ADVNEWLINE();
        int p;
        WordToInt(&p);
        printf("ID          :%d \n", p);
        ADVNEWLINE();
        char y[currentWord.Length];
        WordToStr(&y);
        ADVWORD();
        char z[currentWord.Length]; 
        WordToStr(&z);
        if(isSamaStr(y, z)){
            printf("Nama        :%s\n", z);
        }else{
            printf("Nama        :%s ", y);
            printf("%s\n", z);
        }
        ADVNEWLINE();
        int a,b,c;
        WordToInt(&a);
        ADVWORD();
        WordToInt(&b);
        ADVWORD();
        WordToInt(&c);
        printf("KADALUARSA  :%d %d %d\n", a,b,c);
        ADVNEWLINE();
        int d,e,f;
        WordToInt(&d);
        ADVWORD();
        WordToInt(&e);
        ADVWORD();
        WordToInt(&f);
        printf("PENGIRIMAN  :%d %d %d\n", d,e,f);
        ADVNEWLINE();
        char g[currentWord.Length];
        WordToStr(&g);
        printf("AKSI        :%s\n", g);    
        printf("\n");   
    }
}