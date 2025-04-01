#include "Solution.h"
#include <iostream>
#include <tuple>
using namespace std;

Solution::Solution(int numItems) {
    this->_itemsSol;
    this->_cantidad_items = numItems;
    this->_items;
    this->_pesoTotal = 0;
    this->_beneficioTotal = 0;
}

void Solution::addItem(int item, int peso, int beneficio) {

    this->_itemsSol[item] = make_tuple(peso, beneficio);
    this->_beneficioTotal += beneficio;
    this->_pesoTotal += peso;
    this->_items.push_back(item);
}

void Solution::removeItem(int item) {
    int peso = get<0>(this->_itemsSol[item]);
    int beneficio = get<1>(this->_itemsSol[item]);
    this->_itemsSol.erase(item);
    this->_pesoTotal -= peso;
    this->_beneficioTotal -= beneficio;

    auto it = this->_items.begin();
    while (it != this->_items.end()) {
        if (*it == item) {
            it = this->_items.erase(it);
        } else {
            ++it;
        }
    }
}

int Solution::getWeightTotal() const {
    return this->_pesoTotal;
}

int Solution::getProfitTotal() const {
    return this->_beneficioTotal;
}

vector<int> Solution::getItems() const {
    return this->_items;
}

bool Solution::contains(int item) const {
    auto it = this->_itemsSol.find(item);
    return it != this->_itemsSol.end();
}

void Solution::printSolution() const {
    auto it_itemsSol = this->_itemsSol.begin();
    while (it_itemsSol != this->_itemsSol.end()) {
        cout << "Nodo: " << it_itemsSol->first 
             << ", Peso: " 
             << get<0>(it_itemsSol->second) << ", Beneficio: " 
             << get<1>(it_itemsSol->second) << "."
             << endl;
        ++it_itemsSol;
    }
}