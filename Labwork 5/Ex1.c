#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void swap(int *a, int *b) {
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}

void bubblesort(int n, int a[]) {
	int flag=1; 
	int start=0, end=n-1;
	int pass=0;
	
	while (flag==1) {
		int i;
		flag=0;
		for (i=start; i<end; i++) {
			if (a[i]>a[i+1]) {
				swap(&a[i],&a[i+1]);
				flag=1;
				
			}
	    }	
	    printf("Pass %d : | ",pass+1);
		for (i=0;i<n;i++) {
				printf("%d ",a[i]);
	    }	
				printf("\n");	
		
		if (flag==0) break; /* If flag = 0 => no 2 elements were swapped => the array is in order */
		flag=0; /* If not then go from back to front */
		end=end-1;
		pass++;
		int j;
		for (j=end-1; j>=start; j--) {
			if (a[j]>a[j+1]) {
				swap(&a[j],&a[j+1]);
				flag=1;
			}
		
		}	
		printf("Pass %d : | ",pass+1);
		for (i=0;i<n;i++) {
				printf("%d ",a[i]);
	    }	
				printf("\n");
		pass++;
		start=start+1;
	
	}
		
}



int main(int argc, char *argv[]) {

	printf("Enter the number of elements ");
	int n;
	scanf("%d",&n);
	int a[n];
	
	printf("\n");
	
	int i;
	for (i=0;i<n;i++) {
		printf("Enter element number %d ",i+1);
		scanf("%d",&a[i]);
	}
	printf("\n");
	
	bubblesort(n,a);
	printf("\n");
	printf("The sorted array is: ");
	
	for (i=0;i<n;i++) {
		printf("%d ",a[i]);
		
	}
	printf("\n");
	printf("\n");
	printf("The worst and average case scenario, the algorithm must execute\n1 while loop * 1 for loop (n*n times) => complexity = O(n^2)\n");
	printf("\n");
	printf("If the array is already sorted, the algorithm only executes 1 for loop \n=> complexity = O(n)\n");
		return 0;
}
