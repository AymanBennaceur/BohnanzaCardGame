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

class Blue : public Card {
    public:
        Blue() {
            name = "Blue";
            number_of_cards = 20;
            beanometer[0] = 4;
            beanometer[1] = 6;
            beanometer[2] = 8;
            beanometer[3] = 10;

        }
        int getCardsPerCoin(int coins) {
            return beanometer[coins-1];
        }
        string getName() {
            return name;
        }
        void print(ostream& os) {
            os << name[0];
        }
};

class Chili : public Card {
    public:
        Chili() {
            name = "Chili";
            number_of_cards = 18;
            beanometer[0] = 3;
            beanometer[1] = 6;
            beanometer[2] = 8;
            beanometer[3] = 9;

        }
        int getCardsPerCoin(int coins) {
            return beanometer[coins-1];
        }
        string getName() {
            return name;
        }
        void print(ostream& os) {
            os << name[0];
        }
};

class Stink : public Card {
    public:
        Stink() {
            name = "Stink";
            number_of_cards = 16;
            beanometer[0] = 3;
            beanometer[1] = 5;
            beanometer[2] = 7;
            beanometer[3] = 8;

        }
        int getCardsPerCoin(int coins) {
            return beanometer[coins-1];
        }
        string getName() {
            return name;
        }
        void print(ostream& os) {
            os << name[0];
        }
};

class Green : public Card {
    public:
        Green() {
            name = "Green";
            number_of_cards = 14;
            beanometer[0] = 3;
            beanometer[1] = 5;
            beanometer[2] = 6;
            beanometer[3] = 7;

        }
        int getCardsPerCoin(int coins) {
            return beanometer[coins-1];
        }
        string getName() {
            return name;
        }
        void print(ostream& os) {
            os << name[0];
        }
};

class soy : public Card {
    public:
        soy() {
            name = "soy";
            number_of_cards = 12;
            beanometer[0] = 2;
            beanometer[1] = 4;
            beanometer[2] = 6;
            beanometer[3] = 7;

        }
        int getCardsPerCoin(int coins) {
            return beanometer[coins-1];
        }
        string getName() {
            return name;
        }
        void print(ostream& os) {
            os << name[0];
        }
};

class black : public Card {
    public:
        black() {
            name = "black";
            number_of_cards = 10;
            beanometer[0] = 2;
            beanometer[1] = 4;
            beanometer[2] = 5;
            beanometer[3] = 6;

        }
        int getCardsPerCoin(int coins) {
            return beanometer[coins-1];
        }
        string getName() {
            return name;
        }
        void print(ostream& os) {
            os << name[0];
        }
};

class Red : public Card {
    public:
        Red() {
            name = "Red";
            number_of_cards = 8;
            beanometer[0] = 2;
            beanometer[1] = 3;
            beanometer[2] = 4;
            beanometer[3] = 5;

        }
        int getCardsPerCoin(int coins) {
            return beanometer[coins-1];
        }
        string getName() {
            return name;
        }
        void print(ostream& os) {
            os << name[0];
        }
};

class garden : public Card {
    public:
        garden() {
            name = "garden";
            number_of_cards = 6;
            beanometer[0] = 0;
            beanometer[1] = 2;
            beanometer[2] = 3;
            beanometer[3] = 0;

        }
        int getCardsPerCoin(int coins) {
            return beanometer[coins-1];
        }
        string getName() {
            return name;
        }
        void print(ostream& os) {
            os << name[0];
        }
};