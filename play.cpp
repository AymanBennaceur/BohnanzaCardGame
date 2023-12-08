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

void loadSavedGame(Deck* deck, DiscardPile* disc, Hand* hand1, Hand* hand2, CardFactory* cf) {
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
    save_file.close();

    std::istringstream is;
    
    is.str(deck_string);
    deck = new Deck((std::istream&)is, cf);

    is.str(disc_string);
    disc = new DiscardPile((std::istream&)is, cf);

    is.str(h1_string);
    hand1 = new Hand((std::istream&)is, cf);

    is.str(h2_string);
    hand2 = new Hand((std::istream&)is, cf);
    
}

int main(){
    CardFactory* factory = CardFactory::getFactory();

    Deck *deck = new Deck();

    std::cout << *deck;


    // DiscardPile disc;
    // disc += deck->draw();
    // disc += deck->draw();
    // disc += deck->draw();
    // disc += deck->draw();

    // Hand h1;

    // h1 += deck->draw();
    // h1 += deck->draw();
    // h1 += deck->draw();
    // h1 += deck->draw();
    // h1 += deck->draw();

    // Hand h2;

    // h2 += deck->draw();
    // h2 += deck->draw();
    // h2 += deck->draw();
    // h2 += deck->draw();
    // h2 += deck->draw();

    // saveGame(deck, &disc, &h1, &h2);

    // Deck* deck2;
    // DiscardPile* disc2;
    // Hand* hand12;
    // Hand* hand22;


    // loadSavedGame(deck2, disc2, hand12, hand22, factory);

    // std::cout << deck2;
    // std::cout << disc2;
    // std::cout << hand12;
    // std::cout << hand22;

    return 0;
}