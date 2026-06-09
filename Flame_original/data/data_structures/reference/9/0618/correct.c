#include<stdio.h>
#include<string.h>
int len=0,ans,n;
struct user{
		int a;
		int b;
		int c;
		int d;
	};
struct user u1[105];
void swap(int i,int j)
{
	struct user tmp;
	tmp=u1[i];
	u1[i]=u1[j];
	u1[j]=tmp;
}
int compete(int i,int j)
{
	if(u1[i].c==u1[j].a&&u1[i].d==u1[j].b) return 1;
	else return 0;
}
int f(int cnt,int i,int j)
{
	int k,l,m=cnt,tmp;
	k=j;
	l=k+1;
	for(l;l<n;l++)
	{
		if(compete(k,l))
		{
			m++;
			m=f(m,k,l);
			if(m>cnt)
			{
				tmp=m;
				m=cnt;
				cnt=tmp;
			}
		}
	}
	return cnt;
}
int main()
{
	int i,j,k,l,cnt;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d%d%d%d",&u1[i].a,&u1[i].b,&u1[i].c,&u1[i].d);
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(u1[j].a>u1[j+1].a) swap(j,j+1);
			else if(u1[j].a==u1[j+1].a&&u1[j].c>u1[j+1].c) swap(j,j+1);
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(compete(i,j))
			{
				cnt=2;
				cnt=f(cnt,i,j);
				if(cnt>len)
				{
					len=cnt;
					ans=i;
				}
			}
		}
	}
	printf("%d %d %d",len,(u1+ans)->a,(u1+ans)->b);
	return 0;
}

