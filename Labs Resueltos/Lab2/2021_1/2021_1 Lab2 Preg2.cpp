
#include <iostream>
#define MAXEMP 7
#define MAXD 6

using namespace std;


void intercambia(int arr[][MAXEMP], int dia, int i, int j){
	int aux;
	aux=arr[dia][i];
	arr[dia][i]=arr[dia][j];
	arr[dia][j]=aux;
}

void intercambiaC(char arr[][MAXEMP], int dia, int i, int j){
	char aux;
	aux=arr[dia][i];
	arr[dia][i]=arr[dia][j];
	arr[dia][j]=aux;
}
void ordena_2(int acc[][MAXEMP], char aux[][MAXEMP], int C, int dia, int i, int j, int flag){
	if(j==C) return;
	if((acc[dia][i] < acc[dia][j] && flag) || (acc[dia][i] > acc[dia][j] && !flag) ){
		intercambia(acc, dia, i, j);
		intercambiaC(aux, dia, i, j);
	}
	ordena_2(acc,aux,C,dia,i,j+1,flag);
}

void ordena(int acc[][MAXEMP], char aux[][MAXEMP], int C, int dia, int i, int flag){
	if(i==C-1) return;
	ordena_2(acc, aux, C, dia, i, i+1, flag);
	ordena(acc, aux, C, dia, i+1, flag);
}

void evalua(int P,int C,int T,int B,int acc[][MAXEMP], char aux[][MAXEMP], int tend[], int dia, int *invertido){
	if(dia==T){
		return;
	}
	int flagComproDia=0;
	ordena(acc, aux, C, dia, 0, tend[dia]);
	cout<<dia+1<<"	"<<P<<"		";
	for(int i=0;i<B;i++){
		if(P>=acc[dia][i]){
			cout<<"("<<aux[dia][i]<<") "<<acc[dia][i]<<"		";
			P=P-acc[dia][i];
			(*invertido)+=acc[dia][i];
			flagComproDia=1;
		}
		else{
			if(!flagComproDia){
				cout<<endl<<"Solo ha podido comprar acciones hasta el dia "<<dia+1<<", tiene "<<*invertido<<" dolares en acciones y le han quedado "<<P<<" dolar(es) de presupuesto"<<endl;
				return;
			}
		}
	}
	cout<<endl;
	int flagSub;
	if(tend[dia]) flagSub=1;
	else flagSub=-1;
	evalua(P, C, T, B+flagSub, acc, aux, tend,  dia+1, invertido);
}

int main(){
	int P=36, C=7, T=6, B=2;
	int acc[MAXD][MAXEMP]={{3,4,5,6,7,1,2},
					 {3,4,5,7,1,2,6},
					 {3,4,5,2,1,6,8},
					 {3,4,5,6,2,1,9},
					 {3,4,5,7,8,9,2},
					 {3,4,5,8,9,7,6}};
	int tend[]={1,1,0,0,1,1};
	char aux[MAXD][MAXEMP];
	for(int i=0;i<T;i++){
		for(int j=0;j<C;j++){
			aux[i][j]='A'+j;
		}
	}
	int invertido;
	cout<<"Dia	Presupuesto		Acciones compradas"<<endl;
	evalua(P, C, T, B, acc, aux, tend, 0, &invertido);

	return 0;
}
