#include <iostream>

#include "Card.h"
#include "Deck.h"
#include "DiscardPile.h"
#include "Hand.h"

// struct save {
//     Deck d;
//     DiscardPile dis;
//     Hand hand1;
//     Hand hand2;
// }


/*
Save file structure:

start --
size_of_deck
deck vector

size_of_discard
discard vector

hand 1 list

hand 2 list
end --
*/

void saveGame(Deck* deck, DiscardPile* disc, Hand* hand1, Hand* hand2) {
    // std::ofstream output_file("save");
    // output_file << deck.size() << "\n";

    // std::ostream_iterator<Card*> output_iterator(output_file, "\n");
    // std::copy(deck.begin(), deck.end(), output_iterator);
    
    }