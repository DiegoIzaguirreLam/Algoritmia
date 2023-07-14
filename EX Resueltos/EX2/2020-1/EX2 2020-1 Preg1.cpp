
#include <iostream>
#include <cstdlib>
#define MAX 100
using namespace std;


int solu[MAX][MAX];
int maxPallets=0;
int var=1;

int valido(int alma[][MAX],int x,int y,int n, int m){
    if(x<0 || y<0 || x>=n || y>=m)
        return 0;
    if(x==0 && y==0) return 0;
    if(alma[x][y]!=0) return 0;
    for(int i=x-1; i<x+2;i++){//area 3x3 alrededor de (x,y)
        for(int j=y-1;j<y+2;j++){
            if(i>=0 && j>=0 && i<n && j<m && alma[i][j]==1){
                return 0;
            }
        }
    }
    return 1;
}
void imprimealma(int alma[][MAX], int n, int m){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            cout<<alma[i][j]<<" ";
        cout<<endl;
    }
}
int colocaPallet(int alma[][MAX],int n,int m,int x, int y, int contPallets){
    if(x==n && y<m) return colocaPallet(alma, n, m, 0, y+1, contPallets);
    if(x==n && y==m){
        if(maxPallets<=contPallets){
            for(int i=0;i<n;i++)
                for(int j=0;j<m;j++)
                    solu[i][j]=alma[i][j];
            maxPallets = contPallets;
        }
        return 0;
    }
    if(valido(alma, x, y, n, m)){
        alma[x][y]=1;
        if(colocaPallet(alma, n, m, x+1, y, contPallets+1))
            return 1;
        else{
            alma[x][y]=0;//back
        }   
    }
    return colocaPallet(alma, n, m, x+1,y,contPallets);
}

int main(){
    int n=5, m=5;
    int alma[n][MAX];
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) alma[i][j]=0;
    colocaPallet(alma, n, m, 0, 0, 0);
    imprimealma(solu, n, m);
    cout<<maxPallets;
    return 0;
}
