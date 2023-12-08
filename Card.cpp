#include "Card.h"

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
        int getMaxCards() {
            return number_of_cards;
        }

        int getCardsPerCoin(int coins) {
            return beanometer[coins-1];
        }
        std::string getName() {
            return name;
        }
        void print(std::ostream& os) {
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
        int getMaxCards() {
            return number_of_cards;
        }

        int getCardsPerCoin(int coins) {
            return beanometer[coins-1];
        }
        std::string getName() {
            return name;
        }
        void print(std::ostream& os) {
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

        int getMaxCards() {
            return number_of_cards;
        }

        int getCardsPerCoin(int coins) {
            return beanometer[coins-1];
        }
        std::string getName() {
            return name;
        }
        void print(std::ostream& os) {
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

        int getMaxCards() {
            return number_of_cards;
        }

        int getCardsPerCoin(int coins) {
            return beanometer[coins-1];
        }
        std::string getName() {
            return name;
        }
        void print(std::ostream& os) {
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

        int getMaxCards() {
            return number_of_cards;
        }

        int getCardsPerCoin(int coins) {
            return beanometer[coins-1];
        }
        std::string getName() {
            return name;
        }
        void print(std::ostream& os) {
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

        int getMaxCards() {
            return number_of_cards;
        }

        int getCardsPerCoin(int coins) {
            return beanometer[coins-1];
        }
        std::string getName() {
            return name;
        }
        void print(std::ostream& os) {
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

        int getMaxCards() {
            return number_of_cards;
        }

        int getCardsPerCoin(int coins) {
            return beanometer[coins-1];
        }
        std::string getName() {
            return name;
        }
        void print(std::ostream& os) {
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
        
        int getMaxCards() {
            return number_of_cards;
        }

        int getCardsPerCoin(int coins) {
            return beanometer[coins-1];
        }
        std::string getName() {
            return name;
        }
        void print(std::ostream& os) {
            os << name[0];
        }
};