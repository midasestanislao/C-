/*Implementación de listas de tipo colas
Gustavo Richarte Pérez
Miguel Angel
Kandy Fabiola
16 de Abril del 2022*/

#include<iostream>
#include<stdlib.h>

using namespace std;

//Nodo
struct datos
{
    int valor;
    datos *dir_sig;
}*primero,*cola,*ultimo=NULL;

//Funciones de la cola
void push(); //insertamos datos
void pop(); //Eliminar datos
void show(); //mostrar datos

int main(){
    short op;
    while(true){
        cout<<"\t\tOPCIONES DE LISTAS TIPO COLA\n"<<endl;
        cout<<"1)Agregar dato\n2)Eliminar dato\n3)Eliminar todos los datos\n4)Mostrar cola\n5)Salir\n"<<endl;
        cout<<"Numero de opcion --> "; cin>>op;

        switch(op){
            case 1:
                push();
                break;
            
            case 2:
                pop();
                break;
            
            case 3:
                cout<<'\n';
                while (primero != NULL){
                    pop();
                }
                if(primero == NULL)
                    cout<<"\nTodos los elementos eliminados\n"<<endl;
                break;                

            case 4:
                show();
                break;

            case 5:
                exit(0);
                break;

            default:
                cout<<"HUMANO ELIGA UNA OPCION VALIDA\n"<<endl;
                break;
        }
    }
    return 0;
}
//Agregar datos
void push(){
    cola = new( datos ); //crear cola, reservar memoria
    cout<<"Digite un dato entero: ";
    cin>>cola->valor;
    if(ultimo!=NULL){
        ultimo->dir_sig=cola;
        cola->dir_sig=NULL;
        ultimo=cola;
        cout<<"Se ha insertado el dato correctamente"<<endl;
        getchar();
        getchar();
    } else {
        primero = ultimo = cola;
        cout<<"Primer dato insertado correctamente"<<endl;
        getchar();
        getchar();
    }
}
//Eliminar datos 
void pop(){
    if(primero != NULL){
        cola = primero;
        cout<<"Eliminando dato"<<endl;
        cout<<primero->valor<<endl;
        primero = cola->dir_sig;
        delete(cola);
        if(primero == NULL){
            cola = NULL;
            ultimo = NULL;
        }
    }else{
        cout<<"No hay datos para eliminar "
        <<" en la cola"<<endl;
        getchar();
        getchar();
    }
}

void show(){
    if(ultimo==NULL){
        cout<<"No hay datos a mostrar"<<endl;
        getchar();
        getchar();
        return ;
    }
    cola=primero;
    while (cola != NULL){
        cout<<cola->valor<<" , ";//mostrando datos
        cola = cola->dir_sig; //cambiando datos
    }
    getchar();
    getchar();
    cout<<'\n';
}