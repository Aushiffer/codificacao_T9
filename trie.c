#include "trie.h"

void inicia_trie(Trie *t) { *t = NULL; }

Trie cria_no() {
    Trie t;

    if (!(t = (Trie)malloc(sizeof(No)))) return NULL;

    for (int i = 0; i < NUM_DIG; i++)
        t->vet_ap[i] = NULL;

    strncpy(t->item, "|NULL|", TAM_PALAVRA);

    return t;
}

void busca_no(Trie t, char codigo[]) {
    char res[TAM_PALAVRA] = "|NULL|";

    busca_no_rec(t, codigo, 0, res);
    
    if (strcmp(res, "|NULL|") != 0)
        printf("%s\n", res);
    else
        printf("palavra nao encontrada\n");
}

void busca_no_rec(Trie t, char codigo[], size_t d, char res[]) {
    if (!t) return;

    if (codigo[d] == '\0') {
        strncpy(res, t->item, TAM_PALAVRA);

        return;
    }
    
    Trie prox;

    if (codigo[d] == '#')
        prox = t->vet_ap[NUM_DIG - 1];
    else
        prox = t->vet_ap[codigo[d] - '2'];

    busca_no_rec(prox, codigo, d + 1, res);
}

Trie insere_no(Trie t, char chave[], size_t d) {
    if (!t) t = cria_no();

    if (chave[d] != '\0') printf("%lu: %c\n", d, chave[d]); // Debugging.

    if (d == strlen(chave)) {
        strncpy(t->item, chave, TAM_PALAVRA);

        return t;
    }

    if (d > 0 && padrao(chave[d]) == padrao(chave[d - 1]))
        t->vet_ap[NUM_DIG - 1] = insere_no(t->vet_ap[NUM_DIG - 1], chave, d + 1);
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

unsigned char eh_folha(Trie t) {
    for (int i = 0; i < NUM_DIG; i++)
        if (t->vet_ap[i]) return 0;

    return 1;
}

void destroi_trie(Trie t) {
    if (!t) return;

    for (int i = 0; i < NUM_DIG; i++)
        destroi_trie(t->vet_ap[i]);

    free(t);
}