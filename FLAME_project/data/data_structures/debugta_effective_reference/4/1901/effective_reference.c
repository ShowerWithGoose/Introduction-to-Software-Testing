#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#define MAX 32

struct node{
	char w[MAX];
	int count;
	struct node*link;
};

struct node*wordlist=NULL;
int getword(FILE*bfp,char*w);
int isNull(char t);
int searchword(char*w);
int insertword(struct node*x,char*w);

int main()
{
	char w[MAX];
	FILE*bfp;
	struct node*x;
	
	bfp=fopen("article.txt","r");
	while(getword(bfp,w)!=EOF)
	{
		searchword(w);
	}
	
	for(x=wordlist;x!=NULL;x=x->link)
	{
		printf("%s %d\n",x->w,x->count);
	}
	
	fclose(bfp);
	return 0;
}

int getword(FILE*bfp,char*w)
{
	char t;
	int j=0;
	while((t=fgetc(bfp))!=EOF)
	{
		if(isNull(t)&&(j<=0))
		{
			continue;
		}
		else if(isNull(t)&&(j>0))
		{
			break;
		}
		if(t>='A'&&t<='Z')
		{
			t=t+'a'-'A';
		}//若为大写转换为小写 
		w[j++]=t;
	}
	w[j]='\0';
	if(j>0)return 1;
	else return -1;
}

int isNull(char t)
{
	return !(((t>='a'&&t<='z')||(t>='A'&&t<='Z')));
}

int insertword(struct node*r,char*w)
{
    struct node*t;
    
    t = (struct node * )malloc(sizeof(struct node));
    if(t == NULL) return -1; //没有内存空间
    strcpy(t->w, w);       //装填好一个初始值
    t->count = 1;                 // 词频初值为1
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
	struct  node *x, *y=NULL; //q为p的前序结点指针
	for(x=wordlist; x != NULL; y=x,x=x->link){
    if(strcmp(w, x->w) < 0) 
 	break;
    else if(strcmp(w, x->w) == 0){
         x->count++;
         return 0 ;    // 找到加1,直接返回
    }
}
return insertword(y, w); // 存在q为NULL
}                                                 // 和q非空两种可能




