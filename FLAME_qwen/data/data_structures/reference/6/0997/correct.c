#include <stdio.h>
#include <string.h>
int main()
{
	int stac[105],i,op,j,n;
	char s[]="error ";
	scanf("%d",&op);
	while(op!=-1)
	{
		
		if(op)
		{
			if(i<99)
			{
			scanf("%d",&n);
			stac[i++]=n;
			}
			else
			{
				printf("%s",s);
			}
		}
		else
		{
			if(i)
			{
				printf("%d ",stac[i-1]);
				i--;
			}	
			else
			printf("%s",s);	
		}
		scanf("%d",&op);
	}
	
	return 0;
	
	
	
	
}

