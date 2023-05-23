#include <stdio.h>
#include <stdlib.h>
#include <locale.h> //biblioteca usada para set_locale
#include <time.h> //biblioteca usada para usa o rand()

/* prototipo das fun��es */

void mean(const int answer[], int size, int frequency);
void median(int answer[], int size);
void mode(const int answer[], int size);
void bubbleSort(int a[], int size);
void printArray(const int a[], int size);

//inicio da main

int main(void)
{
    setlocale(LC_ALL, "Portuguese");
    system("color 0A");//quando compilado o console aparecera com a cor de fundo "0" preto e "A" verde claro
    int frequency, size;//variavei usadas

    while(size <= 0 || size > 500 || frequency <= 0)//enquanto size ou frequencia forem menores ou iguais que "0" o loop ser� feito
    {
        printf("Digite o tamanho m�ximo do vetor: ");
        while(scanf("%d", &size) != 1){//para evitar o loop com valores indesejaveis, o scanf verifica e retornou 1, indicando que o elemento foi lido e atribuido corretamente � variavel
            printf("Por favor, digite um valor do tipo inteiro: ");//a mensagem de erro aparece at� que o usuario digite um valor do tipo inteiro
            //limpar o buffer de entrada
            while(getchar() != '\n');
        }
        printf("Digite o valor m�ximo que cada elemento dever� randomizar: ");
        while(scanf("%d", &frequency) != 1){
            printf("Por favor, digite um valor do tipo inteiro: ");

            while(getchar() != '\n');
        }
        //condi��es feitas para mostrar na tela caso o usuario digite valores indesejaveis
        if(size <= 0 || size > 500)
        {
            printf("valor inv�lido! Por favor digite um valor para o vetor acima de %s ou menor que %s\n", "0", "501");
        }

        if(frequency <= 0)
        {
            printf("valor inv�lido! Por favor digite valor para os elementos acima de zero\n");
        }
    }

    system("cls");//limpa a tela

    srand(time(NULL));//fun��o rand da bibliote time.h

    int* array = (int*)malloc(size * sizeof(int));//aloca mem�ria dinamicamente para "array" de int com "size" elementos, em que "size" � o tamanho maximo determinado pelo usuario

    for (int i = 0; i < size; i++)
    {
        array[i] = rand() % (frequency + 1);//aqui o la�o for preenche cada elemento do array com um valor aleatorio entre 0 e frequency + 1
    }//como eu queriia que contasse o valor "0" tamb�m para o casa de 2 valores, deixei assim, agora caso queira desconsiderar o "0"
    //basta usar 1 + rand() % (frequency + 1), assim os valores come�aram do 1

    /* processa respostas */
    mean(array, size, frequency);
    median(array, size);
    mode(array, size);

    free(array); // Liberar mem�ria alocada para o array

    return 0;
}
/* calcula m�dia de todos os valores de size */
void mean(const int answer[], int size, int frequency)
{
    int total = 0;/* vari�vel para manter a soma dos elementos do array */

    printf("********\n  Mean\n********\n");
    /* totalizar os elementos do array */
    /* valores totais de respostas */
    for (int j = 0; j < size; j++)
    {
        total += answer[j];
    }

    printf("A m�dia � o valor m�dio dos itens de dados.\n");
    printf("A m�dia � igual ao total de todos os itens de dados divididos pelo n�mero de itens de dados (%d).\n", size);
    printf("O valor m�dio para esta execu��o �: %d / %d = %.4f\n\n", total, size, (double)total / size);
}/* fim da fun��o mean */
/* ordena array e determina valor do elemento mediano */
void median(int answer[], int size)
{
    printf("********\n  Mediana\n********\n");

    printf("O array de respostas, n�o ordenado, �:\n");
    printArray(answer, size);/* exibe array n�o ordenado */

    bubbleSort(answer, size);/* ordena array */

    printf("\nO array ordenado �:\n");
    printArray(answer, size);/* exibe array ordenado */
    /* exibe elemento mediano */
    printf("\nA mediana � o elemento %d do array ordenado de %d elementos.\n", size / 2, size);
    printf("Para essa execu��o, a mediana � %d\n\n", answer[size / 2]);
}/* fim da fun��o median */

/* determina a ou as respostas mais frequentes */
void mode(const int answer[], int size)
{
    int max_value = 0;

    // Encontrar o valor m�ximo no array answer
    for (int i = 0; i < size; i++)
    {
        if (answer[i] > max_value)
        {
            max_value = answer[i];
        }
    }
    //aloca mem�ria dinamicamente para "freq" de int com "freq" elementos, em que "max_value + 1" � o tamanho maximo determinado pelo usuario
    int* freq = (int*)calloc(max_value + 1, sizeof(int));
    int largest = 0;/* representa maior frequ�ncia */

    printf("********\n  Moda\n********\n");
    /* resumo das frequ�ncias*/
    for (int j = 0; j < size; j++)
    {
        freq[answer[j]]++;
    }
    /* cabe�alhos de impress�o para colunas do resultado */
    printf("Resposta   Frequencia   Histograma\n");
    /* exibe resultados */
    for (int rating = 0; rating <= max_value; rating++)
    {
        if (freq[rating] > 0)  //verifica se a frequencia do valor "rating" � maior que "0", isso evita imprimir valores que ocorreram no array "answer"
        {
            printf("%-11d%-13d", rating, freq[rating]);
            //atualiza a variavel "largest" com a frequencia mais alta encontrada at� o momento
            if (freq[rating] > largest)
            {
                largest = freq[rating];
            }
            //imprime um "*" para cada ocorrencia do "rating"
            for (int h = 1; h <= freq[rating]; h++)
            {
                printf("*");
            }

            printf("\n");//imprimie nova linha a cada ocorrencia do histograma
        }
    }
    /* exibe o valor da moda */
    printf("A moda � o valor mais frequente.\n");
    printf("Para essa execu��o, a moda �: ");
    //percorre os valores do array "answer", verifica se sua frequencia � igual a/as frequencias mais altas
    for (int rating = 0; rating <= max_value; rating++)
    {
        if (freq[rating] == largest)
        {
            printf("%d, ", rating);
        }
    }

    printf("que ocorreu %d vezes.\n", largest);//printa quantidade de vezes que o/os valores foram repetidos

    free(freq);//libera o freq
}

//reordena os valores
void bubbleSort(int a[], int size)
{
    for (int pass = 1; pass < size; pass++)
    {
        for (int j = 0; j < size - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}
//printa o array
void printArray(const int a[], int size)
{
    for (int j = 0; j < size; j++)
    {
        printf("%2d ", a[j]);
        if ((j + 1) % 10 == 0)
        {
            printf("\n");
        }
    }
    printf("\n");
}
