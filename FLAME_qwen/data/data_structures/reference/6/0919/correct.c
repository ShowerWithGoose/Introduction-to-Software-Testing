#include<stdio.h>

int main()
{
	int s[107];
	int i=-1,op,count=0;
    scanf("%d",&op);
    while(op != -1)
    {
    	if(op == 1)
    	{
    		if(count == 100) printf("error ");
    		else{
    			scanf("%d",&s[++i]);
    			count++;
			}
		}
		else if(op == 0)
		{
			if(count == 0) printf("error ");
			else{
				printf("%d ",s[i]);
				i--;
				count--;
			}
		}
		scanf("%d",&op);
	}
	return 0;
}


