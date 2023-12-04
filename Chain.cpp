#ifndef chain_h
#define chain_h

#include <string>
#include <vector>
#include "Card.h"
#include "cardfactory.h"
#include <iostream>
#include <typeinfo>
using namespace std;

class IllegalTypeException : public invalid_argument {
public:
    IllegalTypeException() : invalid_argument("IllegalTypeException: Runtime type does not match the template type of the chain.") {}
};

class IllegalType : public exception
{
    virtual const char* what() const throw()
    {
        return "Wrong type of card for this chain.";
    }
};

class Chain_Base {
protected:
    string beanType;

public:
    Chain_Base(string bean) : beanType(bean) {};
    virtual ~Chain_Base() = default;
    virtual int sell() = 0;
    string getBeanType() {
        return beanType;
    }
    virtual void print(std::ostream&) const = 0;

    friend ostream& operator<<(ostream& out, Chain_Base& chain) {
        out << chain.getBeanType() << "\t";
        chain.print(out);
        return out;
    };
};

template<class T> class Chain : public Chain_Base {
    std::vector<T*> chain_byType;

public:
    Chain() {}

    virtual ~Chain() {
        chain_byType.clear();
    }

    virtual Chain<T>& operator+=(T* gem) {
        //not sure about this
        if (typeid(*gem) != typeid(T)) {
            throw IllegalTypeException();
        }

        chain_byType.push_back(gem);
        return *this;
    }

    virtual int sell() override {
        int numCards = static_cast<int>(chain_byType.size());
        return chain_byType.at(0)->getCoinsPerCard(numCards);
    }

    virtual void print(std::ostream& o) const override {
        o << getBeanType() << " ";
        for (auto& c : chain_byType) {
            c->print(o);
            o << " ";
        }
    }
};

#endif /* chain_h */
