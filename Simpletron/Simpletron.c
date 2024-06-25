#include "Simpletron.h"

void Programa(Memoria *mem){

    for(int i=0;i<=99;i++){
        mem->memoria[i]=0;
    }// Limpando a memoria

    int aux=0;
    int aux2=0;

    while(aux<=99 && aux2!=-99999){
        printf("%.2d ? ",aux);
        scanf("%d",&aux2);
        mem->memoria[aux]=aux2;
        getchar();
        aux++;
    }// Guardando as instrucoes digitadas pelo usuario

    printf("\n***Carregamento do programa concluido***\n\n***Inicio da execucao do programa***\n\n");
}


void dump(Memoria *mem){

    printf("\nREGISTROS:");
    printf("\nAcumulador: %+.4d",mem->acumulador);
    printf("\nContador: %.2d",mem->contador);
    printf("\nRegistro: %+d",mem->registro);
    printf("\nCodigo: %.2d",mem->codigo);
    printf("\nOperando: %.2d",mem->operando);

    printf("\n\nMEMORIA: \n  ");

    for(int j=0;j<=9;j++){
    printf("      %d",j);
    } // Linha
    int aux=0;
    int controle=0;
    while(aux<=90){
        printf("\n%.2d",aux); // Colunas
        for(int i=0;i<=9;i++){
            if(mem->memoria[controle] == -99999){  // Alinhar o registrador com -99999
                printf(" %+.4d",mem->memoria[controle]);
            }else{
            printf("  %+.4d",mem->memoria[controle]);
            }
            controle++;
        }
        aux += 10;
    }
}


void Carregamento(Memoria *mem){

    mem->acumulador=0;
    mem->contador=0;
    mem->registro=0;
    mem->codigo=0;
    mem->operando=0;

    bool controle = false;

    while((mem->memoria[mem->contador]!= -99999)&&(mem->contador<=99)){

        mem->registro = mem->memoria[mem->contador];  //Guarda o codigo de 4 numeros
        mem->codigo = mem->registro/100;             //Guarda os dois numeros, que representam o codigo
        mem->operando = mem->registro%100;          //Guarda os dois numeros, que representam o operando

        if(mem->registro<0){
            printf("\n***Erro no sinal do codigo %d***\n***Interrupacao anormal da execucao do Simpletron***\n",mem->registro);
            dump(mem);
            return;
        } // Em caso de erro no sinal

        switch(mem->codigo){   // Operação para cada comando
            case READ:
                printf("Digite um valor: ");
                int aux;
                scanf("%d",&aux);
                while((aux>9999)||(aux<-9999)){
                    printf("O valor extrapolou o limite de -9999 e +9999, digite novamente: ");
                    scanf("%d",&aux);
                }
                mem->memoria[mem->operando] = aux;
                mem->contador++;
                break;
            case WRITE:
                printf("\n%d\n",mem->memoria[mem->operando]);
                mem->contador++;
                break;
            case LOAD:
                mem->acumulador = mem->memoria[mem->operando];
                mem->contador++;
                break;
            case STORE:
                mem->memoria[mem->operando]=mem->acumulador;
                mem->contador++;
                break;
            case ADD:
                mem->acumulador += mem->memoria[mem->operando];
                mem->contador++;
                break;
            case SUBSTRACT:
                mem->acumulador -= mem->memoria[mem->operando];
                mem->contador++;
                break;
            case DIVIDE:
                if(mem->acumulador!=0){
                mem->acumulador = mem->memoria[mem->operando]/mem->acumulador;
                }else{
                    printf("\n***Tentativa de divisao por zero***\n***Interrupacao anormal da execucao do Simpletron***\n");
                    dump(mem);
                    return;
                }
                mem->contador++;
                break;
            case MULTIPLY:
                mem->acumulador *= mem->memoria[mem->operando];
                mem->contador++;
                break;
            case BRANCH:
                mem->contador = mem->operando;
                break;
            case BRANCHNEG:
                if(mem->acumulador<0){
                    mem->contador = mem->operando;
                }else{
                    mem->contador++;
                }
                break;
            case BRANCHZERO:
                if(mem->acumulador==0){
                    mem->contador = mem->operando;
                }else{
                    mem->contador++;
                }
                break;
            case HALT:
                controle = true; // variavel usada na funcao que trata o erro de nao uso do HALT para finalizar o programa
                printf("\n\nExecucao do Simpletron encerrada\n\n");
                dump(mem);
                return;
            default:
            printf("\n***O codigo %d e invalido***\n***Interrupacao anormal da execucao do Simpletron***\n",mem->codigo);
            dump(mem);
            return;
        }
        if((mem->acumulador>9999)||(mem->acumulador<-9999)){
            mem->contador--;
            printf("\n***Overflow do Acumulador***\n***Interrupacao anormal da execucao do Simpletron***\n");
            dump(mem);
            return;
        } // Em caso de Overflow do acumulador
        }
        if(mem->contador>99){
            printf("\n***Programa encerrado por atingir limite de espaco, digite no maximo 100 instrucoes!***\n");
            dump(mem);
            return;
        } //Em caso de mais de 100 instrucoes
        if((mem->memoria[mem->contador]== -99999) && !(controle)){
            printf("\n***Programa encerrado incorretamente, digite 4300 para encerra-lo!***\n");
            dump(mem);
            return;
        } // Em caso de encerrar o programa sem usar o HALT
}
