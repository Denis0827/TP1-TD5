// DynamicProgrammingKP01.cpp
#include "KP01withCGInstance.h"
#include "DynamicProgrammingKP01.h"
#include <vector>
#include <algorithm>

DynamicProgrammingKP01::DynamicProgrammingKP01(const string& archivo) {
    this->_instancia = KP01withCGInstance();
    this->_instancia.cargar_datos(archivo);
    this->_bestSol = Solution();  
}

vector<vector<int>> DynamicProgrammingKP01::valor_optimo() {

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
            if (this->_instancia.getWeight(k-1) > c){
                m[k][c] = m[k - 1][c];
            }
            else {
                if (m[k - 1][c] > this->_instancia.getProfit(k-1) + m[k - 1][c - this->_instancia.getWeight(k-1)]){
                    m[k][c] = m[k - 1][c];
                }
                else {
                    m[k][c] = this->_instancia.getProfit(k-1) + m[k - 1][c - this->_instancia.getWeight(k-1)];
                }
            }
        }   
    }

    return m;
}


/*

Solution DynamicProgrammingKP01::solve() {

    vector<vector<int>> m = vector<vector<int>>(this->_instancia.getNumItems(), vector<int>(this->_instancia.getNumItems(), -1)); // O(N^2)

    for (int i = 0; i <= this->_instancia.getNumItems(); i++) {
        m[i][0] = 0;
    }

    for (int c = 0; c <= this->_instancia.getCapacity(); c++) {
        m[0][c] = 0;
    }

    for (int k = 1; k <= this->_instancia.getNumItems(); k++){
        for (int c = 1; c <= this->_instancia.getCapacity(); c++){
            if (this->_instancia.getWeight(k) > c){
                m[k][c] = m[k-1][c];
            }
            else {
                if (m[k - 1][c] > this->_instancia.getProfit(k) + m[k - 1][c - this->_instancia.getWeight(k)]){
                    m[k][c] = m[k - 1][c];
                }
                else {
                    m[k][c] = this->_instancia.getProfit(k) + m[k - 1][c - this->_instancia.getWeight(k)];
                }
            }
        }   
    }

    return m[this->_instancia.getNumItems()][this->_instancia.getCapacity()];
}

*/

int main() {
    DynamicProgrammingKP01 PD = DynamicProgrammingKP01("mochila_chica_n10_no_conflict.txt");
    vector<vector<int>> matriz = PD.valor_optimo();

    for (const auto& fila : matriz) {
        for (const auto& valor : fila) {
            std::cout << valor << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}




