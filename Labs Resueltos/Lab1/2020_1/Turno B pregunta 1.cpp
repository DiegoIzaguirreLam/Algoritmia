
#include <stdio.h>
#include <iostream>
#include <math.h>

using namespace std;


// primero se van a registrar los datos de entrada, se guardaran las posiciones de cada persona estatica en una matriz, donde se identificaran de la siguiente manera:
// posestaticos[numero de persona estatica][0 para posicion x o 1 para posicion y], similarmente se repetira con las posiciones de la persona en movimiento.
// luego para cada movimiento se calculara la distancia a cada persona estatica, y si es menor al radio y la persona estatica respectiva esta contagiada, se imprimira
// el mensaje de aviso
int main(){
	int nestaticos, nmovi, sospechoso=0, nmovcont;
	double distancia, radio;
	
	cin>>nestaticos>>radio;
	int posestaticos[nestaticos][2], estadoestaticos[nestaticos];
	for(int i=0;i<nestaticos;i++)
		cin>>estadoestaticos[i]>>posestaticos[i][0]>>posestaticos[i][1];
	cin>>nmovi;
	int movimientos[nmovi][2];
	for(int i=0;i<nmovi;i++)
		cin>>movimientos[i][0]>>movimientos[i][1];
	
	for(int i=0;i<nmovi;i++){
		for(int j=0;j<nestaticos;j++){
			distancia=sqrt(pow(posestaticos[j][0]-movimientos[i][0], 2)+pow(posestaticos[j][1]-movimientos[i][1], 2)); //se calcula la distancia
			if(distancia>radio) continue;
			if(!sospechoso){
				if(estadoestaticos[j])
					cout<<"Persona podria haberse contagiado en su movimiento "<<i+1<< " por la persona "<<j+1<<" con un nivel de cercania "<<(int)distancia<<endl;
					//sospechoso=1; //para que solo imprima el primero 
			}

		}
	}
	return 0;
}
