//Alumno: Diego Izaguirre Lam. Codigo: 20210529
#include <iostream>
#define MAX 7
#define CAMINOINVALIDO 99999
using namespace std;

int movi[5][2];

void movimientos(){
	movi[0][0]=-1; movi[0][1]=-1;
	movi[1][0]=-1; movi[1][1]=0;
	movi[2][0]=-1; movi[2][1]=1;
	movi[3][0]=1; movi[3][1]=-1;
	movi[4][0]=0; movi[4][1]=-1;
}

int min(int num1, int num2){
	if(num1<num2) return num1;
	else return num2;
}

int robot(int n, int m, char campo[][MAX], int x, int y, int cont, char detecta[][MAX]){
	if(x>=n || y>=m) return CAMINOINVALIDO;
	if(x==n-1 && y==m-1) return cont;
	if(campo[x][y]=='*'){
		detecta[x][y]='*';
		return CAMINOINVALIDO;
	}
	else{
		for(int i=0;i<5;i++)
			detecta[x+movi[i][0]][y+movi[i][1]]=campo[x+movi[i][0]][y+movi[i][1]];
		cont++;
	}
	int der, abajo, diagonal;
	der=robot(n,m,campo,x,y+1,cont,detecta);
	abajo=robot(n,m,campo,x+1,y,cont,detecta);
	diagonal=robot(n,m,campo,x+1,y+1,cont,detecta);
	return min(min(der,abajo),diagonal);
}

int main(){
	int n=9, m=5;
	char campo[][MAX]={ {' ', ' ', ' ', ' ', '*'},
						{' ', ' ', ' ', ' ', ' '},
						{' ', ' ', '*', ' ', ' '},
						{' ', ' ', ' ', ' ', ' '},
						{' ', '*', '*', ' ', '*'},
						{' ', '*', '*', ' ', '*'},
						{'*', '*', ' ', '*', ' '},
						{'*', '*', '*', '*', ' '},
						{'*', ' ', ' ', ' ', ' '}};			
	char detecta[n][MAX];
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			detecta[i][j]=' ';
	movimientos();
	int pasos=robot(n, m, campo, 0, 0, 0, detecta);
	if(pasos != CAMINOINVALIDO){
		cout<<"El robot llega al punto final en "<<pasos<<" pasos"<<endl;
	}
	else{
		cout<<"No es posible llegar al punto final"<<endl;
	}
	cout<<"Mapa de minas detectadas: "<<endl;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++)
			cout<<detecta[i][j]<<" ";
		cout<<endl;
	}
	return 0;
}
