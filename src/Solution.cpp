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
    auto it_itemsSol = this->_itemsSol.begin();
    while (it_itemsSol != this->_itemsSol.end()) {
        cout << "Nodo: " << it_itemsSol.first 
             << ", Peso: " 
             << get<0>(it_itemsSol.second) << ", Beneficio: " 
             << get<1>(it_itemsSol.second) << "."
             << endl;
        ++it_itemsSol;
    }
}

