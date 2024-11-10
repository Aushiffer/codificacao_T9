#ifndef __TRIE__
#define __TRIE__

// Número de dígitos possíveis.
#define NUM_DIG 9

// Tamanho máximo da palavra.
#define TAM_PALAVRA 257

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// TAD: Trie n-ária.
typedef struct No *Trie;
typedef struct No {
    Trie vet_ap[NUM_DIG];
    char item[TAM_PALAVRA];
} No;

// Recebe um ponteiro para uma trie n-ária e o inicializa com NULL.
void inicia_trie(Trie *t);

// Retorna um novo nó de uma trie n-ária, cujos apontadores são nulos.
// Caso a alocação gere erro, retorna NULL.
Trie cria_no();

// Recebe uma trie e uma chave.
// Altera a chave da trie para a chave mandada por parâmetro.
void set_chave(Trie t, char chave[]);

// Recebe uma trie, uma string e um valor posicional para o dígito sendo considerado;
// Insere uma palavra na trie n-ária, criando o caminho que representa a palavra.
Trie insere_no(Trie t, char chave[], size_t d);

// Recebe uma trie e um código em T9;
// Realiza uma busca conforme a travessia na trie é realizada;
// Se a string existir na trie, imprime a palavra buscada, caso contrário imprime 'palavra nao encontrada'.
// É uma função auxiliar para a função recursiva de busca.
void busca_no(Trie t, char codigo[]);

// Recebe uma trie, um código em T9, a chave correspondente ao código, um valor posicional para o dígito sendo considerado e uma string de resultado;
// Busca uma palavra na trie n-ária e coloca o resultado em uma string de consulta.
Trie busca_no_rec(Trie t, char codigo[], size_t d);

// Recebe uma trie e retorna 1 se o nó for uma folha, 0 caso contrário.
unsigned char eh_folha(Trie t);

// Recebe um caractere e retorna o padrão associado a ele. Caso o caractere não pertença a nenhum padrão, retorna -1.
int padrao(char c);

// Recebe uma trie e libera todo o espaço alocado para ela.
void destroi_trie(Trie t);

#endif // __TRIE__