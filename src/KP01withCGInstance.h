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
    KP01withCGInstance();

    // Observadores
    int getWeight(int index) const;
    int getProfit(int index) const;
    int getNumItems() const;
    int getCapacity() const;
    int getWeightTotal() const;
    int getProfitTotal() const;

    // Modificadores
    void cargar_datos(const string& archivo);
    void setWeightProfit(int index, int weight, int profit);
    void addConflict(int item1, int item2);
    void removeConflict(int item1, int item2);

    // Otros métodos
    bool hasConflict(vector<int> solution, int item) const;
};

#endif // KP01WITHCGINSTANCE_H