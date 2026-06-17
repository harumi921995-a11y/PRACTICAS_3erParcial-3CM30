#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Saludo {
public:
    void mostrar() {
        cout << "Hola mundo" << endl;
    }
};

class Operacion {
public:
    void sumar(int a, int b) {
        cout << "La suma de " << a << " + " << b << " es: " << a + b << endl;
    }
};

class Calculadora {
public:
    void ejecutar(float n1, float n2) {
        cout << "Suma: " << n1 + n2 << endl;
        cout << "Resta: " << n1 - n2 << endl;
        cout << "Multiplicacion: " << n1 * n2 << endl;
        if (n2 != 0) {
            cout << "Division: " << n1 / n2 << endl;
        } else {
            cout << "Error: Division entre cero" << endl;
        }
    }
};

class CalculadoraVariante {
public:
    void sumar(int a, int b) {
        cout << "Suma de 2 enteros: " << a + b << endl;
    }
    void sumar(int a, int b, int c) {
        cout << "Suma de 3 enteros: " << a + b + c << endl;
    }
};

class Base {
public:
    int sumar(int a, int b) { return a + b; }
    int avanzar(int a) { return a + 1; }
    int restar(int a, int b) { return a - b; }
};

class CalculadoraPro : public Base {
public:
    int multiplicar(int base, int veces) {
        int r = 0;
        for (int i = 0; i < veces; i++) {
            r = sumar(r, base);
        }
        return r;
    }
    int potencia(int base, int exp) {
        if (exp == 0) return 1;
        int r = base;
        for (int i = 1; i < exp; i++) {
            r = multiplicar(r, base);
        }
        return r;
    }
    void divisionRestas(int dividendo, int divisor) {
        if (divisor == 0) {
            cout << "Error: Division entre cero" << endl;
            return;
        }
        int cociente = 0;
        int residuo = dividendo;
        while (residuo >= divisor) {
            residuo = restar(residuo, divisor);
            cociente++;
        }
        cout << "Cociente: " << cociente << " | Residuo: " << residuo << endl;
    }
};

class Persona {
private:
    char nombre[50];
    int edad;
public:
    void capturar() {
        cout << "Ingresa Nombre: "; cin >> nombre;
        cout << "Ingresa Edad: "; cin >> edad;
    }
    void mostrar() {
        cout << "Persona -> Nombre: " << nombre << " | Edad: " << edad << endl;
    }
    string getNombre() { return string(nombre); }
    int getEdad() { return edad; }
};

class Analizador {
public:
    void procesarAlVuelo(float &max, float &min, float &prom) {
        float num, suma = 0;
        for (int i = 0; i < 5; i++) {
            cout << "Ingresa valor " << i + 1 << ": "; cin >> num;
            if (i == 0) {
                max = num;
                min = num;
            } else {
                if (num > max) max = num;
                if (num < min) min = num;
            }
            suma += num;
        }
        prom = suma / 5.0;
    }
};

class AnalizadorArreglo {
private:
    float datos[5];
public:
    void capturar() {
        for (int i = 0; i < 5; i++) {
            cout << "datos[" << i << "]: "; cin >> datos[i];
        }
    }
    float procesar() {
        float suma = 0;
        for (int i = 0; i < 5; i++) {
            suma += datos[i];
        }
        return suma / 5.0;
    }
};

class ProcesadorPunteros {
public:
    void procesarConIndireccion(float *p, float &max, float &min, float &prom) {
        float suma = 0;
        max = *(p + 0);
        min = *(p + 0);
        cout << "\nDirecciones RAM y valores:" << endl;
        for (int i = 0; i < 5; i++) {
            cout << "Direccion RAM: " << (p + i) << " | Valor: " << *(p + i) << endl;
            if (*(p + i) > max) max = *(p + i);
            if (*(p + i) < min) min = *(p + i);
            suma += *(p + i);
        }
        prom = suma / 5.0;
    }
};

class Matriz {
private:
    int m[2][2];
public:
    void capturar(string n) {
        cout << "Matriz " << n << " (2x2):\n";
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                cout << "[" << i << "][" << j << "]: "; cin >> m[i][j];
            }
        }
    }
    void mostrar() {
        for (int i = 0; i < 2; i++) {
            cout << "[ ";
            for (int j = 0; j < 2; j++) cout << m[i][j] << " ";
            cout << "]\n";
        }
    }
    void multiplicarEscalar(int k) {
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) m[i][j] *= k;
        }
    }
    Matriz multiplicarMatrices(Matriz otra) {
        Matriz res;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) res.m[i][j] = 0;
        }
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                for (int k = 0; k < 2; k++) {
                    res.m[i][j] += this->m[i][k] * otra.m[k][j];
                }
            }
        }
        return res;
    }
    int getCelda(int i, int j) { return m[i][j]; }
};

class GeneradorFractales {
public:
    int calcularRamificacion(int nivel) {
        if (nivel <= 0) return 1;
        return 2 * calcularRamificacion(nivel - 1);
    }
};

void guardarArchivos(string txtSaludo, int p4Suma, float p8Prom, float p9Prom, float p10Prom, Persona p, Matriz mat, int frac) {
    ofstream txt("reporte.txt");
    if (txt.is_open()) {
        txt << "--- RECOLECCION DE VARIABLES DEL PARCIAL ---\n";
        txt << "P1_Saludo: " << txtSaludo << "\n";
        txt << "P4_Sobrecarga: " << p4Suma << "\n";
        txt << "P8_PromedioAlVuelo: " << p8Prom << "\n";
        txt << "P9_PromedioArreglo: " << p9Prom << "\n";
        txt << "P10_PromedioPunteros: " << p10Prom << "\n";
        txt << "P7_Persona: " << p.getNombre() << " (Edad: " << p.getEdad() << ")\n";
        txt << "P11_Matriz_Pos_0_0: " << mat.getCelda(0,0) << "\n";
        txt << "P15_Fractal: " << frac << "\n";
        txt.close();
    }

    ofstream csv("reporte.csv");
    if (csv.is_open()) {
        csv << "Practica,Variable,Resultado\n";
        csv << "P1,Saludo," << txtSaludo << "\n";
        csv << "P4,SobrecargaTres," << p4Suma << "\n";
        csv << "P8,PromedioAlVuelo," << p8Prom << "\n";
        csv << "P9,PromedioArreglo," << p9Prom << "\n";
        csv << "P10,PromedioPunteros," << p10Prom << "\n";
        csv << "P7,EdadPersona," << p.getEdad() << "\n";
        csv << "P15,NivelFractal," << frac << "\n";
        csv.close();
    }

    ofstream xml("reporte.xml");
    if (xml.is_open()) {
        xml << "<?xml version=\"1.0\"?>\n<reporte>\n";
        xml << "  <saludo>" << txtSaludo << "</saludo>\n";
        xml << "  <promedios>\n";
        xml << "    <vuelo>" << p8Prom << "</vuelo>\n";
        xml << "    <arreglo>" << p9Prom << "</arreglo>\n";
        xml << "    <puntero>" << p10Prom << "</puntero>\n";
        xml << "  </promedios>\n";
        xml << "  <persona>\n";
        xml << "    <nombre>" << p.getNombre() << "</nombre>\n";
        xml << "    <edad>" << p.getEdad() << "</edad>\n";
        xml << "  </persona>\n";
        xml << "  <fractal>" << frac << "</fractal>\n";
        xml << "</reporte>\n";
        xml.close();
    }

    ofstream json("reporte.json");
    if (json.is_open()) {
        json << "{\n";
        json << "  \"saludo\": \"" << txtSaludo << "\",\n";
        json << "  \"sobrecarga\": " << p4Suma << ",\n";
        json << "  \"promedioVuelo\": " << p8Prom << ",\n";
        json << "  \"promedioArreglo\": " << p9Prom << ",\n";
        json << "  \"promedioPunteros\": " << p10Prom << ",\n";
        json << "  \"persona\": {\n";
        json << "    \"nombre\": \"" << p.getNombre() << "\",\n";
        json << "    \"edad\": " << p.getEdad() << "\n";
        json << "  },\n";
        json << "  \"fractal\": " << frac << "\n";
        json << "}\n";
        json.close();
    }
}

int main() {
    int opc = 0;
    string textSal = "Hola mundo";
    int sumaP4 = 0;
    float promP8 = 0, maxP8 = 0, minP8 = 0;
    float promP9 = 0;
    float promP10 = 0, maxP10 = 0, minP10 = 0;
    float arrP10[5] = {0,0,0,0,0};
    int fracRes = 0;

    Saludo s;
    Operacion op;
    Calculadora miCalc;
    CalculadoraVariante cv;
    CalculadoraPro cp;
    Persona p;
    AnalizadorArreglo aa;
    ProcesadorPunteros pp;
    Matriz mA, mB, mR;

    while (opc != 10) {
        cout << "\n=== MENU INTERACTIVO PRACTICAS FIRST PARCIAL ===" << endl;
        cout << "1. Practicas 1 a 4 (Fundamentos, Parametros, Calculadora y Sobrecarga)" << endl;
        cout << "2. Practicas 5 & 6 (Herencia y Operaciones Sucesivas)" << endl;
        cout << "3. Practica 7 & 7 Bis (Abstraccion de Persona y sizeof)" << endl;
        cout << "4. Practica 8 (Analizador de Datos al Vuelo)" << endl;
        cout << "5. Practica 9 (Analizador Arreglo Interno)" << endl;
        cout << "6. Practica 10 (Aritmetica de Punteros e Indireccion)" << endl;
        cout << "7. Practica 11 (Multiplicacion Matrices)" << endl;
        cout << "8. Practica 15 (Recursividad Fractal)" << endl;
        cout << "9. Practicas 12 a 14 (Procesar y Exportar Datos a Archivos)" << endl;
        cout << "10. Salir" << endl;
        cout << "Selecciona una opcion: "; cin >> opc;

        switch(opc) {
            case 1:
                cout << "\n--- Practica 1 ---" << endl;
                s.mostrar();
                cout << "\n--- Practica 2 ---" << endl;
                int n1, n2;
                cout << "Ingresa n1: "; cin >> n1;
                cout << "Ingresa n2: "; cin >> n2;
                op.sumar(n1, n2);
                cout << "\n--- Practica 3 ---" << endl;
                miCalc.ejecutar(n1, n2);
                cout << "\n--- Practica 4 ---" << endl;
                int n3;
                cout << "Ingresa n3 para sobrecarga de 3 valores: "; cin >> n3;
                cv.sumar(n1, n2);
                cv.sumar(n1, n2, n3);
                sumaP4 = n1 + n2 + n3;
                break;
            case 2:
                int b, v, e;
                cout << "Ingresa Base: "; cin >> b;
                cout << "Ingresa Multiplicador (Veces): "; cin >> v;
                cout << "Ingresa Exponente: "; cin >> e;
                cout << "Multiplicacion Sucesiva: " << cp.multiplicar(b, v) << endl;
                cout << "Potencia Sucesiva: " << cp.potencia(b, e) << endl;
                cout << "Division por Restas Sucesivas:\n";
                cp.divisionRestas(b, v);
                break;
            case 3:
                p.capturar();
                p.mostrar();
                cout << "Tamano de la clase Persona por sizeof: " << sizeof(p) << " bytes." << endl;
                break;
            case 4:
                Analizador anz;
                anz.procesarAlVuelo(maxP8, minP8, promP8);
                cout << "Maximo: " << maxP8 << " | Minimo: " << minP8 << " | Promedio: " << promP8 << endl;
                break;
            case 5:
                aa.capturar();
                promP9 = aa.procesar();
                cout << "Promedio del Arreglo: " << promP9 << endl;
                break;
            case 6:
                for (int i = 0; i < 5; i++) {
                    cout << "Ingresa valor para puntero [" << i << "]: "; cin >> arrP10[i];
                }
                pp.procesarConIndireccion(arrP10, maxP10, minP10, promP10);
                cout << "Max: " << maxP10 << " | Min: " << minP10 << " | Promedio: " << promP10 << endl;
                break;
            case 7:
                mA.capturar("A");
                mB.capturar("B");
                cout << "\nMultiplicando Matriz A * Escalar (2):\n";
                mA.multiplicarEscalar(2);
                mA.mostrar();
                cout << "\nMultiplicando Matrices (A * B):\n";
                mR = mA.multiplicarMatrices(mB);
                mR.mostrar();
                break;
            case 8:
                int niv;
                cout << "Ingresa Nivel del Fractal: "; cin >> niv;
                GeneradorFractales gf;
                fracRes = gf.calcularRamificacion(niv);
                cout << "Resultado Ramificaciones: " << fracRes << endl;
                break;
            case 9:
                guardarArchivos(textSal, sumaP4, promP8, promP9, promP10, p, mR, fracRes);
                cout << "Reportes generados en la carpeta del proyecto (.txt, .csv, .xml, .json)" << endl;
                break;
            case 10:
                cout << "Programa finalizado." << endl;
                break;
        }
    }
    return 0;
}
