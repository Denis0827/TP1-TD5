#include "KP01withCGInstance.h"
#include <tuple>
#include <string>
#include <iostream>
#include <fstream>
#include <filesystem>
using namespace std;

KP01withCGInstance::KP01withCGInstance() {
    this->_capacidad = 0;
    this->_cantidad_items = 0;
    this->_items; 
    this->_conflictos;
    this->_cantidad_conflictos = 0;
}

void KP01withCGInstance::setWeightProfit(int index, int weight, int profit) {
    this->_items[index] = make_tuple(weight, profit);
    this->_pesoTotal += weight;
    this->_beneficioTotal += profit;
}

int KP01withCGInstance::getWeight(int index) const {
    return get<0>(this->_items[index]);
}

int KP01withCGInstance::getProfit(int index) const {
    return get<1>(this->_items[index]);
}

int KP01withCGInstance::getNumItems() const {
    return this->_cantidad_items;
}

int KP01withCGInstance::getCapacity() const {
    return this->_capacidad;
}

int KP01withCGInstance::getWeightTotal() const {
    return this->_pesoTotal;
}

int KP01withCGInstance::getProfitTotal() const {
    return this->_beneficioTotal;
}

void KP01withCGInstance::addConflict(int item1, int item2) {
    this->_conflictos[item1][item2] = true;
    this->_conflictos[item1][item2] = true;
}

void KP01withCGInstance::removeConflict(int item1, int item2) {
    this->_conflictos[item1][item2] = false;
    this->_conflictos[item1][item2] = false;
}

bool KP01withCGInstance::hasConflict(vector<int> solution, int item) const {
    for (int i = 0; i < solution.size(); i++) {
        if (this->_conflictos[item][solution[i]] == true) {
            return true;
        }
    }
    return false;
}

void KP01withCGInstance::cargar_datos(const string& archivo) {
    ifstream file(archivo);  // Abrir el archivo de entrada
    if (!file.is_open()) {
        cerr << "No se pudo abrir el archivo " << archivo << endl;
    }

    string line;
    
    // Leer la primera línea: número total de ítems (n)
    getline(file, line);
    this->_cantidad_items = stoi(line);

    // Leer la segunda línea: capacidad de la mochila (C)
    getline(file, line);
    this->_capacidad = stoi(line);

    // Inicializar las variables de la clase
    this->_items;  // Crear un vector de tuplas (peso, beneficio)
    for (int i = 0; i < this->_cantidad_items; i++) {
        this->_items.push_back(make_tuple(0, 0));
    }

    vector<int> pesos;
    while (getline(file, line), ' ') {
        pesos.push_back(stoi(line));
    }

    vector<int> beneficios;
    while (getline(file, line), ' ') {
        pesos.push_back(stoi(line));
    }

    for (int i = 0; i < this->_cantidad_items; i++) {
        setWeightProfit(i, pesos[i], beneficios[i]);
    }

    // Inicializar la matriz de conflictos
    this->_conflictos = vector<vector<bool>>(this->_cantidad_items, vector<bool>(this->_cantidad_items, false));

    // Leer la quinta línea: número de pares de conflictos
    getline(file, line);
    this->_cantidad_conflictos = stoi(line);

    // Leer las siguientes m líneas para los pares de conflictos
    string n1; string n2; int j;
    for (int i = 0; i < this->_cantidad_conflictos; i++) {
        getline(file, line); j = 0;
        while (line[j] != ' ') {
            n1 += line[j];
            j++;
        } 
        for (int k = j + 1; k < line.length(); k++) {
            n2 += line[j];
        }
        addConflict(stoi(n1), stoi(n2));
    }

    file.close();  // Cerrar el archivo después de leerlo
}

int main() {
    KP01withCGInstance instancia = KP01withCGInstance();
    instancia.cargar_datos("./instances/mochila_chica_n10_no_conflict.txt");
    cout << instancia.getCapacity() << endl;
}