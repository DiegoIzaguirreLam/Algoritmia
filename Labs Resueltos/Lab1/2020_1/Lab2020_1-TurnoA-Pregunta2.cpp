#include <iostream>
#include <cmath>

using namespace std;



int main(){
	
	int nestaticas, npos;
	double r, distancia;
	
	cin>>nestaticas>>r;
	int arrEstEstado[nestaticas],arrEstX[nestaticas], arrEstY[nestaticas];
	for(int i=0;i<nestaticas;i++){
		cin>>arrEstEstado[i]>>arrEstX[i]>>arrEstY[i];
	}
	cin>>npos;
	int arrPosX[npos], arrPosY[npos];
	for(int i=0;i<npos;i++){
		cin>>arrPosX[i]>>arrPosY[i];
	}
	
	for(int i=0;i<npos;i++){
		for(int j=0;j<nestaticas;j++){
			distancia=sqrt(pow(arrPosX[i]-arrEstX[j], 2) + pow(arrPosY[i]-arrEstY[j],2));
			if (distancia<=r && arrEstEstado[j])
				cout<<"Persona podria haberse contagiado en su movimiento "<<i+1<<" por la persona "<<j+1<<" con nivel de cercania "<<distancia<<endl;
		}
	}
	
	return 0;
}
