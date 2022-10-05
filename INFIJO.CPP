//Gustavo Richarte Perez
//Ingenieria en Computacion Inteleligente

#include <iostream>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

#define tam 20
using namespace std;

int prioridad(char simbolo);

int main(){
    int opcion,tope=-1,pos=-1,tamexp;
    char pila[tam],epos[tam],epre[tam];
    char expinf[tam],simbolo;
    do
    {
        system("cls");
        cout<<"\n -------------------------------------------------";
        cout<<"\n                   Menu de Opciones";
        cout<<"\n 1.-->Convertir una Expresion de Infija a Postfija";
        cout<<"\n 2.-->Convertir una Expresion en Infija a Prefija";
        cout<<"\n 3.-->Salir del Menu";
        cout<<"\n --------------------------------------------------";
        cout<<"\n Ingrese su opcion: ";
        cin>>opcion;

        switch(opcion){
            case 1: system("cls");
                    cout<<"\n Ingrese la expresion en notacion Infija (sin espacios): ";
                    cin>>expinf;

                    tope=-1;
                    pos=-1;
                    tamexp=strlen(expinf);
                    for (int i = 0; i < tamexp; i++){
                        simbolo=expinf[i];
                        if(simbolo=='('){
                            tope=tope+1;
                            pila[tope]=simbolo;
                        }
                        else if(simbolo==')'){
                            while (pila[tope]!='('){
                                pos=pos+1;
                                epos[pos]=pila[tope];
                                tope=tope-1;
                            }
                            tope=tope-1;
                        }
                        else if((simbolo>='a')&&(simbolo<='z')||(simbolo>='A')&&(simbolo<='Z')){
                            pos=pos+1;
                            epos[pos]=simbolo;
                        }
                        else {
                            while(tope>-1 && (prioridad(simbolo)<=prioridad(pila[tope]))){
                                pos=pos+1;
                                epos[pos]=pila[tope];
                                tope=tope-1;
                            }
                            tope=tope+1;
                            pila[tope]=simbolo;
                        }
                    }

                    while (tope>-1){
                        pos=pos+1;
                        epos[pos]=pila[tope];
                        tope=tope-1;
                    }
                    cout<<"\nLa expresion en posfija es: ";
                    for (int i = 0; i <= pos; i++){
                        cout<<epos[i];
                    }
                    getch();

                break;
            
            case 2: system ("cls");
                    cout<<"\n Ingrese la expresion en notacion Infija (sin espacios): ";
                    cin>>expinf;

                    tope=-1;
                    pos=-1;
                    tamexp=strlen(expinf);
                    for (int i = tamexp-1; i>=0 ; i--){
                        simbolo=expinf[i];
                        if(simbolo==')'){
                            tope=tope+1;
                            pila[tope]=simbolo;
                        }
                        else if(simbolo=='('){
                            while (pila[tope]!=')'){
                                pos=pos+1;
                                epre[pos]=pila[tope];
                                tope=tope-1;
                            }
                            tope=tope-1;
                        }
                        else if((simbolo>='a')&&(simbolo<='z')||(simbolo>='A')&&(simbolo<='Z')){
                            pos=pos+1;
                            epre[pos]=simbolo;
                        }
                        else {
                            while(tope>-1 && (prioridad(simbolo)<prioridad(pila[tope]))){
                                pos=pos+1;
                                epre[pos]=pila[tope];
                                tope=tope-1;
                            }
                            tope=tope+1;
                            pila[tope]=simbolo;
                        }
                    }

                    while (tope>-1){
                        pos=pos+1;
                        epre[pos]=pila[tope];
                        tope=tope-1;
                    }
                    cout<<"\nLa expresion en prefija es: ";
                    for (int i = pos; i >= 0; i--){
                        cout<<epre[i];
                    }
                    getch();
                break;
            
            default: cout<<"\n Por favor seleccione una opcion valida...";
            getch();
            break;
        }
    } while (opcion!=3);
   getch(); 
}

int prioridad(char simbolo){
    int priori;
    switch (simbolo){
        case '^': priori = 3; break;
        case '/': priori = 2; break;
        case '*': priori = 2; break;
        case '-': priori = 1; break;
        case '+': priori = 1; break;
        case ')': priori = 0; break;
        case '(': priori = 0; break;
    }
    return priori;
}