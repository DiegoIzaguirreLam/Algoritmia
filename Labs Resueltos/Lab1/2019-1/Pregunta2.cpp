
#include <stdio.h>
#include <cstdlib>
#include <string.h>
#include <math.h>
#include <iostream>

using namespace std;

int m[4][2], t;

void movimientos(){
	m[0][0]=-1; m[0][1]=0;
	m[1][0]=0; m[1][1]=1;
	m[2][0]=1; m[2][1]=0;
	m[3][0]=0; m[3][1]=-1;
}
void PopulateGameBoard(int t, char tablero[][5]){
	
	//srand(time(null));
	
	for(int i=0;i<t;i++){
		for(int j=0;j<t;j++){
			tablero[i][j] = rand() % (90 + 1 - 65) + 65;
		}
	}
}

void ShowGameBoard(int t, char tablero[][5]){
	for(int i=0;i<t;i++){
		for(int j=0;j<t;j++){
			cout<<" "<<tablero[i][j]<<" ";
		}
		cout<<endl;
	}
}

int busca(char word[], int t, char tablero[][5], char res[3],int row,int col, int nletras){
	if(tablero[row][col]!=word[0]){
		for(int i=0;i<3;i++) res[i]=-1;
		return 0;
	}
	int j=1, s=0, nrow, ncol;
	for(int i=0;i<4;i++){
		nrow=row+m[i][0];
		ncol=col+m[i][1];
		for(j=1;j<nletras;j++){
			if(nrow<0 || ncol<0 || nrow>=t || ncol>=t) break;
			if(tablero[nrow][ncol]!=word[j]){
				j--;
				break;
			}
			nrow=nrow+m[i][0];
			ncol=ncol+m[i][1];
		}
		if(nletras==j){
			res[0]=(char)(row+'0'); res[1]=(char)(col+'0');
			if(i==0) res[2]='U';
			if(i==1) res[2]='R';
			if(i==2) res[2]='D';
			if(i==3) res[2]='L';
			return 1;
		}
	}
}

int SearchWord(char word[], int t, char tablero[][5], char res[]){
	int nletras;
	for(nletras=0;word[nletras];nletras++);
	for(int i=0;i<t;i++){
		for(int j=0;j<t;j++){
			if(busca(word, t, tablero, res, i, j, nletras)) return 1;
		}
	}
        return 0;
}


int main(){
    movimientos();
	int npalabras;
	char palabra[10], res[3];
	cout<<"Ingrese el tamanio de la cuadricula: "<<endl;
	cin>>t;
	char tablero[5][5];
	PopulateGameBoard(t, tablero);
	cout<<"Bienvenido al juego de sopa de letras"<<endl;
	ShowGameBoard(t, tablero);
	cout<<"Ingrese la cantidad de palabras a buscar: "<<endl;
	cin>>npalabras;
	for(int i=0; i<npalabras;i++){
		cout<<"Palabra "<<i+1<<": ";
		cin>>palabra;
		SearchWord(palabra,t,tablero,res);
		if(res[0]==-1)
			cout<<"Palabra "<<i+1<<" - "<<palabra<<" no encontrada";
		else{
			cout<<"Palabra "<<i+1<<" - "<<palabra<<"encontrada en ("<<res[0]<<","<<res[1]<<") -";
			if(res[2]=='U') cout<<"arriba";
			if(res[2]=='R') cout<<"derecha";
			if(res[2]=='D') cout<<"abajo";
			if(res[2]=='L') cout<<"izquierda";
		}
		cout<<endl;
	}
	return 0;
}
