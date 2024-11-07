#include <stdio.h>
#include <stdlib.h>
#include "trie.h"

enum FlagsErro {
    ERRO_ARGC_INVALIDO = 1,
    ERRO_FOPEN,
    ERRO_MALLOC
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

    while (!feof(arquivo)) {
        fscanf(arquivo, "%s", teste);
        printf("%s ", teste);
    }

    printf("\n");
    fclose(arquivo);
    free(teste);

    return 0;
}