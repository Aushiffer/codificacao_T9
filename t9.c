#include "trie.h"

enum FlagsErro {
    ERRO_ARGC_INVALIDO = 1,
    ERRO_FOPEN,
    ERRO_TRIE
};

int main(int argc, char *argv[]) {
    if (argc != 2) {
        perror("main() - erro ao processar argumento, use ./t9 <nome do arquivo>.<extensão>");

        return ERRO_ARGC_INVALIDO;
    }

    FILE *arquivo;
    Trie trie; inicia_trie(&trie);
    char buf_input[TAM_PALAVRA];

    if (!(arquivo = fopen(argv[1], "r"))) {
        perror("main() - erro ao abrir arquivo");

        return ERRO_FOPEN;
    }

    if (!(trie = cria_no())) {
        perror("main() - erro na criação da raiz (dummy node)");

        return ERRO_TRIE;
    }

    while (!feof(arquivo)) {
        fscanf(arquivo, "%s", buf_input);
        
        trie = insere_no(trie, buf_input, 0);

        printf("\n");
    }

    busca_no(trie, "7625##");
    fclose(arquivo);
    destroi_trie(trie);

    return 0;
}