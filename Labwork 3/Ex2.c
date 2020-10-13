#include <stdio.h>
#include <stdlib.h>


struct Node {
	int data;
	struct Node* pnext;
} Node;

struct Node*front =NULL;
struct Node*rear= NULL;

void Bapcai(int x) {
	struct Node* node = (struct Node*)(malloc(sizeof*node));
	node->data=x;
	node->pnext=NULL;
	
	if(front==NULL && rear==NULL){
		front=rear=node;
		return;
	}
	
	rear->pnext=node;
	rear=node;
}

void Thitrang() {
	struct Node* temp= front;
	if (front==NULL) {
		printf("The queue is empty");
	}
	
	if (front==rear) {
		printf("Person %d is served ",temp->data);
		front=rear=NULL;
	}
	
	else {
		printf("Person %d is served ",temp->data);	
		front=front->pnext;
    }
	free(temp);
}

void display() {
	
	
	struct Node* temp=front;
	if (front==NULL) {
		printf("The queue is empty");
	}
	
	else {
		printf("The queue is ");
	while (temp!= NULL) {
		
		printf("%d ",temp->data);
		temp=temp->pnext;
	}
}
}

int main(int argc, char *argv[]) {
	int n,choice;
	printf("Enter the number of people waiting in the queue ");
	scanf("%d",&n);
	
	int i,option;
	
	for (i=0; i<n; i++) {
		Bapcai(i+1);
	}
	
	display(n);
	
	printf("\nDo you want to continue? Enter 1 for Yes or 0 for No ");
	scanf("%d",&option);
	
	if (option==1) {
	
	do {
		choice=0;
		printf("\nEnter 1 to serve some people");
		printf("\nEnter 2 to add some people to the queue");
		printf("\nEnter 3 to display the queue");
		printf("\nEnter 0 to quit ");
		scanf("%d",&choice);
	
	if (choice==1) {
		int serve;
		printf("How many person do you want to serve? ");
		scanf("%d",&serve);
			
		int j;
		for (j=0; j<serve; j++) 
		 Thitrang();
	}
	
	if (choice==2) {
		int add;
		printf("How many person do you want to add? ");
		scanf("%d",&add);
		
		int k;
		for (k=0;k<add;k++) {
		
		i=i+1;
		Bapcai(i);
	}
	}
	
	if (choice==3) {
		display();
	}
	
	if (choice==0) {
		break;
	}
	

	printf("\nDo you want to continue? Enter 1 for Yes or 0 for No ");
	scanf("%d",&option);
	
	}
	while (option==1);
}
	
	return 0;
}
