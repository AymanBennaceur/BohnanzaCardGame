#ifndef HAND_H
#define HAND_H

// #include <iostream>
#include <vector>
#include "CardFactory.h"

class Hand : public std::vector<Card*> {
    public:
        
        Hand(std::istream& is, CardFactory* cf);
        using vector<Card*>::vector;

        Hand& operator+=(Card* c);

        Card* play();

        Card* top();

        Card* operator[](int i);

        friend std::ostream& operator << (std::ostream &out, Hand &h){
            for (int i=0; i<h.size(); i++){
                h.at(i)->print(out);
            }
            return out;
        }
};

#endif