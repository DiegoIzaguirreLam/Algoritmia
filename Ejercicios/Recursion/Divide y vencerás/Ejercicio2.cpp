#include <iostream>

using namespace std;


int cuentaCeros(int ini, int fin, int arr[], int cont){
	int med=(ini+fin)/2;
	if(ini==fin)
		return cont + !arr[ini];
	/*if(ini>fin)
		return cont;*/
	if(arr[med]==0)
		cuentaCeros(ini, med-1, arr, fin-med+cont+1);
	else
		cuentaCeros(med+1, fin, arr, cont);
}

int main(){
	int n=7;
	int arr[]={0,0,0,0,0,0,0};
	
	cout << cuentaCeros(0, n-1, arr, 0);
	
	return 0;
}
