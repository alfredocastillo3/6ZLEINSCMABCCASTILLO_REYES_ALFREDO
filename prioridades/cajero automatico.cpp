#include <iostream>
#include <string.h>
#include <fstream>
#include <windows.h>


using namespace std;

using std::ofstream;

//ESTRUCTURAS
struct clientes{
	string nombre;
	double sueldo;
	
};


struct tarjetas{
	int usuario;
	int pin;
	
	struct clientes user;
	
};


//DECLARACIONES
struct tarjetas v[4];

int v1;
double retiro, saldo, agregar2, anterior, ret2, ag2;





//PROTOTIPOS
void titulo(string);
void cargar();
bool buscar(int, bool);
void menu();
void limit();
void consultar();
void retirar();
void verificar(double);
void menuretiro();
void agregar();
void agregarsaldo(double);
void menuagregar();
void imprimir();

void error();
void error2();
void error3();


main()
{
	int usuario, contra;
	
	cargar();	
	system("color 5");
	titulo(" BIENVENIDO ");
	
	cout << "INGRESA TU USUARIO  :  ";
	cin >> usuario ;
	cout << "\n \n";
	
	
		
	//verificar usuario 
	if (buscar(usuario, true))
	{
		cout << "INGRESA TU PIN  :  ";
		cin >> contra;
	
			
		//verificar pin 
		if(buscar(contra, false))
		{
			
			//VERIFICA SI COINCIDE LOS DATOS ENCONTRADOS
			if((v[v1].usuario == usuario) && (v[v1].pin == contra))
			{
				menu();
			}
			else
			{
				system("cls");
				titulo("BIENVENIDO AL CAJERO AUTOMATICO");
				
				cout << "\n \n EL USUARIO Y EL PIN NO COINCIDEN INTENTA DE NUEVO  \n \n";
				system("pause");
				return main();
			}
			
		}
		else
		{
			cout << "\n \n EL PIN ES INVALIDO  \n \n";
			system("pause");
			return main();
		}
	}
	else
	{
		cout << "\n \n USUARIO  INCORRECTO  \n \n";
		system("pause");
		return main();
	}
	
	
			
}

void menu()
{
	string op;
	
	
	system("cls");
	titulo("MENU DE CAJERO AUTOMATICO ");
	
	
	while(true)
	{
		cout << "1.  CONSULTAR SAlDO  \n";
		cout << "2.  RETIRAR   \n";
		cout << "3.  DEPOSITO \n";
		cout << "4.  HISTORIAL \n";
		cout << "5.  SALIR ";
		cout << "\n \n \n";	
		cout << "Elegir una Opcion  :   ";
		cin >> op;
		
		if (op == "1")
		{
			consultar();
			break;
		}
		else if(op == "2")
		{
			retirar();
			break;
		}
		else if(op == "3")
		{
			agregar();
			break;
		}
		else if(op == "4")
		{
			imprimir();
			break;
		}
		else if(op == "5")
		{
			main();
			break;
		}
		else
		{
			error();
			break;
		}
			
	
	}
	
}
void otros(){	
    system("cls");
	titulo("OPCIONES DE RETIRO ");
        cout<< "12. 500 \n \n";
		cout<< "13. 600 \n \n";
		cout<< "14. 700 \n \n";
		cout<< "15. 800 \n \n";
		cout<< "16. 900 \n \n";
		cout<< "17. 1000 \n \n";
		cout<< "18. 2000 \n \n";
		cout<< "19. 3000 \n \n";
		cout<< "20. 4000 \n \n";
		cout<< "21. 5000 \n \n";
		cout<< "22. 6000 \n \n";
		cout<< "23. 7000 \n \n";
		cout<< "24. 8000 \n \n";
		cout<< "25. 9000 \n \n";
		
		system("pause");
		
}
void consultar(){
	system("cls");
	titulo("CONSULTA DE SALDO ");
	
	cout << "  Usuario  :  " << v[v1].usuario << "\n \n";
	cout << "  Nombre   :  " << v[v1].user.nombre << "\n \n";
	cout << "  Saldo    :  " << v[v1].user.sueldo << "\n \n";

	
	system("pause");
	menu();
	
}


void retirar()
{
	retiro = 0;
	
	string op2;
	
	system("cls");
	titulo("OPCIONES DE RETIRO ");
	
	while(true)
	{
		cout<< "1.  50 \n \n";            
		cout<< "2.  100 \n \n";
		cout<< "3.  200 \n \n";
		cout<< "4.  220 \n \n";
		cout<< "5.  240 \n \n";
		cout<< "6.  250 \n \n";
		cout<< "7.  270 \n \n";
		cout<< "8.  290 \n \n";
		cout<< "9.  300 \n \n";
		cout<< "10. otros \n \n";
		cout<< "11.  Cancelar \n \n";
	
		
		cout << "\n \n \n";
		cout << "Elegir Opcio de Retiro  :  ";
		cin >> op2;
		
		if(op2=="1")
		{
			retiro = 50;
			
			verificar(retiro);
			break;
		}
		else if(op2=="2")
		{
			retiro = 100;
			verificar(retiro);
			break;
		}
		else if(op2=="3")
		{
			retiro = 200;
			verificar(retiro);
			break;
		}
		else if(op2=="4")
		{
			retiro = 220;
			verificar(retiro);
			break;
		}
		else if(op2=="5")
		{
			retiro = 240;
			
			verificar(retiro);
			break;
		}
		else if(op2=="6")
		{
			retiro = 250;
			verificar(retiro);
			break;
		}
		else if(op2=="7")
		{
			retiro = 270;
			verificar(retiro);
			break;
		}
		else if(op2=="8")
		{
			retiro = 290;
			verificar(retiro);
			break;
		}
		else if(op2=="9")
		{
			retiro = 330;
			
			verificar(retiro);
			break;
		}
		else if(op2=="10")
		{
			otros();
			
		
		}
		else if(op2=="12")
		{
			retiro = 500;
			verificar(retiro);
			break;
		}
		else if(op2=="13")
		{
			retiro = 220;
			verificar(retiro);
			break;
		}
		else if(op2=="14")
		{
			retiro = 700;
			
			verificar(retiro);
			break;
		}
		else if(op2=="15")
		{
			retiro = 800;
			verificar(retiro);
			break;
		}
		else if(op2=="16")
		{
			retiro = 900;
			verificar(retiro);
			break;
		}
		else if(op2=="17")
		{
			retiro = 1000;
			verificar(retiro);
			break;
		}
		else if(op2=="18")
		{
			retiro = 2000;
			
			verificar(retiro);
			break;
		}
		else if(op2=="19")
		{
			retiro = 3000;
			verificar(retiro);
			break;
		}
		else if(op2=="20")
		{
			retiro = 4000;
			verificar(retiro);
			break;
		}
		else if(op2=="21")
		{
			retiro = 5000;
			verificar(retiro);
			break;
		}
		else if(op2=="22")
		{
			retiro = 6000;
			
			verificar(retiro);
			break;
		}
		else if(op2=="23")
		{
			retiro = 7000;
			verificar(retiro);
			break;
		}
		else if(op2=="24")
		{
			retiro = 8000;
			verificar(retiro);
			break;
		}
		else if(op2=="25")
		{
			retiro = 9000;
			verificar(retiro);
			break;
		}
		else if(op2=="11")
		{
			menu();
		}
		
		else
		{
			error2();
			break;
			
		}
	}	
	
}

void verificar(double rt)
{
	saldo = v[v1].user.sueldo;
	anterior = saldo;
	
	if (saldo >= rt)
	{
		saldo = saldo - rt;
		v[v1].user.sueldo = saldo;
		ret2 = rt;
		system("cls");
		titulo("RETIRO DE SALDO ");
		cout << "SU SALDO DE " << rt << " FUE RETIRADO CON EXITO \n \n";
		cout << "SU NUEVO SALDO ES " << saldo << "\n \n \n";
		system("pause");
		menuretiro();		
		
	}
	else
	{
		system("cls");
		titulo("OPCIONES DE RETIRO ");
		cout << "SALDO INSUFICIENTE PARA EL RETIRO  \n \n \n";
		system("pause");
		retirar();
		
	}
	
}


void menuretiro()
{
	string op3;
	
	system("cls");
	titulo("OPCIONES DE RETIRO ");
	cout << "1. REALIZAR OTRO RETIRO   \n \n \n";
	cout << "2. IR AL MENU   \n \n \n";
	cout << "Elegir una Opcion  :   ";
	cin >> op3;
	
	
	if(op3== "1")
	{
		retirar();
	}
	else if(op3=="2")
	{
		menu();
	}
	else
	{
		menuretiro();
	}
	
	
}


void agregar()
{
	agregar2 = 10000;
	
	string op4;
	
	system("cls");
	titulo("Deposito ");
	
	while(true)
	{
		cout<< "1.  50 \n \n";
		cout<< "2.  100 \n \n";
		cout<< "3.  200 \n \n";
		cout<< "4.  500 \n \n";
	    cout<< "5.  1000 \n  \n";
	    cout<< "6.  5000 \n \n";
		cout<< "7.  6000 \n \n";
		cout<< "8.  7000 \n \n";
		cout<< "9.  8000 \n \n";
	    cout<< "10. 9000 \n  \n";
	    cout<< "12. 100000 \n  \n";
		cout<< "11.  Cancelar \n \n";
		
		
		cout << "\n \n \n";
		cout << "Elegir Opcio de Retiro  :  ";
		cin >> op4;
		
		if(op4=="1")
		{
			agregar2 = 50;
			agregarsaldo(agregar2);
			break;
		}
		else if(op4=="2")
		{
			agregar2 = 100;
			agregarsaldo(agregar2);
			break;
		}
		else if(op4=="3")
		{
			agregar2 = 200;
			agregarsaldo(agregar2);
			break;
		}
		else if(op4=="4")
		{
			agregar2 = 500;
			agregarsaldo(agregar2);
			break;
		}
			else if(op4=="5")
		{
			agregar2 = 1000;
			agregarsaldo(agregar2);
			break;
		}
		else if(op4=="6")
		{
			agregar2 = 5000;
			agregarsaldo(agregar2);
			break;
		}
		else if(op4=="7")
		{
			agregar2 = 6000;
			agregarsaldo(agregar2);
			break;
		}
		else if(op4=="8")
		{
			agregar2 = 7000;
			agregarsaldo(agregar2);
			break;
		}
			else if(op4=="9")
		{
			agregar2 = 8000;
			agregarsaldo(agregar2);
			break;
		}
				else if(op4=="10")
		{
			agregar2 = 9000;
			agregarsaldo(agregar2);
			break;
		}
		else if(op4=="12")
		{	
			limit();
		}
		else if(op4=="11")
		{
			menu();
		}
		else
		{
			error3();
			break;
			
		}
	}	
	
}


void limit(){
	 system("cls");
    cout <<"a llegado al limite de deposito";
    system("pause");
    menu();   
}
void agregarsaldo(double as)
{
	saldo = v[v1].user.sueldo;
	saldo = saldo + as;
	v[v1].user.sueldo = saldo;
	
		ag2 = as;
		system("cls");
		titulo("DEPOSITO ");
		cout << "SU SALDO DE " << as << " FUE AGREGADO CON EXITO \n \n";
		cout << "SU NUEVO SALDO ES " << saldo << "\n \n \n";
		system("pause");
		menuagregar();		

}

void menuagregar()
{
	string op5;
	
	system("cls");
	titulo("OPCIONES DE DEPOSITO");
	cout << "1. REALIZAR OTRO DEPOSITO   \n \n \n";
	cout << "2. IR AL MENU   \n \n \n";
	cout << "Elegir una Opcion  :   ";
	cin >> op5;
	
	
	if(op5== "1")
	{
		agregar();
	}
	else if(op5=="2")
	{
		menu();
	}
	else
	{
		menuagregar();
	}
	
	
}


void imprimir()
{
	lecopen("movimientos.txt",ios::in);
	
	system("cls");
	titulo("HISTORIAL DE MOVIMIENTOS ");
	
	ofstream imp("cliente.txt");
	
	cout << "USUARIO        :   " << v[v1].usuario << "\n \n";
	
	cout << "NOMBRE         :   " << v[v1].user.nombre << "\n \n";
	
	cout << "SALDO ANTERIOR :   " << anterior << "\n \n";
	
	cout << "SALDO RETIRADO   :   " << ret2 << "\n \n";

	cout << "SALDO DEPOSITADO :   " << ag2 << "\n \n";
	
	cout << "SALDO ACTUAL   :   " << v[v1].user.sueldo << "\n \n";
	
	
	
	imp  << "USUARIO        :   " << v[v1].usuario << "\n \n";	
	imp  << "NOMBRE         :   " << v[v1].user.nombre << "\n \n";	
	imp  << "SALDO ANTERIOR :   " << anterior << "\n \n";	
	imp  << "SALDO RETIRO   :   " << ret2 << "\n \n";	
	imp  << "MONTO AGREGADO :   " << ag2 << "\n \n";	
	imp  << "SALDO ACTUAL   :   " << v[v1].user.sueldo << "\n \n";

	
	imp.close();
		
	cout << "\n \n DATOS DE MOVIMIENTOS \n \n \n";
	system("pause");
	menu();
	
	
	
}



void error3()
{
	system("cls");
	titulo("OPCIONES INVALIDAS DEL CAJERO AUTOMATICO ");
	cout << "LA OPCION DE INGRESO DE SALDO NO EXISTE \n \n ";
	system("pause");
	agregar();
}



void error2()
{
	system("cls");
	titulo("OPCIONES INVALIDAS DEL CAJERO AUTOMATICO ");
	cout << "LA OPCION DE RETIRO NO EXISTE \n \n ";
	system("pause");
	retirar();
}


void error()
{
	system("cls");
	titulo("OPCIONES INVALIDAS DEL CAJERO AUTOMATICO ");
	cout << "LA OPCION INGRESADO NO EXISTE \n \n ";
	system("pause");
	menu();
}


void titulo(string title)
{
	int i;
	int val;
	
	val = title.length() ;
	
	val = val + 20;
	
	
	for(i=0; i<= val; i++)
	{
		cout << " ";
	}
	
	cout << "\n \n";
	
	for(i=0; i<= val; i++)
	{
		cout << " ";
		if(i==4 )
		{
			cout << title;
		}
		
		cout << "";
		
	}
	
	cout << "\n";
	
	for(i=0; i<= val; i++)
	{
		cout << " ";
	}
	
	cout << "\n \n \n";
	
}




void cargar()
{
	v[0].usuario= 2323;
	v[0].pin	= 1111;
	v[0].user.nombre = "DILAN";
	v[0].user.sueldo = 10000;
	
	v[1].usuario= 2324;
	v[1].pin	= 2222;
	v[1].user.nombre = "MISAEL";
	v[1].user.sueldo = 10000;
	
	
	v[2].usuario= 2325;
	v[2].pin	= 3333;
	v[2].user.nombre = "BRYAN";
	v[2].user.sueldo = 10000; 
	
	v[3].usuario= 2326;
	v[3].pin	= 4444;
	v[3].user.nombre = "STEPHANIE";
	v[3].user.sueldo = 10000;

	

	
}


bool buscar(int bs, bool up)
{
	int i=0;

	
	if(up == true)
	{
		for(i=0; i<= 3; i++)
		{
			if(v[i].usuario == bs)
			{
				v1 = i;
				return true;
			}
		
		
		
		}
	}
	else
	{
		for(i=0; i<= 3; i++)
		{
			if(v[i].pin == bs)
			{
			
				return true;
			}
		
		
		}
	}

}








