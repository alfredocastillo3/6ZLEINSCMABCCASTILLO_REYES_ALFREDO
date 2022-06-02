#include <iostream>
using namespace std;
void Edad( int anioAct , int mesAct, int fechAct, int anioNac, int mesNac, int fechNac);
int main ()
{
    int anioAct;
    int mesAct; 
    int fechAct; 
    int anioNac; 
    int mesNac;
    int fechNac; 
 
    cout << "Ingrese Año Actual: ";cin>>anioAct;
    cout << "Ingrese Mes Actual: ";cin>>mesAct;
    cout << "Ingrese Fecha Actual: ";  cin >> fechAct;
    cout << "\nIngrese Año Nacimiento: ";cin>>anioNac;
    cout << "Ingrese Mes de Nacimiento: ";cin>>mesNac;
    cout << "Ingrese Fecha de Nacimiento: ";cin>>fechNac;
    Edad( anioAct , mesAct, fechAct, anioNac, mesNac, fechNac);
    return 0;
}
void Edad( int anioAct , int mesAct, int fechAct, int anioNac, int mesNac, int fechNac)
{
    int respFech , respMes;
    if ( fechAct < fechNac  )
    {   
        fechAct = fechAct + 30; 
        mesAct = mesAct - 1; 
        respFech =  fechAct - fechNac; 
    }
    else 
        respFech =  fechAct - fechNac;  
    if( mesAct < mesNac )
    {   
        mesAct = mesAct + 12; 
        anioAct = anioAct - 1 ; 
        respMes = mesAct - mesNac; 
    }
    else 
        respMes = mesAct - mesNac; 
    cout << "\nUd. tiene:\n";
    cout << " Edad: " <<anioAct - anioNac << endl; 
    cout << " Mes: " << respMes << endl; 
    cout << " Dia: " << respFech << endl; 
}
