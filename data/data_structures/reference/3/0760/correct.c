#include<stdio.h>
#include<string.h>
int main()
{
	char a[200];
	int n,i,k,m;
	gets(a);
	n=strlen(a);
	for(i=0;i<n;i=i+1)
	{
		if(a[i]=='.')
		{
			if(i==1)
			{
				if(a[i-1]=='0')
				{
					for(k=i+1;k<n;k=k+1)
					{
						if(a[k]!='0')
						{
							printf("%c",a[k]);
							if(a[k+1]!=0)
							{
								printf(".");
								m=k+1;
								while(a[m]!=0)
								{
									printf("%c",a[m]);
									m=m+1;
								}
								printf("e-%d",k-i);
								return 0;
							}
							if(k+1==n)
							{
								printf("e-%d",k-i);
								return 0;
							}
						}
					}
				}
				if(a[i-1]!='0')
				{
					for(k=0;k<n;k=k+1)
					{
						printf("%c",a[k]);
					}
					printf("e0");
					return 0;
				}
			}
			else
			{
				m=i;
				printf("%c.",a[0]);
				for(k=1;a[k]!='.';k=k+1)
				{
					printf("%c",a[k]);
				}
				for(k=k+1;k<n;k=k+1)
				printf("%c",a[k]);
				printf("e%d",m-1);
				return 0;
			}
		}
	}
}

