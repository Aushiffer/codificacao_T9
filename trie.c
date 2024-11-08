#include "trie.h"

void inicia_trie(Trie *t) { *t = NULL; }

unsigned char eh_folha(Trie t) {
    for (int i = 0; i < NUM_DIG; i++)
        if (t->vet_ap[i]) return 0;

    return 1;
}