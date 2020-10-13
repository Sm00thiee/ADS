#include<iostream>
using namespace std;

void number(float &a, float &b, float &c, float &d){
	c = a + b;
	d = a * b;
}


void charac(char &a, char &b, char &c, char &d){
	c = a + b;
	d = a * b;
}


int main(){
	int n;
	cout<<"Type of input: "<<endl;
	cout<<"1 = numbers, 2 = characters"<<endl;
	cin>>n;
	if (n == 1){
		float x,y,c,d;
		cout<<"Enter input: ";
		cout<<"x = ";
		cin>>x;
		cout<<"             y = ";
		cin>>y;
		number(x, y, c, d);
		cout<<"Sum = "<<c<<endl;
		cout<<"Product = "<<d<<endl;
	}
	else if(n == 2){
		char x,y,c,d;
		cout<<"Enter input: ";
		cout<<"x = ";
		cin>>x;
		cout<<"             y = ";
		cin>>y;
		charac(x, y, c, d);
		cout<<"Sum = "<<c<<endl;
		cout<<"Product = "<<d<<endl;	
	}
}
