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
    Solution solve();
    vector<vector<int>> valor_optimo();
};

#endif // DYNAMICPROGRAMMINGKP01_H