//PROBLEMA DE ANIMACION

#include "pch.h"
#include<iostream>
#include<conio.h>
using namespace std;
using namespace System;

void ventana() {
	Console::SetWindowSize(80, 40);
}

void cursor(int x, int y) {
	Console::SetCursorPosition(x, y);
}

//ANIMACION CON TRES CARACTERES
int main()
{
	//DECLARANDO VARIABLES
	int x1 = 12, y1 = 15, dy1 = 1;
	int x2 = 40, y2 = 25, dx2 = 1;
	int x3 = 65, y3 = 15, dy3 = 1, dx3 = 1;
	int colisiones = 0;

	ventana();

	//BANDERAS DE CONTROL PARA EL MOVIMIENTO DE LOS CARACTERES
	bool moverCaracter1 = false;
	bool moverCaracter2 = false;
	bool moverCaracter3 = false;
	bool detenerCaracteres = false;

	//DIBUJANDO LOS TRES CARACTERES
	cursor(x1, y1); cout << char(42);
	cursor(x2, y2); cout << char(64);
	cursor(x3, y3); cout << char(35);

	while (true)
	{
		//OBTENER LA TECLA PRESIONADA Y MOVER EL CARACTER 1 CON LA LETRA "I"
		if (_kbhit()) {
			char tecla = _getch();
			if (tecla == 'i') moverCaracter1 = true;
			else if (tecla == 'c') moverCaracter2 = true;
			else if (tecla == 'd') moverCaracter3 = true;
			else if (tecla == 'p') detenerCaracteres = !detenerCaracteres;
		}
		if (!detenerCaracteres) {

			if (moverCaracter1) {
				//BORRAR
				cursor(x1, y1); cout << " ";

				//MOVER Y ROBOTAR CUANDO LLEGA AL LIMITE DE LA CONSOLA
				if (y1 == 1 || y1 == 39) dy1 *= -1;
				y1 += dy1;

				//DIBUJAR
				cursor(x1, y1); cout << char(42);

			}

			if (moverCaracter2) {
				//BORRAR
				cursor(x2, y2); cout << " ";

				//MOVER Y ROBOTAR CUANDO LLEGA AL LIMITE DE LA CONSOLA
				if (x2 == 1 || x2 == 79) dx2 *= -1;
				x2 += dx2;

				//DIBUJAR
				cursor(x2, y2); cout << char(64);

			}

			//AHORA EL TERCER CARACTER DEBE MOVERSE POR TODA LA PANTALLA CUANDO PRESIONE LA TECLA "D"
			if (moverCaracter3) {
				//BORRAR
				cursor(x3, y3); cout << " ";

				//MOVER Y ROBOTAR CUANDO LLEGA AL LIMITE DE LA CONSOLA
				if (x3 == 1 || x3 == 79) dx3 *= -1;
				if (y3 == 1 || y3 == 39) dy3 *= -1;
				x3 += dx3;
				y3 += dy3;

				//DIBUJAR
				cursor(x3, y3); cout << char(35);

			}
		}


		//CONTADOR DE LA CANTIDAD DE COLISIONES ENTRE LOS CARACTERES
		if (x1 == x2 && y1 == y2) colisiones++;
		if (x1 == x3 && y1 == y3) colisiones++;
		if (x2 == x3 && y2 == y3) colisiones++;

		Console::SetCursorPosition(40, 40); cout << "Colisiones: " << colisiones;

		_sleep(100);
	}


	_getch();
    return 0;
}
