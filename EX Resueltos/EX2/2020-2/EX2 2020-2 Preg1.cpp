

#include <iostream>

using namespace std;


void imprimeSolu(int ubicaciones[],int M){
	cout<<"{";
	for(int i=0;i<M;i++){
		cout<<ubicaciones[i];
		if(i!=M-1) cout<<", ";
		else cout<<"}";
	}
	cout<<endl;
}

int almacenaProductos(int productos[], int N,int ubicaciones[],int M, int indProd, int distribucion[]){
	if(indProd==N){
		imprimeSolu(distribucion, M);
		return 0;//se pudieron almacenar todos los productos
	}
	
	for(int i=0;i<M;i++){//probamos insertarlo en todas las posiciones
		if(ubicaciones[i]-distribucion[i] >= productos[indProd]){
			distribucion[i] += productos[indProd];
			if(almacenaProductos(productos, N, ubicaciones, M, indProd+1, distribucion))
				return 1;
			else{
				distribucion[i] -= productos[indProd];
			}
		}
	}
	return 0;
}

int main(){
	int productos[]={2,3,1,4};
	int N=4;
	int ubicaciones[]={3,2,5,1,3};
	int M=5;
	int distribucion[M]={};
	int solu[M]={};
	
	almacenaProductos(productos, N, ubicaciones, M, 0, distribucion);
	return 0;
}
