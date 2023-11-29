#include <string>
#include <iostream>
using namespace std;

class Card {
    protected:
        string name;
        int number_of_cards;
        int beanometer[4];
    public:
        virtual int getCardsPerCoin(int) =0;
        virtual string getName() = 0;
        virtual void print(ostream&) = 0;
        friend ostream & operator << (ostream &out, const Card &c){
            out << c.name[0];
            return out;
        }
        // friend istream & operator >> (istream &in, Card &c) {
        //     string name;
        //     cout << "Enter card name: ";
        //     in >> name;
        //     if(!name.compare("Blue")) {
        //         c = Blue();
        //     } else if (!name.compare("Chili")) {
        //         c = Chili();
        //     } else if (!name.compare("Stink")) {
        //         c = Stink();
        //     } else if (!name.compare("Green")) {
        //         c = Green();
        //     } else if (!name.compare("soy")) {
        //         c = soy();
        //     } else if (!name.compare("black")) {
        //         c = black();
        //     } else if (!name.compare("Red")) {
        //         c = Red();
        //     } else if (!name.compare("garden")) {
        //         c = garden();
        //     }
        //     return in;
        // }
};

