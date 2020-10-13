#include<stdio.h> 

int multiply(int a, int b) {
	if (b==0) return 0;
	if (b>0) return a+multiply(a,b-1);
	if (b<0) return -multiply(a,-b);
}
  
int main(int argc, char *argv[]) {
	printf("Enter 2 integers ");
	int a,b;
	scanf("%d %d",&a,&b);

	printf("%d",multiply(a,b));   
  return 0; 
} 
