#include "trie.h"

void inicia_trie(Trie *t) { *t = NULL; }

Trie cria_no() {
    Trie t;

    if (!(t = (Trie)malloc(sizeof(No)))) return NULL;

    for (int i = 0; i < NUM_DIG; i++)
        t->vet_ap[i] = NULL; // Inicialização dos ponteiros.

    return t;
}

unsigned char eh_folha(Trie t) {
    for (int i = 0; i < NUM_DIG; i++)
        if (t->vet_ap[i]) return 0;

    return 1;
}