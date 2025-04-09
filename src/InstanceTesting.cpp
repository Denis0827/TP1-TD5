#include <iostream>
#include "KP01withCGInstance.h"
using namespace std;

int errores = 0;

void caso_getters_basicos() {
    cout << "[Caso: Getters con mochila chica sin conflictos]..." << endl;

    KP01withCGInstance instancia;
    instancia.cargar_datos("mochila_chica_n10_no_conflict.txt");

    if (instancia.getNumItems() != 10) errores++;
    if (instancia.getCapacity() != 6016) errores++;

    if (instancia.getWeight(0) != 1351) errores++;
    if (instancia.getProfit(0) != 1962) errores++;
    if (instancia.getWeightTotal() != 10220) errores++; // suma de pesos
    if (instancia.getProfitTotal() != 12255) errores++; // suma de beneficios
}

void caso_conflictos_en_instancia() {
    cout << "[Caso: Verificación de conflictos en instancia con grafo tipo ciclo]..." << endl;

    KP01withCGInstance instancia;
    instancia.cargar_datos("costo_peso_correlaciona_n20_cycle.txt");

    vector<int> solucion = {1};
    if (!instancia.hasConflict(solucion, 2)) errores++; // 1–2 están en conflicto
    if (instancia.hasConflict(solucion, 5)) errores++;  // 1–5 no están en conflicto
}

int main() {
    caso_getters_basicos();
    caso_conflictos_en_instancia();

    if (errores == 0) {
        cout << "\n Todos los tests de KP01withCGInstance pasaron correctamente." << endl;
    } else {
        cout << "\n Se detectaron " << errores << " errores en los tests de KP01withCGInstance." << endl;
    }

    return 0;
}