#include "simulator.c"
#include "../Tree/tree.c"
#include "../Time/time.c"
#include "../Mesin_Karakter/charmachine.c"
#include "../Mesin_Kata/wordmachine.c"


int main(){
    // Simulator S;

    // BacaSimulator(&S);
    // DisplaySimulator(S);
    // printf("\n");
    // // printf("coba geser 1\n");
    // // MoveSimulator(&S, 2);
    // DisplaySimulator(S);
    // printf("\n");
    // DisplayNama(S);
    // DisplayLokasi(S);

    // printf("TES GESER\n");
    // int x;
    // // do{
    // //     scanf("%d", &x);
    // //     switch (x)
    // //     {
    // //     case 1:
    // //         MoveSimulator(&S, 1);
    // //         break;
    // //     case 2:
    // //         MoveSimulator(&S, 2);
    // //         break;
    // //     case 3:
    // //         MoveSimulator(&S, 3);
    // //         break;
    // //     case 4:
    // //         MoveSimulator(&S, 4);
    // //         break;
        
    // //     default:
    // //         break;
    // //     }
    // // }while(x!=-999);

    // DisplayLokasi(S);
    PrioQueueTime pq;
    MakeEmpty(&pq, 50);
    PrintPrioQueueTime(pq);
    Makanan X;
    ID(X) = 14;
    Queue q;
    AddQueue(&q, X);
    Del(&q, &X);
    printf("%d\n", ID(X));
    Enqueue(&pq, (infotype) X);
    PrintPrioQueueTime(pq);

}