#include "Deck.h"

// Deck(std::istream& is, const CardFactory* cf) {
//     if(is) {
//         this = cf.getDeckFromSave(is);
//     }
//     else {
//         this = cf.getDeck();
//     }
// }

Card* Deck::operator[](int i) {
    return vector<Card*>::at(i);
}

void Deck::add(Card* c) {
    vector<Card*>::push_back(c);
}

const Card* Deck::operator[](int i) const {
    return vector<Card*>::at(i);
}

Card* Deck::draw() {
    Card* c = vector<Card*>::back();
    vector<Card*>::pop_back();
    return c;
}


