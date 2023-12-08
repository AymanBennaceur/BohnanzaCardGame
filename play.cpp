#include <iostream>
#include <fstream>
#include <string.h>



#include "Card.h"
#include "Deck.h"
#include "DiscardPile.h"
#include "Hand.h"
#include "CardFactory.h"
#include "Player.h"
#include "Table.h"

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

void play(Deck* deck, DiscardPile dpile, Player p1, Player p2, Hand h1, Hand h2) {
    int turn = 0; // 0 for player 1, 1 for player 2
    Player players[] = {p1, p2};
    while(deck->size()>0) {
        std::string choice;
        std::cout << "Pause? (y/n): ";
        std::cin >> choice;
        if (choice.compare("y") != 0) {
            saveGame(deck, &dpile, &h1, &h2);
            exit(0);
        } else {
            // i have no idea how to display the table
            players[turn].draw()
        }
    }
    
    

}

int main(){
    CardFactory* factory = CardFactory::getFactory();
    std::string choice;

    std::cout << "Welcome to Bohnanza!\n";
    std::cout << "Start a new game or continue? (new|continue): ";
    std::cin >> choice;

    if (choice.compare("continue") != 0) {
        std::string p1_name;
        std::string p2_name;
        std::cout << "\nEnter the name for player 1: ";
        std::cin >> p1_name;
        std::cout << "\nEnter the name for player 2: ";
        std::cin >> p2_name;

        Player p1(p1_name);
        Player p2(p2_name);

        Deck *deck = new Deck();
        DiscardPile dpile;

        Hand h1;
        Hand h2;

        for (int i=0; i<5; i++) {
            h1 += deck->draw();
            h2 += deck->draw();
        }

        play(deck, dpile, h1, h2);

    } else {
        // there is something wrong with this where i cant access the elements idk
        game g = loadSavedGame(factory);
    }

    





   


    return 0;
}