#include<stdio.h>
int main()
{
	int n,q=0,i=0,a[105],s[105],top=0;
	while(scanf("%d",&n)!=EOF)
	{
		if(n==-1) break;
		else
		{
		    a[q]=n;
	        q++;
	    }
	}
	while(i<=q-1)
	{
	    if(a[i]==1)
	    {
	    	s[top]=a[i+1];
	    	top++;
		}
		if(a[i]==0)
		{
			if(top==0)
			{
				printf("error ");
			}
		    else
		    {
				printf("%d ",s[top-1]);
			    top--;
		    }
		}
		i++;
	}
	return 0;
} 

