

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
// using namespace std;



class NotEnoughCoins: public std::exception{
    virtual const char* what() const throw(){
        return "Vous n'avez pas assez de pièces (2coins) pour acheter une troisième chaîne";
    }
};


class Player {
    int coins,
    numChains,
    maxChains;
    std::string playerName;
    //Wont work until we make hand..
    Hand* hand;
public:
    std::vector<Chain<Card*>*> chain;

    //constructeur
    Player(std::string&);
    Player(std::istream& in, CardFactory*);

    //returns the name of the player
    std::string getName() const;
    int getNumCoins() const;

    void setHand(Hand*);
    Hand* getHand();


    Player& operator+=(int);

    int getMaxNumChains() const;
    int getNumChains() const;
    void addChain(Chain<Card*>*);

    Chain<Card*>* operator[](int i);

    void buyThirdChain();
    void printHand(std::ostream&, bool);

    void operator<<(std::ostream& out);

    friend std::ostream& operator<<(std::ostream& out, const Player& player);

};

#endif /* Player_h */