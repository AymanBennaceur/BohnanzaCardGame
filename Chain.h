#ifndef CHAIN_H
#define CHAIN_H
// #include "Card.h"
#include <iostream>
#include <typeinfo>
#include <type_traits>

#include <vector>
#include "CardFactory.h"
#include "Chain_Base.h"

// using namespace std;

template<class T>
class Chain: public Chain_Base {
public:
    Chain(Card *card);
    Chain& operator+=(T);
    int sell();
    // Chain(std::istream&, CardFactory*);
    std::vector<T> getChain();
    friend std::ostream& operator << (std::ostream & out, Chain& chain)  {
        // if (chain.cards.size() > 0) {
        //     out << chain.cards.at(0)->getName() << "   ";
        // }

        for (int x = 0; x < int(chain.getChain().size());x++) {
            chain.cards.at(x)->print(out);
        }
        return out;
    }
    bool isCorrectType(std::string);
private:
    std::vector<T> cards;
    std::string chainType;
};
#endif