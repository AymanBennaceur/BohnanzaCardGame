#include <iostream>
#include <fstream>


#include "Card.h"
#include "Deck.h"
#include "DiscardPile.h"
#include "Hand.h"
#include "CardFactory.h"


struct header {
    int size_deck;
    int size_disc;
    int size_hand1;
    int size_hand2;
};


void saveGame(Deck* deck, DiscardPile* disc, Hand* hand1, Hand* hand2) {
    header game_params;
    game_params.size_deck = deck->size();
    game_params.size_disc = disc->size();
    game_params.size_hand1 = hand1->size();
    game_params.size_hand2 = hand2->size();

    

    std::ofstream save_file;
    save_file.open("save.txt");
    save_file << *deck;
    save_file << *disc;
    save_file << *hand1;
    save_file << *hand2;

    save_file.close();

}

void loadSavedGame(Deck* deck, DiscardPile* disc, Hand* hand1, Hand* hand2) {
    header game_params;
    std::ifstream save_file;
    save_file.open("save.bin");
    save_file.read((char*)&game_params.size_deck, sizeof(game_params.size_deck));
    save_file.read((char*)&game_params.size_disc, sizeof(game_params.size_disc));
    save_file.read((char*)&game_params.size_hand1, sizeof(game_params.size_hand1));
    save_file.read((char*)&game_params.size_hand2, sizeof(game_params.size_hand2));

    std::cout << game_params.size_deck;
    // data game;
    // save_file.read((char*)&game.deck, (int)game_params.size_deck);
    // save_file.read((char*)&game.disc, (int)game_params.size_disc);
    // save_file.read((char*)&game.hand1, (int)game_params.size_hand1);
    // save_file.read((char*)&game.hand2, (int)game_params.size_hand2);

    // const Deck deck2 = (Deck)game.deck;
    // std::cout << deck2;
    
}

int main(){
    CardFactory* factory = CardFactory::getFactory();


    Deck* deck = (factory->getDeck());

    DiscardPile disc;
    disc += deck->draw();
    disc += deck->draw();
    disc += deck->draw();
    disc += deck->draw();

    Hand h1;

    h1 += deck->draw();
    h1 += deck->draw();
    h1 += deck->draw();
    h1 += deck->draw();
    h1 += deck->draw();

    Hand h2;

    h2 += deck->draw();
    h2 += deck->draw();
    h2 += deck->draw();
    h2 += deck->draw();
    h2 += deck->draw();

    // std::cout<<"Made it here";

    saveGame(deck, &disc, &h1, &h2);

    Deck* deck2;
    DiscardPile* disc2;
    Hand* hand12;
    Hand* hand22;


    loadSavedGame(deck2, disc2, hand12, hand22);


    return 0;
}