#include "KP01withCGInstance.h"
#include <tuple>
#include <string>
#include <iostream>
#include <fstream>
#include <filesystem>
using namespace std;

KP01withCGInstance::KP01withCGInstance() {
    this->_capacidad = 0; // O(1)
    this->_cantidad_items = 0; // O(1)
    this->_items; // O(1)
    this->_conflictos; // O(1)
    this->_cantidad_conflictos = 0; // O(1)
    this->_pesoTotal = 0; // O(1)
    this->_beneficioTotal = 0; // O(1)
}

void KP01withCGInstance::setWeightProfit(int index, int weight, int profit) {
    this->_items[index] = make_tuple(weight, profit); // O(1)
    this->_pesoTotal += weight; // O(1)
    this->_beneficioTotal += profit; // O(1)
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

void KP01withCGInstance::addConflict(int item1, int item2) {
    this->_conflictos[item1][item2] = true; // O(1)
    this->_conflictos[item2][item1] = true; // O(1)
}

void KP01withCGInstance::removeConflict(int item1, int item2) {
    this->_conflictos[item1][item2] = false; // O(1)
    this->_conflictos[item2][item1] = false; // O(1)
}

bool KP01withCGInstance::hasConflict(vector<int> solution, int item) const {
    for (int i = 0; i < solution.size(); i++) { // O(S)
        if (this->_conflictos[item][solution[i]] == true) { // O(1)
            return true; // O(1)
        }
    }
    return false; // O(1)
}

void KP01withCGInstance::cargar_datos(const string& archivo) {
    ifstream file(archivo); // O(1)
    if (!file.is_open()) { // O(1)
        cerr << "No se pudo abrir el archivo " << archivo << endl; // O(1)
    }

    string line; // O(1)
    
    // Leer la primera línea: número total de ítems (n)
    getline(file, line); // O(1)
    this->_cantidad_items = stoi(line); // O(1)

    // Leer la segunda línea: capacidad de la mochila (C)
    getline(file, line); // O(1)
    this->_capacidad = stoi(line); // O(1)

    this->_items;  // O(1)
    for (int i = 0; i < this->_cantidad_items; i++) { // O(N) con N = cantidad de items
        this->_items.push_back(make_tuple(0, 0)); // O(1)
    }

    vector<int> pesos; string elem_p; // O(1)
    getline(file, line); // O(1)
    for (int i = 0; i < line.length(); i++) { // O(N)
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
    for (int i = 0; i < line.length(); i++) { // O(N)
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
    this->_conflictos = vector<vector<bool>>(this->_cantidad_items, vector<bool>(this->_cantidad_items, false)); // O(N^2)

    // Leer la quinta línea: número de pares de conflictos
    getline(file, line); // O(1)
    this->_cantidad_conflictos = stoi(line); // O(1)

    // Leer las siguientes m líneas para los pares de conflictos
    string n1; string n2; int j; // O(1)
    for (int i = 0; i < this->_cantidad_conflictos; i++) { // O(C) con C = cantidad de conflictos
        n1 = ""; n2 = ""; // O(1)
        getline(file, line); j = 0; // O(1)
        while (line[j] != ' ') { // O(1) porque sabemos que la línea puede tener una cantidad limitada de caracteres, pues 
                                 // como mucho habrían 999 ítems en la instancia (o eso creemos....)
            n1 += line[j]; // O(1)
            j++; // O(1)
        } 
        for (int k = j + 1; k < line.length(); k++) { // O(1) por lo mismo de arriba
            n2 += line[k]; // O(1)
        }
        addConflict(stoi(n1), stoi(n2)); // O(1)
    }

    file.close();  // O(1)
}