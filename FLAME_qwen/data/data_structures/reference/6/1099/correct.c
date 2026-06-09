#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<memory.h>
#define MAX 1000 



typedef struct stack Stack;
struct stack{
	int cnt;
	int element[MAX];
}s; 


void choose();
void in_stack();
void out_stack();
int main()
{	
	
	choose();
 
return 0;
}

void choose(){
	s.cnt=0;
	int op;
	while(~scanf("%d",&op))
	{
		
		if(op==-1) break;
		else if(op==1)	in_stack();
		else if(op==0) out_stack();
	}
}
	

void in_stack(){
	int n;
	scanf("%d",&n);
	if(s.cnt>=100) printf("error ");
	else
	{ 
	s.element[s.cnt++]=n;
	} 
}

void out_stack(){
	if(s.cnt <1) printf("error ");
	else
	{
	printf("%d ",s.element[--s.cnt]);
	}
	
}


