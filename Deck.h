#include <iostream>
#include <vector>
#include "Card.h"
#include "CardFactory.h"


class Deck : public std::vector<Card*> {
    public:
        using vector<Card*>::vector;

        // example save file: b B R s S S ...

        Deck(istream& is, const CardFactory* cf) {
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
                        this = cf.getDeck();
                    }
                }
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