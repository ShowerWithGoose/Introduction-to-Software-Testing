#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>



#define MAX_NUM 100


int main()
{
	//freopen("damn.txt","r",stdin);//
	
	int a[MAX_NUM],top;
	memset(a,0,sizeof(a));
	
	top=-1;
	
	int temp;
	int op;
	while(scanf("%d",&op)!=EOF)
	{
		switch(op)
		{
			case -1:return 0;
			
			case 0:
				if(top==-1)
				{
					printf("error ");
				}
				else
				{
					printf("%d ",a[top--]);
				}
				break;
			case 1:
				scanf("%d",&temp);
				if(top==MAX_NUM-1)
				{
					printf("error ");
				}
				else
				{
					a[++top]=temp;
				}
				break;
		}
	}
	
	
	
	
	
	
	
	
	return 0;
}

