#include <iostream>
#include <fstream>
#include <string.h>
#include <typeinfo>


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



void play(Table t, CardFactory* cf) {
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
                // TODO
            }
            Card* c = players[turn]->getHand()->play();
            std::cout << "Card to play: " << *c << "\n";

            if (players[turn]->getNumChains() == 0) {
                std::cout << "No chains to display.\n" ;
            } else {
                std::string choice = "yes";
                while(choice.compare("no")!= 0) {
                    std::cout << "Current chains: \n";
                    for (int i=0; i<players[turn]->getNumChains();i++) {
                        std::cout << players[turn][i];
                    }
                    std::cout << "Cash in chain? (1|2|3|no)";
                    std::cin >> choice;
                    if (choice.compare("1") == 0) {
                        // TODO CASH IN CHAIN 1
                    } else if (choice.compare("2") == 0) {
                        // cash in second chain
                    } else if (choice.compare("3") == 0) {
                        // check if third chain exists and cash in
                    } 
                }
                
            }
            

            // a chain of same type exists
            bool played = 0;
            for (int i =0; i<players[turn]->getNumChains(); i++) {
                if((*players[turn])[i]->isCorrectType(c->getName())) {
                    std::string choice;
                    std::cout << "Chain available, add card to chain? (y/n)";
                    std::cin >> choice;
                    if (choice.compare("y")==0) {
                        std::cout << "\nAdded card to chain\n";
                        (*(*players[turn])[i])+=c;
                        played = 1;
                        break;
                    } else {
                        break;
                    }
                }
            }

            // chain of same type does not exist but there is room
            if (!played && players[turn]->getNumChains() < players[turn]->getMaxNumChains()) {
                std::string choice;
                std::cout << "\nNo current chains found start a new one? (y/n)";
                std::cin >> choice;
                if (choice.compare("y") == 0) {
                    Chain<typeof(c)> chain(c);
                    players[turn]->addChain(&chain);
                    played = 1;
                }
            } else {
                std::cout << "No current chains found and out of chain slots";


            }

            std::cout << "\nCurrent chains: \n";
            for (int i=0; i<players[turn]->getNumChains();i++) {
                std::cout << players[turn][i] << "\n";
            }
            // ask the player if they want to cash in chanins again
            std::string choice = "yes";
            while(choice.compare("no")!= 0) {
                std::cout << "Current chains: \n";
                for (int i=0; i<players[turn]->getNumChains();i++) {
                    std::cout << players[turn][i];
                }
                std::cout << "Cash in chain? (1|2|3|no)";
                std::cin >> choice;
                if (choice.compare("1") == 0) {
                    // CASH IN CHAIN 1
                } else if (choice.compare("2") == 0) {
                    // cash in second chain
                } else if (choice.compare("3") == 0) {
                    // check if third chain exists and cash in
                } 
            }
        
            std::cout<< "\n Reveal hand and discard a card?";
            std::cin >> choice;

            if (choice.compare("yes") == 0) {
                int i;
                while (1) {
                    std::cout << *(players[turn]->getHand());
                    std::cout << "\nWhich card would you like to select? (1|2|3|4|5)";
                    std::cin >> i;

                    if(i <= 5) {
                        Card* c = (*players[turn]->getHand())[i];
                        std::cout << "Discarding card: " << c->getName();
                        *t.discardPile += c;
                    }

                }
            }

            // draw 3 cards from deck and place in trading area
            std::cout << "\nDrawing 3 cards from the deck and placing in trade area\n";
            *t.tradeArea += t.deck->draw();
            *t.tradeArea += t.deck->draw();
            *t.tradeArea += t.deck->draw();
            std::cout << "Trade area: " << *t.tradeArea;

            while(t.tradeArea->legal(t.discardPile->top())) {
                std::cout<< "\nPlacing card in trade area: " << *t.discardPile->top();
                *t.tradeArea += t.discardPile->pickUp();
            }     

            std::cout << "\nTrade area: " << *t.tradeArea;


            for (int i=0; i<t.tradeArea->numCards(); i++) {
                std::string choice;
                std::list<Card*>::const_iterator it = (t.tradeArea->getTraded()).begin();
                std::advance(it, i);
                Card *c = *it;

                std::cout << "Would you like to chain the following card? (y/n): " << *c;

                if (choice.compare("y")==0) {

                    bool played = 0;
                    for (int i =0; i<players[turn]->getNumChains(); i++) {
                        if((*players[turn])[i]->isCorrectType(c->getName())) {
                            std::string choice;
                            std::cout << "Chain available, adding to chain";
                            (*(*players[turn])[i])+=c;
                            played = 1;
                            break;
                        }
                    }
                    if(!played) {
                        //TODO create a new chain or option to buy chain
                        std::cout << "Could not find chain";
                    }

                }
            }

            while (players[turn]->getHand()->size() < 5) {
                *(players[turn]->getHand()) += t.getDeck()->draw();

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

        play(t, factory);

    } else {
        // there is something wrong with this where i cant access the elements idk
        game g = loadSavedGame(factory);
    }

    





   


    return 0;
}