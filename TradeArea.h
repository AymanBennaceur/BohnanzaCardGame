#ifndef TRADE_AREA_H
#define TRADE_AREA_H

#include <vector>
#include <list>
#include <iostream>
#include <string.h>
#include <list>

#include "CardFactory.h"

class TradeArea {

public:
    std::list<Card*> Traded;
    const std::list<Card*>& getTraded() const {
        return Traded;
    }
    TradeArea& operator += (Card*);
    bool legal(Card*);
    bool empty();
    Card* trade(std::string);
    int numCards();
    TradeArea() {};

    TradeArea(std::istream&, CardFactory* );
    friend std::ostream& operator<<(std::ostream& os, TradeArea& tradeArea) {
        const auto& tradedCards = tradeArea.getTraded();
        for (const auto& card : tradedCards) {
            os << card->getName() << " ";
        }
        return os;
    }

};
#endif