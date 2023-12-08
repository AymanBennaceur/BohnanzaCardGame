#include "DiscardPile.h"

DiscardPile& DiscardPile::operator+=(Card* c) {
    push_back(c);
    DiscardPile* d = this;
    return *d;
}

Card* DiscardPile::pickUp() {
    Card* c = back();
    pop_back();
    return c;
}
Card* DiscardPile::top() {
    return back();
}
void DiscardPile::print(std::ostream& out) {
    for (int i=0; i<size(); i++){
        at(i)->print(out);
    }
}


