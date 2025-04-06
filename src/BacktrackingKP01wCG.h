// BacktrackingKP01.h
#ifndef BACKTRACKINGKP01WCG_H
#define BACKTRACKINGKP01WCG_H

#include "Solution.h"
#include "KP01withCGInstance.h"

class BacktrackingKP01wCG {
private:
    KP01withCGInstance _instancia;
    Solution _bestSol;
    
    int beneficio_restante(KP01withCGInstance instancia, int k, int n) {
        int suma = 0; // O(1)
        for (int i = k; i < n; i++) { // O(R) con R = cantidad de items restantes a partir de k
            suma += instancia.getProfit(i); // O(1)
        }
        return suma; // O(1)
    }

    void Mochila_BT(Solution S, int k) {
        if (k == this->_instancia.getNumItems()) { // O(1)
            if (S.getWeightSolution() <= this->_instancia.getCapacity() 
                && S.getProfitSolution() > this->_bestSol.getProfitSolution()) { // O(1)
                this->_bestSol = S; // O(1)
            } 
        } else {
            if ((S.getWeightSolution() <= this->_instancia.getCapacity()) && // poda por factibilidad, O(1)
                (S.getProfitSolution() + beneficio_restante(this->_instancia, k, this->_instancia.getNumItems()) 
                    > this->_bestSol.getProfitSolution()) && // poda por optimalidad, O(R)
                (!this->_instancia.hasConflict(S.getItems(), k))) { // grafo de conflictos, O(S)
                Mochila_BT(S, k + 1); // O(2^N/2)
                S.addItem(k, this->_instancia.getWeight(k), this->_instancia.getProfit(k)); // O(log(N))
                Mochila_BT(S, k + 1); // O(2^N/2)
            } else {
                Mochila_BT(S, k + 1); // O(2^N/2)
            }
        }
    };

    // Complejidad: O(2^N*(log(N)+R))

public:
    BacktrackingKP01wCG(const string& archivo);
    Solution solve();
};

#endif // BACKTRACKINGKP01_H