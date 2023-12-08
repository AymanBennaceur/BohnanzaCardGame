#include <iostream>
#include <fstream>


#include "Card.h"
#include "Deck.h"
#include "DiscardPile.h"
#include "Hand.h"
#include "CardFactory.h"


struct game {
    Deck* deck;
    DiscardPile* dpile;
    Hand* h1;
    Hand* h2;
};

void saveGame(Deck* deck, DiscardPile* disc, Hand* hand1, Hand* hand2) {
    std::ofstream save_file;
    save_file.open("save.txt");

    save_file << *deck << "\n";
    save_file << *disc << "\n";
    save_file << *hand1 << "\n";
    save_file << *hand2 << "\n";

    save_file.close();

}

game loadSavedGame(CardFactory* cf) {
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
    game g;
    
    is.str(deck_string);
    g.deck = new Deck((std::istream&)is, cf);

    is.str(disc_string);
    g.dpile = new DiscardPile((std::istream&)is, cf);

    is.str(h1_string);
    g.h1 = new Hand((std::istream&)is, cf);

    is.str(h2_string);
    g.h2 = new Hand((std::istream&)is, cf);

}

int main(){
    CardFactory* factory = CardFactory::getFactory();

    Deck *deck = new Deck();

    DiscardPile dpile;
    dpile += deck->draw();
    dpile += deck->draw();
    dpile += deck->draw();
    dpile += deck->draw();

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

    saveGame(deck, &dpile, &h1, &h2);

    Deck* deck2;
    DiscardPile* disc2;
    Hand* hand12;
    Hand* hand22;

    game g = loadSavedGame(factory);

    // std::cout << g.deck << "\n";
    // std::cout << *disc2 << "\n";
    // std::cout << *hand12 << "\n";
    // std::cout << *hand22 << "\n";

    return 0;
}