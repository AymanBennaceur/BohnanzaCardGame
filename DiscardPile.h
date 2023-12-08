#ifndef DISCARD_H
#define DISCARD_H


#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include "CardFactory.h"


class DiscardPile : public std::vector<Card*>{ 
    using vector<Card*>::vector;
    public:
    DiscardPile(std::istream& is, CardFactory* cf);

    DiscardPile& operator+=(Card* c);

    Card* pickUp();

    Card* top();

    void print(std::ostream& out);

    friend std::ostream & operator << (std::ostream &out, DiscardPile &d){
        for (int i=0; i<d.size(); i++){
            d.at(i)->print(out);
        }
        return out;
    }
};
#endif