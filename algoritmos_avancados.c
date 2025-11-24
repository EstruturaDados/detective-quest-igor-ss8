
// Desafio Detective Quest
// Tema 4 - Árvores e Tabela Hash
// Este código inicial serve como base para o desenvolvimento das estruturas de navegação, pistas e suspeitos.
// Use as instruções de cada região para desenvolver o sistema completo com árvore binária, árvore de busca e tabela hash.

// DESAFIO NOVATO
// OBJETIVO: Criar uma árvore binária com nome para cada cômodo

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOME 50

// Estrutura para representar cada sala da mansão
typedef struct Sala {
    char nome[MAX_NOME];
    struct Sala *esq; 
    struct Sala *dir;
} Sala;

// Função para alocar uma nova sala
Sala* criarSala(char* nomeSala) {
    Sala* s = (Sala*)malloc(sizeof(Sala));
    

    strcpy(s->nome, nomeSala);
    s->esq = NULL;
    s->dir = NULL;
    return s;
}

void explorarSalas(Sala* inicio) {
    Sala* atual = inicio;
    char opcao;

    printf("\n--- DETECTIVE QUEST --\n");

    while (atual != NULL) {
        printf("\n------------------\n");
        printf("Voce esta aqui: [ %s ]\n", atual->nome);

        // Verifica se é um beco sem saída (nó folha)
        if (atual->esq == NULL && atual->dir == NULL) {
            printf("\n> Chegou ao fim da linha! Nao tem mais saídas aqui.\n");
            printf("> Investigação terminada neste ponto.\n");
            break;
        }

        // Mostra opções se existirem
        printf("Opcoes:\n");
        if (atual->esq) printf(" [e] Esquerda: %s\n", atual->esq->nome);
        if (atual->dir) printf(" [d] Direita:  %s\n", atual->dir->nome);
        
        printf("\nPara onde vai? (e/d ou s para sair): ");
        scanf(" %c", &opcao);

        if (opcao == 'e' || opcao == 'E') {
            if (atual->esq) {
                atual = atual->esq;
            } else {
                printf(">> Nao tem passagem para a esquerda!\n");
            }
        } 
        else if (opcao == 'd' || opcao == 'D') {
            if (atual->dir) {
                atual = atual->dir;
            } else {
                printf(">> Nao tem passagem para a direita!\n");
            }
        } 
        else if (opcao == 's' || opcao == 'S') {
            printf("Saindo do jogo...\n");
            break;
        } 
        else {
            printf(">> Comando invalido, tente de novo.\n");
        }
    }
}

int main() {
    // Criação das salas (nós da árvore)
    Sala* hall = criarSala("Hall de Entrada");
    Sala* salaEstar = criarSala("Sala de Estar");
    Sala* salaJantar = criarSala("sala de jantar");
    Sala* biblioteca = criarSala("Biblioteca");
    Sala* jardim = criarSala("jardim");
    Sala* sotao = criarSala("sótaõ");

    hall->esq = salaEstar;
    hall->dir = salaJantar;

    salaEstar->esq = biblioteca;
    salaEstar->dir = jardim;

    salaJantar->dir = sotao;

    // Começa o jogo //
    explorarSalas(hall);

    return 0;
}