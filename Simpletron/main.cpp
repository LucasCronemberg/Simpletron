// TRABALHO SEMESTRAL - LINGUAGEM DE PROGRAMAÇÃO
// GUSTAVO VENENO FURLAN - FCT UNESP
#include <iostream>
#include "Simpletron.c"

using namespace std;

int main(){

    printf("*** Bem vindo ao Simpletron! ***\n");
    printf("*** Favor digitar seu programa, uma instrucao ***\n");
    printf("*** (ou palavra de dados) por vez. Mostrarei ***\n");
    printf("*** o numero do local e uma interrogacao (?). ***\n");
    printf("*** Voce, entao, devera digitar a palavra para esse ***\n");
    printf("*** local. Digite a sentinela -99999 para ***\n");
    printf("*** encerrar a entrada do seu programa. ***\n\n");

    Memoria x;

    Programa(&x);
    Carregamento(&x);

    printf("\n");
    return 0;
}
