#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Node {
	int data;
	struct Node* pnext;
} Node;

struct Node *top=NULL;

void push(int x) {
	struct Node*node=(struct Node*)(malloc(sizeof*node));
	node->data=x;
	
	if (top==NULL) {
		node->pnext=NULL;
	}
	else
	node->pnext=top;
	top=node;
		
}

void pop() {
	if (top==NULL) {
		printf("Stack is empty");
	}
	
	else {
		struct Node*temp=top;
		top=temp->pnext;
		free(temp);
		
	}
}

void display()
{
  
      struct Node *temp = top;
      while(temp->pnext != NULL){
	 printf("%d--->",temp->data);
	 temp = temp -> pnext;
      }
	  printf("%d--->NULL",temp->data);
   }
  
int main(int argc, char *argv[]) {
	int x,n,i;
	int unumber;
	printf("Press enter to draw the 1st number ");
	getchar();
	srand (time(NULL));
	int secret=rand()%9+1;
	
	push(secret);
	printf("Done\n");
	printf("Press enter to continue drawing the 2nd number ");
	getchar();
	int secret2=rand()%9+1;
		

	while (secret==secret2) {
	
		printf("2 numbers are the same, re-draw\n");
		getchar();
		secret2=rand()%9+1;
			
		
	}
	
	push(secret2);
		printf("Done\n");
	

	printf("\n");
	printf("\n");
	printf("Enter your number (3rd number) ");
	scanf("%d",&unumber);
	
	if ((unumber>secret && unumber<secret2) || (unumber>secret2 && unumber<secret)) {
		printf("YOU WON\n");
		printf("The 2 numbers are %d and %d ",secret,secret2);
	} 
	else {
		
		pop();
		printf("Your number was incorrect\n");
		printf("Press enter to re-draw the 2nd number ");
		getchar();
		getchar();
		int secret2=rand()%9+1;
			

	
		while (secret==secret2) {
	
			printf("2 numbers are the same, re-draw\n");
			getchar();
			secret2=rand()%9+1;
			
		
		}
		push(secret2);
		printf("Done\n");
		printf("Re-enter your number (3rd number) ");
		scanf("%d",&unumber);
		if ((unumber>secret && unumber<secret2) || (unumber>secret2 && unumber<secret)) {
		printf("YOU WON\n");
		printf("The 2 numbers are %d and %d ",secret,secret2);
	} 
	else {
	printf("YOU LOST\n");
	printf("The 2 numbers are %d and %d ",secret,secret2);
	}

}

	return 0;
}
