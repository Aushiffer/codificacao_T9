#ifndef __TRIE__
#define __TRIE__

// Número de dígitos possíveis + 1 caracter de terminação.
#define NUM_DIG 8

#include <stdlib.h>

// Padrões para cada dígito do teclado.
#define PADRAO_2 "ABCabc"
#define PADRAO_3 "DEFdef"
#define PADRAO_4 "GHIghi"
#define PADRAO_5 "JKLjkl"
#define PADRAO_6 "MNOmno"
#define PADRAO_7 "PQRSpqrs"
#define PADRAO_8 "TUVtuv"
#define PADRAO_9 "WXYZwxyz"

// Dígitos possíveis
#define ALFABETO "#23456789"

// TAD: Trie M-ária de existência.
typedef struct No *Trie;
typedef struct No {
    Trie vet_ap[NUM_DIG];
} No;

// Recebe um ponteiro para uma trie e o inicializa com NULL.
void inicia_trie(Trie *t);

// Retorna um novo nó de uma trie existencial, cujos apontadores são nulos.
// Caso a alocação gere erro, retorna NULL.
Trie cria_no();

// Recebe uma trie, uma string e um valor posicional para o dígito sendo considerado;
// Insere uma palavra na trie existencial, criando o caminho que representa a palavra.
Trie insere_no(Trie t, char str[], int d);

// Recebe uma trie e um código em T9;
// Realiza uma busca conforme a travessia na trie é realizada;
// Se a string existir na trie, imprime a palavra buscada, caso contrário imprime 'palavra nao encontrada'.
// É uma função auxiliar para a função recursiva de busca.
void busca_no(Trie t, char codigo[]);

// Recebe uma trie, um código em T9 e um valor posicional para o dígito sendo considerado e uma string de resultado;
// Busca uma palavra na trie existencial e coloca o resultado em uma string de consulta.
void busca_no_rec(Trie t, char codigo[], int d, char res[]);

// Recebe uma string de padrão, índices das extremidades do vetor 'l' e 'r' e um caracter 'c';
// Retorna 1 se o caracter existe no padrão, 0 caso contrário.
unsigned char existe(char padrao[], int l, int r, char c);

// Recebe uma trie e retorna 1 se o nó for uma folha, 0 caso contrário.
unsigned char eh_folha(Trie t);

#endif // __TRIE__