#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include "Card.h"
#include "Card.cpp"
#include "Deck.h"


class CardFactory {
    private:
        std::vector<Card*> d;
        static CardFactory* cf;
        CardFactory() {
            int i;
            for (i = 0; i<20; i++) {
                d.push_back(new Blue());
            }
            for (i = 0; i<18; i++) {
                d.push_back(new Chili());
            } 
            for (i = 0; i<16; i++) {
                d.push_back(new Stink());
            } 
            for (i = 0; i<14; i++) {
                d.push_back(new Green());
            } 
            for (i = 0; i<12; i++) {
                d.push_back(new soy());
            } 
            for (i = 0; i<10; i++) {
                d.push_back(new black());
            } 
            for (i = 0; i<8; i++) {
                d.push_back(new Red());
            } 
            for (i = 0; i<6; i++) {
                d.push_back(new garden());
            } 
        }
    public:
        CardFactory(CardFactory &other) = delete();
        void operator=(const CardFactory&) = delete();

        static CardFactory* getFactory() {
            if(cf == nullptr) {
                cf = new CardFactory();
            }
            return cf;
        }

        Deck getDeck() {
            std::random_device rd;
            std::mt19937 g(rd());
            std::shuffle(d.begin(), d.end(), g);
            return d;
        }
};

