#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
	char can;
	struct Node *pnext;
} *top=NULL;


void push(char can) {
	struct Node *node;
	node = (struct Node*)(malloc(sizeof*node));
	node->can=can;
	
	if (top == NULL) {
		node->pnext=NULL;
	}
	else
		node->pnext=top;
	top=node;
	printf("%c is pushed\n",node->can);
}

void pop()
{	

   if(top == NULL)
      printf("\nStack is empty\n");
   else{
      struct Node *temp = top;
    
      printf("%c", temp->can);
      top = temp->pnext;
      free(temp);
   }
}


int main(int argc, char *argv[]) {
	char str[50];
	printf("Enter name ");
	gets(str);
	
	int length=strlen(str);
	int i;
	
	for (i=0;i<length;i++) {
		push(str[i]);
	}
	
	 printf("The reverse name is : ");
	for (i=0;i<length;i++) {
		pop();
	}

	
	return 0;
}
