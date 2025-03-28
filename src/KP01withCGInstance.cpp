#include "KP01withCGInstance.h"

void construir_arbol(vector<int> solucion_parcial, int n, int k) {
    if (k == n) {
        this->_arbol.append(actual);
    } else {
        construir_arbol(solucion_parcial, n, k + 1);
        solucion_parcial.push_back(k); // agrego el elemento k-esimo del conjunto
        construir_arbol(solucion_parcial, n, k + 1);
    }
}


KP01withCGInstance::KP01withCGInstance(int n, int cap) {
    this->_capacidad = cap;
    this->_cantidad_items = n;

    this->_items; // preguntar
    for (int i = 0; i < n; i++) {
        this->_items[i] = tuple(0, 0);
    }

    this->_arbol; // preguntar
    construir_arbol([], n, 0);

    this->_conflictos(n, vector<bool>(n, false));
}

void KP01withCGInstance::setWeight(int index, int weight) {
    this->_items[index][0] = weight;
}

void KP01withCGInstance::setProfit(int index, int profit) {
    this->_items[index][1] = profit;
}

int KP01withCGInstance::getWeight(int index) const {
    return get<0>(this->_items[index]);
}

int KP01withCGInstance::getProfit(int index) const {
    return get<1>(this->_items[index]);
}

int KP01withCGInstance::getNumItems() const {
    return this->_cantidad_items;
}

int KP01withCGInstance::getCapacity() const {
    return this->_capacidad;
}

void KP01withCGInstance::addConflict(int item1, int item2) {
    this->_conflictos[item1][item2] = true;
    this->_conflictos[item1][item2] = true;
}

void KP01withCGInstance::removeConflict(int item1, int item2) {
    this->_conflictos[item1][item2] = false;
    this->_conflictos[item1][item2] = false;
}

KP01withCGInstance::KP01withCGInstance cargar_datos(const string& archivo) {
    
}
