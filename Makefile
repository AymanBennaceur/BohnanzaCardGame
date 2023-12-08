CC=g++
CFLAGS=-I

Bohnanza: play.o Card.o Deck.o DiscardPile.o CardFactory.o Hand.o TradeArea.o Chain.o
	$(CC) Card.h Deck.h DiscardPile.h CardFactory.h Hand.h TradeArea.h
	$(CC) -o main play.o Card.o Deck.o DiscardPile.o CardFactory.o Hand.o TradeArea.o Chain.o
