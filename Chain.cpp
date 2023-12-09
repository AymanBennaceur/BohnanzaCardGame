// using namespace std;


#include "Chain.h"

//Exception
class IllegalTypeException : public std::invalid_argument {
public:
    IllegalTypeException() : std::invalid_argument("IllegalTypeException: Runtime type does not match the template type of the chain.") {}
};

//constructor
template<typename T>
Chain<T>::Chain(Card *card)
{
    cards.push_back(card);
}


//ajoute une carte à Chain. Si le type du temps d’exécution ne correspond pas au type patron de la chaîne
template<typename T>
Chain<T>& Chain<T>::operator+=(T card) {
    // fix this
    if (typeid(card) == typeid(cards.front())) {
        throw new IllegalTypeException();
    }
    else {
        cards.push_back(card);
    }
    return *this;
}

template<typename T>
bool Chain<T>::isCorrectType(std::string other) {
    return other.compare(chainType) == 0;
}


template<typename T>
std::vector<T> Chain<T>::getChain() {
        return cards;
    }

//compte le nombre de cartes dans la chaîne courante et renvoie le nombre de pièces
template<typename T>
int Chain<T>::sell() {
    T card;
    int nbrCarte = card->getCardsPerCoin(cards.size());
    return nbrCarte;
}


// Ajouter un opérateur d’insertion pour afficher Chain
// template<typename T>
// std::ostream& Chain<T>::operator<<(std::ostream& os, Chain<T>& chain) {
//     // os << (chain.getChain())[0]->getName() << "   ";
//     for (int x = 0; x < int(chain.getChain().size());x++) {
//             chain.cards.at(x)->print(os);
//         }
//         return os;
//     return os;
// }





