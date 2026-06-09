#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
typedef struct node{long long a,b;}nod;
nod x[1010],y[1010],z[2000010];long long n1,n2,k;
long long cmp(const void *aa,const void *bb)
{
	nod a=*(nod*)aa;
	nod b=*(nod*)bb;
	return b.b-a.b;
}
int main()
{
	char ch;ch=' ';
	while(ch!='\n')
	{
		n1++;
		scanf("%lld%lld",&x[n1].a,&x[n1].b);
		ch=getchar();
	}ch=' ';
	while(ch!='\n')
	{
		n2++;
		scanf("%lld%lld",&y[n2].a,&y[n2].b);
		ch=getchar();
	}long long i,j;
	for(i=1;i<=n1;i++)
		{
			for(j=1;j<=n2;j++)
				{
					z[k].a=x[i].a*y[j].a;
					z[k].b=x[i].b+y[j].b;
					k++;
				}
		}
	qsort(z,k,sizeof(z[0]),cmp);
	for(i=1;i<k;i++)
	{
		if(z[i].b==z[i-1].b)z[i].a+=z[i-1].a;
		else printf("%lld %lld ",z[i-1].a,z[i-1].b);
		
	}printf("%lld %lld",z[k-1].a,z[k-1].b);
} 




