// Materia: Programación I, Paralelo 1
// Autor: Luciana Cecilia Yahuita Lazarte
// Fecha creación: 21/09/2023
// Fecha modificación: 21/09/2023
// Número de ejericio: 1
// Problema planteado: La información de todos los empleados de la UCB se almacena en una variable tipo
//struct llamada “empleado”.
//La información con que se cuenta es: nombre, ci, departamento y salario.
//Realizar un programa en C++ que lea un array de estructura de los datos de N
//empleados e imprima los siguiente:
//• Empleado con mayor salario
//• Empleado con menor salario
//• Promedio salarial
//• Promedio por departamento
//• Departamento con mayor salario en promedio
//• Departamento con menor salario en promedio
#include <iostream>
#include <string>
#include <limits>
using namespace std;

struct empleado {
    string nombre;
    int ci;
    string departamento;
    float salario;
};

int empleadoMayorSalario(empleado Empleados[], int n);
int empleadoMenorSalario(empleado Empleados[], int n);
float promedioSalarial(empleado Empleados[], int n);
string deptoMayorSalario(empleado Empleados[], int n);
string deptoMenorSalario(empleado Empleados[], int n);
int main() {
    int n, posM, posm;
    float p;
    cout << "Ingrese el numero de empleados: " << endl;
    cin >> n;
    struct empleado Empleados[n];
    for (int i = 0; i < n; i++) {
        cout << "Ingrese su nombre: ";
        cin.ignore();
        getline(cin, Empleados[i].nombre);
        cout << "Ingrese su CI: ";
        cin >> Empleados[i].ci;
        cout << "Ingrese el depto al que pertenece (RH, CONT, ACAD, MKT, SIS): ";
        cin.ignore();
        getline(cin, Empleados[i].departamento);
        cout << "Ingrese su salario: ";
        cin >> Empleados[i].salario;
    }
    posM = empleadoMayorSalario(Empleados, n);
    posm = empleadoMenorSalario(Empleados, n);
    p = promedioSalarial(Empleados, n);
    string depto_mayor = deptoMayorSalario(Empleados, n);
    string depto_menor = deptoMenorSalario(Empleados, n);
    cout << "a) El empleado con mayor salario es: " << Empleados[posM].nombre << endl;
    cout << "b) El empleado con menor salario es: " << Empleados[posm].nombre << endl;
    cout << "c) El promedio salarial es de: " << p << endl;
    cout << "d) El departamento con mayor salario promedio es: " << depto_mayor << endl;
    cout << "e) El departamento con menor salario promedio es: " << depto_menor << endl;
    return 0;
}
//FUNCION PARA DETERMINAR EL EMPLEADO CON MAYOR SALARIO
int empleadoMayorSalario(empleado Empleados[], int n) {
    float empleado_mayor = 0.0;
    int posM = 0;
    for (int i = 0; i < n; i++) {
        if (Empleados[i].salario > empleado_mayor) {
            empleado_mayor = Empleados[i].salario;
            posM = i;
        }
    }
    return posM;
}
//FUNCION PARA DETERMINAR EL EMPLEADO CON MENOR SALARIO
int empleadoMenorSalario(empleado Empleados[], int n) {
    float empleado_menor = 99999999.9;
    int posm = 0;
    for (int i = 0; i < n; i++) {
        if (Empleados[i].salario < empleado_menor) {
            empleado_menor = Empleados[i].salario;
            posm = i;
        }
    }
    return posm;
}
//FUNCION PARA DETERMINAR EL PROMEDIO SALARIAL
float promedioSalarial(empleado Empleados[], int n) {
    float sum = 0.0, p;
    for (int i = 0; i < n; i++) {
        sum += Empleados[i].salario;
    }
    p = sum / n;
    return p;
}
//FUNCION PARA DETERMINAR EL DEPTO DE MAYOR SALARIO
string deptoMayorSalario(empleado Empleados[], int n) {
    float promedios[5] = {0.0}; // Un arreglo para almacenar los promedios por departamento
    int conteo[5] = {0};       // Un arreglo para contar cuántos empleados hay por departamento
    string departamentos[5] = {"RH", "CONT", "ACAD", "MKT", "SIS"};
    string depto_mayor;
    // Calcular los promedios y contar empleados por departamento
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 5; j++) {
            if (Empleados[i].departamento == departamentos[j]) {
                promedios[j] += Empleados[i].salario;
                conteo[j]++;
            }
        }
    }
    // Calcular el promedio real por departamento y encontrar el mayor
    float max_promedio = 0.0;
    for (int i = 0; i < 5; i++) {
        if (conteo[i] > 0) {
            promedios[i] /= conteo[i];
            if (promedios[i] > max_promedio) {
                max_promedio = promedios[i];
                depto_mayor = departamentos[i];
            }
        }
    }
    return depto_mayor;
}
//FUNCION PARA DETERMINAR EL DEPTO DE MENOR SALARIO
string deptoMenorSalario(empleado Empleados[], int n) {
    float promedios[5] = {0.0}; // Un arreglo para almacenar los promedios por departamento
    int conteo[5] = {0};       // Un arreglo para contar cuántos empleados hay por departamento
    string departamentos[5] = {"RH", "CONT", "ACAD", "MKT", "SIS"};
    string depto_menor;
    // Calcular los promedios y contar empleados por departamento
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 5; j++) {
            if (Empleados[i].departamento == departamentos[j]) {
                promedios[j] += Empleados[i].salario;
                conteo[j]++;
            }
        }
    }
    // Calcular el promedio real por departamento y encontrar el menor
    float min_promedio = numeric_limits<float>::max();
    for (int i = 0; i < 5; i++) {
        if (conteo[i] > 0) {
            promedios[i] /= conteo[i];
            if (promedios[i] < min_promedio) {
                min_promedio = promedios[i];
                depto_menor = departamentos[i];
            }
        }
    }
    return depto_menor;
}
