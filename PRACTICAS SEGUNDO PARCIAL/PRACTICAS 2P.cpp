#include <iostream>
#include <string>
#include <list>

using namespace std;

// === CLASE BASE DE DATOS PARA LOS ALGORITMOS ===
class Alumno {
private:
    string nombre;
    int boleta;
public:
    Alumno() {
        nombre = "Sin registro";
        boleta = 0;
    }
    Alumno(string n, int b) {
        nombre = n;
        boleta = b;
    }
    void setDatos(string n, int b) {
        nombre = n;
        boleta = b;
    }
    int getBoleta() { return boleta; }
    string getNombre() { return nombre; }
    void mostrar() {
        cout << "Alumno: " << nombre << " | Boleta: " << boleta << endl;
    }
};

// === BLOQUE 1: ORDENAMIENTO (ALGORITMO DE LA BURBUJA DIRECTO) ===
class OrdenadorBurbuja {
public:
    void ordenarPorBoleta(Alumno arr[], int n) {
        Alumno temp;
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (arr[j].getBoleta() > arr[j + 1].getBoleta()) {
                    // Swap o intercambio físico de las instancias completas en la RAM
                    temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }
};

// === BLOQUE 2: ESTRUCTURA LINEAL ESTÁTICA (PILA / STACK) ===
class PilaEstatica {
private:
    int tope;
    int capacidad;
    int* arreglo;
public:
    PilaEstatica(int tam) {
        capacidad = tam;
        arreglo = new int[capacidad];
        tope = -1;
    }
    ~PilaEstatica() {
        delete[] arreglo;
    }
    bool estaLlena() {
        return tope == capacidad - 1;
    }
    bool estaVacia() {
        return tope == -1;
    }
    void push(int elemento) {
        if (estaLlena()) {
            cout << "Error: La pila se encuentra llena (Overflow)" << endl;
            return;
        }
        tope++;
        arreglo[tope] = elemento;
        cout << "Elemento " << elemento << " apilado correctamente." << endl;
    }
    int pop() {
        if (estaVacia()) {
            cout << "Error: La pila esta vacia (Underflow)" << endl;
            return -1;
        }
        int valor = arreglo[tope];
        string sin_formato_1;
        tope--;
        return valor;
    }
    void mostrarPila() {
        if (estaVacia()) {
            cout << "La pila esta vacia." << endl;
            return;
        }
        cout << "Estado actual de la Pila (desde el Tope):" << endl;
        for (int i = tope; i >= 0; i--) {
            cout << "[ " << arreglo[i] << " ]" << endl;
        }
    }
};

// === BLOQUE 3: ESTRUCTURA DINÁMICA CON PLANTILLAS (LISTA DOBLE STL) ===
class GestorListaSTL {
private:
    list<string> listaTareas;
public:
    void insertarInicio(string tarea) {
        listaTareas.push_front(tarea);
        cout << "Tarea agregada al inicio." << endl;
    }
    void insertarFinal(string tarea) {
        listaTareas.push_back(tarea);
        cout << "Tarea agregada al final." << endl;
    }
    void eliminarInicio() {
        if (listaTareas.empty()) {
            cout << "La lista ya esta vacia." << endl;
            return;
        }
        cout << "Eliminando: " << listaTareas.front() << endl;
        listaTareas.pop_front();
    }
    void mostrarLista() {
        if (listaTareas.empty()) {
            cout << "La lista dinamica esta vacia." << endl;
            return;
        }
        cout << "Elementos de la Lista Doblemente Enlazada (Iteradores STL):" << endl;
        // Uso estricto de iteradores explícitos para asegurar compatibilidad en el laboratorio
        list<string>::iterator it;
        for (it = listaTareas.begin(); it != listaTareas.end(); ++it) {
            cout << "Nodo RAM -> Direccion/Contenido: " << *it << endl;
        }
    }
};

int main() {
    int opc = 0;

    // Persistencia para el Bloque de Ordenamiento
    int tamArreglo = 0;
    Alumno listaAlumnos[20];
    OrdenadorBurbuja controladorBurbuja;

    // Persistencia para el Bloque de Pila Estática
    PilaEstatica miPila(5);

    // Persistencia para el Bloque de Lista Dinámica STL
    GestorListaSTL miListaDinamica;

    while (opc != 8) {
        cout << "\n=========================================================" << endl;
        cout << "       SISTEMA GENERAL DE CONTROL - SEGUNDO PARCIAL      " << endl;
        cout << "=========================================================" << endl;
        cout << "1. [Burbuja] Registrar alumnos para ordenar" << endl;
        cout << "2. [Burbuja] Ejecutar ordenamiento y mostrar" << endl;
        cout << "3. [Pila] Agregar elemento (Push)" << endl;
        cout << "4. [Pila] Retirar elemento (Pop)" << endl;
        cout << "5. [Pila] Mostrar estado de la pila estatica" << endl;
        cout << "6. [Lista STL] Insertar tarea en la lista doble" << endl;
        cout << "7. [Lista STL] Mostrar tareas e iteradores dinamicos" << endl;
        cout << "8. Salir del programa" << endl;
        cout << "Selecciona una opcion: ";
        cin >> opc;

        switch (opc) {
            case 1: {
                cout << "\n¿Cuantos alumnos deseas registrar? (Maximo 20): ";
                cin >> tamArreglo;
                if (tamArreglo > 20 || tamArreglo <= 0) {
                    cout << "Cantidad invalida de alumnos." << endl;
                    tamArreglo = 0;
                } else {
                    for (int i = 0; i < tamArreglo; i++) {
                        string nom;
                        int bol;
                        cout << "\nAlumno " << i + 1 << endl;
                        cout << "Nombre (sin espacios): "; cin >> nom;
                        cout << "Boleta: "; cin >> bol;
                        listaAlumnos[i].setDatos(nom, bol);
                    }
                }
                break;
            }
            case 2: {
                if (tamArreglo == 0) {
                    cout << "\nNo hay alumnos registrados en la memoria RAM." << endl;
                } else {
                    cout << "\n--- LISTA ORIGINAL ---" << endl;
                    for (int i = 0; i < tamArreglo; i++) listaAlumnos[i].mostrar();

                    controladorBurbuja.ordenarPorBoleta(listaAlumnos, tamArreglo);

                    cout << "\n--- LISTA ORDENADA POR BOLETA (BURBUJA POO) ---" << endl;
                    for (int i = 0; i < tamArreglo; i++) listaAlumnos[i].mostrar();
                }
                break;
            }
            case 3: {
                int elementoPila;
                cout << "\nIngresa el numero entero a colocar en la pila: ";
                cin >> elementoPila;
                miPila.push(elementoPila);
                break;
            }
            case 4: {
                int sacado = miPila.pop();
                if (sacado != -1) {
                    cout << "\nElemento retirado de la parte superior: " << sacado << endl;
                }
                break;
            }
            case 5: {
                cout << endl;
                miPila.mostrarPila();
                break;
            }
            case 6: {
                string descTarea;
                int subOpc;
                cout << "\nDescripcion de la tarea (sin espacios): "; cin >> descTarea;
                cout << "1. Insertar al inicio (push_front)\n2. Insertar al final (push_back)\nOpcion: ";
                cin >> subOpc;
                if (subOpc == 1) {
                    miListaDinamica.insertarInicio(descTarea);
                } else {
                    miListaDinamica.insertarFinal(descTarea);
                }
                break;
            }
            case 7: {
                cout << endl;
                miListaDinamica.mostrarLista();
                break;
            }
            case 8: {
                cout << "\nCerrando sistema del segundo parcial." << endl;
                break;
            }
            default: {
                cout << "\nOpcion incorrecta." << endl;
                break;
            }
        }
    }
    return 0;
}
