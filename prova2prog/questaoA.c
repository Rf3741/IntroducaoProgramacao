#include <stdio.h>

double logNatural2(int n){

    double Soma = 1;
    int Inverso = -1;

    for (double i = 2; i < n; i++){
        Soma = Soma + (1/i * Inverso);
        Inverso = Inverso * -1;
    }

    return Soma;
}

int main(){
    int n;
    scanf("%d", &n);


    printf("Resultado aproximado de Ln(2) em função de n: %.2lf", logNatural2(n));
}

