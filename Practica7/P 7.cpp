#include <iostream>
#include <string>

using namespace std;

class NodoArbol {
public:
    int dato;
    NodoArbol* izq;
    NodoArbol* der;

    NodoArbol(int valor) {
        dato = valor;
        izq = NULL;
        der = NULL;
    }
};

class ArbolBinario {
private:
    NodoArbol* raiz;

    NodoArbol* insertarRecursivo(NodoArbol* nodo, int valor) {
        if (nodo == NULL) {
            return new NodoArbol(valor);
        }
        if (valor < nodo->dato) {
            nodo->izq = insertarRecursivo(nodo->izq, valor);
        } else if (valor > nodo->dato) {
            nodo->der = insertarRecursivo(nodo->der, valor);
        }
        return nodo;
    }

    void preordenRecursivo(NodoArbol* nodo) {
        if (nodo == NULL) return;
        cout << nodo->dato << " ";
        preordenRecursivo(nodo->izq);
        preordenRecursivo(nodo->der);
    }

    void inordenRecursivo(NodoArbol* nodo) {
        if (nodo == NULL) return;
        inordenRecursivo(nodo->izq);
        cout << nodo->dato << " ";
        inordenRecursivo(nodo->der);
    }

    void postordenRecursivo(NodoArbol* nodo) {
        if (nodo == NULL) return;
        postordenRecursivo(nodo->izq);
        postordenRecursivo(nodo->der);
        cout << nodo->dato << " ";
    }

public:
    ArbolBinario() {
        raiz = NULL;
    }

    void insertar(int valor) {
        raiz = insertarRecursivo(raiz, valor);
        cout << "[OK] Elemento " << valor << " insertado en el Arbol (RAM).\n";
    }

    void mostrarPreorden() {
        if (raiz == NULL) cout << "El arbol esta vacio.";
        preordenRecursivo(raiz);
        cout << "\n";
    }

    void mostrarInorden() {
        if (raiz == NULL) cout << "El arbol esta vacio.";
        inordenRecursivo(raiz);
        cout << "\n";
    }

    void mostrarPostorden() {
        if (raiz == NULL) cout << "El arbol esta vacio.";
        postordenRecursivo(raiz);
        cout << "\n";
    }
};

int main() {
    ArbolBinario miArbol;
    int opcion = 0;

    while (opcion != 5) {
        cout << "\n=== PRACTICA 7: ARBOLES BINARIOS DE BUSQUEDA (TERCER PARCIAL) ===\n";
        cout << "1. Insertar elemento en el Arbol\n";
        cout << "2. Recorrido en Preorden (Raiz - Izq - Der)\n";
        cout << "3. Recorrido en Inorden (Izq - Raiz - Der)\n";
        cout << "4. Recorrido en Postorden (Izq - Der - Raiz)\n";
        cout << "5. Salir de la Practica\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                int valorInput;
                cout << "\nIngrese el valor entero a meter al arbol: ";
                cin >> valorInput;
                miArbol.insertar(valorInput);
                break;
            }
            case 2: {
                cout << "\n--- RECORRIDO PREORDEN ---\n";
                miArbol.mostrarPreorden();
                break;
            }
            case 3: {
                cout << "\n--- RECORRIDO INORDEN (ORDENADO) ---\n";
                miArbol.mostrarInorden();
                break;
            }
            case 4: {
                cout << "\n--- RECORRIDO POSTORDEN ---\n";
                miArbol.mostrarPostorden();
                break;
            }
            case 5: {
                cout << "\nSaliendo de la Practica 7.\n";
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
