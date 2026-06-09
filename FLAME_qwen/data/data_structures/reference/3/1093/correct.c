#include<stdio.h>
#include<string.h>
char a[108];
int main()
{
	int i=0,j,cnt=0,f=0,mark=0,k,t=0;
	gets(a);
	if(a[0]=='-')
	{
		printf("-");
		i=1;
	}
	if(a[i]=='0')
	{
		while(a[i]=='0'||a[i]=='.')
		{
			cnt++;
			i++;
		}
		printf("%c",a[i]);
		++i;
		if(a[i]!='\0')printf(".");
		for(;a[i]!='\0';i++)
		{
			if(a[i]=='.')continue;
			printf("%c",a[i]);
		}
		printf("e-%d",cnt-1);
		return 0;
	}
	else
	{
		printf("%c",a[i]);
		j=1;
		while(a[i+j]=='0')
		{
			j++;
		}
		if(a[i+j]=='\0')
		{
			printf("e%d",j-1);
			return 0;//30000µÄÇé¿ö 
		}
		else
		{
			printf(".");
			for(k=0;k<j-1;k++)
			printf("0");
			for(;a[i+j]!='\0';j++)
			{
				if(a[i+j]=='.')
				{
					cnt=j-1;
					f=1;
					continue;
				}
				if(a[i+j]=='0')
				{
					while(a[i+j+t]=='0')
					{
						t++;
					}
					if(a[i+j+t]=='\0')
					{
						break;
					}
					else 
					{
						for(k=0;k<t;k++)
						printf("0");
						j+=t-1;
						continue;
					}
					
				}
				printf("%c",a[i+j]);
			}
			if(f==0)
			{
				cnt=strlen(a)-i-1;
			}
			printf("e%d",cnt);
			return 0;
		}
			
	}
}

