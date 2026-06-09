#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
typedef struct word
{
	char name[10000];
	int x;
}W;
W a[10000];
int compare(const void*s1,const void*s2);
int main()
{
	FILE *p;
	int i,j=0,k=0;
	char s;
	p=fopen("article.txt","r");
	while(fscanf(p,"%c",&s)!=EOF)
	{
		if(isalpha(s))
		{
			a[k].name[j++]=(tolower(s));
		}		
		else if(strlen(a[k].name))
		{
			a[k].x=1;
			k++;
			j=0;
		}
	}
	qsort(a,k,sizeof(a[0]),compare);
	for(i=0;i<k;i++)
	{
		if(strcmp(a[i].name,a[i+1].name)==0)
		{
			a[i+1].x=a[i].x+a[i+1].x;
		}		
		else if(strlen(a[i].name))
		{
			printf("%s %d\n",a[i].name,a[i].x);
		}
	}
	return 0;
} 
int compare(const void*s1,const void*s2)
{
	struct word *a=(struct word *)s1;
	struct word *b=(struct word *)s2;
	return strcmp(a->name,b->name);
}

