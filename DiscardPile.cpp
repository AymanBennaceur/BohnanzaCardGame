#include "DiscardPile.h"

DiscardPile& DiscardPile::operator+=(Card* c) {
    vector<Card*>::push_back(c);
    DiscardPile* d = this;
    return *d;
}

Card* DiscardPile::pickUp() {
    Card* c = vector<Card*>::back();
    vector<Card*>::pop_back();
    return c;
}
Card* DiscardPile::top() {
    return vector<Card*>::back();
}
void DiscardPile::print(std::ostream& out) {
    for (int i=0; i<vector<Card*>::size(); i++){
        vector<Card*>::at(i)->print(out);
        out << " ";
    }
}
