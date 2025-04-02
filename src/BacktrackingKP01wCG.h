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
        int suma = 0;
        for (int i = k; i < n; i++){
            suma += instancia.getProfit(i); 
        }
        return suma;
    }

    void Mochila_BT(Solution S, int k) {
        if (k == this->_instancia.getNumItems()) {
            if (S.getWeightSolution() <= this->_instancia.getCapacity() && S.getProfitSolution() > this->_bestSol.getProfitSolution()) {
                this->_bestSol = S;
            } 
        } else {
            if ((S.getWeightSolution() <= this->_instancia.getCapacity()) && // poda por factibilidad
                (S.getProfitSolution() + beneficio_restante(this->_instancia, k, this->_instancia.getNumItems()) > this->_bestSol.getProfitSolution()) && // poda por optimalidad
                (!this->_instancia.hasConflict(S.getItems(), k))) { // grafo de conflictos
                Mochila_BT(S, k + 1); 
                S.addItem(k, this->_instancia.getWeight(k), this->_instancia.getProfit(k)); 
                Mochila_BT(S, k + 1); 
            } else {
                Mochila_BT(S, k + 1);
            }
        }
    };

public:
    BacktrackingKP01wCG(const string& archivo);
    Solution solve();
};

#endif // BACKTRACKINGKP01_H