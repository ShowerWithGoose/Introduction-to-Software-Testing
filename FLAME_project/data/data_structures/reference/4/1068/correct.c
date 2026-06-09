#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include <stdio.h>
typedef struct Node
{
    char word[100];
	int data;
	struct Node* next;
}Node;
//创建链表 
Node* createList()
{
	Node* headNode=(Node*)malloc(sizeof(Node));
	//headNode->data=1;
	headNode->next=NULL;
	return headNode;
}
//创建节点（子函数）
Node* createNode(char word[])
{
	Node* newNode=(Node*)malloc(sizeof(Node));
	strcpy(newNode->word,word);
    newNode->data=1;
	newNode->next=NULL;
	return newNode; 
}
//打印链表
void printfList(Node* headNode)
{
	Node* pMove=headNode->next;
	while(pMove)
	{
        printf("%s ",pMove->word);
		printf("%d\n",pMove->data);
		pMove=pMove->next;
	}
}
//尾插法
void insertLast(Node* headNode,char word[])
{
    Node* p=headNode;
	Node* newNode=createNode(word);
	while(p->next!=NULL) p=p->next;
	p->next=newNode;
}
//指定位置插入
int insertAppiont(Node* headNode,char word[],char posword[])
{
	Node* posNode=headNode->next;
	Node* posNodeFront=headNode;
	Node* newNode=createNode(word);
	if(posNode==NULL)
	return -1;
	else
	{
		while(strcmp(posNode->word,posword)!=0)
		{
		    posNodeFront=posNode;
			posNode=posNodeFront->next;
			if(posNode==NULL)
			return -1;
		}
		newNode->next=posNode;
		posNodeFront->next=newNode;
		return 1;
	}
}
//内容查找
void findNode(Node* headNode,char findword[])
{
	Node* pMove=headNode->next;
	char word[100]={0};
	int flag=0;
	if(pMove==NULL)
	{
		insertLast(headNode,findword);
		return;
	}
	else
	while(strcmp(pMove->word,findword)!=0)
	{
		if(strcmp(pMove->word,findword)>0&&flag==0)
			{
				strcpy(word,pMove->word);
				flag=1;
			}
		pMove=pMove->next;
		if(pMove==NULL&&flag==1)
        {
           insertAppiont(headNode,findword,word);
           return;
        }
		else if(pMove==NULL&&flag==0)
		{
           insertLast(headNode,findword);
		   return;
		} 
	}
	pMove->data++;
}
//释放空间
void breakList(Node* headNode)
{
	Node* pMove=headNode->next;
	Node* pMoveFront=headNode;
	while(pMove)
	{
      free(pMoveFront);
	  pMoveFront=pMove;
	  pMove=pMove->next;
	}
	free(pMoveFront);
}
int main()  
{
 FILE *in;
 in=fopen("article.txt","r");
 char word[100]={0};
 char c;
 Node* article=createList();
 memset(article,0,sizeof(article));
 int k=0;
 while((c=fgetc(in))!=EOF)
 {
     if((c>='a'&&c<='z')||(c>='A'&&c<='Z'))
         word[k++]=tolower(c);
     else
		 if(k!=0)
		 {
       findNode(article,word);
       k=0;
       memset(word,0,sizeof(word));
		 }
 }
 printfList(article);
 fclose(in);
 breakList(article);
 return 0;
}
