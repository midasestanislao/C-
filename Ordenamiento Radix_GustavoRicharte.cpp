#include<iostream>
#include<cmath>
#include<vector>
#include<locale.h>

using namespace std;

void Radix(int [], int);
void imprimir(int [], int);

vector<vector<int>> Vec;

int main(){
    setlocale( LC_ALL, "spanish");
    int NumerodeElementos;
    cout<<"\tDigite el numeros de elementos: ";
    cin>>NumerodeElementos;
    int Numeros[NumerodeElementos];
    for (int i = 0; i < NumerodeElementos; i++){
        cout<<"Digite el numero de la posicion ["<<i+1<<"]: ";
        cin>>Numeros[i];
    }
    Radix(Numeros,NumerodeElementos);
    
}

void Radix(int a[],int n){
    Vec.resize(10);
    int temp, m=0;

    for (int i = 0; i < 7; i++){
        for(int j=0;j<n;j++){
            temp = (int) (a[j]/pow(10,i))%10;
            Vec[temp].push_back(a[j]);
        }

        for (int k = 0; k<10; k++){
            for (int l=0; l<Vec[k].size(); l++){
                a[m]=Vec[k][l];
                m++;
            }
            Vec[k].clear();
        }
        m=0;
    }
    imprimir(a,n);
}

void imprimir(int a[], int tam){
    cout<<"\t\tArreglo de Numeros Ordenados.\n\n";
    for (int i = 0; i < tam; i++){
        cout<<"\t["<<a[i]<<"] ";
    }
    
}