#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
int main()
{
	int TOP=-1,op,item;
	int a[100];
	while(scanf("%d",&op)!=-1)
	{
		if(op==1)
		{
			scanf("%d",&item);
			if(TOP==100)
			printf("error ");
			else
			a[++TOP]=item;
		} 
		else if(op==0)
		{
			if(TOP==-1)
			printf("error ");
			else 
			printf("%d ",a[TOP--]);
		}
	}
	return 0;
}



