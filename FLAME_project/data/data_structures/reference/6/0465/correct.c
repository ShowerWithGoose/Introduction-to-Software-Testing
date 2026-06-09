#include<stdio.h>

int main()
{
	int s[101];
	int top=0;
	int a,b;
	while (scanf ("%d",&a) , a != -1)
	{
		switch (a)
		{
			case 1:
				scanf ("%d",&b);
				if (top>=100)
				{
					printf ("error ");
				}
				else 
				{
					s[top]=b;
					top++;
				}
				break;
			case 0:
				if (top<=0)
				{
					printf ("error ");
				}
				else 
				{
					printf ("%d ",s[top-1]);
					top--;
				}
				break;
		}
		/*printf ("top=%d\n",top);
		printf ("Current S is:");
		int i;
		for (i=0;i<=top-1;i++)
		{
			printf ("%d ",s[i]);
		}
		printf ("\n");
		*/
	}
	return 0;	
} 



