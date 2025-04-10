#include <tuple>
#include <string>
#include <iostream>
#include "Item.h"
using namespace std;

Item::Item(int numero, int weight, int profit) {
    this->_numero = numero;
    this->_peso = weight;
    this->_beneficio = profit;
}

int Item::getNumero() const {
    return this->_numero;
}

int Item::getWeight() const {
    return this->_peso;
}

int Item::getProfit() const {
    return this->_beneficio;
}