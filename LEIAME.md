# codificacao_T9
Trabalho feito na disciplina de Algoritmos e Estruturas de Dados III.
O objetivo do trabalho era implementar o texto preditivo T9, um tipo de entrada desenvolvida para ser usada em teclados numéricos.

## Autoria
Caio E. F. de Miranda e Andreus G. Schultz.

## Estrutura de dados
Foi usada uma trie n-ária mista com uma trie existencial.
Cada nó da trie guarda um vetor de apontadores, um para cada dígito possível, e um apontador para char, que aqui é denotado como string.
Toda chave é representada por um caminho único relativo à sua codificação em T9, com sua string armazenada no último nó do caminho.