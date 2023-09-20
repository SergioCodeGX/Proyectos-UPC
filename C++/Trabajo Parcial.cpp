//JUEGO DE CARTAS GRUPO 7

#include "pch.h"
#include<iostream>
#include<conio.h>
#include<ctime>
#include<cstdlib>

using namespace std;
using namespace System;

int generarValorAleatorio(int minValor, int maxValor);
int obtenerOpcionesMenu();
void imprimirInstrucciones();
void imprimirCreditos(int opcion);
void imprimirCarta(int x, int y, int carta, int palo);
int determinarGanador(int sumaPuntajeJugadorUno, int sumaPuntajeJugadorDos);
void simularJuego();

int main() {




    return 0;
}

int generarValorAleatorio(int minValor, int maxValor) {
    return minValor + rand() % (maxValor + 1 - minValor);
}

//MENU DE OPCIUONES
int obtenerOpcionesMenu() {
    int opcion;
    do {
        cout << "-----------------------------" << endl;
        cout << "| MENU PRINCIPAL" << endl;
        cout << "-----------------------------" << endl;
        cout << "| 1. Jugar" << endl;
        cout << "| 2. Instrucciones" << endl;
        cout << "| 3. Creditos" << endl;
        cout << "| 4. Salir" << endl;
        cout << "-----------------------------" << endl;
        cout << "| Ingrese una opcion: ";
        cin >> opcion;

        if (opcion < 1 || opcion > 3) {
            cout << "Opcion incorrecta, intente nuevamente" << endl;
        }

    } while (opcion < 1 || opcion > 3);

    return opcion;
}

//INSTRUCCIONES DEL JUEGO
void imprimirInstrucciones() {
    cout << "| INSTRUCCIONES:" << endl;
    cout << "----------------------------------------------------------------" << endl;
    cout << "| Este es un juego de cartas que simula el juego Jan Ken Po." << endl;
    cout << "| El computador genera dos cartas aleatorias" << endl;
    cout << "| Son de 5 a 10 partidas | 100 puntos por cada jugada ganada." << endl;
    cout << "----------------------------------------------------------------" << endl;
    cout << "| PIEDRA: 1,2,3,4." << endl;
    cout << "| PAPEL: 5,6,7,8." << endl;
    cout << "| TIJERA: 9,10,11,12,13." << endl;
    cout << "----------------------------------------------------------------" << endl;
    cout << "| Piedra gana a tijera." << endl;
    cout << "| Papel gana a piedra." << endl;
    cout << "| Tijera gana a papel." << endl;
    cout << "| Si salen iguales se vuelve a jugar." << endl;
    cout << "----------------------------------------------------------------" << endl;
    cout << "| Gana el jugador con MAYOR PUNTAJE acumulado." << endl;
    cout << "----------------------------------------------------------------" << endl;
    cout << "| Presione cualquier tecla para volver al menu principal" << endl;
    _getch();
}

//CREDITOS DEL JUEGO
void imprimirCreditos(int opcion) {
    cout << "--------------------------------------------" << endl;
    cout << "| CREDITOS: " << endl;
    cout << "--------------------------------------------" << endl;
    cout << "| Juego creado por: " << endl;
    cout << "--------------------------------------------" << endl;
    cout << "| 1.Monroy Ruiz, Sergio Elias" << endl;
    cout << "| 2.Rodriguez Lucen, Jean Pierre Rodrigo" << endl;
    cout << "| 3.Carrasco Atao, Hugo Vidal" << endl;
    cout << "--------------------------------------------" << endl;
}

//DIBUJAR CARTAS DEL 1 AL 13
void imprimirCarta(int x, int y, int carta, int palo) {

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

//DETERMINANDO EL GANADOR
int determinarGanador(int sumaPuntajeJugadorUno, int sumaPuntajeJugadorDos) {
    int ganador;

    if (sumaPuntajeJugadorUno > sumaPuntajeJugadorDos) {
        ganador = 1; //JUGADOR UNO GANA
    }
    else if (sumaPuntajeJugadorDos > sumaPuntajeJugadorUno) {
        ganador = 2; //JUGADOR DOS GANA
    }
    else {
        ganador = -1; //EMPATE
    }
    return ganador;
}

void simularJuego() {
    

    
}