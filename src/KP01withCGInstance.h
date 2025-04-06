// KP01withCGInstance.h
#ifndef KP01WITHCGINSTANCE_H
#define KP01WITHCGINSTANCE_H
#include <vector>
#include <string>
#include <tuple>
using namespace std;

class KP01withCGInstance {
private:
    // Definir estructura interna.
    vector<tuple<int, int>> _items;
    int _capacidad;
    int _cantidad_items;
    int _pesoTotal;
    int _beneficioTotal;

    // Agregar el grafo de conflictos.
    vector<vector<bool>> _conflictos;
    int _cantidad_conflictos;

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
    void addConflict(int item1, int item2); // O(1)
    // Pre: item1 < this->_cantidad_items && item2 < this->_cantidad_items
    void removeConflict(int item1, int item2); // O(1)
    // Pre: item1 < this->_cantidad_items && item2 < this->_cantidad_items

    // Otros métodos
    bool hasConflict(vector<int> solution, int item) const; // O(S)
    // Pre: item < this->_cantidad_items
};

#endif // KP01WITHCGINSTANCE_H