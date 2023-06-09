#include <iostream>

#define MAX 5
using namespace std;

// funcion para calcular la suma de cada subarreglo
int calcularPeso(int meteorito[MAX][MAX][MAX], int x1, int x2, int y1, int y2, int z1, int z2) {
    int peso = 0;
    for (int x = x1; x <= x2; x++) {
        for (int y = y1; y <= y2; y++) {
            for (int z = z1; z <= z2; z++) {
                peso += meteorito[x][y][z];
            }
        }
    }
    return peso;
}

// funcion recursiva para hallar el cubo
int encontrarCuboVibranio(int meteorito[MAX][MAX][MAX], int x1, int x2, int y1, int y2, int z1, int z2, int cortes) {
    if (x1 > x2 || y1 > y2 || z1 > z2) {
        return 999;
    }
    if (meteorito[x1][y1][z1]==1) {//si encuentra el meteorito
        cout << "El cubo de vibranio se encuentra en la posición (" << x1+1 << ", " << y1+1 << ", " << z1+1 << ")" << endl;
        return cortes;
    }

    if(x1!=x2){//primero cortamos en x
        int mitadX = (x1 + x2) / 2;
        int pesoX = calcularPeso(meteorito, x1, mitadX, y1, y2, z1, z2);
        if(pesoX > 0){
            return encontrarCuboVibranio(meteorito, x1, mitadX, y1, y2, z1, z2, cortes+1);
        }
        else{
            return encontrarCuboVibranio(meteorito, mitadX+1, x2, y1, y2, z1, z2, cortes+1);
        }
    }
    else if(y1!=y2){//luego, habiendo ubicado la coordenada x del meteorito, cortamos en y
        int mitadY = (y1 + y2) / 2;
        int pesoY = calcularPeso(meteorito, x1, x2, y1, mitadY, z1, z2);
        if(pesoY > 0){
            return encontrarCuboVibranio(meteorito, x1, x2, y1, mitadY, z1, z2, cortes+1);
        }
        else{
            return encontrarCuboVibranio(meteorito, x1, x2, mitadY+1, y2, z1, z2, cortes+1);
        }
    }
    else{//habiendo encontrado coordenadas x y y del meteorito procedemos a cortar en Z hasta encontrarlo.
        int mitadZ = (z1 + z2) / 2;
        int pesoZ = calcularPeso(meteorito, x1, x2, y1, y2, z1, mitadZ);
        if(pesoZ>0){
            return encontrarCuboVibranio(meteorito, x1, x2, y1, y2, z1, mitadZ, cortes+1);
        }
        else{
            return encontrarCuboVibranio(meteorito, x1, x2, y1, y2, mitadZ+1, z2, cortes+1);
        }
    }
}

int main() {
    int L=4, W=3, H=2;
    int meteorito[MAX][MAX][MAX]={};//se crea la matriz con 0s
    meteorito[2][1][1] = 1;//se coloca el meteorito
    
    int cortes;
    cortes=encontrarCuboVibranio(meteorito, 0, L-1, 0, W-1, 0, H-1, 0);
    cout << "Número total de cortes realizados: " << cortes << endl;

    return 0;
}
