#include<stdio.h> 
#include<string.h>
int main()
{char str[104];
int i,j,k,l;
gets(str);
l=strlen(str);
if(str[0]=='0')
	{for(i=0;str[i]=='.'||str[i]=='0';i++)
		{
		}
	if(i+1==l)
		{printf("%ce-%d",str[i],i-1);
		}
	else
		{printf("%c.",str[i++]);
		for(j=i;j<l;j++)
			printf("%c",str[j]);
		printf("e-%d",i-2);
		}
	return 0;
	}
k=0;
for(i=1;i<l;i++)
	{if(str[i]==0)
		k++;
	}
if(k+1==i)
	{printf("%ce%d",str[0],l-1);
	return 0;
	}
for(k=0;k<l&&str[k]!='.';k++)
	{
	}
printf("%c.",str[0]);
for(i=1;i<k;i++)
	printf("%c",str[i]);
for(i=k+1;i<l;i++)
	printf("%c",str[i]);
printf("e%d",k-1);
return 0;
}

