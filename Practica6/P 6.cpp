#include <iostream>
#include <string>
#include <fstream> 

using namespace std;

class DigrafoMatriz {
private:
    int matriz[10][10];
    string nombresNodos[10];
    int cantidadNodos;

public:
    DigrafoMatriz() {
        cantidadNodos = 0;
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                matriz[i][j] = 0;
            }
        }
    }

    void registrarNodo(string nombre) {
        if (cantidadNodos >= 10) {
            cout << "[ERROR] Se ha alcanzado el limite maximo de 10 nodos.\n";
            return;
        }
        nombresNodos[cantidadNodos] = nombre;
        cantidadNodos++;
        cout << "[OK] Nodo '" << nombre << "' registrado.\n";
    }

    int buscarIndice(string nombre) {
        for (int i = 0; i < cantidadNodos; i++) {
            if (nombresNodos[i] == nombre) return i;
        }
        return -1;
    }

    void agregarAristaDirigida(string origen, string destino, int peso) {
        int indexOrigen = buscarIndice(origen);
        int indexDestino = buscarIndice(destino);

        if (indexOrigen == -1 || indexDestino == -1) {
            cout << "[ERROR] Uno o ambos nodos no existen.\n";
            return;
        }
        matriz[indexOrigen][indexDestino] = peso;
        cout << "[OK] Arco dirigido establecido: " << origen << " -> " << destino << "\n";
    }

    // MODIFICACIÓN: Función para cargar desde archivo
    void cargarDesdeArchivo(string nombreArchivo) {
        ifstream archivo(nombreArchivo.c_str()); // .c_str() para compatibilidad
        if (!archivo.is_open()) {
            cout << "[ERROR] No se pudo abrir el archivo.\n";
            return;
        }

        string tipo, n1, n2;
        int peso;
        while (archivo >> tipo) {
            if (tipo == "NODO") {
                archivo >> n1;
                registrarNodo(n1);
            } else if (tipo == "ARCO") { // Usamos ARCO para diferenciar
                archivo >> n1 >> n2 >> peso;
                agregarAristaDirigida(n1, n2, peso);
            }
        }
        archivo.close();
        cout << "[OK] Datos cargados correctamente.\n";
    }

    void mostrarMatriz() {
        if (cantidadNodos == 0) {
            cout << "[AVISO] El digrafo esta vacio.\n";
            return;
        }
        cout << "\n--- MATRIZ DE ADYACENCIA (FILA -> COLUMNA) ---\n\t";
        for (int i = 0; i < cantidadNodos; i++) cout << nombresNodos[i] << "\t";
        cout << "\n";
        for (int i = 0; i < cantidadNodos; i++) {
            cout << nombresNodos[i] << "\t";
            for (int j = 0; j < cantidadNodos; j++) cout << matriz[i][j] << "\t";
            cout << "\n";
        }
    }
};

int main() {
    DigrafoMatriz miDigrafo;
    int opcion = 0;

    while (opcion != 5) { // Actualizado a 5
        cout << "\n=== PRACTICA 6: DIGRAFOS ===\n";
        cout << "1. Registrar Nodo\n";
        cout << "2. Conectar Arco Dirigido\n";
        cout << "3. Desplegar Matriz\n";
        cout << "4. Cargar desde archivo (datos_digrafo.txt)\n";
        cout << "5. Salir\n";
        cout << "Seleccione: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                string nombre;
                cout << "Nombre del nodo: "; cin >> nombre;
                miDigrafo.registrarNodo(nombre);
                break;
            }
            case 2: {
                string o, d; int p;
                cout << "Origen: "; cin >> o;
                cout << "Destino: "; cin >> d;
                cout << "Peso: "; cin >> p;
                miDigrafo.agregarAristaDirigida(o, d, p);
                break;
            }
            case 3: miDigrafo.mostrarMatriz(); break;
            case 4: miDigrafo.cargarDesdeArchivo("datos_digrafo.txt"); break;
            case 5: cout << "Saliendo...\n"; break;
            default: cout << "Opcion invalida.\n";
        }
    }
    return 0;
}
