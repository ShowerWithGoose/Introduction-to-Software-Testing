#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define maxn 50
#include<ctype.h>

typedef struct node{
	char a[maxn];
	int count;
	struct node* link;
}Node,*Nodeptr;

Nodeptr List=0;

void insert(char a[])
{
	if(List==0)
	{
		List=(Nodeptr)malloc(sizeof(Node));
		strcpy(List->a,a);
		List->count=1;
		List->link=0;
	}else{
		if(strcmp(List->a,a)>0){
			Nodeptr ptr=(Nodeptr)malloc(sizeof(Node));
			ptr->count=1;
			strcpy(ptr->a,a);
			ptr->link=List;
			List=ptr;
		}else{
			Nodeptr r=List,p;
			while(r!=0&&strcmp(r->a,a)<0){
				p=r;r=r->link;
			}
			if(r==0)
			{
				Nodeptr ptr=(Nodeptr)malloc(sizeof(Node));
				ptr->count=1;
				strcpy(ptr->a,a);
				ptr->link=0;
				p->link=ptr;
			}else if(strcmp(r->a,a)==0){
				r->count++;
			}else{
				Nodeptr ptr=(Nodeptr)malloc(sizeof(Node));
				ptr->count=1;
				strcpy(ptr->a,a);
				ptr->link=r;p->link=ptr;
			}
		}
	}
}

char buf[10000];
char word[maxn];

int main()
{
	FILE * in;
	in=fopen("article.txt","r");
	while(fgets(buf,10000,in))
	{
		int flag=0;int cnt=0;
		for(int i=0;i<strlen(buf);i++)
		{
			if(flag)
			{
				if(!isalpha(buf[i]))
				{
					insert(word);
					memset(word,0,sizeof(word));
					cnt=0;flag=0;
				}else{
					buf[i]=tolower(buf[i]);
					word[cnt++]=buf[i];
				}
			}else
			{
				if(isalpha(buf[i])){
					flag=1;word[cnt++]=tolower(buf[i]);
				}
			}
		}
	} 
	for(Nodeptr it=List;it!=0;it=it->link)
	{
		printf("%s %d\n",it->a,it->count);
	}
	fclose(in);
}

