#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<malloc.h>

typedef struct Node{
	char word[100];
	int count;
	struct Node * link;
}NODE,*PNODE;
PNODE Wordlist=NULL;//定义单词表头指针
int getWord(FILE *fp,char *str);//从文件中读取单词 
int isNull(char c);
int searchWord(char w[]);
int insertWord(PNODE p,char w[]);
void traverse(PNODE list);
int getLength(PNODE list);
 
int main()
{
	char word[100];
	FILE *fp = fopen("article.txt","r");

	
	while((getWord(fp,word)!=EOF))
	{
		searchWord(word);
//		printf("%s\n",word);
	}
	
//	printf("%d\n",getLength(Wordlist));
	traverse(Wordlist);
	return 0;
}

int getWord(FILE *fp,char *str)
{
	char c;
	int counter = 0;
	while((c = fgetc(fp)) != EOF){
		if( isNull(c) && (counter <= 0)){
			//消去非字母字符
			continue;
		}
		else if(isNull(c) && (counter > 0)){
			//一个单词读取完毕
			break;
		}
		str[counter++] = tolower(c); //将大写字母都转化成小写字母 
	}
	str[counter] = '\0';
	
	if(counter > 0)//读入成功返回1 
		return 1;
	else//读入不成功返回-1 
		return -1;
}
int isNull(char c)
{
	return !((c>='a'&&c<='z')||(c>='A'&&c<='Z'));
	//是字母则返回0 不是字母返回1 
}

//在链表中p节点之后插入包含给定单词的节点，同时置次数为1 
int insertWord(PNODE p,char w[100])
{
	PNODE q;
	
	q=(PNODE)malloc(sizeof(NODE));
	if(q==NULL)return -1;//没有内存空间 
	strcpy(q->word,w);
	q->count = 1;
	q->link = NULL;
	if(Wordlist == NULL) //空链表 
		Wordlist = q;
	else if(p == NULL)	//插入到头结点之前 
	{
		q->link = Wordlist;
		Wordlist = q;
	}
	else
	{
		q->link = p->link;
		p->link = q;
	}
	return 0;
}
//在链表中查找单词，找到次数加一，未找到则插入 
int searchWord(char w[100])
{
	PNODE p,q=NULL;//q为p的前序节点指针
	for(p=Wordlist;p!=NULL;q=p,p=p->link)
	{
		if(strcmp(w,p->word)<0) 
		/*如果w是比较靠前的单词，则先退出循环 将w存入到单词表中 */
			break;
		if(strcmp(w,p->word)==0)
		{
			p->count++;
			return 0;
		}
			
	}
	return insertWord(q,w);
}
void traverse(PNODE list)
{
	PNODE p = list;
	for(p = list; p!= NULL;p = p->link)
		printf("%s %d\n",p->word,p->count);
}
int getLength(PNODE list)
{
	PNODE p;//p为遍历链表节点的指针
	int n = 0;
	for(p = list;p != NULL; p = p->link)
		n++;
	return n;
}



