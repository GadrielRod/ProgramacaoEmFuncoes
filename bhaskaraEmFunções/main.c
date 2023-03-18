#include <stdio.h>
#include <stdlib.h>
#include <math.h>



int main()
{
    int a, b, c;

    printf("Digite o valor de \na: ");
    scanf("%d",&a);
    printf("Digite o valor de \nb: ");
    scanf("%d",&b);
    printf("Digite o valor de \nc: ");
    scanf("%d",&c);


    printf("O resultado do delta: %d ", DeltaDaFuncao(a,b,c));

    if(DeltaDaFuncao(a,b,c) < 0){

        printf("\n A função não possui raizes!");
    }else{
        printf("\nO resultado da raiz: %d", RaizQuadrada(a,b,c));
        printf("\nx1: %d", X1(a,b,c));
        printf("\nx2: %d", X2(a,b,c));
    }

    return 0;
}

int DeltaDaFuncao(a,b,c){

    int delta = pow(b,2) - 4 * a * c;
    return delta;

}

int RaizQuadrada(int a, int b, int c){


    int raiz = sqrt(DeltaDaFuncao(a,b,c));
    return raiz;
}

int X1(int a,int b, int c){
    int x1 = (-b + RaizQuadrada(a,b,c)) / 2 * a;
    return x1;
}

int X2(int a,int b, int c){
    int x2 = (-b - RaizQuadrada(a,b,c)) / 2 * a;
    return x2;
}







