#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#ifdef __MSDOS__
#include <iostream.h>
#else
#include <cstdlib>
using namespace std;
#endif

typedef struct Paciente{ //Definimos //Definimos una estructura estructura donde se ve las características características que tendrá cada paciente. paciente.
char Nombre[50];//Nombre Completo maximo de 49 caracteres, y un espacio para el

char DNI[9];//Creamos la variable char DNI[9];//Creamos la variable DNI de 8 digitos y un DNI de 8 digitos y un espacio para la variable de fin espacio para la variable de fin

char Fecha[11];//Fecha en formato aaaa/mm/dd un espacio para el caracter '\0'
char alergico_a[50];//Cadena para guardar los medicamentos si es alergico a alguno
char tiene_seguro;//caracer S o N , S=asegurado y N= No asegurado
int edad;
}Paciente;
void CrearArchivoPaciente(){//Esta opciòn creará un archivo donde se guardara la información

FILE *ArchivoPaciente;
Paciente Nuevo;//Creamos un nuevo elemento paciente
system("cls");
printf("\t\t\t*****Nuevo Paciente*****\n");
fflush(stdin);//limpia el buffer para evitar errores (
printf("\n\t\t*Nombre completo: ");
gets(Nuevo.Nombre);//Capturamos el nombre
printf("\n\t\t*Fecha de Registro: ");//Capturamos la fecha de ingreso
scanf("%s",&Nuevo.Fecha);
char str[40];
  strcpy (str,Nuevo.Nombre);//Lo (str,Nuevo.Nombre);//Lo copiamos copiamos a una cadena de caracteres caracteres
strcat (str,".dat");//Agregamos ".dat" para crear el archivo con su nombre del paciente
ArchivoPaciente=fopen(str,"a+");//Creamos el archivo nuevo del paciente
fflush(stdin);//Limpia el buffer
if (ArchivoPaciente==NULL){//En caso de un error

system("\nPause");
}
else{
//Guardamos nombre y fecha de registro en el archivo
fprintf(ArchivoPaciente,"\n Nombre: %s ",Nuevo.Nombre);

fclose(ArchivoPaciente);//cerramos el archivo
printf("\nPaciente %s registrado con exito.\n",Nuevo.Nombre);
system("\nPause");
} }
void IngresarNuevoPaciente(){//Esta opciòn permitirá ingresar información ingresar información del nuevo paciente del nuevo paciente

FILE *ArchivoPaciente;
Paciente Nuevo;//Creamos un nuevo elemento paciente
system("cls");
printf("\t\t\t*****Editar Paciente*****\n");
//Capturamos el nombre y evitamos que salte
fflush(stdin);//vaceamos el buffer para evitar errores
printf("\n\t\t*Nombre a buscar: ");
gets(Nuevo.Nombre);
char str[40];//creamos una cadena para usarla luego
strcpy (str,Nuevo.Nombre);//Copiamos nombre en la cadena creada
  strcat (str,".dat");//concatenamos (str,".dat");//concatenamos con ".dat" para crear ese tipo de archivos archivos
ArchivoPaciente=fopen(str,"a+");//Abrimos el archivo para escribir sobre el.
if (ArchivoPaciente==NULL){//En caso de error

system("\nPause");
}
else{
system("cls");

fflush(stdin);
//Agregamos los demas atributos del //Agregamos los demas atributos del paciente paciente
printf("\n\t\t*edad: ");fflush(stdin);
scanf("%i",&Nuevo.edad);
//Capturamos el DNI y vaceamos el buffer
printf("\n\t\t*No: ");fflush(stdin);
scanf("%s",&Nuevo.DNI);
//Capturamos Alergias y vaceamos el buffer
printf("\n\t\t*Alergico a (ninguno = N): ");fflush(stdin);
gets(Nuevo.alergico_a);
//Capturamos asegurados y vaceamos el buffer
printf("\n\t\t*Tiene seguro? (s/n): ");fflush(stdin);
scanf("%c",&Nuevo.tiene_seguro);
//Guardamos los datos en los arc //Guardamos los datos en los archivos correspondien hivos correspondientes
fprintf(ArchivoPaciente,"\nDNI: %s ",Nuevo.DNI);
fprintf(ArchivoPaciente,"\nAlergico a: %s ",Nuevo.alergico_a);
fprintf(ArchivoPaciente,"\nAsegurado: %c ",Nuevo.tiene_seguro);
fprintf(ArchivoPaciente,"\nEDAD: %i ",Nuevo.edad);
//Cerramos el archivo
fclose(ArchivoPaciente);

system("Pause");
  }
}
void MostrarHistorialDePaciente(){
Paciente Nuevo;
FILE *Archivo;
system("cls");
fflush(stdin);//vaceamos el buffer para evitar errores
printf("\n\t\t******Historial******");
printf("\n\t\t*Nombre a buscar: ");//Pedimos el nombre del paciente del paciente
gets(Nuevo.Nombre);
char str[40];//creamos una cadena de caracteres
strcpy (str,Nuevo.Nombre);//copiamos nombre en ella
strcat (str,".dat");//concatenamos con ".dat"
Archivo=fopen(str,"r");//Abrimos el archivo para lectura
if (Archivo==NULL){//En caso no exista, dará error

system("\nPause");
}
else{
system("cls");

char c[30];
fflush(stdin);//vaceamos el buffer para evitar errores
while(!feof(Archivo)){//Mientras no sea el final del archivo
fscanf(Archivo," %[^\n]",&c);//leemos linea por linea
printf("\n%s",c);//Imprimimos lo leido
}
fclose(Archivo);//cerramos el archivo
printf("\n\n");
system("\tPause");
  }
}
void BuscarHistorialPaciente(){
char nombre[40];
system("cls");
printf("\t\t******Buscar Paciente******\n");
printf("\n\n\t\tIngrese nombre a buscar: ");
fflush(stdin);//vaceamos el buffer para evitar errores
gets(nombre);
FILE *Archivo;//creamos una instancia para abrir el archivo
char str[40];//creamos una cadena de caracteres para copiar nombre
strcpy (str,nombre);
strcat (str,".dat");//concatenamos con ".dat"
Archivo=fopen(str,"a+");//abrimos el archivo para agregar algunos datos
if (Archivo==NULL){//en caso de un error
perror("\n\nNo se encuentra el paciente");
system("Pause");
}
else{
system("cls");

char c[30];
fflush(stdin);//vaceamos el buffer para evitar errores
while(!feof(Archivo)){//Mientras no sea el final del archivo
fscanf(Archivo," %[^\n]",&c);//leemos linea por linea
printf("\n%s",c);//Imprimimos lo leido
}
char extras[50];//Cadenas extras para el historial
fprintf(Archivo,"\n\n\n****Nueva Cita****");


fprintf(Archivo,"\nFecha: %s",extras);fflush(stdin);
printf("\tDoctor: ");gets(extras);//Doctor que lo atiende
fprintf(Archivo,"\nDoctor: %s",extras);fflush(stdin);
printf("\tEspecialidad: ");gets(extras);//Especialidad del doctor
fprintf(Archivo,"\nEspecialidad: %s",extras);
printf("\n");
char descripcion[100];//Cadena para guardar una descripcion de la cita
printf("\nDescripcion: ");fflush(stdin);
gets(descripcion);//capturamos descripcion
fprintf(Archivo,"\nDescripcion: %s",descripcion);//guardamos en el archivo
fclose(Archivo);//cerramos el archivo
system("Pause");
} 
}
int submenu(){//SubMenu el cual retornara la opcion elegida por la persona.
int op=0;
system("cls");
printf("\t\t\t*****EXPEDIENTE *****\n\n");
printf("\t\t1)Crear Archivo Del Paciente\n");
printf("\t\t2)Ingresar Datos Nuevo Del Paciente\n");
printf("\t\t3)Mostrar Expediente del Paciente\n");
printf("\t\t4)Buscar Expediente \n");
printf("\t\t5)Calculadora imc \n");
printf("\t\t6)Salir\n");
  
scanf("%i",&op);//Leemos la opcion elegida
return op;//Devolvemos la opcion elegida
}


void imc ()
{
    float IMC, altura_en_m, peso_en_kg;
    cout << "Ingresa el valor de altura en m: ";
    cin >> altura_en_m;
    cin.get();
    cout << "Ingresa el valor de peso en kg: ";
    cin >> peso_en_kg;
    cin.get();
    IMC=peso_en_kg/altura_en_m/altura_en_m;
    if(IMC<16)
        cout << "Criterio de ingreso en hospital." << endl;
    if(IMC>=16&&IMC<17)
        cout << "Infrapeso." << endl;
    if(IMC>=17&&IMC<18)
        cout << "Bajo peso." << endl;
    if(IMC>=18&&IMC<25)
        cout << "Peso normal (saludable)." << endl;
    if(IMC>=5&&IMC<30)
        cout << "Sobrepeso (obesidad de grado I)." << endl;
    if(IMC>=30&&IMC<35)
        cout << "Sobrepeso cr\242nico (obesidad de grado II)." << endl;
    if(IMC>=35&&IMC<40)
        cout << "Obesidad prem\242rbida (obesidad de grado III)." << endl;
    if(IMC>=40)
        cout << "Obesidad m\242rbida (obesidad de grado IV)." << endl;
    cout << "Valor de IMC: " << IMC << endl;
    cout << endl;
    system ("pause");
    
}

void Historial_Medico(){
while(1){//Bucle infinito para mantenernos en el menu
switch(submenu()){//Este switch estará definido por submenu()
case 1:
//Crear archivo para un nuevo paciente
CrearArchivoPaciente();
break;
case 2:
//Agregaremos los datos del nuevo pac //Agregaremos los datos del nuevo paciente
IngresarNuevoPaciente();
break;
case 3:
//En esta sección podremos ver el historial de un paciente
MostrarHistorialDePaciente();
break;
case 4:
//Podremos editar el historial del paciente
BuscarHistorialPaciente();
break;
case 5:

imc();
break;
case 6://Si presiona la tecla 5 sale del bucle
return;
default:
 
system("PAUSE");
} } }
int main(){
Historial_Medico();
return 0;
}
