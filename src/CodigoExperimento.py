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
    nombre_archivo_salida = "resultadoExperimentoPython.csv"
    with open(nombre_archivo_salida, mode='w', newline="") as archivo:
        csv_writer = csv.writer(archivo)
        csv_writer.writerow(["Algoritmo", "Tiempo", "Instancia", "Items Seleccionados"])
    
        ejecucion(csv_writer, "BT", "mochila_chica_n10_no_conflict.txt")
        ejecucion(csv_writer, "PD", "mochila_chica_n10_no_conflict.txt")  
        ejecucion(csv_writer, "BT", "mochila_chica_n20_no_conflict.txt")
        ejecucion(csv_writer, "PD", "mochila_chica_n20_no_conflict.txt")  
        ejecucion(csv_writer, "BT", "mochila_chica_n30_no_conflict.txt")
        ejecucion(csv_writer, "PD", "mochila_chica_n30_no_conflict.txt")  
        #ejecucion(csv_writer, "BT", "mochila_chica_n40_no_conflict.txt")
        ejecucion(csv_writer, "PD", "mochila_chica_n40_no_conflict.txt")  
        #ejecucion(csv_writer, "BT", "mochila_chica_n50_no_conflict.txt")
        ejecucion(csv_writer, "PD", "mochila_chica_n50_no_conflict.txt")  
        #ejecucion(csv_writer, "BT", "mochila_chica_n60_no_conflict.txt")
        ejecucion(csv_writer, "PD", "mochila_chica_n60_no_conflict.txt")  
        #ejecucion(csv_writer, "BT", "mochila_chica_n70_no_conflict.txt")
        ejecucion(csv_writer, "PD", "mochila_chica_n70_no_conflict.txt")  
        #ejecucion(csv_writer, "BT", "mochila_chica_n80_no_conflict.txt")
        ejecucion(csv_writer, "PD", "mochila_chica_n80_no_conflict.txt")  
        #ejecucion(csv_writer, "BT", "mochila_chica_n90_no_conflict.txt")
        #ejecucion(csv_writer, "PD", "mochila_chica_n90_no_conflict.txt")  
        #ejecucion(csv_writer, "BT", "mochila_chica_n100_no_conflict.txt")
        #ejecucion(csv_writer, "PD", "mochila_chica_n100_no_conflict.txt")  
        
        ejecucion(csv_writer, "BT", "mochila_apretada_n10_no_conflict.txt")
        ejecucion(csv_writer, "PD", "mochila_apretada_n10_no_conflict.txt")  
        ejecucion(csv_writer, "BT", "mochila_apretada_n20_no_conflict.txt")
        ejecucion(csv_writer, "PD", "mochila_apretada_n20_no_conflict.txt")  
        ejecucion(csv_writer, "BT", "mochila_apretada_n30_no_conflict.txt")
        ejecucion(csv_writer, "PD", "mochila_apretada_n30_no_conflict.txt")  
        ejecucion(csv_writer, "BT", "mochila_apretada_n40_no_conflict.txt")
        ejecucion(csv_writer, "PD", "mochila_apretada_n40_no_conflict.txt")  
        ejecucion(csv_writer, "BT", "mochila_apretada_n50_no_conflict.txt")
        ejecucion(csv_writer, "PD", "mochila_apretada_n50_no_conflict.txt")  
        ejecucion(csv_writer, "BT", "mochila_apretada_n60_no_conflict.txt")
        ejecucion(csv_writer, "PD", "mochila_apretada_n60_no_conflict.txt")  
        ejecucion(csv_writer, "BT", "mochila_apretada_n70_no_conflict.txt")
        ejecucion(csv_writer, "PD", "mochila_apretada_n70_no_conflict.txt")  
        ejecucion(csv_writer, "BT", "mochila_apretada_n80_no_conflict.txt")
        ejecucion(csv_writer, "PD", "mochila_apretada_n80_no_conflict.txt") 
        
        ejecucion(csv_writer, "BT", "costo_peso_correlaciona_n20_cycle.txt")
        ejecucion(csv_writer, "BT", "costo_peso_correlaciona_n22_cycle.txt")
        ejecucion(csv_writer, "BT", "costo_peso_correlaciona_n24_cycle.txt")
        ejecucion(csv_writer, "BT", "costo_peso_correlaciona_n26_cycle.txt")
        ejecucion(csv_writer, "BT", "costo_peso_correlaciona_n28_cycle.txt")
        ejecucion(csv_writer, "BT", "costo_peso_correlaciona_n30_cycle.txt")
        ejecucion(csv_writer, "BT", "costo_peso_correlaciona_n32_cycle.txt")
        ejecucion(csv_writer, "BT", "costo_peso_correlaciona_n34_cycle.txt")
        ejecucion(csv_writer, "BT", "costo_peso_correlaciona_n36_cycle.txt")
        ejecucion(csv_writer, "BT", "costo_peso_correlaciona_n38_cycle.txt")
        ejecucion(csv_writer, "BT", "costo_peso_correlaciona_n40_cycle.txt")
        
        ejecucion(csv_writer, "BT", "costo_peso_correlaciona_n20_star.txt")
        ejecucion(csv_writer, "BT", "costo_peso_correlaciona_n22_star.txt")
        ejecucion(csv_writer, "BT", "costo_peso_correlaciona_n24_star.txt")
        ejecucion(csv_writer, "BT", "costo_peso_correlaciona_n26_star.txt")
        ejecucion(csv_writer, "BT", "costo_peso_correlaciona_n28_star.txt")
        ejecucion(csv_writer, "BT", "costo_peso_correlaciona_n30_star.txt")
        #ejecucion(csv_writer, "BT", "costo_peso_correlaciona_n32_star.txt")
        #ejecucion(csv_writer, "BT", "costo_peso_correlaciona_n34_star.txt")
        #ejecucion(csv_writer, "BT", "costo_peso_correlaciona_n36_star.txt")
        #ejecucion(csv_writer, "BT", "costo_peso_correlaciona_n38_star.txt")
        #ejecucion(csv_writer, "BT", "costo_peso_correlaciona_n40_star.txt")