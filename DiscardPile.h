#ifndef DISCARD_H
#define DISCARD_H


#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include "Card.h"


class DiscardPile : public std::vector<Card*>{ 
    using vector<Card*>::vector;
    public:
    // DiscardPile(std::istream& is, const CardFactory* cf);

    DiscardPile& operator+=(Card* c);

    Card* pickUp();

    Card* top();

    void print(std::ostream& out);

    friend std::ostream & operator << (std::ostream &out, DiscardPile &d){
        d.back()->print(out);
        out << " ";
        return out;
    }
};
#endif