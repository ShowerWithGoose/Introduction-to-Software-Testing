#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
typedef struct
{
	char st[21];
	int d;
}node;
node a[11000];
int cmp(const void *xx,const void *yy)
{
	node n1=*(node *)xx;
	node n2=*(node *)yy;
	int len1=strlen(n1.st+1),len2=strlen(n2.st+1);
	int mmin=len1;if(len1>len2) mmin=len2;
	for(int i=1;i<=mmin;i++)
	{
		if(n1.st[i]>n2.st[i]) return 1;
		if(n1.st[i]<n2.st[i]) return -1;
	}
	if(len1>len2) return 1;
	if(len1<len2) return -1;
	return 0;
}
char st[11000];
char C[11000];
int pd(char c)
{
	if(c>='a'&&c<='z'||c>='A'&&c<='Z') return 1;
	return 0;
}
char change(char c)
{
	if(c>='A'&&c<='Z') return c-'A'+'a';
	return c;
}
int t;
int pare(int k)
{
	if(strlen(a[k].st+1)!=t) return 0;
	for(int i=1;i<=t;i++)
	{
		if(a[k].st[i]!=C[i]) return 0;
	}
	return 1;
}
int main()
{
	freopen("article.txt","r",stdin);
	int tot=0;
	while(gets(st+1))
	{
		int len=strlen(st+1);
		t=0;
		for(int i=1;i<=len;i++)
		{
			if(pd(st[i])==0)
			{
				if(t!=0)
				{
					int bk=1;
					for(int j=1;j<=tot;j++)
					{
						if(pare(j)==1)
						{
							a[j].d++;bk=0;break;
						}
					}
					if(bk==1)
					{
						a[++tot].d=1;
						for(int j=1;j<=t;j++) a[tot].st[j]=C[j];
					}
				}
				t=0;
				continue;
			}
			if(i==1||pd(st[i-1])==0)
			{
				t=1;C[t]=change(st[i]);
			}
			else
			{
				C[++t]=change(st[i]);
			}
		}
		if(t!=0)
		{
			int bk=1;
			for(int j=1;j<=tot;j++)
			{
				if(pare(j)==1)
				{
					a[j].d++;bk=0;break;
				}
			}
			if(bk==1)
			{
				a[++tot].d=1;
				for(int j=1;j<=t;j++) a[tot].st[j]=C[j];
			}
		}
	}
	qsort(a+1,tot,sizeof(node),cmp);
	for(int i=1;i<=tot;i++)
	{
		for(int j=1;j<=strlen(a[i].st+1);j++) printf("%c",a[i].st[j]);
		printf(" %d\n",a[i].d);
	}
	return 0;
}

