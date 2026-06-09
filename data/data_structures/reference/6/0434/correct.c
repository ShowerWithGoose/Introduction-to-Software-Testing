#include <stdio.h>

int main ()
{
	int op,stack[105],i=0;//i是元素个数
	
	scanf ("%d",&op);
	while (op!=-1)
	{
		if (op==1)
		{
			scanf ("%d",&stack[i]);
			i++;
		}
		else if (op==0)
		{
			if (i==0)
				printf ("error ");
			else
			{
				i--;
				printf ("%d ",stack[i]);
			}
		}
		scanf ("%d",&op);
	}
	
	return 0;
}
