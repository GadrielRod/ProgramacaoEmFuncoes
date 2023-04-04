// Função Iterativa de Fibonacci

#include <stdio.h>

long fibonacci(long n);
//protipo da função

//funcao main inicia

int main(void){
    long result; //valor de Fibonacci
    long number; //numero fornecido pelo usuario

    //obtem o inteiro do usuario
    printf("Digite um inteiro: ");
    scanf("%ld", &number);

    //calcula valor de fibonacci para numero informado pelo usuario
    result = fibonacci(number);

    //mostra o resultado
    printf("Fibonacci(%ld) = %ld\n", number, result);

    return 0;
}

//definição iterativa da função fibonacci
long fibonacci(long n){


        while(n > 1){
            return fibonacci(n-1) + fibonacci(n-2);
        }


    //fim do else
}//fim da função fibonaccie

