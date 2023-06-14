#include <iostream>
#define MAX 10

using namespace std;
int x=0;
int maxRect=0;
int mov[8][2];

void cargamov(){
    mov[0][0]=-1; mov[0][1]=0;
    mov[1][0]=-1; mov[1][1]=1;
    mov[2][0]=0; mov[2][1]=1;
    mov[3][0]=1; mov[3][1]=1;
    mov[4][0]=1; mov[4][1]=0;
    mov[5][0]=1; mov[5][1]=-1;
    mov[6][0]=0; mov[6][1]=-1;
    mov[7][0]=-1; mov[7][1]=-1;
}

void imprimeTablero(int tablero[][8]){
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++)
            cout<<tablero[i][j]<<" ";
        cout<<endl;
    }
}

int posible(int n, int m,int c, int mapa[][MAX],int x,int y,int i){
	int x1=x, y1=y;
	for(int j=1; j<c; j++){
		x1=x1+mov[i][0];
		y1=y1+mov[i][1];
		if(x1<0 || y1<0 || x1>=n || y1>=m) return 0;
		if(mapa[x1][y1]!=0) return 0;
	}
	return 1;
}

void rectangulos(int n,int m, int c,int mapa[][MAX], int x, int y, int cont){
    if(x<0 || y<0 || y>=m || x>=n){
    	if(cont>maxRect) maxRect=cont;
        return;
    }
    if(cont>maxRect) maxRect=cont;
    int x1, y1;
    mapa[x][y]=cont+1;//se pone el primero, se asume que esta en una posicion correcta
    for(int i=0;i<8;i++){//para cada movimiento, se valida
    	if(posible(n, m, c, mapa, x, y, i)){//si es posible poner un rectangulo en la direccion del movimiento
			x1=x;
			y1=y;
    		for(int j=1;j<c;j++){//ubica el rectangulo
    			x1=x1+mov[i][0];
				y1=y1+mov[i][1];
				mapa[x1][y1]=cont+1;
			}
			for(int j=0;j<8;j++){
				if(mapa[x1+mov[j][0]][y1+mov[j][1]]==0) rectangulos(n, m, c, mapa, x1+mov[j][0],y1+mov[j][1],cont+1);
			}
    		for(int j=1;j<c;j++){//borra el rectangulo
    			mapa[x1][y1]=0;
    			x1=x1-mov[i][0];
				y1=y1-mov[i][1];
			}
		}
	}
	mapa[x][y]=0;
}

int main()
{
    int n=4, m=4, c=2;
    int mapa[n][MAX];
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            mapa[i][j]=0;
    cargamov();
    rectangulos(n, m, c, mapa, 0, 0, 0);
    cout<<maxRect;
    
    return 0;
}
