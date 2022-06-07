

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <iostream>

using namespace std;




struct dato{
    
    int i;
    dato *s; 
}*a, *i, *p, *e;


int da;



int buscar(int d);
void insertar(int dat);
void mostrar(void);
void borrar(void);
void menu(void);
void guardar(void);
void cargar(void);




main(){
    menu();
}



void menu(void){

    int opc, da;

    do{
       
        cout<<"1.- Buscar datos";
        cout<<"\t 2.- Insertar datos";
        cout<<"\t 3.- Mostrar datos";
        cout<<"\t 4.- Borrar un dato";
        cout<<"\t 5.- Guardar datos a un Archivo";
        cout<<"\t 6.- Cargar datos de un Archivo";
        cout<<"\t 0.- Salir";
        cout<<"\n Seleccione una opcion";
        cin>>opc;
        
        switch (opc)
        {
        case 0: 
            cout<<"\n\n Finalizar gracias Adios :3";
            getch();
           
            p=i;
            while(p){

                a=p;
                p=p->s;
                delete(a);
            }
            exit(0);
        case 1:
            cout<<"\n\n Ingresa el datos a buscar:";
            cin>>da;
            if(buscar(da))
                cout<<"Datos Existe wiiiii";
            else
                cout<<"Dato no existe solo juguito contigo T_T ";
            getch();
            break;
        case 2:
            cout<<"Ingresa el Dato:";
            cin>>da;
            insertar(da);
            break;
        case 3:
            mostrar();
            break;
        case 4:
            borrar();
            break;
        case 5:
            guardar();
            break;
        case 6:
            cargar();
            break;
        
        default:
            cout<<"Opcion no valida aprender a leer ¬¬";
            getch();
        }

    }while(opc);

}


//metodo mostrar

void mostrar(void){
    int cont = 1;
    if(!i){
        cout<<"No hay lista para mostrar";
        getch();
        return;
    }
    p=i;
    cout<<endl<<endl;
    while(p){

        cout<<cont++<<"\n Valor = "<<p->i<<endl;

    }
    cout<<"\n Fin de la lista";
    getch();
}

int buscar(int d){

    if(!i){
        cout<<"\n No hay datos en la lista";
        getch();
        return(0);
    }

    
    p=i;
    a = NULL;
    while(p->s && p->i<d){
        
        a=p;
        p=p->s;

    }
    return(p->i==d?1:0);

}

void insertar(int dat){

    if(!i){
    
        i = new(dato);
        i->s = NULL;
        i->i = dat;
        return; 
    }
    if(buscar(dat)){
      
        cout<<"\n El Dato Existe";
        getch();
        return;
    }
   
    e = new(dato);
    e->i=dat;
    if(p==i && p->s){
        if(p->i < e->i){
            p->s = e;
            e->s = NULL;
        }else{
            e->s = p;
            i=e;
        }
        return;
    }
    if(p->s){
        a->s = e;
        e->s = p;
        return;
    }
    if(e->i > p->i){
        e->s = NULL;
        p->s = e;
    }else{
        a->s = e;
        e->s = p;
    }
}

void borrar(void){
    cout<<"\n Ingresa el dato que deseas eliminar: ";  
    cin>>da;
    if(buscar(da)){

        if(a)
            a->s = p->s;   
        else
            i = p->s;    
        delete(p);
        cout<<"\n Dato eliminado";
    }else{
        cout<<"\n Dato no se encuentra T_T";
        getch();
    }
}
void guardar(void){

    
    FILE *arch;
    arch = fopen("Datos-a.txt", "w");
    if(!i){
        cout<<"\n No hay lista para guardar";
        getch();
        return;
    }
    p = i;
    while(p){
        fprintf(arch, "%i\n",p->i);
        p = p->s;

    }
    cout<<"\n Archivo guardado";
    fclose(arch);
    getch();
}


void cargar(void){

    int c, x;
    FILE *arch;
    arch = fopen("Datos-a.txt", "r");
    if(!arch){
        cout<<"\n No existe el archivo";
        getch();
        return;
    }
    do{
        c = fscanf(arch, "%i\n", &x);
        if(c!= EOF){
            insertar(x);
        }
    }while(c!=EOF);
    cout<<"\nArchivo cargado";
    fclose(arch);
    getch();
}
