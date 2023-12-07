#ifndef HAND_H
#define HAND_H

#include <iostream>
#include <queue>
#include <list>
#include "Card.h"
// #include "CardFactory.h"

template<typename Card, typename Container=std::queue<Card*>>
class Hand {
    std::queue<Card*> h;
    // std::queue<Card*> h;

    public:
        // Hand(istream& is, const CardFactory cf) {
        //     this = cf.getHandFromSave(is);
        // }

        Hand& operator+=(Card* c) {
            h.push(c);
            Hand * hand = this;
            return hand;
        }

        Card* play() {
            Card* c = h.front();
            h.pop();
            return c;
        }

        Card* top() {
            return h.front();
        }

        Card* operator[](int i) {
            Card* c = h.at(i-1);
            h.erase(h.begin() + i-1);
            return c;
        }

        // typedef typename std::list<Card*>::const_iterator const_iterator;
        friend std::ostream & operator << (std::ostream &out, const Hand &hand){

            for (typename std::list<Card*>::const_iterator it=hand.h.begin(); it != hand.h.end(); ++it){
                (*it)->print(out);
                out << " ";
            }
            return out;
        }

};

#endif