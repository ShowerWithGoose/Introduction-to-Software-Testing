#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
struct node{
	char word[20];
	int cnt;
	struct node *next;
}*p,*q,*head,*p0;
int getWord(FILE *in,char *word)
{
    char c;
    while(!isalpha(c=fgetc(in)))
    	if(c==EOF)
			return EOF;
    do{
        *word++=tolower(c);
    }while(isalpha(c=fgetc(in)));
    *word='\0';
	return 1;
}
void countWord(char word[])
{
	for(p=head->next;p!=NULL;p=p->next)
	{
		if(strcmp(p->word,word)==0)//若该单词已出现过
		{
			p->cnt++;//出现次数++
			return;
		}
	}
	p0=(struct node*)malloc(sizeof(struct node));//该单词未出现，创建新结点
	strcpy(p0->word,word);
	p0->cnt=1;
	for(q=head,p=head->next;p!=NULL;q=p,p=p->next)
	{
		if(strcmp(p0->word,p->word)<0)//讲单词按字典序排序插入链表（除尾结点） 
		{
			p0->next=p;
			q->next=p0;
			return;
		}
	}
	p0->next=NULL;//插入到尾结点
	q->next=p0;
	return;
}
int main()
{
	FILE *in;
	in=fopen("article.txt","r");
	char word[20];
	head=(struct node*)malloc(sizeof(struct node));//形式头结点，不存储数据
	head->next=NULL;
	while(getWord(in,word)!=EOF)
		countWord(word);
	for(p=head->next;p!=NULL;p=p->next)
		printf("%s %d\n",p->word,p->cnt);//打印
	for(p=head;p!=NULL;p=head)
	{
		head=p->next;
		free(p);//删除链表
	}
	fclose(in);
	return 0;
}

