#include<stdio.h>
int main()
{
char a[110];
int i,j,num=0;
gets(a);
if(a[0]=='0'&&a[1]=='.')
{
	for(i=0;a[i]!='\0';i++)
	{
		if(a[i]>'0'&&a[i]<='9')
		{
			if(a[i+1]!='\0')
			{
				printf("%c",a[i]);
				printf(".");
			    for(j=i+1;a[j]!='\0';j++)
			    {
				printf("%c",a[j]);
			    }
			    printf("e-%d",num-1);
			    break;
			}
			else
			{
				printf("%c",a[i]);
				printf("e-%d",num-1);
			    break;
			}
		}
		else
		{
			num++;
		}
	}
}
else if(a[0]>'0'&&a[0]<='9'&&a[1]=='.')
{
	printf("%se0",a);
}
else
{
	for(i=0;a[i]!='\0';i++)
	{
		if(a[i]!='.')
		{
			num++;
		}
		else if(a[i]=='.')
		{
			j=i;
			break;
		}
	}
	printf("%c",a[0]);
	printf(".");
	for(i=1;a[i]!='.';i++)
	{
		printf("%c",a[i]);
	}
	for(i=j+1;a[i]!='\0';i++)
	{
		printf("%c",a[i]);
	}
	printf("e");
	printf("%d",num-1);
}
return 0;
}

