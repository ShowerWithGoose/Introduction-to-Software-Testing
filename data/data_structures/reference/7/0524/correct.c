#include<stdio.h>
typedef struct
{
	int z,c[2],p,st;
}Node;
Node a[1000];
int n,p,cnt,dep;
int i,j,k;
int main()
{
	scanf("%d%d",&n,&a[++cnt].z);n--;
	while(n--)
	{
		p=1;
		scanf("%d",&a[++cnt].z);
		while(1)
		{
			if(a[cnt].z<a[p].z)
			{
				if(a[p].c[0])	p=a[p].c[0];
				else
				{
					a[cnt].p=p;
					a[p].c[0]=cnt;
					break;
				}
			}
			else
			{
				if(a[p].c[1])	p=a[p].c[1];
				else
				{
					a[cnt].p=p;
					a[p].c[1]=cnt;
					break;
				}
			}
		}
	}
	p=1;
	dep=1;
	while(p)
	{
		if(a[p].st==2)
		{
			if(a[p].c[0]==0&&a[p].c[1]==0)	printf("%d %d\n",a[p].z,dep);
			dep--;
			p=a[p].p;
		}
		else if(a[p].c[a[p].st++])
		{
			p=a[p].c[a[p].st-1];
			dep++;
		}		
	}
	return 0;
}


