#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
int a[1000000];
char b[1000000];
int count,ans,i,j;
int x=99999999;
int main()
{
while(1)
{
	scanf("%d %c",&a[count],&b[count]);
	count++;
	if(b[count-1]=='=')
	break;
}
for(i=0;i<count;i++)
{
	if(b[i]=='*' || b[i]=='/')
	{
		if(b[i]=='*')
		{
		ans=a[i]*a[i+1];
		a[i+1]=ans;
		a[i]=x;
		b[i]=' ';
		}
		else
		{
		ans=a[i]/a[i+1];
		a[i+1]=ans;
		a[i]=x;
		b[i]=' ';
		}
	}
	}
//	for(i=0;i<count;i++)
//	{
//		printf("%d",a[i]);
//		printf("%c",b[i]);
//	}
	for(i=0;i<count;i++)
	{
	
	if(b[i]=='+' || b[i]=='-')
	{
		if(b[i]=='+')
		{
			for(j=i+1;j<count;j++)
			{ 
			if(a[j]!=x)
			break;
			}
		ans=a[i]+a[j];
		a[j]=ans;
		a[i]=x;
		b[i]=' ';
		}
		else
		{
			for(j=i+1;j<count;j++)
			{ 
			if(a[j]!=x)
			break;
			}
		ans=a[i]-a[j];
		a[j]=ans;
		a[i]=x;
		b[i]=' ';
		}
	}
	}

//	for(i=0;i<count;i++)
//	{
//		printf("%d",a[i]);
//		printf("%c",b[i]);
//	}
	printf("%d",a[count-1]);

return 0;
}


