#include <iostream>
#include <fstream>
#include <string.h>



// #include "Card.h"
// #include "Deck.h"
// #include "DiscardPile.h"
// #include "Hand.h"
#include "CardFactory.h"
// #include "Player.h"
#include "Table.h"
// #include "TradeArea.h"

struct game {
    Deck* deck;
    DiscardPile* dpile;
    Hand* h1;
    Hand* h2;
};

void save(Table&table) {
    std::ofstream save_file;
    save_file.open("save.txt");

    save_file << *table.deck<< "\n";
    save_file << table.player1 << "\n";
    save_file << table.player2 << "\n";
    save_file << *table.tradeArea << "\n";
    save_file << *table.discardPile << "\n";

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



void play(Table t) {
    int turn = 0; // 0 for player 1, 1 for player 2
    Player* players[] = {t.getP1(), t.getP2()};
    while(t.getDeck()->size()>0) {
        std::string choice;
        std::cout << "Pause? (y/n): ";
        std::cin >> choice;
        if (choice.compare("y") == 0) {
            save(t);
            exit(0);
        } else {
            std::cout << "------ Table -------\n" << t << "------ End table -------\n" ;
            std::cout << players[turn]->getName() << "'s turn\n";
            *(players[turn]->getHand()) += t.getDeck()->draw();
            if(!t.getTradeArea()->numCards() == 0) {
                std::cout << "impletemnt trade area";
                //add bean cards from trade area to chains or discard
            }
            Card* c = players[turn]->getHand()->play();
            std::cout << "Card to play: " << *c << "\n";

            // if chain exist, add card to chain

            // else make a new chain and add to player

            // if out of chain space add to trade area


            std::cout << "Current chains: \n";
                for (int i=0; i<players[turn]->getNumChains();i++) {
                    std::cout << players[turn][i];
                }
            
            break;
            turn = !turn;
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
        p1.setHand(&h1);
        p1.setHand(&h2);

        TradeArea trade;

        Table t(&p1, &p2, deck, &dpile, &trade);

        play(t);

    } else {
        // there is something wrong with this where i cant access the elements idk
        game g = loadSavedGame(factory);
    }

    





   


    return 0;
}