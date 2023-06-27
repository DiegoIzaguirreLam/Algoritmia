#include <iostream>
#include <cmath>
#define N 10
#define M 10

int mov[8][2];
int cont=0;

using namespace std;

void generapos(){
	mov[0][0]=1; mov[0][1]=0;
	mov[1][0]=0; mov[1][1]=-1;
	mov[2][0]=0; mov[2][1]=1;
	mov[3][0]=-1; mov[3][1]=0;
	mov[4][0]=1; mov[4][1]=1;
	mov[5][0]=-1; mov[5][1]=-1;
	mov[6][0]=1; mov[6][1]=-1;
	mov[7][0]=-1; mov[7][1]=1;
}

int valida(char tabla[][M],int n,int m,int x1,int y1,char solu[][M]){
	
}

int solucion_robot(char tabla[][M], int n, int m, int x, int y, char solu[][M], char pasos){
	int x1, y1;
	if(cont==20) return 1;
	if(x==n-1 && y==m-1){
		cont++;
		return 0;
	}
	for(int i=0;i<8;i++){
		x1 = x + mov[i][0];
		y1 = y + mov[i][1];
		if(valida(tabla,n,m,x1,y1,solu)){
			solu[nx][ny] = pasos + 1;
			if(solucion_robot(tabla, n, m, x1, y1, solu, pasos+1)){
				return 1;
			}
			else{
				solu[x1][y1]='0';
			}
		}
	}
	return 0;
}

int main(){
	char tabla[N][M]={{' ',' ',' ',' ','*'}, {' ',' ',' ',' ',' '},
	{' ',' ','*',' ',' '}, {' ',' ',' ',' ',' '}, {' ','*','*',' ','*'},
	{' ','*','*',' ','*'}, {' ','*',' ','*',' '}, {'*','*','*','*',' '}, {' ',' ',' ',' ',' '}};
	char solu[N][M];
	int n=9, m=5;
	solu[0][0]='A';
	
	solucion_robot(tabla, n, m, 0, 0, solu, 'A');
	
	
	return 0;
}

