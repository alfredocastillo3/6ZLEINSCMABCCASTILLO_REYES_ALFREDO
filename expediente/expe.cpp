#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

using namespace std;


typedef struct Paciente{ 
char Nombre[50];
char DNI[9];

char Fecha[11];//Fecha en formato aaaa/mm/dd un espacio para el caracter '\0'
char alergico_a[50];//Cadena para guardar los medicamentos si es alergico a alguno
char tiene_seguro;//caracer S o N , S=asegurado y N= No asegurad
char sexo;
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

printf("\n\t\t*Alergico a: (ninguno = N): ");fflush(stdin);
gets(Nuevo.alergico_a);

printf("\n\t\t*Sexo: (M/F): ");fflush(stdin);
scanf("%a");

printf("\n\t\t*Tiene seguro? (s/n): ");fflush(stdin);
scanf("%c",&Nuevo.tiene_seguro);

fprintf(ArchivoPaciente,"\nNo: %s ",Nuevo.DNI);
fprintf(ArchivoPaciente,"\nAlergico a: %s ",Nuevo.alergico_a);
fprintf(ArchivoPaciente,"\nSexo: %a");
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
fflush(stdin);
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
fflush(stdin);
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


char c[30];
fflush(stdin);
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
fprintf(Archivo,"\nDescripcion: %s",descripcion);
fclose(Archivo);
system("Pause");
} 
}
int submenu(){
int op=0;
system("cls");
printf("\t\t\t*****EXPEDIENTE *****\n\n");
printf("\t\t1)Crear Archivo Del Paciente\n");
printf("\t\t2)Ingresar Datos Nuevo Del Paciente\n");
printf("\t\t3)Mostrar Expediente del Paciente\n");
printf("\t\t4)Buscar Expediente \n");
printf("\t\t5)Calculadora imc \n");
printf("\t\t6)Salir\n");
  
scanf("%i",&op);
return op;
}


void imc ()
{
   double altura, peso, IMC;

cout << "introduce tu altura (en metros): ";
 cin >> altura;

cout <<"Introduce tu peso (en kilogramos): ";
 cin >> peso;

IMC = peso/(altura*altura);

 cout << "Tu indice de masa corporal es: " << IMC << endl;

if (IMC<=16)
 cout << "IMC demasiado bajo: infrapeso.";

else if (16<IMC&&IMC<=18.5)
 cout << "IMC bajo: delgadez.";

else if (18.5<IMC&&IMC<=24.5)
 cout << "IMC normal: normopeso.";

else if (24.5<IMC&&IMC<30)
 cout << "IMC alto: sobrepeso.";

else if (30<=IMC)
 cout << "IMC muy alto: obesidad.";

cout << endl << endl;
    system ("pause");
    
}

void Historial_Medico(){
while(1){
switch(submenu()){//Este switch estará definido por submenu()
case 1:
//Crear archivo para un nuevo paciente
CrearArchivoPaciente();
break;
case 2:

IngresarNuevoPaciente();
break;
case 3:

MostrarHistorialDePaciente();
break;
case 4:

BuscarHistorialPaciente();
break;
case 5:

imc();
break;
case 6:
return;
default:
 
system("PAUSE");
} } }
int main(){
Historial_Medico();
return 0;
}
