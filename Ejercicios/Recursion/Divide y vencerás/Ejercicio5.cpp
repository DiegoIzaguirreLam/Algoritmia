/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

int hallaMax(int arr[], int ini, int fin){
    if(ini==fin) return arr[ini];
    int med=(ini+fin)/2;
    
    if(arr[med]<arr[med+1]){
         return hallaMax(arr, med+1, fin);
    }
    else{
        return hallaMax(arr, ini, med);
    }
    
}

int main()
{
    int arr[]={6,7,8,10,54,50,40,30,10, 5,4,2,1};
    int n=13;
    cout<<hallaMax(arr, 0, n-1);
    return 0;
}

