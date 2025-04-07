#include <future>
#include <fstream>
#include <chrono>
#include <iostream>

#include "KP01withCGInstance.h"
#include "Solution.h"
#include "DynamicProgrammingKP01.h"
#include "BacktrackingKP01wCG.h"
#include "BruteForceKP01wCG.h"

void ejecucion(std::ofstream& archivo_generado, std::string algoritmo, const std::string& archivo) {
    auto start = std::chrono::high_resolution_clock::now();

    Solution S;

    if (algoritmo == "FB") {
        BruteForceKP01wCG FB(archivo);
        S = FB.solve();
    } else if (algoritmo == "BT") {
        BacktrackingKP01wCG BT(archivo);
        S = BT.solve();
    } else if (algoritmo == "PD") {
        DynamicProgrammingKP01 PD(archivo);
        S = PD.solve();
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;

    archivo_generado << algoritmo << "," << elapsed.count() << "," << archivo << "\n";
    cout << algoritmo << "," << elapsed.count() << "," << archivo << "\n";
}


int main() {
    std::ofstream archivo("resultadoExperimento.csv");

    if (!archivo.is_open()) {
        std::cerr << "No se pudo abrir el archivo." << std::endl;
        return 1;
    }

    // === Instancias mochila chica ===

    //ejecucion(archivo, "FB", "mochila_chica_n40_no_conflict.txt");
    //ejecucion(archivo, "BT", "mochila_chica_n40_no_conflict.txt");

    //ejecucion(archivo, "FB", "mochila_chica_n50_no_conflict.txt");
    //ejecucion(archivo, "BT", "mochila_chica_n50_no_conflict.txt");

    //ejecucion(archivo, "FB", "mochila_chica_n60_no_conflict.txt");
    //ejecucion(archivo, "BT", "mochila_chica_n60_no_conflict.txt");

    //ejecucion(archivo, "FB", "mochila_chica_n70_no_conflict.txt");
    //ejecucion(archivo, "BT", "mochila_chica_n70_no_conflict.txt");

    //ejecucion(archivo, "FB", "mochila_chica_n80_no_conflict.txt");
    //ejecucion(archivo, "BT", "mochila_chica_n80_no_conflict.txt");

    //ejecucion(archivo, "FB", "mochila_chica_n90_no_conflict.txt");
    //ejecucion(archivo, "BT", "mochila_chica_n90_no_conflict.txt");

    //ejecucion(archivo, "FB", "mochila_chica_n100_no_conflict.txt");
    //ejecucion(archivo, "BT", "mochila_chica_n100_no_conflict.txt");


    // === Instancias mochila apretada ===

    //ejecucion(archivo, "FB", "mochila_apretada_n40_no_conflict.txt");

    //ejecucion(archivo, "FB", "mochila_apretada_n50_no_conflict.txt");

    //ejecucion(archivo, "FB", "mochila_apretada_n60_no_conflict.txt");

    //ejecucion(archivo, "FB", "mochila_apretada_n70_no_conflict.txt");

    //ejecucion(archivo, "FB", "mochila_apretada_n80_no_conflict.txt");


    // === Instancias mochila con conflicto ===

    //ejecucion(archivo, "FB", "costo_peso_correlaciona_n32_star.txt");

    //ejecucion(archivo, "FB", "costo_peso_correlaciona_n34_star.txt");

    //ejecucion(archivo, "FB", "costo_peso_correlaciona_n36_star.txt");
    //ejecucion(archivo, "BT", "costo_peso_correlaciona_n36_star.txt");

    //ejecucion(archivo, "FB", "costo_peso_correlaciona_n38_star.txt");
    //ejecucion(archivo, "BT", "costo_peso_correlaciona_n38_star.txt");

    ejecucion(archivo, "FB", "costo_peso_correlaciona_n40_cycle.txt");
    //ejecucion(archivo, "FB", "costo_peso_correlaciona_n40_star.txt");
    //ejecucion(archivo, "BT", "costo_peso_correlaciona_n40_star.txt");

    archivo.close();
    return 0;
}
