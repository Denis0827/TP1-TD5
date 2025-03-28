#include "Solution.h"

Solution::Solution(int numItems) {
    this->_itemsSol;
    this->_cantidad_items = numItems;
}

void Solution::addItem(int item, int peso, int beneficio) {
    this->_itemsSol[item] = tuple(peso, beneficio);
}

void Solution::removeItem(int item) {
    this->_itemsSol.erase(item);
}

bool Solution::contains(int item) const {
    return this->_itemsSol.find(item);
}

void Solution::printSolution() const {

}

