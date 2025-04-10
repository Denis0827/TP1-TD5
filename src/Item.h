#ifndef ITEM_H
#define ITEM_H

class Item {
private:
    int _numero;
    int _peso;
    int _beneficio;

public:
    // Constructor
    Item(int numero, int weight, int profit); // O(1)

    // Observadores
    int getNumero() const;
    int getWeight() const;
    int getProfit() const;
};

#endif // GRAPH_H