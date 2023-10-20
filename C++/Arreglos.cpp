//Ejercicio 1
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

// Función para imprimir elementos únicos
void imprimirElementosUnicos(int *arr, int tamano) {
	// Crear un arreglo dinámico para realizar un seguimiento de elementos únicos
	int *elementosUnicos = new int[tamano];
	int elementosUnicosTamano = 0;

	// Iterar a través del arreglo
	for (int i = 0; i < tamano; i++) {
    	bool esRepetido = false;
    	// Verificar si el elemento ya se ha impreso
    	for (int j = 0; j < elementosUnicosTamano; j++) {
        	if (arr[i] == elementosUnicos[j]) {
            	esRepetido = true;
            	break;
        	}
    	}

    	// Si el elemento no es repetido, imprimirlo y agregarlo al arreglo de elementos únicos
    	if (!esRepetido) {
        	cout << "Elemento único: " << arr[i] << endl;
        	elementosUnicos[elementosUnicosTamano] = arr[i];
        	elementosUnicosTamano++;
    	}
	}

	// Liberar la memoria del arreglo dinámico de elementos únicos
	delete[] elementosUnicos;
}

int main() {
	int tamano;
	cout << "Ingrese la cantidad de números que desea ingresar: ";
	cin >> tamano;

	int *numeros;
	crearArreglo(numeros, tamano); // Llama a la función para crear el arreglo dinámico

	ingresarNumeros(numeros, tamano); // Llama a la función para ingresar números en el arreglo

	cout << "Elementos únicos:" << endl;
	imprimirElementosUnicos(numeros, tamano); // Llama a la función para imprimir elementos únicos

	// Liberar la memoria del arreglo dinámico principal
	delete[] numeros;

	return 0;
}