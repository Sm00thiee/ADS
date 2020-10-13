#include <iostream>
using namespace std;

int main(){
	int num[1000000000];
	int i, sum = 0, n;
	int *ptr;
	cin>>n;
	
	for (i = 0; i < n; i++)
		scanf ("%d", &num[i]);
	ptr = &num[i];
	
	for (i = 0; i < n; i++){
		sum += *ptr;
		ptr++;
	}
	cout<<sum<<endl;
}
