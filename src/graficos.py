import pandas as pd
import matplotlib.pyplot as plt
import os

print("[INFO] Ruta actual:", os.getcwd())

def cargar_csv_con_mensaje(ruta):
    try:
        df = pd.read_csv(ruta, sep=',')
        df.columns = df.columns.str.strip()
        print(f"[OK] Archivo leído: {ruta}")
        return df
    except FileNotFoundError:
        print(f"[ERROR] No se encontró el archivo en la ruta: {ruta}")
        return None

def extraer_n(instancia):
    for part in instancia.split('_'):
        if part.startswith('n') and part[1:].isdigit():
            return int(part[1:])
    return -1

# ===================== EXPERIMENTO 2 =====================
archivo_bt_cpp_exp2 = "src/experimento2_btc++.csv"
archivo_bt_python_exp2 = "src/experimento1_btpython.csv"

df_bt_cpp_exp2 = cargar_csv_con_mensaje(archivo_bt_cpp_exp2)
df_bt_py_exp2 = cargar_csv_con_mensaje(archivo_bt_python_exp2)

if df_bt_cpp_exp2 is not None and df_bt_py_exp2 is not None:
    cpp_cycle = df_bt_cpp_exp2[df_bt_cpp_exp2['Instancia'].str.contains("cycle")].copy()
    cpp_star = df_bt_cpp_exp2[df_bt_cpp_exp2['Instancia'].str.contains("star")].copy()
    py_cycle = df_bt_py_exp2[df_bt_py_exp2['Instancia'].str.contains("cycle")].copy()
    py_star = df_bt_py_exp2[df_bt_py_exp2['Instancia'].str.contains("star")].copy()

    for df in [cpp_cycle, cpp_star, py_cycle, py_star]:
        df['n'] = df['Instancia'].apply(extraer_n)
        df.sort_values('n', inplace=True)
        df.reset_index(drop=True, inplace=True)

    # Cycle
    plt.figure(figsize=(10, 6))
    plt.plot(cpp_cycle['n'], cpp_cycle['Tiempo'], marker='o', label='BT C++ - cycle')
    plt.plot(py_cycle['n'], py_cycle['Tiempo'], marker='o', label='BT Python - cycle')
    plt.ylim(bottom=0)  # Escala ajustada
    plt.xlabel('Tama\u00f1o de la instancia (n)')
    plt.ylabel('Tiempo de ejecuci\u00f3n (s)')
    plt.title('Experimento 2 - Cycle: BT Python vs C++')
    plt.legend()
    plt.grid(True)
    plt.tight_layout()
    plt.show()

    # Star
    plt.figure(figsize=(10, 6))
    plt.plot(cpp_star['n'], cpp_star['Tiempo'], marker='o', label='BT C++ - star')
    plt.plot(py_star['n'], py_star['Tiempo'], marker='o', label='BT Python - star')
    plt.xlabel('Tama\u00f1o de la instancia (n)')
    plt.ylabel('Tiempo de ejecuci\u00f3n (s)')
    plt.title('Experimento 2 - Star: BT Python vs C++')
    plt.legend()
    plt.grid(True)
    plt.tight_layout()
    plt.show()

# ===================== EXPERIMENTO 3 =====================
archivo_bt_cpp_exp3 = "src/experimento2_btc++.csv"
archivo_fb_cpp_exp3 = "src/experimento3_bfc++.csv"

df_bt_cpp_exp3 = cargar_csv_con_mensaje(archivo_bt_cpp_exp3)
df_fb_cpp_exp3 = cargar_csv_con_mensaje(archivo_fb_cpp_exp3)

if df_bt_cpp_exp3 is not None and df_fb_cpp_exp3 is not None:
    bt_cycle = df_bt_cpp_exp3[df_bt_cpp_exp3['Instancia'].str.contains("cycle")].copy()
    bt_star = df_bt_cpp_exp3[df_bt_cpp_exp3['Instancia'].str.contains("star")].copy()
    fb_cycle = df_fb_cpp_exp3[df_fb_cpp_exp3['Instancia'].str.contains("cycle")].copy()
    fb_star = df_fb_cpp_exp3[df_fb_cpp_exp3['Instancia'].str.contains("star")].copy()

    for df in [bt_cycle, bt_star, fb_cycle, fb_star]:
        df['n'] = df['Instancia'].apply(extraer_n)
        df.sort_values('n', inplace=True)
        df.reset_index(drop=True, inplace=True)

    # Cycle
    plt.figure(figsize=(10, 6))
    plt.plot(bt_cycle['n'], bt_cycle['Tiempo'], marker='o', label='BT C++ - cycle')
    plt.plot(fb_cycle['n'], fb_cycle['Tiempo'], marker='o', label='FB C++ - cycle')
    plt.xlabel('Tama\u00f1o de la instancia (n)')
    plt.ylabel('Tiempo de ejecuci\u00f3n (s)')
    plt.title('Experimento 3 - Cycle: BT vs Fuerza Bruta (C++)')
    plt.legend()
    plt.grid(True)
    plt.tight_layout()
    plt.show()

    # Star
    plt.figure(figsize=(10, 6))
    plt.plot(bt_star['n'], bt_star['Tiempo'], marker='o', label='BT C++ - star')
    plt.plot(fb_star['n'], fb_star['Tiempo'], marker='o', label='FB C++ - star')
    plt.xlabel('Tama\u00f1o de la instancia (n)')
    plt.ylabel('Tiempo de ejecuci\u00f3n (s)')
    plt.title('Experimento 3 - Star: BT vs Fuerza Bruta (C++)')
    plt.legend()
    plt.grid(True)
    plt.tight_layout()
    plt.show()

# ===================== EXPERIMENTO 4 - C++ =====================
archivo_bt_cpp_exp4 = "src/experimento4_btkp01c++.csv"
archivo_dp_cpp_exp4 = "src/experimento5_dpc++.csv"

df_bt_cpp_exp4 = cargar_csv_con_mensaje(archivo_bt_cpp_exp4)
df_dp_cpp_exp4 = cargar_csv_con_mensaje(archivo_dp_cpp_exp4)

if df_bt_cpp_exp4 is not None and df_dp_cpp_exp4 is not None:
    bt_chica = df_bt_cpp_exp4[df_bt_cpp_exp4['Instancia'].str.contains("mochila_chica")].copy()
    bt_apretada = df_bt_cpp_exp4[df_bt_cpp_exp4['Instancia'].str.contains("mochila_apretada")].copy()
    dp_chica = df_dp_cpp_exp4[df_dp_cpp_exp4['Instancia'].str.contains("mochila_chica")].copy()
    dp_apretada = df_dp_cpp_exp4[df_dp_cpp_exp4['Instancia'].str.contains("mochila_apretada")].copy()

    for df in [bt_chica, bt_apretada, dp_chica, dp_apretada]:
        df['n'] = df['Instancia'].apply(extraer_n)
        df.sort_values('n', inplace=True)
        df.reset_index(drop=True, inplace=True)

    # Mochila chica
    plt.figure(figsize=(10, 6))
    plt.plot(bt_chica['n'], bt_chica['Tiempo'], marker='o', label='BT C++ - Mochila chica')
    plt.plot(dp_chica['n'], dp_chica['Tiempo'], marker='o', label='DP C++ - Mochila chica')
    plt.xlabel('Tama\u00f1o de la instancia (n)')
    plt.ylabel('Tiempo de ejecuci\u00f3n (s)')
    plt.title('Experimento 4 C++ - Mochila chica')
    plt.legend()
    plt.grid(True)
    plt.tight_layout()
    plt.show()

    # Mochila apretada
    plt.figure(figsize=(10, 6))
    plt.plot(bt_apretada['n'], bt_apretada['Tiempo'], marker='o', label='BT C++ - Mochila apretada')
    plt.plot(dp_apretada['n'], dp_apretada['Tiempo'], marker='o', label='DP C++ - Mochila apretada')
    plt.xlabel('Tama\u00f1o de la instancia (n)')
    plt.ylabel('Tiempo de ejecuci\u00f3n (s)')
    plt.title('Experimento 4 C++ - Mochila apretada')
    plt.legend()
    plt.grid(True)
    plt.tight_layout()
    plt.show()

# ===================== EXPERIMENTO 4 - PYTHON =====================
archivo_bt_py_exp4 = "src/experimento6_btkp01python.csv"
archivo_dp_py_exp4 = "src/experimento7_dppython.csv"

df_bt_py_exp4 = cargar_csv_con_mensaje(archivo_bt_py_exp4)
df_dp_py_exp4 = cargar_csv_con_mensaje(archivo_dp_py_exp4)

if df_bt_py_exp4 is not None and df_dp_py_exp4 is not None:
    bt_chica = df_bt_py_exp4[df_bt_py_exp4['Instancia'].str.contains("mochila_chica")].copy()
    bt_apretada = df_bt_py_exp4[df_bt_py_exp4['Instancia'].str.contains("mochila_apretada")].copy()
    dp_chica = df_dp_py_exp4[df_dp_py_exp4['Instancia'].str.contains("mochila_chica")].copy()
    dp_apretada = df_dp_py_exp4[df_dp_py_exp4['Instancia'].str.contains("mochila_apretada")].copy()

    for df in [bt_chica, bt_apretada, dp_chica, dp_apretada]:
        df['n'] = df['Instancia'].apply(extraer_n)
        df.sort_values('n', inplace=True)
        df.reset_index(drop=True, inplace=True)

    # Mochila chica
    plt.figure(figsize=(10, 6))
    plt.plot(bt_chica['n'], bt_chica['Tiempo'], marker='o', label='BT Python - Mochila chica')
    plt.plot(dp_chica['n'], dp_chica['Tiempo'], marker='o', label='DP Python - Mochila chica')
    plt.xlabel('Tama\u00f1o de la instancia (n)')
    plt.ylabel('Tiempo de ejecuci\u00f3n (s)')
    plt.title('Experimento 4 Python - Mochila chica')
    plt.legend()
    plt.grid(True)
    plt.tight_layout()
    plt.show()

    # Mochila apretada
    plt.figure(figsize=(10, 6))
    plt.plot(bt_apretada['n'], bt_apretada['Tiempo'], marker='o', label='BT Python - Mochila apretada')
    plt.plot(dp_apretada['n'], dp_apretada['Tiempo'], marker='o', label='DP Python - Mochila apretada')
    plt.xlabel('Tama\u00f1o de la instancia (n)')
    plt.ylabel('Tiempo de ejecuci\u00f3n (s)')
    plt.title('Experimento 4 Python - Mochila apretada')
    plt.legend()
    plt.grid(True)
    plt.tight_layout()
    plt.show()