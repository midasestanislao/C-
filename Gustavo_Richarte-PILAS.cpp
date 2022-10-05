#include<iostream>
#include<conio.h>
#include<stdlib.h>

using namespace std;

// Gustavo Richarte
//Ingenieria en Computacion Inteligente
//
// 19_Marzo-2022
// Objetivo: Realizar un programa que permita operar difentes procedimientos a partir de una pila.
// *Nota: Los lineamientos se encuentran en la entrega del trabajo 

struct Nodo{
	int dato;
	Nodo* siguiente;
};

//Prototipos de Funciones
void menu();
void agregarPila(Nodo *&,Nodo *&,int);
void sacarPila(Nodo *&,int &n);
void sacarPila_1(Nodo *&,int &n);
void mostrarPila(Nodo *);
void mostrarPila_1(Nodo *);
void verificarPila(Nodo *);
void verificarPila_1(Nodo *);
void buscarPila(Nodo *,int);
void regresarPila(Nodo *);

int main(){
	
	menu();

	getch();
	return 0;
}



void menu(){
	Nodo *pila = NULL;
	Nodo *pila2 = NULL;
	int opcion;
	int dato;
    bool rpt = false;
    bool laos = false;

	do{
		cout<<"\t----MENU----\n";
		cout<<"1. Insertar un elemento a la pila - Push"<<endl;
		cout<<"2. Sacar - Pop"<<endl;
		cout<<"3.- Mostrar los Elementos de la Pila"<<endl;
		cout<<"4.- Crear una Pila -vacia"<<endl;
		cout<<"5.- Verificar si la pila esta vacia"<<endl;
		cout<<"6.- Obtener un elemento de la pila"<<endl;
		cout<<"7.- Regresar el tamanio o el numero de elementos que contiene la pila"<<endl;
		cout<<"8.- Salir"<<endl;
		cout<<"Opcion: ";
		cin>>opcion;

		switch (opcion)
		{
		case 1: cout<<"\nDigite un elemento: ";
				cin>>dato;
				agregarPila(pila,pila2,dato);
				cout<<"\n";
				system("pause");
			break;
		case 2: cout<<"\n---Sacando los elementos de la pila---\n"<<endl;	
                while (pila != NULL){
					sacarPila(pila,dato);
					if(pila != NULL){
						cout<<"El elemento "<<dato<<" ha sido extraido."<<endl;
					}
				}

				system("pause");
			break;
		case 3: cout<<"\n----Elementos de la pila----"<<endl;
			mostrarPila(pila);
			if(rpt == true){	
				mostrarPila_1(pila2);
			}
			rpt=false;
            cout<<"\n"<<endl;
			system("pause");
			break;
		case 4: cout<<"---Lista totalmente borrada---"<<endl;
                while (pila2 != NULL){
					sacarPila_1(pila2,dato);
					if(pila2 != NULL){
						cout<<"El elemento "<<dato<<" ha sido extraido."<<endl;
					}
				}
                cout<<"\n";
                system("pause");
			break;
		case 5: cout<<"\nVerificando....\n "<<endl;
				verificarPila(pila);
                if (laos == true){
                    verificarPila_1(pila2);
                }
                
				cout<<"\n";
				system("pause");
			break;
		case 6: cout<<"\nDigite el elemento obtener: ";
				cin>>dato;
				buscarPila(pila,dato);
				cout<<"\n";
				system("pause");
			break;
		case 7: cout<<"\nRestaurando valores ...."<<endl;
				regresarPila(pila2);
                rpt = true;
                laos = true;
				cout<<"\n"<<endl;
				system("pause");
			break;
		
		default:
			cout<<"Esa opcion no existe. JAJA"<<endl;
			cout<<"Escoja una nueva opcion"<<endl;
			cout<<"\nOpcion: "; cin>>opcion;
			cout<<"\n";
			system("pause");
			break;
		}
		system("cls"); //limpiar pantalla
	} while (opcion != 8);
}

void agregarPila(Nodo *&pila,Nodo *&pila2,int n){
	Nodo *nuevo_nodo = new Nodo(); //1. Crear el espacio en memoria para almacenar un número
	Nodo *actual = new Nodo();
	actual->dato = n;
	nuevo_nodo->dato = n; //2. Cargar el valor dentro del nodo(dato)
	nuevo_nodo->siguiente = pila; //3. Cargar el puntero pila dentro del nodo (*siguiente)
	actual->siguiente = pila2; //3. Cargar el puntero pila dentro del nodo (*siguiente)
	pila = nuevo_nodo; //4. Asignar el nuevo nodo a pila
	pila2 = actual;
	cout<<"\nElemento "<<n<<" agregado a PILA correctamente"<<endl;
}

void sacarPila(Nodo *&pila, int &n){
	Nodo *aux = pila; //1.- Crear una variable *aux de tipo Nodo
	n = aux->dato; //2.- Igualar el n a aux->dato
	pila = aux->siguiente; //3.- Pasar pila a siguiente nodo
	delete aux; //4.- Eliminar auxiliar
    
}

void sacarPila_1(Nodo *&pila2, int &n){
	Nodo *aux1 = pila2; //1.- Crear una variable *aux de tipo Nodo
	n = aux1->dato; //2.- Igualar el n a aux->dato
	pila2 = aux1->siguiente; //3.- Pasar pila a siguiente nodo
	delete aux1; //4.- Eliminar auxiliar
    
}

void verificarPila(Nodo *pila){
	Nodo *actual = new Nodo();
	actual = pila;

	if (actual != NULL){
		cout<<"La pila SI contiene elementos ."<<endl;
	} else {
		cout<<"La lista esta VACIA ."<<endl;
	}
}

void verificarPila_1(Nodo *pila2){
	Nodo *actual = new Nodo();
	actual = pila2;

	if (actual != NULL){
		cout<<"La pila SI contiene elementos ."<<endl;
	} 
    else if(actual ==NULL) {
		cout<<"La lista esta VACIA ."<<endl;
	}
}

void mostrarPila(Nodo *pila){
	Nodo *actual = new Nodo();
	actual = pila;

	while (actual != NULL){
		cout<<actual->dato<<" , ";
		actual = actual->siguiente;
	}
	
}

void mostrarPila_1(Nodo *pila2){
	Nodo *nuevo_nodo = new Nodo();
	nuevo_nodo = pila2;
	while (nuevo_nodo != NULL){
		cout<<nuevo_nodo->dato<<" , ";
		nuevo_nodo = nuevo_nodo->siguiente;
	}
}

void buscarPila(Nodo *pila,int n){
	bool band = false;

	Nodo *actual = new Nodo();
	actual = pila;

	while ((actual != NULL) && (actual->dato <= n)){
		if(actual->dato == n){
			band = true;
		}
		actual = actual->siguiente;
	}

	if(band == true){
		cout<<"Elemento "<<n<<" SI a sido encontrado en lista\n";
	}
	else {
		cout<<"Elemento "<<n<<" NO encontrado en la lista\n";
	}
}

void regresarPila(Nodo *pila2){
	Nodo *actual = new Nodo();
	actual = pila2;

	cout<<"\nValores iniciales restaurados"<<endl;
	while (actual != NULL){
		cout<<actual->dato<<" , ";
		actual = actual->siguiente;
	}	
}