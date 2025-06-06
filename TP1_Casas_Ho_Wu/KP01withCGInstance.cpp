#include "KP01withCGInstance.h"
#include "Graph.h"
#include <tuple>
#include <string>
#include <iostream>
#include <fstream>
#include <filesystem>
using namespace std;

KP01withCGInstance::KP01withCGInstance() {
    this->_capacidad = 0; // O(1)
    this->_cantidad_items = 0; // O(1)
    this->_items = vector<tuple<int, int>>(); // O(1)
    this->_pesoTotal = 0; // O(1)
    this->_beneficioTotal = 0; // O(1)
    this->_conflictos = Graph(); // O(1)
}


int KP01withCGInstance::getWeight(int index) const {
    return get<0>(this->_items[index]); // O(1)
}

int KP01withCGInstance::getProfit(int index) const {
    return get<1>(this->_items[index]); // O(1)
}

int KP01withCGInstance::getNumItems() const {
    return this->_cantidad_items; // O(1)
}

int KP01withCGInstance::getCapacity() const {
    return this->_capacidad; // O(1)
}

int KP01withCGInstance::getWeightTotal() const {
    return this->_pesoTotal; // O(1)
}

int KP01withCGInstance::getProfitTotal() const {
    return this->_beneficioTotal; // O(1)
}

int KP01withCGInstance::cantidadConflictos() const {
    return this->_conflictos.getCantidadConflictos(); // O(1)
}

void KP01withCGInstance::setWeightProfit(int index, int weight, int profit) {
    this->_items[index] = make_tuple(weight, profit); // O(1)
    this->_pesoTotal += weight; // O(1)
    this->_beneficioTotal += profit; // O(1)
}

void KP01withCGInstance::cargarDatos(const string& archivo) {
    ifstream file(archivo); // O(1)
    if (!file.is_open()) { // O(1)
        cerr << "No se pudo abrir el archivo " << archivo << endl; // O(1)
    }

    string line; // O(1)
    
    // Leer la primera línea: número total de ítems
    getline(file, line); // O(1)
    this->_cantidad_items = stoi(line); // O(1)

    // Leer la segunda línea: capacidad de la mochila
    getline(file, line); // O(1)
    this->_capacidad = stoi(line); // O(1)

    for (int i = 0; i < this->_cantidad_items; i++) { // O(N) con N = cantidad de items
        this->_items.push_back(make_tuple(0, 0)); // O(1)
    }
    
    vector<int> pesos; string elem_p; // O(1)
    getline(file, line); // O(1)
    for (size_t i = 0; i < line.length(); i++) { // O(1) porque sabemos que la línea puede tener una cantidad limitada de caracteres, pues 
                                                // como mucho habrían 999 ítems en la instancia (o eso creemos....)
        if (line[i] != ' ') { // O(1)
            elem_p += line[i]; // O(1)
        } else {
            pesos.push_back(stoi(elem_p)); // O(1)
            elem_p = ""; // O(1)
        }
    }
    pesos.push_back(stoi(elem_p)); // O(1)

    vector<int> beneficios; string elem_b; // O(1)
    getline(file, line); // O(1)
    for (size_t i = 0; i < line.length(); i++) { // O(1) por lo mismo que antes
        if (line[i] != ' ') { // O(1)
            elem_b += line[i]; // O(1)
        } else { 
            beneficios.push_back(stoi(elem_b)); // O(1)
            elem_b = ""; // O(1)
        }
    }
    beneficios.push_back(stoi(elem_b)); // O(1)

    for (int i = 0; i < this->_cantidad_items; i++) { // O(N)
        setWeightProfit(i, pesos[i], beneficios[i]); // O(1)
    }

    // Inicializar la matriz de conflictos
    this->_conflictos.construirMatriz(this->_cantidad_items); // O(N^2)

    // Leer la quinta línea: número de pares de conflictos
    getline(file, line); // O(1)
    int cant_conflictos = stoi(line); // O(1)

    // Leer las siguientes m líneas para los pares de conflictos
    string n1; string n2; int j; // O(1)
    for (int i = 0; i < cant_conflictos; i++) { // O(C) con C = cantidad de conflictos
        n1 = ""; n2 = ""; // O(1)
        getline(file, line); j = 0; // O(1)
        while (line[j] != ' ') { // O(1) porque fijé una cantidad máximo de ítems (999)
            n1 += line[j]; // O(1)
            j++; // O(1)
        } 
        for (size_t k = j + 1; k < line.length(); k++) { // O(1) por lo mismo de arriba
            n2 += line[k]; // O(1)
        }
        this->_conflictos.addConflict(stoi(n1), stoi(n2)); // O(1)
    }

    file.close();  // O(1)
}

bool KP01withCGInstance::hasConflict(vector<int> solution, int item) const {
    vector<vector<bool>> matriz = this->_conflictos.getMatriz(); // O(1)
    for (size_t i = 0; i < solution.size(); i++) { // O(S)
        // Verifico si para algún item dentro de solution se genera conflicto con el item pasado por parámetro
        if (matriz[item][solution[i]] == true) { // O(1) 
            return true; // O(1)
        }
    }
    return false; // O(1)
}

bool KP01withCGInstance::hasConflictTotal(vector<int> solution) const {
    vector<vector<bool>> matriz = this->_conflictos.getMatriz(); // O(1)
    for (size_t i = 0; i < solution.size(); i++) { // O(S) con S = cantidad de elem en solution
        // Verifico solo para lo nuevo, lo anterior al ítem ya fue verificado y 
        // cumple que si m[i][j] = true, entonces m[j][i] = true
        for (size_t j = i + 1; j < solution.size(); j++) { // O(S)
            if (matriz[solution[i]][solution[j]] == true) { // O(1)
                return true; // O(1)
            }
        }
    }
    return false; // O(1)
}