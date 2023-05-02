#include <iostream>

using namespace std;

void merge(int A[], int inicial, int medio, int final){
	int longitud1, longitud2, i, p, q;
	
	longitud1=(medio+1)-inicial;//primera mitad del arreglo
	longitud2=final-medio;//segunda mitad del arreglo
	
	int P[longitud1+1];
	int Q[longitud2+1];
	
	//agrego los valores mayores de ambos arreglos
	P[longitud1]=999999;
	Q[longitud2]=999999;
	
	//copiamos los valores desde A hacia los arreglos auxiliares P y Q
	for (i=inicial;i<=medio;i++)
		P[i-inicial]=A[i];
	for (i=medio+1;i<=final;i++)
		Q[i-(medio+1)]=A[i];
	
	p=q=0;
	for (i=inicial;i<=final;i++)
		if (P[p]<Q[q])
			A[i]=P[p++];
		else
			A[i]=Q[q++];
}

void mergesort(int A[], int inicial, int final){
	if (inicial==final)
		return;
		
	int medio=(inicial+final)/2;
	mergesort(A,inicial, medio);//logn
	mergesort(A,medio+1, final);//logn
	
	merge(A, inicial, medio, final);
	
}

int clasifica(int arr[], int ini, int fin, int cont,double pi, int total){
	int med=(ini+fin)/2;
	double porc;
	if(ini==fin){
		cont+=arr[ini];
		porc = (double)(cont)/total;
		if(porc>=pi) return 1;
		else return 0;
	}
	
	if(arr[med]==1){
		return clasifica(arr, ini, med-1, cont+fin-med+1, pi, total);
	}
	else{
		return clasifica(arr, med+1, fin, cont, pi, total);
	}
}


int main(){
	int n=8, m=6;
	int lote[][n]={ {0,0,0,1,1,0,-1,-1},
					{1,0,1,1,1,0,1,0},
					{0,1,1,1,1,1,1,1},
					{1,1,1,1,1,0,1,-1},
					{1,0,0,0,0,1,-1,-1},
					{1,1,0,1,0,1,1,-1}};
	double pi=0.7;
	int largo[]={6,8,8,7,6,7};
	for(int i=0;i<m;i++)
		mergesort(lote[i],0,largo[i]-1);
	for(int i=0;i<m;i++){
		for(int j=0;j<largo[i];j++)
			cout<<lote[i][j]<<"	";
		cout<<endl;
	}

	
	for(int i=0;i<m;i++){
		cout<<i+1;
		if(clasifica(lote[i], 0, largo[i]-1, 0, pi, largo[i]))
			cout<<" Aprobado"<<endl;
		else
			cout<<" Rechazado"<<endl;
	}
		
	
	
	return 0;
}
