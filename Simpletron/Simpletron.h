#ifndef SIMPLETRON_H_INCLUDED
#define SIMPLETRON_H_INCLUDED

#include <stdio.h>

/** TRABALHO SEMESTRAL DE LINGUAGEM DE PROGRAMAÇÃO - SIMPLETRON
    ALUNO: GUSTAVO VENENO FURLAN
    PROFESSOR: ROGERIO EDUARDO GARCIA
 **/


#define READ 10
#define WRITE 11
#define LOAD 20
#define STORE 21
#define ADD 30
#define SUBSTRACT 31
#define DIVIDE 32
#define MULTIPLY 33
#define BRANCH 40
#define BRANCHNEG 41
#define BRANCHZERO 42
#define HALT 43

typedef struct{
    int memoria[100];
    int acumulador;
    int contador;
    int registro;
    int codigo;
    int operando;
}Memoria;

void Programa(Memoria mem);
void Carregamento(Memoria mem);
void dump(Memoria mem);


#endif // SIMPLETRON_H_INCLUDED
