#include<stdio.h>  //如果两个单词之间是逗号而不是空格。。。 
#include<stdlib.h>
#include<string.h>
#define N 1024
typedef struct node{
	char word[N];
	int cnt;
	struct node *link;
}Words,*wordsptr;
Words *list=NULL,*p,*q,*p0=NULL;
void deposit(char *ps);
int isalp(char c)
{
	if((c>='A'&&c<='Z')||(c>='a'&&c<='z')) return 1;
	else return -1;
}
int main()
{
	char s[N],ts[N];
	char *ps;
	int i,j;
	FILE *in;
	in=fopen("article.txt","r");
	
	while(fscanf(in,"%s ",s)!=EOF)
	{
		ps=s;   //指向该字符串的指针 
		for(j=0;s[j]!='\0'&&isalp(s[j])==-1;j++) ps++; //最前面的字符如果不是字母去掉  
		//如果没有判断\0,会读取\0以后的数据！！！ 
		for(i=0;ps[i]!='\0';i++)
			if(ps[i]>='A'&&ps[i]<='Z') ps[i]=ps[i]-'A'+'a'; //都转换为小写字母 
			
		j=0;
		for(i=0;ps[i]!='\0';i++)
		{
			if(isalp(ps[i])==1) ts[j++]=ps[i];  //ts[]存放取出的单词 
			else
			{
				if(j==0) continue;  //如果是连续的标点符号直接跳到下一个 
				ts[j]='\0';
				deposit(ts);
				j=0;
			}
		}
		if(ps[i]=='\0'&&j!=0) // 考虑最后一个字符是字母的情况 
		{
			ts[j]='\0';
			deposit(ts); 
		}
	
	}
	//输出 
	for(p=list;p!=NULL;)
	{
		printf("%s %d\n",p->word,p->cnt);
		q=p;
		p=p->link;
		free(q);
	}
	fclose(in);
	return 0;
}



void deposit(char *ps)
{
		q=(wordsptr)malloc(sizeof(Words));
		q->link=NULL;  q->cnt=1;
		strcpy(q->word,ps);
		if(list==NULL) list=p=q;
		else
		{
			for(p=list;p!=NULL&&strcmp(q->word,p->word)>0;p0=p,p=p->link)
			;
			if(p==NULL) p0->link=q;
			else if(strcmp(q->word,p->word)==0)  //在此之前得先判断p是否为NULL  ！！！ 
			{
				p->cnt++; free(q);
			}
			else if(p==list)  //插入头结点 
			{
				q->link=list;
				list=q;
			}
			else
			{
				q->link=p;
				p0->link=q;
			}
		}
}

