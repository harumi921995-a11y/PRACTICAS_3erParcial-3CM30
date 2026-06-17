#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Persona {
private:
    string nombre;
    int edad;

public:
    Persona() : nombre(""), edad(0) {}
    Persona(string n, int e) : nombre(n), edad(e) {}

    string getNombre() const { return nombre; }
    int getEdad() const { return edad; }

    void mostrar() const {
        cout << "Nombre: " << nombre << " | Edad: " << edad << endl;
    }
};

class ManejadorXML {
public:
    void guardarXML(int datoBase, Persona arreglosADT[], int tam) {
        ofstream archivo;
        archivo.open("datos.xml", ios::out);

        if (archivo.is_open()) {
            archivo << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n";
            archivo << "<Configuracion>\n";
            archivo << "  <DatoBase>" << datoBase << "</DatoBase>\n";
            archivo << "  <ListaPersonas>\n";
            
            for (int i = 0; i < tam; i++) {
                archivo << "    <Persona>\n";
                archivo << "      <Nombre>" << arreglosADT[i].getNombre() << "</Nombre>\n";
                archivo << "      <Edad>" << arreglosADT[i].getEdad() << "</Edad>\n";
                archivo << "    </Persona>\n";
            }
            
            archivo << "  </ListaPersonas>\n";
            archivo << "</Configuracion>\n";
            archivo.close();
            cout << "[OK] Archivo XML guardado correctamente.\n";
        } else {
            cout << "[ERROR] No se pudo crear el archivo XML.\n";
        }
    }

    void leerXML() {
        ifstream archivo;
        archivo.open("datos.xml", ios::in);

        if (archivo.is_open()) {
            string linea;
            cout << "\n--- CONTENIDO DEL ARCHIVO XML ---\n";
            while (getline(archivo, linea)) {
                cout << linea << "\n";
            }
            archivo.close();
        } else {
            cout << "[ERROR] No se encontro el archivo XML.\n";
        }
    }
};

int main() {
    ManejadorXML gestor;
    int opcion = 0;
    
    int valorBase = 0;
    Persona listaPersonas[10];
    int cantidadElementos = 0;
    bool datosCapturados = false;

    while (opcion != 4) {
        cout << "\n=== PRACTICA 1: PERSISTENCIA XML (TERCER PARCIAL) ===\n";
        cout << "1. Capturar datos basicos y arreglo ADT\n";
        cout << "2. Escribir datos en archivo XML\n";
        cout << "3. Leer archivo XML generado\n";
        cout << "4. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                cout << "\n--- CAPTURA DE DATOS INTERACTIVA ---\n";
                cout << "Ingrese un codigo o dato numerico base: ";
                cin >> valorBase;
                
                cout << "Cual es la cantidad de registros para el arreglo? (Maximo 10): ";
                cin >> cantidadElementos;
                
                if (cantidadElementos > 10 || cantidadElementos <= 0) {
                    cout << "[ERROR] Cantidad invalida.\n";
                    cantidadElementos = 0;
                } else {
                    for (int i = 0; i < cantidadElementos; i++) {
                        string nom;
                        int ed;
                        cout << "\nRegistro [" << i + 1 << "]\n";
                        cout << "Nombre (sin espacios): ";
                        cin >> nom;
                        cout << "Edad: ";
                        cin >> ed;
                        
                        listaPersonas[i] = Persona(nom, ed);
                    }
                    datosCapturados = true;
                    cout << "[OK] Arreglo de objetos cargado en RAM.\n";
                }
                break;
            }
            case 2: {
                if (!datosCapturados) {
                    cout << "[AVISO] Primero debe capturar datos en la opcion 1.\n";
                } else {
                    gestor.guardarXML(valorBase, listaPersonas, cantidadElementos);
                }
                break;
            }
            case 3: {
                gestor.leerXML();
                break;
            }
            case 4: {
                cout << "\nSaliendo de la Practica 1.\n";
                break;
            }
            default: {
                cout << "[ERROR] Opcion no valida.\n";
                break;
            }
        }
    }
    return 0;
}
