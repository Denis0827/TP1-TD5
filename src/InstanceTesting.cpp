#include "KP01withCGInstance.h"
using namespace std;

TEST(KP01withCGInstanceTests, testSetWeightProfitAndGetters) {
    KP01withCGInstance instancia;
    
    // Setear valores manualmente
    instancia.cargar_datos("test_data/test1.txt");

    ASSERT_EQ(instancia.getNumItems(), 3);
    ASSERT_EQ(instancia.getCapacity(), 10);
    ASSERT_EQ(instancia.getWeight(0), 2);
    ASSERT_EQ(instancia.getProfit(0), 3);
    ASSERT_EQ(instancia.getWeight(1), 4);
    ASSERT_EQ(instancia.getProfit(1), 6);
    ASSERT_EQ(instancia.getWeightTotal(), 9); // 2+4+3
    ASSERT_EQ(instancia.getProfitTotal(), 13); // 3+6+4
}

TEST(KP01withCGInstanceTests, testHasConflict) {
    KP01withCGInstance instancia;
    instancia.cargar_datos("test_data/test2.txt");

    vector<int> solucion = {1}; // Item 0 en conflicto con 1
    ASSERT_TRUE(instancia.hasConflict(solucion, 0));
    
    solucion = {2};
    ASSERT_FALSE(instancia.hasConflict(solucion, 0));
}
