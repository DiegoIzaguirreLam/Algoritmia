
#include <iostream>

using namespace std;

int maxG=0;
int matGanancia[10][12];
int indG=0;
int indSol=0;
int solParcial[12];
int tamArr[10];

int maxBack(int arr[],int n, int i, int gParcial){
	if(i>=n){
		if(gParcial>maxG){
                    maxG=gParcial;
                    indSol=0;
                    for(int j=0;j<indG;j++){//copio la solucion
                        matGanancia[indSol][j]=solParcial[j];
                    }
                    tamArr[indSol]=indG;
                    indSol++;
                }
                else if(gParcial==maxG){
                    for(int j=0;j<indG;j++){
                        matGanancia[indSol][j]=solParcial[j];
                    }
                    tamArr[indSol]=indG;
                    indSol++;
                }
		return 0;
	}
        solParcial[indG++]=i;
	if(maxBack(arr, n, i+3, gParcial+arr[i]))
		return 1;
	else{
            indG--;
            maxBack(arr, n, i+1, gParcial);
        }
	return 0;
}

int main(){
	int arr[]={3,6,1,2,4,5,18,10,13,7,15,2};
	int n=12;
	maxBack(arr, n, 0, 0);
	cout<<maxG<<endl;
	for(int i=0;i<indSol;i++){
            for(int j=0;j<tamArr[i];j++){
                cout<<"Proyecto "<<matGanancia[i][j]+1<<": "<<arr[matGanancia[i][j]]<<"k"<<endl;
            }
            cout<<endl;
        }
	return 0;
}
