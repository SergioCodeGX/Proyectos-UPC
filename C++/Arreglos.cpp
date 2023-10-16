#include <iostream>

using namespace std;

const int TAMANIO_ARREGLO = 5;

void llenarArreglo(int arreglo[], int tamanio) {
    for (int i = 0; i < tamanio; i++) {
        cout << "Ingrese el elemento " << i + 1 << ": ";
        cin >> arreglo[i];
    }
}

void imprimirArreglo(int arreglo[], int tamanio) {
    for (int i = 0; i < tamanio; i++) {
        cout << arreglo[i] << " ";
    }
    cout << endl;
}

int sumarArreglo(int arreglo[], int tamanio) {
    int suma = 0;
    for (int i = 0; i < tamanio; i++) {
        suma += arreglo[i];
    }
    return suma;
}

int main() {
    int miArreglo[TAMANIO_ARREGLO];

    llenarArreglo(miArreglo, TAMANIO_ARREGLO);

    cout << "El arreglo es: ";
    imprimirArreglo(miArreglo, TAMANIO_ARREGLO);

    int suma = sumarArreglo(miArreglo, TAMANIO_ARREGLO);
    cout << "La suma de los elementos del arreglo es: " << suma << endl;

    return 0;
}