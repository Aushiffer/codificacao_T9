#include "trie.h"

void inicia_trie(Trie *t) { *t = NULL; }

Trie cria_no() {
    Trie t;

    if (!(t = (Trie)malloc(sizeof(No)))) return NULL;

    for (int i = 0; i < NUM_DIG; i++)
        t->vet_ap[i] = NULL;

    set_chave(t, "|NULL|");

    return t;
}

void set_chave(Trie t, char chave[]) { strncpy(t->item, chave, TAM_PALAVRA); }

void busca_no(Trie t, char codigo[]) {
    if (!codigo_valido(codigo)) {
        printf("entrada invalida\n");

        return;
    }

    Trie no_busca = busca_no_rec(t, codigo, 0);

    if (no_busca && strcmp(no_busca->item, "|NULL|") != 0) {
        printf("%s\n", no_busca->item);

    } else
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
            Trie novo_no = cria_no();
            set_chave(novo_no, chave);

            return novo_no;
        }

        if (strcmp(t->item, "|NULL|") == 0)
            set_chave(t, chave);
        else
            t->vet_ap[NUM_DIG - 1] = insere_no(t->vet_ap[NUM_DIG - 1], chave, d);

        return t;     
    }

    if (!t) {
        if (!(t = cria_no())) {
            perror("insere_no() - erro ao inserir um novo nó");

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
            perror("insere_no() - padrão não encontrado");

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
        if (codigo[i] < '2' && codigo[i] != '#') return 0;

    return 1;
}

void destroi_trie(Trie t) {
    if (!t) return;

    for (int i = 0; i < NUM_DIG; i++)
        destroi_trie(t->vet_ap[i]);

    free(t);
}