#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
	int data;
	struct Node* next;
  }  Node;
  
  Node* init()
  {
  	Node* S=(Node*)malloc(sizeof(Node));
  	S->data=0;
  	S->next=NULL;
  	return S;
  }
  
  int judge(Node* S)
  {
  	if(S->data==0||S->next==NULL)
  	{
  		return 1;
	  }
	  else{
	  	return 0;
	  }
  	
  }
  
  void pop(Node *L) {
    if (L->data == 0) {
        printf("error ");
    } else {
        Node *node = L->next;
        int data = node->data;
        L->next = node->next;
        free(node);
        L->data--;
        printf("%d ",data);
    }
}
  
  void push(Node*S,int data)
  {
  	Node* node=(Node *)malloc(sizeof(Node));
  	node->data = data;
  	node->next=S->next;
  	S->next =node;
  	S->data++;
  }
  
  void printS(Node*S)
  {
  	Node* node=S->next;
	  while(node) 
	  {
	  	printf("%d ", node->data);
	  	node=node->next;
	  }
  }
int main()
{
    Node*S=init();
    int a;
    while(a!=-1)
    {
    scanf("%d",&a);
 if(a!=0&&a!=1&&a!=-1)
    {
    	push(S,a);    	
	}
 if(a==0)
	{
		pop(S);
	}
}


}


