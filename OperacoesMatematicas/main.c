#include <stdio.h>
#include <stdlib.h>
#include <math.h>//biblioteca math.h servir� para um caso que ainda n�o foi obtida uma solu��o
#include <locale.h>//biblioteca locale.h serve para incluir caracteres da localidade no programa e evitar erros de escrita no console do usuario
#include <windows.h>//biblioteca windows.h serve para o Sleep e system("cls") no programa
//prototipo das fun��es usadas
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
    menuDeOperacoes();//chama a fun��o menu onde h� um switch case que realizara as fun��es de uma calculadora
    return 0;
}

void menuDeOperacoes(){
    char continuar[0];//declarei um char[0] que servir� para cancelar ou continuar uma opera��o matematica escolhida
    int operacao, inteiro, resultado2;//essas variaveis foram declaradas para lidar com valores inteiros
    float n1, n2, resultado;// n1, n2 e resultado foram declaradas para evitar repeti��o de codigos
    //printf mais focados na quest�o estetica
    printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=CALCULADORA=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf("\t\t\t\t\t\t 0 - Encerrar programa\n");
    printf("\t\t\t\t\t\t 1 - Soma\n");
    printf("\t\t\t\t\t\t 2 - Subtra��o\n");
    printf("\t\t\t\t\t\t 3 - Multiplica��o\n");
    printf("\t\t\t\t\t\t 4 - Divis�o\n");
    printf("\t\t\t\t\t\t 5 - Pot�ncia��o\n");
    printf("\t\t\t\t\t\t 6 - Fatorial\n");
    printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=CREATED BY Gabriel R.=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf("\nQual opera��o  matem�tica o usu�rio desejaria realizar: ");
    scanf("%d", &operacao);//armazena e l� o valor digitado pelo usuario
    //switch case realizara as fun��es escolhidas pelo usuario
    switch(operacao){
    case 0://caso 0 o programa ser� encerrado
        printf("\nPrograma encerrado\n");
        break;
    case 1://caso 1 o programa realizara a soma
        mensagemSistema();//simula��o de uma mensagem do sistema, indicando carregamento e limpa o console
        printf("\n\t=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=SOMA=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
        while(continuar[0] != 'n'){//ap�s a realiza��o soma, o usuario ser� questionado se deseja realizar uma nova opera��o, caso seja digitado "n" o loop termina
            n1 = valorUm();//n1 recebe a fun��o valorUm que servira para realizar a conta
            n2 = valorDois();//n2 � o mesmo caso
            resultado = somar(n1, n2);//resultado recebe a fun��o somar que tem os valores n1 e n2
            printf("\nA soma de: %.0f + %.0f = %.2f\n", n1, n2, resultado);//printa na tela o resultado
            printf("\nDeseja continuar 's' ou 'n' : ");
            scanf("%s", continuar);
        }
        system("cls");//limpa o console
        menuDeOperacoes();//retorna a fun��o de menu
        break;
    case 2://realizara a subtra��o
        mensagemSistema();
        printf("\n\t=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=SUBTRA��O=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
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
    case 3://caso 3 realizara a multiplica��o
        mensagemSistema();
        printf("\n\t=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=MULTIPLICA��O=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
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
    case 4://caso 4 realizara a divis�o
        mensagemSistema();
        printf("\n\t=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=DIVIS�O=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
            while(continuar[0] != 'n'){
            n1 = valorUm();
            n2 = valorDois();
                if(n2 == 0){//se o valor de n2 for igual a 0, ira printar na tela
                    printf("\nN�o � possivel dividir por zero!\n");
                }else{//sen�o apenas realizara a divis�o normalmente
                    resultado = dividir(n1, n2);
                    printf("\nO qouciente de: %.0f / %.0f = %.2f\n", n1, n2, resultado);
                }
            printf("\nDeseja continuar 's' ou 'n' : ");
            scanf("%s", continuar);
            }
        system("cls");
        menuDeOperacoes();
        break;
    case 5://caso 5 calculara a pot�ncia
        mensagemSistema();
        printf("\n\t=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=POT�NCIA��O=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
            while(continuar[0] != 'n'){
                n1 = valorUm();
                n2 = valorDois();
                resultado = potenciacao(n1, n2);
                if(n1 == 0){//se n1 for igual a 0
                    printf("\nA base de '0' elevado a qualquer expoente resultara no proprio '0'\n");
                }else{//sen�o calcula a pot�ncia normalmente
                printf("\nA pot�ncia de: %.0f ^ %.0f = %.2f\n", n1, n2, resultado);
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
                inteiro = valorUm();//ocasi�o especial para quando o ususario digitar um valor do tipo float, ent�o sera atribuido como um inteiro
                resultado2 = fatorial(inteiro); //o mesmo vale para resultado obtido atr�ves da fun��o fatorial
                if(inteiro < 0){//se inteiro for menor que 0 printa
                    printf("\nN�o existe fatorial de um numero negativo\n");
                }else{//sen�o calcula normalmente
                printf("O fatorial de: %d = %d\n", inteiro, resultado2);
                printf("\nDeseja continuar 's' ou 'n' : ");
                scanf("%s", continuar);
                }
            }
        system("cls");
        menuDeOperacoes();
        break;
    default://caso seja digitado algum outro valor no menu retorna mensagem e menu de opera��es
        mensagemSistema();
        printf("\nValor informado errado\n");
        menuDeOperacoes();
        break;
    }
}

float somar(float parcela1, float parcela2){
    return parcela1 + parcela2;//fun��o somar retorna parcela 1 + parcela 2
}

float subtracao(float minuendo, float subtraendo){
    return minuendo - subtraendo;//fun��o subtra��o retorna minuendo - subtraendo
}
float multiplicacao(float multiplicando, float multiplicador){
    return multiplicando * multiplicador;//fun��o multiplica��o retorna multiplicando x multiplicador
}
float dividir(float dividendo, float divisor){
    return dividendo / divisor;//fun��o dividir retorna dividendo / divisor
}
float potenciacao(float base, float expoente){
    if(expoente == 0){//se expoente igual 0 retorna 1
        return 1;
    }else if(expoente < 0){
        return pow(base, expoente);//aqui chamei a fun��o da biblioteca math.h, pois o resultado n�o saiu como planejado(1 / potencia)
    }else{
        return base * potenciacao(base, expoente-1);//fun��o potencia��o retorna se expoente for maior a 0, onde se expoente igual a 2, retornara a propria fun��o at� q o expoente seja igual a 0
    }
}
float fatorial(float inteiro){
    int i;
    float fatorial = 1;
    for(i=2; i <= inteiro; i++){
        fatorial = fatorial * i;
    }
    return fatorial;//fun��o fatorial retorna o fatorial de um numero inteiro
}
float valorUm(){//fun��o valor 1, criada para evitar a repeti��o de codigos e em consequencia diminuir o tamanho total do codigo
    float valorUm;
    printf("\nDigite o primeiro valor: ");
    scanf("%f", &valorUm);
}
float valorDois(){//o mesmo vale para a fun��o valor 2
    float valorDois;
    printf("\nDigite o segundo valor: ");
    scanf("%f", &valorDois);
}
void mensagemSistema(){//fun��o mensagem sistema, limpa o console e simula um carregamento
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
