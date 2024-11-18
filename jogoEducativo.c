#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_QUESTOES 10

typedef struct {
    int dificuldade;
    int valor1; 
    int valor2; 
    int operacao; 
    int resultado; 
}Calcular;

Calcular* operacoes[MAX_QUESTOES];

//Gera um números aleatórios para escolher a operação, atribui na struct Calcular e retorna o valor aleatório.
int operacaoAleatoria(Calcular *calcular){
    srand(time(NULL));
    calcular->operacao = rand() % 3; 
    return calcular->operacao;
}

//Gera números aleatórios e atribui no valor1 e valor2 da struct Calcular.
void valorAleatorio(Calcular *calcular, int dificuldade){
    srand(time(NULL));
    int max = 1;
    for (int i = 0; i < dificuldade; i++){
        max *= 10;
    }    
    calcular->valor1 = rand() % max + 1;
    calcular->valor2 = rand() % max + 1;
}

void soma(Calcular *calcular){
    calcular->resultado = calcular->valor1 + calcular->valor2;
}

void subtracao(Calcular *calcular){
    calcular -> resultado = calcular->valor1 - calcular->valor2;
}

void multiplicacao(Calcular *calcular){
    calcular->resultado = calcular->valor1 * calcular->valor2;
}

void infoOperacao(Calcular *calcular){
    int operador = calcular->operacao;

    if(operador = 0){
        printf("\n%d + %d = %d\n", calcular->valor1, calcular->valor2, calcular->resultado);
    }else if(operador = 1){
        printf("\n%d - %d = %d\n", calcular->valor1, calcular->valor2, calcular->resultado);
    }else if(operador = 2){
        print("\n%d * %d = %d\n", calcular->valor1, calcular->valor2, calcular->resultado);
    }
    
}

void historico(Calcular *calcular){
    printf("\nSeu Historico:\n");
    for(int i = 0; i < MAX_QUESTOES; i++){
        infoOperacao(operacoes[i]);
    }
}

void jogar(Calcular *calcular){
    int pontuacao;
    int dificuldade = 1;
    
    for (int i = 0; i < 10; i++){
        valorAleatorio(calcular, dificuldade);
        switch (operacaoAleatoria(calcular)){
        case 0:
            soma(calcular);
            break;
        case 1:
            subtracao(calcular);
            break;
        case 2:
            multiplicacao(calcular);
            break;
        }
    }
    
}

int main(){
    Calcular calcular[10];    
    jogar(&calcular);
}

