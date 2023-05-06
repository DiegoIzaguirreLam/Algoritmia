#include <iostream>
using namespace std;

void merge(int A[], int inicial, int medio, int final, int &inversiones){
	int longitud1, longitud2, i, p, q;
	
	longitud1=(medio+1)-inicial;//primera mitad del arreglo
	longitud2=final-medio;//segunda mitad del arreglo
	
	int P[longitud1+1];
	int Q[longitud2+1];
	//{1, 3, 5, 2, 4, 6};
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
		if (P[p]<=Q[q]){
			A[i]=P[p++];
		}
		else{
			A[i]=Q[q++];
			inversiones+=longitud1-p;
		}
			
}

void mergesort(int A[], int inicial, int final, int &inversiones){
	if (inicial==final)
		return;
		
	int medio=(inicial+final)/2;
	mergesort(A,inicial, medio, inversiones);//logn
	mergesort(A,medio+1, final, inversiones);//logn
	
	merge(A, inicial, medio, final, inversiones);
	
}
	

int main(){
	int A[]={1, 3, 5, 2, 4, 6, 4};
	int i, n=7;
	int inversiones=0;
	cout<<endl;
	
	mergesort(A, 0,n-1, inversiones);
	
	cout << inversiones;
	
	return 0;
}


