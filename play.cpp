#include <iostream>
#include <fstream>


#include "Card.h"
#include "Deck.h"
#include "DiscardPile.h"
#include "Hand.h"
#include "CardFactory.h"


void saveGame(Deck* deck, DiscardPile* disc, Hand* hand1, Hand* hand2) {
    std::ofstream save_file;
    save_file.open("save.txt");

    save_file << *deck << "\n";
    save_file << *disc << "\n";
    save_file << *hand1 << "\n";
    save_file << *hand2 << "\n";

    save_file.close();

}

void loadSavedGame(Deck* deck, DiscardPile* disc, Hand* hand1, Hand* hand2) {
    std::ifstream save_file;
    save_file.open("save.txt");

    char deck_string[105];
    char disc_string[105];
    char h1_string[6];
    char h2_string[6];

    save_file >> deck_string;
    save_file >> disc_string;
    save_file >> h1_string;
    save_file >> h2_string;

    std::cout << deck_string << "\n";
    std::cout << disc_string << "\n";
    std::cout << h1_string << "\n";
    std::cout << h2_string << "\n";

    save_file.close();
    
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

    saveGame(deck, &disc, &h1, &h2);

    Deck* deck2;
    DiscardPile* disc2;
    Hand* hand12;
    Hand* hand22;


    loadSavedGame(deck2, disc2, hand12, hand22);


    return 0;
}