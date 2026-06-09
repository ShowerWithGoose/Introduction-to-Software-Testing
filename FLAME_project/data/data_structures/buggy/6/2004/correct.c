#include <stdio.h>
#include <stdlib.h>
typedef struct node{
	int date;
	struct node *link;
}node;
typedef struct node *nodeptr;
nodeptr top;  
void inti(){
	top = NULL;
}
nodeptr isempty()
{
	return top == NULL;
}
void push(int item)
{
	
	nodeptr p;
	if((p=(nodeptr)malloc(sizeof(node)))==NULL){
		printf("error ");
		
	}else{
		p->date=item;
		p->link=top;
		top=p;
	}
}
int pop()
{
	nodeptr p;
	int item;
	if(isempty()){printf("error ");
	}else{p=top;
	item=top->date;
	top=top->link;
	free(p);
	printf("%d ",item);
	return item;
	}
}
int main()
{
	int n,item,out;
	inti();
	while(scanf("%d",&n)!=-1)
	{
		switch(n)
		{
			case 1:scanf("%d",&item);push(item);break;
			case 0:pop();break;
		}
	}
	return 0;
}

