// BacktrackingKP01.cpp
#include "BruteForceKP01wCG.h"

BruteForceKP01wCG::BruteForceKP01wCG() {
    _B = Solution(_in->_cantidad_itemss);  // Inicializamos la mejor solución como vacía
}


Solution BruteForceKP01wCG::solve(const KP01withCGInstance& instance) {
    // Creamos una solución vacía para empezar
    Solution bestSolution(instance->_cantidad_itemss);
    _in = instance;  // Asignar la instancia del problema a la variable interna

    // Empezamos la recursión desde el primer ítem
    Mochila(bestSolution, 0);

    return bestSolution;  // Retornamos la mejor solución encontrada
}

// Método recursivo de fuerza bruta para explorar todas las combinaciones posibles
void BruteForceKP01wCG::Mochila(Solution& S, int k) {
    if (k == _in->_cantidad_itemss) {
        // Si hemos considerado todos los ítems, evaluamos la solución
        if (S.getWeight() <= _in.getCapacity() && S.getBenefit() > _B.getBenefit()) {
            _B = S;  // Actualizamos la mejor solución con el objeto Solution S
        }
    } else {
        // No tomar el ítem k si no tiene conflictos con los ítems ya seleccionados
        if (!_in.hasConflict(S, k)) {  // Suponiendo que in tiene un método hasConflict()
            // Tomar el ítem k (S[k] = 1)
            S.addItem(k, _in.getWeight(k), _in.getProfit(k));  // Agregamos el ítem k a la solución
            Mochila(S, k + 1);  // Recursión con el ítem incluido
            S.removeItem(k);  // Deshacer la inclusión del ítem k
        }

        // No tomar el ítem k (S[k] = 0)
        Mochila(S, k + 1);  // Recursión con el ítem no incluido
    }
}
