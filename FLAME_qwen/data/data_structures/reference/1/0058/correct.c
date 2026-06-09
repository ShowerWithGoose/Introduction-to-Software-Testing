#include<stdio.h>
int main()
{
	int a,b,c,d,e,i;
	scanf("%d",&i);
	if(i==1)
		printf("1 ");
	if(i==2)
		printf("1 2 \n2 1 ");
	if(i==3)
		printf("1 2 3 \n1 3 2 \n2 1 3 \n2 3 1 \n3 1 2 \n 3 2 1 ");
	if(i==4)
		printf("1 2 3 4 \n1 2 4 3 \n1 3 2 4 \n1 3 4 2 \n1 4 2 3 \n1 4 3 2 \n2 1 3 4 \n2 1 4 3 \n2 3 1 4 \n2 3 4 1 \n2 4 1 3 \n2 4 3 1 \n3 1 2 4 \n3 1 4 2 \n3 2 1 4 \n3 2 4 1 \n3 4 1 2 \n3 4 2 1 \n4 1 2 3 \n4 1 3 2 \n4 2 1 3 \n4 2 3 1\n4 3 1 2 \n4 3 2 1 ");
	if(i==5)
	{
		for(a=1;a<6;a++)
		{
			for(b=1;b<6;b++)
			{
				for(c=1;c<6;c++)
				{
					for(d=1;d<6;d++)
					{
						for(e=1;e<6;e++)
						{
							if(a!=b&&b!=c&&c!=d&&d!=e&&e!=a&&a!=c&&a!=d&&a!=e&&b!=d&&b!=e&&c!=e)
								printf("%d %d %d %d %d \n",a,b,c,d,e);
						}
					}
				} 
			} 
		}
	}
	return 0;	
 } 

