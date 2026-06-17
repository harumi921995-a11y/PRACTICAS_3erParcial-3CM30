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

class ManejadorHTML {
public:
    void guardarHTML(int datoBase, Persona arreglosADT[], int tam) {
        ofstream archivo;
        archivo.open("datos.html", ios::out);

        if (archivo.is_open()) {
            archivo << "<!DOCTYPE html>\n";
            archivo << "<html>\n";
            archivo << "<head>\n";
            archivo << "  <title>Reporte Practica 4</title>\n";
            archivo << "  <meta charset=\"UTF-8\">\n";
            archivo << "</head>\n";
            archivo << "<body>\n";
            archivo << "  <h1>Práctica 4: Persistencia HTML</h1>\n";
            archivo << "  <p><strong>Dato Base de la Configuración:</strong> " << datoBase << "</p>\n";
            archivo << "  <table border=\"1\" cellpadding=\"5\" cellspacing=\"0\">\n";
            archivo << "    <tr bgcolor=\"#cccccc\">\n";
            archivo << "      <th>No.</th>\n";
            archivo << "      <th>Nombre</th>\n";
            archivo << "      <th>Edad</th>\n";
            archivo << "    </tr>\n";
            
            for (int i = 0; i < tam; i++) {
                archivo << "    <tr>\n";
                archivo << "      <td>" << (i + 1) << "</td>\n";
                archivo << "      <td>" << arreglosADT[i].getNombre() << "</td>\n";
                archivo << "      <td>" << arreglosADT[i].getEdad() << "</td>\n";
                archivo << "    </tr>\n";
            }
            
            archivo << "  </table>\n";
            archivo << "</body>\n";
            archivo << "</html>\n";
            archivo.close();
            cout << "[OK] Archivo HTML guardado correctamente.\n";
        } else {
            cout << "[ERROR] No se pudo crear el archivo HTML.\n";
        }
    }

    void leerHTML() {
        ifstream archivo;
        archivo.open("datos.html", ios::in);

        if (archivo.is_open()) {
            string linea;
            cout << "\n--- CONTENIDO DEL ARCHIVO HTML (CODIGO FUENTE) ---\n";
            while (getline(archivo, linea)) {
                cout << linea << "\n";
            }
            archivo.close();
        } else {
            cout << "[ERROR] No se encontro el archivo HTML.\n";
        }
    }
};

int main() {
    ManejadorHTML gestor;
    int opcion = 0;
    
    int valorBase = 0;
    Persona listaPersonas[10];
    int cantidadElementos = 0;
    bool datosCapturados = false;

    while (opcion != 4) {
        cout << "\n=== PRACTICA 4: PERSISTENCIA HTML (TERCER PARCIAL) ===\n";
        cout << "1. Capturar datos basicos y arreglo ADT\n";
        cout << "2. Escribir datos en archivo HTML\n";
        cout << "3. Leer archivo HTML generado\n";
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
                    gestor.guardarHTML(valorBase, listaPersonas, cantidadElementos);
                }
                break;
            }
            case 3: {
                gestor.leerHTML();
                break;
            }
            case 4: {
                cout << "\nSaliendo de la Practica 4.\n";
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
