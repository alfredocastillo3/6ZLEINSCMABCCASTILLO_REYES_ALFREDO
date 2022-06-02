#include<iostream>

using namespace std;

//definir la estructura de la lista 

struct nodo{
	
	//los datos de la lista 
	int valor;
	nodo*siguiente;
	
};

//metodo para insertar 
void insertarlista(nodo*&,int);


int main{
	//declarar variable de la lista 
	nodo *lista = NULL;
	
	//variable
	int op = 1,c,i =0, valores;
	
	cout<<"trabajando con listas (simples,doblemente enlazadas, circulares ,circulares dobles)"
	while(op!=3){
		cout<<"ejemplo de listas simples"<<endl;
		cout<<"1.-insertar nuevo valor en la lista"<<endl;
		cout<<"2.-ver lista"<<endl;
		cout<<"3.- salir"<<endl;
		cin>>op;
		
		switch(op){
			case1:
				cout<<"indica el numero de valores a introducir\n";
				cin>>valores;
				while(i<valores){
					cout<<"valor["<<i<<"]\n";
					cin>>c;
					insertarlista(lista, c);
					i++;
					
				}
				break
			case 2:
				cout<<"ver elementos de la lista";
				cout<<"pendiente ";
				break;
				default;
				cour<<"gracias por estar aqui uwu";
				
		}
	}
	return=0;
	
	void insertarLista(Nodo *&lista,int c){
		
		Nodo *inslista = new Nodo();
		inslista->valor = c;
		
		//necesito un auxiliar para cadenar  los valores de lista
		Nodo *aux = lista;
		Nodo *aux2;
		
		
		//se meten para encadenarlo
		while((aux!=NULL)&&(aux->valor<c)){
			aux2=aux;
			aux = aux->siguiente;
		}
		lista->siguiente = NULL;
		
		if(insLista == aux){
			lista = inslista;
			
		}else{
			aux2-> siguiente=aux;
			cout<<"elemnto:"<<c<<"insetar"<<endl
		}
		
		
	void mostrarlista(Nodo *lista){
		Nodo * recursos = new Nodo();
		recurso = lista;
		
		while(recurso!=NULL){
			cout<<recurso->valor<<endl;
			recurso=recurso->siguiente;
			
		}
	}	

	}
	


}
//imprimir lista y borrar un elemento de la lista que sea el ultumo

