#include <stdio.h>
#include <string.h>
int main()
{
	char a[100];
	double b[100];int i,c,d,e=1,n,m,f=0,k,p=0,j,l;
	for(i=0;;i++)
	{
		scanf("%lf%c",&b[i],&a[i]);
		if(a[i]==' ')
		{
			scanf("%c",&a[i]);
		}
		if(a[i]==' ')
		{
			scanf("%c",&a[i]);
		}
		if(a[i]=='=')
		break;//上边是输入 
	}
	k=i;
		
		for(i=0;i<=k;i++)
		{
			if(a[i]=='/')
			{
				while(b[i]==0)
				{
					i--;
					e=e+1;
					p=p+1;
				}
				b[i]=b[i]/b[i+e];
				b[i+e]=0;
					i=i+p;
					e=1;
					p=0;
			}
		}
		e=1;		
		p=0;
		for(i=0;i<=k;i++)
		{
			if(a[i]=='*')
			{
				while(b[i]==0)//把用过的标记 
				{
					i--;
					e=e+1;//i减少几个 e增加几个 保证下边的 	b[i]=b[i]*b[i+e];
					p=p+1;
				}
			 b[i]=b[i]*b[i+e];
				b[i+e]=0;
					i=i+p;//i变回减少之前 
					e=1;
					p=0;
			}
	
		}
		e=1;
		p=0;
		for(i=0;i<=k;i++)
		{
			if(a[i]=='-')
			{
				while(b[i]==0)
				{
					i--;
					e=e+1;
					p=p+1;
				}
				b[i]=b[i]-b[i+e];
				b[i+e]=0;
					i=i+p;
					e=1;
					p=0;
		}
		}
	e=1;
	p=0;
		
		for(i=0;i<=k;i++)
		{
			if(a[i]=='+')
			{	
				while(b[i]==0)
				{
					i--;
					e=e+1;
					p=p+1;
				}
				b[i]=b[i]+b[i+e];
				l=(int)b[i];
				b[i+e]=0;
					i=i+p;
					e=1;
					p=0;
		}

	}
	
	j=(int)b[0];
	if(b[0]!=0)
	printf("%d",j);
	else if(b[0]==0)
	{
		printf("%d",l);
	}
	
		
		
		
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}

