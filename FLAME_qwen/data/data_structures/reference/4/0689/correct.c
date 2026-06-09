#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#define max(a,b) (a>b?a:b)
struct word{
	char content[100];
	int num;
};
int cmp(const struct word *a,const struct word *b)
{
	return strncmp(a->content,b->content,max(strlen(a->content),strlen(b->content)));
}
void digitchange(FILE *in1,FILE *in2)//将文档中所有字符存为纯小写字母单词+空格 
{
	char a;
	while(a=fgetc(in1),a!=EOF)
	{
	    if(isalpha(a))
	    {
	    if(a>='A'&&a<='Z')
			fprintf(in2,"%c",a+32);
		else if((a>='a'&&a<='z'))
		    fprintf(in2,"%c",a);
		}
		else
		    fprintf(in2," ");
	}
}
typedef struct word wordcount;
wordcount a[1000];
int main()
{
	FILE *in1,*in2;
	in1=fopen("article.txt","r");
	in2=fopen("article1.txt","w");
	char words[100];
	int i,j,k=0,flag;
	digitchange(in1,in2);
	fclose(in2);
	in2=fopen("article1.txt","r");
	while(fscanf(in2,"%s",words)!=EOF)
	{
	    flag=0;
		for(i=0;i<k;i++)
		{
			if(!strcmp(a[i].content,words))
			{
				a[i].num++;
				flag=1;
			}
		}
		if(flag==0)
		{
			strcpy(a[k].content,words);
			a[k].num=1;
			k++;
		}
	}
	qsort(a,k,sizeof(wordcount),cmp);
	for(i=0;i<k;i++)
	{
		printf("%s %d\n",a[i].content,a[i].num);
	 } 
	fclose(in1);
	fclose(in2);
	return 0;
}

