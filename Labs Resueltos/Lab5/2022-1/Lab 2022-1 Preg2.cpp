
#define MAX 10
#include <iostream>

using namespace std;

int mov[8][2];
int nSolus;

void cargamov(){
	mov[0][0]=1; mov[0][1]=0;
	mov[1][0]=1; mov[1][1]=1;
	mov[2][0]=0; mov[2][1]=1;
	mov[3][0]=-1; mov[3][1]=1;
	mov[4][0]=-1; mov[4][1]=0;
	mov[5][0]=-1; mov[5][1]=-1;
	mov[6][0]=0; mov[6][1]=-1;
	mov[7][0]=1; mov[7][1]=-1;
}

void imprime_mapa(char arr[][MAX], int n, int m){
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
}


int encuentraRuta(char mapa[][MAX], char solucion[][MAX], int n, int m, int x, int y, char car){
	if(x<0 || x>=n || y<0 || y>=m) return 0;
	if(x==n-1 && y==m-1){
		if(nSolus<20){//se imprimen las 20 primeras soluciones
			solucion[x][y]=car;
			cout<<"Solucion "<<nSolus+1<<": "<<endl;
			imprime_mapa(solucion, n, m);
			nSolus++;
			solucion[x][y]=' ';
			cout<<endl;
			return 0;//para que busque otra solu
		}
		else return 1; // para que deje de buscar solus
	}
	solucion[x][y]=car;//lo pongo asumiendo que la posicion es correcta
	for(int i=0;i<8;i++){//reviso los alrededores para poner minas
		if(mapa[x+mov[i][0]][y+mov[i][1]]=='*') solucion[x+mov[i][0]][y+mov[i][1]]='*';
	}
	for(int i=0;i<8;i++){//para cada movimiento, pruebo si me puedo mover en esa direccion
		if(solucion[x+mov[i][0]][y+mov[i][1]]==' '){//solo en caso sea una posicion valida, aplico la recursion para esta posicion
			if(encuentraRuta(mapa, solucion, n, m, x+mov[i][0], y+mov[i][1], car+1))
				return 1;
		}
	}
	solucion[x][y]=' ';
	return 0;
}


int main(){
	int n=9, m=5;
	char mapa[][MAX]={{' ',' ',' ',' ','*'}, {' ',' ',' ',' ',' '},
	{' ',' ','*',' ',' '}, {' ',' ',' ',' ',' '}, {' ','*','*',' ','*'},
	{' ','*','*',' ','*'}, {' ','*',' ','*',' '}, {'*','*','*','*',' '}, {' ',' ',' ',' ',' '}};
	
	char solucion[n][MAX];
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++) solucion[i][j]=' ';
	
	cargamov();
	imprime_mapa(solucion, n, m);
	nSolus=0;
	encuentraRuta(mapa, solucion, n, m, 0, 0, 'A');
	if(nSolus==0){
		cout<<"No se encontraron rutas posibles"<<endl;
	}
	
	return 0;
}
