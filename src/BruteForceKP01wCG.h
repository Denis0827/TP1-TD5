// BruteForceKP01wCG.h
#ifndef BRUTEFORCEKP01WCG_H
#define BRUTEFORCEKP01WCG_H

#include "Solution.h"
#include "KP01withCGInstance.h"
#include "Graph.h"

// Clase que implementa el algoritmo de fuerza bruta para KP01 con conflictos
class BruteForceKP01wCG {
    private:
        KP01withCGInstance _instancia; // O(1)
    
        // Algoritmo recursivo que explora todas las combinaciones posibles de ítems
        void Mochila_FB(Solution& S, int k, Solution& B) {
            if (k == this->_instancia.getNumItems()) { // O(1)
                if (S.getWeightSolution() <= this->_instancia.getCapacity()  // O(1)
                    && S.getProfitSolution() > B.getProfitSolution()         // O(1)
                    && !this->_instancia.hasConflictTotal(S.getItems())) {  // O(S^2)
                    B = S;  // O(N)
                } 
            } else {
                S.addItem(k, this->_instancia.getWeight(k), this->_instancia.getProfit(k)); // O(log N)
                Mochila_FB(S, k + 1, B);  // recursión → O(2^N)
                S.removeItem(k);  // O(N)
                Mochila_FB(S, k + 1, B);  // recursión → O(2^N)
            }
        };
    
    public:
        BruteForceKP01wCG(const string& archivo); // O(N^2 + C)
        Solution solve(); // O(2^N * (N + S^2))
    };
    
    #endif // BRUTEFORCEKP01WCG_H
    