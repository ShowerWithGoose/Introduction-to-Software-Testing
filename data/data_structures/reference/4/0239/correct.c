#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
struct dc{
	char word[500];
	int num;
};
int cmp(const void *a,const void *b)
{
	struct dc *c=(struct dc*)a;
	struct dc *d=(struct dc*)b;
	return (strcmp(c->word,d->word));
}
int main()
{
	struct dc a[1000];
	FILE *fp=fopen("article.txt","r");
	char ch,c[100000];
	int num1=0,x=0,mum=0;
	while((ch=fgetc(fp))!=EOF)
	{c[mum++]=ch;}
	for(int j=0;j<mum;j++)
	{	
		if(!isalpha(c[j]))
		{
			num1++;
			x=0;
		}
		else if(isalpha(c[j]))
		{
			a[num1].word[x]=tolower(c[j]);
			x++;
		}
	}	
	for(int k=0;k<num1;k++)
	{
		if(strlen(a[k].word)>0)
		a[k].num=1;
	}
	qsort(a,num1,sizeof(a[0]),cmp);
	for(int l=0;l<num1;l++)
	{
		if(a[l].num>0)
		{
			if(strcmp(a[l].word,a[l+1].word)==0)
			{
				a[l+1].num+=a[l].num;
				a[l].num=0;
			}
		}
	}
	for(int i=0;i<num1;i++)
	{
		if(a[i].num>0)
		printf("%s %d\n",a[i].word,a[i].num);
	}
	fclose(fp);
	return 0;
}
