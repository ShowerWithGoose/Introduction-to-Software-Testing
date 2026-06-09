#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#include<ctype.h>
typedef struct node{
	char word[50];
	int count;
	struct node* next;
} *wordl,wordli;
wordl head=NULL;
FILE *in;
char tmp;
int Insertword(wordl p,char* w)
{
	wordl q;
	q=(wordl)malloc(sizeof(wordli));
	if(q==NULL)return -1;//无内存空间 
	strcpy(q->word,w);
	q->count=1;
	q->next=NULL;
	if(head==NULL)
	{
		head=q;	
	}
	else if(p==NULL)//插入头结点后 
	{
		q->next=head;
		head=q;
	}
	else{
		q->next=p->next;
		p->next=q;
	}
	return 0;
}
int searchWord(char *w)
{
	wordl p , q=NULL;//q为p的前序结点指针
	for(p=head;p!=NULL;q=p,p=p->next)
	{
		if(!strcmp(w,p->word))
		{
			p->count++;
			return 0;
		}
		else if(strcmp(w,p->word)<0)
		{
			break;
		}
	} 
	return Insertword(q,w);
}
int getword(FILE *bfp,char word[])
{
	int i=0;
	char temp;
	while((temp=fgetc(bfp))!=EOF)
	{
		if(isalpha(temp))
		{
			word[i]=tolower(temp);
			i++;
		}
		else if(i>0){
		word[i]='\0';
		return 0;  }
	} 
	return EOF;
}
int main(){
 in= fopen("article.txt","r");
 char word[50];
while(getword(in,word)!=EOF)
{
	if(searchWord(word)==-1)
	{
		return -1;
	}
}
wordl p;
for(p=head;p!=NULL;p=p->next)
{
	printf("%s %d\n",p->word,p->count);
}
fclose(in);
return 0;
}

