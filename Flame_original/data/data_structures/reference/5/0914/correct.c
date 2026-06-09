#include <stdio.h> 
int main()
{
	struct num{
		int n;
		int pow;
	}; 
	struct num x[1000],y[1000],z[1001];
	int a=0,b=2100000000,p=0,q=0,s=0,lx=0,ly=0;
	while(scanf("%d %d",&p,&q)!=EOF)
	{
		r:
			if(s==0)
			{
				if(b<=q)
				{
					s=1;
			    	lx=a;
			    	a=0;
			    	goto r;
				}
				x[a].n=p;
		    	x[a].pow=q;
		    	b=q;
			}
			else if(s==1)
			{
				y[a].n=p;
				y[a].pow=q;
			}
		a++;
	}
	ly=a;
	a=0;
	b=0;
	p=0;
	q=0;
	s=0;
	while(a<lx)
	{
		b=0;
		while(b<ly)
		{
			q=0;
			p=x[a].pow+y[b].pow;
			while(q<s||s==0)
			{
				if(z[q].pow==p&&s!=0)
				{
					z[q].n=z[q].n+x[a].n*y[b].n;
					break;
				}
				q++;
				if(q==s||s==0)
				{
					z[s].n=x[a].n*y[b].n;
					z[s].pow=p;
					s++;
					break;
				}
			}
			b++;
		}
		a++;
	}
	p=0;
	while(p==0)
	{
		p=1;
		a=0;
		while(a<s-1)
		{
			if(z[a].pow<z[a+1].pow)
			{
				z[1000]=z[a+1];
				z[a+1]=z[a];
				z[a]=z[1000];
				p=0;
				break;
			}
			a++;
		}
	}
	a=0;
	while(a<s)
	{
		printf("%d %d ",z[a].n,z[a].pow);
		a++;
	}
	return 0;
}

