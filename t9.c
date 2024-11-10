#include "trie.h"

enum FlagsErro {
    ERRO_ARGC_INVALIDO = 1,
    ERRO_FOPEN,
    ERRO_MALLOC,
    ERRO_TRIE
};

int main(int argc, char *argv[]) {
    if (argc != 2) {
        perror("main() - erro ao processar argumento, use ./t9 <nome do arquivo>.<extensão>");

        return ERRO_ARGC_INVALIDO;
    }

    FILE *arquivo;

    if (!(arquivo = fopen(argv[1], "r"))) {
        perror("main() - erro ao abrir arquivo");

        return ERRO_FOPEN;
    }

    char *teste;

    if (!(teste = (char *)malloc(64 * sizeof(char)))) {
        perror("main() - erro de alocação");

        return ERRO_MALLOC;
    }

    Trie trie; inicia_trie(&trie);

    if (!(trie = cria_no())) return ERRO_TRIE; // Deve existir um nó 'dummy' antes da inserção de qualquer palavra.

    // Testes.
    trie = insere_no(trie, "socks", 0);
    trie = insere_no(trie, "rocks", 0);
    trie = insere_no(trie, "jello", 0);
    trie = insere_no(trie, "jell", 0);

    while (!feof(arquivo)) {
        fscanf(arquivo, "%s", teste);
        printf("%s ", teste);
    }

    printf("\n");
    fclose(arquivo);
    free(teste);
    destroi_trie(trie);

    return 0;
}