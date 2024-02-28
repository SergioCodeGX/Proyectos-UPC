//CAZA DE AVES
//TAREA ACADEMICA
//Sergio Monroy / U20231E371

#include <iostream>
#include <conio.h>
#include <windows.h>
#include <ctime>
#include <vector>

using namespace std;
using namespace System;

const int anchoPantalla = 90;
const int alturaPantalla = 30;
const int maxAves = 10;

struct Ave {
    int x, y;
    int direction;
    WORD color;
};


void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}


void setTextColor(WORD color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}


void CrearEstadoInicial(const vector<Ave>& Aves, int cazadorX, int cazadorY) {
    system("cls");
    for (const auto& Ave : Aves) {
        gotoxy(Ave.x, Ave.y);
        setTextColor(Ave.color);
        cout << "~^~";
    }
    setTextColor(15);
    gotoxy(cazadorX, cazadorY);
    cout << "I";
    gotoxy(anchoPantalla / 2 - 15, alturaPantalla / 2);
    cout << "Bienvenido, presione una tecla para iniciar el juego!!!!";
}


int main() {
    srand(time(NULL));
    vector<Ave> aves;
    int cazadorX = anchoPantalla / 2;
    int cazadorY = alturaPantalla - 1;
    int balaX = -1;
    int balaY = -1;
    int CantidadAveCazadas = 0;

    while (aves.size() < maxAves) {
        aves.push_back({ rand() % anchoPantalla, rand() % (alturaPantalla - 4), 1, static_cast<WORD>(1 + rand() % 14) });
    }

    CrearEstadoInicial(aves, cazadorX, cazadorY);
    _getch();

    while (!aves.empty()) {
        gotoxy(0, 0);

        for (const auto& ave : aves) {
            gotoxy(ave.x, ave.y);
            setTextColor(ave.color);
            cout << "~^~";
        }

        setTextColor(15);
        gotoxy(cazadorX, cazadorY);
        cout << "I";

        if (balaX != -1 && balaY != -1) {
            gotoxy(balaX, balaY);
            cout << "*";
        }

        gotoxy(0, alturaPantalla);
        cout << "Cazados: " << CantidadAveCazadas;

        if (_kbhit()) {
            char tecla = _getch();
            if (tecla == -32) {
                tecla = _getch();
                if (tecla == 75 && cazadorX > 0) {
                    cazadorX--;
                }
                else if (tecla == 77 && cazadorX < anchoPantalla - 1) {
                    cazadorX++;
                }
            }
            else if (tecla == 32 && balaX == -1 && balaY == -1) {
                balaX = cazadorX;
                balaY = cazadorY - 1;
            }
        }

        for (auto& bird : aves) {
            bird.x += bird.direction;
            if (bird.x <= 0 || bird.x >= anchoPantalla - 3) {
                bird.direction *= -1;
            }
        }

        if (balaY != -1) {
            balaY--;

            for (size_t i = 0; i < aves.size(); ++i) {
                if (balaX >= aves[i].x && balaX <= aves[i].x + 2 && balaY == aves[i].y) {
                    aves.erase(aves.begin() + i);
                    CantidadAveCazadas++;
                    balaX = -1;
                    balaY = -1;
                    break;
                }
            }

            if (balaY < 0) {
                balaX = -1;
                balaY = -1;
            }
        }

        Sleep(100);
        system("cls");
    }


    setTextColor(15);
    cout << "--------------" << endl;
    cout << "Fin del juego" << endl;
    cout << "Haz cazado: " << CantidadAveCazadas << " aves" << endl;
    cout << "--------------" << endl;


    _getch(); return 0;
}