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
// Se a string correspondente ao código existir na trie, imprime a palavra buscada, caso contrário imprime 'palavra nao encontrada'.
// É uma função auxiliar para a função recursiva de busca.
void busca_no(Trie t, char codigo[]);

// Recebe uma trie, um código em T9 e um valor posicional para o dígito sendo considerado.
// Busca uma palavra na trie n-ária e retorna o nó que possui a chave (ou NULL caso ela não exista).
Trie busca_no_rec(Trie t, char codigo[], size_t d);

// Recebe um caractere e retorna o padrão associado a ele. Caso o caractere não pertença a nenhum padrão, retorna -1.
int padrao(char c);

// Recebe um código em T9 e verifica se e avalia sua validade, ou seja, se para todo dígito 'k' do código, 'k' está em [2..9].
unsigned char codigo_valido(char codigo[]);

// Recebe uma trie e libera todo o espaço alocado para ela.
void destroi_trie(Trie t);

#endif // __TRIE__