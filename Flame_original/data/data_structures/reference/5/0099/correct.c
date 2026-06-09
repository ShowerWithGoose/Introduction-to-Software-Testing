#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
typedef struct node{long long x,z;}nod;
nod a1[1010],a2[1010],ans[2000010];long long n1,n2,sum;
long long cmp(const void *aa,const void *bb)
{
	nod a=*(nod*)aa;
	nod b=*(nod*)bb;
	return b.z-a.z;
}
int main()
{
	char ch;ch=' ';
	while(ch!='\n')
	{
		n1++;
		scanf("%lld%lld",&a1[n1].x,&a1[n1].z);
		ch=getchar();
	}ch=' ';
	while(ch!='\n')
	{
		n2++;
		scanf("%lld%lld",&a2[n2].x,&a2[n2].z);
		ch=getchar();
	}long long i,j;
	for(i=1;i<=n1;i++)
		{
			for(j=1;j<=n2;j++)
				{
					ans[sum].x=a1[i].x*a2[j].x;
					ans[sum].z=a1[i].z+a2[j].z;
					sum++;
				}
		}
	qsort(ans,sum,sizeof(ans[0]),cmp);
	for(i=1;i<sum;i++)
	{
		if(ans[i].z==ans[i-1].z)ans[i].x+=ans[i-1].x;
		else printf("%lld %lld ",ans[i-1].x,ans[i-1].z);
		
	}printf("%lld %lld",ans[sum-1].x,ans[sum-1].z);
} 




