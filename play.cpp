#include <iostream>
#include <fstream>


#include "Card.h"
#include "Deck.h"
#include "DiscardPile.h"
#include "Hand.h"
#include "CardFactory.h"


using handType = Hand<Card, std::queue<Card*>>;

struct save {
    int size_deck;
    Deck deck;
    int size_disc;
    DiscardPile disc;
    handType hand1;
    handType hand2;
};

void saveGame(Deck* deck, DiscardPile* disc, handType* hand1, handType* hand2) {
    save game;
    game.size_deck = deck->size();
    game.deck = *deck;
    game.size_disc = disc->size();
    game.disc = *disc;
    game.hand1 = *hand1;
    game.hand2 = *hand2;

    std::ofstream save_file;
    save_file.open("save.bin");
    save_file.write((char*)&game, sizeof(game));
    save_file.close();

}

// void loadSavedGame(Deck* deck, DiscardPile* disc, handType* hand1, handType* hand2) {

// }

int main(){
    CardFactory* factory = CardFactory::getFactory();
    Deck* deck = (factory->getDeck());

    DiscardPile disc;
    disc += deck->draw();
    disc += deck->draw();
    disc += deck->draw();
    disc += deck->draw();

    handType h1;

    h1 += deck->draw();
    h1 += deck->draw();
    h1 += deck->draw();
    h1 += deck->draw();
    h1 += deck->draw();

    handType h2;

    h2 += deck->draw();
    h2 += deck->draw();
    h2 += deck->draw();
    h2 += deck->draw();
    h2 += deck->draw();

    saveGame(deck, &disc, &h1, &h2);

    return 0;
}