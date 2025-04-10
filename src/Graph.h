// Graph.h
#ifndef GRAPH_H
#define GRAPH_H

#include "Solution.h"

class Graph {
private:
    vector<vector<bool>> _conflictos;
    int _cantidad_conflictos;

public:
    // Constructor
    Graph(); // O(1)

    // Observadores
    int getCantidadConflictos() const; // O(1)
    vector<vector<bool>> getMatriz() const; // O(1)

    // Modificadores
    void construirMatriz(int cantidad_items); // O(N^2)
    void addConflict(int item1, int item2); // O(1)
    // Pre: item1 < this->_cantidad_items && item2 < this->_cantidad_items
    void removeConflict(int item1, int item2); // O(1)
    // Pre: item1 < this->_cantidad_items && item2 < this->_cantidad_items
};

#endif // GRAPH_H