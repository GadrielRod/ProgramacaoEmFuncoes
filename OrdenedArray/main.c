#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define SIZE 10
int main()
{

    setlocale(LC_ALL, "Portuguese");

    int a[SIZE] = {2, 6, 4, 8, 10, 12, 89, 68, 45, 37};
    int i, pass, hold;

    printf("Itens de dados na ordem original:\n");

    for(i = 0; i < SIZE; i++) {
        printf("%4d", a[i]);
    }

    printf("\n\nIniciando o algoritmo de ordenação...\n\n");

    for(pass = 1; pass < SIZE; pass++) {
        printf("Passagem %d:\n", pass);

        for(i = 0; i < SIZE - 1; i++) {


            if(a[i] > a[i + 1]) {
                hold = a[i];
                a[i] = a[i + 1];
                a[i + 1] = hold;

                printf("%4d",a[i]);
            } else {
                printf("%4d",a[i]);
            }
        }

        printf("\n");
    }

    printf("\nItens de dados em ordem crescente:\n");

    for(i = 0; i < SIZE; i++) {
        printf("%4d", a[i]);
    }

    printf("\n");

    printf("\n\nIniciando o algoritmo de ordenação...\n\n");

    for(pass = 1; pass < SIZE; pass++) {
        printf("Passagem %d:\n", pass);

        for(i = 0; i < SIZE - 1; i++) {


            if(a[i] < a[i + 1]) {
                hold = a[i];
                a[i] = a[i + 1];
                a[i + 1] = hold;

                printf("%4d",a[i]);
            } else {
                printf("%4d",a[i]);
            }
        }

        printf("\n");
    }

    printf("\nItens de dados em ordem crescente:\n");

    for(i = 0; i < SIZE; i++) {
        printf("%4d", a[i]);
    }

    printf("\n");
    return 0;
}
