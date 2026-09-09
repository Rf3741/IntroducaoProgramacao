#include <stdio.h>

int fibonacci(int num){

    if(num == 1){
        return 0;
    }else if(num == 2){
        return 1;
    }

    return fibonacci(num-1) + fibonacci(num-2);

}

int main()
{
    int fib;
    int num = 10;
    
    for(int i = 1; i <= num; i++){
        int fib = fibonacci(i);
        printf("%d ", fib); // Imprime o número seguido de um espaço
    }

    printf("\n");

    return 0;
}