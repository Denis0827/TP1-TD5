#include "KP01withCGInstance.h"

void construir_arbol(vector<int> solucion_parcial, int n, int k) {
    if (k == n) {
        this->_arbol.append(actual);
    } else {
        construir_arbol(solucion_parcial, n, k + 1);
        solucion_parcial.push_back(k); // agrego el elemento k-esimo del conjunto
        construir_arbol(solucion_parcial, n, k + 1);
    }
}


KP01withCGInstance::KP01withCGInstance(int n, int cap) {
    this->_capacidad = cap;
    this->_cantidad_items = n;

    this->_items; // preguntar
    for (int i = 0; i < n; i++) {
        this->_items[i] = tuple(0, 0);
    }

    this->_arbol; // preguntar
    construir_arbol([], n, 0);

    this->_conflictos(n, vector<bool>(n, false));
}

void KP01withCGInstance::setWeight(int index, int weight) {
    this->_items[index][0] = weight;
}

void KP01withCGInstance::setProfit(int index, int profit) {
    this->_items[index][1] = profit;
}

int KP01withCGInstance::getWeight(int index) const {
    return get<0>(this->_items[index]);
}

int KP01withCGInstance::getProfit(int index) const {
    return get<1>(this->_items[index]);
}

int KP01withCGInstance::getNumItems() const {
    return this->_cantidad_items;
}

int KP01withCGInstance::getCapacity() const {
    return this->_capacidad;
}

void KP01withCGInstance::addConflict(int item1, int item2) {
    this->_conflictos[item1][item2] = true;
    this->_conflictos[item1][item2] = true;
}

void KP01withCGInstance::removeConflict(int item1, int item2) {
    this->_conflictos[item1][item2] = false;
    this->_conflictos[item1][item2] = false;
}


bool hasConflict(int item) const {
    for i in range _cantidad_items{
        if (this -> _conflictos[item][i] == true) return true;
    }
    return false;
}

KP01withCGInstance::KP01withCGInstance cargar_datos(const string& archivo) {
    std::ifstream file(archivo);  // Abrir el archivo de entrada
    if (!file.is_open()) {
        std::cerr << "No se pudo abrir el archivo " << archivo << std::endl;
        return *this;  // Retornar el objeto vacío si no se pudo abrir el archivo
    }

    std::string line;
    
    // Leer la primera línea: número total de ítems (n)
    std::getline(file, line);
    std::stringstream ss(line);  // Usar stringstream para procesar la línea
    int n;
    ss >> n;  // Convertir el número de ítems desde la cadena
    this->_cantidad_items = n;

    // Leer la segunda línea: capacidad de la mochila (C)
    std::getline(file, line);
    ss.clear();  // Limpiar el stringstream
    ss.str(line);
    int C;
    ss >> C;  // Convertir la capacidad de la mochila desde la cadena
    this->_capacidad = C;

    // Inicializar las variables de la clase
    this->_items = std::vector<std::tuple<int, int>>(n);  // Crear un vector de tuplas (peso, beneficio)

    // Leer la tercera línea: pesos de los ítems
    std::getline(file, line);
    ss.clear();
    ss.str(line);
    std::vector<int> pesos(n);
    for (int i = 0; i < n; ++i) {
        ss >> pesos[i];  // Leer los pesos
    }

    // Leer la cuarta línea: beneficios de los ítems
    std::getline(file, line);
    ss.clear();
    ss.str(line);
    std::vector<int> beneficios(n);
    for (int i = 0; i < n; ++i) {
        ss >> beneficios[i];  // Leer los beneficios
    }

    // Asignar los pesos y beneficios a los ítems
    for (int i = 0; i < n; ++i) {
        this->setWeight(i, pesos[i]);
        this->setProfit(i, beneficios[i]);
    }

    // Leer la quinta línea: número de pares de conflictos (m)
    std::getline(file, line);
    ss.clear();
    ss.str(line);
    int m;
    ss >> m;  // Leer el número de pares de conflictos

    // Inicializar la matriz de conflictos
    this->_conflictos = std::vector<std::vector<bool>>(n, std::vector<bool>(n, false));

    // Leer las siguientes m líneas para los pares de conflictos
    for (int i = 0; i < m; ++i) {
        std::getline(file, line);
        std::stringstream ss2(line);
        int u, v;
        ss2 >> u >> v;  // Leer el par de índices en conflicto
        this->_conflictos[u][v] = true;
        this->_conflictos[v][u] = true;  // Los conflictos son bidireccionales
    }

    file.close();  // Cerrar el archivo después de leerlo

    return *this;  // Retornar el objeto con los datos cargados
}


