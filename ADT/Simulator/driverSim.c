#include "simulator.c"


int main(){
    Simulator S;

    BacaSimulator(&S);
    // printf("%saaaa\n", Nama(S));
    DisplaySimulator(S);
    // printf("%.0f\n", Baris(Lokasi(S))+50);
    printf("\n");
    MoveSimulator(&S, 2);
    DisplaySimulator(S);
    printf("\n");
    // printf("%d",(int)Nama(S));
    DisplayNama(S);
    DisplayLokasi(S);

    // printf("TES GESER\n");
    // int x;
    // do{
    //     scanf("%d", &x);
    //     switch (x)
    //     {
    //     case 1:
    //         MoveSimulator(&S, 1);
    //         break;
    //     case 2:
    //         MoveSimulator(&S, 2);
    //         break;
    //     case 3:
    //         MoveSimulator(&S, 3);
    //         break;
    //     case 4:
    //         MoveSimulator(&S, 4);
    //         break;
        
    //     default:
    //         break;
    //     }
    // }while(x!=-999);

    // TulisPOINT(Lokasi(S));

}