#ifndef CHAIN_H
#define CHAIN_H
#include <iostream>
#include <vector>
#include "CardFactory.h"
// #include "Card.h"
#include "Chain_Base.h"

// using namespace std;

template<class T>
class Chain: public Chain_Base {
public:
    Chain<T>& operator+=(Card*) override;
    int sell() override;
    Chain(istream&, const CardFactory*) ;
    vector<T> getChain() {
        return cards;
    }
    friend ostream& operator << (ostream & out, const Chain& chain) ;
private:
    vector<T> cards;
};
#endif