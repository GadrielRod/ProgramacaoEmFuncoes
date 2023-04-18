#include <stdio.h>
#include <stdlib.h>


int globoVar();

void funcaoEstatica(){
    static int staticVar = 0;
    staticVar++;
    printf("StaticVar dentro da função funcaoEstatica: %d\n", staticVar);
}

void funcaoNaoEstatica(){
    int staticVar2 = 0;
    staticVar2++;
    printf("StaticVar dentro da função funcaoEstatica: %d\n", staticVar2);
}

void funcaoLocal(){
    int localVar = 10;
    printf("LocalVar dentro da funcaoLocal: %d\n",localVar);
}

int main()
{
    int globoVar = 10;
    printf("GlobalVar dentro da função main: %d\n", globoVar);
    for(int i = 0; i < 5; i++){
        funcaoEstatica();
    }
    for(int i = 0; i < 5; i++){
        funcaoNaoEstatica();
    }
    //printf("LocalVar dentro da funcaoLocal: %d\n",localVar);
    outraFuncao();
    return 0;
}

void outraFuncao(){
    int globoVar = 20;
    printf("GlobalVar dentro dentra função main a partir da outraFuncao: %d\n", globoVar);
}
