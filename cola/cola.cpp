#include<iostream>

using namespace std;


struct nodo{
	string color; 
	struct nodo *siguiente;
};


struct cola{
	nodo *ultimo;
	nodo *primero;
};


void encolar(struct cola &q, string c){

	struct nodo *aux = new(struct nodo);
	
	aux ->color = c;
	aux ->siguiente = NULL;
	
	if(q.ultimo == NULL){
		q.ultimo = aux;
	}else{
		(q.primero)->siguiente = aux;
	}
	
	q.primero = aux;
}


string desencolar(struct cola &q){
	string col;
	struct nodo *aux;
	

	aux = q.ultimo;
	col = aux->color;
	q.ultimo = (q.ultimo)->siguiente;
	
	
	delete(aux);
	
	return col;
}


void muestracola(struct cola q){

	struct nodo *aux;
	
	aux = q.ultimo;

	while(aux!=NULL){
		cout<<aux->color<<" --> ";
		aux = aux->siguiente;
	}
}


void vaciarcola(struct cola &q){
	
	struct nodo *aux;
	
	while(q.ultimo != NULL){
		aux = q.ultimo;
		q.ultimo = aux->siguiente;
		delete(aux);
	}
	q.ultimo = NULL;
	q.primero = NULL;
}

void menu(){
	cout<<"\n\t Cola de Colores\n";
	cout<<"\t 1. Encolar\n";
	cout<<"\t 2. Desencolar\n";
	cout<<"\t 3. Mostrar\n";
	cout<<"\t 4. Vaciar\n";
	cout<<"\t 5. Salir\n";
}

int main(){

	struct cola q;
	

	q.ultimo = NULL;
	q.primero = NULL;
	
	
	string dato;
	int op;
	string x; 
	
	do{
		menu();
		cout<<"\t"; cin>>op;
		
		switch(op){
			case 1:
				cout<<"\n\t Color a Encolar: ";
				cin>>dato;
				encolar(q,dato);
				cout<<"\n\t Color: "<<dato<<" encolado...\n";
			break;
			
			case 2:
				x = desencolar(q);
				cout<<"\n\t Color: "<<x<<" desencolado...\n";
			break;
			
			case 3:
				cout<<"\n\t Mostrar Cola: \n";
				
				if(q.ultimo != NULL) muestracola(q);
				else cout<<"\n\t Cola Vacia...\n";
			break;
			
			case 4:
				vaciarcola(q);
				cout<<"\n\t Colita se Vacio...\n";
			break;
			
		}
	}while(op != 5);
	
	return 0;
}
