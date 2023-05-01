#include <cstdlib>
#include <iostream>
#define MAX 6
using namespace std;

/*
 * 
 */

int sonda(int mapa[][MAX], int N,int M,int xmov, int ymov, int x, int y, int primerUniverso){
    if(x>=N || y>=M || x<0 || y<0) return 0;
    int cont=0;
    if(ymov!=0){
        if(primerUniverso)
            for(int i=0;i<M;i++) cont+=mapa[x][i];
        for(int i=0;i<N;i++)
            if(i!=x) cont+=mapa[i][y];
    }
    else{
        if(primerUniverso) for(int i=0;i<N;i++) cont+=mapa[i][y];
        for(int i=0;i<N;i++)
            if(i!=y) cont+=mapa[x][i];
    }
    cont+=sonda(mapa, N, M, xmov, ymov, x+xmov, y+ymov, 0);
    return cont;
}

int main(int argc, char** argv) {
    int N=6, M=6;
    int mapa[][MAX]={   {0,0,0,1,0,1},
                        {0,0,1,0,0,0},
                        {0,1,0,0,0,1},
                        {1,0,0,0,0,0},
                        {0,1,0,0,0,0},
                        {0,0,0,0,1,0}};
    cout<<sonda(mapa, N, M, 0, 1, 3,2, 1);
    return 0;
}

