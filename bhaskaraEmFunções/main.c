#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Aqui calcularemos o Delta da função
float DeltaDaFuncao(float a,float b,float c){

    float delta = pow(b,2) - 4 * a * c;
    return delta;

}

//Aqui calcularemos a raiz quadrada do Delta
float RaizQuadrada(float a, float b, float c){


    float raiz = sqrt(DeltaDaFuncao(a,b,c));
    return raiz;
}

//Aqui calcularemos o x1 ou primeira raiz real?
float X1(float a,float b, float c){
    float x1 = (-b + RaizQuadrada(a,b,c)) / (2 * a);
    return x1;
}

//Aqui calcularemos o x2 ou segunda raiz real?
float X2(float a,float b, float c){
    float x2 = (-b - RaizQuadrada(a,b,c)) / (2 * a);
    return x2;
}

int main()
{
    float a, b, c;

//Aqui é onde tudo começa, onde pedimos para o usuario digitar os valores de a, b, c Ou os valores da equação que são Ax^2, bx e c.

    printf("Digite o valor de \na: ");
    scanf("%f",&a);
    printf("Digite o valor de \nb: ");
    scanf("%f",&b);
    printf("Digite o valor de \nc: ");
    scanf("%f",&c);


    printf("O resultado do delta: %.2f ", DeltaDaFuncao(a,b,c));

//Aqui ocorrerá um if que determina se a conta possui x1 e x2, caso o Delta tenha como resultado um valor menor que 0. Ocorrera a primeira condição.

    if(DeltaDaFuncao(a,b,c) < 0){

        printf("\n A função não possui raizes!");
    }else{
        printf("\nO resultado da raiz: %.2f", RaizQuadrada(a,b,c));
        printf("\nx1: %.2f", X1(a,b,c));
        printf("\nx2: %.2f", X2(a,b,c));
    }

    return 0;
}











