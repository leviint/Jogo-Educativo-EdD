# Jogo Educativo Matemático
Este repositório contém um programa escrito em linguagem C que executa um jogo educacional de cálculos matemáticos.  
O jogo é composto por um questionário de 10 questões de operações matemáticas de **soma**, **subtração** e **multiplicação**, onde o jogador será avaliado pelo seu desempenho e colocado em um ranking entre todos os participantes.  
Esta atividade faz o uso dos conceitos aprendidos ao longo do semestre da disciplina de Estrutura de Dados.  

### Conceitos utilizados:
- Structs
- Funções
- Bibliotecas
- Estruturas de decisão
    - Switch case
    - if/else
- Manipulação
    - Entradas
    - Strings
    - Números
    - Memória
- Aleatoriedade  

## Funcionalidades
### Seleção de dificuldade
- O jogador pode escolher entre níveis de dificuldade (1 a 4). Os níveis afetam o intervalo de valores numéricos que serão utilizados nas operações
    - **Nível 1 (Fácil)**
        - 0 a 10
    - **Nível 2 (Médio)**
        - 0 a 100
    - **Nível 3 (Difícil)**
        - 0 a 1.000
    - **Nível 4 (Insano)**
        - 0 a 10.000  

### Geração de operações aleatórias
- O sistema aleatoriamente gera operações de **soma**, **subtração** ou **multiplicação** de acordo com o nível de dificuldade, para que o jogador as resolva.

### Avaliação de respostas
- O jogador acumula pontos conforme acerta as operações que são atribuídas para ele resolver.

### Menu de navegação
- O programa possui um menu via terminal intuitivo com gerenciamento de erros. Ao inserir um input inválido, o programa irá apontar o erro repetir o prompt ao usuário até que ele insira um input válido.

- Após a conclusão do questionário, a nota final será exibida e o jogador poderá escolher entre jogar novamente ou encerrar o programa.

---
## Integrantes
- **Antônio Tavaresde Lucena e Mello** - UC24101777 - GERENTE
- **Allefy Rafael F. da Silva** - UC24101130 - Assistência geral e requisitos
- **Arthur Lemos Bendini** - 24101142 - Criação do README.md e assistência geral
- **Divino Chaves Stefa** - UC24101628 - Definir dificuldade
- **Joyce Miranda de Souza** - UC24102351 - Histórico de operações
- **Victor Kauê Lima de Taiva** - UC24103357 - Geração de operadores
- **Caroline Zaiatz** - UC24101689 - Ranking
- **Beatriz Medina** - UC24101412 - Ranking

**ORIENTADOR**: Professor Weldes Lima Oliveira

---