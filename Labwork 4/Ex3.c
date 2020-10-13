#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct Node {
	int data;
	struct Node* pnext;
} Node;

struct Node* phead=NULL;

void initNode(int data) {

	struct Node *node=(struct Node*)(malloc(sizeof*node));
	node->data=data;
	
	if (phead==NULL) 
		node->pnext=NULL;
	
	else 
		node->pnext=phead;
	phead=node;
}

void display() {
struct Node * temp=phead;
	if (temp==NULL) {
		printf("List is empty");
}
	else { while (temp!=NULL) {
	
	printf("%d",temp->data);
	temp=temp->pnext;
}
}
}

int sum(struct Node *phead) {
	if (phead==NULL) return 0;
	else
	return phead->data+sum(phead->pnext);
}
int main(int argc, char *argv[]) {
	int bapcai,thitrang;
	
	printf("Enter the number of elements in the list ");
	scanf("%d",&bapcai);
	
	int i;
	for (i=0;i<bapcai;i++) {
		printf("Enter the element number %d ",i+1);
		scanf("%d",&thitrang);
		initNode(thitrang);
	}
	
	printf("Sum of list: %d",sum(phead));
	return 0;
}
