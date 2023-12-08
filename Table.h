#ifndef TABLE_H
#define TABLE_H

#include "Player.h"
#include "TradeArea.h"
#include "Deck.h"
#include "DiscardPile.h"


class Table {
public:
    Table(Player* p1, Player* p2, Deck* d, DiscardPile* dpile, TradeArea* t);
    Table(std::istream& is, const CardFactory* cf);
    bool win(std::string& playerName) const;
    void printHand(bool flag) ;
    friend std::ostream& operator<<(std::ostream& os, const Table& table);
    Deck* getDeck();
    Player* getP1();
    Player* getP2();
    DiscardPile* getDiscard();
    TradeArea* getTradeArea();


private:
    Player* player1;
    Player* player2;
    Deck* deck;
    DiscardPile* discardPile;
    TradeArea* tradeArea;
};
#endif
