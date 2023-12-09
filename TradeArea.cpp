#include "TradeArea.h"

//ajoute une carte à l’échange mais ne vérifie pas si c'est légal de placer la carte
TradeArea& TradeArea::operator+=(Card* card) {
    Traded.push_back(card);
    TradeArea* t = this;
    return *t;
}

//renvoie true si la carte peut être légalement ajouté à l’échange
bool TradeArea::legal(Card* card)  {
    for (auto& c : Traded) {
        //verifie si une carte du même haricot est déjà en échange
        if (c->getName() == card->getName()) {
            return true;
        }
    }
    return false;
}

// bool TradeArea::empty() {
//     numCards() == 0;
// }


// supprime de l’échange une carte du correspondant nom.
Card* TradeArea::trade(std::string chainName) {
    // Remove a card of the corresponding bean name from the trade area
    for (auto it = Traded.begin(); it != Traded.end(); ++it) {
        if ((*it)->getName() == chainName) {
            Card* tradedCard = *it;
            Traded.erase(it);
            return tradedCard;
        }
    }
    //in case something goes wrong, we return null..
    return nullptr;
}


//renvoie le nombre courant de cartes en échange, .size() de la librairie list
int TradeArea::numCards(){
    return Traded.size();
}

//l'opérateur d'insertion pour insérer toutes les cartes en échange dans ostream
// std::ostream& operator<<(std::ostream& os, const TradeArea& tradeArea) {
//     const auto& tradedCards = tradeArea.getTraded();
//     for (const auto& card : tradedCards) {
//         os << card->getName() << " ";
//     }
//     return os;
// }


//TradeArea possède un constructeur qui accepte un flux istream et construit un objet de type TradeArea à partir du fichier
//how do we build this from a file ? lol
TradeArea::TradeArea(std::istream& is, CardFactory* factory) {

}