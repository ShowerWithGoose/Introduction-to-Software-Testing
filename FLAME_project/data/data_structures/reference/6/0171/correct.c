#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define maxsize 1000
struct Node
{
	int  data;
	struct Node *next;
};

struct stack
{
	struct Node *stackTop;
	int size;
};

struct Node *createNode(int data)
{
	struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode -> data = data;
	newNode -> next = NULL;
	return newNode; 
}

struct stack *creatStack()
{
	struct stack *myStack = (struct stack*)malloc(sizeof(struct stack));
	myStack -> stackTop = NULL;
	myStack -> size = 0;
	return myStack;
}

void push(struct stack *myStack,int data)
{
	struct Node *newNode = createNode(data);
	newNode -> next = myStack -> stackTop;
	myStack -> stackTop = newNode;
	myStack -> size++;
}

void pop(struct stack *myStack)
{
	if(myStack -> size == 0)
  printf("Stack is empty ! Can't pop !");
	else
	{
	struct Node *nextNode =  myStack -> stackTop -> next;
	free(myStack -> stackTop);
	myStack -> stackTop = nextNode;
	myStack -> size--;
	}
}

int getTop(struct stack *myStack)
{
  if(myStack -> size == 0)
  {
  	printf("Stack is empty !\n");
  	return myStack -> size;
	}
	return myStack -> stackTop -> data;
}

int isEmpty(struct stack *myStack)
{
	if(myStack -> size == 0)
  return 0;
  return 1;
}

int main()
{
  int a[205],i=0,j;
  while(scanf("%d",&a[i])!=EOF)
  i++;
  struct stack *stack1 = creatStack();
  for(j=0;j<i;j++)
  {
  	if(a[j]==1)
  	{
  		push(stack1,a[j+1]);
  		j++;
		}
		else if(a[j]==0)
		{
			if(isEmpty(stack1)==0)
			printf("error ");
			else
			{
			printf("%d ",getTop(stack1));
			pop(stack1);	
			}
		}
	}
}



