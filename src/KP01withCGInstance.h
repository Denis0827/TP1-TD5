// KP01withCGInstance.h
#ifndef KP01WITHCGINSTANCE_H
#define KP01WITHCGINSTANCE_H
#include <vector>
#include <string>
#include <tuple>
#include "Graph.h"
using namespace std;

class KP01withCGInstance {
private:
    // Definir estructura interna.
    vector<tuple<int, int>> _items;
    int _capacidad;
    int _cantidad_items;
    int _pesoTotal;
    int _beneficioTotal;

    Graph _conflictos;

public:
    // Constructor
    KP01withCGInstance(); // O(1)

    // Observadores
    int getWeight(int index) const; // O(1)
    // Pre: index < this->_cantidad_items
    int getProfit(int index) const; // O(1)
    // Pre: index < this->_cantidad_items
    int getNumItems() const; // O(1)
    int getCapacity() const; // O(1)
    int getWeightTotal() const; // O(1)
    int getProfitTotal() const; // O(1)

    // Modificadores
    void cargar_datos(const string& archivo); // O(N^2 + C)
    void setWeightProfit(int index, int weight, int profit); // O(1)
    // Pre: index < this->_cantidad_items

    // Otros métodos
    int cantidadConflictos() const;
    bool hasConflict(vector<int> solution, int item) const; // O(S)
    // Pre: item < this->_cantidad_items
    bool hasConflictTotal(vector<int> solution) const; // O(S^2)
};

#endif // KP01WITHCGINSTANCE_H