#include <stdio.h>
#include <stdlib.h>
#include <locale.h> //biblioteca usada para set_locale
#include <time.h> //biblioteca usada para usa o rand()

/* prototipo das funções */

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

    while(size <= 0 || size > 500 || frequency <= 0)//enquanto size ou frequencia forem menores ou iguais que "0" o loop será feito
    {
        printf("Digite o tamanho máximo do vetor: ");
        while(scanf("%d", &size) != 1){//para evitar o loop com valores indesejaveis, o scanf verifica e retornou 1, indicando que o elemento foi lido e atribuido corretamente à variavel
            printf("Por favor, digite um valor do tipo inteiro: ");//a mensagem de erro aparece até que o usuario digite um valor do tipo inteiro
            //limpar o buffer de entrada
            while(getchar() != '\n');
        }
        printf("Digite o valor máximo que cada elemento deverá randomizar: ");
        while(scanf("%d", &frequency) != 1){
            printf("Por favor, digite um valor do tipo inteiro: ");

            while(getchar() != '\n');
        }
        //condições feitas para mostrar na tela caso o usuario digite valores indesejaveis
        if(size <= 0 || size > 500)
        {
            printf("valor inválido! Por favor digite um valor para o vetor acima de %s ou menor que %s\n", "0", "501");
        }

        if(frequency <= 0)
        {
            printf("valor inválido! Por favor digite valor para os elementos acima de zero\n");
        }
    }

    system("cls");//limpa a tela

    srand(time(NULL));//função rand da bibliote time.h

    int* array = (int*)malloc(size * sizeof(int));//aloca memória dinamicamente para "array" de int com "size" elementos, em que "size" é o tamanho maximo determinado pelo usuario

    for (int i = 0; i < size; i++)
    {
        array[i] = rand() % (frequency + 1);//aqui o laço for preenche cada elemento do array com um valor aleatorio entre 0 e frequency + 1
    }//como eu queriia que contasse o valor "0" também para o casa de 2 valores, deixei assim, agora caso queira desconsiderar o "0"
    //basta usar 1 + rand() % (frequency + 1), assim os valores começaram do 1

    /* processa respostas */
    mean(array, size, frequency);
    median(array, size);
    mode(array, size);

    free(array); // Liberar memória alocada para o array

    return 0;
}
/* calcula média de todos os valores de size */
void mean(const int answer[], int size, int frequency)
{
    int total = 0;/* variável para manter a soma dos elementos do array */

    printf("********\n  Mean\n********\n");
    /* totalizar os elementos do array */
    /* valores totais de respostas */
    for (int j = 0; j < size; j++)
    {
        total += answer[j];
    }

    printf("A média é o valor médio dos itens de dados.\n");
    printf("A média é igual ao total de todos os itens de dados divididos pelo número de itens de dados (%d).\n", size);
    printf("O valor médio para esta execução é: %d / %d = %.4f\n\n", total, size, (double)total / size);
}/* fim da função mean */
/* ordena array e determina valor do elemento mediano */
void median(int answer[], int size)
{
    printf("********\n  Mediana\n********\n");

    printf("O array de respostas, não ordenado, é:\n");
    printArray(answer, size);/* exibe array não ordenado */

    bubbleSort(answer, size);/* ordena array */

    printf("\nO array ordenado é:\n");
    printArray(answer, size);/* exibe array ordenado */
    /* exibe elemento mediano */
    printf("\nA mediana é o elemento %d do array ordenado de %d elementos.\n", size / 2, size);
    printf("Para essa execução, a mediana é %d\n\n", answer[size / 2]);
}/* fim da função median */

/* determina a ou as respostas mais frequentes */
void mode(const int answer[], int size)
{
    int max_value = 0;

    // Encontrar o valor máximo no array answer
    for (int i = 0; i < size; i++)
    {
        if (answer[i] > max_value)
        {
            max_value = answer[i];
        }
    }
    //aloca memória dinamicamente para "freq" de int com "freq" elementos, em que "max_value + 1" é o tamanho maximo determinado pelo usuario
    int* freq = (int*)calloc(max_value + 1, sizeof(int));
    int largest = 0;/* representa maior frequência */

    printf("********\n  Moda\n********\n");
    /* resumo das frequências*/
    for (int j = 0; j < size; j++)
    {
        freq[answer[j]]++;
    }
    /* cabeçalhos de impressão para colunas do resultado */
    printf("Resposta   Frequencia   Histograma\n");
    /* exibe resultados */
    for (int rating = 0; rating <= max_value; rating++)
    {
        if (freq[rating] > 0)  //verifica se a frequencia do valor "rating" é maior que "0", isso evita imprimir valores que ocorreram no array "answer"
        {
            printf("%-11d%-13d", rating, freq[rating]);
            //atualiza a variavel "largest" com a frequencia mais alta encontrada até o momento
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
    printf("A moda é o valor mais frequente.\n");
    printf("Para essa execução, a moda é: ");
    //percorre os valores do array "answer", verifica se sua frequencia é igual a/as frequencias mais altas
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
