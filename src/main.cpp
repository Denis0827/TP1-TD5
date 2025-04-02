// main.cpp
#include "KP01withCGInstance.h"
#include "Solution.h"
#include "DynamicProgrammingKP01.h"
#include "BacktrackingKP01wCG.h"
#include "BruteForceKP01wCG.h"

#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
    if (argc < 3) {
        cerr << "Usage: " << argv[0] << " <algorithm> <instance>\n";
        cerr << "Available algorithms: dp (Dynamic Programming), bt (Backtracking), bf (Brute Force)\n";
        return 1;
    }

    string algorithm = argv[1];
    string instance_name = argv[2];

    KP01withCGInstance instance;


    cout << instance.getNumItems() << endl;
    cout << instance.getCapacity() << endl;

    Solution solution = Solution();

    if (algorithm == "dp") {
        DynamicProgrammingKP01 solver_dp;
        solution = solver_dp.solve(instance);
    } else if (algorithm == "bt") {
        BacktrackingKP01wCG solver_bt;
        solution = solver_bt.solve(instance);
    } else if (algorithm == "bf") {
        BruteForceKP01wCG solver_bf;
        solution = solver_bf.solve(instance);
    } else {
        cerr << "Unknown algorithm: " << algorithm << "\n";
        return 1;
    }

    // Imprimir resultados sobre la solucion


    return 0;
}
