// DynamicProgrammingKP01.cpp
#include "KP01withCGInstance.h"
#include "DynamicProgrammingKP01.h"
#include <vector>
#include <chrono>
#include <algorithm>

// Constructor: carga instancia desde archivo
DynamicProgrammingKP01::DynamicProgrammingKP01(const string& archivo) {
    this->_instancia = KP01withCGInstance(); // O(1)
    this->_instancia.cargarDatos(archivo);  // O(N^2 + C)
    this->_bestSol = Solution(); // O(1)
}

// Construcción de la tabla dinámica
vector<vector<int>> DynamicProgrammingKP01::matriz_optima() {
    int n = this->_instancia.getNumItems(); // O(1)
    int C = this->_instancia.getCapacity(); // O(1)
    
    vector<vector<int>> m(n + 1, vector<int>(C + 1, -1)); // O(N*C)

    // La primera fila y la primera columna se inicializan en cero porque son casos vacíos
    for (int i = 0; i <= n; i++) { // O(N)
        m[i][0] = 0; // O(1)
    }

    for (int c = 0; c <= C; c++) { // O(C)
        m[0][c] = 0; // O(1)
    }

    for (int k = 1; k <= n; k++) {  // O(N)
        for (int c = 1; c <= C; c++) {  // O(C)
            // Si p[k] > c, entonces el item k ya no entra en la mochila
            if (this->_instancia.getWeight(k - 1) > c) { // O(1)
                m[k][c] = m[k-1][c];  // O(1)
            } else {
                if (m[k - 1][c] > this->_instancia.getProfit(k - 1) + m[k - 1][c - this->_instancia.getWeight(k - 1)]) { // O(1)
                    // Si añadir el item k no aumenta el valor de beneficio, no actualizo el m[k][c]
                    m[k][c] = m[k - 1][c];  // O(1)
                } else {
                    m[k][c] = this->_instancia.getProfit(k - 1) + m[k - 1][c - this->_instancia.getWeight(k - 1)]; // O(1) 
                }
            }
        }
    }

    return m; // O(1)
}

// Reconstrucción de la solución óptima desde la tabla
Solution DynamicProgrammingKP01::solve() {
    vector<vector<int>> m = matriz_optima(); // O(N*C)
    int k = this->_instancia.getNumItems(); // O(1)
    int c = this->_instancia.getCapacity(); // O(1)
    Solution S = Solution(); // O(1)

    while (k != 0 && c != 0) { // O(N)
        if (m[k][c] != m[k-1][c] && // O(1)
            m[k][c] == m[k-1][c - this->_instancia.getWeight(k-1)] + this->_instancia.getProfit(k-1)) { // O(1)
            S.addItem(k-1, this->_instancia.getWeight(k-1), this->_instancia.getProfit(k-1)); // O(log N)
            c -= this->_instancia.getWeight(k-1); // O(1)
        }
        k--; // O(1)
    }

    S.reverse(); // O(N)
    return S; // O(1)
}


/*
int main() {
    
    auto start = std::chrono::high_resolution_clock::now();

    DynamicProgrammingKP01 PD = DynamicProgrammingKP01("instances/mochila_chica_n30_no_conflict.txt");
    Solution S = PD.solve();
    S.printSolution();

    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> elapsed = end - start;
    std::cout << "Tiempo de ejecución: " << elapsed.count() << " segundos\n";

    return 0;
}
    */
    




