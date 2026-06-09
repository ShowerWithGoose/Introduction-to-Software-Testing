#include<stdio.h>
typedef struct d{
	int vjn;//顶点右 
}point;//分支节点 
typedef struct c1{
	point vn[100];
}root;//根节点 
int visit1[100];
int visit2[100];
int visit3[100];
int visit4[100];
int queue1[100]; int head=0;int top=-1;
int one[100];int l=-1;int j[100];
void dps1(root G[],int a);
void dps2(root G[],int a,int b);
void dps3(root G[],int a,int b);
void dps4(root G[],int a,int b);
int main()
{
	root i[100];int al;
	int m,n,vi,vj;//m顶点数，n边数 
	scanf("%d%d",&m,&n);
	int t,s;//计数君 
	for(t=0;t<m;t++)
	{
		visit1[t]=0;
		visit2[t]=0;
		visit3[t]=0;
		visit4[t]=0;
		j[t]=0;
	} 
	int u;int p;
	for(t=0;t<n;t++)
	{
		scanf("%d%d",&vi,&vj);
		p=j[vi];j[vi]++;
		i[vi].vn[p].vjn=vj;
		for(s=p;s>0;s--)
		{
			for(u=0;u<s;u++)
			{
				if(i[vi].vn[u].vjn>i[vi].vn[u+1].vjn)
			    {
				    al=i[vi].vn[u].vjn;
				    i[vi].vn[u].vjn=i[vi].vn[u+1].vjn;
				    i[vi].vn[u+1].vjn=al;
			    }
			}
			
		}
		//以上vi->vj
	    p=j[vj];j[vj]++;
		i[vj].vn[p].vjn=vi;
		for(s=p;s>0;s--)
		{
			for(u=0;u<s;u++)
			{
				if(i[vj].vn[u].vjn>i[vj].vn[u+1].vjn)
			    {
				    al=i[vj].vn[u].vjn;
				    i[vj].vn[u].vjn=i[vj].vn[u+1].vjn;
				    i[vj].vn[u+1].vjn=al;
			    }
			}
		}
		//以上vj->vi
	}
	int r;scanf("%d",&r);
	//printf("%d\n",i[7].vn[1].vjn);
	dps1(i,0);//第一行 
	for(t=0;t<=l;t++)
	{
		printf("%d ",one[t]);
	}
	l=-1;printf("\n");
	dps2(i,0,m);//第二行 
	for(t=0;t<=top;t++)
	{
		printf("%d ",queue1[t]);
	}
	head=0;top=-1;printf("\n");
	dps3(i,0,r);//第三行 
	for(t=0;t<=l;t++)
	{
		printf("%d ",one[t]);
	}
	printf("\n");
	dps4(i,0,r);//第四行 
	for(t=0;t<=top;t++)
	{
		printf("%d ",queue1[t]);
	}
	return 0;
}
//第一行 
void dps1(root G[],int a)
{
	int w=0;int prime=0;
	visit1[a]=1;one[++l]=a;
	while(w<j[a])
	{
		if(visit1[G[a].vn[w].vjn]!=1)
		{
			prime=1;w=G[a].vn[w].vjn;
			break;
		}
		else w++;
	}
	if(prime==0) w=-1;
	while(w!=-1)
	{
		dps1(G,w);w=0;prime=0;
		while(w<j[a])
	    {
		    if(visit1[G[a].vn[w].vjn]!=1)
		    {
			    prime=1;w=G[a].vn[w].vjn;
			    break;
		    }
		    w++;
	    }
	    if(prime==0) w=-1;
	}
} 
//第二行 
void dps2(root G[],int a,int b)
{
	if(visit2[a]!=1)
	{
		queue1[++top]=a;
		visit2[a]=1;
	}
	int w=0;
	while(w<j[a])
	{
		if(visit2[G[a].vn[w].vjn]!=1)
		{
			queue1[++top]=G[a].vn[w].vjn;
			visit2[G[a].vn[w].vjn]=1;
		}
		w++;
	}
	if(head<=top)
	{
		dps2(G,queue1[++head],b);
	}
}
//第三行 
void dps3(root G[],int a,int b)
{
	int w=0;int prime=0;
	visit3[a]=1;one[++l]=a;
	while(w<j[a])
	{
		if(visit3[G[a].vn[w].vjn]!=1&&G[a].vn[w].vjn!=b)
		{
			prime=1;w=G[a].vn[w].vjn;
			break;
		}
		w++;
	}
	if(prime==0) w=-1;
	
	while(w!=-1)
	{
		dps3(G,w,b);w=0;prime=0;
		while(w<j[a])
	    {
		    if(visit3[G[a].vn[w].vjn]!=1&&G[a].vn[w].vjn!=b)
		    {
			    prime=1;w=G[a].vn[w].vjn;
			    break;
		    }
		    w++;
	    }
	    if(prime==0) w=-1;
	}
}
//第四行
void dps4(root G[],int a,int b)
{
	if(visit4[a]!=1)
	{
		if(a!=b)
		{
			queue1[++top]=a;
		}
		visit4[a]=1;
	}
	int w=0;
	while(w<j[a])
	{
		if(visit4[G[a].vn[w].vjn]!=1&&G[a].vn[w].vjn!=b)
		{
			queue1[++top]=G[a].vn[w].vjn;
			visit4[G[a].vn[w].vjn]=1;
		}
		w++;
	}
	if(head<=top)
	{
		dps4(G,queue1[++head],b);
	}
} 

