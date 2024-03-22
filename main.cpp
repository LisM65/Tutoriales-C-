#include <iostream>
#include <conio.h>
#include <stdlib.h>
using namespace std;

struct Nodo{
    int dato;
    Nodo *der;
    Nodo *izq;
};

/*********PROTOTIPOS*********/
void menu();
Nodo *crearNodo(int);
void insertarNodo(Nodo *&,int);
void mostrarArbol(Nodo *,int);
//bool busqueda(Nodo *, int);

Nodo *arbol = NULL;

int main(){
    menu();
    getch();
    return 0;
}

/*******FUNCION MENU**********/
void menu(){
    int dato,opcion,contador=0;

    do{
        cout<<"\t.:MENU:."<<endl;
        cout<<"1. INSERTAR UN NUEVO NODO"<<endl;
        cout<<"2. MOSTRAR ARBOL"<<endl;
        cout<<"3. BUSCAR UN ELEMENTO"<<endl;
        cout<<"4. SALIR"<<endl;
        cout<<"OPCION: "<<endl;
        cin>>opcion;

        switch(opcion){
            case 1:
                cout<<"\tDigite un numero: ";
                cin>>dato;
                insertarNodo(arbol,dato);
                cout<<"\n";
                system("pause");
                break;
            case 2:
               cout<<"\nMostrando el arbol completo:\n\n";
               mostrarArbol(arbol,contador);
               cout<<"\n";
               system("pause");
               break;
            /*case 3:
                cout<<"\nDigite el elemento a buscar: ";
                cin>>dato;
                if(busqueda(arbol,dato)==true){
                    cout<<"\nElemento "<<dato<<" a sido encontrado en el arbol\n";
                }else{
                    cout<<"\nElemento no encontrado";
                }
                cout<<"\n";
                system("pause");
                break;*/
        }
        system("cls");
    }while(opcion!=3);
}

/******CREAR NUEVO NODO*********/
Nodo *crearNodo(int n){
    Nodo *nuevo_nodo=new Nodo();

    nuevo_nodo->dato = n;
    nuevo_nodo->der = NULL;
    nuevo_nodo->izq = NULL;
    return nuevo_nodo;
}

/********INSERTAR NODO**********/
void insertarNodo(Nodo *&arbol,int n){
    if(arbol==NULL){
        Nodo *nuevo_nodo=crearNodo(n);
        arbol=nuevo_nodo;
    }else{
        int valorRaiz=arbol->dato;
        if(n<valorRaiz){
            insertarNodo(arbol->izq,n);
        }else{
            insertarNodo(arbol->der,n);
        }
    }
}

/*********MOSTRAR ARBOL**********/
void mostrarArbol(Nodo *arbol,int cont){
    if(arbol==NULL){
        return;
    }else{
        mostrarArbol(arbol->der,cont+1);
        for(int i=0;i<cont;i++){
            cout<<"   ";
        }
        cout<<arbol->dato<<endl;
        mostrarArbol(arbol->izq,cont+1);
    }
}

/************BUSCAR ELEMENTO**************/
/*bool busqueda(Nodo *arbol,int n){
    if(arbol==NULL){
        return false;
    }else if(arbol->dato==n){
        return true;
    }else if(n<arbol->dato){
        return busqueda(arbol->izq,n);
    }else{
        return busqueda(arbol->der,n);
    }
}*/
