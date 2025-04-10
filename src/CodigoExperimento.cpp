
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
    } else if (algoritmo == "DP") {
        DynamicProgrammingKP01 DP(archivo);
        S = DP.solve();
    }

    vector<int> items = S.getItems();

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;

    archivo_generado << algoritmo << ";" << elapsed.count() << ";" << archivo << ";";
    
    archivo_generado << "[";
    for (size_t i = 0; i < items.size(); ++i) {
        archivo_generado << items[i];
        if (i != items.size() - 1) {
            archivo_generado << ",";
        }
    }
    archivo_generado << "]" << "\n";

    cout << algoritmo << "," << elapsed.count() << "," << archivo << "\n";
}


int main() {
    std::ofstream archivo("resultadoExperimentoC++2.csv");

    if (!archivo.is_open()) {
        std::cerr << "No se pudo abrir el archivo." << std::endl;
        return 1;
    }

    // === Instancias mochila chica ===
    ejecucion(archivo, "FB", "mochila_chica_n10_no_conflict.txt");
    ejecucion(archivo, "BT", "mochila_chica_n10_no_conflict.txt");
    ejecucion(archivo, "DP", "mochila_chica_n10_no_conflict.txt");

    ejecucion(archivo, "FB", "mochila_chica_n20_no_conflict.txt");
    ejecucion(archivo, "BT", "mochila_chica_n20_no_conflict.txt");
    ejecucion(archivo, "DP", "mochila_chica_n20_no_conflict.txt");

    ejecucion(archivo, "FB", "mochila_chica_n30_no_conflict.txt");
    ejecucion(archivo, "BT", "mochila_chica_n30_no_conflict.txt");
    ejecucion(archivo, "DP", "mochila_chica_n30_no_conflict.txt");

    //ejecucion(archivo, "FB", "mochila_chica_n40_no_conflict.txt");
    //ejecucion(archivo, "BT", "mochila_chica_n40_no_conflict.txt");
    ejecucion(archivo, "DP", "mochila_chica_n40_no_conflict.txt");

    //ejecucion(archivo, "FB", "mochila_chica_n50_no_conflict.txt");
    //ejecucion(archivo, "BT", "mochila_chica_n50_no_conflict.txt");
    ejecucion(archivo, "DP", "mochila_chica_n50_no_conflict.txt");

    //ejecucion(archivo, "FB", "mochila_chica_n60_no_conflict.txt");
    //ejecucion(archivo, "BT", "mochila_chica_n60_no_conflict.txt");
    ejecucion(archivo, "DP", "mochila_chica_n60_no_conflict.txt");

    //ejecucion(archivo, "FB", "mochila_chica_n70_no_conflict.txt");
    //ejecucion(archivo, "BT", "mochila_chica_n70_no_conflict.txt");
    ejecucion(archivo, "DP", "mochila_chica_n70_no_conflict.txt");

    //ejecucion(archivo, "FB", "mochila_chica_n80_no_conflict.txt");
    //ejecucion(archivo, "BT", "mochila_chica_n80_no_conflict.txt");
    ejecucion(archivo, "DP", "mochila_chica_n80_no_conflict.txt");

    //ejecucion(archivo, "FB", "mochila_chica_n90_no_conflict.txt");
    //ejecucion(archivo, "BT", "mochila_chica_n90_no_conflict.txt");
    ejecucion(archivo, "DP", "mochila_chica_n90_no_conflict.txt");

    //ejecucion(archivo, "FB", "mochila_chica_n100_no_conflict.txt");
    //ejecucion(archivo, "BT", "mochila_chica_n100_no_conflict.txt");
    ejecucion(archivo, "DP", "mochila_chica_n100_no_conflict.txt");
    

    // === Instancias mochila apretada ===
    ejecucion(archivo, "FB", "mochila_apretada_n10_no_conflict.txt");
    ejecucion(archivo, "BT", "mochila_apretada_n10_no_conflict.txt");
    ejecucion(archivo, "DP", "mochila_apretada_n10_no_conflict.txt");

    ejecucion(archivo, "FB", "mochila_apretada_n20_no_conflict.txt");
    ejecucion(archivo, "BT", "mochila_apretada_n20_no_conflict.txt");
    ejecucion(archivo, "DP", "mochila_apretada_n20_no_conflict.txt");

    ejecucion(archivo, "FB", "mochila_apretada_n30_no_conflict.txt");
    ejecucion(archivo, "BT", "mochila_apretada_n30_no_conflict.txt");
    ejecucion(archivo, "DP", "mochila_apretada_n30_no_conflict.txt");

    //ejecucion(archivo, "FB", "mochila_apretada_n40_no_conflict.txt");
    ejecucion(archivo, "BT", "mochila_apretada_n40_no_conflict.txt");
    ejecucion(archivo, "DP", "mochila_apretada_n40_no_conflict.txt");

    //ejecucion(archivo, "FB", "mochila_apretada_n50_no_conflict.txt");
    ejecucion(archivo, "BT", "mochila_apretada_n50_no_conflict.txt");
    ejecucion(archivo, "DP", "mochila_apretada_n50_no_conflict.txt");

    //ejecucion(archivo, "FB", "mochila_apretada_n60_no_conflict.txt");
    ejecucion(archivo, "BT", "mochila_apretada_n60_no_conflict.txt");
    ejecucion(archivo, "DP", "mochila_apretada_n60_no_conflict.txt");

    //ejecucion(archivo, "FB", "mochila_apretada_n70_no_conflict.txt");
    ejecucion(archivo, "BT", "mochila_apretada_n70_no_conflict.txt");
    ejecucion(archivo, "DP", "mochila_apretada_n70_no_conflict.txt");

    //ejecucion(archivo, "FB", "mochila_apretada_n80_no_conflict.txt");
    ejecucion(archivo, "BT", "mochila_apretada_n80_no_conflict.txt");
    ejecucion(archivo, "DP", "mochila_apretada_n80_no_conflict.txt");

    // === Instancias mochila con conflicto ===
    ejecucion(archivo, "FB", "costo_peso_correlaciona_n20_cycle.txt");
    ejecucion(archivo, "BT", "costo_peso_correlaciona_n20_cycle.txt");
    ejecucion(archivo, "FB", "costo_peso_correlaciona_n20_star.txt");
    ejecucion(archivo, "BT", "costo_peso_correlaciona_n20_star.txt");

    ejecucion(archivo, "FB", "costo_peso_correlaciona_n22_cycle.txt");
    ejecucion(archivo, "BT", "costo_peso_correlaciona_n22_cycle.txt");
    ejecucion(archivo, "FB", "costo_peso_correlaciona_n22_star.txt");
    ejecucion(archivo, "BT", "costo_peso_correlaciona_n22_star.txt");

    ejecucion(archivo, "FB", "costo_peso_correlaciona_n24_cycle.txt");
    ejecucion(archivo, "BT", "costo_peso_correlaciona_n24_cycle.txt");
    ejecucion(archivo, "FB", "costo_peso_correlaciona_n24_star.txt");
    ejecucion(archivo, "BT", "costo_peso_correlaciona_n24_star.txt");

    ejecucion(archivo, "FB", "costo_peso_correlaciona_n26_cycle.txt");
    ejecucion(archivo, "BT", "costo_peso_correlaciona_n26_cycle.txt");
    ejecucion(archivo, "FB", "costo_peso_correlaciona_n26_star.txt");
    ejecucion(archivo, "BT", "costo_peso_correlaciona_n26_star.txt");

    ejecucion(archivo, "FB", "costo_peso_correlaciona_n28_cycle.txt");
    ejecucion(archivo, "BT", "costo_peso_correlaciona_n28_cycle.txt");
    ejecucion(archivo, "FB", "costo_peso_correlaciona_n28_star.txt");
    ejecucion(archivo, "BT", "costo_peso_correlaciona_n28_star.txt");

    ejecucion(archivo, "FB", "costo_peso_correlaciona_n30_cycle.txt"); 
    ejecucion(archivo, "BT", "costo_peso_correlaciona_n30_cycle.txt");
    ejecucion(archivo, "FB", "costo_peso_correlaciona_n30_star.txt");
    ejecucion(archivo, "BT", "costo_peso_correlaciona_n30_star.txt");

    //ejecucion(archivo, "FB", "costo_peso_correlaciona_n32_cycle.txt");
    ejecucion(archivo, "BT", "costo_peso_correlaciona_n32_cycle.txt");
    //ejecucion(archivo, "FB", "costo_peso_correlaciona_n32_star.txt");
    ejecucion(archivo, "BT", "costo_peso_correlaciona_n32_star.txt");

    //ejecucion(archivo, "FB", "costo_peso_correlaciona_n34_cycle.txt");
    ejecucion(archivo, "BT", "costo_peso_correlaciona_n34_cycle.txt");
    //ejecucion(archivo, "FB", "costo_peso_correlaciona_n34_star.txt");
    ejecucion(archivo, "BT", "costo_peso_correlaciona_n34_star.txt");

    //ejecucion(archivo, "FB", "costo_peso_correlaciona_n36_cycle.txt");
    ejecucion(archivo, "BT", "costo_peso_correlaciona_n36_cycle.txt");
    //ejecucion(archivo, "FB", "costo_peso_correlaciona_n36_star.txt");
    ejecucion(archivo, "BT", "costo_peso_correlaciona_n36_star.txt");

    //ejecucion(archivo, "FB", "costo_peso_correlaciona_n38_cycle.txt");
    ejecucion(archivo, "BT", "costo_peso_correlaciona_n38_cycle.txt");
    //ejecucion(archivo, "FB", "costo_peso_correlaciona_n38_star.txt");
    ejecucion(archivo, "BT", "costo_peso_correlaciona_n38_star.txt"); 

    //ejecucion(archivo, "FB", "costo_peso_correlaciona_n40_cycle.txt");
    ejecucion(archivo, "BT", "costo_peso_correlaciona_n40_cycle.txt");
    //ejecucion(archivo, "FB", "costo_peso_correlaciona_n40_star.txt");
    //ejecucion(archivo, "BT", "costo_peso_correlaciona_n40_star.txt");

    archivo.close();
    return 0;
}


