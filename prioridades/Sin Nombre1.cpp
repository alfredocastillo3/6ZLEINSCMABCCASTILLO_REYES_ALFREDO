
#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <string>
#include <iomanip> // permite el redondeo matemático a lugares decimales

using namespace std;
// Declarar clase CuentaBancaria
class BankAccount {
    // Declarar variables
 private:
   string pinNum;
   char accType;
   double balance;
   double amount;

public:
   /// Constructor de BankAccount
   BankAccount(){
      // Inicializar variables de saldo y cantidad
      balance = 0.0;
      amount = 0.0;
   }

   // Declarar prototipos de funciones
   void pinNumber();
   void accountType();
   void balanceChecking();
   void balanceSavings();
   void deposit();
   void withdraw();
   void display();
};  // Fin de la clase CuentaBancaria

// Función para recuperar pinNumber del usuario final
void BankAccount::pinNumber()
{
   cout << "________________________________________________________________________________";
   cout << " \n\t\t\t         CAJERO AUTOMATICO " << endl;
   cout << "________________________________________________________________________________";
  // solicita al usuario final el número PIN para acceder a la cuenta bancaria
   cout << "\n\t\t\t  INGRESE EL         PIN: \n " <<endl;
   cout << "\t\t\t\t      ";

  // For loop para permitir que el usuario vuelva a ingresar el pin 4 veces si no es válido
   for(int i = 0; i <= 3; i++) {
   // Máscara pinNum con asteriscos
     char ch;
     cout << setw(1); // Espacio de formato de salida
     ch = _getch();
     while(ch != 13){
        pinNum.push_back(ch); // presione pinNum y reemplace con asterisco
        cout << '*';
        ch = _getch();
     }

      
      // Establecer pinNum 
      if(pinNum == "utc2020") {
         cout << "\n\n\t\t\t    ¡Bienvenido a tu cuenta!" << endl;
        // Muestra el menú de opciones si pinNumber es correcto
         display();

         // Verificar si pinNum contiene todo
         while(!(cin >> pinNum)) {
             // Restablecer la entrada
            cin.clear();
	      // Obtener entrada de cadenat
	       while (cin.get() != '\n')
              continue;
           // Ask user to try again:
           cout << "\n\t\t\t     Introduzca un PIN:  ";
         } // End while cin
     // Pide al usuario que vuelva a intentarlo:
    } else if (i >= 4) {
         cout << " \n\t\t\t    ¡Tu cuenta está bloqueada! \n " ;
      	 cout << " \t\t\t    Has alcanzado el límite de intentos. " << endl;
         // Si el usuario ingresa un pin numérico no válido, permita volver a ingresar el pin
      } else {
         cout << " \n\t\t\t    Número PIN no válido \n " ;
         cout << " \t\t\t    Introduzca el número PIN de nuevo: \n " ;
         cout << "\t\t\t\t   ";
         cin >> pinNum;
      }// Fin de lo contrario
   }// Fin del bucle pinNum
}// Fin de la función pinNumber


// Función para recuperar el tipo de cuenta del usuario final
void BankAccount::accountType(){
  cout << " \n\t\t\t Seleccionar tipo de cuenta: \n " ;
  cout << " \t\t\t Cuenta Corriente 'C' o Ahorro 'S': " ;
  cin >> accType;


  // Si se ingresa C o c, mostrar Cuenta de cheques 
  if(accType == 'C' || accType == 'c') {
     cout << "\t\t\t================================" << endl << endl;
     cout << "\t\t\t\tCuenta " << endl << endl;
     cout << "\t\t\t================================" << endl << endl;
  // Else if S or s is entered display Savings Account
  } else if (accType == 'S' || accType == 's') {
     cout << "\t\t\t================================" << endl << endl;
     cout << "\t\t\t\tCuenta de Ahorro" <<endl << endl;
     cout << "\t\t\t================================" << endl << endl;
  } else {
   cout << " \t\t\t Tipo de cuenta no válido. \n " ;
    cout << " \t\t\t Seleccionar tipo de cuenta: 'C' o 'S': " ;
    cin >> accType;
  }
} // Fin de la función getAccountType

// Función de depósito
void BankAccount::deposit(){
   cout << " \n\t\t\t\t     DEPOSITO \n " ;
   cout << " \t\t\t    Ingrese el monto del deposito $ " ;
   cin >> amount;
   cout << "\n\t\t\t========deposito========" << endl << endl;
   cout << setprecision(2) << fixed; //round decimal 2 places
   cout << "\t\t\t Cantidad depositada = $" << amount << endl << endl;
   balance += amount;
   cout << "\t\t\t Nuevo saldo  $" << balance << endl << endl;
   cout << "\t\t\t===============================" << endl;
}// End deposit function

// Withdraw function
void BankAccount::withdraw(){
  cout << " \n\t\t\t\t     RETIRAR \n " ;
  cout << " \t\t\t    Ingrese el monto a retirar $ " ;
  cin >> amount;
  cout << "\n\t\t\t=======Retirar recibo==========" << endl << endl;
  cout << "\t\t\t Monto retirado = $" << amount << endl << endl;
  balance -= amount;
  cout << "\t\t\t Nuevo saldo $" << balance << endl <<endl;
  cout << "\t\t\t=================================" << endl;
}// End withdraw function

// Function to display Checking account balance
void BankAccount::balanceChecking() {
   cout <<"\n\t\t\t======Saldo de cuenta corriente======";
   cout << "\n\t\t\t Cuenta de cheques # xxxxxxxx4567\n";
   //balance = 10000;
   cout << "\n\t\t\t Balance = $" << balance << endl;
   cout <<"\n\t\t\t==================================" << endl;
}// End getBalanceChecking function

// Function to display Savings account balance
void BankAccount::balanceSavings() {
  cout << " \n\t\t\t =====Saldo de cuenta corriente===== " ;
   cout << " \n\t\t\t Cuenta de cheques # xxxxxxxx4567 \n " ;
  //balance = 25000;
  cout << "\n\t\t\t Saldo = $" << balance << endl;
  cout << "\n\t\t\t=================================" << endl;
}// End balanceSavings function

// Display options menu after entering pin number
void BankAccount::display(){
  int options = 1;
     // While options is not zero allow enduser to select an option to access bankaccount
      while( options != 0 ) {
        cout << "\n\t\t\t  1. Tipo de cuenta \n";
        cout << "\t\t\t  2. Depósito\n";
        cout << "\t\t\t  3. Retirar \n";
        cout << "\t\t\t  4. Comprobación del saldo de la cuenta \n";
        cout << "\t\t\t  5. Saldo de la cuenta de ahorros\n";
        cout << "\t\t\t  0.Finalizar transacciones \n";
        cout <<"\n\t\t\t\t\t";
        cin >> options;

       // Switch statement to call functions based on end user selected option
        switch (options) {
          case 0: pinNumber();
          break;
          case 1: accountType();
          break;
          case 2: deposit();
          break;
          case 3: withdraw();
          break;
          case 4: balanceChecking();
          break;
          case 5: balanceSavings();
          break;
          default: cout << "\n\t\t\t    Opción no válida" << endl;
        }
      }
}

int main()
{
  // Change screen text color
  system("color 0b");
   // Declare BankAccount Object
   BankAccount bank;
   // Call functions
   bank.pinNumber();
   bank.accountType();
   bank.balanceChecking();
   bank.balanceSavings();
   bank.deposit();
   bank.withdraw();

   return 0;
}
