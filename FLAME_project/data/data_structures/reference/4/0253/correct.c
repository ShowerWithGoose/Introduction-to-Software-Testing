#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct aaa
{
	int n;
	char w[100];
}a[100000];
int cmp(const void *x,const void *y)
{
	struct aaa p=*(struct aaa*)x;
	struct aaa q=*(struct aaa*)y;
	return strcmp(p.w,q.w);
}
int main()
{
	char b[10000],c[100];
	int cnt=0,l,f=0,flag;
	FILE *in;
	in=fopen("article.txt","r");
	while(fgets(b,10000,in)!=NULL)
	{
		l=strlen(b);
		for(int i=0;i<l;i++)
		if(b[i]>='A'&&b[i]<='Z')
		b[i]=b[i]-'A'+'a';
		for(int i=0;i<l;i++)
		{
			if(b[i]<'a'||b[i]>'z')
			continue;
			for(int j=0;;j++)
			{
				if(b[i+j]>='a'&&b[i+j]<='z')
				{
					c[f]=b[i+j];
					f++;
				}
				else
				{
					flag=1;
					for(int k=0;k<cnt;k++)
					if(strcmp(c,a[k].w)==0)
					{
						flag=0,a[k].n++;break;
					}
					if(flag)
					{
						strcpy(a[cnt].w,c);
						a[cnt].n=1;
						cnt++;
					}
					memset(c,0,sizeof(c));f=0;
					i=i+j;
					break;
				}
			}
		}
	}
	qsort(a,cnt,sizeof(a[0]),cmp);
	for(int i=0;i<cnt;i++)
	printf("%s %d\n",a[i].w,a[i].n);
}

