#include<iostream>
using namespace std;

int leerNumeroClientes();
void mostrarMenuOpciones();
int leerCantidadVideoJuegos();
int leerCantidadAccesorios();
int leerCantidadTarjetas();
float calcularMonto(int cantidadVideoJuegos, int cantidadAccesorios, int cantidadTarjetas);
void reporteDeVentas(int uni_videojuegos, int uni_accesorios, int uni_tarjetas, float monto_total, int montoDescontado);

int main(){

    int cantidadVideoJuegos;
    int cantidadAccesorios;
    int cantidadTarjetas;
    int contadorClientes = 0;
    int contadorVideoJuegos = 0;
    int contadorAccesorios = 0;
    int contadorTarjetas = 0;
    float montoTotal = 0;
    int numeroClientes = leerNumeroClientes();

    do
    {
       cout << "Cliente " << contadorClientes + 1 << endl;
       cantidadVideoJuegos = leerCantidadVideoJuegos();
       cantidadAccesorios = leerCantidadAccesorios();
       cantidadTarjetas = leerCantidadTarjetas();
       



    } while (contadorClientes > numeroClientes);

    return 0;
}

int leerNumeroClientes(){
    int numeroClientes;
    cout << "Ingrese la cantidad de clientes: ";
    cin >> numeroClientes;
    return numeroClientes;
}

int leerCantidadVideoJuegos(int numeroClientes){
    int cantidadVideoJuegos;
    cout << "Ingrese la cantidad de videojuegos: ";
    cin >> cantidadVideoJuegos;
    return cantidadVideoJuegos;
}

int leerCantidadAccesorios(int numeroClientes){
    int cantidadAccesorios;
    cout << "Unidades vendidas de Accesorios: ";
    cin >> cantidadAccesorios;
    return cantidadAccesorios;
}

int leerCantidadTarjetas(int numeroTarjetas){
    int cantidadTarjetas;
    cout << "Unidades vendidas de Tarjetas Visuales: ";
    cin >> cantidadTarjetas;
    return cantidadTarjetas;
}

float calcularMonto(int cantidadVideoJuegos, int cantidadAccesorios, int cantidadTarjetas){
    float montoTotal;
    float videoJuegos = 170.50;
    float accesorios = 80.90;
    float tarjetas = 50.00;
    montoTotal = (cantidadVideoJuegos * 170.50) + (cantidadAccesorios * 80.90) + (cantidadTarjetas * 50.00);
    return montoTotal;
}

void reporteDeVentas(int uni_videojuegos, int uni_accesorios, int uni_tarjetas, float monto_total, int montoDescontado){
    cout << "Total unidades de VideoJuegos: " << uni_videojuegos << endl;
    cout << "Total unidades de accesorios: " << uni_accesorios << endl; 
    cout << "Total unidades de tarjetas visuales: " << uni_tarjetas << endl;
    cout << "Monto total facturado: " << monto_total << endl;
    cout << "Monto descontado: " << montoDescontado << endl;
}