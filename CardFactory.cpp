#include "CardFactory.h"
CardFactory* CardFactory::cf = 0;

Deck* CardFactory::getDeck() {
    Deck* d;


    d->push_back(new Blue());
    d->push_back(new Blue());
    d->push_back(new Blue());
    d->push_back(new Blue());
    d->push_back(new Blue());
    d->push_back(new Blue());
    d->push_back(new Blue());
    d->push_back(new Blue());
    d->push_back(new Blue());
    d->push_back(new Blue());
    d->push_back(new Blue());
    d->push_back(new Blue());


    std::cout<<"made it here";


    // for (int i = 0; i<20; i++) {
    //     d->push_back(new Blue());
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
    // std::random_device rd;
    // std::mt19937 g(rd());
    // std::shuffle(d->begin(), d->end(), g);
    return d;
}

CardFactory* CardFactory::getFactory() {
    
    if(cf == nullptr) {
        cf = new CardFactory();
    }
    return cf;
}
