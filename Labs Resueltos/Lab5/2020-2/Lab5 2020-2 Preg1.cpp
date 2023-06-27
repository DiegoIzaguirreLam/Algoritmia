#include <iostream>

using namespace std;

int mov[2][2] = {{1,0},{0,1}};

int solu[5][5] = {{0,0,0,0,0},
                  {0,0,0,0,0},
                  {0,0,0,0,0},
                  {0,0,0,0,0},
                  {0,0,0,0,0}};
int p =0;
int indPedEnc=0;

int es_valido(int dato, int pedido[], int c){
    for(int i=0; i<c; i++){
        if(pedido[i] == dato){
            indPedEnc = i;
            return 1;
        }
    }
    return 0;
}

void despachaPedido(int matriz[5][5], int pedido[], int n, int c, int x, int y){
    if(p == c){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cout<<solu[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
        return;
    }

    if(x >= n || y >= n){
        return;
    }
    if(es_valido(matriz[x][y], pedido, c)){
        solu[x][y] = matriz[x][y];
        pedido[indPedEnc] = -1;
        p++;
        for(int i=0; i<2; i++){
            despachaPedido(matriz, pedido, n, c, x+mov[i][0], y+mov[i][1]);
        }
        pedido[indPedEnc] = matriz[x][y];
        p--;
        solu[x][y] = 0;
    }else{
        for(int i=0; i<2; i++){
            despachaPedido(matriz, pedido, n, c, x+mov[i][0], y+mov[i][1]);
        }
    }
}

int main(){
    int n=5, c=4;
    int pedido[] = {5,7,7,8};

    int matriz[5][5] = {{2,8,6,6,7},
                        {7,6,8,5,10},
                        {2,9,10,7,6},
                        {5,9,8,11,7},
                        {3,2,8,10,3}};
    despachaPedido(matriz, pedido, n, c, 0,0);
    return 0;
}
