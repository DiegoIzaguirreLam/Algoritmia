
#include <iostream>

using namespace std;

int x=0;

int hallaPeso(int alma[],int n,int peso,int solu[], int ind){
	if(ind==n || peso<0) return 0;
	
	if(alma[ind]==peso){
		x++;
		solu[ind]=1;
		cout<<"Resultado "<<x<<":";
		for(int i=0;i<=ind;i++){
			if(solu[i]) cout<<" "<<alma[i]<<"k";
		}
		cout<<"	Ubicaciones: ";
		for(int i=0;i<=ind;i++){
			if(solu[i]){
				if(i%4==0) cout<<"IA"<<i/4+1;
				if(i%4==1) cout<<"IB"<<i/4+1;
				if(i%4==2) cout<<"DA"<<i/4+1;
				if(i%4==3) cout<<"DB"<<i/4+1;
				cout<<" ";
			}
		}
		cout<<endl;
		solu[ind]=0;
		return 0;
	}
	solu[ind]=1;
	
	if(hallaPeso(alma, n, peso-alma[ind], solu, ind+1)){
		return 1;
	}
	else{
		solu[ind]=0;
		return hallaPeso(alma, n, peso, solu, ind+1);
	}
}

int main(){
	int alma[]={7, 9, 8, 18, 17, 12, 6, 7, 14, 11, 10, 15, 19, 8, 12, 11};
	int n=16;
	int peso=23;
	int solu[n]={0};
	
	hallaPeso(alma, n, peso, solu, 0);
	if(!x){
		cout<<"No se encontro"<<endl;
	}
	return 0;
}



