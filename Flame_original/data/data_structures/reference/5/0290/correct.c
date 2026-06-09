#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct zu
{
	int a;
	int b;
};
int cmp(const void *a,const void *b)
{
	struct zu *aa=(struct zu *)a;
	struct zu *bb=(struct zu *)b;
	if( (*aa).b > (*bb).b ) return -1;
	return 1;
}
struct zu l1[1000],l2[1000],l3[10000000],num;
int c[10000],d[10000];
char s1[1000000],s2[1000000];
int main()
{
	gets(s1);
	gets(s2);
	int la,lb;
	la=strlen(s1);
	lb=strlen(s2);
	int j=0,k=0,cnt=0,w=0,v=0;
	for(int i=0; i<la; i++)
	{
		while(s1[i]!=' '&&i<la)
			c[j]=c[j]*10+s1[i++]-'0';
		j++;
	}
	for(int i=0; i<lb; i++)
	{
		while(s2[i]!=' '&&i<lb)
			d[k]=d[k]*10+s2[i++]-'0';
		k++;
	}
	for(int i=0; i<j; i+=2)
	{
		l1[w].a=c[i];
		l1[w++].b=c[i+1];
	}
	for(int i=0; i<k; i+=2)
	{
		l2[v].a=d[i];
		l2[v++].b=d[i+1];
	}
	for(int i=0; i<w; i++)
	{
		for(int o=0; o<v; o++)
		{
			num.a=l1[i].a*l2[o].a;
			num.b=l1[i].b+l2[o].b;
			int flag=1;
			for(int m=0; m<=cnt&&flag; m++)
			{
				if(num.b==l3[m].b)
				{
					l3[m].a+=num.a;
					flag=0;
				}
			}
			if(flag==1)
			{
				l3[cnt].a=num.a;
				l3[cnt++].b=num.b;
			}
		}
	}
	qsort(l3,cnt,sizeof(l3[0]),cmp);
	for(int m=0; m<=cnt; m++)
	{
		if(l3[m].a!=0)
			printf("%d %d ",l3[m].a,l3[m].b);
	}
	return 0;
}



