#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include "Card.h"
#include "Card.cpp"
#include "Deck.h"


class DiscardPile : public std::vector<Card*>{ 
    using vector<Card*>::vector;
    public:
    DiscardPile(istream& is, const CardFactory* cf) {
        this = cf.getDiscardFromSave(is);
    }
    DiscardPile& operator+=(Card* c) {
        push_back(c);
    }
    Card* pickUp() {
        Card* c = back();
        pop_back();
        return c;
    }
    Card* top() {
        return back();
    }
    void print(std::ostream& out) {
        for (int i=0; i<d.size(); i++){
            d.at(i)->print(out);
            out << " ";
        }
        return out;
    }

    friend ostream & operator << (ostream &out, const DiscardPile &d){
        out << d.back().getName();
    }
}