#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

struct Paciente {
    int edad;
    char sexo;
    char tipoPrueba;
    char resultado;
};

void genera_y_muestra_arreglo(Paciente* pacientes, int n);
void hallar_menor_y_cuantos(Paciente* pacientes, int n);
void porcentaje_resultados(Paciente* pacientes, int n);
void promedio_edad_por_tipo(Paciente* pacientes, int n);
void ordenar_y_mostrar(Paciente* pacientes, int n);

int main()
{
    srand(time(0));
    int n = 5;
    Paciente* pacientes = new Paciente[n];

    genera_y_muestra_arreglo(pacientes, n);
    hallar_menor_y_cuantos(pacientes,n);


    delete[] pacientes;
    system("pause>0");
    return 0;
}

void genera_y_muestra_arreglo(Paciente* pacientes, int n) {
    for (int i = 0; i < n; i++)
    {
        //generar valores aleatorios
        pacientes[i].edad = rand() % 76 + 15;
        pacientes[i].sexo = (rand() % 2 == 0)? 'M': 'F';
        pacientes[i].tipoPrueba = (rand() % 3 == 0) ? 'P'
            : (rand() % 2 == 0) ? 'A' : 'S';
        pacientes[i].resultado = (rand() % 2 == 0) ? 'P' : 'N';

        //mostrar los resultados
        cout << "============================================" << endl;
        cout << "Paciente " << (i + 1) << ":" << endl;
        cout << "Edad " << pacientes[i].edad << ":" << endl;
        cout << "Sexo " << pacientes[i].sexo << ":" << endl;
        cout << "Tipo Prueba " << pacientes[i].tipoPrueba << ":" << endl;
        cout << "Resultado " << pacientes[i].resultado << ":" << endl;
        cout << "============================================" << endl;

    }
}

void hallar_menor_y_cuantos(Paciente* pacientes, int n) {
    int menorEdad = pacientes[0].edad;
    int contMenorEdad = 0;

    for (int i = 0; i < n; i++)
    {
        if (pacientes[i].edad < menorEdad) {
            menorEdad = pacientes[i].edad;
            contMenorEdad=1;
        }else if (pacientes[i].edad ==  menorEdad) {
            contMenorEdad++;
        }
    }

    cout << "La menor edad de los pacientes es:" << menorEdad << endl;
    cout << "Cantidad de pacientes con esas edad:" << contMenorEdad << endl;    
}

void porcentaje_resultados(Paciente* pacientes, int n) {
    int contMenores35 = 0, contMayores50 = 0;
    double porMenores35, porMayores50;

    //Incremento de contadores
    for (int i = 0; i < n; i++)
    {
        if (pacientes[i].sexo == 'M' && pacientes[i].edad < 35 && pacientes[i].resultado == 'P') {
            contMenores35++;
        }

        if (pacientes[i].edad >= 50 && pacientes[i].resultado == 'N') {
            contMayores50++;
        }
    }

    //Calcular los porcentajes
    porMenores35 = (contMenores35 / n) * 100;
    porMayores50 = (contMayores50 / n) * 100;

    //Mostrar resultados
    cout << "Porcentajes de varones menores de 35 " <<porMenores35 <<endl;
    cout << "Porcentajes de personas mayores de 50 " << porMayores50 << endl;

}

void promedio_edad_por_tipo(Paciente* pacientes, int n) {

}

void ordenar_y_mostrar(Paciente* pacientes, int n) {
	

}