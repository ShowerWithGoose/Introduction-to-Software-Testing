#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#define MAX 32

struct node{
	char word[MAX];
	int sum;
	struct node*link;
};

struct node*wordlist=NULL;
int getword(FILE*bfp,char*w);
int isNull(char c);
int searchword(char*w);
int insertword(struct node*p,char*w);

int main()
{
	char word[MAX];
	FILE*bfp;
	struct node*p;
	
	bfp=fopen("article.txt","r");
	while(getword(bfp,word)!=EOF)
	{
		searchword(word);
	}
	
	for(p=wordlist;p!=NULL;p=p->link)
	{
		printf("%s %d\n",p->word,p->sum);
	}
	
	fclose(bfp);
	return 0;
}

int getword(FILE*bfp,char*w)
{
	char c;
	int count=0;
	while((c=fgetc(bfp))!=EOF)
	{
		if(isNull(c)&&(count<=0))
		{
			continue;
		}
		else if(isNull(c)&&(count>0))
		{
			break;
		}
		if(c>='A'&&c<='Z')
		{
			c=c+'a'-'A';
		}//若为大写转换为小写 
		w[count++]=c;
	}
	w[count]='\0';
	if(count>0)return 1;
	else return -1;
}

int isNull(char c)
{
	return !(((c>='a'&&c<='z')||(c>='A'&&c<='Z')));
}

int insertword(struct node*r,char*w)
{
    struct node*t;
    
    t = (struct node * )malloc(sizeof(struct node));
    if(t == NULL) return -1; //没有内存空间
    strcpy(t->word, w);       //装填好一个初始值
    t->sum = 1;                 // 词频初值为1
    t->link = NULL;              
    if(wordlist == NULL) //1:空链表,插入t结点
        wordlist = t;
    else if (r == NULL){  //2:首(头)结点前插入t
        t->link = wordlist;
        wordlist = t;
       }
    else {                       // 3:在r结点后插入t
          t->link = r->link;
          r->link = t;
       }
      return 0;
}

int searchword(char *w)
{
	struct  node *p, *q=NULL; //q为p的前序结点指针
	for(p=wordlist; p != NULL; q=p,p=p->link){
    if(strcmp(w, p->word) < 0) 
 	break;
    else if(strcmp(w, p->word) == 0){
         p->sum++;
         return 0 ;    // 找到加1,直接返回
    }
}
return insertword(q, w); // 存在q为NULL
}                                                 // 和q非空两种可能




