//GRUPO 5 | D4

#include "pch.h"
#include<iostream>
#include<conio.h>

using namespace std;
using namespace System;

//ESTABLECER TAMAÑO DE VENTANA
void ventana() {
    Console::SetWindowSize(80, 40);
}

//GENERAR VALOR ALEATORIO
int generarValorAletorio(int minValor, int maxValor) {
    return minValor + rand() % (maxValor + 1 - minValor); //Con esto se genera un valor aleatorio entre un rango de valores, por ejemplo entre 1 y 6 generarValorAletorio(1, 6);
}

void titulo_de_juego() {

    Console::ForegroundColor = ConsoleColor::DarkRed;   cout << "  .----------------.  .----------------." << endl;
    Console::ForegroundColor = ConsoleColor::DarkGray; cout << " | .--------------. || .--------------. |" << endl;
    Console::ForegroundColor = ConsoleColor::DarkGray; cout << " | |  ________    | || |   _    _     | |" << endl;
    Console::ForegroundColor = ConsoleColor::DarkGray; cout << " | | |_   ___ `.  | || |  | |  | |    | |" << endl;
    Console::ForegroundColor = ConsoleColor::DarkGreen; cout << " | |   | |   `. \\ | || |  | |__| |_   | |" << endl;
    Console::ForegroundColor = ConsoleColor::DarkGreen; cout << " | |   | |    | | | || |  |____   _|  | |" << endl;
    Console::ForegroundColor = ConsoleColor::DarkGreen; cout << " | |  _| |___.' / | || |      _| |_   | |" << endl;
    Console::ForegroundColor = ConsoleColor::DarkGray; cout << " | | |________.'  | || |     |_____|  | |" << endl;
    Console::ForegroundColor = ConsoleColor::DarkGray; cout << " | |              | || |              | |" << endl;
    Console::ForegroundColor = ConsoleColor::DarkGray; cout << " | '--------------' || '--------------' |" << endl;
    Console::ForegroundColor = ConsoleColor::DarkRed; cout << " '----------------'  '------------------'" << endl;

    cout << endl;

    Console::ForegroundColor = ConsoleColor::White; cout << "Presione para entrar al menu de inicio..." << endl;
    cin.get();
    system("cls");

}

//MENU DE OPCIONES
int generarMenuOpciones() {
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
    system("cls");
    cout << "\nINSTRUCCIONES:" << endl;
    cout << "--------------------------------------------------------------" << endl;
    cout << "| Este es un juego de dados que simula el juego D4.           |" << endl;
    cout << "| Son de 8 partidas | 4 dados                                 |" << endl;
    cout << "--------------------------------------------------------------" << endl;
    cout << "---------------------------------------------------------------" << endl;
    cout << "| El jugador inciara el juego lanzando los dados de forma     |" << endl;
    cout << "| aleatoriay viendo en que interaccion consigue igualar los   |" << endl;
    cout << "| valores iniciales.                                          |" << endl;
    cout << "| Los valores iniciales son los que se obtienen en la primera |" << endl;
    cout << "| tirada de los dados.                                        |" << endl;
    cout << "| La computadora seguira trabjando de forma aleatoria y       |" << endl;
    cout << "| revisando en que momento (de forma iterativa)               |" << endl;
    cout << "| consigue igualar los valores iniciales.                     |" << endl;
    cout << "---------------------------------------------------------------" << endl;
    cout << "--------------------------------------------------------------|" << endl;
    cout << "| Gana el jugador que obtenga mayor numero de dados iguales en|" << endl;
    cout << "| el menor numero de interacciones en una de las 08 partidas. |" << endl;
    cout << "--------------------------------------------------------------" << endl;
    cout << " Presione cualquier tecla para volver al menu principal" << endl;
    _getch();
    system("cls"); //LIMPIAR PANTALLA CUANDO SE PRESIONA UNA TECLA
}

//CREDITOS DEL JUEGO
void creditosDelJuego() {
    system("cls");
    cout << " \nCREDITOS: " << endl;
    cout << "---------------------------------------------------------" << endl;
    cout << "| Juego creado por:                                     |" << endl;
    cout << "---------------------------------------------------------" << endl;
    cout << "---------------------------------------------------------" << endl;
    cout << "| 1.Monroy Ruiz, Sergio Elias                           |" << endl;
    cout << "| 2.Robles Peralta, Martin Miguel                       |" << endl;
    cout << "| 3.Alejandro Romero, Daryl Daniel                      |" << endl;
    cout << "---------------------------------------------------------" << endl;
    cout << "---------------------------------------------------------" << endl;
    cout << " Presione cualquier tecla para volver al menu principal" << endl;
    _getch();
    system("cls"); //LIMPIAR PANTALLA CUANDO SE PRESIONA UNA TECLA
}

//IMPRIMIR DADOS
void imprimirDados(int x, int y, int valor) {

    switch (valor) {
    case 1:
        Console::SetCursorPosition(x, y);     cout << " ------- ";
        Console::SetCursorPosition(x, y + 1); cout << "|       |";
        Console::SetCursorPosition(x, y + 2); cout << "|   O   |";
        Console::SetCursorPosition(x, y + 3); cout << "|       |";
        Console::SetCursorPosition(x, y + 4); cout << " ------- ";
        break;
    case 2:
        Console::SetCursorPosition(x, y);     cout << " ------- ";
        Console::SetCursorPosition(x, y + 1); cout << "| O     |";
        Console::SetCursorPosition(x, y + 2); cout << "|       |";
        Console::SetCursorPosition(x, y + 3); cout << "|     O |";
        Console::SetCursorPosition(x, y + 4); cout << " ------- ";
        break;
    case 3:
        Console::SetCursorPosition(x, y);     cout << " ------- ";
        Console::SetCursorPosition(x, y + 1); cout << "| O     |";
        Console::SetCursorPosition(x, y + 2); cout << "|   O   |";
        Console::SetCursorPosition(x, y + 3); cout << "|     O |";
        Console::SetCursorPosition(x, y + 4); cout << " ------- ";
        break;
    case 4:
        Console::SetCursorPosition(x, y);     cout << " ------- ";
        Console::SetCursorPosition(x, y + 1); cout << "| O   O |";
        Console::SetCursorPosition(x, y + 2); cout << "|       |";
        Console::SetCursorPosition(x, y + 3); cout << "| O   O |";
        Console::SetCursorPosition(x, y + 4); cout << " ------- ";
        break;
    case 5:
        Console::SetCursorPosition(x, y);     cout << " ------- ";
        Console::SetCursorPosition(x, y + 1); cout << "| O   O |";
        Console::SetCursorPosition(x, y + 2); cout << "|   O   |";
        Console::SetCursorPosition(x, y + 3); cout << "| O   O |";
        Console::SetCursorPosition(x, y + 4); cout << " ------- ";
        break;
    case 6:
        Console::SetCursorPosition(x, y);     cout << " ------- ";
        Console::SetCursorPosition(x, y + 1); cout << "| O   O |";
        Console::SetCursorPosition(x, y + 2); cout << "| O   O |";
        Console::SetCursorPosition(x, y + 3); cout << "| O   O |";
        Console::SetCursorPosition(x, y + 4); cout << " ------- ";
        break;
    default:
        break;
    }
}

//MOSTRAR GANADOR DE LA RONDA
void mostrarGanadorRonda(int ganador) {

    if (ganador == 1) {
        Console::SetCursorPosition(1, 20); cout << "Jugador 1 gana la ronda | (Presiona enter para continuar)";
    }
    else if (ganador == 2) {
        Console::SetCursorPosition(1, 20); cout << "Jugador 2 gana la ronda | (Presiona enter para continuar)";
    }
    else {
        Console::SetCursorPosition(1, 20); cout << "La ronda termina en empate | (Presiona enter para continuar)";
    }
    _getch();
    system("cls");
}

//MOSTRAR GANADOR DE LA PARTIDA
void mostrarGanadorPartida(int resultadoJugador1, int resultadoJugador2) {

    if (resultadoJugador1 > resultadoJugador2) {
        Console::SetCursorPosition(1, 20); cout << "Jugador 1 gana la partida | (Presiona enter para volver al menu principal)" << endl;
    }
    else if (resultadoJugador1 < resultadoJugador2) {
        Console::SetCursorPosition(1, 20); cout << "Jugador 2 gana la partida | (Presiona enter para volver al menu principal)" << endl;
    }
    else {
        Console::SetCursorPosition(1, 20); cout << "La partida termina en empate | (Presiona enter para volver al menu principal)" << endl;
    }

    _getch();
    system("cls");
}

//FUNCION PARA SIMULAR EL JUEGO
void simularJuego() { 

    int numPartidas = 8;

    int partidasJugadas1 = 0;
    int partidasJugadas2 = 0;
    int contadorPartidas1 = 1;
    int contadorPartidas2 = 1;

    int dadoUno = 0;
    int dadoDos = 0;
    int dadoTres = 0;
    int dadoCuatro = 0;
    char deseaContinuar;

    //REPETICIONES DE DADOS PARA CADA JUGADOR

    int repeticionesDadoUno1 = 0;
    int repeticionesDadoDos1 = 0;
    int repeticionesDadoTres1 = 0;
    int repeticionesDadoCuatro1 = 0;

    int repeticionesDadoUno2 = 0;
    int repeticionesDadoDos2 = 0;
    int repeticionesDadoTres2 = 0;
    int repeticionesDadoCuatro2 = 0;

    int ganadorRonda = 0;

    int resultadoJugador1 = 0;
    int resultadoJugador2 = 0;


    system("cls");

    while (true) {

        //JUGADOR 1

        //---------------------------------------//

        //GENERAR DADOS PARA EL JUGADOR 1
        dadoUno = generarValorAletorio(1, 6);
        dadoDos = generarValorAletorio(1, 6);
        dadoTres = generarValorAletorio(1, 6);
        dadoCuatro = generarValorAletorio(1, 6);

        //IMPRIMIR DADOS PARA EL JUGADOR 1
        cout << " Jugador 1: " << endl;
        cout << " " << contadorPartidas1++ << " ronda" << endl;
        imprimirDados(10, 6, dadoUno);
        imprimirDados(30, 6, dadoDos);
        imprimirDados(10, 13, dadoTres);
        imprimirDados(30, 13, dadoCuatro);

        //VERIFICAR Y CONTAR LAS REPETICIONES DE DADOS PARA EL JUGADOR 1
        if (dadoUno == dadoDos || dadoUno == dadoTres || dadoUno == dadoCuatro) repeticionesDadoUno1++;
        if (dadoDos == dadoUno || dadoDos == dadoTres || dadoDos == dadoCuatro) repeticionesDadoDos1++;
        if (dadoTres == dadoUno || dadoTres == dadoDos || dadoTres == dadoCuatro) repeticionesDadoTres1++;
        if (dadoCuatro == dadoUno || dadoCuatro == dadoDos || dadoCuatro == dadoTres) repeticionesDadoCuatro1++;

        cout << endl;
        cout << endl;
        cout << endl;
        cout << endl;

        partidasJugadas1++;

        //VERIFICAR SI SE HAN JUGADO LAS 8 PARTIDAS
        if (partidasJugadas1 > numPartidas) {
			break;
		}

        cout << "\n(S) PARA LANZAR LOS DADOS: " << endl;
        cin >> deseaContinuar;
        deseaContinuar = toupper(deseaContinuar);

        if (deseaContinuar != 'S') {
            break;
        }

        system("cls");

        //JUGADOR 2

        //---------------------------------------//

        //GENERAR DADOS PARA EL JUGADOR 2
        dadoUno = generarValorAletorio(1, 6);
        dadoDos = generarValorAletorio(1, 6);
        dadoTres = generarValorAletorio(1, 6);
        dadoCuatro = generarValorAletorio(1, 6);

        //IMPRIMIR DADOS PARA EL JUGADOR 2
        cout << " Jugador 2: " << endl;
        cout << " " << contadorPartidas2++ << " ronda" << endl;
        imprimirDados(10, 6, dadoUno);
        imprimirDados(30, 6, dadoDos);
        imprimirDados(10, 13, dadoTres);
        imprimirDados(30, 13, dadoCuatro);

        //VERIFICAR Y CONTAR LAS REPETICIONES DE DADOS PARA EL JUGADOR 2
        if (dadoUno == dadoDos || dadoUno == dadoTres || dadoUno == dadoCuatro) repeticionesDadoUno2++;
        if (dadoDos == dadoUno || dadoDos == dadoTres || dadoDos == dadoCuatro) repeticionesDadoDos2++;
        if (dadoTres == dadoUno || dadoTres == dadoDos || dadoTres == dadoCuatro) repeticionesDadoTres2++;
        if (dadoCuatro == dadoUno || dadoCuatro == dadoDos || dadoCuatro == dadoTres) repeticionesDadoCuatro2++;

        cout << endl;
        cout << endl;
        cout << endl;
        cout << endl;

        partidasJugadas2++;

        //VERIFICAR SI SE HAN JUGADO LAS 8 PARTIDAS
        if (partidasJugadas2 == numPartidas) {
            break;
        }

        cout << "\n(S) PARA LANZAR LOS DADOS: " << endl;
        cin >> deseaContinuar;
        deseaContinuar = toupper(deseaContinuar);

        //---------------------------------------//

        // CALCULAR EL GANADOR DE LA RONDA
        if (repeticionesDadoUno1 + repeticionesDadoDos1 + repeticionesDadoTres1 + repeticionesDadoCuatro1 >
            repeticionesDadoUno2 + repeticionesDadoDos2 + repeticionesDadoTres2 + repeticionesDadoCuatro2) {
            ganadorRonda = 1;
        }
        else if (repeticionesDadoUno1 + repeticionesDadoDos1 + repeticionesDadoTres1 + repeticionesDadoCuatro1 <
            repeticionesDadoUno2 + repeticionesDadoDos2 + repeticionesDadoTres2 + repeticionesDadoCuatro2) {
            ganadorRonda = 2;
             }

        mostrarGanadorRonda(ganadorRonda);

    }

    //CALCULAR EL GANADOR DE LA PARTIDA
    resultadoJugador1 = repeticionesDadoUno1 + repeticionesDadoDos1 + repeticionesDadoTres1 + repeticionesDadoCuatro1;
    resultadoJugador2 = repeticionesDadoUno2 + repeticionesDadoDos2 + repeticionesDadoTres2 + repeticionesDadoCuatro2;

    mostrarGanadorPartida(resultadoJugador1, resultadoJugador2);
}

int main()
{
    ventana();
    titulo_de_juego();
    srand(time(NULL));

    int opcion;

    //MENU DE OPCIONES
    do
    {
        opcion = generarMenuOpciones();

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