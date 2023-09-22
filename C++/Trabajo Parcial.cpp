//Juego JanKenCards GRUPO 7

#include "pch.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <conio.h>

using namespace System;
using namespace std;

int generarValorAletorio(int minValor, int maxValor);
int obtenerMenuOpciones();
void imprimirInstrucciones();
void creditosDelJuego();
void imprimirCarta(int x, int y, int carta, int palo);
int determinarGanadorJugada(int cartaJugador1, int cartaJugador2);
void determinarGanadorPartida(int puntajeFinal1, int puntajeFinal2);
void simularJuego();

int main()
{   
    //Ajustar tamaño de la consola
    Console::SetWindowSize(100, 40);

    srand(time(NULL));
    int opcion;

    //Llamando a las funciones para imprimir el menu de opciones
    do
    {
        opcion = obtenerMenuOpciones();

        switch (opcion)
        {
        case 1:
            imprimirInstrucciones();
            break;
        case 2:
            simularJuego();
            break;
        case 3:
            creditosDelJuego();
            break;
        case 4:
            cout << "\n Gracias por jugar!" << endl;
            break;

        }

    } while (opcion != 4);

    system("pause>NULL");
    return 0;
}

//GENERAR VALOR ALEATORIO
int generarValorAletorio(int minValor, int maxValor) {
    return minValor + rand() % (maxValor + 1 - minValor);
}

//MENU DE OPCIONES
int obtenerMenuOpciones() {
    int opcion;
    do
    {
        cout << " \nMENU PRINCIPAL:" << endl;
        cout << "-----------------------------" << endl;
        cout << "| 1. Instrucciones          |" << endl;
        cout << "| 2. Jugar                  |" << endl;
        cout << "| 3. Creditos               |" << endl;
        cout << "| 4. Salir                  |" << endl;
        cout << "-----------------------------" << endl;
        cout << " Ingrese una opcion: ";
        cin >> opcion;

        if (opcion < 1 || opcion > 4) {
            cout << "Opcion invalida, seleccionar una opcion entre 1 y 4" << endl;
        }

    } while (opcion < 1 || opcion> 4);

    return opcion;
}

//INSTRUCCIONES DEL JUEGO
void imprimirInstrucciones() {
    cout << "\nINSTRUCCIONES:" << endl;
    cout << "--------------------------------------------------------------" << endl;
    cout << "| Este es un juego de cartas que simula el juego Jan Ken Po. |" << endl;
    cout << "| El computador genera dos cartas aleatorias                 |" << endl;
    cout << "| Son de 5 a 10 partidas | 100 puntos por cada jugada ganada.|" << endl;
    cout << "--------------------------------------------------------------" << endl;
    cout << "| PIEDRA: 1,2,3,4.                                           |" << endl;
    cout << "| PAPEL: 5,6,7,8.                                            |" << endl;
    cout << "| TIJERA: 9,10,11,12,13.                                     |" << endl;
    cout << "--------------------------------------------------------------" << endl;
    cout << "| Piedra gana a tijera.                                      |" << endl;
    cout << "| Papel gana a piedra.                                       |" << endl;
    cout << "| Tijera gana a papel.                                       |" << endl;
    cout << "| Si salen iguales se vuelve a jugar.                        |" << endl;
    cout << "--------------------------------------------------------------" << endl;
    cout << "| Gana el jugador con MAYOR PUNTAJE acumulado.               |" << endl;
    cout << "--------------------------------------------------------------" << endl;
    cout << " Presione cualquier tecla para volver al menu principal" << endl;
    _getch();
}

//CREDITOS DEL JUEGO
void creditosDelJuego() {
    cout << " \nCREDITOS: " << endl;
    cout << "---------------------------------------------------------" << endl;
    cout << "| Juego creado por:                                     |" << endl;
    cout << "---------------------------------------------------------" << endl;
    cout << "| 1.Monroy Ruiz, Sergio Elias                           |" << endl;
    cout << "| 2.Rodriguez Lucen, Jean Pierre Rodrigo                |" << endl;
    cout << "| 3.Carrasco Atao, Hugo Vidal                           |" << endl;
    cout << "---------------------------------------------------------" << endl;
    cout << " Presione cualquier tecla para volver al menu principal" << endl;
    _getch();
}

//IMPRIMIR CARTAS
void imprimirCarta(int x, int y, int carta, int palo)
{
    if (carta == 1)
    {
        Console::SetCursorPosition(x, y); cout << "A"; for (int i = 1; i <= 11; i++) cout << (char)196; cout << (char)191;
        Console::SetCursorPosition(x, y + 1); cout << (char)palo; for (int i = 1; i <= 11; i++) cout << " "; cout << (char)179;
        Console::SetCursorPosition(x, y + 2); cout << (char)179; for (int i = 1; i <= 11; i++) cout << " "; cout << (char)179;
        Console::SetCursorPosition(x, y + 3); cout << (char)179; for (int i = 1; i <= 11; i++) cout << " "; cout << (char)179;
        Console::SetCursorPosition(x, y + 4); cout << (char)179; for (int i = 1; i <= 11; i++) cout << " "; cout << (char)179;
        Console::SetCursorPosition(x, y + 5); cout << (char)179; for (int i = 1; i <= 5; i++) cout << " "; cout << (char)palo; for (int i = 1; i <= 5; i++) cout << " "; cout << (char)179;
        Console::SetCursorPosition(x, y + 6); cout << (char)179; for (int i = 1; i <= 11; i++) cout << " "; cout << (char)179;
        Console::SetCursorPosition(x, y + 7); cout << (char)179; for (int i = 1; i <= 11; i++) cout << " "; cout << (char)179;
        Console::SetCursorPosition(x, y + 8); cout << (char)179; for (int i = 1; i <= 11; i++) cout << " "; cout << (char)179;
        Console::SetCursorPosition(x, y + 9); cout << (char)179; for (int i = 1; i <= 11; i++) cout << " "; cout << (char)palo;
        Console::SetCursorPosition(x, y + 10); cout << (char)192; for (int i = 1; i <= 11; i++) cout << (char)196; cout << "A";
    }
    if (carta == 2)
    {
        Console::SetCursorPosition(x, y); cout << carta; for (int i = 1; i <= 5; i++)cout << (char)196; cout << (char)palo; for (int i = 1; i <= 5; i++)cout << (char)196; cout << (char)191;
        Console::SetCursorPosition(x, y + 1); cout << (char)palo; for (int i = 1; i <= 11; i++) cout << " "; cout << (char)179;
        Console::SetCursorPosition(x, y + 2); cout << (char)179; for (int i = 1; i <= 11; i++) cout << " "; cout << (char)179;
        Console::SetCursorPosition(x, y + 3); cout << (char)179; for (int i = 1; i <= 11; i++) cout << " "; cout << (char)179;
        Console::SetCursorPosition(x, y + 4); cout << (char)179; for (int i = 1; i <= 11; i++) cout << " "; cout << (char)179;
        Console::SetCursorPosition(x, y + 5); cout << (char)179; for (int i = 1; i <= 11; i++) cout << " "; cout << (char)179;
        Console::SetCursorPosition(x, y + 6); cout << (char)179; for (int i = 1; i <= 11; i++) cout << " "; cout << (char)179;
        Console::SetCursorPosition(x, y + 7); cout << (char)179; for (int i = 1; i <= 11; i++) cout << " "; cout << (char)179;
        Console::SetCursorPosition(x, y + 8); cout << (char)179; for (int i = 1; i <= 11; i++) cout << " "; cout << (char)179;
        Console::SetCursorPosition(x, y + 9); cout << (char)179; for (int i = 1; i <= 11; i++) cout << " "; cout << (char)palo;
        Console::SetCursorPosition(x, y + 10); cout << (char)192; for (int i = 1; i <= 5; i++)cout << (char)196; cout << (char)palo; for (int i = 1; i <= 5; i++)cout << (char)196; cout << carta;
    }
    if (carta == 3)
    {
        Console::SetCursorPosition(x, y); cout << carta; for (int i = 1; i <= 5; i++)cout << (char)196; cout << (char)palo; for (int i = 1; i <= 5; i++)cout << (char)196; cout << (char)191;
        Console::SetCursorPosition(x, y + 1); cout << (char)palo; for (int i = 1; i <= 11; i++) cout << " "; cout << (char)179;
        Console::SetCursorPosition(x, y + 2); cout << (char)179; for (int i = 1; i <= 11; i++) cout << " "; cout << (char)179;
        Console::SetCursorPosition(x, y + 3); cout << (char)179; for (int i = 1; i <= 11; i++) cout << " "; cout << (char)179;
        Console::SetCursorPosition(x, y + 4); cout << (char)179; for (int i = 1; i <= 11; i++) cout << " "; cout << (char)179;
        Console::SetCursorPosition(x, y + 5); cout << (char)179; for (int i = 1; i <= 5; i++) cout << " "; cout << (char)palo; for (int i = 1; i <= 5; i++) cout << " "; cout << (char)179;
        Console::SetCursorPosition(x, y + 6); cout << (char)179; for (int i = 1; i <= 11; i++) cout << " "; cout << (char)179;
        Console::SetCursorPosition(x, y + 7); cout << (char)179; for (int i = 1; i <= 11; i++) cout << " "; cout << (char)179;
        Console::SetCursorPosition(x, y + 8); cout << (char)179; for (int i = 1; i <= 11; i++) cout << " "; cout << (char)179;
        Console::SetCursorPosition(x, y + 9); cout << (char)179; for (int i = 1; i <= 11; i++) cout << " "; cout << (char)palo;
        Console::SetCursorPosition(x, y + 10); cout << (char)192; for (int i = 1; i <= 5; i++)cout << (char)196; cout << (char)palo; for (int i = 1; i <= 5; i++)cout << (char)196; cout << carta;
    }
    if (carta == 4)
    {
        Console::SetCursorPosition(x, y); cout << carta; cout << (char)palo; for (int i = 1; i <= 9; i++)cout << (char)196; cout << (char)palo;   cout << (char)191;
        Console::SetCursorPosition(x, y + 1); cout << (char)palo; for (int i = 1; i <= 11; i++) cout << " "; cout << (char)179;
        Console::SetCursorPosition(x, y + 2); cout << (char)179; for (int i = 1; i <= 11; i++) cout << " "; cout << (char)179;
        Console::SetCursorPosition(x, y + 3); cout << (char)179; for (int i = 1; i <= 11; i++) cout << " "; cout << (char)179;
        Console::SetCursorPosition(x, y + 4); cout << (char)179; for (int i = 1; i <= 11; i++) cout << " "; cout << (char)179;
        Console::SetCursorPosition(x, y + 5); cout << (char)179; for (int i = 1; i <= 11; i++) cout << " "; cout << (char)179;
        Console::SetCursorPosition(x, y + 6); cout << (char)179; for (int i = 1; i <= 11; i++) cout << " "; cout << (char)179;
        Console::SetCursorPosition(x, y + 7); cout << (char)179; for (int i = 1; i <= 11; i++) cout << " "; cout << (char)179;
        Console::SetCursorPosition(x, y + 8); cout << (char)179; for (int i = 1; i <= 11; i++) cout << " "; cout << (char)179;
        Console::SetCursorPosition(x, y + 9); cout << (char)179; for (int i = 1; i <= 11; i++) cout << " "; cout << (char)palo;
        Console::SetCursorPosition(x, y + 10); cout << (char)192; cout << (char)palo; for (int i = 1; i <= 9; i++)cout << (char)196; cout << (char)palo; cout << carta;
    }
    if (carta == 5)
    {
        Console::SetCursorPosition(x, y); cout << carta; cout << (char)palo; for (int i = 1; i <= 9; i++)cout << (char)196; cout << (char)palo;   cout << (char)191;
        Console::SetCursorPosition(x, y + 1); cout << (char)palo; for (int i = 1; i <= 11; i++) cout << " "; cout << (char)179;
        Console::SetCursorPosition(x, y + 2); cout << (char)179; for (int i = 1; i <= 11; i++) cout << " "; cout << (char)179;
        Console::SetCursorPosition(x, y + 3); cout << (char)179; for (int i = 1; i <= 11; i++) cout << " "; cout << (char)179;
        Console::SetCursorPosition(x, y + 4); cout << (char)179; for (int i = 1; i <= 11; i++) cout << " "; cout << (char)179;
        Console::SetCursorPosition(x, y + 5); cout << (char)179; for (int i = 1; i <= 5; i++) cout << " "; cout << (char)palo; for (int i = 1; i <= 5; i++) cout << " "; cout << (char)179;
        Console::SetCursorPosition(x, y + 6); cout << (char)179; for (int i = 1; i <= 11; i++) cout << " "; cout << (char)179;
        Console::SetCursorPosition(x, y + 7); cout << (char)179; for (int i = 1; i <= 11; i++) cout << " "; cout << (char)179;
        Console::SetCursorPosition(x, y + 8); cout << (char)179; for (int i = 1; i <= 11; i++) cout << " "; cout << (char)179;
        Console::SetCursorPosition(x, y + 9); cout << (char)179; for (int i = 1; i <= 11; i++) cout << " "; cout << (char)palo;
        Console::SetCursorPosition(x, y + 10); cout << (char)192; cout << (char)palo; for (int i = 1; i <= 9; i++)cout << (char)196; cout << (char)palo; cout << carta;
    }
    if (carta == 6)
    {
        Console::SetCursorPosition(x, y); cout << carta; cout << (char)palo; for (int i = 1; i <= 9; i++)cout << (char)196; cout << (char)palo;   cout << (char)191;
        Console::SetCursorPosition(x, y + 1); cout << (char)palo; for (int i = 1; i <= 11; i++) cout << " "; cout << (char)179;
        Console::SetCursorPosition(x, y + 2); cout << (char)179; for (int i = 1; i <= 11; i++) cout << " "; cout << (char)179;
        Console::SetCursorPosition(x, y + 3); cout << (char)179; for (int i = 1; i <= 11; i++) cout << " "; cout << (char)179;
        Console::SetCursorPosition(x, y + 4); cout << (char)179; for (int i = 1; i <= 11; i++) cout << " "; cout << (char)179;
        Console::SetCursorPosition(x, y + 5); cout << (char)179; cout << (char)palo; for (int i = 1; i <= 9; i++) cout << " "; cout << (char)palo;  cout << (char)179;
        Console::SetCursorPosition(x, y + 6); cout << (char)179; for (int i = 1; i <= 11; i++) cout << " "; cout << (char)179;
        Console::SetCursorPosition(x, y + 7); cout << (char)179; for (int i = 1; i <= 11; i++) cout << " "; cout << (char)179;
        Console::SetCursorPosition(x, y + 8); cout << (char)179; for (int i = 1; i <= 11; i++) cout << " "; cout << (char)179;
        Console::SetCursorPosition(x, y + 9); cout << (char)179; for (int i = 1; i <= 11; i++) cout << " "; cout << (char)palo;
        Console::SetCursorPosition(x, y + 10); cout << (char)192; cout << (char)palo; for (int i = 1; i <= 9; i++)cout << (char)196; cout << (char)palo; cout << carta;
    }
    if (carta == 7)
    {
        Console::SetCursorPosition(x, y); cout << carta; cout << (char)palo; for (int i = 1; i <= 9; i++)cout << (char)196; cout << (char)palo;   cout << (char)191;
        Console::SetCursorPosition(x, y + 1); cout << (char)palo; for (int i = 1; i <= 11; i++) cout << " "; cout << (char)179;
        Console::SetCursorPosition(x, y + 2); cout << (char)179; for (int i = 1; i <= 11; i++) cout << " "; cout << (char)179;
        Console::SetCursorPosition(x, y + 3); cout << (char)179; for (int i = 1; i <= 5; i++) cout << " "; cout << (char)palo; for (int i = 1; i <= 5; i++) cout << " "; cout << (char)179;
        Console::SetCursorPosition(x, y + 4); cout << (char)179; for (int i = 1; i <= 11; i++) cout << " "; cout << (char)179;
        Console::SetCursorPosition(x, y + 5); cout << (char)179; cout << (char)palo; for (int i = 1; i <= 9; i++) cout << " "; cout << (char)palo;  cout << (char)179;
        Console::SetCursorPosition(x, y + 6); cout << (char)179; for (int i = 1; i <= 11; i++) cout << " "; cout << (char)179;
        Console::SetCursorPosition(x, y + 7); cout << (char)179; for (int i = 1; i <= 11; i++) cout << " "; cout << (char)179;
        Console::SetCursorPosition(x, y + 8); cout << (char)179; for (int i = 1; i <= 11; i++) cout << " "; cout << (char)179;
        Console::SetCursorPosition(x, y + 9); cout << (char)179; for (int i = 1; i <= 11; i++) cout << " "; cout << (char)palo;
        Console::SetCursorPosition(x, y + 10); cout << (char)192; cout << (char)palo; for (int i = 1; i <= 9; i++)cout << (char)196; cout << (char)palo; cout << carta;
    }
    if (carta == 8)
    {
        Console::SetCursorPosition(x, y); cout << carta; cout << (char)palo; for (int i = 1; i <= 9; i++)cout << (char)196; cout << (char)palo;   cout << (char)191;
        Console::SetCursorPosition(x, y + 1); cout << (char)palo; for (int i = 1; i <= 11; i++) cout << " "; cout << (char)179;
        Console::SetCursorPosition(x, y + 2); cout << (char)179; for (int i = 1; i <= 11; i++) cout << " "; cout << (char)179;
        Console::SetCursorPosition(x, y + 3); cout << (char)179; for (int i = 1; i <= 5; i++) cout << " "; cout << (char)palo; for (int i = 1; i <= 5; i++) cout << " "; cout << (char)179;
        Console::SetCursorPosition(x, y + 4); cout << (char)179; for (int i = 1; i <= 11; i++) cout << " "; cout << (char)179;
        Console::SetCursorPosition(x, y + 5); cout << (char)179; cout << (char)palo; for (int i = 1; i <= 9; i++) cout << " "; cout << (char)palo;  cout << (char)179;
        Console::SetCursorPosition(x, y + 6); cout << (char)179; for (int i = 1; i <= 11; i++) cout << " "; cout << (char)179;
        Console::SetCursorPosition(x, y + 7); cout << (char)179; for (int i = 1; i <= 5; i++) cout << " "; cout << (char)palo; for (int i = 1; i <= 5; i++) cout << " "; cout << (char)179;
        Console::SetCursorPosition(x, y + 8); cout << (char)179; for (int i = 1; i <= 11; i++) cout << " "; cout << (char)179;
        Console::SetCursorPosition(x, y + 9); cout << (char)179; for (int i = 1; i <= 11; i++) cout << " "; cout << (char)palo;
        Console::SetCursorPosition(x, y + 10); cout << (char)192; cout << (char)palo; for (int i = 1; i <= 9; i++)cout << (char)196; cout << (char)palo; cout << carta;
    }
    if (carta == 9)
    {
        Console::SetCursorPosition(x, y); cout << carta; cout << (char)palo; for (int i = 1; i <= 9; i++)cout << (char)196; cout << (char)palo;   cout << (char)191;
        Console::SetCursorPosition(x, y + 1); cout << (char)palo; for (int i = 1; i <= 11; i++) cout << " "; cout << (char)179;
        Console::SetCursorPosition(x, y + 2); cout << (char)179; for (int i = 1; i <= 11; i++) cout << " "; cout << (char)179;
        Console::SetCursorPosition(x, y + 3); cout << (char)179; cout << (char)palo; for (int i = 1; i <= 9; i++) cout << " "; cout << (char)palo;   cout << (char)179;
        Console::SetCursorPosition(x, y + 4); cout << (char)179; for (int i = 1; i <= 11; i++) cout << " "; cout << (char)179;
        Console::SetCursorPosition(x, y + 5); cout << (char)179; for (int i = 1; i <= 5; i++) cout << " "; cout << (char)palo; for (int i = 1; i <= 5; i++) cout << " "; cout << (char)179;
        Console::SetCursorPosition(x, y + 6); cout << (char)179; for (int i = 1; i <= 11; i++) cout << " "; cout << (char)179;
        Console::SetCursorPosition(x, y + 7); cout << (char)179; cout << (char)palo; for (int i = 1; i <= 9; i++) cout << " "; cout << (char)palo;   cout << (char)179;
        Console::SetCursorPosition(x, y + 8); cout << (char)179; for (int i = 1; i <= 11; i++) cout << " "; cout << (char)179;
        Console::SetCursorPosition(x, y + 9); cout << (char)179; for (int i = 1; i <= 11; i++) cout << " "; cout << (char)palo;
        Console::SetCursorPosition(x, y + 10); cout << (char)192; cout << (char)palo; for (int i = 1; i <= 9; i++)cout << (char)196; cout << (char)palo; cout << carta;
    }
    if (carta == 10)
    {
        Console::SetCursorPosition(x, y); cout << carta; cout << (char)palo; for (int i = 1; i <= 9; i++)cout << (char)196; cout << (char)palo;   cout << (char)191;
        Console::SetCursorPosition(x, y + 1); cout << (char)palo; for (int i = 1; i <= 11; i++) cout << " "; cout << (char)179;
        Console::SetCursorPosition(x, y + 2); cout << (char)179; for (int i = 1; i <= 5; i++) cout << " "; cout << (char)palo; for (int i = 1; i <= 5; i++) cout << " "; cout << (char)179;
        Console::SetCursorPosition(x, y + 3); cout << (char)179; cout << (char)palo; for (int i = 1; i <= 9; i++) cout << " "; cout << (char)palo;   cout << (char)179;
        Console::SetCursorPosition(x, y + 4); cout << (char)179; for (int i = 1; i <= 11; i++) cout << " "; cout << (char)179;
        Console::SetCursorPosition(x, y + 5); cout << (char)179; for (int i = 1; i <= 11; i++) cout << " "; cout << (char)179;
        Console::SetCursorPosition(x, y + 6); cout << (char)179; for (int i = 1; i <= 11; i++) cout << " "; cout << (char)179;
        Console::SetCursorPosition(x, y + 7); cout << (char)179; cout << (char)palo; for (int i = 1; i <= 9; i++) cout << " "; cout << (char)palo;   cout << (char)179;
        Console::SetCursorPosition(x, y + 8); cout << (char)179; for (int i = 1; i <= 5; i++) cout << " "; cout << (char)palo; for (int i = 1; i <= 5; i++) cout << " "; cout << (char)179;
        Console::SetCursorPosition(x, y + 9); cout << (char)179; for (int i = 1; i <= 11; i++) cout << " "; cout << (char)palo;
        Console::SetCursorPosition(x, y + 10); cout << (char)192; cout << (char)palo; for (int i = 1; i <= 9; i++)cout << (char)196; cout << (char)palo; cout << carta;
    }
    if (carta == 11)
    {
        Console::SetCursorPosition(x, y); cout << "J"; for (int i = 1; i <= 11; i++) cout << (char)196; cout << (char)191;
        Console::SetCursorPosition(x, y + 1); cout << (char)palo; for (int i = 1; i <= 11; i++) cout << " "; cout << (char)179;
        Console::SetCursorPosition(x, y + 2); cout << (char)179; for (int i = 1; i <= 11; i++) cout << (char)178; cout << (char)179;
        Console::SetCursorPosition(x, y + 3); cout << (char)179; for (int i = 1; i <= 11; i++) cout << (char)176; cout << (char)179;
        Console::SetCursorPosition(x, y + 4); cout << (char)179; for (int i = 1; i <= 11; i++) cout << (char)177; cout << (char)179;
        Console::SetCursorPosition(x, y + 5); cout << (char)179; for (int i = 1; i <= 11; i++) cout << (char)178;  cout << (char)179;
        Console::SetCursorPosition(x, y + 6); cout << (char)179; for (int i = 1; i <= 11; i++) cout << (char)176; cout << (char)179;
        Console::SetCursorPosition(x, y + 7); cout << (char)179; for (int i = 1; i <= 11; i++) cout << (char)177; cout << (char)179;
        Console::SetCursorPosition(x, y + 8); cout << (char)179; for (int i = 1; i <= 11; i++) cout << (char)178; cout << (char)179;
        Console::SetCursorPosition(x, y + 9); cout << (char)179; for (int i = 1; i <= 11; i++) cout << " "; cout << (char)palo;
        Console::SetCursorPosition(x, y + 10); cout << (char)192; for (int i = 1; i <= 11; i++) cout << (char)196; cout << "J";
    }
    if (carta == 12)
    {
        Console::SetCursorPosition(x, y); cout << "Q"; for (int i = 1; i <= 11; i++) cout << (char)196; cout << (char)191;
        Console::SetCursorPosition(x, y + 1); cout << (char)palo; for (int i = 1; i <= 11; i++) cout << " "; cout << (char)179;
        Console::SetCursorPosition(x, y + 2); cout << (char)179; for (int i = 1; i <= 11; i++) cout << (char)176; cout << (char)179;
        Console::SetCursorPosition(x, y + 3); cout << (char)179; for (int i = 1; i <= 11; i++) cout << (char)177; cout << (char)179;
        Console::SetCursorPosition(x, y + 4); cout << (char)179; for (int i = 1; i <= 11; i++) cout << (char)178; cout << (char)179;
        Console::SetCursorPosition(x, y + 5); cout << (char)179; for (int i = 1; i <= 11; i++) cout << (char)178;  cout << (char)179;
        Console::SetCursorPosition(x, y + 6); cout << (char)179; for (int i = 1; i <= 11; i++) cout << (char)176; cout << (char)179;
        Console::SetCursorPosition(x, y + 7); cout << (char)179; for (int i = 1; i <= 11; i++) cout << (char)177; cout << (char)179;
        Console::SetCursorPosition(x, y + 8); cout << (char)179; for (int i = 1; i <= 11; i++) cout << (char)178; cout << (char)179;
        Console::SetCursorPosition(x, y + 9); cout << (char)179; for (int i = 1; i <= 11; i++) cout << " "; cout << (char)palo;
        Console::SetCursorPosition(x, y + 10); cout << (char)192; for (int i = 1; i <= 11; i++) cout << (char)196; cout << "Q";
    }
    if (carta == 13)
    {
        Console::SetCursorPosition(x, y); cout << "K"; for (int i = 1; i <= 11; i++) cout << (char)196; cout << (char)191;
        Console::SetCursorPosition(x, y + 1); cout << (char)palo; for (int i = 1; i <= 11; i++) cout << " "; cout << (char)179;
        Console::SetCursorPosition(x, y + 2); cout << (char)179; for (int i = 1; i <= 11; i++) cout << (char)178; cout << (char)179;
        Console::SetCursorPosition(x, y + 3); cout << (char)179; for (int i = 1; i <= 11; i++) cout << (char)178; cout << (char)179;
        Console::SetCursorPosition(x, y + 4); cout << (char)179; for (int i = 1; i <= 11; i++) cout << (char)177; cout << (char)179;
        Console::SetCursorPosition(x, y + 5); cout << (char)179; for (int i = 1; i <= 11; i++) cout << (char)177;  cout << (char)179;
        Console::SetCursorPosition(x, y + 6); cout << (char)179; for (int i = 1; i <= 11; i++) cout << (char)176; cout << (char)179;
        Console::SetCursorPosition(x, y + 7); cout << (char)179; for (int i = 1; i <= 11; i++) cout << (char)176; cout << (char)179;
        Console::SetCursorPosition(x, y + 8); cout << (char)179; for (int i = 1; i <= 11; i++) cout << (char)178; cout << (char)179;
        Console::SetCursorPosition(x, y + 9); cout << (char)179; for (int i = 1; i <= 11; i++) cout << " "; cout << (char)palo;
        Console::SetCursorPosition(x, y + 10); cout << (char)192; for (int i = 1; i <= 11; i++) cout << (char)196; cout << "K";
    }
}

//FUNCION PARA DETERMINAR EL GANADOR DE CADA JUGADA
int determinarGanadorJugada(int cartaJugadorUno, int cartaJugadorDos) {

    if (cartaJugadorUno == cartaJugadorDos) {
        return 0;
    }
    else if (((cartaJugadorUno >= 1 && cartaJugadorUno <= 4 && cartaJugadorDos >= 9 && cartaJugadorDos <= 13) ||
        (cartaJugadorUno >= 5 && cartaJugadorUno <= 8 && cartaJugadorDos >= 1 && cartaJugadorDos <= 4) ||
        (cartaJugadorUno >= 9 && cartaJugadorUno <= 13 && cartaJugadorDos >= 5 && cartaJugadorDos <= 8))) {
        return 1;
    }
    else {
        return 2;
    }
}

//FUNCION PARA DETERMINAR EL GANADOR DE LA PARTIDA
void determinarGanadorPartida(int puntajeFinal1, int puntajeFinal2)
{
    int ganador;

    if (puntajeFinal1 > puntajeFinal2) {
        cout << "\nEl ganador es el jugador 1" << endl;
    }
    else if (puntajeFinal1 < puntajeFinal2) {
        cout << "\nEl ganador es el jugador 2" << endl;
    }
    else {
        cout << "\nHan quedado empate" << endl;
    }
}

//FUNCION PARA SIMULAR EL JUEGO
void simularJuego() {

    int numPartidas = 0;
    int partidasJugadas = 0;
    int puntajeJugadorUno = 0;
    int puntajeJugadorDos = 0;
    int paloAleatorio;
    int cartaJugadorUno;
    int cartaJugadorDos;
    int resultadoGanador;
    int ganadorEmpate;
    char deseaContinuar;

    //PEDIR NUMERO DE PARTIDAS
    do
    {
        cout << " Ingrese el numero de partidas (entre 5 y 10): ";
        cin >> numPartidas;

    } while (numPartidas < 5 || numPartidas > 10);

    //Determinar el valor de los numeros de las cartas
    cout << "\n(PIEDRA = 1,2,3,4 | PAPEL = 5,6,7,8 | TIJERA = 9,10,11,12,13)" << endl;

    while (true) {

        //Generando carta aleatoria jugador uno y dos"
        cartaJugadorUno = generarValorAletorio(1, 13);
        cartaJugadorDos = generarValorAletorio(1, 13);


        //Generar el palo aleatorio
        paloAleatorio = generarValorAletorio(3, 6);


        //Imprimir las cartas en console del jugador uno y dos
        imprimirCarta(10, 13, cartaJugadorUno, paloAleatorio);
        imprimirCarta(10, 27, cartaJugadorDos, paloAleatorio);
        cout << endl;
        cout << endl;


        //Determinar el ganador de la jugada
        resultadoGanador = determinarGanadorJugada(cartaJugadorUno, cartaJugadorDos);

        //Imprimir numero de partida
        cout << "Nro de partida: " << partidasJugadas + 1 << endl;


        //Imprimir el ganador de la jugada
        if (resultadoGanador == 1) {
            cout << "Jugador 1 gana la partida." << endl;
            puntajeJugadorUno += 100;
        }
        else if (resultadoGanador == 2) {
            cout << "Jugador 2 gana la partida." << endl;
            puntajeJugadorDos += 100;
        }
        else {
            cout << "Empate en esta partida. Se decide al azar el ganador." << endl;
            ganadorEmpate = generarValorAletorio(1, 2);
            if (ganadorEmpate == 1) {
                cout << "Jugador 1 gana la partida" << endl;
                puntajeJugadorUno += 50;
            }
            else if (ganadorEmpate == 2) {
                cout << "Jugador 2 gana la partida" << endl;
                puntajeJugadorDos += 50;
            }
        }

        partidasJugadas++;

        //LA PARTIDA TERMINA CUANDO SE HAYAN JUGADO EL NUMERO DE PARTIDAS INDICADAS
        if (partidasJugadas == numPartidas) {
			break;
		}

        cout << "(S) PARA CONTINUAR (N) PARA SALIR: " << endl;
        cin >> deseaContinuar;
        deseaContinuar = toupper(deseaContinuar);

        if (deseaContinuar != 'S') {
            break;
        }

    }//FIN DEL BUCLE WHILE


    //Imprimir puntaje final
    cout << "\nPUNTAJE FINAL" << endl;
    cout << "\nJugador uno: " << puntajeJugadorUno << endl;
    cout << "Jugador dos: " << puntajeJugadorDos << endl;

    //Determinar el ganador de la partida
    determinarGanadorPartida(puntajeJugadorUno, puntajeJugadorDos);
}