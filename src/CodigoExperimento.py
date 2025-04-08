import time
import csv
import os

from BTDPKP01 import (
    InstanciaMochila,
    mochila_backtracking_con_conflictos,
    mochila_dp
)

def ejecucion(archivo_csv, algoritmo, archivo_instancia):
    instancia = InstanciaMochila(archivo_instancia)

    start = time.time()

    if algoritmo == "BT":
        solucion = mochila_backtracking_con_conflictos(instancia)
    elif algoritmo == "PD":
        if instancia.conflictos is not None:
            print(f"PD no se ejecuta con conflictos: {archivo_instancia}")
            return
        solucion = mochila_dp(instancia)
    else:
        print(f"Algoritmo no reconocido: {algoritmo}")
        return

    elapsed = time.time() - start
    indices = solucion.indices_seleccionados()
    indices_str = "[" + ", ".join(map(str, indices)) + "]"


    # Escribir en el archivo CSV
    archivo_csv.writerow([
        algoritmo,
        f"{elapsed:.6f}",
        archivo_instancia,
        indices_str
    ])

    # Mostrar por consola
    print(f"{algoritmo},{elapsed:.6f},{archivo_instancia},{indices}")


if __name__ == "__main__":
    nombre_archivo_salida = "resultado_experimento.csv"
    with open(nombre_archivo_salida, mode='w', newline="") as archivo:
        csv_writer = csv.writer(archivo)
        csv_writer.writerow(["Algoritmo", "Tiempo", "Instancia", "Items Seleccionados"])
        
        # Lista de ejecuciones
        instancias = [
            # Mochila chica
            "mochila_chica_n10_no_conflict.txt",
            "mochila_chica_n20_no_conflict.txt",

            # Mochila apretada
            "mochila_apretada_n10_no_conflict.txt",
            "mochila_apretada_n20_no_conflict.txt",
            "mochila_apretada_n30_no_conflict.txt",
            "mochila_apretada_n40_no_conflict.txt",
            "mochila_apretada_n50_no_conflict.txt",

            # Mochila con conflictos
            "costo_peso_correlaciona_n20_cycle.txt",
            "costo_peso_correlaciona_n20_star.txt",
            "costo_peso_correlaciona_n22_cycle.txt",
            "costo_peso_correlaciona_n22_star.txt",
        ]
        
        print("Directorio actual:", os.getcwd())


        for archivo_instancia in instancias:
            if not os.path.exists(archivo_instancia):
                print(f"Archivo no encontrado: {archivo_instancia}")
                continue

            ejecucion(csv_writer, "BT", archivo_instancia)
            ejecucion(csv_writer, "PD", archivo_instancia)  # Solo corre si no hay conflictos
