// BacktrackingKP01.h
#ifndef BACKTRACKINGKP01WCG_H
#define BACKTRACKINGKP01WCG_H

#include "Solution.h"
#include "KP01withCGInstance.h"

class BacktrackingKP01wCG {
private:
    KP01withCGInstance _instancia;

    int beneficio_restante(const KP01withCGInstance& instancia, int k, int n) {
        int suma = 0;
        for (int i = k; i < n; i++) {
            suma += instancia.getProfit(i);
        }
        return suma;
    }

    void Mochila_BT(Solution& S, int k, Solution& B) {
        if (k == this->_instancia.getNumItems()) {
            if (S.getWeightSolution() <= this->_instancia.getCapacity() 
                && S.getProfitSolution() > B.getProfitSolution()) {
                B = S;
            }
        } else {
            if ((S.getWeightSolution() <= this->_instancia.getCapacity()) &&
                (S.getProfitSolution() + beneficio_restante(this->_instancia, k, this->_instancia.getNumItems()) > B.getProfitSolution()) &&
                (!this->_instancia.hasConflict(S.getItems(), k))) {
                    S.addItem(k, this->_instancia.getWeight(k), this->_instancia.getProfit(k));
                    Mochila_BT(S, k + 1, B);
                    S.removeItem(k);                        
            } Mochila_BT(S, k + 1, B);
        }
    };

public:
    BacktrackingKP01wCG(const string& archivo);
    Solution solve();
};

#endif // BACKTRACKINGKP01_H