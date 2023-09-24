// Materia: Programación I, Paralelo 1
// Autor: Luciana Cecilia Yahuita Lazarte
// Fecha creación: 24/09/2023
// Fecha modificación: 24/09/2023
// Número de ejericio: 3
// Problema planteado: Realice un programa en C++ con funciones y estructuras para el estacionamiento del
//Multicine.
//Este estacionamiento cuenta con 4 pisos, cada piso tiene distintas capacidades de
//autos
//Piso 1 – 50 autos
//Piso 2 – 40 autos
//Piso 3 – 30 autos
//Piso 4 – 45 autos
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
using namespace std;

struct Automovil {
    char tipo[20];
    char marca[20];
    char modelo[20];
    char color[15];
};

const int capacidad_piso1 = 50;
const int capacidad_piso2 = 40;
const int capacidad_piso3 = 30;
const int capacidad_piso4 = 45;

int vpiso1[capacidad_piso1] = {0};
int vpiso2[capacidad_piso2] = {0};
int vpiso3[capacidad_piso3] = {0};
int vpiso4[capacidad_piso4] = {0};

int vehiculos_ingresados_total = 0;

void contador_espacios(int[], int[], int[], int[], int&, int&, int&, int&, int, int, int, int);
void contador_tipo(Automovil[], int, int&, int&, int&, int&, int&);
void contador_color(Automovil[], int, int&, int&, int&, int&, int&, int&);
void contador_marca(Automovil[], int, int&, int&, int&, int&, int&);

int main() {
    int v;
    int vagoneta = 0, camioneta = 0, automoviles = 0, minivans = 0, motocicletas = 0;
    int rojo = 0, negro = 0, plata = 0, azul = 0, blanco = 0, gris = 0;
    int toyota = 0, suzuki = 0, ford = 0, nissan = 0, volkswagen = 0;

    srand(time(0));
    const int max_vehiculos = capacidad_piso1 + capacidad_piso2 + capacidad_piso3 + capacidad_piso4;
    Automovil aut[max_vehiculos];

    do {
        cout << "Ingrese la cantidad de vehiculos (ingrese 0 si desea terminar la simulacion): ";
        cin >> v;
        cin.ignore();
        if (v == 0) {
            break;
        }

        for (int i = 0; i < v; i++) {
            int piso;
            bool asignado = false;

            while (!asignado) {
                piso = rand() % 4 + 1;
                int* vpiso;

                switch (piso) {
                    case 1:
                        if (vehiculos_ingresados_total < capacidad_piso1) {
                            vpiso = vpiso1;
                            asignado = true;
                        }
                        break;
                    case 2:
                        if (vehiculos_ingresados_total < capacidad_piso2) {
                            vpiso = vpiso2;
                            asignado = true;
                        }
                        break;
                    case 3:
                        if (vehiculos_ingresados_total < capacidad_piso3) {
                            vpiso = vpiso3;
                            asignado = true;
                        }
                        break;
                    case 4:
                        if (vehiculos_ingresados_total < capacidad_piso4) {
                            vpiso = vpiso4;
                            asignado = true;
                        }
                        break;
                }

                if (asignado) {
                    for (int j = 0; j < capacidad_piso1; j++) {
                        if (vpiso[j] == 0) {
                            vpiso[j] = 1;
                            break;
                        }
                    }
                }

                if (!asignado) {
                    cout << "El piso seleccionado está lleno. Espere en la cola." << endl;
                }
            }

            cout << "Ingrese los detalles del vehiculo " << i + 1 << ":" << endl;
            cout << "Tipo (camioneta, automovil, motocicleta, minivan, vagoneta): ";
            cin.getline(aut[vehiculos_ingresados_total].tipo, 20);
            cout << "Marca: ";
            cin.getline(aut[vehiculos_ingresados_total].marca, 20);
            cout << "Modelo: ";
            cin.getline(aut[vehiculos_ingresados_total].modelo, 20);
            cout << "Color (rojo, negro, plata, azul, blanco, gris): ";
            cin.getline(aut[vehiculos_ingresados_total].color, 15);

            vehiculos_ingresados_total++;
        }
    } while (true);

    cout << "Fin de la simulación." << endl;

    int vehiculos_piso1 = 0;
    int vehiculos_piso2 = 0;
    int vehiculos_piso3 = 0;
    int vehiculos_piso4 = 0;

    for (int i = 0; i < capacidad_piso1; i++) {
        if (vpiso1[i] == 1) {
            vehiculos_piso1++;
        }
    }

    for (int i = 0; i < capacidad_piso2; i++) {
        if (vpiso2[i] == 1) {
            vehiculos_piso2++;
        }
    }

    for (int i = 0; i < capacidad_piso3; i++) {
        if (vpiso3[i] == 1) {
            vehiculos_piso3++;
        }
    }

    for (int i = 0; i < capacidad_piso4; i++) {
        if (vpiso4[i] == 1) {
            vehiculos_piso4++;
        }
    }

    cout << "Piso 1: " << vehiculos_piso1 << " vehiculos" << endl;
    cout << "Piso 2: " << vehiculos_piso2 << " vehiculos" << endl;
    cout << "Piso 3: " << vehiculos_piso3 << " vehiculos" << endl;
    cout << "Piso 4: " << vehiculos_piso4 << " vehiculos" << endl;

    contador_tipo(aut, vehiculos_ingresados_total, vagoneta, camioneta, automoviles, minivans, motocicletas);
    cout << "Hay en el parqueo: " << endl;
    cout << "Vagonetas: " << vagoneta << endl;
    cout << "Camionetas: " << camioneta << endl;
    cout << "Automoviles: " << automoviles << endl;
    cout << "Minivans: " << minivans << endl;
    cout << "Motocicletas: " << motocicletas << endl;

    contador_color(aut, vehiculos_ingresados_total, rojo, negro, plata, azul, blanco, gris);
    cout << "Autos rojos: " << rojo << endl;
    cout << "Autos negros: " << negro << endl;
    cout << "Autos plata: " << plata << endl;
    cout << "Autos blancos: " << blanco << endl;
    cout << "Autos grises: " << gris << endl;
    cout << "Autos azules: " << azul << endl;

    contador_marca(aut, vehiculos_ingresados_total, toyota, suzuki, ford, nissan, volkswagen);
    cout << "Toyota: " << toyota << endl;
    cout << "Suzuki: " << suzuki << endl;
    cout << "Ford: " << ford << endl;
    cout << "Nissan: " << nissan << endl;
    cout << "Volkswagen: " << volkswagen << endl;

    return 0;
}

void contador_tipo(Automovil aut[], int v, int& num1, int& num2, int& num3, int& num4, int& num5) {
    for (int i = 0; i < v; i++) {
        if (strcmp(aut[i].tipo, "vagoneta") == 0) {
            num1++;
        }
        if (strcmp(aut[i].tipo, "camioneta") == 0) {
            num2++;
        }
        if (strcmp(aut[i].tipo, "automovil") == 0) {
            num3++;
        }
        if (strcmp(aut[i].tipo, "minivan") == 0) {
            num4++;
        }
        if (strcmp(aut[i].tipo, "motocicleta") == 0) {
            num5++;
        }
    }
}

void contador_color(Automovil aut[], int v, int& numa, int& numb, int& numc, int& numd, int& nume, int& numf) {
    for (int i = 0; i < v; i++) {
        if (strcmp(aut[i].color, "rojo") == 0) {
            numa++;
        }
        if (strcmp(aut[i].color, "negro") == 0) {
            numb++;
        }
        if (strcmp(aut[i].color, "plata") == 0) {
            numc++;
        }
        if (strcmp(aut[i].color, "azul") == 0) {
            numd++;
        }
        if (strcmp(aut[i].color, "blanco") == 0) {
            nume++;
        }
        if (strcmp(aut[i].color, "gris") == 0) {
            numf++;
        }
    }
}

void contador_marca(Automovil aut[], int v, int& a, int& b, int& c, int& d, int& e) {
    for (int i = 0; i < v; i++) {
        if (strcmp(aut[i].marca, "toyota") == 0) {
            a++;
        }
        if (strcmp(aut[i].marca, "suzuki") == 0) {
            b++;
        }
        if (strcmp(aut[i].marca, "ford") == 0) {
            c++;
        }
        if (strcmp(aut[i].marca, "nissan") == 0) {
            d++;
        }
        if (strcmp(aut[i].marca, "volkswagen") == 0) {
            e++;
        }
    }
}

void contador_espacios(int piso1[], int piso2[], int piso3[], int piso4[], int& libres_piso1, int& libres_piso2, int& libres_piso3, int& libres_piso4, int capacidad_piso1, int capacidad_piso2, int capacidad_piso3, int capacidad_piso4) {
    libres_piso1 = capacidad_piso1 - vehiculos_ingresados_total;
    libres_piso2 = capacidad_piso2 - vehiculos_ingresados_total;
    libres_piso3 = capacidad_piso3 - vehiculos_ingresados_total;
    libres_piso4 = capacidad_piso4 - vehiculos_ingresados_total;
}

