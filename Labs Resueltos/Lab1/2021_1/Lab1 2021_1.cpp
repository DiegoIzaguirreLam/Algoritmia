#include <iostream>
#include <cmath>

using namespace std;

void cargabin(int num, int n, int cromo[]){
	int i, res;
	for(int i=0;i<n;i++)cromo[i]=0;
	i=0;
	while(num>0){
		res = num%2;
		num = num/2;
		cromo[i]=res;
		i++;
	}
}

int cuentaUnos(int num[], int n){
	int cuenta=0;
	for(int i=0; i<n; i++){
		if(num[i]==1)
			cuenta++;
	}
	return cuenta;	
}

int main(){
	int N, i;
	cout<<"Ingrese el numero N: ";
	cin>>N;
	int M, C, parcialp;
	cout<<"Ingrese M y C: ";
	cin>>M>>C;
	int bahia1[N], bahia2[N], bahia3[N];
	cout<<"Ingrese los números de la bahia 1: ";
	for(i=0;i<N;i++) cin>>bahia1[i];
	cout<<"Ingrese los números de la bahia 2: ";
	for(i=0;i<N;i++) cin>>bahia2[i];
	cout<<"Ingrese los números de la bahia 3: ";
	for(i=0;i<N;i++) cin>>bahia3[i];
	
	int cromo[3*N], opcion=(int)pow(2, 3*N);
	
	//4 -> 000000000000
	//3 -> 000000000
	//2 -> 000000
	//1 -> 000
	int cuentaUnos;
	for(i=0; i<opcion; i++){
		parcialp=0;
		cargabin(i, 3*N, cromo);
		cuentaUnos=0;
		for(int j=0; j<3*N; j++){
			if(j<=3)
				parcialp=cromo[j]*bahia1[j]+parcialp;
			if(j>3 and j<=7)
				parcialp=cromo[j]*bahia2[j-N]+parcialp;
			if(j>7)
				parcialp=cromo[j]*bahia3[j-2*N]+parcialp;
			cuentaUnos+=cromo[j];
		}
		if(parcialp==C and cuentaUnos==M){
			int impBahia1=1, impBahia2=1, impBahia3=1;
				for(int j=0; j<3*N; j++){
					if(j<=3 and cromo[j]){
						if(impBahia1){
							cout<<"Bahia 1: ";
							impBahia1=0;
						}
						cout<<bahia1[j]<<" ";
					}
					if(j>3 and j<=7 and cromo[j]){
						if(impBahia2){
							cout<<"Bahia 2: ";
							impBahia2=0;
						}
						cout<<bahia2[j-N]<<" ";
					}
					if(j>7 and cromo[j]){
						if(impBahia3){
							cout<<"Bahia 3: ";
							impBahia3=0;
						}
						cout<<bahia3[j-2*N]<<" ";
					}
				}
			cout<<"Comb num: "<<i<<"\n";//<<"Cuenta Unos: "<<cuentaUnos<<"\n";	
		}
		
	}
	return 0;
}


