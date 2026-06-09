#include<stdio.h>
#define MAXSIZE 100
int s[MAXSIZE];
int top=-1;
int isFull()
{
    return top==MAXSIZE-1;	
}
int isEmpty()
{
	return top==-1;
}
void  push(int s[MAXSIZE],int item)
{
    if(isFull(s)>0)
    printf("error ");
    else
    s[++top]=item;
}
void pop(int s[MAXSIZE])
{
    if(isEmpty(s)>0)
    printf("error ");
    else
    printf("%d ",s[top--]); 
}
int main()
{
	int n,i=0,len;
	int a[100];
	while(scanf("%d",&n)!=-1)
	{
		a[i]=n;
		i++;
	}
    len=i;
	for(i=0;i<len;i++)
	{
		if(a[i]==1)
		push(s,a[i+1]);
		else if(a[i]==0)
		pop(s);
    }
	return 0;	
}

