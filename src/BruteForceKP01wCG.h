// BruteForceKP01wCG.h
#ifndef BRUTEFORCEKP01WCG_H
#define BRUTEFORCEKP01WCG_H

#include "Solution.h"
#include "KP01withCGInstance.h"

class BruteForceKP01wCG {
private:
    KP01withCGInstance in;



public:
    BruteForceKP01wCG(const string& archivo);
    Solution solve(const KP01withCGInstance& instance);
};

#endif // BRUTEFORCEKP01WCG_H