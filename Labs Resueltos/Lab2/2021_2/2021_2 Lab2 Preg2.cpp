
#include <iostream>
#define MAX 10

using namespace std;

int linea(int alma[][MAX], int n, int x, int y){
	int cont=0;
	if(y>=n-1) return cont; 
	cont+=alma[x][y];
	cont+=linea(alma, n, x, y+1);
	return cont;
}

int columna(int alma[][MAX], int n, int x, int y){
	int cont=0;
	if(x>=n) return cont;
	cont+=alma[x][y];
	cont+=columna(alma, n, x+1, y);
	return cont;
}

int peso(int alma[][MAX], int n, int m, int x){
	int cuenta;
	if(x>=m-1) return cuenta;
	cuenta=linea(alma, n, x, 0)+columna(alma,m,x,n-1);
	return max(cuenta, peso(alma, n-1, m, x+1));
}

void linea_pedido(int alma[][MAX], int n, int x, int y, int pesos[], int verifPesos[], int i){
	if(y>=n-1) return ; 
	if(alma[x][y]==pesos[i]) verifPesos[i]=1;
	linea_pedido(alma, n, x, y+1, pesos, verifPesos, i);
}

void columna_pedido(int alma[][MAX], int n, int x, int y, int pesos[], int verifPesos[], int i){
	if(x>=n) return ;
	if(alma[x][y]==pesos[i]) verifPesos[i]=1;
	columna_pedido(alma, n, x+1, y, pesos, verifPesos, i);
}


void pedido(int alma[][MAX], int n, int m, int x, int p, int pesos[]){
	int verifPesos[p]={}, k;
	if(x>=m-1){
		cout<<"El pedido no puede cumplirse";
		return;
	}
	for(int i=0;i<p;i++){
		linea_pedido(alma, n, x, 0, pesos, verifPesos, i);
		columna_pedido(alma, m, x, n-1, pesos, verifPesos, i);
	}
	k=0;
	for(k=0;k<p;k++){
		if(!(verifPesos[k]==1)){
			k--;
			break;
		}
	}
	if(k==p){
		cout<<"El pedido puede cumplirse"<<endl;
		return;
	}
	else
		pedido(alma, n-1, m, x+1, p, pesos);
	
}

int main(){
	int n=6;
	int alma[][MAX]={{1,2,9,1,2,3},
				     {5,1,7,0,2,1},
				     {0,7,0,3,8,1},
				     {1,2,6,1,2,2},
				     {0,6,9,5,0,5},
				     {0,0,4,0,9,0}};
	
	peso(alma, n, n, 0);
	int p;
	cout<<"Ingrese el numero de pesos del pedido: ";
	cin>>p;
	int pesos[p];
	cout<<"Ingrese los pesos del pedido: ";
	for(int i=0;i<p;i++)
		cin>>pesos[i];
	
	pedido(alma, n, n, 0, p, pesos);
	
	return 0;
}



