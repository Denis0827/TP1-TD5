#ifndef SOLUTION_H
#define SOLUTION_H

#include <vector>
#include <iostream>
using namespace std;

class Solution {
private:
    // Definir estructura interna.
    map<int, tuple<int, int>> _itemsSol;
    int _cantidad_items;

public:
    // Constructor
    Solution(int numItems); 
    
    // Modificadores
    void addItem(int item, int peso, int beneficio);
    void removeItem(int item);

    // Otros métodos
    bool contains(int item) const;
    void printSolution() const;
};

#endif // SOLUTION_H

