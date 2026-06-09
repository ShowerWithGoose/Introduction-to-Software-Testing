#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define LL long long
#define D double
#define f(i,s,n) for(i=s;i<n;i++)
int main()
{
	char s[120];
	char a[130];
	gets(s);
	int i=0,j,k=0;
	int flag=0;
	if(s[0]=='0')
	{
		if(s[2]=='9')
		{
			printf("9e-1");
		} 
		else
	{	
	j=2;
	for(i=2;s[i]!='\0';i++)
	{
		if(s[i]!='0'&&flag==0&&s[i]>='0'&&s[i]<='9')
		{
			a[0]=s[i];
			k=i;
			flag=1;
			continue;
		}
		if(flag==1)
		{
			if(s[i+1]!='\0')
		a[1]='.';
		a[j++]=s[i];	
		}
	}	
	a[j]='\0';
    for(i=0;a[i]!='\0';i++)
    {
    printf("%c",a[i]);
	}
	printf("e-%d",k-1);
	} 
	} 
	else
	{
		j=0;
	while(s[i]!='.')
	{
	i++;	
	}
	k=i;
	for(i=0;s[i]!='\0';i++)
	{
		if(s[i]!='.')
		a[j++]=s[i];
		else 
		continue;
	}
	a[j]='\0';
	for(j=i;j>1;j--)
	a[j]=a[j-1];
	a[1]='.';
	 for(i=0;a[i]!='\0';i++)
	    {
	    printf("%c",a[i]);
		}
		printf("e%d",k-1);
	}		
	return 0;
} 

