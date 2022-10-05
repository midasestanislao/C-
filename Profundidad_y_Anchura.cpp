#include<bits/stdc++.h>
#include<conio.h>
using namespace std;

queue<int> cola;

void imprimir();
void agregar(int, int);

int matriz[20][20],nodos;
int cola[20];

int main(){
    int  i,j;
    cout<<"Dame la cantidad de nodos: "; cin>>nodos;
    int matriz[20][20];
    for(i=0; i<nodos; i++){
        for(j=0; j<nodos; j++){
            matriz[i][j]=0;
        }
    }

    imprimir();

    
    getch();
    return 0;
}

void agregarvecino(int nodo1,int nodo2){
    int contador=0;
    matriz[nodo1-1][nodo2-1] = 1;
    //matriz[nodo2-1][nodo1-1] = 1;


    /*for (int i = 0; i < nodos; i++){
        for (int j = 0; j < nodos; j++){
                
        }   
    }*/
    
    
}

void imprimir(){
    int nodo1,nodo2,opc;
    do{
        cout<<"\nDigite el nodo a conectar: ";
        cin>>nodo1;
        cout<<"Digite el nodo con el que conecta: ";
        cin>>nodo2;

        cout<<"Quieres agregar otra conexion: "; cin>>opc;
        
        agregarvecino(nodo1,nodo2);
    }while(opc!=2);

    cout<<"----------------Impresion de matriz----------------\n\n";
    for(int i=0; i<nodos; i++){
        cout<<"\t";
        for(int j=0; j<nodos; j++){
            cout<<matriz[i][j]<<" ";
        }
        cout<<endl;
    }
}