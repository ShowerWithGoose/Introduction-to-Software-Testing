#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 10000
int cmp(const void*,const void*);
struct word
{
 char s[N];
 int t;
}aw[N];

int main()
{
 	FILE *fp;
	fp=fopen("article.txt","r");
 	char ch;
 	int i=0,cnt=0;
	 while(fscanf(fp,"%c",&ch)!=EOF)
 	{
  	if(isalpha(ch))
  		aw[cnt].s[i++]=(tolower(ch));
  	else if(strlen(aw[cnt].s)){
  		aw[cnt++].t=1;
		i=0;
		}
 	}
 	qsort(aw,cnt,sizeof(aw[0]),cmp);
 	for(i=0;i<cnt;i++)
 	{
  	if(strcmp(aw[i].s,aw[i+1].s)==0)
  		aw[i+1].t+=aw[i].t;
 	else if(strlen(aw[i].s))
 	 	printf("%s %d\n",aw[i].s,aw[i].t);
 	}
 	return 0;
}

int cmp(const void*p1,const void *p2)
{
 struct word *a=(struct word *)p1;
 struct word *b=(struct word *)p2;
 return strcmp(a->s,b->s);
}
//

