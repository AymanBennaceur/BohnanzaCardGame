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
        if(is) {
            is.seekg(0, is.end);
            int l = is.tellg()/2;
            is.seekg(0, is.beg);
            char c;
            for (int i = 0; i<l; i++) {
                is.seekg(2, is.cur);
                is.readsome(c, 1);
                if (c == "B") {
                    push_back(new Blue());
                } else if (c == "C") {
                    push_back(new Chili());
                } else if (c == "S") {
                    push_back(new Stink());
                } else if (c == "G") {
                    push_back(new Green());
                } else if (c == "s") {
                    push_back(new soy());
                } else if (c == "b") {
                    push_back(new black());
                } else if (c == "R") {
                    push_back(new Red());
                } else if (c == "g") {
                    push_back(new Green());
                } else {
                    cout << "error reading save file, starting new game";
                }
            }
        }
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