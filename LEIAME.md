# codificacao_T9
Trabalho feito na disciplina de Algoritmos e Estruturas de Dados III.
O objetivo do trabalho era implementar o texto preditivo T9, um tipo de entrada desenvolvida para ser usada em teclados numéricos.

## Autoria
Caio E. F. de Miranda e Andreus G. Schultz.

## Estrutura de dados
Foi usada uma trie n-ária mista com uma trie existencial.
Cada nó da trie guarda um vetor de apontadores, um para cada dígito possível, e um apontador para char, que aqui é denotado como string.
Toda chave é representada por um caminho único relativo à sua codificação em T9, com sua string armazenada no último nó do caminho.
Se duas palavras possuírem a mesma codificação, a que foi inserida depois é colocada no vetor de apontadores no índice referente ao caractere '#'. Consequentemente, se for inserida outra palavra com a mesma codificação, ela será inserida no índice referente ao '#' da segunda palavra, e assim por diante.

## Algoritmos relevantes
### Busca | Complexidade: O(c), onde 'c' é o tamanho do código.
A busca é feita através de uma interface que verifica, antecipadamente, se o código sendo buscado é válido dentro do contexto da codificação.
Se o código for válido, a busca na trie é feita recursivamente com base no código mandado no parâmetro da função.
Se o nó retornado pela função recursiva não for nulo e possuir uma string, então a busca foi bem sucedida e a string no nó é mostrada é impressa na saída padrão. Caso contrário, na saída padrão é mostrado 'palavra nao encontrada'.

### Inserção | Complexidade: O(k), onde 'k' é o tamanho da chave.
A inserção é feita avaliando cada caractere de uma chave a ser inserida, da esquerda para a direita.
Cada caractere é mapeado para o seu respectivo padrão, e então a inserção ocorre no índice do vetor de apontadores referente àquele padrão.
Se o nó na chamada atual é nulo e a chave não foi completamente processada, o caminho da chave é incrementado e a inserção continua.
Se, na chamada atual, todos os caracteres foram processados, existem três possibilidades:

#### O nó atual é nulo
Um novo nó é criado, a chave é inserida e então ele é retornado.

#### O nó atual não é nulo mas não existe uma chave nele
A chave é inserida no nó e então ele é retornado.

#### O nó atual não é nulo e já existe uma chave nele
Significa que existe uma coincidência de codificação nas chaves. 
A inserção ocorre recursivamente no índice do vetor de apontadores referente ao '#'.

## Dificuldades no trabalho
- Desenvolver as ideias para tratar os diferentes casos na inserção;
- Tratar a entrada da maneira esperada.