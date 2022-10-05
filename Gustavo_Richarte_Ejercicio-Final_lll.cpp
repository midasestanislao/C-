/*Gustavo Richartre Perez
ID: 292791
Ingenieria en Computaciión Inteligente
Grado : 2°E*/

#include<iostream>
#include<conio.h>
#include<string.h>

using namespace std;

struct Nodo {
    int dato;
    Nodo *siguiente;
};

void agregarPila(Nodo *&,char);
void sacarPila(Nodo *&, char &);

int completo=0;

int main(){
    Nodo *pila = NULL;
    char dato;
    int opcion;
    //int completo;
    
    do{
        cout<<"\n\n\t.:MENU:.\n";
        cout<<"1.- Insertar un caracter a la pila"<<endl;
        cout<<"2.- mostar todos los elementos de la pila"<<endl;
        cout<<"3.- Salir"<<endl;
        cout<<"Opcion: "<<endl;
        cin>>opcion;

        switch(opcion){
            case 1: cout<<"\nDigite un caracter: ";
                    cin>>dato;
                    agregarPila(pila,dato);
                    break;
            case 2: cout<<"\nMostrando todos los elementos de la pila: ";
                    while (pila != NULL){
                        sacarPila(pila,dato);
                        if(pila != NULL){
                            cout<<dato<<" , ";
                        }
                        else{
                            cout<<dato<<".";
                        }
                    }
                    if(completo != 0){
                        cout<<"\n\nLa expresion es erronea"<<endl;
                    } else {
                        cout<<"\n\nLa expresion es correcta"<<endl;
                    }
                    break;
            case 3: cout<<"\nEl programa ha finalizado\n";
                    break;
                    
        }
    } while (opcion!=3);
    
    
    getch();
    return 0;
}

void agregarPila(Nodo *&pila,char n){
    Nodo *nuevo_nodo = new Nodo();
    nuevo_nodo->dato = n;
    nuevo_nodo->siguiente = pila;
    pila = nuevo_nodo;

    if(nuevo_nodo->dato =='('){
        completo ++;
    } else if(nuevo_nodo->dato == ')'){
        completo --;
    }
    cout<<"\tElemento "<<n<<" ha sido agregado a PILA correctamente";
}

void sacarPila(Nodo *&pila, char &n){
    Nodo *aux = pila;
    n = aux->dato;
    pila = aux->siguiente;
    delete aux;
}