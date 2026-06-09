#include <stdio.h>
int main(){
	int op;
	int a[1000],b[1000];
	int count=0,rear=0;
	scanf("%d",&op);
	while(op!=-1)
	{
		if(op==1)
		{
			scanf("%d",&b[rear++]);
			if (count<100&&rear>0)
			{
				a[count++]=b[--rear];
			}
			else
			printf("error ");
		}
		else
		if(count==0)
		printf("error ");
		else
		printf("%d ",a[--count]);
		scanf("%d",&op);
	}
	return 0;
}

