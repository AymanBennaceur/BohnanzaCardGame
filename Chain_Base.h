#ifndef CHAIN_BASE_H
#define CHAIN_BASE_H

#include <iostream>
#include <vector>
#include "Card.h"

class Chain_Base {
public:
    virtual Chain_Base& operator+=(Card* card)=0;
    virtual int sell() = 0;
    virtual std::vector<Card*> getChain() =0;
    virtual bool isCorrectType(std::string) = 0;
    // virtual void print(std::ostream& os);
};

#endif /* CHAIN_BASE_H */
