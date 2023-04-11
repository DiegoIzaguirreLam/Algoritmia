

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




int main(){
	int n=16, peso=23, parcial, mpeso, mcomb, opcion;
	int paq[]={7, 9, 8, 18, 17, 12, 6, 7, 14, 11, 10, 15, 19, 8, 12, 11};
	int cromo[n];
	opcion=(int)pow(2, n);
	
	for(int i=0;i<opcion;i++){
		cargabin(i,n,cromo);
		parcial=0;
		for(int j=0;j<n;j++)
			parcial=cromo[j]*paq[j]+parcial;
		if(parcial==peso){
			for(int k=0;k<n;k++){
				if(cromo[k]==1){
					if(k%4==0) cout<<"IA" << k/4+1 << " ";
					if(k%4==1) cout<<"IB" << k/4+1 << " ";
					if(k%4==2) cout<<"DA" << k/4+1 << " ";
					if(k%4==3) cout<<"DB" << k/4+1 << " ";
				}
			}
			cout<<endl;
		}
	}
	return 0;
}



