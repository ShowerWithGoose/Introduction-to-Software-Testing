#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define max 1010

int i,j,k,r,flag,tem=1;
char s[max],m[max],n[max];
struct stat{
	char word[max];
	int cnt;
};

struct stat a[max];

int count(struct stat a[],int l);
int compare(const void *x,const void *y);

int main()
{
	FILE *in;
	in=fopen("article.txt","r");
	while((r=fgetc(in))!=EOF)
	{
		if(isalpha(r))
		{
			a[i].word[j++]=tolower(r);tem=0;
		}
		else
		{
			if(!tem) a[i++].cnt=1;
			j=0;tem=1;
		}
	}
	qsort(a,i,sizeof(a[0]),compare);i=count(a,i);
	for(k=0;k<i;)
	{
		printf("%s %d\n",a[k].word,a[k].cnt);
		k++;		
	}
	return 0;
}
int count(struct stat a[],int l) 
{
	for(i=0,j=0; i<l; i++)
	{
		for(k=i-1; k>=0; k--) 
		{
			flag=strcmp(a[i].word,a[k].word);
			if(!flag)	break;
		}	
		if(k==-1)
		{
			strcpy(a[j].word,a[i].word);j++;
		}
		else a[j-1].cnt++;
	} 
	return j;
}

int compare(const void *x,const void *y)
{
    const struct stat *p=x;
    const struct stat *q=y;
	if(strcmp(p->word,q->word)<0) return -1;
    else return 1;
}
