// Graph.cpp
#include "Graph.h"
#include <vector>
using namespace std;

Graph::Graph() {
    this->_conflictos = vector<vector<bool>>(); // O(1)
    this->_cantidad_conflictos = 0; // O(1)
}

void Graph::construirMatriz(int cantidad_items) {
    this->_conflictos = vector<vector<bool>>(cantidad_items, vector<bool>(cantidad_items, false)); // O(N^2)
}

vector<vector<bool>> Graph::getMatriz() const{
    return this->_conflictos; // O(1)
}

void Graph::addConflict(int item1, int item2) {
    this->_conflictos[item1][item2] = true; // O(1)
    this->_conflictos[item2][item1] = true; // O(1)
    this->_cantidad_conflictos++; // O(1)
}

void Graph::removeConflict(int item1, int item2) {
    this->_conflictos[item1][item2] = false; // O(1)
    this->_conflictos[item2][item1] = false; // O(1)
    this->_cantidad_conflictos--; // O(1)
}

int Graph::getCantidadConflictos() const {
    return this->_cantidad_conflictos;
}

