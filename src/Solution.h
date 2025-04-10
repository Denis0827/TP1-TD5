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
    Solution(); // O(1)
    
    // Modificadores
    void addItem(int item, int peso, int beneficio); // O(log(N))
    void removeItem(int item); // O(N)
    // Pre: item tiene que estar en el conjunto de _itemsSol y _items

    // Observadores
    int getWeightSolution() const; // O(1)
    int getProfitSolution() const; // O(1)
    vector<int> getItems() const; // O(1)

    // Otros métodos
    bool contains(int item) const; // O(log(N))
    void printSolution() const; // O(N)

    void reverse(); // O(N)
};

#endif // SOLUTION_H

