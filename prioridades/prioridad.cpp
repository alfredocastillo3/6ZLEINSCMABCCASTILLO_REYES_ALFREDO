#include <iostream>
using namespace std;

int main()
{
    // La clave correcta
    
    cout << "Bienvenido al cajero automático\n";
    cout << "Ingrese la clave: ";
    string clave = "";
    cin >> clave;
   
    {
        cout << "Clave incorrecta";
        // Con return detenemos la ejecución del programa
        return 0;
    }
    // Si llegamos hasta aquí, podemos estar seguros de que el usuario introdujo la clave correcta
    cout << "Clave correcta\nBienvenido\n";
    double fondos = 5000; // Simular fondos

    string eleccion = "";
    // Menú
    while (eleccion != "2")
    {
        // Mostrar fondos
        cout << "Fondos disponibles: " << fondos << endl;
        // Imprimir menú
        cout << "1. Retirar dinero\n2. Salir\nSeleccione: ";
        cin >> eleccion;
        if (eleccion == "1")
        {
            // Solicitar cuánto se retira
            double retiro;
            cout << "Ingrese cantidad a retirar: " << endl;
            cin >> retiro;
            // Comprobar si puede retirar
            if (retiro > fondos || retiro <= 0)
            {
                cout << "No puede retirar esa cantidad";
            }
            else
            {
                // En caso de que sí pueda retirar
                cout << "OK. Ha retirado " << retiro << endl;
                // Restamos los fondos existentes
                fondos = fondos - retiro;
                // Y el ciclo sigue...
            }
        }
    }
    return 0;
}
