#include <stdio.h>

int main(){
    int paisA = 5000000;
    int paisB = 7000000;
    int anos = 0;

    while(paisA < paisB){

        paisA = paisA * (1.03);
        paisB = paisB * (1.02);

        anos++;
    }

    printf("\n%d\n", anos);

    return 0;
}