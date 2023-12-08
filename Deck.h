#ifndef DECK_H
#define DECK_H

#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <stdexcept>
#include <sstream>

#include "CardFactory.h"



class Deck : public std::vector<Card*> {
    public:
        using vector<Card*>::vector;
        Deck(std::istream& is, CardFactory* cf);
        Deck();
        Card* operator[](int i);
        const Card* operator[](int i) const;
        Card* draw();
        void add(Card* c);
        void shuffle();

        friend std::ostream& operator << (std::ostream &out, Deck &d){
            for (int i=0; i<d.size(); i++){
                d.at(i)->print(out);
            }
            return out;
        }
};

#endif