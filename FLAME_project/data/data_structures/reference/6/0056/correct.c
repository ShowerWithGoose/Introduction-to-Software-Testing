#include<stdio.h>
int a[1000]; 
int main()
{
    int i=0,mark,shujv;
    for(i=0;;)
    {
    	scanf("%d",&mark);
    	if(mark==1)
    	{
    		scanf("%d",&shujv);
    		if(i==100)
    		{
    			printf("error ");
			}
			else
				a[i++]=shujv;
		}
		if(mark==0)
		{
			if(i==0)
			{
				printf("error ");
			}
			else 
				printf("%d ",a[--i]);
		}
		if(mark==-1)
		{
			break;
		}
	}
	return 0;
}


