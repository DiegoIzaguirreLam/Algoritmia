#include <iostream>

using namespace std;

void patron(int n, int i){
	if(n<=0) return;
	patron(n/2, i);
	for(int j=0;j<i;j++) cout<<" ";
	for(int j=0;j<n;j++) cout<<"* ";
	cout<<endl;
	patron(n/2, i+n);
}


int main(){
	patron(8,0);
	return 0;
}
