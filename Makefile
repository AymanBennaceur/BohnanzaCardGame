CC=g++
CFLAGS=-I

Bohnanza: play.o Card.o Deck.o DiscardPile.o CardFactory.o Hand.o
	# $(CC) Card.h Deck.h DiscardPile.h CardFactory.h Hand.h
	$(CC) -o main play.o Card.o Deck.o DiscardPile.o CardFactory.o Hand.o
