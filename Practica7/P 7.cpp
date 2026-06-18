#include <iostream>
#include <string>
#include <fstream> // Necesaria para manejar archivos

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
        if (nodo == NULL) return new NodoArbol(valor);
        if (valor < nodo->dato) nodo->izq = insertarRecursivo(nodo->izq, valor);
        else if (valor > nodo->dato) nodo->der = insertarRecursivo(nodo->der, valor);
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
    ArbolBinario() { raiz = NULL; }

    void insertar(int valor) {
        raiz = insertarRecursivo(raiz, valor);
    }

    // MODIFICACIÓN: Función para cargar desde archivo
    void cargarDesdeArchivo(string nombreArchivo) {
        ifstream archivo(nombreArchivo.c_str());
        if (!archivo.is_open()) {
            cout << "[ERROR] No se pudo abrir el archivo.\n";
            return;
        }
        int valor;
        while (archivo >> valor) {
            insertar(valor);
            cout << "[OK] Elemento " << valor << " cargado desde archivo.\n";
        }
        archivo.close();
    }

    void mostrarPreorden() {
        if (raiz == NULL) { cout << "Vacio"; return; }
        preordenRecursivo(raiz); cout << "\n";
    }

    void mostrarInorden() {
        if (raiz == NULL) { cout << "Vacio"; return; }
        inordenRecursivo(raiz); cout << "\n";
    }

    void mostrarPostorden() {
        if (raiz == NULL) { cout << "Vacio"; return; }
        postordenRecursivo(raiz); cout << "\n";
    }
};

int main() {
    ArbolBinario miArbol;
    int opcion = 0;

    while (opcion != 6) { // Actualizado a 6
        cout << "\n=== PRACTICA 7: ARBOLES ===\n";
        cout << "1. Insertar elemento\n";
        cout << "2. Preorden\n";
        cout << "3. Inorden\n";
        cout << "4. Postorden\n";
        cout << "5. Cargar desde archivo (datos_arbol.txt)\n";
        cout << "6. Salir\n";
        cout << "Seleccione: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                int v; cout << "Valor: "; cin >> v;
                miArbol.insertar(v);
                break;
            }
            case 2: miArbol.mostrarPreorden(); break;
            case 3: miArbol.mostrarInorden(); break;
            case 4: miArbol.mostrarPostorden(); break;
            case 5: miArbol.cargarDesdeArchivo("datos_arbol.txt"); break;
            case 6: cout << "Saliendo...\n"; break;
            default: cout << "Opcion invalida.\n";
        }
    }
    return 0;
}
