#ifndef CHAIN_BASE_H
#define CHAIN_BASE_H

#include <iostream>
#include <vector>
#include "Card.h"

class Chain_Base {
public:
    virtual Chain_Base& operator+=(Card* card);
    virtual int sell();
    virtual std::vector<Card*> getChain() ;
    virtual void print(std::ostream& os);
};

#endif /* CHAIN_BASE_H */
