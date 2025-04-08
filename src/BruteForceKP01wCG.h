// BruteForceKP01wCG.h
#ifndef BRUTEFORCEKP01WCG_H
#define BRUTEFORCEKP01WCG_H

#include "Solution.h"
#include "KP01withCGInstance.h"
#include "Graph.h"

class BruteForceKP01wCG {
private:
    KP01withCGInstance _instancia;
    Solution _bestSol;

    void Mochila_FB(const Solution& S, int k) {

        if (k == this->_instancia.getNumItems()) { // O(1)
            if (S.getWeightSolution() <= this->_instancia.getCapacity() 
                && S.getProfitSolution() > this->_bestSol.getProfitSolution()
                && !this->_instancia.hasConflictTotal(S.getItems())) { // O(N^2))
                this->_bestSol = S; // O(1)
            } 
        } else {
            Mochila_FB(S, k + 1); // O(2^N/2)
            S.addItem(k, this->_instancia.getWeight(k), this->_instancia.getProfit(k)); // O(log(N))
            Mochila_FB(S, k + 1); // O(2^N/2)
        }
        
    };

    // Complejidad: O(2^N*(log(N)))

public:
    BruteForceKP01wCG(const string& archivo);
    Solution solve();
};

#endif // BRUTEFORCEKP01WCG_H