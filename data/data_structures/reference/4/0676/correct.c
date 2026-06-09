#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
struct node{
	char word[30];
	int  num;
	struct node *link;
};
typedef struct node Node;
typedef struct node* Nodeptr;

char ch;
int main()
{
	FILE *fp;
	fp=fopen("article.txt","r");
	
	int i=0,j=0;
	Nodeptr p,q,list=NULL;
	
	ch=fgetc(fp);
	while(ch!=EOF)
	{
		if(isalpha(ch)==0)//跳过非字母字符 
		{
			ch=fgetc(fp);
			continue;
		}
		i=0;
		q=(Nodeptr)malloc(sizeof(Node));//新建链节
		while(isalpha(ch)) //读取单个单词 
		{
			ch=tolower(ch);//转换大写为小写
			q->word[i++]=ch; 
			ch=fgetc(fp);
		}
		q->word[i]='\0';
		q->num=1;
		q->link=NULL;
		if(list==NULL)
		{
			list=p=q;
		}
		else
		{
			for(p=list;p!=NULL;p=p->link)
			{
				
				if(strcmp(q->word,p->word)==0)
				{
					(p->num)++;
					break;
				}
				else if(strcmp(q->word,list->word)<0)
				{
					q->link=list;
					list=q;
					break;
				}
				else if(p->link==NULL)
				{
					p->link=q;
					break;
				}
				else if(strcmp(q->word,p->word)>0&&strcmp(q->word,p->link->word)<0)//q插入p后 
				{
					q->link=p->link;
					p->link=q;
					break;
			    }
			}
		}
//		ch=fgetc(fp);//读取下一个字符 
	}
	
	for(p=list;p!=NULL;p=p->link)
	{
		printf("%s %d\n",p->word,p->num);
	}
	return 0;
}





