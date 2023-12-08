#include "Table.h"

Table::Table(Player* p1, Player* p2, Deck* d, DiscardPile* dpile, TradeArea* t) {
    player1 = p1;
    player2 = p2;
    deck = d;
    discardPile = dpile;
    tradeArea = t;
}

//renvoie true si le joueur a gagné
bool Table::win(std::string& playerName) const {
        int player1Coins = player1->getNumCoins();
        int player2Coins = player2->getNumCoins();
        int PlayerWithMaxCoins = std::max(player1Coins, player2Coins);

        // La condition de gagner est que toutes les cartes de Deck doivent avoir été reprises et alors le joueur avec le plus de pièces gagne.
        if (player1->getNumCoins() > PlayerWithMaxCoins && deck->empty()) {
            return true;
        }

        if (player2->getNumCoins() > PlayerWithMaxCoins && deck->empty()) {
            return true;
        }
        return false;
    }

//affiche la première carte de la main du joueur (avec l’argument false) ou l'ensemble de la main du joueur (avec argument true)
void Table::printHand(bool flag)  {
    //we can use the method we have in player class as it does same thing...
    player1->printHand(std::cout, flag);
    player2->printHand(std::cout, flag);
}

std::ostream& operator<<(std::ostream& os, const Table& table) {
    os << "Player 1:\n" << *table.player1 << "\n";
    os << "Player 2:\n" << *table.player2 << "\n";
    os << "Discard Pile:\n" << *table.discardPile << "\n";
    os << "Trade Area:\n" << *table.tradeArea << "\n";
    return os;
}

    Deck* Table::getDeck() {
        return deck;
    }
    Player* Table::getP1() {
        return player1;
    }

    Player* Table::getP2() {
        return player2;
    }
    DiscardPile* Table::getDiscard() {
        return discardPile;
    }
    TradeArea* Table::getTradeArea() {
        return tradeArea;
    }


//A partir du fichier to implement
//Table::Table(std::istream& is, const CardFactory* cf) {
//
//}