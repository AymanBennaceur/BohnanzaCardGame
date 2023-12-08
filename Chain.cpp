#include <vector>
#include "Card.h"
#include <iostream>
// using namespace std;


#include "Chain.h"

//Exception
class IllegalTypeException : public std::invalid_argument {
public:
    IllegalTypeException() : std::invalid_argument("IllegalTypeException: Runtime type does not match the template type of the chain.") {}
};

//ajoute une carte à Chain. Si le type du temps d’exécution ne correspond pas au type patron de la chaîne
template<typename T>
Chain<T>& Chain<T>::operator+=(T card) {
    if (typeid(card) != typeid(cards.front())) {
        throw new IllegalTypeException();
    }
    else {
        cards.push_back(card);
    }
    return *this;
}

template<typename T>
std::vector<T> Chain<T>::getChain() {
        return &cards;
    }

//compte le nombre de cartes dans la chaîne courante et renvoie le nombre de pièces
template<typename T>
int Chain<T>::sell() {
    int nbrCarte = getCardsPerCoin(cards.size());
    return nbrCarte;
}

//Ajouter un opérateur d’insertion pour afficher Chain
template<typename T>
std::ostream& operator <<(std::ostream& os, Chain<Card*>& chain) {
    os << (chain.getChain())[0]->getName() << "   ";
    for (int x = 0; x < int(chain.getChain().size());x++) {
        (chain.getChain())[x]->print(os);
    }
    return os;
}





