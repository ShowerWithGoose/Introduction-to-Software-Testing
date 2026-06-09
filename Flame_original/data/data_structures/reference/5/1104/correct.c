#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
struct f{
	int a;
	int b;
}s[10001],c[10001],ch[1000001];
int main()
{
	struct f s[10001];
	struct f c[10001];
	struct f ch[10001];
	int i=0,j=0,x,y,z,k,t;
	for(i=0;;i++)
	{
		scanf("%d %d",&s[i].a,&s[i].b);
		x=i+1;
		if(getchar()=='\n')
			break;
	}
	for(i=0;;i++)
	{
		scanf("%d %d",&c[i].a,&c[i].b);
		y=i+1;
		if(getchar()=='\n')
			break;
	}
	for(i=0,k=0;i<x;i++)
	{
		for(j=0;j<y;j++,k++)
		{
			ch[k].a=s[i].a*c[j].a;
			ch[k].b=s[i].b+c[j].b;
		}
	}
	z=k;
	for(k=0;k<z;k++)
	{
		for(j=k+1;j<z;j++)
		{
			if(ch[k].b<ch[j].b)
			{
				t=ch[k].a;
				ch[k].a=ch[j].a;
				ch[j].a=t;
				t=ch[k].b;
				ch[k].b=ch[j].b;
				ch[j].b=t;
			}
			else if(ch[k].b==ch[j].b)
			{
				ch[k].a+=ch[j].a;
				ch[j].a=0;
				ch[j].b=0;
			}
		}
	}
	for(k=0;ch[k].a!=0;k++)
	{
		printf("%d %d ",ch[k].a,ch[k].b);
	}
}

