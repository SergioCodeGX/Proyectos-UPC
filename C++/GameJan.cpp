#include "pch.h"
#include <iostream>
#include <Windows.h>
#include <ctime>
#include <conio.h>

const int ANCHO_PANTALLA = 120;
const int ALTO_PANTALLA = 28;
const int ANCHO_ROBOT = 16;
const int ALTO_ROBOT = 6;

//Define las teclas de control del robot
const int ARRIBA = 72;
const int ABAJO = 80;
const int IZQUIERDA = 75;
const int DERECHA = 77;

// Define las nuevas dimensiones del robot y el meteorito
const int ANCHO_NUEVO_ROBOT = 8;
const int ALTO_NUEVO_ROBOT = 6;
const int ANCHO_METEORITO = 3;
const int ALTO_METEORITO = 2;
const int LINEA_INFERIOR = ALTO_PANTALLA - 1;

using namespace std;
using namespace System;

// Declaración de funciones
void moverRobot(int& x, int& y, int dx, int dy);
void moverMeteorito(int& x, int& y, int& dx, int& dy, int& color);
void dibujarRobot(int x, int y);
void dibujarMeteorito(int x, int y, int color);
void ventana();
void ubica(int x, int y);
void presentacion(int x, int y);
void color(int c);
void imprimirCreditosJuego(int x, int y);
void imprimirIntruccionesJuego(int x, int y);
int imprimirMenuDeOpciones(int x, int y);
void imprimirLineaInferior();
void dibujarMuestras(int cantidadMuestras);
float aleatorio();

int main() {
    srand(time(nullptr));
    int vidas = 3;

    int velocidad = 0;
    int distancia = 0;
    int altura = 0;
    int tiempoLlegada = 0;
    int meteoritosEstaticos = 0;
    int meteoritosMovimiento = 0;
    int meteoritosAcercandose = 0;
    int cantidadMuestras = 14;

    // Ajusta las coordenadas iniciales del robot
    int xr1 = ANCHO_PANTALLA / 2 - ANCHO_ROBOT / 2;
    int yr1 = ALTO_PANTALLA / 2 - ALTO_ROBOT / 2;  // Ajusta la posición inicial del robot
    int dxr1 = 0, dyr1 = 0;
    int x, y;

    int numMeteoritos = 4;
    int xMeteoritos[4] = { 10, 50, 30, 70 };
    int yMeteoritos[4] = { 5, 10, 15, 20 };
    int dxMeteoritos[4] = { 1, -1, 1, -1 };
    int dyMeteoritos[4] = { 1, -1, 1, -1 };
    int coloresMeteoritos[4] = { 11, 13, 14, 12 }; // Colores: 11 = Cyan, 13 = Magenta, 14 = Amarillo, 12 = Rojo

    ventana();
    x = 30;
    y = 10;

    presentacion(ANCHO_PANTALLA / 2 - 7, ALTO_PANTALLA / 2 - 3);

    system("pause>0");
    Console::Clear();

    x = 10;
    y = 10;

    imprimirCreditosJuego(x, y);

    x = 1;
    y = 1;

    imprimirIntruccionesJuego(x, y);

    x = 1;
    y = 1;

    while (true) {
        if (_kbhit()) {
            int key = _getch();
            if (key == IZQUIERDA) {
                dxr1 = -1;
                dyr1 = 0;
            }
            else if (key == DERECHA) {
                dxr1 = 1;
                dyr1 = 0;
            }
            else if (key == ARRIBA) {
                dxr1 = 0;
                dyr1 = -1;
            }
            else if (key == ABAJO) {
                dxr1 = 0;
                dyr1 = 1;
            }
        }

        for (int i = 0; i < numMeteoritos; i++) {
            moverMeteorito(xMeteoritos[i], yMeteoritos[i], dxMeteoritos[i], dyMeteoritos[i], coloresMeteoritos[i]);
        }

        // Mover el robot
        moverRobot(xr1, yr1, dxr1, dyr1);

        // Dibujar elementos
        Console::Clear();

        for (int i = 0; i < numMeteoritos; i++) {
            dibujarMeteorito(xMeteoritos[i], yMeteoritos[i], coloresMeteoritos[i]);
        }

        dibujarRobot(xr1, yr1);

        // Verificar colisión para cada meteorito
        for (int i = 0; i < numMeteoritos; i++) {
            if (xr1 >= xMeteoritos[i] && xr1 <= xMeteoritos[i] + ANCHO_METEORITO && yr1 >= yMeteoritos[i] && yr1 <= yMeteoritos[i] + ALTO_METEORITO) {
                vidas--;
                xr1 = max(1, min(ANCHO_PANTALLA - ANCHO_NUEVO_ROBOT, ANCHO_PANTALLA / 2 - ANCHO_NUEVO_ROBOT / 2));
                yr1 = 2;  // Modificado yr1
                xMeteoritos[i] = rand() % (ANCHO_PANTALLA - ANCHO_METEORITO) + 1;
                yMeteoritos[i] = rand() % (ALTO_PANTALLA - ALTO_METEORITO) + 1;
                dxMeteoritos[i] = rand() % 3 - 1;
                dyMeteoritos[i] = rand() % 3 - 1;
                coloresMeteoritos[i] = rand() % 15 + 1; // Cambia el color aleatoriamente
            }
        }
        imprimirLineaInferior();
        dibujarMuestras(cantidadMuestras);
        Sleep(120);
    }

    // El juego ha terminado (el robot se quedó sin vidas)
    ubica(ANCHO_PANTALLA / 2 - 10, ALTO_PANTALLA / 2);
    cout << "¡El robot perdió todas sus vidas!";
    return 0;
}

// Implementación de funciones
void ventana() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SMALL_RECT sr;
    COORD consoleSize;

    sr.Left = 0;
    sr.Top = 0;
    sr.Right = ANCHO_PANTALLA - 1;
    sr.Bottom = ALTO_PANTALLA - 1;

    consoleSize.X = ANCHO_PANTALLA;
    consoleSize.Y = ALTO_PANTALLA;

    SetConsoleWindowInfo(hConsole, TRUE, &sr);
    SetConsoleScreenBufferSize(hConsole, consoleSize);
}

void ubica(int x, int y) {
    Console::SetCursorPosition(x, y);
}

void moverRobot(int& x, int& y, int dx, int dy) {
    // Calcula la posición futura del robot
    int nuevaX = x + dx;

    // Limita la posición del robot a la parte derecha de la consola
    if (nuevaX >= ANCHO_PANTALLA - ANCHO_ROBOT) {
        x = ANCHO_PANTALLA - ANCHO_ROBOT;
    }
    else if (nuevaX < 1) {
        x = 1;
    }
    else {
        x = nuevaX;
    }

    y += dy;

    // Limita las posiciones del robot dentro de los bordes del escenario
    y = max(1, min(y, ALTO_PANTALLA - 6));
}



void moverMeteorito(int& x, int& y, int& dx, int& dy, int& color) {
    x += dx;
    y += dy;

    // Rebotar en los bordes del escenario
    if (x <= 1 || x >= ANCHO_PANTALLA - ANCHO_METEORITO) {
        dx = -dx;
    }
    if (y <= 1 || y >= ALTO_PANTALLA - ALTO_METEORITO) {
        dy = -dy;
    }
}

void dibujarRobot(int x, int y) {
    ubica(x, y);     cout << "            . ";
    ubica(x, y + 1); cout << "            | ";
    ubica(x, y + 2); cout << " ___________| ";
    ubica(x, y + 3); cout << "|:o:|       | ";
    ubica(x, y + 4); cout << "|___|_______| ";
    ubica(x, y + 5); cout << "(o)-(o)-(o)-(o)";
}

void dibujarMeteorito(int x, int y, int color) {
    ubica(x, y);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color); // Establece el color
    cout << "***" << endl;
    ubica(x, y + 1);
    cout << "***"; // Forma de meteorito
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); // Restaura el color a blanco (15)
}

void presentacion(int x, int y) {
    int espacioIzquierda = (ANCHO_PANTALLA - 51) / 4;  // Ajusta este valor para controlar la posición horizontal

    ubica(espacioIzquierda, y);
    color(14);
    cout << "____    ____  __       ___             __   _______  .______        ______          __    ______   ";

    ubica(espacioIzquierda, y + 1);
    cout << "\\   \\  /   / |  |     /   \\           |  | |   ____| |   _  \\      /  __  \\        |  |  /  __  \\  ";

    ubica(espacioIzquierda, y + 2);
    cout << " \\   \\/   /  |  |    /  ^  \\          |  | |  |__    |  |_)  |    |  |  |  |       |  | |  |  |  | ";

    ubica(espacioIzquierda, y + 3);
    cout << "  \\      /   |  |   /  /_\\  \\   .--.  |  | |   __|   |      /     |  |  |  | .--.  |  | |  |  |  | ";

    ubica(espacioIzquierda, y + 4);
    cout << "   \\    /    |  |  /  _____  \\  |  `--'  | |  |____  |  |\\  \\----.|  `--'  | |  `--'  | |  `--'  | ";

    ubica(espacioIzquierda, y + 5);
    cout << "    \\__/     |__| /__/     \\__\\  \\______/  |_______| | _| `._____| \\______/   \\______/   \\______/  ";
}

void color(int c)
{
    switch (c)
    {
    case 1:Console::ForegroundColor = ConsoleColor::Black;       break;
    case 2:Console::ForegroundColor = ConsoleColor::Blue;		 break;
    case 3:Console::ForegroundColor = ConsoleColor::Cyan;		 break;
    case 4:Console::ForegroundColor = ConsoleColor::DarkBlue;	 break;
    case 5:Console::ForegroundColor = ConsoleColor::DarkCyan;	 break;
    case 6:Console::ForegroundColor = ConsoleColor::DarkGray;	 break;
    case 7:Console::ForegroundColor = ConsoleColor::DarkGreen;	 break;
    case 8:Console::ForegroundColor = ConsoleColor::DarkMagenta; break;
    case 9:Console::ForegroundColor = ConsoleColor::DarkRed;	 break;
    case 10:Console::ForegroundColor = ConsoleColor::DarkYellow; break;
    case 11:Console::ForegroundColor = ConsoleColor::Gray;		 break;
    case 12:Console::ForegroundColor = ConsoleColor::Green;		 break;
    case 13:Console::ForegroundColor = ConsoleColor::Magenta;	 break;
    case 14:Console::ForegroundColor = ConsoleColor::Red;		 break;
    case 15:Console::ForegroundColor = ConsoleColor::White;		 break;
    case 16:Console::ForegroundColor = ConsoleColor::Yellow;	 break;
    }
}

void imprimirIntruccionesJuego(int x, int y) {

    ubica(x, y);
    cout << "\nINSTRUCCIONES:" << endl;
    cout << "--------------------------------------------------------------" << endl;
    cout << "¡Bienvenido al emocionante juego Viaje Rojo!" << endl;
    cout << "\nTu misión es ayudar al Rover Perseverance a aterrizar en la superficie de Marte" << endl;
    cout << "y enviar las muestras recolectadas de regreso a la Tierra. Asegúrate de seguir " << endl;
    cout << "las instrucciones y reglas del juego para tener una exitosa mision en Marte." << endl;
    cout << "Marte está lleno de meteoritos que pueden ser peligrosos. Debes evitar chocar con ellos." << endl;
    cout << "Algunos meteoritos estarán estáticos, mientras que otros se moverán a lo largo del terreno marciano." << endl;
    cout << "\nGanas cuando Rovert sube nuevamente a su nave." << endl;
    cout << "\nPresione cualquier tecla para iniciar" << endl;
    _getch();
    system("cls");

}

int imprimirMenuDeOpciones(int x, int y) {

    ubica(x, y);
    int opcion;
    do {
        cout << " \nTIPO MOVIMIENTO DE ROVER:" << endl;
        cout << "--------------------------------------" << endl;
        cout << "| 1.Mover el Rover automaticamente    |" << endl;
        cout << "| 2.Controlar a Rover con las teclas  |" << endl;
        cout << "--------------------------------------" << endl;
        cout << " Ingrese una opcion: ";
        cin >> opcion;

        if (opcion < 1 || opcion > 4) {
            cout << "Opcion invalida, seleccionar una opcion entre 1 y 2" << endl;
        }

    } while (opcion < 1 || opcion > 2);

    return opcion;
}

void imprimirCreditosJuego(int x, int y) {

    ubica(x, y);
    cout << " \nCREDITOS: " << endl;
    cout << "---------------------------------------------------------" << endl;
    cout << "| Juego creado por:                                     |" << endl;
    cout << "---------------------------------------------------------" << endl;
    cout << "| 1.Monroy Ruiz, Sergio Elias                           |" << endl;
    cout << "| 2.Rodriguez Lucen, Jean Pierre Rodrigo                |" << endl;
    cout << "| 3.Carrasco Atao, Hugo Vidal                           |" << endl;
    cout << "---------------------------------------------------------" << endl;
    cout << " Presione cualquier tecla para continuar" << endl;
    _getch();
    system("cls");

}

float aleatorio()
{
    // Retorna un número aleatorio entre -1 y 1
    return ((float)rand() / RAND_MAX) * 2 - 1;
}

void imprimirLineaInferior() {
    Console::SetCursorPosition(0, LINEA_INFERIOR);
    for (int i = 0; i < ANCHO_PANTALLA; i++) {
        cout << "=";
    }
}

void dibujarMuestras(int cantidadMuestras) {
    int xInicioMuestras = 7;
    int yMuestras = LINEA_INFERIOR - 1;

    ubica(xInicioMuestras, yMuestras);
    color(14);

    for (int i = 0; i < cantidadMuestras; i++) {
        cout << "*";
        xInicioMuestras += 8;
        ubica(xInicioMuestras, yMuestras);
    }

    color(15);
}