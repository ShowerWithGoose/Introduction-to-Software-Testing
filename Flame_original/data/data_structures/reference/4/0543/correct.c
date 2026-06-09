#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cop(const void* a1,const void* b1);
struct words
{
	char word[100];
	int num;
};
struct words *ex,list[100];
int main()
{
	ex=&list[0];
	FILE *in,*out;
	in=fopen("article.txt","r");
	char str[50][100]={},wo[100]={},sen[100]={};
	int co=0,i,j=1,k=1,le;
	while(fgets(sen,sizeof(sen)-1,in))
	{
		le=strlen(sen);
		for(i=1;i<=le;i++)
			if((sen[i-1]<'a'||sen[i-1]>'z')&&(sen[i-1]<'A'||sen[i-1]>'Z'))
				sen[i-1]=32;
		strcpy(str[j-1],sen);
		j++;
	}
	j--;
	fclose(in);
	out=fopen("article.txt","w");
	for(k=1;k<=j;k++)
	{
		fputs(str[k-1],out);
	}
	fclose(out);
	j=1;
	k=1;
	in=fopen("article.txt","r");
	
	while(fscanf(in,"%s",wo)==1)
	{
		le=strlen(wo);
		for(i=1;i<=le;i++)
		{
			
			if((wo[i-1]<'a'||wo[i-1]>'z')&&(wo[i-1]<'A'||wo[i-1]>'Z'))
			{
				for(j=i;j<le;j++)
					wo[j-1]=wo[j];
				wo[le-1]='\0';
				i--;
				le--;
			}
		}
		for(i=1;i<=le;i++)
		{
			if(wo[i-1]>='A'&&wo[i-1]<='Z')
				wo[i-1]=wo[i-1]+32;
		}
		for(i=1;i<=100;i++)
		{
			if(strcmp(list[i-1].word,wo)==0)
			{
				list[i-1].num++;
				co=1;	
			}
		}
		if(co==0)
		{
			strcpy(list[k-1].word,wo);
			list[k-1].num++;
			k++;
		}
		memset(wo,0,sizeof(wo));
		co=0;
	}
	qsort(list,k,sizeof(list[0]),cop);
	for(i=1;i<=k-1;i++)
	{
		printf("%s %d",list[i].word,list[i].num);
		if(i!=k-1)
			printf("\n");
	}
	return 0;
}
int cop(const void* a1,const void* b1)
{
	struct words* a=(struct words*) a1;
	struct words* b=(struct words*) b1;
	return strcmp(a->word,b->word);
}

