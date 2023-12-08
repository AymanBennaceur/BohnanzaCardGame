#ifndef CARD_FACTORY_H
#define CARD_FACTORY_H

#include <iostream>
#include <vector>

#include "Card.cpp"

class CardFactory {
    private:

        static CardFactory* cf;
        
        CardFactory(){
        }        
        

    public:
        
        CardFactory(CardFactory &other) = delete;
        void operator=(const CardFactory&) = delete;

        // Deck* getDeck();
        Card* getCard(char c);

        static CardFactory* getFactory();


};


#endif