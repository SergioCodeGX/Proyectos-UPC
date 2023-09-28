#include <iostream>
using namespace std;

int leer_edad();
char leer_sexo();
char leer_plataforma();
char leer_nivel_satisfaccion();

int main() {

    int edad;
    char sexo, plataforma, nivel_satisfaccion;
    int cont_estudiante = 0, cont_adultos =0, cont_estu_plat_canvas=0;
    int cont_nivel_sat_bueno = 0, cont_nivel_sat_regular = 0, cont_nivel_sat_malo = 0 ;
    int edad_mujer_joven=-1;
    double promedio = 0;

    do {
    cout << "Estudiante " << (cont_estudiante+1) <<endl;
    edad = leer_edad();

    if (edad == 0) {
     break;
    }

    sexo = leer_sexo();
    plataforma = leer_plataforma();
    nivel_satisfaccion = leer_nivel_satisfaccion();

    if (edad >= 60) {
    cont_adultos++;
    }

    if (plataforma == 'C') {
    cont_estu_plat_canvas++;
     }

    if (nivel_satisfaccion == 'B') {
    cont_nivel_sat_bueno++;
    }

    else if (nivel_satisfaccion == 'R') {
    cont_nivel_sat_regular++;
    }

    else {
    cont_nivel_sat_malo++;
    }

    if (sexo == 'F' && plataforma != 'M') {
    edad_mujer_joven = edad;
    }

    cout << endl;
    cont_estudiante++;

    } while (edad != 0);

    if (cont_estudiante > 0) {
    promedio = (double)cont_estu_plat_canvas / cont_estudiante;
    }

    cout << "Resultados" << endl;
    cout << "¿Cuantos estudiantes son adultos mayores (adulto mayor es quien tiene 60o mas años)?: " << cont_adultos << endl;
    cout << "¿Cual es el promedio de edad de los estudiantes que utilizan la plataforma Canvas?: " << promedio << endl;
    cout << "¿Cual es el nivel o niveles de satisfaccion que tiene la menor frecuencia?" << endl;

    if (cont_nivel_sat_bueno <= cont_nivel_sat_regular && cont_nivel_sat_bueno <=
    cont_nivel_sat_malo) {
    cout << "Bueno" << endl;
    }

    if (cont_nivel_sat_regular <= cont_nivel_sat_bueno && cont_nivel_sat_regular <=
    cont_nivel_sat_malo) {
    cout << "Regular" << endl;
    }

    if (cont_nivel_sat_malo <= cont_nivel_sat_bueno && cont_nivel_sat_malo <=
    cont_nivel_sat_regular) {
     cout << "Malo" << endl;
    }

    cout << "¿Cual es la edad de la mujer mas joven que no utiliza Moodle?" << endl;
    if (edad_mujer_joven != -1) {
    cout << "La edad es:" << edad_mujer_joven << endl;
    }
    else {
    cout << "No hubo" << endl;
    }
     return 0;
    }

    int leer_edad() {
    int edad;
    do
    {
    cout << "Ingrese su edad:";
    cin >> edad;
    } while ((edad<17 || edad>65) && edad!=0);
r   eturn edad;
}
char leer_sexo() {
char sexo;
do
{
 cout << "Sexo(F:Femenino, M:Masculino):";
cin >> sexo;
sexo = toupper(sexo);
} while (sexo !='F' && sexo!='M');
return sexo;
}
char leer_plataforma() {
char plataforma;
do
{
 cout << "Plataforma(B:Blackboard, C:Canvas, M: Moodle):";
cin >> plataforma;
plataforma = toupper(plataforma);
} while (plataforma != 'B' && plataforma != 'C' && plataforma != 'M');
return plataforma;
}
char leer_nivel_satisfaccion() {
char nivel_satisfaccion;
do
{
 cout << "Nivel de satisfaccion (B:Bueno, R:Regular, M:Malo):";
cin >> nivel_satisfaccion;
nivel_satisfaccion = toupper(nivel_satisfaccion);
} while (nivel_satisfaccion != 'B' && nivel_satisfaccion != 'R' && nivel_satisfaccion !=
'M');
return nivel_satisfaccion;
}