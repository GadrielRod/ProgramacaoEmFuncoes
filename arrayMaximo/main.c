#include <stdio.h>
#include <stdlib.h>
#include <time.h> //biblioteca para gerar o rand() e fazer a aleatoriedade do programa
#include <locale.h>

int main()
{
//vindo da biblioteca windowns.h color � uma combina��o de dois digitos hexadecimais
// que v�o de 0 a F cada um possuindo uma cor, o primeiro digito � cor de fundo e o segundo a cor da fonte da letra
    system("color 02");

    setlocale(LC_ALL, "Portuguese");
    //variaveis "size" o tamanho do array, "i" e "j" contadores
    int size;
    int i;
    int j;

    //se size for menor ou maior que valor permitido cancela programa
    while(size <= 0 || size > 100)
    {
        printf("Digite o tamanho m�ximo de o a 100: ");
        scanf("%d", &size);
        system("cls");

        if(size <= 0 || size > 100){
            printf("valor inv�lido! Por favor digite novamente\n");
        }
    }


        //aloca dinamicamente mem�ria suficiente para armazenar um array de inteiros com tamanho especificado pelo usu�rio
        int* array = (int*)malloc(size * sizeof(int));
        //� usada para inicializar a semente do gerador de n�meros pseudoaleat�rios da fun��o 'rand()' em C
        srand(time(NULL));

        printf( "%s%13s%17s\n", "Elemento", "Valor", "Histograma");

        for(i = 0; i < size; i++)
        {
            //ao usar rand() % algum valor, o resultadod ser� um n�mero inteiro aleat�rio, nesse caso de 0 a 25, por isso 26
            array[i] = rand() % 26;
            printf( "%7d%13d", i + 1, array[i]);
            printf("\033[8C");//o controlador ASNI serve para posicionar o cursor 8 colunas para a direira, nesse caso em especifico
            for(j = 1; j <= array[i]; j++)
            {
                printf( "%c", '*' );
            }

            printf( "\n" );

        }
        free(array);//libera a mem�ria alocada para o array

    return 0;
}
