#ifndef CARD_H
#define CARD_H
#include <string>
#include <iostream>

class Card {

    protected:
        std::string name;
        int number_of_cards;
        int beanometer[4];
    public:
        virtual int getCardsPerCoin(int) =0;
        virtual std::string getName() = 0;
        virtual void print(std::ostream&) = 0;

        friend std::ostream & operator << (std::ostream &out, const Card &c){
            out << c.name[0];
            return out;
        }
};

#endif