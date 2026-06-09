#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
struct word{
	char w[110];
	int cnt;
}a[10100];
typedef struct word *node;
int f(const void*a,const void*b)
{
	node p=(node)a;
	node q=(node)b;
	return strcmp(p->w,q->w);
}
int main()
{
	FILE *in;
	in=fopen("article.txt","r");
	char c;
	int i=0,n=0;
	while((c=fgetc(in))!=EOF)
	{
		if(c<='z'&&c>='a'||c<='Z'&&c>='A')
		{
			a[n].w[i]=(tolower(c));
			i++;
		}
		else if(strlen(a[n].w)!=0)
		{
			a[n].cnt=1;
			n++;
			i=0;	
		}
	}
	qsort(a,n,sizeof(a[0]),f);
	for(i=0;i<n;i++)
	{
		if(strcmp(a[i+1].w,a[i].w)==0)
			a[i+1].cnt+=a[i].cnt;
		else if(strlen(a[i].w)!=0) 
			printf("%s %d\n",a[i].w,a[i].cnt); 
	}
	return 0;
	fclose(in);
}

