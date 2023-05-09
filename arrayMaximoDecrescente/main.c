#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

void ordemDecrescente(int array[], int size);//prototipo da fun��o ordemDecrescente


int main()
{
    system("color 05");//aqui determinei as cores para fundo preto e fonte roxa

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
        system("cls");//limpa a tela

        if(size <= 0 || size > 100)
        {
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
        printf( "%7d%13d", i, array[i]);
        printf("\033[8C");
//para evitar de o '*' ficar colado no valor adicionei
//esse controlador ANSI que serve para coisas como exibir cores, limpar tela e posicionar o cursor,
//nesse caso posicionei o cursor tantas colunas para direita
        for(j = 1; j <= array[i]; j++)
        {
            printf( "%c", '*' );
        }

        printf( "\n" );

    }
    printf("\nArray em ordem decrescente:\n");
    ordemDecrescente(array, size);//aqui chamo a fun��o para ordenar em ordem decrescente
    printf( "\n%s%13s%17s\n", "Elemento", "Valor", "Histograma");
    for(i = 0; i < size; i++)
    {
        //ao usar rand() % algum valor, o resultadod ser� um n�mero inteiro aleat�rio, nesse caso de 0 a 25, por isso 26
        printf( "%7d%13d", i, array[i]);
        printf("\033[8C");
        for(j = 1; j <= array[i]; j++)
        {
            printf( "%c", '*' );
        }

        printf( "\n" );

    }

    free(array);//libera a mem�ria alocada para o array

    return 0;
}


void ordemDecrescente(int array[], int size)
{
    for(int i = 0; i < size - 1; i++)//loop externo itera sobre cada elemento do array, exceto o ultimo
    {
        for(int j = i + 1; j < size; j++)//loop interno itera sobre os elementos restantes do array, a partir da posi��o i + 1
        {
            if(array[j] > array[i])//verifica se 'j' � maior que o elemento na posi��o 'i', e se sim realiza a troca
            {
                int hold = array[i];//armazena os valores do elemento 'i' na vari�vel hold
                array[i] = array[j];//atribui o valor do elemento 'j' � posi��o 'i'
                array[j] = hold;//por fim atribui o valor de hold � posi��o 'j', trocando os elemento corretamente
            }
        }
    }
}
