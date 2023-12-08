CC=g++
CFLAGS=-I

# main: play.o Card.o Deck.o DiscardPile.o CardFactory.o Hand.o TradeArea.o
main:
	$(CC)  Hand.h  Card.h  Deck.h  DiscardPile.h  CardFactory.h  TradeArea.h  Chain.h  Chain_Base.h Player.h Table.h
	$(CC) Card.cpp Deck.cpp DiscardPile.cpp CardFactory.cpp Hand.cpp TradeArea.cpp Chain.cpp Player.cpp  Table.cpp play.cpp -o main 
	
	

clean:
	rm -f *.o
	rm -f *.gch
	rm -f main