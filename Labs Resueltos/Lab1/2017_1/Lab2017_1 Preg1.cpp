/*
Datos de entrada de prueba:
Ejemplo 1:
3
4 2
T 1 1
A 1 5
C 3 2

Ejemplo 2:
2
4 2
T 3 3
A 1 5
*/
#include <iostream>
#define MAX 100
using namespace std;
int m[8][2];// en el peor caso (caballo), hay 8 posibles movimientos

void movimientos(char tipo, int *nmov){
	if(tipo=='T'){
		m[0][0]=-1; m[0][1]=0;
		m[1][0]=0; m[1][1]=1;
		m[2][0]=1; m[2][1]=0;
		m[3][0]=0; m[3][1]=-1;
		(*nmov)=4;
	}
	if(tipo=='A'){
		m[0][0]=-1; m[0][1]=1;
		m[1][0]=1; m[1][1]=1;
		m[2][0]=1; m[2][1]=-1;
		m[3][0]=-1; m[3][1]=-1;
		(*nmov)=4;
	}
	if(tipo=='C'){
		m[0][0]=-2; m[0][1]=-1;
		m[1][0]=-2; m[1][1]=1;
		m[2][0]=-1; m[2][1]=2;
		m[3][0]=1; m[3][1]=2;
		m[4][0]=2; m[4][1]=1;
		m[5][0]=2; m[5][1]=-1;
		m[6][0]=1; m[6][1]=-2;
		m[7][0]=-1; m[7][1]=-2;
		(*nmov)=8;
	}
}




int main(){
	int n, xrey, yrey, nmov, x, y, jaque=0, obstaculo;
	
	char tipo[n];
	int xN[n], yN[n];
	cin>>n;
	cin>>xrey>>yrey;
	for(int i=0;i<n;i++){
		cin>>tipo[i]>>xN[i]>>yN[i];
	}
	for(int i=0;i<n;i++){
		movimientos(tipo[i], &nmov);
		if(tipo[i]=='C'){// es caballo
			for(int j=0;j<nmov;j++){
				x=xN[i]+m[j][0];
				y=yN[i]+m[j][1];
				if(x==xrey && y==yrey){
					jaque=1;
					break;
				}
			}
		}
		else{
			for(int j=0;j<nmov;j++){
				x=xN[i]+m[j][0];
				y=yN[i]+m[j][1];
				obstaculo=0;
				while(x<=MAX && y<=MAX && x>=0 && y>=0){
					for(int l=0;l<n;l++){
						if(xN[l]==x && yN[l]==y && i!=l){
							obstaculo=1;
							break;
						}
					}
					if(obstaculo) break;
					if(x==xrey && y==yrey){
						jaque=1;
						break;
					}
					x=x+m[j][0];
					y=y+m[j][1];
				}
				if(jaque) break;
			}
		}
		if(jaque){
			cout<<"SI"<<endl;
			break;
		}
	}
	if(!jaque)
		cout<<"NO"<<endl;
	return 0;
}
