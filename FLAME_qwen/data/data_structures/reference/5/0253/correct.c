#include<stdio.h>
#include<stdlib.h>
struct aaa
{
	long long x,z;
}a[100000],b[100000],c[100000];
int cmp(const void *x,const void *y)
{
	struct aaa p=*(struct aaa*)x;
	struct aaa q=*(struct aaa*)y;
	return q.z-p.z;
}
int main()
{
	int cnt1=0,cnt2=0,cnt3=0,flag,p;
	char ch;
	while(1)
	{
		cnt1++;
		scanf("%lld %lld%c",&a[cnt1].x,&a[cnt1].z,&ch);
		if(ch=='\n')
		break;
	}
	while(1)
	{
		cnt2++;
		scanf("%lld %lld%c",&b[cnt2].x,&b[cnt2].z,&ch);
		if(ch=='\n')
		break;
	}
	for(int i=1;i<=cnt1;i++)
	{
		for(int j=1;j<=cnt2;j++)
		{
			flag=1;
			p=a[i].z+b[j].z;
			for(int k=0;k<cnt3;k++)
			if(p==c[k].z)
			{
				flag=0;
				c[k].x+=a[i].x*b[j].x;
				break;
			}
			if(flag)
			{
				c[cnt3].z=p;
				c[cnt3].x=a[i].x*b[j].x;
				cnt3++;
			}
		}
	}
	qsort(c,cnt3,sizeof(c[0]),cmp);
	for(int i=0;i<cnt3;i++)
	printf("%lld %lld ",c[i].x,c[i].z);
}

