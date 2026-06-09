#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
struct node{
    char word[100];
    int num;
};
char book[10000];   
int cmp(const void *p1,const void *p2);               
int main()
{
    FILE* fp;
    char c;
    if((fp=fopen("article.txt","r"))==NULL)
    {
    	printf("can not open the file!");
    	return 0;
	}
	struct node sum[200];
    int count=0,i,j,wordsum=0,k=0;
    while((c=fgetc(fp))!=EOF)
    {
    	book[count]=c;
    	count++;
	}
	for(i=0;i<count;i++)
	{
		if(isalpha(book[i])==0)
		{
			if(k!=0)
			{
				sum[wordsum].num=1;
				wordsum++;
			}
			k=0;
		}
		else
		{
			sum[wordsum].word[k]=tolower(book[i]);
			k++;
		}
	}
	qsort(sum,wordsum,sizeof(struct node),cmp);
	for(i=0;i<wordsum;i++)
	{
		if(strcmp(sum[i].word,sum[i+1].word)==0&&i!=wordsum-1)
		{
			sum[i].num++;
			for(j=i+1;j<wordsum-1;j++)
			{
				sum[j]=sum[j+1];
			}
			wordsum--;
			i--;
		}
	}
	for(i=0;i<wordsum;i++)
	{
		printf("%s %d\n",sum[i].word,sum[i].num);
	}
	return 0;
}
int cmp(const void *p1,const void *p2)
{
	struct node *a=(struct node *)p1;
	struct node *b=(struct node *)p2;
	return strcmp(a->word,b->word);
}

