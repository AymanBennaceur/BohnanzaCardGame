#include <iostream>
#include <vector>
#include "Card.h"


class Deck : public std::vector<Card*> {
    public:
        using vector<Card*>::vector;
        // example save file: b B R s S S ...

        Deck(istream& is, const CardFactory* cf) {
            if(is) {
                this = cf.getDeckFromSave(is);
            }
            else {
                this = cf.getDeck();
            }
        }

        Card* operator[](int i) {
            return at(i);
        }

        const Card* operator[](int i) const {
            return at(i);
        }
        Card* draw() {
            Card* c = back();
            pop_back();
            return c;
        }

        friend ostream & operator << (ostream &out, const Deck &d){
            for (int i=0; i<d.size(); i++){
                d.at(i)->print(out);
                out << " ";
            }
            return out;
        }
};