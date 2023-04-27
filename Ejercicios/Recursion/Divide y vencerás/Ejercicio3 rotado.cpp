#include <iostream>


using namespace std;

void hallaMenor( int arr[], int ini, int fin){
    if(ini==fin || arr[ini]<arr[fin]){
        cout<<"El menor elemento es: "<<arr[ini]<<endl;
        return;
    }
    int med=(ini+fin)/2;
    if(arr[med]>arr[fin]) hallaMenor(arr,med+1,fin);
    else hallaMenor(arr,ini,med);
}

int main(){
	int arr[]={8,2,3,4,5,6,7};
	int n=7;
	
	hallaMenor(arr, 0, n-1);
	return 0;
}
