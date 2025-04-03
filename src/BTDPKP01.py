class Item:
    def __init__(self, peso, beneficio):
        self.peso = peso
        self.beneficio = beneficio

    def __repr__(self):
        return f"Item(peso={self.peso}, beneficio={self.beneficio})"


class InstanciaMochila:
    def __init__(self, archivo):
        with open(archivo, 'r') as f:
            lineas = [line.strip() for line in f.readlines()]

        self.n = int(lineas[0])
        self.capacidad = int(lineas[1])
        pesos = list(map(int, lineas[2].split()))
        beneficios = list(map(int, lineas[3].split()))
        self.items = [Item(p, b) for p, b in zip(pesos, beneficios)]

    def __repr__(self):
        return f"InstanciaMochila(n={self.n}, capacidad={self.capacidad}, items={self.items})"


class SolucionMochila:
    def __init__(self):
        self.items_seleccionados = []
        self.beneficio_total = 0
        self.peso_total = 0

    def agregar_item(self, item):
        self.items_seleccionados.append(item)
        self.beneficio_total += item.beneficio
        self.peso_total += item.peso

    def __repr__(self):
        return (f"SolucionMochila(peso_total={self.peso_total}, beneficio_total={self.beneficio_total}, "
                f"items_seleccionados={self.items_seleccionados})")


# Backtracking

def mochila_backtracking(instancia):
    mejor_solucion = SolucionMochila()

    def backtrack(i, solucion_actual):
        nonlocal mejor_solucion

        if i == instancia.n:
            if solucion_actual.beneficio_total > mejor_solucion.beneficio_total:
                mejor_solucion = SolucionMochila()
                mejor_solucion.items_seleccionados = solucion_actual.items_seleccionados[:]
                mejor_solucion.beneficio_total = solucion_actual.beneficio_total
                mejor_solucion.peso_total = solucion_actual.peso_total
            return

        # Omitir el ítem i
        backtrack(i + 1, solucion_actual)

        # Incluir el ítem i si cabe
        item = instancia.items[i]
        if solucion_actual.peso_total + item.peso <= instancia.capacidad:
            solucion_actual.agregar_item(item)
            backtrack(i + 1, solucion_actual)
            # Deshacer
            solucion_actual.items_seleccionados.pop()
            solucion_actual.beneficio_total -= item.beneficio
            solucion_actual.peso_total -= item.peso

    backtrack(0, SolucionMochila())
    return mejor_solucion


# Programación Dinámica

def mochila_dinamica(instancia):
    n = instancia.n
    C = instancia.capacidad
    dp = [[0] * (C + 1) for _ in range(n + 1)]

    for i in range(1, n + 1):
        for w in range(C + 1):
            if instancia.items[i - 1].peso <= w:
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - instancia.items[i - 1].peso] + instancia.items[i - 1].beneficio)
            else:
                dp[i][w] = dp[i - 1][w]

    # reconstruir solución
    solucion = SolucionMochila()
    w = C
    for i in range(n, 0, -1):
        if dp[i][w] != dp[i - 1][w]:
            item = instancia.items[i - 1]
            solucion.agregar_item(item)
            w -= item.peso

    return solucion


# Ejemplo de uso:
instancia = InstanciaMochila("mochila_chica_n10_no_conflict.txt")
print(instancia)
solucion_bt = mochila_backtracking(instancia)
print("Backtracking:", solucion_bt)
solucion_dp = mochila_dinamica(instancia)
print("Programación Dinámica:", solucion_dp)

