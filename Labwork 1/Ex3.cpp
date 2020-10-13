#include<iostream>
#include<Math.h>
using namespace std;

typedef struct Point{
	float x;
	float y;
};
typedef struct Point p1, p2;


int main(){
	struct Point p1,p2;
	cin>>p1.x;
	cin>>p1.y;
	cin>>p2.x;
	cin>>p2.y;
	float c = pow((p2.x - p1.x),2);
	float d = pow((p2.y - p1.y),2);
	float e = sqrt(c+d);
	cout<<e;
}
