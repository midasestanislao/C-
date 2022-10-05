//Declarar un arreglo de 10 posiciones 
//1 1 1 45 45 70 70 82 82 70

#include<iostream>
#include<conio.h>
using namespace std;

int main() {
	setlocale(LC_ALL," ");
	int numeros[] = {7,4,2,87,45,70,13,90,82,78};
	int i,j,aux,min;

    //Algoritmo del Ordenamiento por Selección 
	for(int i=0;i<10;i++){
        min=i;
        for (int j=i+1; j < 10; j++){
            if(numeros[j] < numeros[min]){
              min = j;  
            }
        }
        aux = numeros[i];
        numeros[i] = numeros[min];
        numeros[min] = aux;
	}

    cout<<"Orden Ascendente: ";
    for (int i = 0; i < 10; i++){
        cout<<numeros[i]<<" ";
    }

    cout<<"\nOrden Descendente: ";
    for (int i = 9; i >= 0; i--){
        cout<<numeros[i]<<" ";
    }
    
    getch();
    return 0;
}