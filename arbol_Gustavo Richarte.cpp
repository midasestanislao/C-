//Gustavo Richarte Pérez
//Ingenieria en Computacion Inteligente 2 - A
#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<windows.h>

using namespace std;

struct Nodo{
    int valor;
    Nodo *der;
    Nodo *izq;
};

//Prototipos
void menu();
Nodo *crearNodo(int);
void insertarNodo(Nodo *&,int);
void mostrarArbol(Nodo *,int);
bool busqueda(Nodo *,int);
void preOrden(Nodo *);
void InOrden(Nodo *);
void PostOrden(Nodo *);

Nodo *arbol = NULL;

int main(){
for(int i=0; i<10;i++){ 
    cout<<"\t\tCargando el programa porfavor espere .....";
    Sleep(200);
    system("cls");
    cout<<"\t\tCargando el programa porfavor espere *....";
    Sleep(200);
    system("cls");
    cout<<"\t\tCargando el programa porfavor espere .*..." ;
    Sleep(200);
    system("cls");
    cout<<"\t\tCargando el programa porfavor espere ..*.." ;
    Sleep(200);
    system("cls");
    cout<<"\t\tCargando el programa porfavor espere ...*." ;
    Sleep(200);
    system("cls");
    cout<<"\t\tCargando el programa porfavor espere ....*" ;
    Sleep(200);
    system("cls");
}
    menu();

    getch();
    return 0;
}

Nodo *crearNodo(int n){
    Nodo *nuevo_nodo = new Nodo();

    nuevo_nodo->valor = n;
    nuevo_nodo->der = NULL;
    nuevo_nodo->izq = NULL;

    return nuevo_nodo;
}

//Función para insertar elementos en el arbol
void insertarNodo(Nodo *&arbol,int n){
    if (arbol==NULL){ //Si el arbol esta vacio
        Nodo *nuevo_nodo = crearNodo(n);
        arbol = nuevo_nodo;
    }
    else { //Si el arbol tiene un nodo o mas
        int valorRaiz = arbol->valor; //Obtenemos el valor de la raiz
        if(n < valorRaiz){ //Si el elemento es menor a la raiz va a la izquierda
           insertarNodo(arbol->izq,n); 
        }
        else{ //Si el elemento es mayor a la raiz, insertamos en der
            insertarNodo(arbol->der,n);
        }
    }   
}

void mostrarArbol(Nodo *arbol,int cont){
    if(arbol == NULL) return;
    else{
        mostrarArbol(arbol->der,cont+1); //Mostramos el arbol por la derecha
        for(int i=0;i<cont;i++){
            cout<<"  ";
        }
            cout<<arbol->valor<<endl;
            mostrarArbol(arbol->izq,cont+1); //Mostramos el arbol por la izquierda
    }
}

bool busqueda(Nodo *arbol,int n){
    if(arbol == NULL) return false;
    else if(arbol->valor==n) return true;
    else if(n < arbol->valor) return busqueda(arbol->izq,n); 
    //Si el elemento es menor a la raíz se busca por la rama izquierda 
    else if(n > arbol->valor) return busqueda(arbol->der,n);
     //Si el elemento es mayor a la raíz se busca por la rama derecha 
}

void preOrden(Nodo *arbol){ //Función para mostrar los datos en PreOrden
    if (arbol == NULL) return;
    else{
        cout<<arbol->valor<<" - ";
        preOrden(arbol->izq);
        preOrden(arbol->der);
    }
}

void InOrden(Nodo *arbol){ //Función para mostrar los datos en InOrden
    if (arbol == NULL) return;
    else
    {
        InOrden(arbol->izq);
        cout<<arbol->valor<<" - ";
        InOrden(arbol->der);
    }  
}


void PostOrden(Nodo *arbol){ //Función para mostrar los datos en PostOrden
    if (arbol == NULL) return;
    else {
        PostOrden(arbol->izq);
        PostOrden(arbol->der);
        cout<<arbol->valor<<" - ";
    }    
}

void menu(){
    int valor,opcion,contador=0;
    
    do {
       cout<<".:Bienvenido Usuario:.\n"<<endl;
       cout<<"1.- Insertar un nuevo valor"<<endl;
       cout<<"2.- Mostar arbol completo"<<endl;
       cout<<"3.- Buscar un nodo en el arbol"<<endl;
       cout<<"4.- Recorrer el arbol en PreOrden"<<endl;
       cout<<"5.- Recorrer el arbol en InOrden"<<endl;
       cout<<"6.- Recorrer el arbol en PostOrden"<<endl;
       cout<<"7.- Salir"<<endl;
       cout<<"Opcion: "; cin>>opcion;

       switch (opcion) {
            case 1:
                cout<<"\nDigite un numero: ";
                cin>>valor;
                insertarNodo(arbol,valor); //Insertamos un nuevo nodo
                cout<<"\n";
                system("pause");
                break;

            case 2:
                cout<<"\nMostrar el arbol completo:\n\n";
                mostrarArbol(arbol,contador);
                cout<<"\n";
                system("pause");
                break;

            case 3: cout<<"\nDigite el elemento a buscar: ";
                    cin>>valor;
                    if(busqueda(arbol,valor) == true){ //La función ha encontrado el elemento
                        cout<<"\nEl elemento "<<valor<<" a sido encontrado\n";
                    } else{ //No hay el elemento
                        cout<<"\nEl elemento no ha sido encontrado\n";
                    }
                    cout<<"\n";
                    system("pause");
                    break;
            
            case 4: cout<<"\nMostrar el arbol en PreOrden:\n";
                    preOrden(arbol);
                    cout<<"\n\n";
                    system("pause");
                    break;

            case 5: cout<<"\nMostrar el arbol en InOrden:\n";
                    InOrden(arbol);
                    cout<<"\n\n";
                    system("pause");
                    break;

            case 6: cout<<"\nMostrar el arbol en PostOrden:\n";
                    PostOrden(arbol);
                    cout<<"\n\n";
                    system("pause");
                    break;

            case 7: cout<<"\nSaliendo del programa"<<endl;
            for(int i=0; i<10;i++){ //La función sleep sirve para hacer 
                                    //una pausa por determinada cantidad de segundos
                cout<<"\t\tSaliendo el programa porfavor espere .....";
                Sleep(200);
                system("cls");
                cout<<"\t\tSaliendo el programa porfavor espere *....";
                Sleep(200);
                system("cls");
                cout<<"\t\tSaliendo el programa porfavor espere .*..." ;
                Sleep(200);
                system("cls");
                cout<<"\t\tSaliendo el programa porfavor espere ..*.." ;
                Sleep(200);
                system("cls");
                cout<<"\t\tSaliendo el programa porfavor espere ...*." ;
                Sleep(200);
                system("cls");
                cout<<"\t\tSaliendo el programa porfavor espere ....*" ;
                Sleep(200);
                system("cls");
            }

            default:
                cout<<"Esa opcion no existe";
                cout<<"\n";
                system("pause");
                break; 
       } 
        system("cls");
    } while (opcion!=7);
}

// 8 3 1 6 4 7 10 14 13