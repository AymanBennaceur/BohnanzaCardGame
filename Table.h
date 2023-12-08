#include "Player.h"
#include "TradeArea.h"

class Table {
public:
    Table(std::istream& is, const CardFactory* cf);
    bool win(std::string& playerName) const;
    void printHand(bool flag) ;
    friend std::ostream& operator<<(std::ostream& os, const Table& table);

private:
    Player player1;
    Player player2;
    Deck deck;
    DiscardPile discardPile;
    TradeArea tradeArea;
};
