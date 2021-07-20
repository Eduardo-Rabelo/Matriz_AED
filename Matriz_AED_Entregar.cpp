#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

int main(){
	
	int n;
	
	srand(time(NULL));
	
	cout << "Digite valor de n:";
	cin >> n;
	cout << endl;
	int matriz[n][n];
	int matriz1[n][n];
	int *p;
	int contr=1,contbaixo=1,contvolta=0,contvai=0,contl=1,soma=0,i=0;
	bool fim=false;
	srand(time(NULL));
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			matriz[i][j] =rand()%99;	
		}
	}

	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if( matriz[i][j]<10){
				cout << 0;
			}	
			cout << matriz[i][j] << " ";	
		}
		cout << endl;
	}
	
	cout << endl << endl;
	
	p = &matriz[0][0];
	soma=soma+*p;
	cout << endl << endl << endl;
	cout << *p << " ";
	
	
	while(i<(n*n) && fim==false){

		if(contr%n!=0 && contbaixo<n){
			
			if(*(p-1)>*(p+1) && *(p-1)>*(p+n) && contvai==0 && contr>1){
				contvolta=1;
				contr--;
				p=p-1;
				cout << *p << " ";
				soma=soma+*p;
			}
			
			else if(*(p+1)>*(p+n) && contvolta==0){
				contvai=1;
				contr++;
				p=p+1;
				cout << *p << " ";
				soma=soma+*p;
			}
			
			else if(*(p+n)>*(p+1)){
				contvolta=0;
				contvai=0;
				contbaixo++;
				p=p+n;
				cout << *p << " ";
				soma=soma+*p;
			}
			else if(*(p+n)==*(p+1)){
				contvolta=0;
				contvai=0;
				contbaixo++;
				p=p+n;;
				cout << *p << " ";
				soma=soma+*p;
			}
			
			else if(contvolta=1 && *(p-1)>*(p+n) && contr>1){
				contr--;
				p=p-1;
				cout << *p << " ";
				soma=soma+*p;
			}
			
			else if(contvolta=1){
				contvolta=0;
				contvai=0;
				contbaixo++;
				p=p+n;;
				cout << *p << " ";
				soma=soma+*p;
			}
		}

		else if(contr%n==0 && contbaixo<n){
			
			if(*(p-1)>*(p+n) && contvai==0){
				contvolta=1;
				contr--;
				p=p-1;
				cout << *p << " ";
				soma=soma+*p;
			}
			else{
				contvolta=0;
				contvai=0;
				contbaixo++;
				p=p+n;
				cout << *p << " ";
				soma=soma+*p;
			}

		}

		else if(contbaixo==n && contr%n!=0){
			contr++;
			p=p+1;
			cout << *p << " ";
			soma=soma+*p;
			if(p==&matriz[0][0]+n*n){
				fim=true;
			}
		}
		i++	;
	}

	cout << endl << endl << endl;
	cout << "SOMA:" << soma << endl << endl;
	
	return 0; 
}
