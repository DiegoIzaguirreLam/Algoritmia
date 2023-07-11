#include <iostream>
#define MAX 5

using namespace std;

double mejorPromT=9999999, mejorPromP=999999, mejorPromV=999999, mejorProm=99999;

int mejorSol[3][MAX]={};

int valida(int flagGrupo,int c,int indTrib,int indPref,int indVIP, int &ind){
    if(flagGrupo==0){
        if(indTrib<c){
            ind=indTrib;
            return 1;
        }
    }
    if(flagGrupo==1){
        if(indPref<c){
            ind=indPref;
            return 1;
        }
    }
    if(flagGrupo==2){
        if(indVIP<c){
            ind=indVIP;
            return 1;
        }
    }
    return 0;
}

int asignaPersonas(int edades[],int n,int c,int t,int p,int v,int solu[][MAX],int indPersona,int indTrib,int indPref,int indVIP ){
    if(indPersona==n){
        double promT=0, promP=0, promV=0, prom=0;
        for(int i=0;i<3;i++){
            for(int j=0;j<c;j++){
                if(i==0) promT+=solu[i][j];
                if(i==1) promP+=solu[i][j];
                if(i==2) promV+=solu[i][j];
            }
        }
		promT/=c;
		promP/=c;
        promV/=c;
		prom = (promT+promP+promV)/3;
        if(prom<mejorProm){
			for(int i=0;i<3;i++){
				for(int j=0;j<c;j++){
					mejorSol[i][j]=solu[i][j];
				}
			}
			mejorPromT=promT;
			mejorPromP=promP;
			mejorPromV=promV;
		}
        return 0;
    }
    int ind, usaSillaT, usaSillaP, usaSillaV;
    for(int i=0;i<3;i++){//lo intento poner en cada una
        if(valida(i, c, indTrib, indPref, indVIP, ind)){
            usaSillaT=0; usaSillaP=0; usaSillaV=0;
            if(edades[indPersona]>=45){
                if(i==0){
                    if(t<=0) continue;
                    usaSillaT=1;
                }
                if(i==1){
                    if(p<=0) continue;
                    usaSillaP=1;
                }
                if(i==2){
                    if(v<=0) continue;
                    usaSillaV=1;
                }
            }
            solu[i][ind]=edades[indPersona];
            if(asignaPersonas(edades, n, c, t-usaSillaT, p-usaSillaP, v-usaSillaV, solu, indPersona+1, indTrib+(i==0), indPref+(i==1), indVIP+(i==2)))
                return 1;
            else
                solu[i][ind]=0;
        }
    }
    return 0;
}

int main(){
    int c=3, t=2, p=1, v=0;
    int edades[]={25, 50, 35, 28, 45, 23, 24, 18, 48};
    int n=3*c;
    int solu[3][MAX]={};
    
    asignaPersonas(edades, n, c, t, p, v, solu, 0, 0, 0, 0);
    for(int i=0;i<3;i++){
    	for(int j=0;j<c;j++){
    		cout<<mejorSol[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<"Promedio de edades en Tribuna: "<<mejorPromT<<endl;
	cout<<"Promedio de edades en Preferencial: "<<mejorPromP<<endl;
	cout<<"Promedio de edades en Vip: "<<mejorPromV<<endl;
	
    return 0;
}
