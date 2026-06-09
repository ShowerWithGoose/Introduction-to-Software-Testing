#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

int main()
{
	char a[101],b[101];
	int n,i,j,k,p,q,flag=0;
	gets(a);
	n=strlen(a);
	
	for(q=0;q<n;q++)
	{
		if(a[q]=='.')
		{flag=1;
		break;
		}
	}
	
	if(flag==0)
	{
		if(n>1)
		{
			b[0]=a[0];
		    b[1]='.';
		    for(i=2,k=1;k<=n;k++,i++)
		    {
			    b[i]=a[k];
		    }
		printf("%se%d",b,n-1);
		return 0;
		}
		else if(n==1)
	    {
		printf("%se0",a);
		return 0;
	    }
	}
	
	
else if(flag==1)
{
    if(a[0]=='0'&&a[1]=='.')
	{
		for(i=2;i<n;i++)
		{
			if(a[i]!='0')
			break;
		}
		
				
				
				if(i==n-1)
				{
					
					printf("%ce%d",a[n-1],2-n);
					return 0;
				}
				
				else if(i<n-1)
				{
					b[0]=a[i];
					j=1-i;
				    b[1]='.';
				for(k=2,i=i+1;i<=n;i++,k++)
				{
					b[k]=a[i];
				}
				    printf("%se%d",b,j);
		            return 0;
				}
			
	}
	else if(a[0]!='0')
	{
		for(i=1;i<n;i++)
		{
			if(a[i]=='.')
			{
				p=i;
				break;
			}
		}
		if(p==1)
		{
			printf("%se%d",a,0);
			return 0;
		}
		else{
			b[0]=a[0];
		    b[1]='.';
			for(k=2,j=1;j<p;j++,k++)
			{
				b[k]=a[j] ;
			}
			for(j=p+1;j<=n;j++,k++)
			{
				b[k]=a[j] ;
			}
			printf("%se%d",b,p-1);
			return 0;
		}
		
		
	}
}
	
}

