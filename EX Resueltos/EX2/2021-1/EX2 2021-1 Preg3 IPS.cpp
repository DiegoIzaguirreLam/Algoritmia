
#include <iostream>
using namespace std;

int validaNum(char num, int numFormado,int flagCeroAnt){
	if(numFormado>=100) return 0; //si ya tiene 3 digitos
        if(flagCeroAnt) return 0;
	int numInt;
	numInt = num - '0';
	numFormado = numFormado * 10 + numInt;
	if(numFormado>255) return 0;
	return 1;
}

int validaPunto(int cuentaPuntos){
	if(cuentaPuntos==3) return 0;
	return 1;
}

int generaIPs(char s[], int n, char ip[], int nip, int indS, int indIP, int numFormado, int cuentaPuntos, int flagCeroAnt, int flagPuntoAnt){
	if(indS==n && cuentaPuntos==3){
		for(int i=0;i<nip;i++) cout<<ip[i]<<" ";
                cout<<endl;
		return 0;
	}
    if(indS==n) return 0; // si ya termino de recorrer la cadena s y la ip generada no tiene 3 puntos exactamente, retorna 0.
	char car;
	for(int i=0;i<2;i++){//probar punto o siguiente caracter, si no se puede entonces retorna 0
		if(i==0){
			car = s[indS];
			if(validaNum(car, numFormado, flagCeroAnt)){
				ip[indIP] = car;
                                if(car=='0' && flagPuntoAnt) flagCeroAnt=1;
                                else flagCeroAnt=0;
				if(generaIPs(s, n, ip, nip, indS+1, indIP+1, numFormado*10 + (car-'0'), cuentaPuntos, flagCeroAnt, 0))
					return 1;
				ip[indIP] = ' ';
			}
		}
		else{
			car = '.';
			if(!flagPuntoAnt && indIP!=0 && validaPunto(cuentaPuntos)){
				ip[indIP] = car;
				if(generaIPs(s, n, ip, nip, indS, indIP+1, 0, cuentaPuntos+1, 0, 1))
					return 1;
				ip[indIP] = ' ';
			}
		}
	}
	return 0;
}

int main(){
	char s[]="101069";
	int n = sizeof(s)/sizeof(s[0]) - 1; //hallar el tamaño de la cadena s, -1 ya que no queremos que n considere el caracter de terminacion 
	char ip[n+4]={' '};
	int nip=n+4;
	
	generaIPs(s, n, ip, nip, 0, 0, 0, 0, 0, 1);
	
	return 0;
}


