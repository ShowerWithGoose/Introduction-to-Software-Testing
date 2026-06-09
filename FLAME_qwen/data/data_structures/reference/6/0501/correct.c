#include <stdio.h> 
int stack[100];
void push(int shu);
void pop();
int top=-1;
int main()
{
	int op,shu,input[100000];
	int i=0;
	int j;
	while(1)
	{
		scanf("%d",&input[i]);
		if(input[i]==-1) break;		
		i++;
	}
		for(j=0;j<=i;j++)
		{
			if(input[j]==0) 
		    {
			    pop();
		    }
		    else if(input[j]!=1)
		    {
			    shu=input[j];
			    push(shu);
		    }			
		}
   return 0;     		
}
void push(int shu)
{
	if(top==99)
	{
		printf("error ");
		return;
	}
	top++;
	stack[top]=shu;
	return;
}
void pop()
{
	if(top==-1)
	{
		printf("error ");
		return;
	}
	printf("%d ",stack[top]);
	top--;
}

