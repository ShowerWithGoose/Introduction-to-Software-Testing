#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define tolower(c) (c>='A'&&c<='Z'?'a'-'A'+c:c)

struct node{
	int count;
	char word[32];
	struct node *link;
};

typedef struct node danci;
danci *Wordlist = NULL;
char word[32];

/*在链表中p结点后插入包含给定单词的结点，同时置次数为1*/
int insertWord(struct node *p,char *w)
{
	struct node  *q;
	q = (struct node *)malloc(sizeof(struct node));
	strcpy(q->word, w);
	q->count = 1;
	q->link = NULL;              
	if(Wordlist == NULL) //空链表
	   Wordlist = q;
	else if (p == NULL){ //插入到第一个结点前
	   q->link = Wordlist;
	   Wordlist = q;
	}
	else {
	   q->link = p->link;
	   p->link = q;
	}
	return 0;
}

/*在链表中查找一单词，若找到，则次数加1；否则将该单词插入到有序表中相应位置，同时次数置1*/
int searchWord(char *w)
{
	struct node *p, *q=NULL; //q为p的前序结点指针
	//顺序查找
	for(p=Wordlist; p != NULL; q=p,p=p->link){
	    if(strcmp(w, p->word) < 0) 
	 		break;
	    else if(strcmp(w, p->word) == 0){//找到
	         p->count++;
	         return 0 ;
	    }
	}
	return insertWord(q, w);
}

char m = 0;
int getword(FILE *p)
{
	int k = 0;
	 
    while(m != EOF)
    {
    	m = fgetc(p);
    	if(isalpha(m) != 0){
    		word[k++] = tolower(m);
    		break;
		}
	}

	while(m != EOF)
	{
		m = fgetc(p);
		if(isalpha(m) != 0)
		{
			word[k++] = tolower(m);
		}
		else
			break;
	}
	
	word[k] = '\n';
	k = 0;
	
	if(m == EOF)
		return -1;
	else
		return 0;
}

int main()
{
    FILE *in;
    in = fopen("article.txt","r");
	struct node *p;
    int n;
    while( getword(in) == 0) //从文件中读入一个单词
    {
       	searchWord(word);
       	memset(word,0,sizeof(word));
	} 
        
    for(p=Wordlist; p != NULL; p=p->link) //遍历输出单词表
       {
	 for(n = 0;n<strlen(p->word)-1;n++)
			printf("%c",p->word[n]);
		printf(" %d\n",p->count);}
    fclose(in);
    return 0;
} 


