// BacktrackingKP01.h
#ifndef BACKTRACKINGKP01WCG_H
#define BACKTRACKINGKP01WCG_H

#include "Solution.h"
#include "KP01withCGInstance.h"

// Clase que implementa el algoritmo de backtracking con podas para KP01 con conflictos
class BacktrackingKP01wCG {
    private:
        KP01withCGInstance _instancia; // O(1)
    
        // Suma de beneficios restantes desde el ítem k hasta n-1
        int beneficio_restante(const KP01withCGInstance& instancia, int k, int n) {
            int suma = 0; // O(1)
            for (int i = k; i < n; i++) {  // O(N - k) → O(N) en el peor caso
                suma += instancia.getProfit(i); // O(1)
            }
            return suma; // O(1)
        }
    
        // Algoritmo de backtracking con podas
        void Mochila_BT(Solution& S, int k, Solution& B) {
            if (k == this->_instancia.getNumItems()) { // O(1)
                if (S.getWeightSolution() <= this->_instancia.getCapacity()  // O(1)
                    && S.getProfitSolution() > B.getProfitSolution()) {  // O(1)
                    B = S;  // O(1) porque es una asignación por memoria
                }
            } else {
                if ((S.getWeightSolution() <= this->_instancia.getCapacity()) &&   // O(1), poda por factibilidad
                    (S.getProfitSolution() + beneficio_restante(this->_instancia, k, this->_instancia.getNumItems()) > B.getProfitSolution()) && // O(N), poda por optimalidad
                    (!this->_instancia.hasConflict(S.getItems(), k))) { // O(S), poda por factibilidad para el grafo de conflictos
                        S.addItem(k, this->_instancia.getWeight(k), this->_instancia.getProfit(k)); // O(1)
                        Mochila_BT(S, k + 1, B);  // recursión → O(2^N)
                        S.removeItem(k); // O(N)
                }
                Mochila_BT(S, k + 1, B); // recursión → O(2^N)
            }
        };
    
    public:
        BacktrackingKP01wCG(const string& archivo); // O(N^2 + C)
        Solution solve(); // O(2^N*(N + S)) en el peor caso
    };
    
    #endif // BACKTRACKINGKP01_H