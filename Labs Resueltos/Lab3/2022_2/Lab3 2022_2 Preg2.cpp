
#include <iostream>
#define MAX 10

using namespace std;

int maxradiacion(int fila[], int ini, int fin, int &columMax, int &maxRad){
	int med=(ini+fin)/2;
	if((fila[med-1] == 0 && fila[med+1]==0) || ini>fin) return 0;
	if(ini==fin){
		if(fila[ini]>maxRad){
			columMax=ini;
			maxRad=fila[columMax];
			return maxRad;
		}
		else 
			return 0;
	}
	if(fila[med-1]>fila[med])
		maxradiacion(fila, ini, med-1, columMax, maxRad);
	else
		maxradiacion(fila, med+1, fin, columMax, maxRad);
}

int main(){
	int n=7, m=8;
	int mapa[][m]={	{0,0,0,0,0,0,0},
					{0,0,0,0,0,0,0},
					{0,0,0,0,0,0,0},
					{0,0,0,0,0,0,0},
					{0,1,1,1,0,0,0},
					{0,1,2,1,0,0,0},
					{0,1,1,1,0,0,0},
					{0,0,0,0,0,0,0}};
	int maxRad=0, columMax;
	for(int i=0;i<m;i++){
		maxradiacion(mapa[i], 0, n-1, columMax, maxRad);
	}
	cout<<"Mayor radiacion: "<<maxRad<<endl<<"Columna: "<<columMax<<endl;
	
	
	return 0;
}



/*
	int mapa[][m]={ {0,0,0,0,0,0,0},
					{0,0,0,0,0,0,0},
					{0,0,0,0,0,0,0},
					{0,0,0,0,0,0,0},
					{0,0,0,0,1,1,1},
					{0,0,0,0,1,2,2},
					{0,0,0,0,1,2,3},
					{0,0,0,0,1,2,2},
					{0,0,0,0,1,1,1},
					{0,0,0,0,0,0,0}};
*/
