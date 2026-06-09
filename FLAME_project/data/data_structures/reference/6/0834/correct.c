#include<stdio.h>
#define MAXSIZE 100
int s[MAXSIZE];
int top=-1;
void push(int s[],int m);
void pop(int s[]);
int main()
{
	int n,m;
	while((scanf("%d",&n))!=EOF){
		if(n==1){
		scanf("%d",&m);
		push(s,m);
	    }
	    if(n==0){
		pop(s);
	    }
	    if(n==-1)
	    return 0;
	}
	return 0;
 } 
 void push(int s[],int m)
 {
 	if(top==MAXSIZE-1)
 	printf("error ");
 	else
 	s[++top]=m;
 }
 void pop(int s[])
 {
 	if(top==-1){
 		printf("error ");
	}
 	else
 	printf("%d ",s[top--]);
 }

