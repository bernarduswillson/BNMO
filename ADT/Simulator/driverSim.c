#include "simulator.c"


int main(){
    Simulator S;

    BacaSimulator(&S);
    // printf("%saaaa\n", Nama(S));
    DisplaySimulator(S);
    // printf("%.0f\n", Baris(Lokasi(S))+50);
    MoveSimulator(&S, 2);
    DisplaySimulator(S);
    // printf("%d",(int)Nama(S));
    DisplayNama(S);
    DisplayLokasi(S);

    // int x=0;
    // while(x!=-999){
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
    // }

    // TulisPOINT(Lokasi(S));

}