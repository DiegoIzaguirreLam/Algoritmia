/*
4 5 20
2 5 6 10
7 8 15 3
11 9 6 4
*/
#include <iostream>
#include <math.h>
using namespace std;

void cargabin(int num,int n,int cromo[]){
	int i,res;
	for(i=0;i<n;i++)cromo[i]=0; 
	i=0;
	while(num>0){
		res = num%2;
		num = num/2;
		cromo[i]=res;
		i++;
	}
}


int main(){
	
	int N, M, C,parcial,mpeso=0,mcomb,pvalor, pbahia[3], cantPesos, logroLlenar=0;
	cin>>N>>M>>C;
	int n=3*N;
	int paq[n];
	int cromo[n];
	int opcion=(int)pow(2,n);
	
	for(int i=0;i<n;i++){
		cin>>paq[i];
	}
	for(int i=0;i<opcion;i++){
		cargabin(i,n,cromo);
		parcial=0;
		cantPesos=0;
		for(int j=0;j<n;j++){
			parcial+=cromo[j]*paq[j];
			cantPesos+=cromo[j];
		}
		if(parcial==C && cantPesos==M){
			for(int j=0;j<n;j++){
				if(j==0) cout<<"Bahia 1: ";
				if(j==N) cout<<"	Bahia 2: ";
				if(j==2*N) cout<<"	Bahia 3: ";
				if(cromo[j]==1) cout<<paq[j]<<", ";	
			}
                        logroLlenar=1;
			cout<<endl;
		}
	}
	if(logroLlenar==0)
            cout<<"No hay respuestas validas"<<endl;
	return 0;
}
