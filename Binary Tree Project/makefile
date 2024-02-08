countWords: binaryTree.o count_words.o
	gcc -g -Wall count_words.o binaryTree.o -lm -o countWords

binaryTree.o: binaryTree.h binaryTree.c
	gcc -g -Wall -c binaryTree.c

count_words.o: binaryTree.h count_words.c
	gcc -g -Wall -c count_words.c

clean:
	del -f count_words.o binaryTree.o countWords

all: countWords
