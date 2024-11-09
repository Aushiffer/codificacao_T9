#include "trie.h"
#include <stdio.h>
#include <string.h>

void inicia_trie(Trie *t) { *t = NULL; }

Trie cria_no(char item) {
    Trie t;

    if (!(t = (Trie)malloc(sizeof(No)))) return NULL;

    for (int i = 0; i < NUM_DIG; i++)
        t->vet_ap[i] = NULL;

    t->item = item; // Caractere pertencente ao caminho da palavra sendo inserida.

    return t;
}

void busca_no(Trie t, char codigo[], char chave[]) {
    char res[TAM_PALAVRA];

    busca_no_rec(t, codigo, chave, 0, res);
    
    if (strcmp(res, chave) == 0)
        printf("%s\n", res);
    else
        printf("palavra nao encontrada\n");
}

void busca_no_rec(Trie t, char codigo[], char chave[], size_t d, char res[]) {
    if (eh_folha(t)) {
        res[d] = '\0';

        return;
    }

    Trie prox;
    res[d] = t->item;

    if (codigo[d] == '#')
        prox = t->vet_ap[NUM_DIG - 1];
    else
        prox = t->vet_ap[codigo[d] - '2']; // f: [2..9] -> [0..8].

    busca_no_rec(prox, codigo, chave, d + 1, res);
}

Trie insere_no(Trie t, char chave[], size_t d) {
    if (!t) {
        Trie novo_no = cria_no(chave[d]);
        novo_no->vet_ap[NUM_DIG - 1] = cria_no('\0');

        return novo_no; // Termina a inserção da palavra com uma folha após a última letra.
    }

    if (d > 0 && padrao(chave[d]) == padrao(chave[d - 1]))
        t->vet_ap[8] = insere_no(t->vet_ap[NUM_DIG - 1], chave, d + 1);
    else {
        switch (padrao(chave[d])) {
            case 2:
                t->vet_ap[0] = insere_no(t->vet_ap[0], chave, d + 1);

                break;
            case 3:
                t->vet_ap[1] = insere_no(t->vet_ap[1], chave, d + 1);

                break;
            case 4:
                t->vet_ap[2] = insere_no(t->vet_ap[2], chave, d + 1);

                break;
            case 5:
                t->vet_ap[3] = insere_no(t->vet_ap[3], chave, d + 1);

                break;
            case 6:
                t->vet_ap[4] = insere_no(t->vet_ap[4], chave, d + 1);

                break;
            case 7:
                t->vet_ap[5] = insere_no(t->vet_ap[5], chave, d + 1);

                break;
            case 8:
                t->vet_ap[6] = insere_no(t->vet_ap[6], chave, d + 1);

                break;
            case 9:
                t->vet_ap[7] = insere_no(t->vet_ap[7], chave, d + 1);

                break;
            default:
                perror("padrao nao encontrado");

                break;
        }
    }

    return t;
}

int padrao(char c) {
    if (
        c == 'a'
        || c == 'b'
        || c == 'c'
        || c == 'A'
        || c == 'B'
        || c == 'C'
    )
        return 2;

    if (
        c == 'd'
        || c == 'e'
        || c == 'f'
        || c == 'D'
        || c == 'E'
        || c == 'F'
    )
        return 3;

    if (
        c == 'p' 
        || c == 'q' 
        || c == 'r' 
        || c == 's'
        || c == 'P'
        || c == 'Q'
        || c == 'R'
        || c == 'S'
    )
        return 7;

    if (
        c == 'w'
        || c == 'x'
        || c == 'y'
        || c == 'z'
        || c == 'W'
        || c == 'X'
        || c == 'Y'
        || c == 'Z'
    )
        return 9;

    return -1;
}

unsigned char eh_folha(Trie t) { return t->item == '\0'; }

void destroi_trie(Trie t) {
    if (!t) return;

    for (int i = 0; i < NUM_DIG; i++)
        destroi_trie(t->vet_ap[i]);

    free(t);
}