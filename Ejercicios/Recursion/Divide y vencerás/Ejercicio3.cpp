#include <iostream>


using namespace std;

int merge(int ini, int fin, int med, int arr[]){
	int cont=1;
	for(int i=med;i>ini;i--){
		if(arr[i]>arr[i-1])
			cont++;
		else
			break;
	}
	for(int i=med;i<fin;i++){
		if(arr[i]<arr[i+1])
			cont++;
		else
			break;
	}
	return cont;
}

int maxintervalo(int ini, int fin, int arr[]){
	int izq, der, cen;
	if(ini == fin)
		return 1;
	
	int med = (ini + fin)/2;
	izq=maxintervalo(ini, med, arr);
	der=maxintervalo(med+1, fin, arr);
	cen=merge(ini, fin, med, arr);
	return max(max(izq, der), cen);
}


int main(){
	
	int n=8;
	int arr[] = {40, 20, 25, 30, 40, 10, 13, 18};
	
	cout<<maxintervalo(0, n-1, arr);
	return 0;
}
