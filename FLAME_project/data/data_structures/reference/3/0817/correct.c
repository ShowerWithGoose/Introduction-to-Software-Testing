#include<stdio.h>
#include<string.h>
int main()
{
	char x[1000];
	int a,b,c,l;
	scanf("%s",x);
	l=strlen(x);
	int h,n;
	int i,m;
	for(h=0;h<l;h++)
	{
		if(x[h]=='.')
		{
			n=h;
		}
	}
	if(x[0]!='0'&&n==1)
	{
		printf("%se0",x);
	}
	else if((x[0]=='0')&&(n==1))
	{
		for(i=2;i<l;i++)
	    {
		    if(x[i]!='0')
		    {
			    m=i;
			    break;
		    }
	    }
	    char x2[1000];
	    if(m==(l-1))
	    printf("%ce-%d",x[m],(m-1));
	    else{
		    x2[0]=x[m];
		    x2[1]='.';
		int p;
		int q=m;
		for(p=2;m<(l-1);m++,p++)
		{
			x2[p]=x[m+1];
		}
		printf("%se-%d",x2,(q-1));
	    } 
    }
	else
	{
		char x3[1000];
		int j,k;
		x3[0]=x[0];
		x3[1]='.';
		for(j=1,k=2;j<l;j++)
		{
			if(x[j]!='.')
			{
				x3[k]=x[j];
				k=k+1;
			}
		}
		printf("%se%d",x3,(n-1));
	}
	return 0;


	
}

