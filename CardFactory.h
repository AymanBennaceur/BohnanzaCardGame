#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include "Deck.h"
#include "DiscardPile.h"
#include "Hand.h"
#include "Card.cpp"


class CardFactory {
    private:
        Deck d;
        static CardFactory* cf;
        CardFactory();
    public:
        CardFactory(CardFactory &other) = delete;
        void operator=(const CardFactory&) = delete;

        static CardFactory* getFactory();

        Deck getDeck();

        Deck getDeckFromSave(std::istream& is);

        template<typename Card, typename Container=std::queue<Card*>>
        Hand getHandFromSave(std::istream& is);

        DiscardPile getDiscardFromSave(std::istream& is);
};

