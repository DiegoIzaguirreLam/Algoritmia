#include <iostream>


using namespace std;

int cuentaCeros(int arr[], int ini, int fin, int cuenta){
	if(ini>fin) return cuenta;
	if(ini==fin) return cuenta+!arr[ini];
	int med=(ini+fin)/2;
	
	if(arr[med]==0){
		return cuentaCeros(arr, ini, med-1, cuenta+fin-med+1);
	}
	else{
		return cuentaCeros(arr, med+1, fin, cuenta);
	}
}

int main(){
	int arr[]={1,1,0,0,0,0,0};
	int n=7;
	
	cout << "Num ceros: "<<cuentaCeros(arr, 0, n-1, 0);
	return 0;
}
