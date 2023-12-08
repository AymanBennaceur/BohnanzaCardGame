#ifndef CHAIN_H
#define CHAIN_H
#include <iostream>
#include <vector>
#include "CardFactory.h"
#include "Card.h"

using namespace std;

template<class T>
class Chain {
public:
    Chain<T>& operator+=(Card*);
    int sell();
    Chain(istream&, const CardFactory*);
    vector<T> getChain() {
        return cards;
    }
    friend ostream& operator << (ostream & out, const Chain& chain);
private:
    vector<T> cards;
};
#endif