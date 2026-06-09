#include <stdio.h> 
int graph[1024][2];
int found[1024];
int ind[1024];
int s,f,d=-1,q=0;
int swap(int n,int m)
{
	int c=0,d=0;
	c=graph[n][1];
	d=graph[n][2];
	graph[n][1]=graph[m][1];
	graph[n][2]=graph[m][2];
	graph[m][1]=c;
	graph[m][2]=d;
	return 0;
}
int depth(int st)
{
	int b;
	printf("%d ",st);
	found[st]=1;
	b=ind[st];
	while(graph[b][1]==st&&b<2*s)
	{
		if(found[graph[b][2]]!=1)
		{
			depth(graph[b][2]);
		}
		b++;
	}
	return 0;
}
int width(int l,int st)
{
	if(st==d&&q==1)
	{
		return 0;
	}
	int b;
	b=ind[st];
	if(l==1)
	{
		while(graph[b][1]==st&&b<2*s)
    	{
	    	if(found[graph[b][2]]!=1)
	    	{
	    		printf("%d ",graph[b][2]);
	    		f++;
	    		found[graph[b][2]]=1;
	    	}
	    	b++;
    	}
	}
	else
	{
		while(graph[b][1]==st&&b<2*s)
    	{
	    	width(l-1,graph[b][2]);
	    	b++;
    	}
	}
	return 0;
}
int main()
{
	int v,n,m,c;
	scanf("%d %d",&v,&s);
	n=0;
	while(n<s*2)
	{
		scanf("%d %d",&graph[n][1],&graph[n][2]);
		n++;
		graph[n][1]=graph[n-1][2];
		graph[n][2]=graph[n-1][1];
		n++;
	}
	scanf("%d",&d);
	m=1;
	while(m==1)
	{
		m=0;
		n=0;
		while(n<s*2-1)
		{
			if(graph[n][1]>graph[n+1][1]||(graph[n][1]==graph[n+1][1]&&graph[n][2]>graph[n+1][2]))
			{
				swap(n,n+1);
				m=1;
			}
			n++;
		}
	}
	c=0;
	n=0;
	while(n<s*2)
	{
		if(graph[n][1]!=c)
		{
			c=graph[n][1];
			ind[c]=n;
		}
		found[c]=0;
		n++;
	}
	depth(0);
	printf("\n");
	f=0;
	n=1;
	m=0;
	while(m<v)
	{
		found[m]=0;
		m++;
	}
	found[0]=1;
	f++;
	printf("%d ",0);
	while(f!=v)
	{
		width(n,0);
		n++;
	}
	printf("\n");
	f=0;
	n=1;
	m=0;
	while(m<v)
	{
		found[m]=0;
		m++;
	}
	found[d]=1;
	depth(0);
	printf("\n");
	f=0;
	n=1;
	m=0;
	q=1;
	while(m<v)
	{
		found[m]=0;
		m++;
	}
	found[d]=1;
	f++;
	found[0]=1;
	f++;
	printf("%d ",0);
	while(f!=v)
	{
		width(n,0);
		n++;
	}
	return 0;
}



