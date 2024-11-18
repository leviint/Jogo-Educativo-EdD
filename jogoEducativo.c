#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_QUESTOES 10
#define MAX_JOGADORES 5  // Limite de jogadores no ranking

// Definindo as operações matemáticas como constantes
#define SOMA 0
#define SUBTRACAO 1
#define MULTIPLICACAO 2
#define DIVISAO 3  // Nova operação de divisão
#define EXPONENCIACAO 4  // Nova operação de exponenciação

typedef struct {
    int valor1; 
    int valor2; 
    int operacao; 
    int resultado; 
} Calcular;

typedef struct {
    char nome[50];
    int pontos;
} Jogador;

// Definindo um array de jogadores para o sistema de ranking
Jogador ranking[MAX_JOGADORES];

// Array para armazenar as questões
Calcular calcular[MAX_QUESTOES];

// Gera um número aleatório para escolher a operação (0 = soma, 1 = subtração, 2 = multiplicação, 3 = divisão, 4 = exponenciação)
void operacaoAleatoria(Calcular *calcular) {
    calcular->operacao = rand() % 5;  // Agora pode gerar divisões e exponenciações
}

// Gera números aleatórios com base na dificuldade
void valorAleatorio(Calcular *calcular, int dificuldade) {
    int max = 1;
    for (int i = 0; i < dificuldade; i++) {
        max *= 10;
    }
    calcular->valor1 = rand() % max + 1;
    calcular->valor2 = rand() % max + 1;
}

// Funções para realizar as operações
void soma(Calcular *calcular) {
    calcular->resultado = calcular->valor1 + calcular->valor2;
}

void subtracao(Calcular *calcular) {
    calcular->resultado = calcular->valor1 - calcular->valor2;
}

void multiplicacao(Calcular *calcular) {
    calcular->resultado = calcular->valor1 * calcular->valor2;
}

void divisao(Calcular *calcular) {
    if (calcular->valor2 != 0) {
        calcular->resultado = calcular->valor1 / calcular->valor2;
    } else {
        calcular->resultado = 0;  // Evitar divisão por zero
    }
}

void exponenciacao(Calcular *calcular) {
    int base = calcular->valor1;
    int expoente = calcular->valor2;
    calcular->resultado = 1;
    for (int i = 0; i < expoente; i++) {
        calcular->resultado *= base;
    }
}

// Função para mostrar a operação gerada (para feedback ao jogador)
void infoOperacao(Calcular *calcular) {
    switch (calcular->operacao) {
        case SOMA:
            printf("\n%d + %d = ?\n", calcular->valor1, calcular->valor2);
            break;
        case SUBTRACAO:
            printf("\n%d - %d = ?\n", calcular->valor1, calcular->valor2);
            break;
        case MULTIPLICACAO:
            printf("\n%d * %d = ?\n", calcular->valor1, calcular->valor2);
            break;
        case DIVISAO:
            printf("\n%d / %d = ?\n", calcular->valor1, calcular->valor2);
            break;
        case EXPONENCIACAO:
            printf("\n%d ^ %d = ?\n", calcular->valor1, calcular->valor2);
            break;
        default:
            printf("\nOperação desconhecida!\n");
    }
}

// Função para mostrar o histórico das operações realizadas
void mostrarHistorico(Calcular *calcular) {
    printf("\nHistórico de Operações:\n");
    for (int i = 0; i < MAX_QUESTOES; i++) {
        infoOperacao(&calcular[i]);
        printf("Resultado correto: %d\n", calcular[i].resultado);
    }
}

// Função para atualizar o ranking com os jogadores
void atualizarRanking(Jogador *novoJogador) {
    for (int i = 0; i < MAX_JOGADORES; i++) {
        if (ranking[i].pontos < novoJogador->pontos) {
            // Desloca os jogadores abaixo para baixo
            for (int j = MAX_JOGADORES - 1; j > i; j--) {
                ranking[j] = ranking[j - 1];
            }
            ranking[i] = *novoJogador;  // Adiciona o novo jogador
            break;
        }
    }
}

// Função para exibir o ranking
void exibirRanking() {
    printf("\nRanking Atual:\n");
    for (int i = 0; i < MAX_JOGADORES; i++) {
        if (ranking[i].pontos > 0) {
            printf("%d. %s - %d pontos\n", i + 1, ranking[i].nome, ranking[i].pontos);
        }
    }
}

// Função principal do jogo
void jogar(Jogador *jogador) {
    int resposta;
    int dificuldade;
    int continuar = 1; // Variável para controlar o laço do jogo

    while (continuar) {
        // Solicitar a dificuldade
        printf("Escolha a dificuldade (1-4): ");
        scanf("%d", &dificuldade);

        // Gerar e resolver as questões
        for (int i = 0; i < MAX_QUESTOES; i++) {
            valorAleatorio(&calcular[i], dificuldade);  // Passando referência para calcular[i]
            operacaoAleatoria(&calcular[i]);  // Passando referência para calcular[i]

            // Gera a operação com base no tipo
            switch (calcular[i].operacao) {
                case SOMA:
                    soma(&calcular[i]);
                    break;
                case SUBTRACAO:
                    subtracao(&calcular[i]);
                    break;
                case MULTIPLICACAO:
                    multiplicacao(&calcular[i]);
                    break;
                case DIVISAO:
                    divisao(&calcular[i]);
                    break;
                case EXPONENCIACAO:
                    exponenciacao(&calcular[i]);
                    break;
            }

            infoOperacao(&calcular[i]);

            // Obter a resposta do jogador
            printf("Digite sua resposta: ");
            scanf("%d", &resposta);

            // Verificar se a resposta está correta
            if (resposta == calcular[i].resultado) {
                printf("Resposta correta!\n");
                jogador->pontos += 10;  // Adicionar pontos
            } else {
                printf("Resposta errada! O resultado correto era: %d\n", calcular[i].resultado);
            }
        }

        // Perguntar se o jogador quer continuar
        printf("Deseja continuar jogando? (1 - Sim, 0 - Nao): ");
        scanf("%d", &continuar); 
    }
}

// Função para exibir a pontuação final do jogador
void exibirPontuacaoFinal(Jogador *jogador) {
    printf("\nFim do jogo, %s!\n", jogador->nome);
    printf("Sua pontuacao final e: %d pontos\n", jogador->pontos);
}

int main() {
    Jogador jogador;
    
    srand(time(NULL));  // Inicializar o gerador de números aleatórios
    
    // Receber o nome do jogador
    printf("Digite seu nome: ");
    fgets(jogador.nome, sizeof(jogador.nome), stdin);
    jogador.nome[strcspn(jogador.nome, "\n")] = '\0';  // Remover o '\n' do nome

    jogador.pontos = 0;  // Inicializar a pontuação do jogador

    // Iniciar o jogo
    jogar(&jogador);

    // Exibir a pontuação final
    exibirPontuacaoFinal(&jogador);

    // Atualizar o ranking com o novo jogador
    atualizarRanking(&jogador);

    // Exibir o ranking após o jogo
    exibirRanking();

    // Exibir o histórico das operações
    mostrarHistorico(calcular);

    return 0;
}
