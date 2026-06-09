#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
int s[105];
int top=-1;
int main()
{ 
    int op,t;
    while(1)
    {
    	scanf("%d",&op);
		if(op==-1) break;
		else if(op==0)
		{
			if(top==-1) printf("error ");
			else printf("%d ",s[top--]); 
		}
		else if(op==1)
		{
			scanf("%d",&t);
			if(top==99) printf("error ");
			else s[++top]=t;
		}
	}
	return 0;
}



