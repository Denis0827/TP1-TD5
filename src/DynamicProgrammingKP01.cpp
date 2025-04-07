// DynamicProgrammingKP01.cpp
#include "KP01withCGInstance.h"
#include "DynamicProgrammingKP01.h"
#include <vector>
#include <chrono>
#include <algorithm>

DynamicProgrammingKP01::DynamicProgrammingKP01(const string& archivo) {
    this->_instancia = KP01withCGInstance();
    this->_instancia.cargar_datos(archivo);
    this->_bestSol = Solution();  
}

vector<vector<int>> DynamicProgrammingKP01::matriz_optima() {

    int n = this->_instancia.getNumItems();
    int C = this->_instancia.getCapacity();
    
    vector<vector<int>> m(n + 1, vector<int>(C + 1, -1));

    for (int i = 0; i <= this->_instancia.getNumItems(); i++) {
        m[i][0] = 0;
    }

    for (int c = 0; c <= this->_instancia.getCapacity(); c++) {
        m[0][c] = 0;
    }

    for (int k = 1; k <= this->_instancia.getNumItems(); k++){
        for (int c = 1; c <= this->_instancia.getCapacity(); c++){
            if (this->_instancia.getWeight(k - 1) > c){
                m[k][c] = m[k-1][c];
            }
            else {
                if (m[k - 1][c] > this->_instancia.getProfit(k - 1) + m[k - 1][c - this->_instancia.getWeight(k - 1)]){
                    m[k][c] = m[k - 1][c];
                }
                else {
                    m[k][c] = this->_instancia.getProfit(k - 1) + m[k - 1][c - this->_instancia.getWeight(k - 1)];
                }
            }
        }   
    }

    return m;
}

Solution DynamicProgrammingKP01::solve() {
    vector<vector<int>> m = matriz_optima();
    int k = this->_instancia.getNumItems();
    int c = this->_instancia.getCapacity();
    Solution S = Solution();

    while (k != 0 && c != 0) {
        if (m[k][c] != m[k-1][c] &&
            m[k][c] == m[k-1][c - this->_instancia.getWeight(k-1)] + this->_instancia.getProfit(k-1)) {
            S.addItem(k-1, this->_instancia.getWeight(k-1), this->_instancia.getProfit(k-1));
            c -= this->_instancia.getWeight(k-1);
        }
        k--;
    }

    return S;
}


int main() {
    
    auto start = std::chrono::high_resolution_clock::now();

    DynamicProgrammingKP01 PD = DynamicProgrammingKP01("mochila_chica_n30_no_conflict.txt");
    Solution S = PD.solve();
    S.printSolution();

    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> elapsed = end - start;
    std::cout << "Tiempo de ejecución: " << elapsed.count() << " segundos\n";

    return 0;
}
    




