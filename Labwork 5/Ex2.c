#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct Node {
	int data;
	struct Node *pnext;
} Node;

struct Node* phead=NULL;

void initNode(int data) {
	struct Node* node = (struct Node*)(malloc(sizeof*node));
	node->data=data;
	
	if (phead==NULL) {
		node->pnext=NULL;
	}
	else
		node->pnext=phead;
		phead=node;
}

void divide(struct Node*head, struct Node**front, struct Node**back) {
	/* devide the linked list into 2 parts using 2 pointers */
	struct Node* firstptr;
	struct Node* secondptr;
	
	if (head==NULL || head->pnext==NULL) {
		*front=head;
		*back=NULL;
	}
	
	else 
	
	{	firstptr=head;
		secondptr=head->pnext;
		while(secondptr!=NULL) {
			secondptr=secondptr->pnext;
			if (secondptr!=NULL) {
				secondptr=secondptr->pnext;
				firstptr=firstptr->pnext;
			}
		}
	}
	
	*front=head;
	*back=firstptr->pnext;
	firstptr->pnext=NULL;
}

struct Node* mergepartition(struct Node* a, struct Node*b) {
	if (a==NULL) return b;
	if (b==NULL) return a;
	/* compare 2 elements and pick the smaller one */
	struct Node* merged= NULL;
	
	if (a->data<=b->data) {
		merged=a;
		merged->pnext=mergepartition(a->pnext,b);
	} else
	
	{
		merged=b;
		merged->pnext=mergepartition(a,b->pnext);
	}
	
	return merged;
}

void mergesort(struct Node** head2) {
	struct Node* head=*head2;
	struct Node* a=NULL;
	struct Node* b=NULL;
	
	if (head==NULL || head->pnext==NULL) return;
	
	divide(head,&a,&b);
	mergesort(&a);
	mergesort(&b);
	
	*head2=mergepartition(a,b);
}

void display() {
struct Node * temp=phead;
printf("The sorted linked list is: ");
	if (temp==NULL) {
		printf("List is empty");
}
	

	else { while (temp!=NULL) {
	
	printf("%d ",temp->data);
	temp=temp->pnext;
}
}
}


int main(int argc, char *argv[]) {
	printf("Enter the number of element in the linked list ");
	int n;
	int data;
	scanf("%d",&n);
	printf("\n");
	
	int i;
	for (i=0; i<n; i++) {
		printf("Enter the element number %d ",i+1);
		scanf("%d",&data);
		initNode(data);
	}
	printf("\n");
	
	mergesort(&phead);
	printf("The sorted linked list is: ");
	display();
	
	printf("\n");
	printf("\n");
	printf("The complexity of this algorithm is O(log(n))");
	return 0;
}
