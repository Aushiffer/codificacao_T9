#ifndef __TRIE__
#define __TRIE__

// Número de dígitos possíveis
#define NUM_DIG 8

// Padrões para cada dígito do teclado
#define PADRAO_2 "abcABC"
#define PADRAO_3 "defDEF"
#define PADRAO_4 "ghiGHI"
#define PADRAO_5 "jklJKL"
#define PADRAO_6 "mnoMNO"
#define PADRAO_7 "pqrsPQRS"
#define PADRAO_8 "tuvTUV"
#define PADRAO_9 "wxyzWXYZ"

// TAD Trie M-ária de existência
typedef struct No *Trie;
typedef struct No {
    Trie vet_ap[NUM_DIG];
} No;

// Recebe um ponteiro para uma trie e o inicializa com NULL.
Trie inicia_trie(Trie *t);

// Recebe uma trie e uma chave, e então cria um caminho de nós que representa a chave. 
Trie cria_no(Trie t, char str[]);

// Recebe uma string 'str' e retorna o padrão a qual ela pertence. 
unsigned int padrao_dig(char str[]);

// Recebe uma trie e retorna 1 se o nó for uma folha, 0 caso contrário.
unsigned char eh_folha(Trie t);

#endif // __TRIE__