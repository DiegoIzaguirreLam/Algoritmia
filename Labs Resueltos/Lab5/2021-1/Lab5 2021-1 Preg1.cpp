#include <iostream>

using namespace std;

int maxGanancia(int arr[], int n){
    int f[n+2];
    f[0]=0;
    f[1]=0;
    f[2]=0;
    
    int sol[n+2]={0};
    int antesYAct, ant, dobleAnt;
    for(int i=3;i<=n+1;i++){
        antesYAct=arr[i-3]+f[i-3];
        ant=f[i-1];
        dobleAnt=f[i-2];
        if(antesYAct>ant && antesYAct>dobleAnt){
            f[i]=antesYAct;
            sol[i]=1;
            sol[i-1]=0;
            sol[i-2]=0;
        }
        else{
            if(ant>dobleAnt){
                f[i]=ant;
                sol[i]=0;
            }
            else{
                f[i]=dobleAnt;
                sol[i]=0;
            }
        }
    }
    cout<<"Proyectos elegidos: "<<endl;
    for(int i=0;i<=n+1;i++){
        if(sol[i]) cout<<"Proyecto "<<i-2<<": "<<arr[i-3]<<"k"<<endl;
    }
    cout<<endl;
    return f[n+1];
}

int main()
{
    int arr[]={3,6,1,2,4,5,18,10,13,7,15,2};
    int n=12;
    cout<<"Ganancia maxima: "<<maxGanancia(arr, n)<<"k";
    return 0;
}
