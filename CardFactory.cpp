#include "CardFactory.h"


CardFactory::CardFactory() {
    int i;
    for (i = 0; i<20; i++) {
        d.push_back(new Blue());
    }
    for (i = 0; i<18; i++) {
        d.push_back(new Chili());
    } 
    for (i = 0; i<16; i++) {
        d.push_back(new Stink());
    } 
    for (i = 0; i<14; i++) {
        d.push_back(new Green());
    } 
    for (i = 0; i<12; i++) {
        d.push_back(new soy());
    } 
    for (i = 0; i<10; i++) {
        d.push_back(new black());
    } 
    for (i = 0; i<8; i++) {
        d.push_back(new Red());
    } 
    for (i = 0; i<6; i++) {
        d.push_back(new garden());
    } 
}


static CardFactory* CardFatory::getFactory() {
    if(cf == nullptr) {
        cf = new CardFactory();
    }
    return cf;
}

Deck CardFatory::getDeck() {
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(d.begin(), d.end(), g);
    return d;
}

Deck CardFatory::getDeckFromSave(istream& is) {
    Deck df;
    is.seekg(0, is.end);
    int l = is.tellg()/2;
    is.seekg(0, is.beg);
    char c;
    for (int i = 0; i<l; i++) {
        is.seekg(2, is.cur);
        is.readsome(c, 1);
        if (c == "B") {
            df.push_back(new Blue());
        } else if (c == "C") {
            df.push_back(new Chili());
        } else if (c == "S") {
            df.push_back(new Stink());
        } else if (c == "G") {
            df.push_back(new Green());
        } else if (c == "s") {
            df.push_back(new soy());
        } else if (c == "b") {
            df.push_back(new black());
        } else if (c == "R") {
            df.push_back(new Red());
        } else if (c == "g") {
            df.push_back(new Green());
        } else {
            cout << "error reading save file, starting new game";
        }
    }
    return df;
}

Hand CardFatory::getHandFromSave(istream& is) {
    Hand h;
    is.seekg(0, is.end);
    int l = is.tellg()/2;
    is.seekg(0, is.beg);
    char c;
    for (int i = 0; i<l; i++) {
        is.seekg(2, is.cur);
        is.readsome(c, 1);
        if (c == "B") {
            h+=(new Blue());
        } else if (c == "C") {
            h+=(new Chili());
        } else if (c == "S") {
            h+=(new Stink());
        } else if (c == "G") {
            h+=(new Green());
        } else if (c == "s") {
            h+=(new soy());
        } else if (c == "b") {
            h+=(new black());
        } else if (c == "R") {
            h+=(new Red());
        } else if (c == "g") {
            h+=(new Green());
        } else {
            cout << "error reading save file, starting new game";
        }
    }
    return h;
}

DiscardPile CardFatory::getDiscardFromSave(istream& is) {
    DiscardPile dp;
    if(is) {
    is.seekg(0, is.end);
    int l = is.tellg()/2;
    is.seekg(0, is.beg);
    char c;
    for (int i = 0; i<l; i++) {
        is.seekg(2, is.cur);
        is.readsome(c, 1);
        if (c == "B") {
            dp.push_back(new Blue());
        } else if (c == "C") {
            dp.push_back(new Chili());
        } else if (c == "S") {
            dp.push_back(new Stink());
        } else if (c == "G") {
            dp.push_back(new Green());
        } else if (c == "s") {
            dp.push_back(new soy());
        } else if (c == "b") {
            dp.push_back(new black());
        } else if (c == "R") {
            dp.push_back(new Red());
        } else if (c == "g") {
            dp.push_back(new Green());
        } else {
            cout << "error reading save file, starting new game";
        }
    }
    }
    return dp;
}


