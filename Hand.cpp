#include "Hand.h"

Card* Hand::play() {
    Card* c = front();
    erase(begin());
    return c;
}

Card* Hand::top() {
    return front();
}

Card* Hand::operator[](int i) {
    Card* c = at(i-1);
    erase(begin()+i-1);
    return c;
}

Hand& Hand::operator+=(Card* c) {
    push_back(c);
    Hand* h = this;
    return *h;
}
