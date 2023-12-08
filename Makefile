CC=g++
CFLAGS=-I

main: play.o Card.o Deck.o DiscardPile.o CardFactory.o Hand.o TradeArea.o
# main:
	$(CC)  Hand.h  Card.h  Deck.h  DiscardPile.h  CardFactory.h  TradeArea.h  Chain.h  Chain_Base.h

	$(CC)  -c Card.cpp
	$(CC)  -c Deck.cpp
	$(CC)  -c DiscardPile.cpp
	$(CC)  -c CardFactory.cpp
	$(CC)  -c Hand.cpp
	$(CC)  -c TradeArea.cpp
	$(CC)  -c play.cpp
	$(CC) -o main Card.o Deck.o DiscardPile.o CardFactory.o Hand.o TradeArea.o play.o

clean:
	rm -f *.o
	rm -f *.gch