// Materia: Programación I, Paralelo 1
// Autor: Luciana Cecilia Yahuita Lazarte
// Fecha creación: 24/09/2023
// Fecha modificación: 24/09/2023
// Número de ejericio: 2
// Problema planteado: De acuerdo con la siguiente estructura, realice en C++ un programa que lea N atletas y
//nos devuelva el país que mayor número de medallas ha ganado.
#include <iostream>
using namespace std;
struct datos{
    char nombre [40];
    char pais [25];
};
struct atleta{
    char deporte [30];
    struct datos pers;
    int nmedallas;
};
int atleta_max(atleta ats [], int n);
int main (){
    int n, posM;
    cout<<"Ingrese la cantidad (n) de atletas: ";
    cin>>n;
    cin.ignore();
    struct atleta ats[n];
    for (int i=0;i<n;i++){
        cout<<"Ingrese el deporte que practica el atleta "<<i+1<<": ";
        cin.getline(ats[i].deporte,30);
        cout<<"Ingrese el nombre del atleta "<<i+1<<": ";
        cin.getline(ats[i].pers.nombre,40);
        cout<<"Ingrese el pais del atleta "<<i+1<<": ";
        cin.getline(ats[i].pers.pais,25);
        cout<<"Ingre la cantidad de medallas que gano el atleta "<<i+1<<": ";
        cin>>ats[i].nmedallas;
         cin.ignore();
    }
    posM=atleta_max(ats, n);
    cout<<"******************DATOS DEL ATLETA CON MAYOR NUMERO DE MEDALLAS****************************"<<endl;
    cout<<"Nombre: "<<ats[posM].pers.nombre<<endl;
    cout<<"Pais: "<<ats[posM].pers.pais<<endl;
    cout<<"Deporte: "<<ats[posM].deporte<<endl;
    cout<<"Numero de medallas: "<<ats[posM].nmedallas<<endl;
    return 0;
}
//funcion que determina el atleta con mayor numero de medallas
int atleta_max(atleta ats [], int n){
    int mayor_nummedallas=0;
    int posM=0;
    for (int i=0;i<n;i++){
        if (ats[i].nmedallas>mayor_nummedallas){
            mayor_nummedallas=ats[i].nmedallas;
            posM=i;
        }
    }
    return posM;
}
