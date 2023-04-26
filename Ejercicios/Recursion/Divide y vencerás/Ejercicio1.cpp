#include <iostream>

using namespace std;

void buscasolitario(int ini, int fin, int arr[]){
	if(ini==fin){
		cout << "El resultado es: "<<arr[ini];
		return;
	}
	
	int med=(fin+ini)/2;
	if(med%2 == 0){
		if(arr[med]==arr[med+1])
			buscasolitario(med+2, fin, arr);
		else
			buscasolitario(ini, med, arr);
	}
	else{
		if(arr[med]==arr[med-1])
			buscasolitario(med+1, fin, arr);
		else
			buscasolitario(ini, med-1, arr);
	}
}

int main(){
	int n=7;
	int arr[]={1,1,2,2,3,4,4};
	buscasolitario(0, n-1, arr);	
	return 0;
}



