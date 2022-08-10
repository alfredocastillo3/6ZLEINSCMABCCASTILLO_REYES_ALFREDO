

#include<iostream>

#include<stdio.h>

#include<stdlib.h>

using namespace std;

int main()

{

int cont;

int intento=0;

int faltan=5;

int val;

int saldo=0;

int t=9 ;

int valor=0;

int sum;

in:

cout<<"INGRESE UNA CONTRASENA NUEVA\nNO MAYOR A 8 DIGITOS"<<endl;

cin>> cont;

cout<<"SU CONTRASEÑA ES: "<<cont<<" GUARDELA."<<endl;

system("pause");

system("cls");

men:

cout<<"INGRESE SU CONTRASEÑA"<<endl;

cin>>sum;

intento++;

faltan=faltan-intento;

system("cls");

if(intento==5)

{

cout<<"LIMITE REBAZADO"<<endl;

system("pause");

system("cls");

cont=0;

intento=0;

goto in;

}

if(sum==cont)

{

men2:

cout<<"tipo de transaccion ";
cout<<"1=Deposito";
cout<<" 2=Retiro";
cout<<" 3=Consultar saldo";
cout<<"0=Salir del programa:";

cin>>t;

if(t == 2 )

{

cout<<"\nvalor de transaccion:";

cin>> valor;

if (valor>saldo)

cout<<"Transaccion invalida. Fondos insuficientes"<<endl;

else

saldo = saldo-valor;

cout<<"saldo final:"<<saldo<<endl;

system("pause");

system("cls");

goto men2;

}

if(t==1)

{

cout<<"\n valor de transaccion:";

cin>> valor;

saldo = saldo + valor;

if(valor>100000)

{

cout<<"EL LIMITE DE DEPOSITO EN SU TIPO DE CUENTA ES A 100 MIL."<<endl;

saldo = saldo-valor;

system("pause");

system("cls");

goto men2;

}

cout<<"saldo final:"<<saldo<<endl;

system("pause");

system("cls");

goto men2;

}

if(t==3)

{

cout<<"su saldo actual es igual a: "<<saldo<<endl;

system("pause");

system("cls");

goto men2;

}

else

if (t = 0)

cout<<"Tipo de transaccion invalido:"<<endl;

cout<<"saldo final:"<<saldo<<endl;

return 0;

}

else

    goto men;

return 0;

}
