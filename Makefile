CC=g++
CFLAGS=-I

main: play.o Card.o Deck.o DiscardPile.o CardFactory.o Hand.o TradeArea.o
	$(CC)  Hand.h 
	$(CC)  Card.h 
	$(CC)  Deck.h 
	$(CC)  DiscardPile.h 
	$(CC)  CardFactory.h 
	$(CC)  TradeArea.h
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