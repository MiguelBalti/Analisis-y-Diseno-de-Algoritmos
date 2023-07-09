#include<iostream>
using namespace std;

struct bases{
	int n1;
	int n2;
}base[100];
int mult(bases, bases);
bases nueva(bases,bases,bases);
void tresmat();
void fourmat();
void fivemat();
void res(bases m1);
int min(int,int);
void color(int,int);
int i=0;
int main(){
	int matrices;
	system("CLS");
	cout<<"Ingrese el numero de matrices: ";
	cin>>matrices;
	
	for(i=0;i<matrices;i++){
		cout<<"Ingrese el orden de su matriz: ";
		cin>>base[i].n1>>base[i].n2;
	}
	
	switch(matrices){
		case 3:
			tresmat();
			break;
		case 4:
			fourmat();
			break;
		case 5:
			fivemat();
			break;
			
	}
	return 0;
}

bases nueva(bases m1,bases m2){
	bases j;
	j.n1 = m1.n1;
	j.n2 = m2.n2;
	return j;
}
int mult(bases m1,bases m2){
	int mu = m1.n1 * m1.n2;
	return mu * m2.n2;
}

void res(bases m1){
	cout<<m1.n1<<"x"<<m1.n2;
	cout<<" ";
}

int min(int a,int b){
	if(a < b) return a;
	else return b;
}

void color(int a,int b){
	if(a == b){
		printf("\033[0;31m");
	}
}
	
void tresmat(){
	int b1,c2,c1a,c1b;
	b1 = mult(base[0],base[1]);
	base[i] = nueva(base[0],base[1]);
	c1a = mult(base[i],base[2]);
	c2 = mult(base[1],base[2]);
	i++;
	base[i] = nueva(base[1],base[2]);
	c1b = mult(base[0],base[i]);
	
	if(min((c1b+c2),(c1a+b1)) == (c1a+b1) ){
		printf("\033[0;31m");
		cout<<endl<<"(AB)"<<"C"<<"-> "<<c1a+b1;printf("\033[0m");
	}
	else{
		printf("\033[0;31m");
		cout<<"\n\tA"<<"(BC)"<<"-> "<<c1b+c2;printf("\033[0m");
	}
	
	cout<<"\n________________________________________________________________"<<endl;
	cout<<"   |  \t A"<<"\t          B"<<"\t               C";
	cout<<"\n----------------------------------------------------------------";
	cout<<"\nA  |     X       ";       
	cout<<"A";res(base[0]);cout<<"B";res(base[1]);cout<<"-> "<<b1; 
	color(min((c1b+c2),(c1a+b1)),c1a+b1);
	cout<<"\t(AB)";res(base[3]);cout<<"C";res(base[2]);cout<<"-> "<<c1a+b1;printf("\033[0m");
	cout<<endl<<"   |";
	color(min((c1b+c2),(c1a+b1)),c1b+c2);
	cout<<"\t\t\t\t\tA";res(base[0]);cout<<"(BC)";res(base[4]);cout<<"-> "<<c1b+c2;printf("\033[0m");
	cout<<"\n----------------------------------------------------------------";
	cout<<"\nB  |     X                X         ";       
	cout<<"\tB";res(base[1]);cout<<"C";res(base[2]);cout<<"-> "<<c2;  
	cout<<"\n----------------------------------------------------------------";
	cout<<"\nC  |     X                X      \t    X         "<<endl;       
	cout<<"________________________________________________________________"<<endl;
}

void fourmat(){
	int b1,c2,c1a,c1b,j,d3,k,d2b,d2a,d1a,d1b;
	b1 = mult(base[0],base[1]);
	//4
	base[i] = nueva(base[0],base[1]);
	c1a = mult(base[i],base[2]);
	i++; //5
	base[i] = nueva(base[4],base[2]);
	c2 = mult(base[1],base[2]);
	i++;//6
	base[i] = nueva(base[1],base[2]);
	c1b = mult(base[0],base[i]);
	i++;//7
	base[i] = nueva(base[0],base[6]);
	
	if(min((c1a+b1),(c1b+c2)) == (c1a+b1) ){
		j = 5;
	}
	else{
		j = 7;
	}
	d3 = mult(base[2],base[3]);
	i++; //8
	base[i] = nueva(base[2],base[3]);
	d2b = mult(base[1],base[i]);
	i++; //9
	base[i] = nueva(base[1],base[8]);
	d2a = mult(base[6],base[3]);
	i++; //10
	base[i] = nueva(base[6],base[3]);
	
	if(min((c2+d2a),(d3+d2b)) == (c2+d2a) ){
		k = 10;
	}
	else{
		k = 9;
	}
	
	d1a = mult(base[j],base[3]);
	i++; //11
	base[i] = nueva(base[j],base[3]);
	d1b = mult(base[0],base[k]);
	i++;//12
	base[i] = nueva(base[0],base[k]);
	
	if(min((c2+c1b+d1a),(c2+d2a+d1b)) == (c2+c1b+d1a) ){
		printf("\033[0;31m");
		cout<<endl<<"(A(BC))"<<"D"<<"-> "<<c2+c1b+d1a;printf("\033[0m");
	}
	else{
		printf("\033[0;31m");
		cout<<"\n\tA"<<"((BC)D)"<<"-> "<<c2+d2a+d1b;printf("\033[0m");
	}
	cout<<"\n____________________________________________________________________________________________________"<<endl;
	cout<<"   |  \t A"<<"\t          B"<<"\t               C"<<"\t                       D";
	cout<<"\n----------------------------------------------------------------------------------------------------";
	cout<<"\nA  |     X       ";       
	cout<<"A";res(base[0]);cout<<"B";res(base[1]);cout<<"-> "<<b1; 
	color(min((c1b+c2),(c1a+b1)),c1a+b1);
	cout<<"\t(AB)";res(base[4]);cout<<"C";res(base[2]);cout<<"-> "<<c1a+b1;printf("\033[0m");
	color(min((c2+c1b+d1a),(c2+d2a+d1b)),c2+c1b+d1a);	
	cout<<"\t(A(BC))";res(base[j]);cout<<" D";res(base[3]);cout<<"-> "<<c2+c1b+d1a;printf("\033[0m");
	cout<<endl<<"   |";
	color(min((c1b+c2),(c1a+b1)),c1b+c2);
	cout<<"\t\t\t\t\tA";res(base[0]);cout<<"(BC)";res(base[5]);cout<<"-> "<<c1b+c2;printf("\033[0m");
	color(min((c2+c1b+d1a),(c2+d2a+d1b)),c2+d2a+d1b);	
	cout<<"\t\tA";res(base[0]);cout<<"((BC)D)";res(base[k]);cout<<"-> "<<c2+d2a+d1b;printf("\033[0m");
	cout<<"\n----------------------------------------------------------------------------------------------------";
	cout<<"\nB  |     X                X         ";       
	cout<<"\tB";res(base[1]);cout<<"C";res(base[2]);cout<<"-> "<<c2;  
	color(min((c2+d2a),(d3+d2b)),c2+d2a);
	cout<<"\t\t(BC)";res(base[6]);cout<<"D";res(base[3]);cout<<"-> "<<c2+d2a;printf("\033[0m");
	cout<<endl<<"   |";
	color(min((c2+d2a),(d3+d2b)),d3+d2b);
	cout<<"\t\t\t\t\t\t\t\t\tB";res(base[1]);cout<<"(CD)";res(base[8]);cout<<"-> "<<d3+d2b;printf("\033[0m");
	cout<<"\n----------------------------------------------------------------------------------------------------";
	cout<<"\nC  |     X                X      \t\t    X         ";  
	cout<<"\t\tC";res(base[2]);cout<<"D";res(base[3]);cout<<"-> "<<d3<<endl; 
	cout<<"----------------------------------------------------------------------------------------------------";
	cout<<"\nD  |     X                X      \t\t    X      \t\t\t    X"; 
	cout<<"\n____________________________________________________________________________________________________"<<endl; 
}

void fivemat(){
	int b1,c2,c1a,c1b,j,d3,k,d2b,d2a,d1a,d1b,e4,e3b,e3a,e2b,e2a,e1b,l,m,n,e1a;
	b1 = mult(base[0],base[1]);
	//5
	base[i] = nueva(base[0],base[1]);
	c1a = mult(base[i],base[2]);
	i++; //6
	base[i] = nueva(base[5],base[2]);
	c2 = mult(base[1],base[2]);
	i++;//7
	base[i] = nueva(base[1],base[2]);
	c1b = mult(base[0],base[i]);
	i++;//8
	base[i] = nueva(base[0],base[7]);
	
	if(min((c1a+b1),(c1b+c2)) == (c1a+b1) ){
		j = 6;
	}
	else{
		j = 8;
	}
	d3 = mult(base[2],base[3]);
	i++; //9
	base[i] = nueva(base[2],base[3]);
	d2b = mult(base[1],base[i]);
	i++; //10
	base[i] = nueva(base[1],base[9]);
	d2a = mult(base[7],base[3]);
	i++; //11
	base[i] = nueva(base[7],base[3]);
	
	if(min((c2+d2a),(d3+d2b)) == (c2+d2a) ){
		k = 11;
	}
	else{
		k = 10;
	}
	
	d1a = mult(base[j],base[3]);
	i++; //12
	base[i] = nueva(base[j],base[3]);
	d1b = mult(base[0],base[k]);
	i++;//13
	base[i] = nueva(base[0],base[k]);
	if(min((c2+c1b+d1a),(c2+d2a+d1b)) == (c2+c1b+d1a) ){
		l = 12;
	}
	else{
		l = 13;
	}
	e4 = mult(base[3],base[4]);
	i++;//14
	base[i] = nueva(base[3],base[4]);
	e3b = mult(base[2],base[i]);
	i++;//15
	base[i] = nueva(base[2],base[14]);
	e3a = mult(base[9],base[4]);
	i++;//16
	base[i] = nueva(base[9],base[4]);
	
	if(min((d3+e3a),(e4+e3b)) == (d3+e3a) ){
		m = 16;
	}
	else{
		m = 15;
	}	
	e2b = mult(base[1],base[m]);
	i++;//17
	base[i] = nueva(base[1],base[m]);
	e2a = mult(base[k],base[4]);
	i++;//18
	base[i] = nueva(base[k],base[4]);
	if(min((c2+d2a+e2a),(d3+e3b+e2b)) == (c2+d2a+e2a) ){
		n = 18;
	}
	else{
		n = 17;
	}
	e1b = mult(base[0],base[n]);
	e1a = mult(base[l],base[4]);	
	
	if(min((c2+c1b+d1a+e1a),(c2+d2a+e2a+e1b)) == (c2+c1b+d1a+e1a) ){
		printf("\033[0;31m");
		cout<<endl<<"((A(BC))D)"<<"E"<<"-> "<<c2+c1b+d1a+e1a;printf("\033[0m");
	}
	else{
		printf("\033[0;31m");
		cout<<"\n\tA"<<"(((BC)D)E)"<<"-> "<<c2+d2a+e2a+e1b;printf("\033[0m");
	}

	cout<<"\n____________________________________________________________________________________________________________________________________"<<endl;
	cout<<"   |  \t A"<<"\t          B"<<"\t               C"<<"\t                       D"<<"\t                       E";
	cout<<"\n------------------------------------------------------------------------------------------------------------------------------------";
	cout<<"\nA  |     X       ";       
	cout<<"A";res(base[0]);cout<<"B";res(base[1]);cout<<"-> "<<b1; 
	color(min((c1b+c2),(c1a+b1)),c1a+b1);
	cout<<"\t(AB)";res(base[4]);cout<<"C";res(base[2]);cout<<"-> "<<c1a+b1;printf("\033[0m");
	color(min((c2+c1b+d1a),(c2+d2a+d1b)),c2+c1b+d1a);	
	cout<<"\t\t(A(BC))";res(base[j]);cout<<" D";res(base[3]);cout<<"-> "<<c2+c1b+d1a;printf("\033[0m");
	color(min((c2+c1b+d1a+e1a),(c2+d2a+e2a+e1b)),(c2+c1b+d1a+e1a));	
	cout<<"\t\t((A(BC))D)";res(base[l]);cout<<" E";res(base[4]);cout<<"-> "<<c2+c1b+d1a+e1a;printf("\033[0m");
	cout<<endl<<"   |";
	color(min((c1b+c2),(c1a+b1)),c1b+c2);
	cout<<"\t\t\t\t\tA";res(base[0]);cout<<"(BC)";res(base[5]);cout<<"-> "<<c1b+c2;printf("\033[0m");
	color(min((c2+c1b+d1a),(c2+d2a+d1b)),c2+d2a+d1b);	
	cout<<"\t\tA";res(base[0]);cout<<"((BC)D)";res(base[k]);cout<<"-> "<<c2+d2a+d1b;printf("\033[0m");
	color(min((c2+c1b+d1a+e1a),(c2+d2a+e2a+e1b)),(c2+d2a+e2a+e1b));	
	cout<<"\t\tA";res(base[0]);cout<<"(((BC)D)E)";res(base[n]);cout<<"-> "<<c2+d2a+e2a+e1b;printf("\033[0m");
	cout<<"\n------------------------------------------------------------------------------------------------------------------------------------";
	cout<<"\nB  |     X                X         ";       
	cout<<"\tB";res(base[1]);cout<<"C";res(base[2]);cout<<"-> "<<c2;  
	color(min((c2+d2a),(d3+d2b)),c2+d2a);
	cout<<"\t\t\t(BC)";res(base[6]);cout<<"D";res(base[3]);cout<<"-> "<<c2+d2a;printf("\033[0m");
	color(min((c2+d2a+e2a),(e4+e3b+e2b)),(c2+d2a+e2a));
	cout<<"\t\t((BC)D)";res(base[k]);cout<<"E";res(base[4]);cout<<"-> "<<c2+d2a+e2a;printf("\033[0m");
	cout<<endl<<"   |";
	color(min((c2+d2a),(d3+d2b)),d3+d2b);
	cout<<"\t\t\t\t\t\t\t\t\tB";res(base[1]);cout<<"(CD)";res(base[8]);cout<<"-> "<<d3+d2b;printf("\033[0m");
	color(min((c2+d2a+e2a),(e4+e3b+e2b)),(e4+e3b+e2b));
	cout<<"\t\tB";res(base[1]);cout<<"((CD)E)";res(base[m]);cout<<"-> "<<e4+e3b+e2b;printf("\033[0m");
	cout<<"\n------------------------------------------------------------------------------------------------------------------------------------";
	cout<<"\nC  |     X                X      \t\t    X         ";  
	cout<<"\t\tC";res(base[2]);cout<<"D";res(base[3]);cout<<"-> "<<d3;
	
	color(min((d3+e3a),(e4+e3b+e2b)),(d3+e3a));
	cout<<"\t\t\t(CD)";res(base[9]);cout<<"E";res(base[4]);cout<<"-> "<<d3+e3a;printf("\033[0m");
	cout<<endl<<"   |";
	color(min((d3+e3a),(e4+e3b)),(e4+e3b));
	cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\tC";res(base[2]);cout<<"(DE)";res(base[14]);cout<<"-> "<<e4+e3b;printf("\033[0m");
	cout<<"\n------------------------------------------------------------------------------------------------------------------------------------";
	cout<<"\nD  |     X                X      \t\t    X      \t\t\t    X"; 
	cout<<"\t\t\tD";res(base[3]);cout<<"E";res(base[4]);cout<<"-> "<<e4;
	cout<<"\n------------------------------------------------------------------------------------------------------------------------------------";
	cout<<"\nD  |     X                X      \t\t    X      \t\t\t    X      \t\t    X"; 
	cout<<"\n____________________________________________________________________________________________________________________________________"<<endl;
}

	

