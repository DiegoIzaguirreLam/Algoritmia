#include <iostream>
using namespace std;


int min(int a, int b){
	if(a<b) return a;
	else return b;
}


int mergemin(int ini, int fin, int med, int arr[]){
	int min=9999999;
	for(int i=med;i>ini;i--)
		if(arr[i]<min)
			min=arr[i];
	for(int j=med;j<fin;j++)
		if(arr[j]<min)
			min=arr[j];
	return min;
}


int minvalor(int ini, int fin, int arr[]){
	int izq, der, cen;
	if(ini == fin)
		return arr[ini];
	int med = (ini + fin)/2;
	izq=minvalor(ini, med, arr);
	der=minvalor(med+1, fin, arr);
	cen=mergemin(ini, fin, med, arr);
	return min(min(izq, der), cen);
}

int mergemax(int ini, int med, int fin, int arr[], int min){
	int cont=0;
	for(int i=med;i>ini;i--){
		if(arr[i]==min)
			cont++;
		else
			break;
	}
	for(int j=med;j<fin;j++){
		if(arr[j]==min)
			cont++;
		else
			break;
	}
	if(arr[med]==min) cont--; //ya que en este caso se habra contado dos veces, hay que restar uno.
	return cont;
}

int maxintervalo(int ini, int fin, int arr[], int min){
	if(ini==fin){
		return arr[ini]==min;//retorna 1 si es igual al valor minimo, 0 en caso contrario
	}
	int izq, der, cen, med;
	med=(ini+fin)/2;
	izq=maxintervalo(ini, med, arr, min);
	der=maxintervalo(med+1, fin, arr, min);
	cen=mergemax(ini, med, fin, arr, min);
	return max(max(izq,der),cen);
}

int main(){
	int n=30;
	int peso[n]={98, 95, 92, 89, 91, 92, 89, 89, 92, 93, 94, 92, 91, 90, 88, 88, 88, 89, 90, 91, 88, 88, 90, 90, 92, 89, 90, 88, 90, 91};

	int valormin;
	valormin=minvalor(0, n-1, peso);
	
	cout<<"Valor minimo: "<<valormin<<endl;
	cout<<"Mayor cantidad de dias consecutivos en lo que lo obtuvo: "<<maxintervalo(0, n-1, peso, valormin)<<endl;
	return 0;
}
