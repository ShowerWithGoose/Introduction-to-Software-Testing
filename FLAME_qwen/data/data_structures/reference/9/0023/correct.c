#include <stdio.h>
struct xian
{
	int a;
	int b;
	int c;
	int d;
};
void paixu(struct xian lan[999],int n);
int main()
{
	int n,i,j,k=0,l,z,f,g;
	struct xian abc[999];
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d%d%d%d",&abc[i].a,&abc[i].b,&abc[i].c,&abc[i].d);
	}
	paixu(abc,n);
	for(i=0;i<n;i++)
	{
		l=1;
		z=i;
		for(j=i+1;j<n;j++)
		{
			if(abc[j].a==abc[z].c&&abc[j].b==abc[z].d)
			{
				l++;
				z=j;
			}
		}
		if(l>k)
		{
			k=l;
			f=abc[i].a;
			g=abc[i].b;
		}
	}
	printf("%d %d %d",k,f,g);
	return 0;
		
}
void paixu(struct xian lan[999],int n) 
{
	int i,j;
	struct xian zzz;
	for(i=0;i<n;i++)
	{
		for(j=i;j<n;j++)
		{
			if (lan[i].a>lan[j].a)
			{
				zzz=lan[i];
				lan[i]=lan[j];
				lan[j]=zzz;
			}
		}
	}
}



