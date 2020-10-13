#include <stdlib.h>
#include <stdio.h>
 struct node {
    int data;
    struct node *pnext;
};
struct node **top[3];

  
void push(struct node **top, int x) {
    
        struct node *newnode = malloc(sizeof(struct node));
        newnode->data = x;
        newnode->pnext = *top;
        *top = newnode;
    
}

int pop(struct node **top) {
    int temp = 0; 
    struct node *oldnode;

    if (top!= NULL)
    {
        if (*top != NULL)
        {
            oldnode= *top;
            temp = oldnode->data;
            (*top) = oldnode->pnext;
            free(oldnode);
        } 
    } 
    
    return temp;
}

void display(struct node**top) {
	  printf("\n");
	if(*top == NULL)
      printf("--");
   else{
      struct node *temp = *top;
      while(temp != NULL){
	 printf("%d ",temp->data);
	 temp=temp->pnext;
      }	 
   }
}

void TOH(int n, int source, int dest, int temp) 
{ 
    if (n == 1) 
    { 
        printf("\n Move disk 1 from pole %d to pole %d\n", source+1, dest+1); 
        int value=pop(&top[source]);
        push(&top[dest],value);
        display(&top[0]);
      
        display(&top[1]);
        
        display(&top[2]);
        
		return;
    } 
    TOH(n-1, source, temp, dest); 
    printf("\n Move disk %d from pole %d to pole %d\n", n, source+1, dest+1); 
    int value2=pop(&top[source]);
    push(&top[dest],value2);
    display(&top[0]);
      
    display(&top[1]);
        
    display(&top[2]);
  
    TOH(n-1, temp, dest, source); 
} 

int main()
{
 	top[0]=NULL;
 	top[1]=NULL;
	top[2]=NULL;

	printf("Enter number of disks ");
	int disk;
	scanf("%d",&disk);
	
	int i;
	for(i=disk; i>0; i--) {
		push(&top[0],i);
	}
	printf("The original state is: \n");
	
	display(&top[0]);
    display(&top[1]);
    display(&top[2]);

    TOH(disk,0,1,2);
    
    return 0;
}
