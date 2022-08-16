#include<wchar.h>
#include<locale.h>
#include<fstream>
#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include <string>
#include <cstdlib>
#include <time.h>
#include<windows.h>

#define USER "2222"
#define PASS "1234"
#define user "1111"
#define pass "123"

using namespace std;

//estructura de la cola

struct ICO{
	char nombre[10];
	char app[10];
	char apm[10];
	char fechanac[10];
	char genero[10];
	float peso, altura, imc, muneca, brazo, antebrazo, muslo, pantorrilla, cintura, cadera, humero, biceps, triceps, subescapular, suprailiaco;
};

struct Nodo{
	ICO pacientes;
	Nodo *siguiente;
};



//metodos
void login();
void menuadmin();
void menuuser();
void menucita();
void menuexp();
void tiempo();
void agregarDatos(ICO &);
void insertarDatos(Nodo *&, Nodo *&, ICO);
void buscarDatos(Nodo *, ICO);
void modificarDato(Nodo *, ICO);
void eliminarDatos(Nodo *&, Nodo *&, ICO);
void consultar(ifstream &lec);
void buscar(ifstream &lec);
void agregar(ofstream &es);
void editarexp(ifstream &loec);
void borrarexp(ifstream &lec);
bool c_vacia(Nodo *);


int main(){
	
	setlocale(LC_ALL,"*");
	
    
    login();
	
	return 0;
}

void login(){
	string usuario, password;
	int contador = 0;
	bool ingresa = false;
	bool ingresa1 = false;
	
	do{
		system("cls");
		cout<<"\n\t                    ";
		cout<<"\n\t       BIENVENIDO               ";
		cout<<"\n\t                        ";
		cout<<"\n\t    INICIO DE SESION    ";
		cout<<"\n\t                        ";
		cout<<"\n\t        Usuario: ";
		getline(cin, usuario);
		cout<<"\n\t     Contraseña: ";
		
		char caracter;
		caracter = getch();
		
		password = "";
		
		while (caracter != 13){
			password.push_back(caracter);
			cout<<"*";
			caracter = getch();
		}
		
		cout<<"\n\t                     n";
		
		if (usuario == USER && password == PASS){
			ingresa = true;
			system("cls");
		}else if(usuario == user && password == pass){
			ingresa1 = true;
			system("cls");
		}else{
			cout<<"\n\t El Usuario y/o Password son incorrectos\n"<<endl;
			contador++;
			system("pause");
		}
	}while ((ingresa == false && contador < 3) && (ingresa1 == false && contador < 3));
	
	if(ingresa != false){
		menuadmin();
	}else if(ingresa1 != false){
		menuuser();
	}else{
		system("cls");
		cout<<"\n\t Demasiados Intentos comuniquese con TI"<<endl;
	}
}

void  menuadmin(){
	ofstream esc;
	char opcion;
	
	cout<<endl<<"\t      Menú Especialista     ";
	cout<<endl<<"\t 1. Citas                          ";
	cout<<endl<<"\t 2. Expediente Clinico             ";
	cout<<endl<<"\t 3. IMC                           ";
	cout<<endl<<"\t 4. Salir                          ";
	cout<<endl<<"Opción:";
	
	cin>>opcion;
	fflush(stdin);
		
	do{
		switch(opcion){
			case '1':
				system("cls");
				menucita();
			break;
			
			case '2':
				system("cls");
				agregar(esc);
				menuexp();
			break;
			
			case '3':
				system("cls");
				char gen,imcr,Nmi;
//int m=1, f=2;
float fdn;
double alt1,alt2,pes2,pes1,eda,imc,obj;
cout<<"introduzca su edad: "<<endl;
	cin>>eda;
	if (eda>=100){
	cout<<"introduce tu altura(m): "<<endl;
	cin>>alt1;
	cout<<"ahora introduzca se peso(Kg): "<<endl;
	cin>>pes1;
	imc=pes1/(alt1*alt1);
	if (imc<18.5){
		cout<<"Segun la estatura y el peso ingresados, el IMC es "<<imc<<" ,para un individuo de "<<eda<<" aï¿½os es una persona con bajo peso"<<endl;
	}
	if (imc>18.5&&imc<24.9){
		cout<<"Segun la estatura y el peso ingresados, el IMC es "<<imc<<" ,para un individuo de "<<eda<<" aï¿½os es una persona saludable"<<endl;
	}
	if (imc>25&&imc<29.9){
		cout<<"Segun la estatura y el peso ingresados, el IMC es "<<imc<<" ,para un individuo de "<<eda<<" aï¿½os es una persona con sobrepeso"<<endl;
	}
	if (imc>30&&imc<34.9){
		cout<<"Segun la estatura y el peso ingresados, el IMC es "<<imc<<" ,para un individuo de "<<eda<<" aï¿½os es una persona con obesidad I"<<endl;
	}
	if (imc>35&&imc<39.9){
		cout<<"Segun la estatura y el peso ingresados, el IMC es "<<imc<<" ,para un individuo de "<<eda<<" aï¿½os es una persona con obesidad II"<<endl;
	}
	if (imc>40&&imc<49.9){
		cout<<"Segun la estatura y el peso ingresados, el IMC es "<<imc<<" ,para un individuo de "<<eda<<" aï¿½os es una persona con obesidad III"<<endl;
	}
	if (imc>50){
		cout<<"Segun la estatura y el peso ingresados, el IMC es "<<imc<<" ,para un individuo de "<<eda<<" aï¿½os es una persona con obesidad IV"<<endl;
	}
}
else
{
	cout<<"introduzca su Genero (M o F):"<<endl;
	cin>>gen;
	
    if(gen=='m'){
	cout<<"introduce tu altura(m): "<<endl;
	cin>>alt2;
	cout<<"ahora introduzca se peso(kg): "<<endl;
	cin>>pes2;
	imc=pes2/(alt2*alt2);
	if (imc<18.5){
		cout<<"Segun la estatura y el peso ingresados, el IMC es "<<imc<<" ,para un hombre de "<<eda<<" aï¿½os es una persona con bajo peso"<<endl;
	}
	else if (imc>=18.5){
		cout<<"Segun la estatura y el peso ingresados, el IMC es "<<imc<<" ,para un hombre de "<<eda<<" aï¿½os es una persona saludable"<<endl;
	}
	else if (imc>=25){
		cout<<"Segun la estatura y el peso ingresados, el IMC es "<<imc<<" ,para un hombre de "<<eda<<" aï¿½os es una persona con sobrepeso"<<endl;
	}
	else if (imc>=30){
		cout<<"Segun la estatura y el peso ingresados, el IMC es "<<imc<<" ,para un hombre de "<<eda<<" aï¿½os es una persona con obesidad I"<<endl;
	}
	else if (imc>=35){
		cout<<"Segun la estatura y el peso ingresados, el IMC es "<<imc<<" ,para un hombre de "<<eda<<" aï¿½os es una persona con obesidad II"<<endl;
	}
	else if (imc>=40){
		cout<<"Segun la estatura y el peso ingresados, el IMC es "<<imc<<" ,para un hombre de "<<eda<<" aï¿½os es una persona con obesidad III"<<endl;
	}
	else if (imc>=50){
		cout<<"Segun la estatura y el peso ingresados, el IMC es "<<imc<<" ,para un hombre de "<<eda<<" aï¿½os es una persona con obesidad IV"<<endl;
	}
}

	if(gen=='f'){
	
	cout<<"introduce tu altura(m): "<<endl;
	cin>>alt1;
	cout<<"ahora introduzca se peso(kg): "<<endl;
	cin>>pes1;
	imc=pes1/(alt1*alt1);
	if (imc<18.5){
		cout<<"Segun la estatura y el peso ingresados, el IMC es "<<imc<<" ,para una mujer de "<<eda<<" aï¿½os es una persona con bajo peso"<<endl;
	}
	else if (imc>=18.5){
		cout<<"Segun la estatura y el peso ingresados, el IMC es "<<imc<<" ,para una mujer de "<<eda<<" aï¿½os es una persona saludable"<<endl;
	}
	else if (imc>=25){
		cout<<"Segun la estatura y el peso ingresados, el IMC es "<<imc<<" ,para una mujer de "<<eda<<" aï¿½os es una persona con sobrepeso"<<endl;
	}
	else if (imc>=30){
		cout<<"Segun la estatura y el peso ingresados, el IMC es "<<imc<<" ,para una mujer de "<<eda<<" aï¿½os es una persona con obesidad I"<<endl;
	}
	else if (imc>=35){
		cout<<"Segun la estatura y el peso ingresados, el IMC es "<<imc<<" ,para una mujer de "<<eda<<" aï¿½os es una persona con obesidad II"<<endl;
	}
	else if (imc>=40){
		cout<<"Segun la estatura y el peso ingresados, el IMC es "<<imc<<" ,para una mujer de "<<eda<<" aï¿½os es una persona con obesidad III"<<endl;
	}
	else if (imc>=50){
		cout<<"Segun la estatura y el peso ingresados, el IMC es "<<imc<<" ,para una mujer de "<<eda<<" aï¿½os es una persona con obesidad IV"<<endl;
	}
}
}
cout<<"Desea repetir la medicion (S/N):"<<endl;
cin>>Nmi;
do{
	cout<<"introduzca su edad: "<<endl;
	cin>>eda;
	if (eda>=100){
	cout<<"introduce tu altura(m): "<<endl;
	cin>>alt1;
	cout<<"ahora introduzca se peso(Kg): "<<endl;
	cin>>pes1;
	imc=pes1/(alt1*alt1);
	if (imc<18.5){
		cout<<"Segun la estatura y el peso ingresados, el IMC es "<<imc<<" ,para un individuo de "<<eda<<" aï¿½os es una persona con bajo peso"<<endl;
	}
	if (imc>18.5&&imc<24.9){
		cout<<"Segun la estatura y el peso ingresados, el IMC es "<<imc<<" ,para un individuo de "<<eda<<" aï¿½os es una persona saludable"<<endl;
	}
	if (imc>25&&imc<29.9){
		cout<<"Segun la estatura y el peso ingresados, el IMC es "<<imc<<" ,para un individuo de "<<eda<<" aï¿½os es una persona con sobrepeso"<<endl;
	}
	if (imc>30&&imc<34.9){
		cout<<"Segun la estatura y el peso ingresados, el IMC es "<<imc<<" ,para un individuo de "<<eda<<" aï¿½os es una persona con obesidad I"<<endl;
	}
	if (imc>35&&imc<39.9){
		cout<<"Segun la estatura y el peso ingresados, el IMC es "<<imc<<" ,para un individuo de "<<eda<<" aï¿½os es una persona con obesidad II"<<endl;
	}
	if (imc>40&&imc<49.9){
		cout<<"Segun la estatura y el peso ingresados, el IMC es "<<imc<<" ,para un individuo de "<<eda<<" aï¿½os es una persona con obesidad III"<<endl;
	}
	if (imc>50){
		cout<<"Segun la estatura y el peso ingresados, el IMC es "<<imc<<" ,para un individuo de "<<eda<<" aï¿½os es una persona con obesidad IV"<<endl;
	}
}
else
{
	cout<<"introduzca su Genero (M o F):"<<endl;
	cin>>gen;
	
    if(gen=='m'){
	cout<<"introduce tu altura(m): "<<endl;
	cin>>alt2;
	cout<<"ahora introduzca se peso(kg): "<<endl;
	cin>>pes2;
	imc=pes2/(alt2*alt2);
	if (imc<18.5){
		cout<<"Segun la estatura y el peso ingresados, el IMC es "<<imc<<" ,para un hombre de "<<eda<<" aï¿½os es una persona con bajo peso"<<endl;
	}
	else if (imc>=18.5){
		cout<<"Segun la estatura y el peso ingresados, el IMC es "<<imc<<" ,para un hombre de "<<eda<<" aï¿½os es una persona saludable"<<endl;
	}
	else if (imc>=25){
		cout<<"Segun la estatura y el peso ingresados, el IMC es "<<imc<<" ,para un hombre de "<<eda<<" aï¿½os es una persona con sobrepeso"<<endl;
	}
	else if (imc>=30){
		cout<<"Segun la estatura y el peso ingresados, el IMC es "<<imc<<" ,para un hombre de "<<eda<<" aï¿½os es una persona con obesidad I"<<endl;
	}
	else if (imc>=35){
		cout<<"Segun la estatura y el peso ingresados, el IMC es "<<imc<<" ,para un hombre de "<<eda<<" aï¿½os es una persona con obesidad II"<<endl;
	}
	else if (imc>=40){
		cout<<"Segun la estatura y el peso ingresados, el IMC es "<<imc<<" ,para un hombre de "<<eda<<" aï¿½os es una persona con obesidad III"<<endl;
	}
	else if (imc>=50){
		cout<<"Segun la estatura y el peso ingresados, el IMC es "<<imc<<" ,para un hombre de "<<eda<<" aï¿½os es una persona con obesidad IV"<<endl;
	}
}

	if(gen=='f'){
	
	cout<<"introduce tu altura(m): "<<endl;
	cin>>alt1;
	cout<<"ahora introduzca se peso(kg): "<<endl;
	cin>>pes1;
	imc=pes1/(alt1*alt1);
	if (imc<18.5){
		cout<<"Segun la estatura y el peso ingresados, el IMC es "<<imc<<" ,para una mujer de "<<eda<<" aï¿½os es una persona con bajo peso"<<endl;
	}
	else if (imc>=18.5){
		cout<<"Segun la estatura y el peso ingresados, el IMC es "<<imc<<" ,para una mujer de "<<eda<<" aï¿½os es una persona saludable"<<endl;
	}
	else if (imc>=25){
		cout<<"Segun la estatura y el peso ingresados, el IMC es "<<imc<<" ,para una mujer de "<<eda<<" aï¿½os es una persona con sobrepeso"<<endl;
	}
	else if (imc>=30){
		cout<<"Segun la estatura y el peso ingresados, el IMC es "<<imc<<" ,para una mujer de "<<eda<<" aï¿½os es una persona con obesidad I"<<endl;
	}
	else if (imc>=35){
		cout<<"Segun la estatura y el peso ingresados, el IMC es "<<imc<<" ,para una mujer de "<<eda<<" aï¿½os es una persona con obesidad II"<<endl;
	}
	else if (imc>=40){
		cout<<"Segun la estatura y el peso ingresados, el IMC es "<<imc<<" ,para una mujer de "<<eda<<" aï¿½os es una persona con obesidad III"<<endl;
	}
	else if (imc>=50){
		cout<<"Segun la estatura y el peso ingresados, el IMC es "<<imc<<" ,para una mujer de "<<eda<<" aï¿½os es una persona con obesidad IV"<<endl;
	}
}
}
cout<<"Desea repetir la medicion (S/N):"<<endl;
cin>>Nmi;	
}while(Nmi=='s');
cout<<"Cual es su objetivo?"<<endl;
cout<<"1.-Perder Peso \n2.-Ganar Salud\n3.-Ponerse Fuerte"<<endl;
cin>>obj;
if (obj=1){
	cout<<"1"<<endl;
}
if(obj=2){
	cout<<"2"<<endl;
}
if(obj=3){
	 cout<<"3"<<endl;
}
			break;
						
			case '4':
				system("cls");
				login();
			break;
			
			default:
				cout<<"\n\tOpción Invalida \n";
				break;
		}
		cout<<"\n\tPresiona Cualquier Tecla\n";
	 	getch();
		system("cls");
	}while(opcion != '4');
}

//Agregar al registro
void agregar(ofstream &es){
	//"cls" funciona para que limpie la consola
	system("cls");
	string nombre;
	string ape;
	string apeMa;
	string edad;
	string gene;
	string esta;
	string peso;
	string ale;
	string enfe;
	string dis;
	string san;
	string dom;
	string numEx;
	string numIn;
	string numCel;
	string numAux;
	string numAux2;
	string correo;
	string folio;
	
	//String del historial familiar
	string nomb, ape2, apeMa2, edad2, paren, gene2, esta2, peso2, ale2, en, dis2, san2, dom2, numEx2, numIn2;
	string numCel2, numaux, numaux2, correo2;
	
	//string del historial familiar 2
	string nomb2, ape3, apeMa3, edad3, paren2, gene3, esta3, peso3, ale3, en2, dis3, san3, dom3, numEx3, numIn3;
	string numeCel, numeaux, numeaux2, correo3;
	
	//Esta linea sirve para guardar los usuarios
	es.open("Expediente.txt", ios::out | ios::app);
	cout<<"\t\t                               "<<endl;
	cout<<"\t\t                                "<<endl;
	cout<<"\t\t         Nuevo Registro       "<<endl;
	cout<<"\t\t                               "<<endl;
	cout<<"Folio:                          "<<endl;
    cout<<"\t\t                                "<<endl;
	cin>>folio;
	cout<<"\t\t                                "<<endl;
	cout<<"Nombre:                         "<<endl;
	cout<<"\t\t                                "<<endl;
	cin>>nombre;
	cout<<"\t\t                                "<<endl;
	cout<<"Apellido paterno:               "<<endl;
	cout<<"\t\t                                "<<endl;
	cin>>ape;
	cout<<"\t\t                                "<<endl;
	cout<<"Apellido materno:               "<<endl;
	cout<<"\t\t                                "<<endl;
	cin>>apeMa;
	cout<<"\t\t                               "<<endl;
	cout<<"Fecha de nacimiento(dd/mm/aa):  "<<endl;
	cout<<"\t\t                                "<<endl;
	cin>>edad;
	cout<<"\t\t                                "<<endl;
	cout<<"Genero:                         "<<endl;
	cout<<"\t\t                                "<<endl;
	cin>>gene;
	cout<<"\t\t                                "<<endl;
	cout<<"Estatura:                       "<<endl;
	cout<<"\t\t                                "<<endl;
	cin>>esta;
	cout<<"\t\t                                "<<endl;
	cout<<"Peso:                           "<<endl;
	cout<<"\t\t                                "<<endl;
	cin>>peso;
	cout<<"\t\t                                "<<endl;
	cout<<"Alergias:                      "<<endl;
	cout<<"\t\t                                "<<endl;
	cin>>ale;
	cout<<"\t\t                                "<<endl;
	cout<<"Enfermedades cronicas:          "<<endl;
	cout<<"\t\t                                "<<endl;
	cin>>enfe;
	cout<<"\t\t                                "<<endl;
	cout<<"Discapacidad:                   "<<endl;
	cout<<"\t\t                                "<<endl;
	cin>>dis;
	cout<<"\t\t                                "<<endl;
	cout<<"Tipo de sangre:                 "<<endl;
	cout<<"\t\t                                "<<endl;
	cin>>san;
	cout<<"\t\t                                "<<endl;
	cout<<"Calle:                          "<<endl;
	cout<<"\t\t                                "<<endl;
	cin>>dom;
	cout<<"\t\t                                "<<endl;
	cout<<"Numero exterior:                "<<endl;
	cout<<"\t\t                                "<<endl;
	cin>>numEx;
	cout<<"\t\t                                "<<endl;
	cout<<"Numero interior:                "<<endl;
	cout<<"\t\t                                "<<endl;
	cin>>numIn;
	cout<<"\t\t                                "<<endl;
	cout<<"Numero celular:                 "<<endl;
	cout<<"\t\t                                "<<endl;
	cin>>numCel;
	cout<<"\t\t                                "<<endl;
	cout<<"Numero de contacto:            "<<endl;
	cout<<"\t\t                                "<<endl;
	cin>>numAux; 
	cout<<"\t\t                                "<<endl;                               
	cout<<"Numero de contacto 2:           "<<endl;
	cout<<"\t\t                                "<<endl;
	cin>>numAux2;
	cout<<"\t\t                                "<<endl;
	cout<<"Correo electronico:             "<<endl;
	cout<<"\t\t                                "<<endl;
	cin>>correo;
	cout<<"\t\t                            "<<endl;
    cout<<"\t\t                            "<<endl;
    cout<<"\t\t                             "<<endl;
    cout<<"\t\t                                      "<<endl;
    cout<<"\t\t                                      "<<endl;
	cout<<"\t\t                                    "<<endl;
	cout<<"\t\t                                   "<<endl;
	cout<<"\t\t          Historial familiar         "<<endl;
	cout<<"\t\t                                     "<<endl;
	cout<<"\t\t                                    "<<endl;
	cout<<"Nombre:                             "<<endl;
	cout<<"\t\t                                       "<<endl;
	cin>>         nomb;
	cout<<"\t\t                                    "<<endl;
	cout<<"Apellido paterno:                  "<<endl;
	cout<<"\t\t                                    "<<endl;
	cin>>ape2;
	cout<<"\t\t                                    "<<endl;
	cout<<"Apellido materno:                   "<<endl;
	cout<<"\t\t                                    "<<endl;
	cin>>apeMa2;
	cout<<"\t\t                                    "<<endl;
	cout<<"Fecha de nacimiento(dd/mm/aa):      "<<endl;
	cout<<"\t\t                                    "<<endl;
	cin>>edad2;
	cout<<"\t\t                                    "<<endl;
	cout<<"Parentesco:                         "<<endl;
	cout<<"\t\t                                    "<<endl;
	cin>>paren;
	cout<<"\t\t                                    "<<endl;
	cout<<"Genero:                             "<<endl;
	cout<<"\t\t                                    "<<endl;
	cin>>gene2;
	cout<<"\t\t                                    "<<endl;
	cout<<"Estatura:                           "<<endl;
	cout<<"\t\t                                    "<<endl;
	cin>>esta2;
	cout<<"\t\t                                   "<<endl;
	cout<<"Peso:                               "<<endl;
	cout<<"\t\t                                    "<<endl;
	cin>>peso2;
	cout<<"\t\t                                    "<<endl;
	cout<<"Alergias:                           "<<endl;
	cout<<"\t\t                                    "<<endl;
	cin>>ale2;
	cout<<"\t\t                                    "<<endl;
	cout<<"Enfermedades cronicas:              "<<endl;
	cout<<"\t\t                                    "<<endl;
	cin>>en;
	cout<<"\t\t                                    "<<endl;
	cout<<"Discapacidad:                       "<<endl;
	cout<<"\t\t                                    "<<endl;
	cin>>dis2;
	cout<<"\t\t                                    "<<endl;
	cout<<"Tipo de sangre:                     "<<endl;
	cout<<"\t\t                                    "<<endl;
	cin>>san2;
	cout<<"\t\t                                    "<<endl;
	cout<<"Calle:                              "<<endl;
	cout<<"\t\t                                    "<<endl;
	cin>>dom2;
	cout<<"\t\t                                    "<<endl;
	cout<<"Numero exterior:                    "<<endl;
	cout<<"\t\t                                    "<<endl;
	cin>>numEx2;
	cout<<"\t\t                                    "<<endl;
	cout<<"Numero interior:                    "<<endl;
	cout<<"\t\t                                    "<<endl;
	cin>>numIn2;
	cout<<"\t\t                                    "<<endl;
	cout<<"Numero celular:                     "<<endl;
	cout<<"\t\t                                    "<<endl;
	cin>>numCel2;
	cout<<"\t\t                                    "<<endl;
	cout<<"Numero de contacto:                 "<<endl;
	cout<<"\t\t                                    "<<endl;
	cin>>numaux;
	cout<<"\t\t                                    "<<endl;
	cout<<"Numero de contacto 2:               "<<endl;
	cout<<"\t\t                                    "<<endl;
	cin>>numaux2;
	cout<<"\t\t                                   "<<endl;
	cout<<"Correo electronico:                 "<<endl;
	cout<<"\t\t                                    "<<endl;
	cin>>correo2;
	cout<<"\t\t                                  "<<endl;
	cout<<"\t\t                                      "<<endl;
	cout<<"\t\t                                      "<<endl;
	cout<<"\t\t                                      "<<endl;
	cout<<"\t\t                                      "<<endl;
    cout<<"\t\t                                     "<<endl;
	cout<<"\t\t          Historial familiar         "<<endl;
	cout<<"\t\t                                      "<<endl;
	cout<<"\t\t                                     "<<endl;
	cout<<"Nombre:                              "<<endl;
	cout<<"\t\t                                      "<<endl;
	cin>>nomb2;
	cout<<"\t\t                                      "<<endl;
	cout<<"Apellido paterno:                     "<<endl;
	cout<<"\t\t                                      "<<endl;
	cin>>ape3;
	cout<<"\t\t                                      "<<endl;
	cout<<"Apellido materno:                     "<<endl;
	cout<<"\t\t                                      "<<endl;
	cin>>apeMa3;
	cout<<"\t\t                                      "<<endl;
	cout<<"Fecha de nacimiento (dd/mm/aa):       "<<endl;
	cout<<"\t\t                                      "<<endl;
	cin>>edad3;
	cout<<"\t\t                                      "<<endl;
	cout<<"Parentesco:                           "<<endl;
	cout<<"\t\t                                      "<<endl;
	cin>>paren2;
	cout<<"\t\t                                      "<<endl;
	cout<<"Genero:                               "<<endl;
	cout<<"\t\t                                      "<<endl;
	cin>>gene3;
	cout<<"\t\t                                      "<<endl;
	cout<<"Estatura:                            "<<endl;
	cout<<"\t\t                                      "<<endl;
	cin>>esta3;
	cout<<"\t\t                                      "<<endl;
	cout<<"Peso:                                "<<endl;
	cout<<"\t\t                                      "<<endl;
	cin>>peso3;
	cout<<"\t\t                                      "<<endl;
	cout<<"Alergias:                             "<<endl;
	cout<<"\t\t                                      "<<endl;
	cin>>ale3;
	cout<<"\t\t                                      "<<endl;
	cout<<"Enfermedades cronicas:                "<<endl;
	cout<<"\t\t                                      "<<endl;
	cin>>en2;
	cout<<"\t\t                                      "<<endl;
	cout<<"Discapacidad:                         "<<endl;
	cout<<"\t\t                                     "<<endl;
	cin>>dis3;
	cout<<"\t\t                                      "<<endl;
	cout<<"Tipo de sangre:                       "<<endl;
	cout<<"\t\t                                      "<<endl;
	cin>>san3;
	cout<<"\t\t                                     "<<endl;
	cout<<"Calle:                               "<<endl;
	cout<<"\t\t                                      "<<endl;
	cin>>dom3;
	cout<<"\t\t                                      "<<endl;
	cout<<"Numero exterior:                      "<<endl;
	cout<<"\t\t                                      "<<endl;
	cin>>numEx3;
	cout<<"\t\t                                       "<<endl;
	cout<<"Numero interior:                      "<<endl;
	cout<<"\t\t                                      "<<endl;
	cin>>numIn3;
	cout<<"\t\t                                      "<<endl;
	cout<<"Numero celular:                       "<<endl;
	cout<<"\t\t                                     "<<endl;
	cin>>numeCel;
	cout<<"\t\t                                      "<<endl;
	cout<<"Numero de contacto:                   "<<endl;
	cout<<"\t\t                                      "<<endl;
	cin>>numeaux;
	cout<<"\t\t                                      "<<endl;
	cout<<"Numero de contacto 2:                 "<<endl;
	cout<<"\t\t                                      "<<endl;
	cin>>numeaux2;
	cout<<"\t\t                                     "<<endl;
	cout<<"Corrreo electronico:                 "<<endl;
	cout<<"\t\t                                      "<<endl;
	cin>>correo3;
	cout<<"\t\t                                      "<<endl;
	cout<<"\t\t                                        "<<endl;
	cout<<"   ";
	//escritura del paciente
	es<<folio<<" "<<nombre<<" "<<ape<<" "<<apeMa<<" "<<edad<<" "<<gene<<" "<<esta<<" "<<peso<<" "<<ale<<" "<<enfe<<" "<<dis<<" "<<san<<" "<<dom<<" "<<numEx<<" "<<numIn<<" "<<numCel<<" "<<numAux<<" "<<numAux2<<" "<<correo<<"\n";
	//escritura del historial familiar
	es<<nomb<<" "<<ape2<<" "<<apeMa2<<" "<<edad2<<" "<<paren<<" "<<gene2<<" "<<esta2<<" "<<peso2<<" "<<ale2<<" "<<en<<" "<<dis2<<" "<<san2<<" "<<dom2<<" "<<numEx2<<" "<<numIn2<<" "<<numCel2<<" "<<numaux<<" "<<numaux2<<" "<<correo2<<"\n";
	//escritura del historial familiar 2
	es<<nomb2<<" "<<ape3<<" "<<apeMa3<<" "<<edad3<<" "<<paren<<" "<<gene3<<" "<<esta3<<" "<<peso3<<" "<<ale3<<" "<<en2<<" "<<dis3<<" "<<san3<<" "<<dom3<<" "<<numEx3<<" "<<numIn3<<" "<<numeCel<<" "<<numeaux<<" "<<numeaux2<<" "<<correo3<<"\n";
	es.close();
}

void menucita(){
	
	char opcion;
	
	cout<<endl<<"\t  ";
	cout<<endl<<"\t ";
	cout<<endl<<"\t          Cita         ";
	cout<<endl<<"\t ";
	cout<<endl<<"\t ";
	cout<<endl<<"1. Consultar Cita                ";
	cout<<endl<<"\t";
	cout<<endl<<"\t                                  ";
	cout<<endl<<"2. Eliminar Cita                ";
	cout<<endl<<"\t";
	cout<<endl<<"\t ";
	cout<<endl<<"3. Editar Cita                   ";
	cout<<endl<<"\t                                  ";
	cout<<endl<<"4. Regresar                      ";
	cout<<endl<<"\t";
	cout<<endl<<"Opción:";
	
	cin>>opcion;
	fflush(stdin);
	
	do{
		switch(opcion){
			case 1:
			
			tiempo();
				
			break;
			
			case '2':
			
				
			break;
			
			case '3':
				
			break;
						
			case '4':
				system("cls");
				menuadmin();
			break;
			
			default:
				cout<<"\n\tOpción Invalida \n";
				break;
		}
		cout<<"\n\tPresiona Cualquier Tecla\n";
	 	getch();
		system("cls");
	}while(opcion != '4');
}

void menuexp(){
	ifstream lec;
	char opcion;
	
	cout<<endl<<"\t       Expediente       ";
	cout<<endl<<"\t                                  ";
	cout<<endl<<"1. Buscar Expediente Clinico     ";
	cout<<endl<<"\t                                  ";
	cout<<endl<<"2. Consultar Expedientes         ";
	cout<<endl<<"\t                                  ";
	cout<<endl<<"3. Regresar                      ";
	cout<<endl<<"Opción:";
	
	cin>>opcion;
	fflush(stdin);
		
	do{
		switch(opcion){
			case '1':				
				system("cls");
				tiempo();
				buscar(lec);
				menucita();
			break;
			
			case '2':
				tiempo();
				consultar(lec);
			break;
						
			case '3':
				system("cls");
				menuadmin();
			break;
			
			default:
				cout<<"\n\tOpción Invalida \n";
				break;
		}
		cout<<"\n\tPresiona Cualquier Tecla\n";
	 	getch();
		system("cls");
	}while(opcion != '4');
}

//Consultar expediante
void consultar(ifstream &lec){
	system("cls");
	lec.open("Expediente.txt", ios::in);
	bool encontrado = false;
	//strin de busqueda
	string folioaux;
	//string del user
	string folio, nombre, ape, apeMa, edad,  gene, esta, peso, ale, enfe, dis, san, dom, numEx, numIn, numCel, numAux, numAux2, correo;
	//string del historial familiar
	string nomb, ape2, apeMa2, edad2, paren, gene2, esta2, peso2, ale2, en, dis2, san2, dom2, numEx2, numIn2, numCel2, numaux, numaux2, correo2;
	//string del historial familiar 2
	string nomb2, ape3, apeMa3, edad3, paren2, gene3, esta3, peso3, ale3, en2, dis3, san3, dom3, numEx3, numIn3, numeCel, numeaux, numeaux2, correo3;
	cout<<"\t                                       "<<endl;
	cout<<"\t                                      "<<endl;
	cout<<"\t     Consultar expedientes            "<<endl;
	cout<<"\t                                      "<<endl;
	cout<<"Numero de folio a consultar:         "<<endl;
	cin>>folioaux;
	lec>>folio;
	//Este while esta para la busqueda siempre y cuando "encontrado" este en un valor de false
	while(!lec.eof() && !encontrado){
		lec>>nombre;
		lec>>ape;
		lec>>apeMa;
		lec>>edad;
		lec>>gene;
		lec>>esta;
		lec>>peso;
		lec>>ale;
		lec>>enfe;
		lec>>dis;
		lec>>san;
		lec>>dom;
		lec>>numEx;
		lec>>numIn;
		lec>>numCel;
		lec>>numAux;
		lec>>numAux2;
		lec>>correo;
		//Lectura de los datos del historial familiar
		lec>>nomb;
		lec>>ape2;
		lec>>apeMa2;
		lec>>edad2;
		lec>>paren;
		lec>>gene2;
		lec>>esta2;
		lec>>peso2;
		lec>>ale2;
		lec>>en;
		lec>>dis2;
		lec>>san2;
		lec>>dom2;
		lec>>numEx2;
		lec>>numIn2;
		lec>>numCel2;
		lec>>numaux;
		lec>>numaux2;
		lec>>correo2;
		//Lectura de los datos del historial familiar 2
		lec>>nomb2;
		lec>>ape3;
		lec>>apeMa3;
		lec>>edad3;
		lec>>paren2;
		lec>>gene3;
		lec>>esta3;
		lec>>peso3;
		lec>>ale3;
		lec>>en2;
		lec>>dis3;
		lec>>san3;
		lec>>dom3;
		lec>>numEx3;
		lec>>numIn3;
		lec>>numeCel;
		lec>>numeaux;
		lec>>numeaux2;
		lec>>correo3;
		//este if es para comparar e imprimirlo en la pantalla 
		if(folio == folioaux){
			system("cls");
			cout<<"\t                                                 "<<endl;
			cout<<"\t                                                        "<<endl;
			cout<<"\t       Expediente clinico de"<<" "<<nombre<<"         "<<endl;
			cout<<"\t                                           "<<endl;
			cout<<"\t                                                         "<<endl;
			cout<<"Folio:"<<folio<<endl;
			cout<<"Nombre:"<<nombre<<endl;
			cout<<"Apellido paterno:"<<ape<<endl;
			cout<<"Apellido materno:"<<apeMa<<endl;
			cout<<"Fecha de nacimiento(dd/mm/aa):"<<edad<<endl;
			cout<<"Genero:"<<gene<<endl;
			cout<<"Estatura:"<<esta<<endl;
			cout<<"Peso:"<<peso<<endl;
			cout<<"Alergias:"<<ale<<endl;
			cout<<"Enfermedades cronicas:"<<enfe<<endl;
			cout<<"Discapacidades:"<<dis<<endl;
			cout<<"Tipo de sangre:"<<san<<endl;
			cout<<"Calle:"<<dom<<endl;
			cout<<"Numero exterior:"<<numEx<<endl;
			cout<<"Numero interior:"<<numIn<<endl;
			cout<<"Numero de celular:"<<numCel<<endl;
			cout<<"Numero de contacto:"<<numAux<<endl;
			cout<<"Numero de contacto:"<<numAux2<<endl;
			cout<<"Correo electronico:"<<correo<<endl;   
			cout<<"\t"<<endl;
			//Imprimir el historil familiar
			cout<<"\t                                                          "<<endl;
			cout<<"\t                                                   "<<endl;
			cout<<"\t                                                        "<<endl;
			cout<<"\t        Histrial familiar de"<<" "<<nombre<<"           "<<endl;
			cout<<"\t                                                     "<<endl;
			cout<<"\t                                                         "<<endl;
			cout<<"Nombre: "<<nomb<<endl;
			cout<<"Apellido paterno: "<<ape2<<endl;
			cout<<"Apellido materno: "<<apeMa2<<endl;
			cout<<"Fecha de nacimiento(dd/mm/aa): "<<edad2<<endl;
			cout<<"Parentesco: "<<paren<<endl;
			cout<<"Genero: "<<gene2<<endl;
			cout<<"Estatura: "<<esta2<<endl;
			cout<<"Peso: "<<peso2<<endl;
			cout<<"Alergias: "<<ale2<<endl;
			cout<<"Enfermedades cronicas: "<<en<<endl;
			cout<<"Discapacidades: "<<dis2<<endl;
			cout<<"Tipo de sangre: "<<san2<<endl;
			cout<<"Calle: "<<dom2<<endl;
			cout<<"Numero exterior: "<<numEx2<<endl;
			cout<<"Numero interior: "<<numIn2<<endl;
			cout<<"Numero de celular: "<<numCel2<<endl;
			cout<<"Numero de contacto: "<<numaux<<endl;
			cout<<"Numero de contacto: "<<numaux2<<endl;
			cout<<"Correo electronico: "<<correo2<<endl;
			cout<<"\t                                                          "<<endl;
			cout<<"\t                                                          "<<endl;
			//Imprimir el segundo historial familiar
			cout<<"\t                                                          "<<endl;
			cout<<"\t                                                "<<endl;
			cout<<"\t                                                        "<<endl;
			cout<<"\t  Historial familiar de"<<" "<<nombre<<"           "<<endl;
			cout<<"\t                                             "<<endl;
			cout<<"\t                                                         "<<endl;
			cout<<"Nombre: "<<nomb2<<endl;
			cout<<"Apellido paterno: "<<ape3<<endl;
			cout<<"Apellido materno: "<<apeMa3<<endl;
			cout<<"Fecha de nacimiento(dd/mm/aa): "<<edad3<<endl;
			cout<<"Parentesco: "<<paren2<<endl;
			cout<<"Genero: "<<gene3<<endl;
			cout<<"Estatura: "<<esta3<<endl;
			cout<<"Peso: "<<peso3<<endl;
			cout<<"Alergias: "<<ale3<<endl;
			cout<<"Enfermedades cronicas: "<<en2<<endl;
			cout<<"Discapacidades: "<<dis3<<endl;
			cout<<"Tipo de sangre: "<<san3<<endl;
			cout<<"Calle: "<<dom3<<endl;
			cout<<"Numero exterior: "<<numEx3<<endl;
			cout<<"Numero interior: "<<numIn3<<endl;
			cout<<"Numero de celular: "<<numeCel<<endl;
			cout<<"Numero de contacto: "<<numeaux<<endl;
			cout<<"Numero de contacto: "<<numeaux2<<endl;
			cout<<"Correo electronico: "<<correo3<<endl;
			cout<<"\t                                                         "<<endl;
			cout<<"\t                                                          "<<endl;
			//cuando nombre y nombreaux sean el mismo se mandara un true a "encontrado"
			encontrado = true;
		}
		lec>>folio;
	}
	lec.close();
	
	//Si no existe el dato imprime este mensaje
	if(!encontrado)
		cout<<"No existe "<<endl;
		system("pause");
}

//Buscar en el registro
void buscar(ifstream &lec){
	system("cls");
	lec.open("Expedientes.txt", ios::in);
	bool encontrado = false;
	string nombre, edad, gene, esta, peso, folio, folioaux;
	cout<<"Digite el folio: ";
	cin>>folioaux;
	lec>>folio;
	//Este while esta para la busqueda siempre y cuando "encontrado" este en un valor de false
	while(!lec.eof() && !encontrado){
		lec>>nombre;
		lec>>edad;
		lec>>gene;
		lec>>esta;
		lec>>peso;
		//este if es para comparar e imprimirlo en la pantalla 
		if(folio == folioaux){
			system("cls");
			cout<<"\t                                                  "<<endl;
			cout<<"\t                                                 "<<endl;
			cout<<"\t                                                "<<endl;
			cout<<"\t Registro de"<<" "<<nombre<<"          "<<endl;
			cout<<"\t                                                 "<<endl;
			cout<<"Numero de folio: "<<folio<<endl;
			cout<<"Nombre: "<<nombre<<endl;
			cout<<"Edad: "<<edad<<endl;
			cout<<"Genero: "<<gene<<endl;
			cout<<"Estatura: "<<esta<<endl;
			cout<<"Peso: "<<peso<<endl;
			cout<<"                     "<<endl;
			//cuando nombre y nombreaux sean el mismo se mandara un true a "encontrado"
			encontrado = true;
		}
		lec>>folio;
	}
	lec.close();
	
	//Si no existe el dato imprime este mensaje
	if(!encontrado)
		cout<<"Dato no encontrado"<<endl;
		system("pause");
}

//Agregar cita
void agregarcita(ofstream &es){
	//limpiamos la consola
	system("cls");
	//string de los datos basicos
	string folio, nombre, ape, apeMa, fecha, gene, esta, peso;
	//string de los datos de la cita
	string date, fechaCit;
	//Asignamos donde guardar los datos de la cita
	es.open("Cita.txt", ios::out | ios::app);
	//Datos que se guardaran de la cita
	cout<<"\t                       "<<endl;
	cout<<"\t                                        "<<endl;
	cout<<"\t        Nueva Cita                      "<<endl;
	cout<<"\t                                        "<<endl;
	cout<<"\t                                        "<<endl;
	cout<<"Folio:                                  "<<endl;
	cin>>folio;
	cout<<"\t                                        "<<endl;
	cout<<"Nombre:                                 "<<endl;
	cin>>nombre;
	cout<<"\t                                        "<<endl;
	cout<<"Apellido paterno:                       "<<endl;
	cin>>ape;
	cout<<"\t                                        "<<endl;
	cout<<"Apellido materno:                       "<<endl;
	cin>>apeMa;
	cout<<"\t                                        "<<endl;
	cout<<"Genero:                                 "<<endl;
	cin>>gene;
	cout<<"\t                                        "<<endl;
	cout<<"Fecha de nacimiento(dd/mm/aa):          "<<endl;
	cin>>fecha;
	cout<<"\t                                        "<<endl;
	cout<<"Estatura:                               "<<endl;
	cin>>esta;
	cout<<"\t                                        "<<endl;
	cout<<"Peso:                                   "<<endl;
	cin>>peso;
	cout<<"\t                                        "<<endl;
	cout<<"Fecha actual(dd/mm/aa):                 "<<endl;
	cin>>date;
	cout<<"\t                                        "<<endl;
	cout<<"Fecha de la proxima cita(dd/mm/aa):     "<<endl;
	cout<<"\t                                        "<<endl;
	cin>>fechaCit;
	//escritura de la cita
	es<<folio<<" "<<nombre<<" "<<ape<<" "<<apeMa<<" "<<gene<<" "<<fecha<<" "<<esta<<" "<<peso<<" "<<date<<" "<<fechaCit<<"\n";
	es.close();
}

//consultar cita
void consultarci(ifstream &lec){
	system("cls");
	lec.open("Cita.txt", ios::in);
	bool encontrado = false;
	//strin de busqueda
	string folioaux1;
	//Strings de los datos basicos
	string folio, nombre, ape, apeMa, gene, fecha, esta, peso;
	//string de los datos de la cita
	string date, fechaCit;
	cout<<"\t                                 "<<endl;
	cout<<"\t                                  "<<endl;
	cout<<"\t          Consultar cita          "<<endl;
	cout<<"\t                                  "<<endl;
	cout<<"\t                                   "<<endl;
	cout<<"Numero de folio de la cita:        "<<endl;
	cout<<"\t                                    "<<endl;
	cout<<"\t                                    "<<endl;
	cin>>folioaux1;
	lec>>folio;
	//Este while esta para la busqueda siempre y cuando "encontrado" este en un valor de false
	while(!lec.eof() && !encontrado){
		lec>>nombre;
		lec>>ape;
		lec>>apeMa;
		lec>>gene;
		lec>>fecha;
		lec>>esta;
		lec>>peso;
		lec>>date;
		lec>>fechaCit;
		//este if es para comparar e imprimirlo en la pantalla 
		if(folio == folioaux1){
			//limpiamos la consola
			system("cls");
			cout<<"\t                                                          "<<endl;
			cout<<"\t                                                          "<<endl;
			cout<<"Citas de: "<<" "<<nombre<<"         "<<endl;
			cout<<"\t                                                          "<<endl;
			cout<<"\t                                                          "<<endl;
			cout<<"\t                                                           "<<endl;
			cout<<"Folio: "<<folio<<endl;
			cout<<"Nombre: "<<nombre<<endl;
			cout<<"Apellido paterno: "<<ape<<endl;
			cout<<"Apellido materno: "<<apeMa<<endl;
			cout<<"Genero: "<<gene<<endl;
			cout<<"Fecha de nacimiento(dd/mm/aa): "<<fecha<<endl;
			cout<<"Estatura: "<<esta<<endl;
			cout<<"Peso: "<<peso<<endl;
			cout<<"Fecha de la visita(dd/mm/aa): "<<date<<endl;
			cout<<"Fecha de la proxima cita(dd/mm/aa): "<<fechaCit<<endl;
			cout<<"\t                                                        "<<endl;
			cout<<"\t                                                        "<<endl;
			//cuando folio y folioaux1 sean el mismo se mandara un true a "encontrado"
			encontrado = true;
		}
		lec>>folio;
	}
	lec.close();
	//Si no existe el dato imprime este mensaje
	if(!encontrado)
		cout<<"No existe :c"<<endl;
		system("pause");
}

//editar cita
void editarcita(ifstream &lec){
	int opci;
	system("cls");
	//string para editar
	string folioAux, nomAux2, apeAux2, apeMaAux2, fechaAux2, geneAux2, estaAux2, pesoAux2, dateAux2, fechaCitAux2;
	//string de los datos basicos
	string folio, nombre, ape, apeMa, fecha, gene, esta, peso;
	//string de los datos de la cita
	string date, fechaCit;
	cout<<"\t                                          "<<endl;
	cout<<"\t                                          "<<endl;
	cout<<"\t                Editar cita               "<<endl;
	cout<<"\t                                           "<<endl;
	cout<<"\t                                          "<<endl;
	cout<<"1.Folio 								   "<<endl;
	cout<<"2.Nombre								   "<<endl;
	cout<<"3.Apellido paterno 					   "<<endl;
	cout<<"4.Apellido materno 					   "<<endl;
	cout<<"5.Genero								   "<<endl;
	cout<<"6.Fecha de nacimiento(dd/mm/aa)		   "<<endl;
	cout<<"7.Estatura							   "<<endl;
	cout<<"8.Peso								   "<<endl;
	cout<<"9.Fecha(dd/mm/aa)						   "<<endl;
	cout<<"10.Fecha de la proxima cita(dd/mm/aa)	   "<<endl;
	cout<<"11.Salir								   "<<endl;
	cout<<"Ingrese el dato: 						   "<<endl;                              
	cout<<"\t                                          "<<endl;
	cin>>opci;
	//abrir txt
	lec.open("Cita.txt", ios::in);
	ofstream editcita("EditarCita.txt", ios::out);
	//switch
	switch(opci){
		//editar folio
		case 1:
			system("cls");
			if(lec.is_open()){
				cout<<"\n\tIngrese el folio que desea editar: ";
				cin>>folioAux;
				lec>>folio;
				while(!lec.eof()){
					lec>>nombre;
					lec>>ape;
					lec>>apeMa;
					lec>>gene;
					lec>>fecha;
					lec>>esta;
					lec>>peso;
					lec>>date;
					lec>>fechaCit;
						if(folio == folioAux){
							cout<<"\tNuevo folio: ";
							cin>>folioAux;
							editcita<<folioAux<<" "<<nombre<<" "<<ape<<" "<<apeMa<<" "<<gene<<" "<<fecha<<" "<<esta<<" "<<peso<<" "<<date<<" "<<fechaCit<<"\n";
						}else{
							editcita<<folio<<" "<<nombre<<" "<<ape<<" "<<apeMa<<" "<<gene<<" "<<fecha<<" "<<esta<<" "<<peso<<" "<<date<<" "<<fechaCit<<"\n";
					}
					lec>>folioAux;
				}
				lec.close();
				editcita.close();
			}else
				cout<<"Error"<<endl;
				remove("Cita.txt");
				rename("EditarCita.txt", "Cita.txt");
		break;
		
		//editar nombre
		case 2:
			system("cls");
			if(lec.is_open()){
				cout<<"Ingrese el folio: ";
				cin>>folioAux;
				lec>>folio;
				cout<<"Ingrese el nombre a editar: ";
				cin>>nomAux2;
				while(!lec.eof()){
					lec>>nombre;
					lec>>ape;
					lec>>apeMa;
					lec>>gene;
					lec>>fecha;
					lec>>esta;
					lec>>peso;
					lec>>date;
					lec>>fechaCit;
						if(nombre == nomAux2){
							cout<<"Nuevo Nombre: ";
							cin>>nomAux2;
							editcita<<folio<<" "<<nomAux2<<" "<<ape<<" "<<apeMa<<" "<<gene<<" "<<fecha<<" "<<esta<<" "<<peso<<" "<<date<<" "<<fechaCit<<"\n";
						}else{
							editcita<<folio<<" "<<nombre<<" "<<ape<<" "<<apeMa<<" "<<gene<<" "<<fecha<<" "<<esta<<" "<<peso<<" "<<date<<" "<<fechaCit<<"\n";
					}
					lec>>nomAux2;
				}
				lec.close();
				editcita.close();
			}else
				cout<<"Error"<<endl;
				remove("Cita.txt");
				rename("EditarCita.txt", "Cita.txt");
		break;
		
		//editar apellido paterno
		case 3:
			system("cls");
			if(lec.is_open()){
				cout<<"Ingrese el folio: ";
				cin>>folioAux;
				lec>>folio;
				cout<<"Ingrese el Apellido a editar: ";
				cin>>apeAux2;
				while(!lec.eof()){
					lec>>nombre;
					lec>>ape;
					lec>>apeMa;
					lec>>gene;
					lec>>fecha;
					lec>>esta;
					lec>>peso;
					lec>>date;
					lec>>fechaCit;
						if(ape == apeAux2){
							cout<<"Nuevo Nombre: ";
							cin>>apeAux2;
							editcita<<folio<<" "<<nombre<<" "<<apeAux2<<" "<<apeMa<<" "<<gene<<" "<<fecha<<" "<<esta<<" "<<peso<<" "<<date<<" "<<fechaCit<<"\n";
						}else{
							editcita<<folio<<" "<<nombre<<" "<<ape<<" "<<apeMa<<" "<<gene<<" "<<fecha<<" "<<esta<<" "<<peso<<" "<<date<<" "<<fechaCit<<"\n";
					}
					lec>>apeAux2;
				}
				lec.close();
				editcita.close();
			}else
				cout<<"Error"<<endl;
				remove("Cita.txt");
				rename("EditarCita.txt", "Cita.txt");
		break;
		
		//editar apellido materno
		case 4:
			system("cls");
			if(lec.is_open()){
				cout<<"Ingrese el folio: ";
				cin>>folioAux;
				lec>>folio;
				cout<<"Ingrese el apellido a editar: ";
				cin>>apeMaAux2;
				while(!lec.eof()){
					lec>>nombre;
					lec>>ape;
					lec>>apeMa;
					lec>>gene;
					lec>>fecha;
					lec>>esta;
					lec>>peso;
					lec>>date;
					lec>>fechaCit;
						if(apeMa == apeMaAux2){
							cout<<"Apellido materno: ";
							cin>>apeMaAux2;
							editcita<<folio<<" "<<nombre<<" "<<ape<<" "<<apeMaAux2<<" "<<gene<<" "<<fecha<<" "<<esta<<" "<<peso<<" "<<date<<" "<<fechaCit<<"\n";
						}else{
							editcita<<folio<<" "<<nombre<<" "<<ape<<" "<<apeMa<<" "<<gene<<" "<<fecha<<" "<<esta<<" "<<peso<<" "<<date<<" "<<fechaCit<<"\n";
					}
					lec>>apeMaAux2;
				}
				lec.close();
				editcita.close();
			}else
				cout<<"Error"<<endl;
				remove("Cita.txt");
				rename("EditarCita.txt", "Cita.txt");
		break;
		
		//editar genero
		case 5:
			system("cls");
			if(lec.is_open()){
				cout<<"Ingrese el folio: ";
				cin>>folioAux;
				lec>>folio;
				cout<<"Ingrese el genero a editar: ";
				cin>>geneAux2;
				while(!lec.eof()){
					lec>>nombre;
					lec>>ape;
					lec>>apeMa;
					lec>>gene;
					lec>>fecha;
					lec>>esta;
					lec>>peso;
					lec>>date;
					lec>>fechaCit;
						if(gene == geneAux2){
							cout<<"\tGenero: ";
							cin>>geneAux2;
							editcita<<folio<<" "<<nombre<<" "<<ape<<" "<<apeMa<<" "<<geneAux2<<" "<<fecha<<" "<<esta<<" "<<peso<<" "<<date<<" "<<fechaCit<<"\n";
						}else{
							editcita<<folio<<" "<<nombre<<" "<<ape<<" "<<apeMa<<" "<<gene<<" "<<fecha<<" "<<esta<<" "<<peso<<" "<<date<<" "<<fechaCit<<"\n";
					}
					lec>>geneAux2;
				}
				lec.close();
				editcita.close();
			}else
				cout<<"Error"<<endl;
				remove("Cita.txt");
				rename("EditarCita.txt", "Cita.txt");
		break;
		
		//editar la fecha de nacimiento
		case 6:
			system("cls");
			if(lec.is_open()){
				cout<<"Ingrese el folio: ";
				cin>>folioAux;
				lec>>folio;
				cout<<"Ingrese el fecha de nacimiento a editar: ";
				cin>>fechaAux2;
				while(!lec.eof()){
					lec>>nombre;
					lec>>ape;
					lec>>apeMa;
					lec>>gene;
					lec>>fecha;
					lec>>esta;
					lec>>peso;
					lec>>date;
					lec>>fechaCit;
						if(fecha == fechaAux2){
							cout<<"Fecha de nacimiento(dd/mm/aa): ";
							cin>>fechaAux2;
							editcita<<folio<<" "<<nombre<<" "<<ape<<" "<<apeMa<<" "<<gene<<" "<<fechaAux2<<" "<<esta<<" "<<peso<<" "<<date<<" "<<fechaCit<<"\n";
						}else{
							editcita<<folio<<" "<<nombre<<" "<<ape<<" "<<apeMa<<" "<<gene<<" "<<fecha<<" "<<esta<<" "<<peso<<" "<<date<<" "<<fechaCit<<"\n";
					}
					lec>>fechaAux2;
				}
				lec.close();
				editcita.close();
			}else
				cout<<"Error"<<endl;
				remove("Cita.txt");
				rename("EditarCita.txt", "Cita.txt");
		break;
		
		//Estatura
		case 7:
			system("cls");
			if(lec.is_open()){
				cout<<"Ingrese el folio: ";
				cin>>folioAux;
				lec>>folio;
				cout<<"Ingrese la estatura a editar: ";
				cin>>estaAux2;
				while(!lec.eof()){
					lec>>nombre;
					lec>>ape;
					lec>>apeMa;
					lec>>gene;
					lec>>fecha;
					lec>>esta;
					lec>>peso;
					lec>>date;
					lec>>fechaCit;
						if(esta == estaAux2){
							cout<<"Nueva estatura: ";
							cin>>estaAux2;
							editcita<<folio<<" "<<nombre<<" "<<ape<<" "<<apeMa<<" "<<gene<<" "<<fecha<<" "<<estaAux2<<" "<<peso<<" "<<date<<" "<<fechaCit<<"\n";
						}else{
							editcita<<folio<<" "<<nombre<<" "<<ape<<" "<<apeMa<<" "<<gene<<" "<<fecha<<" "<<esta<<" "<<peso<<" "<<date<<" "<<fechaCit<<"\n";
					}
					lec>>estaAux2;
				}
				lec.close();
				editcita.close();
			}else
				cout<<"Error"<<endl;
				remove("Cita.txt");
				rename("EditarCita.txt", "Cita.txt");
		break;
		
		//editar el peso
		case 8:
			system("cls");
			if(lec.is_open()){
				cout<<"Ingrese el folio: ";
				cin>>folioAux;
				lec>>folio;
				cout<<"Ingrese el peso a editar: ";
				cin>>pesoAux2;
				while(!lec.eof()){
					lec>>nombre;
					lec>>ape;
					lec>>apeMa;
					lec>>gene;
					lec>>fecha;
					lec>>esta;
					lec>>peso;
					lec>>date;
					lec>>fechaCit;
						if(peso == pesoAux2){
							cout<<"Nuevo Peso: ";
							cin>>pesoAux2;
							editcita<<folio<<" "<<nombre<<" "<<ape<<" "<<apeMa<<" "<<gene<<" "<<fecha<<" "<<esta<<" "<<pesoAux2<<" "<<date<<" "<<fechaCit<<"\n";
						}else{
							editcita<<folio<<" "<<nombre<<" "<<ape<<" "<<apeMa<<" "<<gene<<" "<<fecha<<" "<<esta<<" "<<peso<<" "<<date<<" "<<fechaCit<<"\n";
					}
					lec>>pesoAux2;
				}
				lec.close();
				editcita.close();
			}else
				cout<<"Error"<<endl;
				remove("Cita.txt");
				rename("EditarCita.txt", "Cita.txt");
		break;
		
		//editar fecha de visita
		case 9:
			system("cls");
			if(lec.is_open()){
				cout<<"Ingrese el folio: ";
				cin>>folioAux;
				lec>>folio;
				cout<<"Ingrese la fecha a editar: ";
				cin>>dateAux2;
				while(!lec.eof()){
					lec>>nombre;
					lec>>ape;
					lec>>apeMa;
					lec>>gene;
					lec>>fecha;
					lec>>esta;
					lec>>peso;
					lec>>date;
					lec>>fechaCit;
						if(date == dateAux2){
							cout<<"Nueva fecha: ";
							cin>>dateAux2;
							editcita<<folio<<" "<<nombre<<" "<<ape<<" "<<apeMa<<" "<<gene<<" "<<fecha<<" "<<esta<<" "<<peso<<" "<<dateAux2<<" "<<fechaCit<<"\n";
						}else{
							editcita<<folio<<" "<<nombre<<" "<<ape<<" "<<apeMa<<" "<<gene<<" "<<fecha<<" "<<esta<<" "<<peso<<" "<<date<<" "<<fechaCit<<"\n";
					}
					lec>>dateAux2;
				}
				lec.close();
				editcita.close();
			}else
				cout<<"Error"<<endl;
				remove("Cita.txt");
				rename("EditarCita.txt", "Cita.txt");
		break;
		
		//editar fecha de cita
		case 10:
			system("cls");
			if(lec.is_open()){
				cout<<"Ingrese el folio: ";
				cin>>folioAux;
				lec>>folio;
				cout<<"Ingrese la fecha de la cita a editar: ";
				cin>>fechaCitAux2;
				while(!lec.eof()){
					lec>>nombre;
					lec>>ape;
					lec>>apeMa;
					lec>>gene;
					lec>>fecha;
					lec>>esta;
					lec>>peso;
					lec>>date;
					lec>>fechaCit;
						if(fechaCit == fechaCitAux2){
							cout<<"Fecha de la cita: ";
							cin>>fechaCitAux2;
							editcita<<folio<<" "<<nombre<<" "<<ape<<" "<<apeMa<<" "<<gene<<" "<<fecha<<" "<<esta<<" "<<peso<<" "<<date<<" "<<fechaCitAux2<<"\n";
						}else{
							editcita<<folio<<" "<<nombre<<" "<<ape<<" "<<apeMa<<" "<<gene<<" "<<fecha<<" "<<esta<<" "<<peso<<" "<<date<<" "<<fechaCit<<"\n";
					}
					lec>>fechaCitAux2;
				}
				lec.close();
				editcita.close();
			}else
				cout<<"Error"<<endl;
				remove("Cita.txt");
				rename("EditarCita.txt", "Cita.txt");
		break;
	}
}


//borrar cita
void borrarcita(ifstream &lec){
	//strin de busqueda
	string folioaux1;
	//Strings de los datos basicos
	string folio, nombre, ape, apeMa, gene, fecha, esta, peso;
	//string de los datos de la cita
	string date, fechaCit;
	//abrir txt
	lec.open("Cita.txt", ios::in);
	ofstream editcita("EditarCita.txt", ios::out);
	if(lec.is_open()){
		cout<<"Ingrese el folio: ";
		cin>>folioaux1;
		lec>>folio;
		while(!lec.eof()){
			lec>>nombre;
			lec>>ape;
			lec>>apeMa;
			lec>>gene;
			lec>>fecha;
			lec>>esta;
			lec>>peso;
			lec>>date;
			lec>>fechaCit;
			if(folio == folioaux1){
				cout<<"Eliminado correctamente";
				//Esta es la linea que hace la funcion de eliminar 
				Sleep(1500);
			}else{
				editcita<<folio<<" "<<nombre<<" "<<ape<<" "<<apeMa<<" "<<gene<<" "<<fecha<<" "<<esta<<" "<<peso<<" "<<date<<" "<<fechaCit<<"\n";
			}
			lec>>folioaux1;
		}
		lec.close();
		editcita.close();
	}else
	cout<<"Error"<<endl;
	remove("Cita.txt");
	rename("EditarCita.txt", "Cita.txt");
}

//void para editarel expediente
void editarexp(ifstream &lec){
	int x;
	system("cls");
	//String de los datos personales
	string folio;
	string nombre;
	string ape;
	string apeMa;
	string edad;
	string gene;
	string esta;
	string peso;
	string ale;
	string enfe;
	string dis;
	string san;
	string dom;
	string numEx;
	string numIn;
	string numCel;
	string numAux;
	string numAux2;
	string correo;
	//Sting para editar
	string folio1, nomb2, apeAux1, apeMaAux1, edadAux1, geneAux1, estaAux1, pesoAux1, aleAux1, enfeAux1, disAux1, sanAux1, domAux1, numExAux1, numInAux1, numCelAux1, numaux1, numaux5, correoAux1;
    cout<<"\t                                        "<<endl;
    cout<<"\t                                          "<<endl;
	cout<<"\t             Editar expediente            "<<endl;
	cout<<"\t                                          "<<endl;
	cout<<"1.Folio                                   "<<endl;
	cout<<"2.Nombre                                  "<<endl;
	cout<<"3.Apellido paterno                        "<<endl;
	cout<<"4.Apellido materno                        "<<endl;
	cout<<"5.Fecha de nacimiento(dd/mm/aa)           "<<endl;
	cout<<"6.Genero                                  "<<endl;
	cout<<"7.Estatura                                "<<endl;
	cout<<"8.Peso                                    "<<endl;
	cout<<"9.Alergias                                "<<endl;
	cout<<"10.Enfermedades cronicas                  "<<endl;
	cout<<"11.Discapacidades                         "<<endl;
	cout<<"12.Tipo de sangre                         "<<endl;
	cout<<"13.Calle                                  "<<endl;
	cout<<"14.Numero exterior                        "<<endl;
	cout<<"15.Numero interior                        "<<endl;
	cout<<"16.Numero de celular                      "<<endl;
	cout<<"17.Numero de contacto                     "<<endl;
	cout<<"18.Numero de contacto                     "<<endl;
	cout<<"19.Correo electronico                     "<<endl;
	cout<<"20.Salir                                  "<<endl;
	cout<<"Ingrese la opcion a editar:"<<endl;
	cin>>x;                                    
	
	lec.open("Expediente.txt", ios::in);
	ofstream editexp("EditarExp.txt", ios::out);
	switch(x){
		//editar folio
		case 1:
			system("cls");
			if(lec.is_open()){
				cout<<"Ingrese el folio que desea editar: ";
				cin>>folio1;
				lec>>folio;
				while(!lec.eof()){
					lec>>nombre;
					lec>>ape;
					lec>>apeMa;
					lec>>edad;
					lec>>gene;
					lec>>esta;
					lec>>peso;
					lec>>ale;
					lec>>enfe;
					lec>>dis;
					lec>>san;
					lec>>dom;
					lec>>numEx;
					lec>>numIn;
					lec>>numCel;
					lec>>numAux;
					lec>>numAux2;
					lec>>correo;
					if(folio == folio1){
						cout<<"Nuevo folio: ";
						cin>>folio1;
						editexp<<folio1<<" "<<nombre<<" "<<ape<<" "<<apeMa<<" "<<edad<<" "<<gene<<" "<<esta<<" "<<peso<<" "<<ale<<" "<<enfe<<" "<<dis<<" "<<san<<" "<<dom<<" "<<numEx<<" "<<numIn<<" "<<numCel<<" "<<numAux<<" "<<numAux2<<" "<<correo<<"\n";
					}else{
						editexp<<folio<<" "<<nombre<<" "<<ape<<" "<<apeMa<<" "<<edad<<" "<<gene<<" "<<esta<<" "<<peso<<" "<<ale<<" "<<enfe<<" "<<dis<<" "<<san<<" "<<dom<<" "<<numEx<<" "<<numIn<<" "<<numCel<<" "<<numAux<<" "<<numAux2<<" "<<correo<<"\n";
					}
					lec>>folio;
				}
				lec.close();
				editexp.close();
			}else
				cout<<"Error"<<endl;
				remove("Expediente.txt");
				rename("EditarExp.txt", "Expediente.txt");
		break;
			
		//editar nombre
		case 2:
			system("cls");
			if(lec.is_open()){
				cout<<"Ingrese el folio: ";
				cin>>folio1;
				lec>>folio;
				cout<<"Ingrese el nombre: ";
				cin>>nomb2;
				while(!lec.eof()){
					lec>>nombre;
					lec>>ape;
					lec>>apeMa;
					lec>>edad;
					lec>>gene;
					lec>>esta;
					lec>>peso;
					lec>>ale;
					lec>>enfe;
					lec>>dis;
					lec>>san;
					lec>>dom;
					lec>>numEx;
					lec>>numIn;
					lec>>numCel;
					lec>>numAux;
					lec>>numAux2;
					lec>>correo;
					if(nombre == nomb2){
						cout<<"Nuevo nombre: ";
						cin>>nomb2;
						editexp<<folio<<" "<<nomb2<<" "<<ape<<" "<<apeMa<<" "<<edad<<" "<<gene<<" "<<esta<<" "<<peso<<" "<<ale<<" "<<enfe<<" "<<dis<<" "<<san<<" "<<dom<<" "<<numEx<<" "<<numIn<<" "<<numCel<<" "<<numAux<<" "<<numAux2<<" "<<correo<<"\n";
					}else{
						editexp<<folio<<" "<<nombre<<" "<<ape<<" "<<apeMa<<" "<<edad<<" "<<gene<<" "<<esta<<" "<<peso<<" "<<ale<<" "<<enfe<<" "<<dis<<" "<<san<<" "<<dom<<" "<<numEx<<" "<<numIn<<" "<<numCel<<" "<<numAux<<" "<<numAux2<<" "<<correo<<"\n";
					}
					lec>>nombre;
				}
				lec.close();
				editexp.close();
			}else
				cout<<"Error"<<endl;
				remove("Expediente.txt");
				rename("EditarExp.txt", "Expediente.txt");
		break;	
		
		//editar apellido paterno
		case 3:
			system("cls");
			if(lec.is_open()){
				cout<<"Ingrese el folio: ";
				cin>>folio1;
				lec>>folio;
				cout<<"Ingrese el Apellido Paterno: ";
				cin>>apeAux1;
				while(!lec.eof()){
					lec>>nombre;
					lec>>ape;
					lec>>apeMa;
					lec>>edad;
					lec>>gene;
					lec>>esta;
					lec>>peso;
					lec>>ale;
					lec>>enfe;
					lec>>dis;
					lec>>san;
					lec>>dom;
					lec>>numEx;
					lec>>numIn;
					lec>>numCel;
					lec>>numAux;
					lec>>numAux2;
					lec>>correo;
					if(ape == apeAux1){
						cout<<"Nuevo Apellido paterno: ";
						cin>>apeAux1;
						editexp<<folio<<" "<<nombre<<" "<<apeAux1<<" "<<apeMa<<" "<<edad<<" "<<gene<<" "<<esta<<" "<<peso<<" "<<ale<<" "<<enfe<<" "<<dis<<" "<<san<<" "<<dom<<" "<<numEx<<" "<<numIn<<" "<<numCel<<" "<<numAux<<" "<<numAux2<<" "<<correo<<"\n";
					}else{
						editexp<<folio<<" "<<nombre<<" "<<ape<<" "<<apeMa<<" "<<edad<<" "<<gene<<" "<<esta<<" "<<peso<<" "<<ale<<" "<<enfe<<" "<<dis<<" "<<san<<" "<<dom<<" "<<numEx<<" "<<numIn<<" "<<numCel<<" "<<numAux<<" "<<numAux2<<" "<<correo<<"\n";
					}
					lec>>apeAux1;
				}
				lec.close();
				editexp.close();
			}else
				cout<<"Error"<<endl;
				remove("Expediente.txt");
				rename("EditarExp.txt", "Expediente.txt");
		break;
		
		case 4:
			system("cls");
			if(lec.is_open()){
				cout<<"Ingrese el folio: ";
				cin>>folio1;
				lec>>folio;
				cout<<"Ingrese el Apellido Materno: ";
				cin>>apeMaAux1;
				while(!lec.eof()){
					lec>>nombre;
					lec>>ape;
					lec>>apeMa;
					lec>>edad;
					lec>>gene;
					lec>>esta;
					lec>>peso;
					lec>>ale;
					lec>>enfe;
					lec>>dis;
					lec>>san;
					lec>>dom;
					lec>>numEx;
					lec>>numIn;
					lec>>numCel;
					lec>>numAux;
					lec>>numAux2;
					lec>>correo;
					if(apeMa == apeMaAux1){
						cout<<"Nuevo Apellido paterno: ";
						cin>>apeMaAux1;
						editexp<<folio<<" "<<nombre<<" "<<ape<<" "<<apeMaAux1<<" "<<edad<<" "<<gene<<" "<<esta<<" "<<peso<<" "<<ale<<" "<<enfe<<" "<<dis<<" "<<san<<" "<<dom<<" "<<numEx<<" "<<numIn<<" "<<numCel<<" "<<numAux<<" "<<numAux2<<" "<<correo<<"\n";
					}else{
						editexp<<folio<<" "<<nombre<<" "<<ape<<" "<<apeMa<<" "<<edad<<" "<<gene<<" "<<esta<<" "<<peso<<" "<<ale<<" "<<enfe<<" "<<dis<<" "<<san<<" "<<dom<<" "<<numEx<<" "<<numIn<<" "<<numCel<<" "<<numAux<<" "<<numAux2<<" "<<correo<<"\n";
					}
					lec>>apeMaAux1;
				}
				lec.close();
				editexp.close();
			}else
				cout<<"Error"<<endl;
				remove("Expediente.txt");
				rename("EditarExp.txt", "Expediente.txt");
		break;
		
		//Editar fecha de nacimiento
		case 5:
			system("cls");
			if(lec.is_open()){
				cout<<"Ingrese el folio: ";
				cin>>folio1;
				lec>>folio;
				cout<<"Ingrese la fecha de nacimiento(dd/mm/aa): ";
				cin>>edadAux1;
				while(!lec.eof()){
					lec>>nombre;
					lec>>ape;
					lec>>apeMa;
					lec>>edad;
					lec>>gene;
					lec>>esta;
					lec>>peso;
					lec>>ale;
					lec>>enfe;
					lec>>dis;
					lec>>san;
					lec>>dom;
					lec>>numEx;
					lec>>numIn;
					lec>>numCel;
					lec>>numAux;
					lec>>numAux2;
					lec>>correo;
					if(edad == edadAux1){
						cout<<"Nueva fecha de nacimiento(dd/mm/aa): ";
						cin>>edadAux1;
						editexp<<folio<<" "<<nombre<<" "<<ape<<" "<<apeMa<<" "<<edadAux1<<" "<<gene<<" "<<esta<<" "<<peso<<" "<<ale<<" "<<enfe<<" "<<dis<<" "<<san<<" "<<dom<<" "<<numEx<<" "<<numIn<<" "<<numCel<<" "<<numAux<<" "<<numAux2<<" "<<correo<<"\n";
					}else{
						editexp<<folio<<" "<<nombre<<" "<<ape<<" "<<apeMa<<" "<<edad<<" "<<gene<<" "<<esta<<" "<<peso<<" "<<ale<<" "<<enfe<<" "<<dis<<" "<<san<<" "<<dom<<" "<<numEx<<" "<<numIn<<" "<<numCel<<" "<<numAux<<" "<<numAux2<<" "<<correo<<"\n";
					}
					lec>>edadAux1;
				}
				lec.close();
				editexp.close();
			}else
				cout<<"Error"<<endl;
				remove("Expediente.txt");
				rename("EditarExp.txt", "Expediente.txt");
		break;
		
		// genero
		case 6:
			system("cls");
			if(lec.is_open()){
				cout<<"Ingrese el folio: ";
				cin>>folio1;
				lec>>folio;
				cout<<"Ingrese el genero: ";
				cin>>geneAux1;
				while(!lec.eof()){
					lec>>nombre;
					lec>>ape;
					lec>>apeMa;
					lec>>edad;
					lec>>gene;
					lec>>esta;
					lec>>peso;
					lec>>ale;
					lec>>enfe;
					lec>>dis;
					lec>>san;
					lec>>dom;
					lec>>numEx;
					lec>>numIn;
					lec>>numCel;
					lec>>numAux;
					lec>>numAux2;
					lec>>correo;
					if(gene == geneAux1){
						cout<<"Ingrese el nuevo genero: ";
						cin>>geneAux1;
						editexp<<folio<<" "<<nombre<<" "<<ape<<" "<<apeMa<<" "<<edad<<" "<<geneAux1<<" "<<esta<<" "<<peso<<" "<<ale<<" "<<enfe<<" "<<dis<<" "<<san<<" "<<dom<<" "<<numEx<<" "<<numIn<<" "<<numCel<<" "<<numAux<<" "<<numAux2<<" "<<correo<<"\n";
					}else{
						editexp<<folio<<" "<<nombre<<" "<<ape<<" "<<apeMa<<" "<<edad<<" "<<gene<<" "<<esta<<" "<<peso<<" "<<ale<<" "<<enfe<<" "<<dis<<" "<<san<<" "<<dom<<" "<<numEx<<" "<<numIn<<" "<<numCel<<" "<<numAux<<" "<<numAux2<<" "<<correo<<"\n";
					}
					lec>>geneAux1;
				}
				lec.close();
				editexp.close();
			}else
				cout<<"Error"<<endl;
				remove("Expediente.txt");
				rename("EditarExp.txt", "Expediente.txt");
		break;
		
		// estatura
		case 7:
			system("cls");
			if(lec.is_open()){
				cout<<"Ingrese el folio: ";
				cin>>folio1;
				lec>>folio;
				cout<<"Ingrese la estatura: ";
				cin>>estaAux1;
				while(!lec.eof()){
					lec>>nombre;
					lec>>ape;
					lec>>apeMa;
					lec>>edad;
					lec>>gene;
					lec>>esta;
					lec>>peso;
					lec>>ale;
					lec>>enfe;
					lec>>dis;
					lec>>san;
					lec>>dom;
					lec>>numEx;
					lec>>numIn;
					lec>>numCel;
					lec>>numAux;
					lec>>numAux2;
					lec>>correo;
					if(esta == estaAux1){
						cout<<"Nueva estatura: ";
						cin>>estaAux1;
						editexp<<folio<<" "<<nombre<<" "<<ape<<" "<<apeMa<<" "<<edad<<" "<<gene<<" "<<estaAux1<<" "<<peso<<" "<<ale<<" "<<enfe<<" "<<dis<<" "<<san<<" "<<dom<<" "<<numEx<<" "<<numIn<<" "<<numCel<<" "<<numAux<<" "<<numAux2<<" "<<correo<<"\n";
					}else{
						editexp<<folio<<" "<<nombre<<" "<<ape<<" "<<apeMa<<" "<<edad<<" "<<gene<<" "<<esta<<" "<<peso<<" "<<ale<<" "<<enfe<<" "<<dis<<" "<<san<<" "<<dom<<" "<<numEx<<" "<<numIn<<" "<<numCel<<" "<<numAux<<" "<<numAux2<<" "<<correo<<"\n";
					}
					lec>>estaAux1;
				}
				lec.close();
				editexp.close();
			}else
				cout<<"Error"<<endl;
				remove("Expediente.txt");
				rename("EditarExp.txt", "Expediente.txt");
		break;
		
		//editar peso
		case 8:
			system("cls");
			if(lec.is_open()){
				cout<<"Ingrese el folio: ";
				cin>>folio1;
				lec>>folio;
				cout<<"Ingrese el peso: ";
				cin>>pesoAux1;
				while(!lec.eof()){
					lec>>nombre;
					lec>>ape;
					lec>>apeMa;
					lec>>edad;
					lec>>gene;
					lec>>esta;
					lec>>peso;
					lec>>ale;
					lec>>enfe;
					lec>>dis;
					lec>>san;
					lec>>dom;
					lec>>numEx;
					lec>>numIn;
					lec>>numCel;
					lec>>numAux;
					lec>>numAux2;
					lec>>correo;
					if(peso == pesoAux1){
						cout<<"Nuevo peso: ";
						cin>>pesoAux1;
						editexp<<folio<<" "<<nombre<<" "<<ape<<" "<<apeMa<<" "<<edad<<" "<<gene<<" "<<esta<<" "<<pesoAux1<<" "<<ale<<" "<<enfe<<" "<<dis<<" "<<san<<" "<<dom<<" "<<numEx<<" "<<numIn<<" "<<numCel<<" "<<numAux<<" "<<numAux2<<" "<<correo<<"\n";
					}else{
						editexp<<folio<<" "<<nombre<<" "<<ape<<" "<<apeMa<<" "<<edad<<" "<<gene<<" "<<esta<<" "<<peso<<" "<<ale<<" "<<enfe<<" "<<dis<<" "<<san<<" "<<dom<<" "<<numEx<<" "<<numIn<<" "<<numCel<<" "<<numAux<<" "<<numAux2<<" "<<correo<<"\n";
					}
					lec>>pesoAux1;
				}
				lec.close();
				editexp.close();
			}else
				cout<<"Error"<<endl;
				remove("Expediente.txt");
				rename("EditarExp.txt", "Expediente.txt");
		break;
		
		//editar alergias
		case 9:
			system("cls");
			if(lec.is_open()){
				cout<<"Ingrese el folio: ";
				cin>>folio1;
				lec>>folio;
				cout<<"Ingrese si tiene o no alergias: ";
				cin>>aleAux1;
				while(!lec.eof()){
					lec>>nombre;
					lec>>ape;
					lec>>apeMa;
					lec>>edad;
					lec>>gene;
					lec>>esta;
					lec>>peso;
					lec>>ale;
					lec>>enfe;
					lec>>dis;
					lec>>san;
					lec>>dom;
					lec>>numEx;
					lec>>numIn;
					lec>>numCel;
					lec>>numAux;
					lec>>numAux2;
					lec>>correo;
					if(ale == aleAux1){
						cout<<"Padece de alergias: ";
						cin>>aleAux1;
						editexp<<folio<<" "<<nombre<<" "<<ape<<" "<<apeMa<<" "<<edad<<" "<<gene<<" "<<esta<<" "<<peso<<" "<<aleAux1<<" "<<enfe<<" "<<dis<<" "<<san<<" "<<dom<<" "<<numEx<<" "<<numIn<<" "<<numCel<<" "<<numAux<<" "<<numAux2<<" "<<correo<<"\n";
					}else{
						editexp<<folio<<" "<<nombre<<" "<<ape<<" "<<apeMa<<" "<<edad<<" "<<gene<<" "<<esta<<" "<<peso<<" "<<ale<<" "<<enfe<<" "<<dis<<" "<<san<<" "<<dom<<" "<<numEx<<" "<<numIn<<" "<<numCel<<" "<<numAux<<" "<<numAux2<<" "<<correo<<"\n";
					}
					lec>>aleAux1;
				}
				lec.close();
				editexp.close();
			}else
				cout<<"Error"<<endl;
				remove("Expediente.txt");
				rename("EditarExp.txt", "Expediente.txt");
		break;
		
		//editar enfermedades cronicas
		case 10:
			system("cls");
			if(lec.is_open()){
				cout<<"\tIngrese el folio: ";
				cin>>folio1;
				lec>>folio;
				cout<<"\n\tIngrese si tiene o no enfermedades cronicas: ";
				cin>>enfeAux1;
				while(!lec.eof()){
					lec>>nombre;
					lec>>ape;
					lec>>apeMa;
					lec>>edad;
					lec>>gene;
					lec>>esta;
					lec>>peso;
					lec>>ale;
					lec>>enfe;
					lec>>dis;
					lec>>san;
					lec>>dom;
					lec>>numEx;
					lec>>numIn;
					lec>>numCel;
					lec>>numAux;
					lec>>numAux2;
					lec>>correo;
					if(enfe == enfeAux1){
						cout<<"Padece de enfermedades cronicas: ";
						cin>>enfeAux1;
						editexp<<folio<<" "<<nombre<<" "<<ape<<" "<<apeMa<<" "<<edad<<" "<<gene<<" "<<esta<<" "<<peso<<" "<<ale<<" "<<enfeAux1<<" "<<dis<<" "<<san<<" "<<dom<<" "<<numEx<<" "<<numIn<<" "<<numCel<<" "<<numAux<<" "<<numAux2<<" "<<correo<<"\n";
					}else{
						editexp<<folio<<" "<<nombre<<" "<<ape<<" "<<apeMa<<" "<<edad<<" "<<gene<<" "<<esta<<" "<<peso<<" "<<ale<<" "<<enfe<<" "<<dis<<" "<<san<<" "<<dom<<" "<<numEx<<" "<<numIn<<" "<<numCel<<" "<<numAux<<" "<<numAux2<<" "<<correo<<"\n";
					}
					lec>>enfeAux1;
				}
				lec.close();
				editexp.close();
			}else
				cout<<"Error"<<endl;
				remove("Expediente.txt");
				rename("EditarExp.txt", "Expediente.txt");
		break;
		
		//editar discapacidades
		case 11:
			system("cls");
			if(lec.is_open()){
				cout<<"Ingrese el folio: ";
				cin>>folio1;
				lec>>folio;
				cout<<"Ingrese el dato que desea cambiar: ";
				cin>>disAux1;
				while(!lec.eof()){
					lec>>nombre;
					lec>>ape;
					lec>>apeMa;
					lec>>edad;
					lec>>gene;
					lec>>esta;
					lec>>peso;
					lec>>ale;
					lec>>enfe;
					lec>>dis;
					lec>>san;
					lec>>dom;
					lec>>numEx;
					lec>>numIn;
					lec>>numCel;
					lec>>numAux;
					lec>>numAux2;
					lec>>correo;
					if(dis == disAux1){
						cout<<"Ingrese el nuevo dato: ";
						cin>>disAux1;
						editexp<<folio<<" "<<nombre<<" "<<ape<<" "<<apeMa<<" "<<edad<<" "<<gene<<" "<<esta<<" "<<peso<<" "<<ale<<" "<<enfe<<" "<<disAux1<<" "<<san<<" "<<dom<<" "<<numEx<<" "<<numIn<<" "<<numCel<<" "<<numAux<<" "<<numAux2<<" "<<correo<<"\n";
					}else{
						editexp<<folio<<" "<<nombre<<" "<<ape<<" "<<apeMa<<" "<<edad<<" "<<gene<<" "<<esta<<" "<<peso<<" "<<ale<<" "<<enfe<<" "<<dis<<" "<<san<<" "<<dom<<" "<<numEx<<" "<<numIn<<" "<<numCel<<" "<<numAux<<" "<<numAux2<<" "<<correo<<"\n";
					}
					lec>>disAux1;
				}
				lec.close();
				editexp.close();
			}else
				cout<<"Error"<<endl;
				remove("Expediente.txt");
				rename("EditarExp.txt", "Expediente.txt");
		break;
		
		//editar tipo de sangre
		case 12:
			system("cls");
			if(lec.is_open()){
				cout<<"Ingrese el folio: ";
				cin>>folio1;
				lec>>folio;
				cout<<"Ingrese el dato que desea cambiar: ";
				cin>>sanAux1;
				while(!lec.eof()){
					lec>>nombre;
					lec>>ape;
					lec>>apeMa;
					lec>>edad;
					lec>>gene;
					lec>>esta;
					lec>>peso;
					lec>>ale;
					lec>>enfe;
					lec>>dis;
					lec>>san;
					lec>>dom;
					lec>>numEx;
					lec>>numIn;
					lec>>numCel;
					lec>>numAux;
					lec>>numAux2;
					lec>>correo;
					if(san == sanAux1){
						cout<<"Tipo de sangre: ";
						cin>>sanAux1;
						editexp<<folio<<" "<<nombre<<" "<<ape<<" "<<apeMa<<" "<<edad<<" "<<gene<<" "<<esta<<" "<<peso<<" "<<ale<<" "<<enfe<<" "<<dis<<" "<<sanAux1<<" "<<dom<<" "<<numEx<<" "<<numIn<<" "<<numCel<<" "<<numAux<<" "<<numAux2<<" "<<correo<<"\n";
					}else{
						editexp<<folio<<" "<<nombre<<" "<<ape<<" "<<apeMa<<" "<<edad<<" "<<gene<<" "<<esta<<" "<<peso<<" "<<ale<<" "<<enfe<<" "<<dis<<" "<<san<<" "<<dom<<" "<<numEx<<" "<<numIn<<" "<<numCel<<" "<<numAux<<" "<<numAux2<<" "<<correo<<"\n";
					}
					lec>>sanAux1;
				}
				lec.close();
				editexp.close();
			}else
				cout<<"Error"<<endl;
				remove("Expediente.txt");
				rename("EditarExp.txt", "Expediente.txt");
		break;
		
		//editar calle
		case 13:
			system("cls");
			if(lec.is_open()){
				cout<<"Ingrese el folio: ";
				cin>>folio1;
				lec>>folio;
				cout<<"Ingrese el dato anterior: ";
				cin>>domAux1;
				while(!lec.eof()){
					lec>>nombre;
					lec>>ape;
					lec>>apeMa;
					lec>>edad;
					lec>>gene;
					lec>>esta;
					lec>>peso;
					lec>>ale;
					lec>>enfe;
					lec>>dis;
					lec>>san;
					lec>>dom;
					lec>>numEx;
					lec>>numIn;
					lec>>numCel;
					lec>>numAux;
					lec>>numAux2;
					lec>>correo;
					if(dom == domAux1){
						cout<<"Calle: ";
						cin>>domAux1;
						editexp<<folio<<" "<<nombre<<" "<<ape<<" "<<apeMa<<" "<<edad<<" "<<gene<<" "<<esta<<" "<<peso<<" "<<ale<<" "<<enfe<<" "<<dis<<" "<<san<<" "<<domAux1<<" "<<numEx<<" "<<numIn<<" "<<numCel<<" "<<numAux<<" "<<numAux2<<" "<<correo<<"\n";
					}else{
						editexp<<folio<<" "<<nombre<<" "<<ape<<" "<<apeMa<<" "<<edad<<" "<<gene<<" "<<esta<<" "<<peso<<" "<<ale<<" "<<enfe<<" "<<dis<<" "<<san<<" "<<dom<<" "<<numEx<<" "<<numIn<<" "<<numCel<<" "<<numAux<<" "<<numAux2<<" "<<correo<<"\n";
					}
					lec>>domAux1;
				}
				lec.close();
				editexp.close();
			}else
				cout<<"Error"<<endl;
				remove("Expediente.txt");
				rename("EditarExp.txt", "Expediente.txt");
		break;
		
		//editar numero exterior
		case 14:
			system("cls");
			if(lec.is_open()){
				cout<<"\tIngrese el folio: ";
				cin>>folio1;
				lec>>folio;
				cout<<"Ingrese el dato anterior: ";
				cin>>numExAux1;
				while(!lec.eof()){
					lec>>nombre;
					lec>>ape;
					lec>>apeMa;
					lec>>edad;
					lec>>gene;
					lec>>esta;
					lec>>peso;
					lec>>ale;
					lec>>enfe;
					lec>>dis;
					lec>>san;
					lec>>dom;
					lec>>numEx;
					lec>>numIn;
					lec>>numCel;
					lec>>numAux;
					lec>>numAux2;
					lec>>correo;
					if(numEx == numExAux1){
						cout<<"Numero exterior: ";
						cin>>numExAux1;
						editexp<<folio<<" "<<nombre<<" "<<ape<<" "<<apeMa<<" "<<edad<<" "<<gene<<" "<<esta<<" "<<peso<<" "<<ale<<" "<<enfe<<" "<<dis<<" "<<san<<" "<<dom<<" "<<numExAux1<<" "<<numIn<<" "<<numCel<<" "<<numAux<<" "<<numAux2<<" "<<correo<<"\n";
					}else{
						editexp<<folio<<" "<<nombre<<" "<<ape<<" "<<apeMa<<" "<<edad<<" "<<gene<<" "<<esta<<" "<<peso<<" "<<ale<<" "<<enfe<<" "<<dis<<" "<<san<<" "<<dom<<" "<<numEx<<" "<<numIn<<" "<<numCel<<" "<<numAux<<" "<<numAux2<<" "<<correo<<"\n";
					}
					lec>>numExAux1;
				}
				lec.close();
				editexp.close();
			}else
				cout<<"Error"<<endl;
				remove("Expediente.txt");
				rename("EditarExp.txt", "Expediente.txt");
		break;
		
		//Editar numero interior
		case 15:
			system("cls");
			if(lec.is_open()){
				cout<<"Ingrese el folio: ";
				cin>>folio1;
				lec>>folio;
				cout<<"Ingrese el dato anterior: ";
				cin>>numInAux1;
				while(!lec.eof()){
					lec>>nombre;
					lec>>ape;
					lec>>apeMa;
					lec>>edad;
					lec>>gene;
					lec>>esta;
					lec>>peso;
					lec>>ale;
					lec>>enfe;
					lec>>dis;
					lec>>san;
					lec>>dom;
					lec>>numEx;
					lec>>numIn;
					lec>>numCel;
					lec>>numAux;
					lec>>numAux2;
					lec>>correo;
					if(numIn == numInAux1){
						cout<<"Numero interior: ";
						cin>>numInAux1;
						editexp<<folio<<" "<<nombre<<" "<<ape<<" "<<apeMa<<" "<<edad<<" "<<gene<<" "<<esta<<" "<<peso<<" "<<ale<<" "<<enfe<<" "<<dis<<" "<<san<<" "<<dom<<" "<<numEx<<" "<<numInAux1<<" "<<numCel<<" "<<numAux<<" "<<numAux2<<" "<<correo<<"\n";
					}else{
						editexp<<folio<<" "<<nombre<<" "<<ape<<" "<<apeMa<<" "<<edad<<" "<<gene<<" "<<esta<<" "<<peso<<" "<<ale<<" "<<enfe<<" "<<dis<<" "<<san<<" "<<dom<<" "<<numEx<<" "<<numIn<<" "<<numCel<<" "<<numAux<<" "<<numAux2<<" "<<correo<<"\n";
					}
					lec>>numInAux1;
				}
				lec.close();
				editexp.close();
			}else
				cout<<"Error"<<endl;
				remove("Expediente.txt");
				rename("EditarExp.txt", "Expediente.txt");
		break;
		
		//Editar numero de celular
		case 16:
			system("cls");
			if(lec.is_open()){
				cout<<"Ingrese el folio: ";
				cin>>folio1;
				lec>>folio;
				cout<<"Ingrese el dato anterior: ";
				cin>>numCelAux1;
				while(!lec.eof()){
					lec>>nombre;
					lec>>ape;
					lec>>apeMa;
					lec>>edad;
					lec>>gene;
					lec>>esta;
					lec>>peso;
					lec>>ale;
					lec>>enfe;
					lec>>dis;
					lec>>san;
					lec>>dom;
					lec>>numEx;
					lec>>numIn;
					lec>>numCel;
					lec>>numAux;
					lec>>numAux2;
					lec>>correo;
					if(numCel == numCelAux1){
						cout<<"Numero de celular: ";
						cin>>numCelAux1;
						editexp<<folio<<" "<<nombre<<" "<<ape<<" "<<apeMa<<" "<<edad<<" "<<gene<<" "<<esta<<" "<<peso<<" "<<ale<<" "<<enfe<<" "<<dis<<" "<<san<<" "<<dom<<" "<<numEx<<" "<<numIn<<" "<<numCelAux1<<" "<<numAux<<" "<<numAux2<<" "<<correo<<"\n";
					}else{
						editexp<<folio<<" "<<nombre<<" "<<ape<<" "<<apeMa<<" "<<edad<<" "<<gene<<" "<<esta<<" "<<peso<<" "<<ale<<" "<<enfe<<" "<<dis<<" "<<san<<" "<<dom<<" "<<numEx<<" "<<numIn<<" "<<numCel<<" "<<numAux<<" "<<numAux2<<" "<<correo<<"\n";
					}
					lec>>numCelAux1;
				}
				lec.close();
				editexp.close();
			}else
				cout<<"Error"<<endl;
				remove("Expediente.txt");
				rename("EditarExp.txt", "Expediente.txt");
		break;
		
		//editar numero de contacto
		case 17:
			system("cls");
			if(lec.is_open()){
				cout<<"Ingrese el folio: ";
				cin>>folio1;
				lec>>folio;
				cout<<"Ingrese el dato anterior: ";
				cin>>numaux1;
				while(!lec.eof()){
					lec>>nombre;
					lec>>ape;
					lec>>apeMa;
					lec>>edad;
					lec>>gene;
					lec>>esta;
					lec>>peso;
					lec>>ale;
					lec>>enfe;
					lec>>dis;
					lec>>san;
					lec>>dom;
					lec>>numEx;
					lec>>numIn;
					lec>>numCel;
					lec>>numAux;
					lec>>numAux2;
					lec>>correo;
					if(numAux == numaux1){
						cout<<"Numero de contacto: ";
						cin>>numaux1;
						editexp<<folio<<" "<<nombre<<" "<<ape<<" "<<apeMa<<" "<<edad<<" "<<gene<<" "<<esta<<" "<<peso<<" "<<ale<<" "<<enfe<<" "<<dis<<" "<<san<<" "<<dom<<" "<<numEx<<" "<<numIn<<" "<<numCel<<" "<<numaux1<<" "<<numAux2<<" "<<correo<<"\n";
					}else{
						editexp<<folio<<" "<<nombre<<" "<<ape<<" "<<apeMa<<" "<<edad<<" "<<gene<<" "<<esta<<" "<<peso<<" "<<ale<<" "<<enfe<<" "<<dis<<" "<<san<<" "<<dom<<" "<<numEx<<" "<<numIn<<" "<<numCel<<" "<<numAux<<" "<<numAux2<<" "<<correo<<"\n";
					}
					lec>>numaux1;
				}
				lec.close();
				editexp.close();
			}else
				cout<<"Error"<<endl;
				remove("Expediente.txt");
				rename("EditarExp.txt", "Expediente.txt");
		break;
		
		//editar numero de contacto 2
		case 18:
			system("cls");
			if(lec.is_open()){
				cout<<"Ingrese el folio: ";
				cin>>folio1;
				lec>>folio;
				cout<<"Ingrese el dato anterior: ";
				cin>>numaux5;
				while(!lec.eof()){
					lec>>nombre;
					lec>>ape;
					lec>>apeMa;
					lec>>edad;
					lec>>gene;
					lec>>esta;
					lec>>peso;
					lec>>ale;
					lec>>enfe;
					lec>>dis;
					lec>>san;
					lec>>dom;
					lec>>numEx;
					lec>>numIn;
					lec>>numCel;
					lec>>numAux;
					lec>>numAux2;
					lec>>correo;
					if(numAux2 == numaux5){
						cout<<"Numero de contacto 2: ";
						cin>>numaux5;
						editexp<<folio<<" "<<nombre<<" "<<ape<<" "<<apeMa<<" "<<edad<<" "<<gene<<" "<<esta<<" "<<peso<<" "<<ale<<" "<<enfe<<" "<<dis<<" "<<san<<" "<<dom<<" "<<numEx<<" "<<numIn<<" "<<numCel<<" "<<numAux<<" "<<numaux5<<" "<<correo<<"\n";
					}else{
						editexp<<folio<<" "<<nombre<<" "<<ape<<" "<<apeMa<<" "<<edad<<" "<<gene<<" "<<esta<<" "<<peso<<" "<<ale<<" "<<enfe<<" "<<dis<<" "<<san<<" "<<dom<<" "<<numEx<<" "<<numIn<<" "<<numCel<<" "<<numAux<<" "<<numAux2<<" "<<correo<<"\n";
					}
					lec>>numaux5;
				}
				lec.close();
				editexp.close();
			}else
				cout<<"Error"<<endl;
				remove("Expediente.txt");
				rename("EditarExp.txt", "Expediente.txt");
		break;
		
		//editar correo
		case 19:
			system("cls");
			if(lec.is_open()){
				cout<<"Ingrese el folio: ";
				cin>>folio1;
				lec>>folio;
				cout<<"Ingrese el dato anterior: ";
				cin>>correoAux1;
				while(!lec.eof()){
					lec>>nombre;
					lec>>ape;
					lec>>apeMa;
					lec>>edad;
					lec>>gene;
					lec>>esta;
					lec>>peso;
					lec>>ale;
					lec>>enfe;
					lec>>dis;
					lec>>san;
					lec>>dom;
					lec>>numEx;
					lec>>numIn;
					lec>>numCel;
					lec>>numAux;
					lec>>numAux2;
					lec>>correo;
					if(correo == correoAux1){
						cout<<"Numero exterior: ";
						cin>>correoAux1;
						editexp<<folio<<" "<<nombre<<" "<<ape<<" "<<apeMa<<" "<<edad<<" "<<gene<<" "<<esta<<" "<<peso<<" "<<ale<<" "<<enfe<<" "<<dis<<" "<<san<<" "<<dom<<" "<<numEx<<" "<<numIn<<" "<<numCel<<" "<<numAux<<" "<<numAux2<<" "<<correoAux1<<"\n";
					}else{
						editexp<<folio<<" "<<nombre<<" "<<ape<<" "<<apeMa<<" "<<edad<<" "<<gene<<" "<<esta<<" "<<peso<<" "<<ale<<" "<<enfe<<" "<<dis<<" "<<san<<" "<<dom<<" "<<numEx<<" "<<numIn<<" "<<numCel<<" "<<numAux<<" "<<numAux2<<" "<<correo<<"\n";
					}
					lec>>correoAux1;
				}
				lec.close();
				editexp.close();
			}else
				cout<<"Error"<<endl;
				remove("Expediente.txt");
				rename("EditarExp.txt", "Expediente.txt");
		break;
	}
}

//borrar expediente
void borrarexp(ifstream &lec){
	//limpiar la consola
	system("cls");
	string nombre;
	string ape;
	string apeMa;
	string edad;
	string gene;
	string esta;
	string peso;
	string ale;
	string enfe;
	string dis;
	string san;
	string dom;
	string numEx;
	string numIn;
	string numCel;
	string numAux;
	string numAux2;
	string correo;
	string folio;
	//busqueda
	string folio1;
	//String del historial familiar
	string nomb, ape2, apeMa2, edad2, paren, gene2, esta2, peso2, ale2, en, dis2, san2, dom2, numEx2, numIn2;
	string numCel2, numaux, numaux2, correo2;
	
	//string del historial familiar 2
	string nomb2, ape3, apeMa3, edad3, paren2, gene3, esta3, peso3, ale3, en2, dis3, san3, dom3, numEx3, numIn3;
	string numeCel, numeaux, numeaux2, correo3;
	//abrir archivos
	lec.open("Expediente.txt", ios::in);
	ofstream editexp("EditarExp.txt", ios::out);
	if(lec.is_open()){
				cout<<"Ingrese el folio: ";
				cin>>folio1;
				lec>>folio;
				while(!lec.eof()){
					lec>>nombre;
					lec>>ape;
					lec>>apeMa;
					lec>>edad;
					lec>>gene;
					lec>>esta;
					lec>>peso;
					lec>>ale;
					lec>>enfe;
					lec>>dis;
					lec>>san;
					lec>>dom;
					lec>>numEx;
					lec>>numIn;
					lec>>numCel;
					lec>>numAux;
					lec>>numAux2;
					lec>>correo;
					//Lectura de los datos del historial familiar
					lec>>nomb;
					lec>>ape2;
					lec>>apeMa2;
					lec>>edad2;
					lec>>paren;
					lec>>gene2;
					lec>>esta2;
					lec>>peso2;
					lec>>ale2;
					lec>>en;
					lec>>dis2;
					lec>>san2;
					lec>>dom2;
					lec>>numEx2;
					lec>>numIn2;
					lec>>numCel2;
					lec>>numaux;
					lec>>numaux2;
					lec>>correo2;
					//Lectura de los datos del historial familiar 2
					lec>>nomb2;
					lec>>ape3;
					lec>>apeMa3;
					lec>>edad3;
					lec>>paren2;
					lec>>gene3;
					lec>>esta3;
					lec>>peso3;
					lec>>ale3;
					lec>>en2;
					lec>>dis3;
					lec>>san3;
					lec>>dom3;
					lec>>numEx3;
					lec>>numIn3;
					lec>>numeCel;
					lec>>numeaux;
					lec>>numeaux2;
					lec>>correo3;
						if(folio == folio1){
							cout<<"Eliminado correctamente ";
							//Esta es la linea que hace la funcion de eliminar 
							Sleep(1500);
						}else{
							editexp<<folio<<" "<<nombre<<" "<<ape<<" "<<apeMa<<" "<<edad<<" "<<gene<<" "<<esta<<" "<<peso<<" "<<ale<<" "<<enfe<<" "<<dis<<" "<<san<<" "<<dom<<" "<<numEx<<" "<<numIn<<" "<<numCel<<" "<<numAux<<" "<<numAux2<<" "<<correo<<"\n";
						}
						lec>>folio;
					}
					lec.close();
					editexp.close();
				}else
					cout<<"Error"<<endl;
					remove("Expediente.txt");
					rename("EditarExp.txt", "Expediente.txt");
}

void calcular(ofstream &es){
	
}


void menuuser(){
	ofstream(esc);
	ifstream(lec);

	
	int opcion;
	
	system("cls");
	cout<<endl<<"\t      ";
	cout<<endl<<"\t                                  ";
	cout<<endl<<"\t         Usuario        ";
	cout<<endl<<"\t         ";
	cout<<endl<<"1. Registrar Expediente          ";
	cout<<endl<<"\t         ";
	cout<<endl<<"2. Consultar Expediente          ";
	cout<<endl<<"\t             ";
	cout<<endl<<"3. Editar Expediente             ";
	cout<<endl<<"\t       ";
	cout<<endl<<"4. Borra Expediente              ";
	cout<<endl<<"\t          ";
	cout<<endl<<"5. Registrar Cita                ";
	cout<<endl<<"\t  ";
	cout<<endl<<"6. Consultar Cita                ";
	cout<<endl<<"\t                       ";
	cout<<endl<<"7. Editar Cita                   ";
	cout<<endl<<"\t                                 ";
	cout<<endl<<"8. Borrar Cita                   ";
	cout<<endl<<"\t                                  ";
	cout<<endl<<"0. Salir                         ";
	cout<<endl<<"\t  ";
	cout<<endl<<"\tOpción:";
	cin>>opcion;

		switch(opcion){
			//Registar expediente
			case 1:
				system("cls");
				agregar(esc);
				menuuser();
				//agregarDatos(pacientes);
				//insertarDatos(frente, fin, pacientes);
			break;
			
			//Consultar expediente
			case 2:
				system("cls");
				consultar(lec);
				menuuser();
				
			break;
			
			//Editar expediente
			case 3:
				system("cls");
				editarexp(lec);
				menuuser();
			break;
			
			//Borrar expediente
			case 4:
				system("cls");
				borrarexp(lec);
				menuuser();
				/*agregarDatos(pacientes);
				insertarDatos(frente, fin, pacientes);*/
			break;
						
			//Agregar cita
			case 5:
				system("cls");
				agregarcita(esc);
				menuuser();
			break;
			
			//Consultar cita
			case 6:
				system("cls");
				consultarci(lec);
				menuuser();
			break;
				
			//editar cita
			case 7:
				system("cls");
				editarcita(lec);
				menuuser();
			break;
				
			//Borra cita
			case 8:
				system("cls");
				borrarcita(lec);
				menuuser();
			break;
			
			//IMC
			case 9:
				
			break;
		}
}

void agregarDatos(ICO &pacientes){
	
	ofstream foutput;
	ifstream finput;
	
	foutput.open ("Expedientes.txt",ios::app);
    finput.open ("Expedientes.txt");
	
	if(finput.is_open()){
		
		int nacimiento, edad;
		
		tiempo();
		cout<<"\n\t    ";
		foutput<<"\n   ";
		cout<<"\n\t|\n\t      Datos Generales       ";
		cout<<endl<<"\t                             ";
		foutput<<"\n\t|\n\t     Datos Generales     ";
		
		cout<<"Nombre: ";
		cin.getline(pacientes.nombre, 10, '\n');
		foutput<<"Nombre: "<< pacientes.nombre;
		
		cout<<"Apellido Paterno: ";
		cin.getline(pacientes.app, 10, '\n');
		foutput<<"Apellido Paterno: "<< pacientes.app;
		
		cout<<"Apellido Materno: ";
		cin.getline(pacientes.apm, 10, '\n');
		foutput<<"Apellido Materno: "<< pacientes.apm;
		
		cout<<"Género: ";
		cin.getline(pacientes.genero, 10, '\n');
		foutput<<"Genero: " << pacientes.genero;
		
		cout<<"Fecha de Nacimiento (dd/mm): ";
		cin.getline(pacientes.fechanac, 10, '\n');
		foutput<<"Fecha de Nacimiento: " << pacientes.fechanac;
		
    	printf("Año de Nacimiento: ");
    	scanf("%d", &nacimiento);
    	printf("Edad: ", edad);
		
		
		
		/*
		cout<<"\t| Folio de Expediente Clinico: ";
		cin>>pacientes.folio;
		foutput<<"\t\t| Folio: " << pacientes.folio;
	
		cout<<"\t| Ingresa Peso del Paciente en kilogramos: ";
		cin>>pacientes.peso;
		foutput<<"\n\t| Peso: " << pacientes.peso <<" kg.";
		
		cout<<"\t| Ingresa Altura del Paciente en metros: ";
		cin>>pacientes.altura;
		foutput<<"\t\t| Altura: " << pacientes.altura <<" m.";
		
		cout<<"\t| Ingresa Fecha de Nacimiento: ";
		cin>>pacientes.fecha;
		foutput<<"\t\t| Fecha de Nacimiento: "<< pacientes.fecha;
		
		cout<<"\t|\n\t|_________Indicadores Antropométricos___________";
		foutput<<"\n\t|\n\t|_______Indicadores Antropométricos________";
		cout<<"\n\t|Los siguientes datos se registran en cm";
		
		cout<<"\t|\n\t| Meñeca del Paciente: ";
		cin>>pacientes.muneca;
		foutput<<"\n\t| Muñeca: "<< pacientes.muneca <<"cm.";
		
		cout<<"\t| Brazo del Paciente: ";
		cin>>pacientes.brazo;
		foutput<<"\t| Brazo: "<< pacientes.brazo <<"cm.";
		
		cout<<"\t| Antebrazo del Paciente: ";
		cin>>pacientes.antebrazo;
		foutput<<"\t\t| Antebrazo: "<< pacientes.antebrazo <<"cm.";
		
		cout<<"\t| Muslo del Paciente: ";
		cin>>pacientes.muslo;
		foutput<<"\n\t| Muslo: "<< pacientes.muslo <<"cm.";
		
		cout<<"\t| Pantorrilla del Paciente: ";
		cin>>pacientes.pantorrilla;
		foutput<<"\t| Pantorrilla: "<< pacientes.pantorrilla <<"cm.";
		
		cout<<"\t| Cintura del Paciente: ";
		cin>>pacientes.cintura;
		foutput<<"\t| Cintura: "<< pacientes.cintura <<"cm.";
		
		cout<<"\t| Cadera del Paciente: ";
		cin>>pacientes.cadera;
		foutput<<"\n\t| Cadera: "<< pacientes.cadera <<"cm.";
		
		cout<<"\t| Humero del Paciente: ";
		cin>>pacientes.humero;
		foutput<<"\t| Humero: "<< pacientes.humero <<"cm.";
		
		cout<<"\t|----------Pliegues o Panículos-----------";
		foutput<<"\n\t|\n\t|----------Pliegues o Panículos------------";
		cout<<"\t|\n\t| tLos siguientes datos se registran en mm";
		
		cout<<"\t|\n\t| Biceps del Paciente: ";
		cin>>pacientes.biceps;
		foutput<<"\n\n\t| Biceps: "<< pacientes.biceps <<"mm.";
		
		cout<<"\t| Subescapular del Paciente: ";
		cin>>pacientes.subescapular;
		foutput<<"\t\t| Subescapular: "<< pacientes.subescapular <<"mm.";
		
		cout<<"\t| Triceps del Paciente: ";
		cin>>pacientes.triceps;
		foutput<<"\n\t| Triceps: "<< pacientes.triceps <<"mm.";
		
		cout<<"\t| Suprialiaco del Paciente: ";
		cin>>pacientes.suprailiaco;
		foutput<<"\t\t| Suprailiaco: "<< pacientes.suprailiaco <<"mm.";
		*/
		cout<<"\t      ";
		foutput<<"\n   ";
		
		
		cout<<"\n\t| Datos ingresados correctamente";
	
    	finput.close();
    	foutput.close();
		fflush(stdin);
    	menuuser();
	}else{
		cout<<"\n\t  Error en Archivo";
	}
}

void insertarDatos(Nodo *&frente, Nodo *&fin, ICO pacientes){
	//Declaro mi nuevo nodo
	Nodo *n_nodo = new Nodo();
	
	//Asignar los valores de los datos
	n_nodo -> pacientes = pacientes;
	
	//siguiente apunte a null
	n_nodo -> siguiente = NULL;
	
	//Primero verificar si esta vacia
	if(c_vacia(frente)){
		frente = n_nodo;
		//si la cola esta vacia frente = nuevo nodo
	}else{
		fin -> siguiente = n_nodo;//si la cola esta vacia
	}
	fin = n_nodo;
}

void eliminarDatos(Nodo *&frente, Nodo *&fin, ICO pacientes){
	pacientes = frente->pacientes;
	Nodo *aux = frente;
	
	if(frente == fin){
		frente = NULL;
		fin = NULL;
	}else{
		frente = frente -> siguiente;
	}
	
	delete aux;
}

void buscarDatos(Nodo *frente, ICO pacientes){
	
	bool band = false;
	
	Nodo *actual = new Nodo();
	actual = frente;
	
	cout<<"Ingrese Folio del Paciente: ";
	cin>>pacientes.nombre;
	
		while((actual != NULL) && (actual->pacientes.nombre <= pacientes.nombre)){
		if(actual->pacientes.nombre == pacientes.nombre){
			cout<<"Paciente: "<<actual->pacientes.nombre<<"; Sexo ("<<actual->pacientes.genero<<"; Peso: "<<actual->pacientes.peso<<" Si a sido encontrado en Registros\n";
		band = true;
		}
		actual = actual->siguiente;
	}
	if(band == true){
		
	}else{
	cout<<"Paciente: "<<actual->pacientes.nombre<<" No a sido endontrado en Registros\n";
	}
}

void modificarDato(Nodo *frente, ICO pacientes){
	
	bool band = false;
	
	Nodo* actual = new Nodo();
	actual = frente;
	
	cout<<"Ingresa Folio del Paciente: ";
	cin>>pacientes.nombre;
		
		while(actual!=NULL && band != true){
			
				if(actual->pacientes.nombre == pacientes.nombre){
					cout << "Paciente Encontrado";
					cout << "Nombre del Paciente: " << actual->pacientes.nombre;
					cout << "Ingrese Nuevo Nombre para este Paciente: ";
					cin >> actual -> pacientes.nombre;
				
					cout << "Sexo del Paciente: "<< actual->pacientes.genero;
					cout << "Ingrese Nuevo Sexo para este Paciente: ";
					cin >> actual -> pacientes.genero;
				
					cout << "Peso del Paciente: "<< actual->pacientes.peso;
					cout << "Ingrese Nuevo Peso para este Paciente: ";
					cin >> actual -> pacientes.peso;
				
					cout << "Paciente Modificado\n\n";
					band = true;
			}
			
			actual = actual->siguiente;
		}
		if(!band){
			cout << "Paciente No Encontrado\n\n";
		}		
}

bool c_vacia(Nodo *frente){
	//Operador Ternario para saber si esta vacia
	return(frente == NULL)? true:false;
}

void tiempo(){
	int hours, minutes, seconds, day, month, year;

	time_t now;

	time(&now);

	struct tm *local = localtime(&now);

	hours = local->tm_hour;
	minutes = local->tm_min;
	seconds = local->tm_sec;

	day = local->tm_mday;
	month = local->tm_mon + 1;
	year = local->tm_year + 1900;

	if (hours < 12) {
		printf("Hora: %02d:%02d:%02d am\n", hours, minutes, seconds);
	}
	else {
		printf("Hora: %02d:%02d:%02d pm\n", hours - 12, minutes, seconds);
	}
	printf("Fecha: %02d/%02d/%d\n", day, month, year);
}

void edadreal(){
	
	
}

