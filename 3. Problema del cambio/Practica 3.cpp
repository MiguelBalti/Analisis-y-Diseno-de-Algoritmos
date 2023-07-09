#include<iostream>
using namespace std;
int n[9], m[] = {500,200,100,50,20,10,5,2,1}, ca[9], total;

void datos();
void imprime();
int cantdinero(int, int);

 int main(){
 	system("CLS");
 	datos();
 	for(int i=0;i<9;i++){
 		ca[i] = cantdinero(m[i],n[i]);
	 }
	imprime();
 	return 0;
 }
 

void datos(){
	cout<<"Ingrese la cantidad total: ";
 	cin>>total;
 	for(int i=0;i<9;i++){
 		cout<<"Ingrese la cantidad de "<<m[i]<<" :";
 		cin>>n[i];
	}
}

void imprime(){
	cout<<endl;
	for(int i=0;i<9;i++){
		if(ca[i] != 0){
		printf("\033[0;31m");
		cout<<"La cantidad de "<<m[i]<<" es: "<<ca[i]<<endl;
		printf("\033[0m");
		}
		else{
		cout<<"La cantidad de "<<m[i]<<" es: "<<ca[i]<<endl;
		}
	}
}

int cantdinero(int valor, int cantidad){
 	if(cantidad == 0){
 		return 0;
	 }
	else if ((total/(valor*cantidad)) >= 1){
		total = total-(valor*cantidad);
		return cantidad;
	}
	else{
		return cantdinero(valor,(cantidad-1));		
	}
 }