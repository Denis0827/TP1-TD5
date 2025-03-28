#ifndef SOLUTION_H
#define SOLUTION_H

#include <vector>
#include <iostream>

class Solution {
private:
    // Definir estructura interna.
    map<int, tuple<int, int>> _itemsSol;
    int _cantidad_items;

public:
    Solution(int numItems); // Constructor to initialize size
    void addItem(int item, int peso, int beneficio);
    void removeItem(int item);
    bool contains(int item) const;
    void printSolution() const;
    // Pueden agregar los metodos que consideren necesarios.
};

#endif // SOLUTION_H

