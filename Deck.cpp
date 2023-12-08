#include "Deck.h"

Deck::Deck(std::istream& is, CardFactory* cf) {
    char c;
    while (is.get(c)){
        add(cf->getCard(c));
    }
}

Deck::Deck() {
    CardFactory* factory = CardFactory::getFactory();
    std::string s = "BBBBBBBBBBBBBBBBBBBBCCCCCCCCCCCCCCCCCCSSSSSSSSSSSSSSSSGGGGGGGGGGGGGGssssssssssssbbbbbbbbbbRRRRRRRRgggggg";
    std::istringstream is;
    is.str(s);
    Deck((std::istream&)is, factory);
    shuffle();
}

void Deck::shuffle() {
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(begin(), end(), g);
}

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


