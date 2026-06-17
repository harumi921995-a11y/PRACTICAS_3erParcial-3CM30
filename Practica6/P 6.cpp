#include <iostream>
#include <string>

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
        cout << "[OK] Nodo '" << nombre << "' registrado en la posicion " << cantidadNodos - 1 << ".\n";
    }

    int buscarIndice(string nombre) {
        for (int i = 0; i < cantidadNodos; i++) {
            if (nombresNodos[i] == nombre) {
                return i;
            }
        }
        return -1;
    }

    void agregarAristaDirigida(string origen, string destino, int peso) {
        int indexOrigen = buscarIndice(origen);
        int indexDestino = buscarIndice(destino);

        if (indexOrigen == -1 || indexDestino == -1) {
            cout << "[ERROR] Uno o ambos nodos no existen. Registralos primero.\n";
            return;
        }

        // En un digrafo solo se asigna el sentido origen -> destino
        matriz[indexOrigen][indexDestino] = peso;
        cout << "[OK] Arco dirigido establecido: " << origen << " -> " << destino << " (Peso: " << peso << ")\n";
    }

    void mostrarMatriz() {
        if (cantidadNodos == 0) {
            cout << "[AVISO] El digrafo esta vacio.\n";
            return;
        }

        cout << "\n--- MATRIZ DE ADYACENCIA (DIGRAFO: FILA -> COLUMNA) ---\n\t";
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
    DigrafoMatriz miDigrafo;
    int opcion = 0;

    while (opcion != 4) {
        cout << "\n=== PRACTICA 6: REQUERIMIENTO DE DIGRAFOS (TERCER PARCIAL) ===\n";
        cout << "1. Registrar Nodo (Vertice)\n";
        cout << "2. Conectar Arco Dirigido (Origen -> Destino)\n";
        cout << "3. Desplegar Matriz de Adyacencia\n";
        cout << "4. Salir de la Practica\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                string nombreNodo;
                cout << "\nIngrese el nombre del nodo (sin espacios): ";
                cin >> nombreNodo;
                miDigrafo.registrarNodo(nombreNodo);
                break;
            }
            case 2: {
                string orig, dest;
                int pesoArco;
                cout << "\n--- CONEXION DE ARCOS DIRIGIDOS ---\n";
                cout << "Ingrese Nodo de Origen: ";
                cin >> orig;
                cout << "Ingrese Nodo de Destino: ";
                cin >> dest;
                cout << "Ingrese el peso de la conexion: ";
                cin >> pesoArco;
                
                miDigrafo.agregarAristaDirigida(orig, dest, pesoArco);
                break;
            }
            case 3: {
                miDigrafo.mostrarMatriz();
                break;
            }
            case 4: {
                cout << "\nSaliendo de la Practica 6.\n";
                break;
            }
            default: {
                cout << "[ERROR] Opcion invalida.\n";
                break;
            }
        }
    }

    return 0;
}
