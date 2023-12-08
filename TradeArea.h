#include "Card.h"
#include <vector>
#include <list>
#include <iostream>
#include "CardFactory.h"
using namespace std;

class TradeArea {
private:
    list<Card*> Traded;
    const std::list<Card*>& getTraded() const {
        return Traded;
    }
public:
    TradeArea& operator += (Card*);
    bool legal(Card*);
    bool empty();
    Card* trade(string);
    int numCards();
    TradeArea(istream&, const CardFactory* );
    friend std::ostream& operator<<(std::ostream& os, const TradeArea& tradeArea);

};