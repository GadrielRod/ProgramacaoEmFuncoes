/* ex05_03.c */

/* Testing the math library functions */

#include <stdio.h>

#include <math.h>



int main( void )

{
    float a, b, c, x;
    float delta, x1, x2;

    printf("Digite o valor de \na: ");
    scanf("%f",&a);
    printf("Digite o valor de \nb: ");
    scanf("%f",&b);
    printf("Digite o valor de \nc: ");
    scanf("%f",&c);


    delta = pow(b,2) - (4 * a *c);
    if(delta < 0){
        printf("\n A função não possui raizes!!");
        printf("\n O delta é: %.2f", delta);
    }else{
        printf("\n O delta é: %.2f", delta);
        x1 = (- b + (sqrt(delta))) / (2 * a);
        x2 = (- b - (sqrt(delta))) / (2 * a);
        printf("\n X1: %.2f",x1);
        printf("\n X2: %.2f",x2);

    }



   return 0;

}
