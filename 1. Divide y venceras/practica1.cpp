#include<iostream>
#include<string>
#include<string.h>
#include <windows.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

using namespace std;
int binario1[128];
int binario2[128];
int binario[100];
int lon;

void recibebinario();
int espotdos(int);
string convpotdos(int, int, string);
int multiplica(int [], int [], int , int);
void dec_bin(int);
string decimal_binstr(int);
void recibedecimal();
int hex_dec();
void recibehexadecimal();
void dec_hex(int);



int main(){
	int base,resul;
	cout<<"Ingresa la longitud del numero con mayor cantidad de digitos\n";	
	cin>>lon;
	cout<<"Ingresa la base: \n";
	cout<<"2 para binario \n";
	cout<<"10 para decimal \n";
	cout<<"16 para hexadecimal \n";
	cin>>base;
	
	
	switch(base){
		case 2:
			string bin1,bin2
			recibebinario();
			dec_bin(multiplica(binario1,binario2,lon,base));
			break;
		case 10:
		
			recibedecimal();
			cout<<multiplica(binario1,binario2,lon,base);
			break;
		case 16:
			recibehexadecimal();
			dec_hex(multiplica(binario1,binario2,lon,base));
			break;
		default: cout<<"No esta en las bases";
	}
	
	
	
	
	
	return 0;
}

int espotdos(int lon){
	int npotdos = 1;
	if((lon & (lon - 1)) == 0){
		return lon;
	}
	else{
		while (npotdos < lon)
        npotdos <<= 1;
    	return npotdos;
	}
}

string convpotdos(int sizelon, int size, string bin){
	if(((sizelon & (sizelon - 1)) == 0) && (sizelon == size)){
		return bin;
	}
	else{
		string sub;
		for(int i = 0; i < (size - sizelon); i++){
			sub.append("0");
		}
		sub.append(bin);
		return sub;
	}
}


void recibebinario(string &bin1,string &bin2){
	string bin1,bin2,subbin1,subbin2;
	int lonbin1,lonbin2;
	cout<<"Ingrese el primer numero ";
	cin>>bin1;
	cout<<"\nIngrese el segundo numero ";
	cin>>bin2;
	lonbin1 = bin1.size();
	lonbin2 = bin2.size();
	lon = espotdos(max(lonbin1,lonbin2));
	bin1 = convpotdos(lonbin1,lon,bin1);
	bin2 = convpotdos(lonbin2,lon,bin2);
	
	
	for(int k=0;k<bin1.size();k++){
		binario1[k] = bin1[k]-48;
	}
	
	for(int k=0;k<bin2.size();k++){
		binario2[k] = bin2[k]-48;
	}
	
}

int multiplica(int bin1[], int bin2[], int size, int base){
	int xi[100],xd[100],yi[100],yd[100],resultado,potdos = 1,mitadpotdos = 1; 
	
	if(size == 1){
		
		return (bin1[0]*bin2[0]);
	}
	else{
		for(int i=0;i<size/2;i++){
			xi[i] = bin1[i];
			yi[i] = bin2[i];			
		}
		for(int i=size/2;i<size;i++){
			xd[i-(size/2)] = bin1[i];
			yd[i-(size/2)] = bin2[i]; 
		}
		potdos <<= size;
		mitadpotdos <<= size/2;	
		resultado = (potdos * multiplica(xi,yi,(size/2),base) + 
			(mitadpotdos * multiplica(xi,yd,(size/2),base)) + (mitadpotdos * multiplica(xd,yi,(size/2),base)) +
			multiplica(xd,yd,(size/2),base));
			
	return resultado;
	}
}

void dec_bin(int decimal){
	int i;
	if(decimal == 1){
		binario[0] = 1;
		i=1;
	}
	if(decimal == 0){
		binario[0] = 0;
		i=0;
	}
	else{
		for(i=0; decimal != 1 ;i++){
			binario[i] = decimal % 2;
			decimal = decimal/2;
			if(decimal == 1){
				binario[i+1] = 1;
			}
		}
	}
	for(int j=i;j>=0;j--){
		cout<<binario[j];
	}
}

string decimal_binstr(int numero){
    string binario = "";
    if (numero > 0) {
        while (numero > 0) {
            if (numero%2 == 0) {
                binario = "0"+binario;
            } else {
                binario = "1"+binario;
            }
            numero = (int) numero/2;
        }
    } else if (numero == 0) {
        binario = "0";
	}
	return binario;
}

void recibedecimal(){
	string bin1,bin2,subbin1,subbin2;
	int lonbin1,lonbin2,num1,num2;
	cout<<"Ingrese el primer numero ";
	cin>>num1;
	cout<<"\nIngrese el segundo numero ";
	cin>>num2;
	bin1 = decimal_binstr(num1);
	bin2 = decimal_binstr(num2);
	lonbin1 = bin1.size();
	lonbin2 = bin2.size();
	lon = espotdos(max(lonbin1,lonbin2));
	bin1 = convpotdos(lonbin1,lon,bin1);
	bin2 = convpotdos(lonbin2,lon,bin2);
	
	for(int k=0;k<bin1.size();k++){
		binario1[k] = bin1[k]-48;
	}
	
	for(int k=0;k<bin2.size();k++){
		binario2[k] = bin2[k]-48;
	}
}

int hex_dec(){
	char  NroHexa[100];
    char Aux[2];
    int  i, Error;
    int NroDec;
    long PosMult;
 
    gets( NroHexa );
    for( Error = 0, i = strlen(NroHexa) - 1; i>=0; i--)
        {
        if( !( ( NroHexa[i] >= 'A' && NroHexa[i] <= 'F' ) ||
               ( NroHexa[i] >= 'a' && NroHexa[i] <= 'f' ) ||
               ( NroHexa[i] >= '0' && NroHexa[i] <= '9' ) ) )
            {
            Error = 1;
            break;
            }
        }
 
    if( !Error )
        {
        for( NroDec = 0, i = strlen(NroHexa) - 1; i>=0; i--)
            {
            PosMult = (long)pow( 16, (strlen(NroHexa) - 1 - i) );
            if( PosMult == 0 )
                PosMult = 1;
            switch( NroHexa[i] )
                {
                case 'A':
                case 'a':
                    NroDec += 10 * PosMult;
                    break;
                case 'B':
                case 'b':
                    NroDec += 11 * PosMult;
                    break;
                case 'C':
                case 'c':
                    NroDec += 12 * PosMult;
                    break;
                case 'D':
                case 'd':
                    NroDec += 13 * PosMult;
                    break;
                case 'E':
                case 'e':
                    NroDec += 14 * PosMult;
                    break;
                case 'F':
                case 'f':
                    NroDec += 15 * PosMult;
                    break;
                default:
                    Aux[0] = NroHexa[i];
                    Aux[1] = '\0';
                    NroDec += atoi( Aux ) * PosMult;
                    break;
                }
            }
        }
        return NroDec;
}

void recibehexadecimal(){
	string bin1,bin2,subbin1,subbin2;
	int lonbin1,lonbin2,num1,num2;
	cout<<"Ingrese el primer numero ";
	fflush(stdin);
	num1 = hex_dec();
	cout<<"\nIngrese el segundo numero ";
	num2 = hex_dec();
	bin1 = decimal_binstr(num1);
	bin2 = decimal_binstr(num2);
	lonbin1 = bin1.size();
	lonbin2 = bin2.size();
	lon = espotdos(max(lonbin1,lonbin2));
	bin1 = convpotdos(lonbin1,lon,bin1);
	bin2 = convpotdos(lonbin2,lon,bin2);
	
	for(int k=0;k<bin1.size();k++){
		binario1[k] = bin1[k]-48;
	}
	
	for(int k=0;k<bin2.size();k++){
		binario2[k] = bin2[k]-48;
	}
}

void dec_hex(int mynum){

	cout.unsetf(ios::dec);
	cout.setf(ios::hex | ios::showbase);
	cout << mynum;
	cout.unsetf(ios::hex);

}



