#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;

class Nodo{
private:
    int dato;
    Nodo *Der;
    Nodo *Izq;
    Nodo *Padre;
public:
    Nodo(int d,Nodo *p){
    	dato=d;
    	Der=Izq=NULL;
    	Padre=p;
    }
    Nodo(){
    	Der=Izq=NULL;
	}
    void AsignarDato(int d){
        dato=d;
    }
    int RetornarDato(){
        return dato;
    }
    Nodo *RetornarDer(){
        return Der;
    }
    Nodo *RetornarIzq(){
        return Izq;
    }
    Nodo *RetornarPadre(){
        return Padre;
    }
    void AsigDer(Nodo *a){
    	Der=a;
	}
	void AsigIzq(Nodo *a){
		Izq=a;
	}
	void AsignarPadre(Nodo *p){
        Padre=p;
    }
};

class Arbol{
	private:
		Nodo *Raiz;
	public:
		Arbol(){
			Raiz=NULL;
		}
		void Insertar3(int d){
			InsertarNodo(Raiz,d,NULL);
		}
		void InsertarNodo(Nodo *a,int d,Nodo *p){
			Nodo *ar=new Nodo(d,p);
			if(a==NULL){
				a=ar;
			}else{
				if(d<a->RetornarDato()){
                    if(a->RetornarIzq()==NULL){
                        a->AsigIzq(a);
                    }else{
                        InsertarNodo(a->RetornarIzq(),d,a);
                    }
				}else if(d>a->RetornarDato()){
				    if(a->RetornarDer()==NULL){
                        a->AsigDer(a);
                    }else{
                        InsertarNodo(a->RetornarDer(),d,a);
                	}
				}
			}
		}
		void M(){
	        preOrdenRec(Raiz);
	    }
	    void preOrdenRec(Nodo *n){
	        cout<<n->RetornarDato()<<"\t";
	        if(n->RetornarIzq()!=NULL){
	            preOrdenRec(n->RetornarIzq());
	            preOrdenRec(n->RetornarDer());
	        }
	    }
	    void Mostrar(){
	    	Mostrara(Raiz);
		}
		void Mostrara(Nodo *r){
			cout<<r->RetornarPadre()->RetornarDato()<<"\t";
			if(r->RetornarDato()){
				Mostrara(r->RetornarIzq());
				Mostrara (r->RetornarDer());
			}
		}
	/***)************ELIMIMAR*******************/ 
	void Eliminacion(int d){
		Eliminar(Raiz,d);
	}
	void Eliminar(Nodo *a,int d){
		if(a==NULL){
			return;
		}else if(d<a->RetornarDato()){
			Eliminar(a->RetornarIzq(),d);
		}else if(d>a->RetornarDato()){
			Eliminar(a->RetornarDer(),d);
		}else{
			Eliminando(a);
		}
	}
	Nodo *Minimo(Nodo *a){
		if(a==NULL){
			return NULL;
		}
		if(a->RetornarIzq()){
			return Minimo(a->RetornarIzq());
		}else{
			return a;
		}
	}
	void Eliminando(Nodo *e){
		if(e->RetornarIzq() && e->RetornarDer()){
			Nodo *menor=Minimo(e->RetornarDer());
			e->RetornarDato()==menor->RetornarDato();
			Eliminando(menor);
		}else if(e->RetornarIzq()){
			Reemplazar(e,e->RetornarIzq());
			Destruir(e);
		}else if(e->RetornarDer()){
			Reemplazar(e,e->RetornarDer());
			Destruir(e);
		}else{
			Reemplazar(e,NULL);
			Destruir(e);
		}
	}
	void Reemplazar(Nodo *a,Nodo *b){
		if(a->RetornarPadre()){
			if(a->RetornarDato()==a->RetornarPadre()->RetornarIzq()->RetornarDato()){
				a->RetornarPadre()->RetornarIzq()==b;
			}else if(a->RetornarDato()==a->RetornarPadre()->RetornarDer()->RetornarDato()){
				a->RetornarPadre()->RetornarDer()==b;
			}
		}
		if(b){
			b->RetornarPadre()==a->RetornarPadre();
		}
	}
	void Destruir(Nodo *d){
		d->RetornarDer()==NULL;
		d->RetornarIzq()==NULL;
		delete d;
	}
};
int main(){
	Arbol *A=new Arbol();
	A->Insertar3(50);
	/*A->Insertar3(10);
	A->Insertar3(30);
	A->Insertar3(40);
	A->Insertar3(25);
	A->Insertar3(20);
	A->Insertar3(1);*/
	//A->M();
	return 0;
}




/***************************************/
/*void InsertarNodo(Nodo *a,int d,Nodo *p){
			Nodo *ar=new Nodo(d,p);
			if(Raiz==NULL){
				Raiz=ar;
			}else{
				int valor=Raiz->RetornarDato();
				if(d<valor){
                    if(Raiz->RetornarIzq()==NULL){
                        Raiz->AsigIzq(a);
                    }else{
                        InsertarNodo(Raiz->RetornarIzq(),d,a);
                    }
				}else if(d>valor){
				    if(Raiz->RetornarDer()==NULL){
                        Raiz->AsigDer(a);
                    }else{
                        InsertarNodo(Raiz->RetornarDer(),d,a);
                	}
				}
			}
		}*/
