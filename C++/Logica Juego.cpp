#include "pch.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace System;
using namespace std;

int main() {
    srand(time(0));

    int jugador1_puntaje = 0;
    int jugador2_puntaje = 0;

    int num_partidas;
    cout << "Ingrese el número de partidas (entre 5 y 10): ";
    cin >> num_partidas;

    if (num_partidas < 5 || num_partidas > 10) {
        cout << "El número de partidas debe estar entre 5 y 10." << endl;
        return 1;
    }

    for (int partida = 1; partida <= num_partidas; partida++) {
        int carta_jugador1 = rand() % 13 + 1;
        int carta_jugador2 = rand() % 13 + 1;

        cout << "Partida " << partida << ":" << endl;
        cout << "Jugador 1 eligió la carta " << carta_jugador1 << endl;
        cout << "Jugador 2 eligió la carta " << carta_jugador2 << endl;

        // Lógica para determinar el ganador de la partida
        if ((carta_jugador1 <= 4 && carta_jugador2 >= 9) ||
            (carta_jugador1 >= 9 && carta_jugador2 <= 4)) {
            jugador1_puntaje += 100;
            cout << "¡Jugador 1 gana la partida!" << endl;
        }
        else if ((carta_jugador1 <= 8 && carta_jugador2 >= 5) ||
            (carta_jugador1 >= 5 && carta_jugador2 <= 8)) {
            jugador2_puntaje += 100;
            cout << "¡Jugador 2 gana la partida!" << endl;
        }
        else {
            cout << "Empate en esta partida. Se juega de nuevo." << endl;
            partida--; // Repetir la partida en caso de empate.
        }
    }

    // Determinar al ganador del juego
    if (jugador1_puntaje > jugador2_puntaje) {
        cout << "¡Jugador 1 gana el juego con " << jugador1_puntaje << " puntos!" << endl;
    }
    else if (jugador2_puntaje > jugador1_puntaje) {
        cout << "¡Jugador 2 gana el juego con " << jugador2_puntaje << " puntos!" << endl;
    }
    else {
        cout << "¡El juego termina en empate!" << endl;
    }

    return 0;
}