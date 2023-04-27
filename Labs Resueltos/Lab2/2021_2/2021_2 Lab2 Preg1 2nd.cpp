

#include <iostream>
#define MAXFASES 7
#define MAXEMP 7

using namespace std;


void intercambioI(int cost[][MAXEMP], int i, int j, int numfase){
	int aux;
	aux=cost[numfase][i];
	cost[numfase][i]=cost[numfase][j];
	cost[numfase][j]=aux;
}

void intercambioC(char cost[][MAXEMP], int i, int j, int numfase){
	char aux;
	aux=cost[numfase][i];
	cost[numfase][i]=cost[numfase][j];
	cost[numfase][j]=aux;
}

void ordena_2(int cost[][MAXEMP], char emp[][MAXEMP], int N, int flagEcon, int numfase, int i, int j){
	if(j==N) return;
	if((cost[numfase][i]>cost[numfase][j] && flagEcon) ||
		(cost[numfase][i]<cost[numfase][j] && !flagEcon)){
			intercambioI(cost, i, j, numfase);
			intercambioC(emp, i,j, numfase);
		}
	ordena_2(cost, emp, N, flagEcon, numfase, i, j+1);
}

void ordenaAscoDesc(int cost[][MAXEMP], char emp[][MAXEMP], int N, int flagEcon, int numfase, int i){
	if(i==N-1) return;
	ordena_2(cost, emp, N, flagEcon, numfase, i, i+1);
	ordenaAscoDesc(cost, emp, N, flagEcon, numfase, i+1);
}

void imprimeCons(int cost[][MAXEMP], char emp[][MAXEMP], int cant, int numfase, int i, int *costoReal, int maxPag){
	if(cant==i) return;
	if(maxPag>cost[numfase][i]){
		cout << emp[numfase][i]<<", ";
		(*costoReal) += cost[numfase][i];
		imprimeCons(cost, emp, cant, numfase, i+1, costoReal, maxPag);
		maxPag-=cost[numfase][i];
	}
	else{
		imprimeCons(cost, emp, cant+1, numfase, i+1, costoReal,maxPag);
	}
}


void eval(int P,int NF,int N,double porc[],int cost[][MAXEMP],char emp[][MAXEMP], int econ[], int cant[], int numfase, int ahorrado){
	if(numfase==NF) return;
	int monto = P*porc[numfase];
	int maxPag=monto+ahorrado, costoReal=0;
	ordenaAscoDesc(cost, emp, N, econ[numfase], numfase, 0);
	
	cout<<numfase+1<<"			"<<monto<<"		";
	imprimeCons(cost, emp, cant[numfase], numfase, 0, &costoReal, maxPag);
	cout<<"		"<<costoReal;
	ahorrado=ahorrado+monto-costoReal;
	cout<<"		"<<ahorrado<<endl;
	eval(P, NF, N, porc, cost, emp, econ, cant, numfase+1, ahorrado);	
}

int main(){
	int P = 200000, NF=7, N=7;
	double porc[]={0.05,0.1,0.15,0.45,0.1,0.05,0.1};
	int cost[][MAXEMP]={{5100,4100,4000,5000,3000,3500,2800},
						{4400,4000,4100,3800,4500,4200,4300},
						{29000, 31000, 32000,30000,33000,35000,34000},
						{90500,90000,91000,93000,89000,85000,92000},
						{6800,7000,6000,6500,6800,6900,6700},
						{10500,10000,9000,9500,11000,10800,8500},
						{10000,9000,11000,12000,9500,10500,11500}};
	int aux[][MAXEMP]={};
	int econ[]={1,1,0,0,1,0,1};
	int cant[]={3,4,1,1,3,1,2};
	char emp[N][MAXEMP];
	for(int i=0;i<NF;i++){
		for(int j=0;j<N;j++){
			emp[i][j]='A'+j;
		}
	}
		
	cout<<"Fase		"<<"Monto Destinado	"<<"	Consultoras elegidas"<<"	Costo real"<<"	Ahorro hasta la fase"<<endl;
	eval(P,NF,N,porc,cost,emp,econ,cant, 0, 0);
	cout<<endl<<endl;
	
	return 0;
}
