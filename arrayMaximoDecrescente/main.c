#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

void ordemDecrescente(int array[], int size);


int main()
{
    system("color 02");

    setlocale(LC_ALL, "Portuguese");
    //variaveis "size" o tamanho do array, "i" e "j" contadores
    int size;
    int i;
    int j;

    //se size for menor ou maior que valor permitido cancela programa
    while(size <= 0 || size > 100)
    {
        printf("Digite o tamanho máximo de o a 100: ");
        scanf("%d", &size);
        system("cls");

        if(size <= 0 || size > 100)
        {
            printf("valor inválido! Por favor digite novamente\n");
        }
    }

    //aloca dinamicamente memória suficiente para armazenar um array de inteiros com tamanho especificado pelo usuário
    int* array = (int*)malloc(size * sizeof(int));
    //é usada para inicializar a semente do gerador de números pseudoaleatórios da função 'rand()' em C
    srand(time(NULL));

    printf( "%s%13s%17s\n", "Elemento", "Valor", "Histograma");

    for(i = 0; i < size; i++)
    {
        //ao usar rand() % algum valor, o resultadod será um número inteiro aleatório, nesse caso de 0 a 25, por isso 26
        array[i] = rand() % 26;
        printf( "%7d%13d", i, array[i]);

        for(j = 1; j <= array[i]; j++)
        {
            printf( "%c", '*' );
        }

        printf( "\n" );

    }

    printf("\nArray em ordem decrescente:\n");
    ordemDecrescente(array, size);
    printf( "%s%13s%17s\n", "Elemento", "Valor", "Histograma");
    for(i = 0; i < size; i++)
    {
        //ao usar rand() % algum valor, o resultadod será um número inteiro aleatório, nesse caso de 0 a 25, por isso 26
        printf( "%7d%13d", i, array[i]);

        for(j = 1; j <= array[i]; j++)
        {
            printf( "%c", '*' );
        }

        printf( "\n" );

    }

    free(array);//libera a memória alocada para o array

    return 0;
}


void ordemDecrescente(int array[], int size)
{
    for(int i = 0; i < size - 1; i++)
    {
        for(int j = i + 1; j < size; j++)
        {
            if(array[j] > array[i])
            {
                int hold = array[i];
                array[i] = array[j];
                array[j] = hold;
            }
        }
    }
}
