// DynamicProgrammingKP01.h
#ifndef DYNAMICPROGRAMMINGKP01_H
#define DYNAMICPROGRAMMINGKP01_H

#include "Solution.h"
#include "KP01withCGInstance.h"

// Clase que implementa el algoritmo de programación dinámica para KP01
class DynamicProgrammingKP01 {
    private:
        KP01withCGInstance _instancia; // O(1)
        Solution _bestSol;             // O(1)
    
    public:
        DynamicProgrammingKP01(const string& archivo);      // O(N^2 + C)
        vector<vector<int>> matriz_optima();                // O(N*C)
        Solution solve();                                   // O(N*C)
    };
    
    #endif // DYNAMICPROGRAMMINGKP01_H