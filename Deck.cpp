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
    return at(i);
}

void Deck::add(Card* c) {
    push_back(c);
}

const Card* Deck::operator[](int i) const {
    return at(i);
}

Card* Deck::draw() {
    Card* c = back();
    pop_back();
    return c;
}


