#include<stdio.h>
#include<string.h>
int main()
{
	char zf[1000000],a,b,c;
	int i,j,k,t,m;
	gets(zf);
	for(i=0;i<strlen(zf);i++)
	{
		if(zf[i]=='-')
		{
			if(i==0)
			{
				printf("-");
			}
			else
			{
				if(zf[i-1]>='a'&&zf[i-1]<'z')
				{
					if(zf[i+1]>zf[i-1]&&zf[i+1]<='z')
					{
						for(j=1;j<zf[i+1]-zf[i-1];j++)
						{
							a=zf[i-1]+j;
							printf("%c",a);
						}
					}
					else
					{
						printf("-");
					}
				}
				else if(zf[i-1]>='A'&&zf[i-1]<'Z')
				{
					if(zf[i+1]>zf[i-1]&&zf[i+1]<='Z')
					{
						for(k=1;k<zf[i+1]-zf[i-1];k++)
						{
							b=zf[i-1]+k;
							printf("%c",b);
						}
					}
					else
					{
						printf("-");
					}
				}
				else if(zf[i-1]>='0'&&zf[i-1]<'9')
				{
					if(zf[i+1]>zf[i-1]&&zf[i+1]<='9')
					{
						for(t=1;t<zf[i+1]-zf[i-1];t++)
						{
							c=zf[i-1]+t;
							printf("%c",c);
						}
					}
					else
					{
						printf("-");
					}
				}
			}
		}
		else
		{
			printf("%c",zf[i]);
		}
	}
	return 0;
}



