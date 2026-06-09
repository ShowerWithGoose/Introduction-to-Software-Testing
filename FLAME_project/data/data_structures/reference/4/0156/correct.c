#include<stdio.h>
#include<ctype.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#define N 10000
struct word
{
	char s[N];
	int t;
}a[N];
int cmp(const void*p1,const void *p2)
{
	struct word *a=(struct word *)p1;struct word *b=(struct word *)p2;
	return strcmp(a->s,b->s);
}
int main()
{
	FILE *fp;
	fp=fopen("article.txt","r");
	char ch;
	int i=0,cnt=0;
	while(fscanf(fp,"%c",&ch)!=EOF)
	{
		if(isalpha(ch))
		a[cnt].s[i++]=(tolower(ch));
		else if(strlen(a[cnt].s))
		{a[cnt].t=1;cnt++;i=0;}
	}
	qsort(a,cnt,sizeof(a[0]),cmp);
	for(i=0;i<cnt;i++)
	{
		if(strcmp(a[i].s,a[i+1].s)==0)
		a[i+1].t+=a[i].t;
		else if(strlen(a[i].s))
		printf("%s %d\n",a[i].s,a[i].t);
	}
	return 0;
}


