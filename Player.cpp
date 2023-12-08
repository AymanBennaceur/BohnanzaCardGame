
#include "Player.h"
#include <iostream>
using namespace std;

//Constructeurs
Player::Player(string& name){
    playerName = name;

}

Player::Player(istream& in, CardFactory*){
//Idk how to implement this
}



//obtenir le nom du joueur
string Player::getName() const{
    return playerName;
}

//returns the number of coins held by the player
int Player::getNumCoins() const{
    return coins;
}

//ajoute un nombre de pièces
Player& Player::operator+=(int numCoins){
    if (numCoins>0) {
        coins += numCoins;
    }
    return *this;
}

//renvoie 2 ou 3, dependament du nombre de chains.
int Player::getMaxNumChains() const{
    return maxChains;
}

//renvoie le nombre de chaînes non nulles.
int Player::getNumChains() const{
    return numChains;
}

//renvoie la chaîne en position i.
Chain_Base& Player::operator[](int i){
    if (i < chain->size()) {
        return chain->at(i);
    }
    //en cas d'erreur, simplement retourner premier element..
    return chain->at(0);

}

//ajoute une troisième chaîne vide au joueur pour deux pièces
void Player::buyThirdChain(){
        if(coins < 2){
            //Si le joueur n'a pas suffisamment de pièces alors une exception NotEnoughCoins est soulevée
            throw new NotEnoughCoins;
        } else{
            maxChains++;
            coins = coins - 2;
        }
    }

//affiche la première carte de la main du joueur (avec l'argument False)
//affiche l'ensemble de la main du joueur (avec l'argument True)
//dans le flux correspondant ostream.
void Player::printHand(ostream& out, bool argument){
        if (argument) {
            // Print the entire hand
            for (const auto& card : hand) {
                out << card->getName() << " ";
            }
        } else {
            // Print only the first card
            out << hand.top()->getName();
        }
    }

//this prints the first desired line "Dave 3 coins"
//we need to print the rest (it says uses Hand so keeping as is for now until implemented)
ostream& operator<<(ostream& out, const Player& player){
    out << player.getName() << player.getNumCoins() << " coin"<< (player.coins > 1 ? "s" : "") << "\n";
    return out;
}