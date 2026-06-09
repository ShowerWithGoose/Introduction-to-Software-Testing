#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main()
{
	int a[101],i,j,k;char b[303];
	for(i=0;;i++)
	{
		scanf("%d %c",&a[i],&b[i]);
		if(b[i]=='=') break;
	}
	for(j=0;j<=i;j++)
	{
		if(b[j]=='*')
		{
			a[j]=a[j]*a[j+1];
			for(k=j+1;k<=i;k++) 
			{
				a[k]=a[k+1];
				b[k-1]=b[k];
			}
			j--;
		}
		if(b[j]=='/')
		{
			a[j]=a[j]/a[j+1];
			for(k=j+1;k<=i;k++) 
			{
				a[k]=a[k+1];
				b[k-1]=b[k];
			}
			j--;
		}
		if(b[0]=='=') break;
	}
	for(j=0;j<=i;j++)
	{
	    if(b[j]=='+')
	    {
	        a[j]=a[j]+a[j+1];
			for(k=j+1;k<=i;k++) 
			{
				a[k]=a[k+1];
				b[k-1]=b[k];
			}
			j--;
		}
		if(b[j]=='-')
		{
	        a[j]=a[j]-a[j+1];
			for(k=j+1;k<=i;k++) 
			{
				a[k]=a[k+1];
				b[k-1]=b[k];
			}
			j--;
		}
		if(b[0]=='=') break;
	}
	printf("%d",a[0]);
}



