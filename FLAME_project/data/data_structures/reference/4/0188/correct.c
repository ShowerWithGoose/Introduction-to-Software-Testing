#include<stdio.h>
#include<string.h>
char temp[1000];
struct cate
{
	char word[1000];
	int count;
	struct cate *link;
};
typedef struct cate node;
typedef struct cate *nodeptr;
char wdcrt(char c)
{
	if(c>='A'&&c<='Z') return c-'A'+'a';
	else return c;
}
nodeptr st=NULL;
nodeptr creat(void)
{
	nodeptr p;
	p=(nodeptr)malloc(sizeof(node));
	int i=0;
	for(;i<=strlen(temp);i++)
		p->word[i]=temp[i];
	p->count=1;
	p->link=NULL; 
	return p;
}
int add(void)
{
	//为空 
	if(st==NULL)
	{
		st=creat();
	}
	else//有单词 
	{
		nodeptr p,q;
		p=st,q=NULL;
		while(strcmp(temp,p->word)>=0)
		{
			q=p;
			p=p->link;
			if(p==NULL) break;
		}
		//第一个
		if(q==NULL)
		{
			q=st;
			st=creat();
			st->link=q;
		}
		//相同 
		else if(strcmp(temp,q->word)==0)
		{
			//printf("_%s++_",q->word); 
			q->count++;
		}
		//不是第一个 
		else
		{
			p=q->link;
			q->link=creat();
			q->link->link=p;
		}
	}
}
int main()
{
	FILE *fr=fopen("article.txt","r");
	char s[100000];
	while(fgets(s,100000,fr)!=NULL)
	{
		int len=strlen(s);
		int i=0;
		int j=0;
		for(;i<len;i++)
		{
			if((s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='Z'))
			{
				temp[j]=wdcrt(s[i]);
				j++;
			}
			else if(j!=0)
			{
				temp[j]=0;
				//printf("*%s*",temp);
				add();
				j=0;
			}
		}
	}
	while(st!=NULL)
	{
		printf("%s %d\n",st->word,st->count);
		st=st->link;
	}
	return 0;
}

