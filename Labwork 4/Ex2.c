#include<stdio.h>
#include<stdlib.h>

int isprime(int x, int n = 2){
    if (x <= 2)
        return (x == 2) ? true : false;
    if (x % n == 0)
        return false;
    if (n * n > x)
        return true;

    return isprime(x, i + 1);
}

int main(){
	int carot;
	printf("Input n: ");
	scanf("%d", &carot);
	for (int i = 0; i <= n; i++){
		if (isprime(carot)){
			printf("Yes");
		}
		else{
			printf("No");
		}
	}
}
