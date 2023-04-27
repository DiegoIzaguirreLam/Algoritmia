#include <cstdlib>

#include <iostream>


using namespace std;

int merge(int ini, int fin, int med, int arr[]){
	int cont=1;
	for(int i=med;i>ini;i--){
		if(arr[i-1]<arr[i]){
			cont++;
		}
		else
			break;
	}
	for(int i=med;i<fin;i++){
		if(arr[i]<arr[i+1]){
			cont++;
		}
		else
			break;
	}
	return cont;
}

int maxintervalo(int ini, int fin, int arr[]){
	if(ini==fin){
		return 1;
	}
	int med=(ini+fin)/2;
	int izq, der, cen;
	izq=maxintervalo(ini, med, arr);
	der=maxintervalo(med+1, fin, arr);
	cen=merge(ini, fin, med, arr);
	return max(max(izq,der),cen);
}


int main(){
	int arr[]={10,20,15,10,12,10,13,18};
	int n=8;
	cout<<maxintervalo(0, n-1, arr)<<endl;
	return 0;
}
