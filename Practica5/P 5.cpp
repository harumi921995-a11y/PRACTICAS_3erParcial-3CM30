#include <iostream>
#include <string>

using namespace std;

class GrafoMatriz {
private:
    int matriz[10][10];
    string nombresNodos[10];
    int cantidadNodos;

public:
    GrafoMatriz() {
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
        cout << "[OK] Nodo '" << nombre << "' registrado en la posición " << cantidadNodos - 1 << " de la RAM.\n";
    }

    int buscarIndice(string nombre) {
        for (int i = 0; i < cantidadNodos; i++) {
            if (nombresNodos[i] == nombre) {
                return i;
            }
        }
        return -1;
    }

    void agregarArista(string origen, string destino, int peso) {
        int indexOrigen = buscarIndice(origen);
        int indexDestino = buscarIndice(destino);

        if (indexOrigen == -1 || indexDestino == -1) {
            cout << "[ERROR] Uno o ambos nodos no existen en el grafo. Registralos primero.\n";
            return;
        }

        matriz[indexOrigen][indexDestino] = peso;
        matriz[indexDestino][indexOrigen] = peso; // Grafo no dirigido
        cout << "[OK] Camino establecido: " << origen << " <-> " << destino << " (Peso: " << peso << ")\n";
    }

    void mostrarMatriz() {
        if (cantidadNodos == 0) {
            cout << "[AVISO] El grafo esta vacio. No hay nodos registrados.\n";
            return;
        }

        cout << "\n--- MATRIZ DE ADYACENCIA ACTUAL ---\n\t";
        for (int i = 0; i < cantidadNodos; i++) {
            cout << nombresNodos[i] << "\t";
        }
        cout << "\n";

        for (int i = 0; i < cantidadNodos; i++) {
            cout << nombresNodos[i] << "\t";
            for (int j = 0; j < cantidadNodos; j++) {
                cout << matriz[i][j] << "\t";
            }
            cout << "\n";
        }
    }
};

int main() {
    GrafoMatriz miGrafo;
    int opcion = 0;

    while (opcion != 4) {
        cout << "\n=== PRACTICA 5: REQUERIMIENTO DE GRAFOS (TERCER PARCIAL) ===\n";
        cout << "1. Registrar un nuevo Nodo (Vertice)\n";
        cout << "2. Conectar Nodos (Agregar Arista con Peso)\n";
        cout << "3. Desplegar Matriz de Adyacencia\n";
        cout << "4. Salir de la Practica\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                string nombreNodo;
                cout << "\nIngrese el identificador o nombre del nodo (sin espacios): ";
                cin >> nombreNodo;
                miGrafo.registrarNodo(nombreNodo);
                break;
            }
            case 2: {
                string orig, dest;
                int pesoCamino;
                cout << "\n--- CONEXION DE ARISTAS INTERACTIVA ---\n";
                cout << "Ingrese el Nombre del Nodo Origen: ";
                cin >> orig;
                cout << "Ingrese el Nombre del Nodo Destino: ";
                cin >> dest;
                cout << "Ingrese el peso o valor de la conexion: ";
                cin >> pesoCamino;
                
                miGrafo.agregarArista(orig, dest, pesoCamino);
                break;
            }
            case 3: {
                miGrafo.mostrarMatriz();
                break;
            }
            case 4: {
                cout << "\nSaliendo de la Practica 5.\n";
                break;
            }
            default: {
                cout << "[ERROR] Opcion invalida en el menu.\n";
                break;
            }
        }
    }

    return 0;
}
