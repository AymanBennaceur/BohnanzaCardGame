CC=g++
CFLAGS=-I

Bohnanza: play.o Card.o Deck.o DiscardPile.o CardFactory.o
	$(CC) -o main play.o Card.o Deck.o DiscardPile.o CardFactory.o
