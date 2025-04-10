# Clase que representa un ítem con peso, beneficio e índice.
class Item:
    def __init__(self, peso, beneficio, indice): 
        self.peso = peso  # O(1)
        self.beneficio = beneficio  # O(1)
        self.indice = indice  # O(1)

    def __repr__(self):  
        return f"Item: {self.indice}, Peso: {self.peso}, Beneficio: {self.beneficio}"  # O(1)


# Clase que modela el grafo de conflictos como una matriz booleana simétrica.
class MatrizConflictos:
    def __init__(self, cantidad_items): 
        self.n = cantidad_items  # O(1)
        self.matriz = [[False] * self.n for _ in range(self.n)]  # O(N^2)
        # Complejidad total: O(N^2)

    def agregar_conflicto(self, i, j):  
        self.matriz[i][j] = True  # O(1)
        self.matriz[j][i] = True  # O(1)
        # Complejidad total: O(1)

    def hay_conflicto(self, i, j): 
        return self.matriz[i][j]  # O(1)
        # Complejidad total: O(1)


# Clase que representa una instancia del problema de la mochila con posibles conflictos.
class InstanciaMochila:
    def __init__(self, archivo): 
        with open(archivo, 'r') as f:  # O(N)
            self.n = int(f.readline())  # O(1)
            self.capacidad = int(f.readline())  # O(1)
            pesos = list(map(int, f.readline().split()))  # O(N)
            beneficios = list(map(int, f.readline().split()))  # O(N)
            linea = f.readline().strip()  # O(1)

            self.items = [Item(pesos[i], beneficios[i], i) for i in range(self.n)]  # O(N)

            if linea == '0':  # O(1)
                self.conflictos = None  # O(1)
            else:
                cantidad_conflictos = int(linea)  # O(1)
                self.conflictos = MatrizConflictos(self.n)  # O(N^2)
                for _ in range(cantidad_conflictos):  # O(C)
                    i, j = map(int, f.readline().split())  # O(1)
                    self.conflictos.agregar_conflicto(i, j)  # O(1)
        # Complejidad total: O(N^2 + C)


# Clase que representa una solución parcial o completa de la mochila.
class SolucionMochila:
    def __init__(self):  
        self.items = []  # O(1)
        self.total_peso = 0  # O(1)
        self.total_beneficio = 0  # O(1)
        # Complejidad total: O(1)

    def agregar(self, item):  
        self.items.append(item)  # O(1)
        self.total_peso += item.peso  # O(1)
        self.total_beneficio += item.beneficio  # O(1)
        # Complejidad total: O(1)

    def remover(self, item):  
        self.items.remove(item)  # O(N)
        self.total_peso -= item.peso  # O(1)
        self.total_beneficio -= item.beneficio  # O(1)
        # Complejidad total: O(N)

    def indices_seleccionados(self):  
        return [item.indice for item in self.items]  # O(N)
        # Complejidad total: O(N)

    def __repr__(self): 
        return "\n".join(
            [f"Item: {item.indice}, Peso: {item.peso}, Beneficio: {item.beneficio}" for item in self.items]  # O(N)
        )



def mochila_backtracking_con_conflictos(instancia):  # O(2^N)
    mejor_solucion = SolucionMochila()  # O(1)

    def es_compatible(item, items_seleccionados):  
        if instancia.conflictos is None:  # O(1)
            return True  # O(1)
        for otro in items_seleccionados:  # O(S)
            if instancia.conflictos.hay_conflicto(item.indice, otro.indice):  # O(1)
                return False  # O(1)
        return True  # O(1)
        # Complejidad total: O(S), con S cantidad de ítems seleccionados
    
    def beneficio_restante(instancia, k, n): 
        suma = 0  # O(1)
        for i in range(k, n):  # O(N)
            suma += instancia.items[i].beneficio  # O(1)
        return suma  # O(1)
        # Complejidad total: O(N)

    def backtrack(i, solucion_actual):  
        nonlocal mejor_solucion  # O(1)
        if i == len(instancia.items):  # O(1)
            if (solucion_actual.total_beneficio > mejor_solucion.total_beneficio
                and solucion_actual.total_peso <= instancia.capacidad):  # O(1)
                mejor_solucion = SolucionMochila()  # O(1)
                mejor_solucion.items = solucion_actual.items.copy()  # O(N)
                mejor_solucion.total_peso = solucion_actual.total_peso  # O(1)
                mejor_solucion.total_beneficio = solucion_actual.total_beneficio  # O(1)
            return  # O(1)

        item = instancia.items[i]  # O(1)

        # Opción 1: tomar el ítem si cabe y no hay conflicto
        if (solucion_actual.total_beneficio + beneficio_restante(instancia, i, instancia.n) > mejor_solucion.total_beneficio # O(N)
            and solucion_actual.total_peso + item.peso <= instancia.capacidad # O(1)
            and es_compatible(item, solucion_actual.items)):  # O(S)
            solucion_actual.agregar(item)  # O(1)
            backtrack(i + 1, solucion_actual)  # O(2^N)
            solucion_actual.remover(item)  # O(N) (por el uso de `list.remove()`)

        # Opción 2: no tomarlo
        backtrack(i + 1, solucion_actual)  # O(2^N)

    backtrack(0, SolucionMochila())  # O(2^N)
    return mejor_solucion  # O(1)
    # Complejidad total: O(2^N*(N + S))


def mochila_dp(instancia): 
    n = instancia.n  # O(1)
    C = instancia.capacidad  # O(1)
    dp = [[0] * (C + 1) for _ in range(n + 1)]  # O(N*C)

    for i in range(1, n + 1):  # O(N)
        peso = instancia.items[i - 1].peso  # O(1)
        beneficio = instancia.items[i - 1].beneficio  # O(1)
        for c in range(C + 1):  # O(C)
            if peso <= c:  # O(1)
                dp[i][c] = max(dp[i - 1][c], dp[i - 1][c - peso] + beneficio)  # O(1)
            else:
                dp[i][c] = dp[i - 1][c]  # O(1)

    # reconstrucción de la solución
    c = C  # O(1)
    solucion = SolucionMochila()  # O(1)
    for i in range(n, 0, -1):  # O(N)
        if dp[i][c] != dp[i - 1][c]:  # O(1)
            item = instancia.items[i - 1]  # O(1)
            solucion.agregar(item)  # O(1)
            c -= item.peso  # O(1)
    
    solucion.items.reverse()  # O(N)
    return solucion  # O(1)
    # Complejidad total: O(N*C)

if __name__ == "__main__":
    instancia = InstanciaMochila("instances/costo_peso_correlaciona_n20_cycle.txt")

    print("Backtracking con conflictos:")
    print(mochila_backtracking_con_conflictos(instancia))

if __name__ == "__main__":
    instancia = InstanciaMochila("instances/costo_peso_correlaciona_n20_cycle.txt")  # O(N + C)

    print("Backtracking con conflictos:")  # O(1)
    print(mochila_backtracking_con_conflictos(instancia))  # O(2^N)

    if instancia.conflictos is None:  # O(1)
        print("\nProgramación Dinámica (sin conflictos):")  # O(1)
        print(mochila_dp(instancia))  # O(N*C)
    else:
        print("\nProgramación Dinámica no ejecutada porque hay conflictos entre ítems.")  # O(1)

