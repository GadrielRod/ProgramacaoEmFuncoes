#include <stdio.h>
#include <windows.h>
#include <time.h>

//prototipo das funções

int EscolhaDeFuncoes();
long FibonacciIterativo(long n);
long FibonacciRecursivo(long n);
void MensagemSistema();

//Função main inicia
int main(void){

    EscolhaDeFuncoes();//chama a função escolha de funções, onde será decidido qual metodo usar recursivo ou iterativo.

    return 0;
}
//função escolha
int EscolhaDeFuncoes(int escolha){
    long numero, i;//declaração das variaveis necessarias para rodar as funções recursivas e iterativas.
    clock_t tempoInicial, tempoFinal;//declaração das variaveis necessarias para calcular o tempo de processamento.
    double tempo_gasto;//variavel responsavel para calcular o tempo total
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf("\t\t\t 0 - Para encerrar o programa\n");
    printf("\t\t\t 1 - Fibonacci por Iterativa\n");
    printf("\t\t\t 2 - Fibonacci por Recurisiva\n");
    printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf("\tQual função você escolhe para resolver a sequencia de Fibonacci? ");
    scanf("%d", &escolha);//variavel usada para armazenar o digito do usuario e definir qual a sua escolha.

    switch(escolha){//switch case para escolher
    case 0://caso 0 programa encerra.
        printf("\nPrograma encerrado!\n");
        break;

    case 1://caso 1 realizara a calculo da função de fibonacci iterativa.
        //caso usuario escolha "1" fara a função iterativa.
            MensagemSistema();//chama a função mensagem sistema.
        do{//cria um laço de repetição até que a condição seja falsa
            printf("\nDigite um valor positivo da sequencia de Fibonacci ou um valor negativo para voltar ao menu de escolha: \n");
            scanf("%ld", &numero);
            system("cls");//limpa o console.
            printf("\t\t\t=-=-=-=-=-=-=-=-=-=-Sequencia de Fibonacci-=-=-=-=-=-=-=-=-=-=\n");
            tempoInicial = clock();//inicia contador.
            for(i =0; i<numero; i++){
            printf("\nFibonacci(%ld) = %ld\n", i, FibonacciIterativo(i));//chama a função de fibonacci iterativa.
            }
            tempoFinal = clock();//termina o contador.
            tempo_gasto = ((double) (tempoFinal - tempoInicial)) / CLOCKS_PER_SEC;//calcula o tempo entre as duas chamadas
            printf("\nTempo gasto para processar: %lf s\n", tempo_gasto);//printa o tempo no console.
        }while(numero > 0);//condição para parar o loop.
        system("cls");
        EscolhaDeFuncoes(escolha);//retorna para a escolha de função.
        break;

    case 2:
        //caso usuario escolha "2"fara a função recursiva
            MensagemSistema();
        do{
            printf("\nDigite um valor positivo da sequencia de Fibonacci ou um valor negativo para voltar ao menu de escolha: \n");
            scanf("%ld", &numero);
            system("cls");//limpa o console.
            printf("\t\t\t=-=-=-=-=-=-=-=-=-=-Sequencia de Fibonacci-=-=-=-=-=-=-=-=-=-=\n");
            tempoInicial = clock();
            for(i = 0; i < numero; i++){
                printf("\nFibonacci(%ld) = %ld\n", i, FibonacciRecursivo(i));
            }//laço que trara a sequencia de fibonacci recursiva.
            tempoFinal = clock();
            tempo_gasto = ((double) (tempoFinal - tempoInicial)) / CLOCKS_PER_SEC;
            printf("\nTempo gasto para processar: %lf s\n", tempo_gasto);
        }while(numero > 0);
        system("cls");
        EscolhaDeFuncoes(escolha);
        break;

    default:
        //caso usuario escolha uma opção não listada
        MensagemSistema();
        printf("Valor informado incorreto digite um dos valores abaixo\n");
        EscolhaDeFuncoes(escolha);

    }
}

//função Fibonacci Iterativo
long FibonacciIterativo(long n){
    long resultado, antepenultimo = 0, ultimo = 1;//variáveis usadas.
    int i = 1;
            if(n <= 1)
                return n;//retorna o proprio valor.
            else{
                if(n == 2)
                    return ultimo;//retorna o 1.
                else{
                    while(i < n){//faz a sequencia certa de fibonacci.
                        resultado = antepenultimo + ultimo;
                        antepenultimo = ultimo;
                        ultimo = resultado;
                        i++;
                    }
                    return resultado;//imprimi resultado.
                }
            }

}

long FibonacciRecursivo(long n){
        if(n == 0){
            return 0;
        }else if(n == 1){
            return 1;
        }else{
            return FibonacciRecursivo(n - 1) + FibonacciRecursivo(n - 2);
        }
}


void MensagemSistema(){
        system("cls");
        printf("Carregando.");
        Sleep(500);//temporizador em milisegundos.
        printf(".");
        Sleep(250);
        printf(".");
        Sleep(250);
        system("cls");
}

