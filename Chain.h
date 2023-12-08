#ifndef CHAIN_H
#define CHAIN_H
#include <iostream>
#include <vector>
#include "CardFactory.h"
#include "Chain_Base.h"

// using namespace std;

template<class T>
class Chain: public Chain_Base {
public:
    Chain& operator+=(T*) override;
    int sell() override;
    Chain(std::istream&, const CardFactory*) ;
    std::vector<T> getChain() {
        return cards;
    }
    friend std::ostream& operator << (std::ostream & out, const Chain& chain) ;
private:
    std::vector<Card*> cards;
};
#endif