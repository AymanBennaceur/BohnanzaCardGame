#include <iostream>

#include "Card.h"
#include "Deck.h"
#include "DiscardPile.h"
#include "Hand.h"


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
    std::ofstream output_file("save");
    std::ostream_iterator<Card*> output_iterator(output_file, "\n");
    std::copy(example.begin(), example.end(), output_iterator);
    
    }