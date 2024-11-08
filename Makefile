CC = gcc
CCFLAGS = -g -Wall -Wextra -pedantic
PROGRAM = t9

all: $(PROGRAM)

$(PROGRAM): trie.o t9.o
	$(CC) $(CCFLAGS) trie.o t9.o -o $(PROGRAM)

trie.o: trie.c
	$(CC) -c trie.c $(CCFLAGS)

t9.o: t9.c
	$(CC) -c t9.c $(CCFLAGS)

clean:
	rm -f *.o $(PROGRAM)