#include <stdio.h>
#include <stdlib.h>
#include <math.h>


float DeltaDaFuncao(float a,float b,float c){

    float delta = pow(b,2) - 4 * a * c;
    return delta;

}

float RaizQuadrada(float a, float b, float c){


    float raiz = sqrt(DeltaDaFuncao(a,b,c));
    return raiz;
}

float X1(float a,float b, float c){
    float x1 = (-b + RaizQuadrada(a,b,c)) / (2 * a);
    return x1;
}

float X2(float a,float b, float c){
    float x2 = (-b - RaizQuadrada(a,b,c)) / (2 * a);
    return x2;
}

int main()
{
    float a, b, c;

    printf("Digite o valor de \na: ");
    scanf("%f",&a);
    printf("Digite o valor de \nb: ");
    scanf("%f",&b);
    printf("Digite o valor de \nc: ");
    scanf("%f",&c);


    printf("O resultado do delta: %.2f ", DeltaDaFuncao(a,b,c));

    if(DeltaDaFuncao(a,b,c) < 0){

        printf("\n A função não possui raizes!");
    }else{
        printf("\nO resultado da raiz: %.2f", RaizQuadrada(a,b,c));
        printf("\nx1: %.2f", X1(a,b,c));
        printf("\nx2: %.2f", X2(a,b,c));
    }

    return 0;
}











