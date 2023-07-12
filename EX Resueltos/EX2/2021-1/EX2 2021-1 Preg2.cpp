#include <iostream>
#define W 10000//por enunciado
#define MAX 50
using namespace std;


void llenar_mochila(char clientes[][MAX], int acciones[], double comision[], double V[][W + 1],int P, int N) {
    int i, j;
    
    double valores[N];
    for(int i=0;i<N;i++){
        valores[i]=P*acciones[i]*comision[i];
    }
    //Condiciones iniciales
    for (j = 0; j <= W; j++)
        V[0][j] = 0;
    for (i = 0; i <= N; i++)
        V[i][0] = 0;
    
    //Iteraciones
    for (j = 1; j <= W; j++) {
        for (i = 1; i <= N; i++) {
            if (j - acciones[i- 1] >= 0)
                V[i][j] = max(V[i - 1][j], valores[i - 1] + V[i - 1][j - acciones[i - 1]]);
            else
                V[i][j] = V[i - 1][j];
        }
    }
    //hallamos cantidad de acciones
    j=W;
    while(V[N][j-1]==V[N][W]){
        j--;
    }
    cout<<"Para este conjunto de datos, la maxima ganancia debido a las comisiones seria de "<<V[N][W]<<" dolares por un total de "<<j<<" acciones"<<endl;    
    //hallamos la solucion
    i=N;
    j=W;
    cout<<"Clientes que se deben elegir para tener la mayor ganancia: "<<endl;
    while(i>0 && j>0){
        if(V[i][j] == valores[i-1] + V[i-1][j-acciones[i-1]]){
            cout<<"Cliente "<<i<<" - "<<clientes[i-1]<<", ganancia = "<<valores[i-1]<<" por comprar "<<acciones[i-1]<<" acciones."<<endl;
            j = j-acciones[i-1];
        }
        i--;
    }
}

int main(){
    int T=10000, P=4, N=6;
    char clientes[N][MAX] = {"John", "Ron", "Micky", "Vicky", "Ceci", "Isa"};
    int acciones[N] = {3000, 3800, 2800, 3500, 3200, 3400};
    double comision[N]={0.1, 0.02, 0.15, 0.05, 0.08, 0.03};
    double V[N + 1][W + 1];
    
    llenar_mochila(clientes, acciones, comision, V, P, N);

    //cout<<"Maxima ganancia: "<<V[N][W];
    return 0;
}

