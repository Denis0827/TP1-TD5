#include "Solution.h"
#include <iostream>
#include <tuple>
using namespace std;

Solution::Solution() {
    this->_itemsSol; // O(1)
    this->_cantidad_items; // O(1)
    this->_items; // O(1)
    this->_pesoTotal = 0; // O(1)
    this->_beneficioTotal = 0; // O(1)
}

void Solution::addItem(int item, int peso, int beneficio) {
    this->_itemsSol[item] = make_tuple(peso, beneficio); // O(1)
    this->_beneficioTotal += beneficio; // O(1)
    this->_pesoTotal += peso; // O(1)
    this->_items.push_back(item); // O(1)
    this->_cantidad_items += 1; // O(1)
}

void Solution::removeItem(int item) {
    int peso = get<0>(this->_itemsSol[item]); // O(1)
    int beneficio = get<1>(this->_itemsSol[item]); // O(1)
    this->_itemsSol.erase(item); // O(log(N)) con N = cantidad de items
    this->_pesoTotal -= peso; // O(1)
    this->_beneficioTotal -= beneficio; // O(1)
    this->_cantidad_items -= 1; // O(1)

    // Ver si puedo sacar este while
    auto it = this->_items.begin(); // O(1)
    while (it != this->_items.end()) { // O(N)
        if (*it == item) { // O(1)
            it = this->_items.erase(it); // O(1)
        } else {
            ++it; // O(1)
        }
    }
}

int Solution::getWeightSolution() const {
    return this->_pesoTotal; // O(1)
}

int Solution::getProfitSolution() const {
    return this->_beneficioTotal; // O(1)
}

vector<int> Solution::getItems() const {
    return this->_items; // O(1)
}

bool Solution::contains(int item) const {
    auto it = this->_itemsSol.find(item);  // O(log(N))
    return it != this->_itemsSol.end(); // O(1)
}

void Solution::printSolution() const {
    auto it_itemsSol = this->_itemsSol.begin(); // O(1)
    /*
    while (it_itemsSol != this->_itemsSol.end()) { // O(N)
        cout << "Item: " << it_itemsSol->first  // O(1)
             << ", Peso: " 
             << get<0>(it_itemsSol->second) << ", Beneficio: "  // O(1)
             << get<1>(it_itemsSol->second) << "." // O(1)
             << endl; // O(1)
        ++it_itemsSol; // O(1)    
    }
    */
    
    cout << this->_beneficioTotal << endl;
}