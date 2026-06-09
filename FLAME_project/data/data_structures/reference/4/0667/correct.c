#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char newword[1000];
FILE *in;
struct cipin{
	char word[1000];
	int num;
	struct cipin* link;
};
struct cipin* create()
{
	struct cipin* headnode=(struct cipin*)malloc(sizeof(struct cipin));
	headnode->link=NULL; strcpy(headnode->word,"!");
	return headnode;
}
int searchword(struct cipin* headlist,char newword[])
{
	struct cipin* pmove=headlist->link;
	while(pmove!=NULL)
	{
		if(strcmp(pmove->word,newword)==0)
		{
			pmove->num++; return 1;
		}
		pmove=pmove->link;
	}
	return 0;
}
void build(struct cipin* headlist,char newword[])
{
	struct cipin* newnode=(struct cipin*)malloc(sizeof(struct cipin));
	struct cipin* pos=headlist->link;
	struct cipin* posfront=headlist;
	while(pos!=NULL)
	{
		if(strcmp(newword,pos->word)<0 && strcmp(newword,posfront->word)>0) //定位 
		{
			strcpy(newnode->word,newword);
			newnode->link=pos;
			posfront->link=newnode;
			newnode->num=1;
			break;
		}
		pos=pos->link;
		posfront=posfront->link;
	}
	if(pos==NULL)
	{
		newnode->num=1; strcpy(newnode->word,newword);
		posfront->link=newnode;
		newnode->link=NULL;
	}
}
void printflist(struct cipin* headnode)
{
	struct cipin* pmove=headnode->link;
	while(pmove!=NULL)
	{
		printf("%s %d\n",pmove->word,pmove->num);
		pmove=pmove->link;
	}
}
int getsword(FILE *in,char newword[])
{
	memset(newword,'\0',31);
	char c;
	int counter=0;
	while((c=fgetc(in))!=EOF) //读入一个单词，下一次从上一次读到的地方开始读取 
	{
		if((c<'A' || (c>'Z' && c<'a') || c>'z') && counter==0) //消掉非字母 
		{
			continue;
		}
		else if((c<'A' || (c>'Z' && c<'a') || c>'z') && counter>0)
		{
			break;
		}
		else
		{
			if(c>=65 && c<=90)
				newword[counter]=c+32;
			else if(c>=97 && c<=122)
				newword[counter]=c;
			counter++;
		}
	}
	newword[counter]='\0';
	if(counter>0) return 1;
	if(counter==0) return 0; 
} //正常 
int main()
{
	int flag=0;
	in=fopen("article.txt","r");
	struct cipin* headlist=create();
	while(getsword(in,newword)!=0) //从文件中读入一个单词 
	{
		flag=0;
		flag=searchword(headlist,newword);
		if(flag==0)
		{
			build(headlist,newword);
		}
	}
	printflist(headlist);
	fclose(in);
	return 0;
}



