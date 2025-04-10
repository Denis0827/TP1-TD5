
class Item:
    def __init__(self, peso, beneficio, indice):
        self.peso = peso
        self.beneficio = beneficio
        self.indice = indice

    def __repr__(self):
        return f"Item: {self.indice}, Peso: {self.peso}, Beneficio: {self.beneficio}"


class MatrizConflictos:
    def __init__(self, cantidad_items):
        self.n = cantidad_items
        self.matriz = [[False] * self.n for _ in range(self.n)]

    def agregar_conflicto(self, i, j):
        self.matriz[i][j] = True
        self.matriz[j][i] = True  # no dirigido

    def hay_conflicto(self, i, j):
        return self.matriz[i][j]


class InstanciaMochila:
    def __init__(self, archivo):
        with open(archivo, 'r') as f:
            self.n = int(f.readline())
            self.capacidad = int(f.readline())
            pesos = list(map(int, f.readline().split()))
            beneficios = list(map(int, f.readline().split()))
            linea = f.readline().strip()

            self.items = [Item(pesos[i], beneficios[i], i) for i in range(self.n)]

            if linea == '0':
                self.conflictos = None
            else:
                cantidad_conflictos = int(linea)
                self.conflictos = MatrizConflictos(self.n)
                for _ in range(cantidad_conflictos):
                    i, j = map(int, f.readline().split())
                    self.conflictos.agregar_conflicto(i, j)


class SolucionMochila:
    def __init__(self):
        self.items = []
        self.total_peso = 0
        self.total_beneficio = 0

    def agregar(self, item):
        self.items.append(item)
        self.total_peso += item.peso
        self.total_beneficio += item.beneficio

    def remover(self, item):
        self.items.remove(item)
        self.total_peso -= item.peso
        self.total_beneficio -= item.beneficio

    def indices_seleccionados(self):
        return [item.indice for item in self.items]

    def __repr__(self):
        return "\n".join(
            [f"Item: {item.indice}, Peso: {item.peso}, Beneficio: {item.beneficio}" for item in self.items]
        )

def mochila_backtracking_con_conflictos(instancia):  # O(2^N)
    mejor_solucion = SolucionMochila()  # O(1)

    def es_compatible(item, items_seleccionados):  # O(S), con S cantidad de ítems seleccionados
        if instancia.conflictos is None:  # O(1)
            return True  # O(1)
        for otro in items_seleccionados:  # O(S)
            if instancia.conflictos.hay_conflicto(item.indice, otro.indice):  # O(1)
                return False  # O(1)
        return True  # O(1)
    
    def beneficio_restante(instancia, k, n):  # O(N)
        suma = 0  # O(1)
        for i in range(k, n):  # O(N)
            suma += instancia.items[i].beneficio  # O(1)
        return suma  # O(1)

    def backtrack(i, solucion_actual):  # O(2^N) en el peor caso
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
        if (solucion_actual.total_beneficio + beneficio_restante(instancia, i, instancia.n) > mejor_solucion.total_beneficio
            and solucion_actual.total_peso + item.peso <= instancia.capacidad
            and es_compatible(item, solucion_actual.items)):  # O(N)
            solucion_actual.agregar(item)  # O(1)
            backtrack(i + 1, solucion_actual)  # O(2^N)
            solucion_actual.remover(item)  # O(N) (por el uso de `list.remove()`)

        # Opción 2: no tomarlo
        backtrack(i + 1, solucion_actual)  # O(2^N)

    backtrack(0, SolucionMochila())  # O(2^N)
    return mejor_solucion  # O(1)


def mochila_dp(instancia):  # O(N*C)
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

if __name__ == "__main__":
    instancia = InstanciaMochila("costo_peso_correlaciona_n20_cycle.txt")

    print("Backtracking con conflictos:")
    print(mochila_backtracking_con_conflictos(instancia))

if __name__ == "__main__":
    instancia = InstanciaMochila("costo_peso_correlaciona_n20_cycle.txt")  # O(N + C)

    print("Backtracking con conflictos:")  # O(1)
    print(mochila_backtracking_con_conflictos(instancia))  # O(2^N)

    if instancia.conflictos is None:  # O(1)
        print("\nProgramación Dinámica (sin conflictos):")  # O(1)
        print(mochila_dp(instancia))  # O(N*C)
    else:
        print("\nProgramación Dinámica no ejecutada porque hay conflictos entre ítems.")  # O(1)

