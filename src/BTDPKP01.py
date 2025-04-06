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

def mochila_backtracking_con_conflictos(instancia):
    mejor_solucion = SolucionMochila()

    def es_compatible(item, items_seleccionados):
        if instancia.conflictos is None:
            return True
        for otro in items_seleccionados:
            if instancia.conflictos.hay_conflicto(item.indice, otro.indice):
                return False
        return True

    def backtrack(i, solucion_actual):
        nonlocal mejor_solucion
        if i == len(instancia.items):
            if solucion_actual.total_beneficio > mejor_solucion.total_beneficio:
                mejor_solucion = SolucionMochila()
                mejor_solucion.items = solucion_actual.items.copy()
                mejor_solucion.total_peso = solucion_actual.total_peso
                mejor_solucion.total_beneficio = solucion_actual.total_beneficio
            return

        item = instancia.items[i]

        # Opción 1: tomar el ítem si cabe y no hay conflicto
        if (
            solucion_actual.total_peso + item.peso <= instancia.capacidad
            and es_compatible(item, solucion_actual.items)
        ):
            solucion_actual.agregar(item)
            backtrack(i + 1, solucion_actual)
            solucion_actual.remover(item)

        # Opción 2: no tomarlo
        backtrack(i + 1, solucion_actual)

    backtrack(0, SolucionMochila())
    return mejor_solucion

def mochila_dp(instancia):
    n = instancia.n
    C = instancia.capacidad
    dp = [[0] * (C + 1) for _ in range(n + 1)]

    for i in range(1, n + 1):
        peso = instancia.items[i - 1].peso
        beneficio = instancia.items[i - 1].beneficio
        for c in range(C + 1):
            if peso <= c:
                dp[i][c] = max(dp[i - 1][c], dp[i - 1][c - peso] + beneficio)
            else:
                dp[i][c] = dp[i - 1][c]

    # reconstrucción de la solución
    c = C
    solucion = SolucionMochila()
    for i in range(n, 0, -1):
        if dp[i][c] != dp[i - 1][c]:
            item = instancia.items[i - 1]
            solucion.agregar(item)
            c -= item.peso

    return solucion

if __name__ == "__main__":
    instancia = InstanciaMochila("costo_peso_correlaciona_n20_cycle.txt")

    print("Backtracking con conflictos:")
    print(mochila_backtracking_con_conflictos(instancia))

    if instancia.conflictos is None:
        print("\nProgramación Dinámica (sin conflictos):")
        print(mochila_dp(instancia))
    else:
        print("\nProgramación Dinámica no ejecutada porque hay conflictos entre ítems.")
