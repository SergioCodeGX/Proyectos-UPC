#include <iostream>
using namespace std;

// Función para crear un arreglo dinámico
void crearArreglo(int *&arr, int tamano) {
	arr = new int[tamano];
}

// Función para ingresar números en el arreglo
void ingresarNumeros(int *arr, int tamano) {
	cout << "Ingrese los números uno por uno:" << endl;
	for (int i = 0; i < tamano; i++) {
    	cout << "Número " << i + 1 << ": ";
    	cin >> arr[i];
	}
}

// Función para contar elementos repetidos y mostrar la cantidad de repeticiones por cada elemento
void contarElementosRepetidos(int *arr, int tamano) {
	cout << "Cantidad de elementos repetidos por cada elemento:" << endl;

	for (int i = 0; i < tamano; i++) {
    	if (arr[i] != -1) {
        	int repeticiones = 1;
        	for (int j = i + 1; j < tamano; j++) {
            	if (arr[i] == arr[j]) {
                	repeticiones++;
                	arr[j] = -1; // Marcar como visitado para no contar duplicados
            	}
        	}
        	cout << "Número " << arr[i] << ": " << repeticiones << " veces" << endl;
    	}
	}
}

int main() {
	int tamano;
	cout << "Ingrese la cantidad de números que desea ingresar: ";
	cin >> tamano;

	int *numeros;
	crearArreglo(numeros, tamano);

	ingresarNumeros(numeros, tamano);

	contarElementosRepetidos(numeros, tamano);

	delete[] numeros;

	return 0;
}