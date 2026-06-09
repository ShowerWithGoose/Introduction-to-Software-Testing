#include<stdio.h>
void p(int n)
{
	int a[n+1],lp;
	for(lp=1;lp<n+1;lp++)
	{
		a[lp]=lp;
	}
	if(n==4)
	{
		printf("1 2 3 4\n");
		while(a[1]+a[2]+a[3]+a[4]!=16)
		{
			if(a[4]==4)
			{
				if(a[3]==4)
				{
					if(a[2]==4)
					{
						a[1]++;
						a[2]=1;
					}
					else
					{
						a[2]++;
					}
					a[3]=1;
				}
				else
				{
					a[3]++;
				}
				a[4]=1;
			}
			else
			{
				a[4]++;
			}
			if(a[1]+a[2]+a[3]+a[4]==10&&a[1]*a[2]*a[3]*a[4]==24)
			{
				printf("%d %d %d %d\n",a[1],a[2],a[3],a[4]);
			}
		}
	}
	else
	{
		printf("1 2 3 4 5\n");
		while(a[1]+a[2]+a[3]+a[4]!=25)
		{
			if(a[5]==5)
			{
				if(a[4]==5)
				{
					if(a[3]==5)
					{
						if(a[2]==5)
						{
							a[1]++;
							a[2]=1;
						}
						else
						{
							a[2]++;
						}
						a[3]=1;
						
					}
					else
					{
						a[3]++;
					}
					a[4]=1;
				}
				else
				{
					a[4]++;
				}
				a[5]=1;
			}
			else
			{
				a[5]++;
			}
			if(a[1]+a[2]+a[3]+a[4]+a[5]==15&&a[1]*a[2]*a[3]*a[4]*a[5]==120)
			{
				printf("%d %d %d %d %d\n",a[1],a[2],a[3],a[4],a[5]);
			}
		}
	}
}



int main()
{
	int n;
	scanf("%d",&n);
	if(n==1)
	{
		printf("1\n");
	}
	if(n==2)
	{
		printf("1 2\n");
		printf("2 1\n");
	}
	if(n==3)
	{
		puts("1 2 3");
		puts("1 3 2");
		puts("2 1 3");
		puts("2 3 1");
		puts("3 1 2");
		puts("3 2 1");
	}
	if(n==4)
	{
		p(4);
	}
	if(n==5)
	{
		p(5);
	}
	
	return 0;
}

