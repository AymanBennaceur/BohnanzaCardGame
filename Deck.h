#ifndef DECK_H
#define DECK_H

#include <iostream>
#include <vector>
#include "Card.h"


class Deck : public std::vector<Card*> {
    public:
        using vector<Card*>::vector;
        // example save file: b B R s S S ...
        // Deck(std::istream& is, const CardFactory* cf);
        Card* operator[](int i);
        const Card* operator[](int i) const;
        Card* draw();
        void add(Card* c);

        friend std::ostream& operator << (std::ostream &out, Deck &d){
            for (int i=0; i<d.size(); i++){
                d.at(i)->print(out);
            }
            return out;
        }
};

#endif