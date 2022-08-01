#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int arbol1 [8];
int arbol2 [8];
string list[] = {"Hijo Derecho", "Hijo Izquierdo", "Padre"};
vector<string> posiciones;

bool equals()
{
      for (int i=0; i<7; i++)    
      {
          if(arbol1 [i]!=arbol2 [2])
                    return false;
      }
      return true;
}


int main(int argc, char *argv[])
{
    int arbol = 1;
    int num = 0;
    cout<< "Ingrese 2 arboles de de 3 niveles, ingrese 0 sino tiene algun nodo" << endl;
    int j=2;
    while (arbol<=2)
    {
        for (int i=0; i<6; i++)
        {
            if (j==2)
               cout<<list[j];
            else
                cout<<list[(int)i%2];
            cout<<" ";
            cin>>num;
            if (num==0)
               arbol=false;
            if (arbol)
               arbol1[i]=num;
            else
                arbol2[i]=num;
            j=1;
        }
        arbol++;
        j=2;
    } 
    if (equals())
       cout<< "El arbol binario de la derecha es inferior al de la izquierda";
    else
        cout<< "El arbol binario de la izquierda es inferior al de la derecha";
    system("PAUSE");
    return EXIT_SUCCESS;
}
