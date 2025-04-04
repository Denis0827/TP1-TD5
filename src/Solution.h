#ifndef SOLUTION_H
#define SOLUTION_H

#include <vector>
#include <iostream>
#include <map>
#include <tuple>
using namespace std;

class Solution {
private:
    // Definir estructura interna.
    map<int, tuple<int, int>> _itemsSol;
    vector<int> _items;
    int _cantidad_items;
    int _pesoTotal;
    int _beneficioTotal;

public:
    // Constructor
    Solution(); 
    
    // Modificadores
    void addItem(int item, int peso, int beneficio);
    void removeItem(int item);

    // Observadores
    int getWeightSolution() const;
    int getProfitSolution() const;
    vector<int> getItems() const;

    // Otros métodos
    bool contains(int item) const;
    void printSolution() const;
};

#endif // SOLUTION_H

