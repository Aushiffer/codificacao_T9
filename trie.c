/*
* trie.c: implementação do TAD Trie n-ária.
* Autores: Caio E. F. de Miranda e Andreus G. Schultz.
* Implementa as funções necessárias para se ter busca e inserção na trie n-ária, segundo o que se pede no enunciado.
*/

#include "trie.h"

void inicia_trie(Trie *t) { *t = NULL; }

Trie cria_no() {
    Trie t;

    if (!(t = (Trie)malloc(sizeof(No)))) return NULL;

    for (int i = 0; i < NUM_DIG; i++)
        t->vet_ap[i] = NULL;

    t->item = NULL;

    return t;
}

void set_chave(Trie t, char chave[]) { 
    if (!t->item)
        t->item = strdup(chave);
    else
        strncpy(t->item, chave, TAM_PALAVRA);
}

void busca_no(Trie t, char codigo[]) {
    if (!codigo_valido(codigo)) {
        printf("entrada invalida\n");

        return;
    }

    Trie no_busca = busca_no_rec(t, codigo, 0);

    if (no_busca && no_busca->item)
        printf("%s\n", no_busca->item);
    else
        printf("palavra nao encontrada\n");
}

Trie busca_no_rec(Trie t, char codigo[], size_t d) { 
    if (!t || codigo[d] == '\0') return t;
    
    Trie prox = (codigo[d] == '#') ? t->vet_ap[NUM_DIG - 1] : t->vet_ap[codigo[d] - '2'];

    return busca_no_rec(prox, codigo, d + 1);
}

Trie insere_no(Trie t, char chave[], size_t d) {    
    if (d == strlen(chave)) {
        if (!t) {
            Trie novo_no;

            if (!(novo_no = cria_no())) {
                fprintf(stderr, "insere_no() - erro ao criar um novo nó\n");

                return NULL;
            }

            set_chave(novo_no, chave);

            return novo_no;
        }

        if (!t->item)
            set_chave(t, chave);
        else
            t->vet_ap[NUM_DIG - 1] = insere_no(t->vet_ap[NUM_DIG - 1], chave, d);

        return t;     
    }

    if (!t) {
        if (!(t = cria_no())) {
            fprintf(stderr, "insere_no() - erro ao criar um novo nó\n");

            return NULL;
        }
    }

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
            fprintf(stderr, "insere_no() - padrão não encontrado\n");

            break;
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
        c == 'g'
        || c == 'h'
        || c == 'i'
        || c == 'G'
        || c == 'H'
        || c == 'I'
    )
        return 4;

    if (
        c == 'j'
        || c == 'k'
        || c == 'l'
        || c == 'J'
        || c == 'K'
        || c == 'L'
    )
        return 5;

    if (
        c == 'm'
        || c == 'n'
        || c == 'o'
        || c == 'M'
        || c == 'N'
        || c == 'O'
    )
        return 6;

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
        c == 't'
        || c == 'u'
        || c == 'v'
        || c == 'T'
        || c == 'U'
        || c == 'V'
    )
        return 8;

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

unsigned char codigo_valido(char codigo[]) {
    for (size_t i = 0; i < strlen(codigo); i++)
        if ((codigo[i] < '2' || codigo[i] > '9') && codigo[i] != '#') return 0;

    return 1;
}

void destroi_trie(Trie t) {
    if (!t) return;

    if (t->item) free(t->item);

    for (int i = 0; i < NUM_DIG; i++)
        destroi_trie(t->vet_ap[i]);

    free(t);
}