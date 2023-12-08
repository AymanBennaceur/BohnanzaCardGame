#include "CardFactory.h"
CardFactory* CardFactory::cf = 0;

// Deck* CardFactory::getDeck() {
//     Deck* d;
//     d->reserve(104);

    // for (int i = 0; i<20; i++) {
    //     std::cout<<"  here " << i;

    //     d->add(new Blue());
    // }
    // for (i = 0; i<18; i++) {
    //     d->push_back(new Chili());
    // } 
    // for (i = 0; i<16; i++) {
    //     d->push_back(new Stink());
    // } 
    // for (i = 0; i<14; i++) {
    //     d->push_back(new Green());
    // } 
    // for (i = 0; i<12; i++) {
    //     d->push_back(new soy());
    // } 
    // for (i = 0; i<10; i++) {
    //     d->push_back(new black());
    // } 
    // for (i = 0; i<8; i++) {
    //     d->push_back(new Red());
    // } 
    // for (i = 0; i<6; i++) {
    //     d->push_back(new garden());
    // } 
//     std::random_device rd;
//     std::mt19937 g(rd());
//     std::shuffle(d->begin(), d->end(), g);
//     return d;
// }


Card* CardFactory::getCard(char c) {
    if (c == 'B') {
        return (new Blue());
    } else if (c == 'C') {
        return new Chili();
    } else if (c == 'S') {
        return new Stink();
    } else if (c == 'G') {
        return new Green();
    } else if (c == 's') {
        return new soy();
    } else if (c == 'b') {
        return new black();
    } else if (c == 'R') {
        return new Red();
    } else if (c == 'g') {
        return new Green();
    } else {
        std::cout << "error getting card, starting new game";
    }
}


CardFactory* CardFactory::getFactory() {
    
    if(cf == nullptr) {
        cf = new CardFactory();
    }
    return cf;
}

