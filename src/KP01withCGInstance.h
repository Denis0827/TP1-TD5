// KP01withCGInstance.h
#ifndef KP01WITHCGINSTANCE_H
#define KP01WITHCGINSTANCE_H

#include "Graph.h"

class KP01withCGInstance {
private:
    // Definir estructura interna.
    vector<tuple<int, int>> _items;
    int _capacidad;
    int _cantidad_items;

    // Agregar el grafo de conflictos.
    vector<vector<bool>> _conflictos;


public:
    KP01withCGInstance(int n, int cap);
    void setWeight(int index, int weight);
    void setProfit(int index, int profit);
    int getWeight(int index) const;
    int getProfit(int index) const;
    int getNumItems() const;
    int getCapacity() const;
    void addConflict(int item1, int item2);
    void removeConflict(int item1, int item2);
    bool hasConflict(const Solution& S, int item);
    // Agregar los metodos que consideren necesarios, en particular para obtener los conflictos.

    KP01withCGInstance cargar_datos(const string& archivo);

};

#endif // KP01WITHCGINSTANCE_H