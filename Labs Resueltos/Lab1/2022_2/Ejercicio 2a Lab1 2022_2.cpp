#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

void cargabin(int num, int n, int cromo[], int *nUnos){
	int i, res;
	for(int i=0;i<n;i++)cromo[i]=0;
	i=0;
	while(num>0){
		res = num%2;
		num = num/2;
		cromo[i]=res;
		i++;
		if(res==1) (*nUnos)++;
	}
}



int main(){
	int opcion, npalabra, nletras=10, pletras, j, k, s;
	char paq[nletras];
	int cromo[nletras];
	cout<<"Ingrese el numero de letras de la palabra: ";
	cin>>npalabra;
	
	char pparcial[npalabra], palabra[npalabra];
	cout<<"Ingrese la palabra letra por letra: ";
	for(int i=0;i<npalabra;i++) cin>>palabra[i];
	cout<<"Ingrese las letras del paquete: ";
	for(int i=0;i<nletras;i++) cin>>paq[i];
	//hallamos el numero total de posibilidades
	opcion=pow(2,nletras);
	for(int i=0;i<opcion;i++){
		pletras=0; // se vuelve a inicializar en 0 para cada iteracion dado que contara el numero de letras para la actual combinacion
		cargabin(i, nletras, cromo, &pletras); //
		if(pletras!=npalabra) continue; // si el numero de letras de la combinacion es diferente al numero de letras de la palabra, entonces se descarta
		for(int l=0;l<npalabra;l++) pparcial[l]=' '; //se limpia la variable que se utilizara para formar la palabra con la combinacion actual.
		s=0; //variable que se utilizara como indice para el arreglo que representa la palabra formada (pparcial)
		for(k=0;k<npalabra;k++){ //primero se recorre por cada palabra de la palabra ingresada.
			for(j=0;j<nletras;j++){ //se prueba para cada palabra si se encuentra en alguna posicion del arreglo con la combinacion (es decir, si cromo[j] es 1).
				if(paq[j]==palabra[k] && cromo[j]==1){ // para cada palabra que se encuentre, se registra el la variable pparcial, que representa la palabra formada en la combinacion.
					pparcial[s]=palabra[k];
					s++;
				}
			}
		}
		if(!strcmp(pparcial, palabra)){ //si al finalizar la palabra formada es igual a la palabra objetivo, entonces se imprime la combinacion.
			cout<<"Palabra encontrada en: ";
			for(int l=0;l<nletras;l++)
				if(cromo[l]==1) cout<<l+1<<" ";
			cout<<endl;
		}
	}
	return 0;
}


