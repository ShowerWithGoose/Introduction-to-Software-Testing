#include<stdio.h>
#include<string.h>
struct mmm{
	char word[105];
	int num;
}p[1005];
int nnn(const void *a,const void *b)
{
	struct mmm *c=(struct mmm*)a;
	struct mmm *d=(struct mmm*)b;
	return strcmp(c->word,d->word);
}
int main()
{
	char s[10095];
	char c;
	struct mmm p[1005];
	int n=0;
	FILE *fp;
	fp=fopen("article.txt","r");
	while((c=fgetc(fp))!=EOF)
	{
		s[n]=c;
		n++;
	}
	n=0;
	int ls=strlen(s);
	for(int i=0;i<ls;i++)
	{
		if(s[i]>='A'&&s[i]<='Z')
		{
			s[i]=s[i]-'A'+'a';
		}
	}
	int k=0;
	for(int i=0;i<ls;i++)
	{

		if(s[i]>='a'&&s[i]<='z')
		{
			p[n].word[k++]=s[i];
			
		}
		else if(s[i]<'a'||s[i]>'z')
		{
			n++;
			k=0;
		}
	}
	qsort(p,n,sizeof(p[1]),nnn);
	for(int i=0;i<n;i++)
	{
		if(strlen(p[i].word)) p[i].num=1;
	}
	for(int i=0;i<n;i++)
	{
		if(!strcmp(p[i].word,p[i+1].word))
		{
			p[i+1].num+=p[i].num;
			p[i].num=0;
		}
	}
	for(int i=0;i<n;i++)
	{
		if(p[i].num!=0)
		{
			printf("%s %d\n",p[i].word,p[i].num);
		}
	}
	return 0;



} 

