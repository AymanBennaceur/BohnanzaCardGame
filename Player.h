

#ifndef Player_h
#define Player_h

#include "CardFactory.h"
#include "Chain.cpp"
#include <string>
#include <vector>
#include <exception>
//doesnt exist for now..
#include "Hand.h"
#include <iostream>
using namespace std;



class NotEnoughCoins: public exception{
    virtual const char* what() const throw(){
        return "Vous n'avez pas assez de pièces (2coins) pour acheter une troisième chaîne";
    }
};


class Player {
    int coins,
    numChains = 0,
    maxChains = 2;
    vector<Chain_Base>* chain;
    string playerName;
    //Wont work until we make hand..
    Hand* hand;
public:
    //constructeur
    Player(string&);
    Player(istream& in, CardFactory*);

    //returns the name of the player
    string getName() const;
    int getNumCoins() const;

    void setHand(Hand*);
    Hand* getHand();


    Player& operator+=(int);

    int getMaxNumChains() const;
    int getNumChains() const;

    Chain_Base& operator[](int i);

    void buyThirdChain();
    void printHand(ostream&, bool);

    void operator<<(ostream& out);

    friend ostream& operator<<(ostream& out, const Player& player);

};

#endif /* Player_h */