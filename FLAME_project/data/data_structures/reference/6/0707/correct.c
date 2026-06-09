#include<stdio.h> 
#include<stdlib.h> 
#define MAXSIZE     100
int  s[MAXSIZE];
int top=-1;
int main()
{int op,item;
	while(scanf("%d",&op)!=-1) 
{if(op==1)
{scanf("%d",&item);
if(top==MAXSIZE-1)
printf("error ");
else
s[++top]=item;
}
if(op==0)
{if(top==-1)
printf("error ");
else
{printf("%d ",s[top]);
top--;
}
}

}
	return 0;
}

