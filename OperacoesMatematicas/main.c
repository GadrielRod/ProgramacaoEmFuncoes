#include <stdio.h>
#include <stdlib.h>
#include <locale.h>//biblioteca locale.h serve para incluir caracteres da localidade no programa e evitar erros de escrita no console do usuario
#include <windows.h>//biblioteca windows.h serve para o Sleep e system("cls") no programa
//prototipo das funções usadas, usei como paramentros, as definições de cada tipo de operação
float somar(float parcela1, float parcela2);
float subtracao(float minuendo, float subtraendo);
float dividir(float dividendo, float divisor);
float multiplicacao(float multiplicando, float multiplicador);
float potenciacao(float base, float expoente);
float fatorial(float inteiro);
void menuDeOperacoes();
void mensagemSistema();
float valorUm(float valorUm);
float valorDois(float valorDois);

int main()//inicio da main
{
    setlocale(LC_ALL, "Portuguese");
    menuDeOperacoes();//chama a função menu onde há um switch case que realizara as funções de uma calculadora
    return 0;
}

void menuDeOperacoes(){
    char operacao, continuar[0];//declarei um char[0] que servirá para cancelar ou continuar uma operação matematica escolhida
    int inteiro, resultado2;//essas variaveis foram declaradas para lidar com valores inteiros
    float n1, n2, resultado;// n1, n2 e resultado foram declaradas para evitar repetição de codigos
    //printf mais focados na questão estetica
    printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=CALCULADORA=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf("\t\t\t\t\t\t '0' - Encerrar programa\n");
    printf("\t\t\t\t\t\t '+' - Soma\n");
    printf("\t\t\t\t\t\t '-' - Subtração\n");
    printf("\t\t\t\t\t\t '*' - Multiplicação\n");
    printf("\t\t\t\t\t\t '/' - Divisão\n");
    printf("\t\t\t\t\t\t '^' - Potênciação\n");
    printf("\t\t\t\t\t\t '!' - Fatorial\n");
    printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=CREATED BY Gabriel R.=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf("\nQual operação  matemática o usuário desejaria realizar: ");
    scanf("%s", &operacao);//armazena e lê o valor digitado pelo usuario
    //switch case realizara as funções escolhidas pelo usuario
    switch(operacao){
    case '0'://caso 0 o programa será encerrado
        printf("\nPrograma encerrado\n");
        break;
    case '+'://caso 1 o programa realizara a soma
        mensagemSistema();//simulação de uma mensagem do sistema, indicando carregamento e limpa o console
        printf("\n\t=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=SOMA=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
        while(continuar[0] != 'n'){//após a realização soma, o usuario será questionado se deseja realizar uma nova operação, caso seja digitado "n" o loop termina
            n1 = valorUm(n1);//n1 recebe a função valorUm que servira para realizar a conta
            n2 = valorDois(n2);//n2 é o mesmo caso
            resultado = somar(n1, n2);//resultado recebe a função somar que tem os valores n1 e n2
            printf("\nA soma de: %.0f + %.0f = %.0f\n", n1, n2, resultado);//printa na tela o resultado
            printf("\nDeseja continuar 's' ou 'n' : ");
            scanf("%s", continuar);
        }
        system("cls");//limpa o console
        menuDeOperacoes();//retorna a função de menu
        break;
    case '-'://realizara a subtração
        mensagemSistema();
        printf("\n\t=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=SUBTRAÇÃO=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
        while(continuar[0] != 'n'){
            n1 = valorUm(n1);
            n2 = valorDois(n2);
            resultado = subtracao(n1, n2);
            printf("\nO resto de: %.0f - %.0f = %.2f\n", n1, n2, resultado);
            printf("\nDeseja continuar 's' ou 'n' : ");
            scanf("%s", continuar);
        }
        system("cls");
        menuDeOperacoes();
        break;
    case '*'://caso 3 realizara a multiplicação
        mensagemSistema();
        printf("\n\t=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=MULTIPLICAÇÃO=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
        while(continuar[0] != 'n'){
            n1 = valorUm(n1);
            n2 = valorDois(n2);
            resultado = multiplicacao(n1, n2);
            printf("\nO produto de: %.0f x %.0f = %.2f\n", n1, n2, resultado);
            printf("\nDeseja continuar 's' ou 'n' : ");
            scanf("%s", continuar);
        }
        system("cls");
        menuDeOperacoes();
        break;
    case '/'://caso 4 realizara a divisão
        mensagemSistema();
        printf("\n\t=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=DIVISÃO=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
            while(continuar[0] != 'n'){
            n1 = valorUm(n1);
            n2 = valorDois(n2);
                if(n2 == 0){//se o valor de n2 for igual a 0, ira printar na tela
                    printf("\nNão é possivel dividir por zero!\n");
                }else{//senão apenas realizara a divisão normalmente
                    resultado = dividir(n1, n2);
                    printf("\nO qouciente de: %.0f / %.0f = %.2f\n", n1, n2, resultado);
                }
            printf("\nDeseja continuar 's' ou 'n' : ");
            scanf("%s", continuar);
            }
        system("cls");
        menuDeOperacoes();
        break;
    case '^'://caso 5 calculara a potência
        mensagemSistema();
        printf("\n\t=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=POTÊNCIAÇÃO=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
            while(continuar[0] != 'n'){
                n1 = valorUm(n1);
                n2 = valorDois(n2);
                resultado = potenciacao(n1, n2);
                if(n1 == 0){//se n1 for igual a 0
                    printf("\nA base de '0' elevado a qualquer expoente resultara no proprio '0'\n");
                }else{//senão calcula a potência normalmente
                printf("\nA potência de: %.0f ^ %.0f = %.2f\n", n1, n2, resultado);
                }
                printf("\nDeseja continuar 's' ou 'n' : ");
                scanf("%s", continuar);
            }
        system("cls");
        menuDeOperacoes();
        break;
    case '!'://caso 6 calcula o fatorial
        mensagemSistema();
        printf("\n\t=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=FATORIAL=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
            while(continuar[0] != 'n'){
                inteiro = valorUm(inteiro);//ocasião especial para quando o ususario digitar um valor do tipo float, então sera atribuido como um inteiro
                resultado2 = fatorial(inteiro); //o mesmo vale para resultado obtido atráves da função fatorial
                if(inteiro < 0){//se inteiro for menor que 0 printa
                    printf("\nNão existe fatorial de um numero negativo\n");
                }else{//senão calcula normalmente
                printf("O fatorial de: %d = %d\n", inteiro, resultado2);
                printf("\nDeseja continuar 's' ou 'n' : ");
                scanf("%s", continuar);
                }
            }
        system("cls");
        menuDeOperacoes();
        break;
    default://caso seja digitado algum outro valor no menu retorna mensagem e menu de operações
        mensagemSistema();
        printf("\nValor informado errado\n");
        menuDeOperacoes();
        break;
    }
}

float somar(float parcela1, float parcela2){
    return parcela1 + parcela2;//função somar retorna parcela 1 + parcela 2
}

float subtracao(float minuendo, float subtraendo){
    return minuendo - subtraendo;//função subtração retorna minuendo - subtraendo
}
float multiplicacao(float multiplicando, float multiplicador){
    return multiplicando * multiplicador;//função multiplicação retorna multiplicando x multiplicador
}
float dividir(float dividendo, float divisor){
    return dividendo / divisor;//função dividir retorna dividendo / divisor
}
float potenciacao(float base, float expoente){
    if(expoente == 0){//se expoente igual 0 retorna 1
        return 1;
    }else if(expoente < 0){//aqui caso expoente seja negativo o laço for fara i-- até se igualar ao expoente
        for(int i = 0; i > expoente; i--){
            base *= base;//depois retornará 1 dividido pelo resultado da potencia
        return 1 / base;
        }
    }else{
        return base * potenciacao(base, expoente-1);//senão faz o calculo da potencia retornando função potencia, expoente - 1, até se igualar a 0
//vale ressaltar q versão do laço for também serviria para caso expoente for maior que 0, mas com certas alterações, então usei essa diferenciada
    }
}
float fatorial(float inteiro){
    int i;
    float fatorial = 1;
    for(i=2; i <= inteiro; i++){
        fatorial = fatorial * i;
    }
    return fatorial;//função fatorial retorna o fatorial de um numero inteiro
}
float valorUm(float valorUm){//função valor 1, criada para evitar a repetição de codigos e em consequencia diminuir o tamanho total do codigo
    printf("\nDigite o primeiro valor: ");
    scanf("%f", &valorUm);
    return valorUm;
}
float valorDois(float valorDois){//o mesmo vale para a função valor 2
    printf("\nDigite o segundo valor: ");
    scanf("%f", &valorDois);
    return valorDois;
}
void mensagemSistema(){//função mensagem sistema, limpa o console e simula um carregamento com Sleep vindo da biblioteca windons.h
    system("cls");
    printf("Carregando.");
    Sleep(500);
    printf(".");
    Sleep(250);
    printf(".");
    Sleep(250);
    printf(".");
    system("cls");
}
