#include <iostream>
#include <queue>
#include "Card.h"
#include "CardFactory.h"

class Hand {
    std::queue<Card*> h;

    public:
        Hand(istream& is, const CardFactory cf) {
            this = cf.getHandFromSave(is);
        }

        Hand& operator+=(Card* c) {
            h.push(c);
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

        friend ostream & operator << (ostream &out, const Hand &hand){
            for (std::list<Card*>::iterator it=hand.h.begin(); it != hand.h.end(); ++it){
                *it->print(out);
                out << " ";
            }
            return out;
        }

}