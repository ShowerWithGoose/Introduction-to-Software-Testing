#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ll long long
#define PI 3.14159265
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
struct words{
	char xx[1024];
	int num;
	int flag;
};
int cmp(const void *a,const void *b)
{
	struct words *c=(struct words*)a;
	struct words *d=(struct words*)b;
	if(strcmp(c->xx,d->xx)>0)
	return 1;
	return -1;
}
char ak[1024];
int main()
{
	int i=0,j=0,k;
	char c;
	struct words word[1024];
	FILE *pf=fopen("article.txt","r");
	while(fgets(ak,1024,pf)!=NULL)
	{
		for(k=0;k<strlen(ak);k++)
		{
			if(isalpha(ak[k])==0&&isalpha(ak[k-1]))
			{
				word[i].num++;
				i++;
				j=0;
			}
			if(ak[k]>='a'&&ak[k]<='z')
			{
				word[i].xx[j]=ak[k];
				j++;
			}
			else if(ak[k]>='A'&&ak[k]<='Z')
			{
				word[i].xx[j]=ak[k]-'A'+'a';
				j++;
			}
		}
	}
	word[i].num++;
	for(j=0;j<=i+1;j++)
	{
		for(k=0;k<strlen(word[j].xx);k++)
		if(word[j].xx[k]<='Z'&&word[j].xx[k]>='A')
		word[j].xx[k]=word[j].xx[k]-'A'+'a';
	}
	for(j=1;j<=i+1;j++)
	{
		for(k=0;k<j;k++)
		{
			if(strcmp(word[j].xx,word[k].xx)==0)
			{
				word[k].num++;
				word[j].flag=1;
			}
		}
	}
	qsort(word,i+1,sizeof(word[0]),cmp);
	for(j=0;j<=i+1;j++)
	{
		if(word[j].flag==0&&(word[j].xx[0]>='a'&&word[j].xx[0]<='z')||(word[j].xx[0]>='A'&&word[j].xx[0]<='Z'))
		printf("%s %d\n",word[j].xx,word[j].num);
	}
	fclose(pf);
	pf=NULL;
	return 0;
}

