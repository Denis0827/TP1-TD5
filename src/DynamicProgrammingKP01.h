// DynamicProgrammingKP01.h
#ifndef DYNAMICPROGRAMMINGKP01_H
#define DYNAMICPROGRAMMINGKP01_H

#include "Solution.h"
#include "KP01withCGInstance.h"

class DynamicProgrammingKP01 {
private:
    KP01withCGInstance _instancia;
    Solution _bestSol;

public:
    DynamicProgrammingKP01(const string& archivo);
    vector<vector<int>> matriz_optima();
    Solution solve();
};

#endif // DYNAMICPROGRAMMINGKP01_H