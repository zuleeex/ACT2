#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

int main() {
    string nombreArchivo = "d:/ACTIVIDAD2/100.txt";
    string archivoPromedio = "d:/ACTIVIDAD2/promedio.txt";

    ifstream archivoDatos(nombreArchivo);
    if (!archivoDatos.is_open()) {
        cerr << "No se pudo abrir el archivo: " << nombreArchivo << endl;
        return 1;
    }

    double suma = 0.0;
    int contador = 0;
    int numero;
    int minimo;
    int maximo;
    bool primer_numero = true;
    double suma_cuadrados = 0.0;

    if (archivoDatos >> numero) {
        suma += numero;
        contador++;
        minimo = numero;
        maximo = numero;
    } else {
        cerr << "El archivo esta vacio" << endl;
        return 1;
    }

    while (archivoDatos >> numero) {
        suma += numero;
        contador++;

        if (numero < minimo) {
            minimo = numero;
        }
        if (numero > maximo) {
            maximo = numero;
        }

        double diferencia = numero - suma / contador;
        suma_cuadrados += diferencia * diferencia;
    }
    archivoDatos.close();

    double promedio = suma / contador;
    double desviacion_estandar = sqrt(suma_cuadrados / contador);

    ofstream archivoResultados(archivoPromedio);
    if (!archivoResultados.is_open()) {
        cerr << "No se pudo crear el archivo de salida: " << archivoPromedio << endl;
        return 1;
    }

    archivoResultados << "                  RESULTADOS                   " << endl;
    archivoResultados << "TOTAL DE DATOS: " << contador << endl;
    archivoResultados << "SUMA DE DATOS: " << suma << endl;
    archivoResultados << "PROMEDIO DE LOS NUMEROS: " << promedio << endl;
    archivoResultados << "MINIMO NUMERO: " << minimo << endl;
    archivoResultados << "MAXIMO NUMERO: " << maximo << endl;
    archivoResultados << "DESVIACION ESTANDAR: " << desviacion_estandar << endl;
    archivoResultados.close();

    cout << "Se ha calculado todo correctamente: " << archivoPromedio << endl;

    return 0;
}
