#include<stdio.h>
#include<ctype.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
char al;
int i=0,cnt=0;
struct ci
{
	char s[1000];
	int t;
}a[1000];
int cmp(const void*p1,const void *p2)
{
	struct ci *a=(struct ci *)p1;struct ci *b=(struct ci *)p2;
	return strcmp(a->s,b->s);
}
int main()
{
	FILE *op;
	op=fopen("article.txt","r");
	
	while(fscanf(op,"%c",&al)!=EOF)
	{
		if(isalpha(al))
		{ 
		a[cnt].s[i++]=(tolower(al));
		} 
		else if(strlen(a[cnt].s))//ÓÐ³¤¶È 
		{
		a[cnt].t=1;
		cnt++;
		i=0;
		}
	}
	qsort(a,cnt,sizeof(a[0]),cmp);
	for(i=0;i<cnt;i++)
	{
		if(strcmp(a[i].s,a[i+1].s)==0)
		{ 
		a[i+1].t+=a[i].t;
		} 
		else if(strlen(a[i].s))
		{ 
		printf("%s %d\n",a[i].s,a[i].t);
		} 
	}
	return 0;
}


