#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <stdexcept>

#include "Deck.h"
#include "DiscardPile.h"
#include "Hand.h"
#include "Card.cpp"

class CardFactory {
    private:

        static CardFactory* cf;
        
        CardFactory(){
        }        
        

    public:
        
        CardFactory(CardFactory &other) = delete;
        void operator=(const CardFactory&) = delete;

        Deck* getDeck();

        static CardFactory* getFactory();



};

