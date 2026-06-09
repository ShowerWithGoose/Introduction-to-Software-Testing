#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct words
{
	char *word;
	int num;
	struct words *next;
};
typedef struct words words;
typedef words *nptr;
nptr getnode()
{
	return (nptr)malloc(sizeof(words));
}
int size;
nptr st,en;
int compare(char *a,char *b)//按照字典序比较单词的顺序 
{
	int t=0;
	int shuo=strlen(a),bao=strlen(b);
	if(shuo==bao)
	{
		for(int i=0;i<shuo;i++)
		{
			if(a[i]<b[i]) t=1;
			else if(a[i]>b[i]) t=-1;
			if(t!=0) break;
		}
	}
	else if(shuo<bao)
	{
		for(int i=0;i<shuo;i++)
		{
			if(a[i]<b[i]) t=1;
			else if(a[i]>b[i]) t=-1;
			if(t!=0) break;
		}
		if(t==0) t=1;
	}
	else if(shuo>bao)
	{
		for(int i=0;i<bao;i++)
		{
			if(a[i]<b[i]) t=1;
			else if(a[i]>b[i]) t=-1;
			if(t!=0) break;
		}
		if(t==0) t=-1;
	}
	return t;
	//1：a在b之前 0：a和b相等 -1：a在b之后 
}
void newnode(char *a)//按位置插入单词 
{
	int la=strlen(a);
	char *now=(char*)malloc((la+4)*sizeof(char));
	for(int i=0;i<la;i++)
	now[i]=a[i];
	if(size==0)//创建链表 
	{
		size=1;
		nptr p=getnode();
		p->word=now;
		p->num=1;
		st=p;
		st->next=NULL;
		en=st;
	}
	else
	{
		if(compare(a,st->word)>0) //a是首个单词 
		{
			nptr p=getnode();
			p->num=1;
			p->word=now;
			p->next=st;
			st=p;
		} 
		else if(compare(a,st->word)==0) st->num++;
		else if(compare(a,en->word)<0) //a是最后一个单词 
		{
			nptr p=getnode();
			p->num=1;
			p->word=now;
			p->next=NULL;
			en->next=p;
			en=en->next;
		}
		else if(compare(a,en->word)==0) en->num++;
		else //a在中间有相同单词，或者a在中间，但是没有和a相同的单词 
		{
			int m=-1;
			nptr k;
			if(st->next==NULL)
			{
				nptr p=getnode();
				p->num=1;
				p->word=a;
				p->next=NULL;
				st->next=p;
				en=p;
			}
			for(nptr p=st;p!=NULL;p=p->next)
			{
				m=compare(a,(p->next)->word);//为了方便后续操作，与下一个词进行比较 
				k=p;
				if(m!=-1) break;//a等于或前于当前单词(k) 
			}
			if(m==0) (k->next)->num++;//当前词数量加一
			else //将p插在中间 
			{
				nptr p=getnode();
				p->num=1;
				p->word=now;
				p->next=k->next;
				k->next=p;
			} 
}
		}
}
char homo[10001];
void getwords()
{
	FILE *file1;
	file1=fopen("article.txt","r");
	char huge;
	int i=0;
	int moca=0;
	int ran=1;
	while(fscanf(file1,"%c",&huge)!=EOF)
	{
		if((huge>='A') && (huge<='Z')) huge=huge-'A'+'a';//大写变成小写 
		if((huge>='a') && (huge<='z'))
		{
			moca=1;
			homo[i]=huge;
			i++;
		}
		else if(moca==1)
		{
			moca=0;
			i=0;
			newnode(homo);
			memset(homo,0,sizeof(homo));
		}
	} 
}
int main()
{
	getwords();
	for(nptr p=st;p!=NULL;p=p->next) printf("%s %d\n",p->word,p->num);
	return 0;
}

