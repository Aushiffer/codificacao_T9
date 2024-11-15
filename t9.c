/* 
* t9.c: programa cliente.
* Autores: Caio E. F. de Miranda e Andreus G. Schultz.
* Carrega as palavras do arquivo de entrada na trie e possibilita a busca por palavras na trie.
*/ 

#include "trie.h"

enum FlagsErro {
    ERRO_ARGC_INVALIDO = 1,
    ERRO_FOPEN,
    ERRO_TRIE_CRIACAO,
    ERRO_TRIE_INSERCAO
};

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "main() - erro ao processar argumento, use ./t9 <nome do arquivo>.<extensão>");

        return ERRO_ARGC_INVALIDO;
    }

    FILE *arquivo;
    Trie trie; inicia_trie(&trie);
    Trie res_busca; inicia_trie(&res_busca);
    char entrada[TAM_PALAVRA], entrada_cat[TAM_PALAVRA << 1];

    // Inicialização da stream de arquivo.
    if (!(arquivo = fopen(argv[1], "r"))) {
        fprintf(stderr, "main() - erro ao abrir arquivo");

        return ERRO_FOPEN;
    }

    // Inicialização da trie.
    if (!(trie = cria_no())) {
        fprintf(stderr, "main() - erro na criação da raiz (dummy node)");

        return ERRO_TRIE_CRIACAO;
    }

    // Construção da trie.
    while (!feof(arquivo)) {
        fscanf(arquivo, "%s", entrada);
        
        if (!(trie = insere_no(trie, entrada, 0))) {
            fprintf(stderr, "main() - erro na inserção");
            fclose(arquivo);
            destroi_trie(trie);

            return ERRO_TRIE_INSERCAO;
        }
    }

    scanf("%s", entrada);
    strncpy(entrada_cat, entrada, TAM_PALAVRA);

    while (strcmp(entrada, "0") != 0) {
        busca_no(trie, entrada_cat);        
        scanf("%s", entrada);

        // Se ao menos o primeiro caractere da nova entrada for '#', concatene a substring com '#'.
        // Caso contrário, apenas substitua entrada_cat.
        if (entrada[0] == '#') 
            strncat(entrada_cat, entrada, TAM_PALAVRA);
        else
            strncpy(entrada_cat, entrada, TAM_PALAVRA);
    }

    fclose(arquivo);
    destroi_trie(trie);

    return 0;
}