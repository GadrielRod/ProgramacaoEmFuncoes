#include <stdio.h>
#include <stdlib.h>
#include <math.h>//biblioteca math.h servirá para um caso que ainda não foi obtida uma solução
#include <locale.h>//biblioteca locale.h serve para incluir caracteres da localidade no programa e evitar erros de escrita no console do usuario
#include <windows.h>//biblioteca windows.h serve para o Sleep e system("cls") no programa
//prototipo das funções usadas
float somar(float parcela1, float parcela2);
float subtracao(float minuendo, float subtraendo);
float dividir(float dividendo, float divisor);
float multiplicacao(float multiplicando, float multiplicador);
float potenciacao(float base, float expoente);
float fatorial(float inteiro);
void menuDeOperacoes();
void mensagemSistema();
float valorUm();
float valorDois();

int main()//inicio da main
{
    setlocale(LC_ALL, "Portuguese");
    menuDeOperacoes();//chama a função menu onde há um switch case que realizara as funções de uma calculadora
    return 0;
}

void menuDeOperacoes(){
    char continuar[0];//declarei um char[0] que servirá para cancelar ou continuar uma operação matematica escolhida
    int operacao, inteiro, resultado2;//essas variaveis foram declaradas para lidar com valores inteiros
    float n1, n2, resultado;// n1, n2 e resultado foram declaradas para evitar repetição de codigos
    //printf mais focados na questão estetica
    printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=CALCULADORA=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf("\t\t\t\t\t\t 0 - Encerrar programa\n");
    printf("\t\t\t\t\t\t 1 - Soma\n");
    printf("\t\t\t\t\t\t 2 - Subtração\n");
    printf("\t\t\t\t\t\t 3 - Multiplicação\n");
    printf("\t\t\t\t\t\t 4 - Divisão\n");
    printf("\t\t\t\t\t\t 5 - Potênciação\n");
    printf("\t\t\t\t\t\t 6 - Fatorial\n");
    printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=CREATED BY Gabriel R.=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf("\nQual operação  matemática o usuário desejaria realizar: ");
    scanf("%d", &operacao);//armazena e lê o valor digitado pelo usuario
    //switch case realizara as funções escolhidas pelo usuario
    switch(operacao){
    case 0://caso 0 o programa será encerrado
        printf("\nPrograma encerrado\n");
        break;
    case 1://caso 1 o programa realizara a soma
        mensagemSistema();//simulação de uma mensagem do sistema, indicando carregamento e limpa o console
        printf("\n\t=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=SOMA=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
        while(continuar[0] != 'n'){//após a realização soma, o usuario será questionado se deseja realizar uma nova operação, caso seja digitado "n" o loop termina
            n1 = valorUm();//n1 recebe a função valorUm que servira para realizar a conta
            n2 = valorDois();//n2 é o mesmo caso
            resultado = somar(n1, n2);//resultado recebe a função somar que tem os valores n1 e n2
            printf("\nA soma de: %.0f + %.0f = %.2f\n", n1, n2, resultado);//printa na tela o resultado
            printf("\nDeseja continuar 's' ou 'n' : ");
            scanf("%s", continuar);
        }
        system("cls");//limpa o console
        menuDeOperacoes();//retorna a função de menu
        break;
    case 2://realizara a subtração
        mensagemSistema();
        printf("\n\t=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=SUBTRAÇÃO=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
        while(continuar[0] != 'n'){
            n1 = valorUm();
            n2 = valorDois();
            resultado = subtracao(n1, n2);
            printf("\nO resto de: %.0f - %.0f = %.2f\n", n1, n2, resultado);
            printf("\nDeseja continuar 's' ou 'n' : ");
            scanf("%s", continuar);
        }
        system("cls");
        menuDeOperacoes();
        break;
    case 3://caso 3 realizara a multiplicação
        mensagemSistema();
        printf("\n\t=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=MULTIPLICAÇÃO=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
        while(continuar[0] != 'n'){
            n1 = valorUm();
            n2 = valorDois();
            resultado = multiplicacao(n1, n2);
            printf("\nO produto de: %.0f x %.0f = %.2f\n", n1, n2, resultado);
            printf("\nDeseja continuar 's' ou 'n' : ");
            scanf("%s", continuar);
        }
        system("cls");
        menuDeOperacoes();
        break;
    case 4://caso 4 realizara a divisão
        mensagemSistema();
        printf("\n\t=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=DIVISÃO=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
            while(continuar[0] != 'n'){
            n1 = valorUm();
            n2 = valorDois();
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
    case 5://caso 5 calculara a potência
        mensagemSistema();
        printf("\n\t=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=POTÊNCIAÇÃO=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
            while(continuar[0] != 'n'){
                n1 = valorUm();
                n2 = valorDois();
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
    case 6://caso 6 calcula o fatorial
        mensagemSistema();
        printf("\n\t=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=FATORIAL=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
            while(continuar[0] != 'n'){
                inteiro = valorUm();//ocasião especial para quando o ususario digitar um valor do tipo float, então sera atribuido como um inteiro
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
    }else if(expoente < 0){
        return pow(base, expoente);//aqui chamei a função da biblioteca math.h, pois o resultado não saiu como planejado(1 / potencia)
    }else{
        return base * potenciacao(base, expoente-1);//função potenciação retorna se expoente for maior a 0, onde se expoente igual a 2, retornara a propria função até q o expoente seja igual a 0
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
float valorUm(){//função valor 1, criada para evitar a repetição de codigos e em consequencia diminuir o tamanho total do codigo
    float valorUm;
    printf("\nDigite o primeiro valor: ");
    scanf("%f", &valorUm);
}
float valorDois(){//o mesmo vale para a função valor 2
    float valorDois;
    printf("\nDigite o segundo valor: ");
    scanf("%f", &valorDois);
}
void mensagemSistema(){//função mensagem sistema, limpa o console e simula um carregamento
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
