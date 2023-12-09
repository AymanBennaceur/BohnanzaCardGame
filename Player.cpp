
#include "Player.h"
#include <iostream>
// using namespace std;

//Constructeurs
Player::Player(std::string& name){
    playerName = name;
    numChains = chain.size();
    maxChains = 2;
    coins = 0;
}
Player::Player(std::istream& in, CardFactory* cf){
    std::getline(in, playerName);

    in >> numChains >> maxChains;
    hand = new Hand(in, cf);

    // Read and initialize chains
    char cardType;
    while (in.get(cardType)) {
        if (cardType != ' ' && cardType != '\n') {
            hand->push_back(cf->getCard(cardType));
        }
    }

    numChains = 0;
    maxChains = 2;
    coins = 0;
}

void Player::setHand(Hand* h) {
    hand = h;
}

Hand* Player::getHand() {
    return hand;
}

//obtenir le nom du joueur
std::string Player::getName() const{
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

void Player::addChain(Chain<Card*>* c) {
    chain.push_back(c);
    numChains++;
}


//renvoie 2 ou 3, dependament du nombre de chains.
int Player::getMaxNumChains() const {
    return maxChains;
}

//renvoie le nombre de chaînes non nulles.
int Player::getNumChains() const{
    return numChains;
}

//renvoie la chaîne en position i.
Chain<Card*>* Player::operator[](int i){
    if (i < chain.size()) {
        return chain.at(i);
    }
    //en cas d'erreur, simplement retourner premier element..
    return chain.at(0);

}

std::vector<Chain<Card*>*> Player::getChains() {
    return chain;
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
void Player::printHand(std::ostream& out, bool argument){
        if (argument) {
            // Print the entire hand
            for (const auto& card : *hand) {
                out << card->getName() << " ";
            }
        } else {
            // Print only the first card
            out << hand->top()->getName();
        }
    }

//this prints the first desired line "Dave 3 coins"
//we need to print the rest (it says uses Hand so keeping as is for now until implemented)
std::ostream& operator<<(std::ostream& out, const Player& player){
    out << player.getName() << " has  " << player.getNumCoins() << " coin"<< (player.coins == 1 ? "" : "s") << "\n";
    return out;
}