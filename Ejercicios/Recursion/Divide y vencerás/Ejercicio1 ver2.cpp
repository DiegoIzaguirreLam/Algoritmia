#include <iostream>

using namespace std;

void solitario(int arr[], int ini, int fin){
    if(ini==fin){
        cout<<"El numero que no se repite es: "<<arr[ini]<<endl;
        return;
    }
    if(ini>fin) return;
    int med=(ini+fin)/2;
    if(med % 2 != 0){
        if(arr[med]==arr[med+1]){
            solitario(arr, ini, med-1);
        }
        else{
            solitario(arr, med+1, fin);
        }
    }
    else{
        if(arr[med]==arr[med-1]){
            solitario(arr, ini, med-2);
        }
        else{
            solitario(arr, med, fin);
        }
    }
}

int main()
{
    int arr[]={1,1,2,2,3,4,4,5,5};
    int n=9;
    solitario(arr, 0, n-1);
    return 0;
}
