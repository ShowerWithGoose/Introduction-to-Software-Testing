#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	struct node{
		char str[100];
		int num;
		struct node *link;
	};
	typedef struct node Node;
	typedef struct node* Nodeptr;
	Nodeptr list,p,p1;
	list=p=p1=NULL;
	p1=(Nodeptr)malloc(sizeof(Node));	//头指针 
	strcpy(p1->str,"");
	p1->link=NULL;
	list=p1;
	FILE *in=fopen("article.txt","r");
	char c;
	char s[100]="";
	while((c=fgetc(in))!=EOF)
	{
		char temp[2]="";
		if((c>='A' && c<='Z') || (c>='a' && c<='z') )
		{ 
			if(c>='A' && c<='Z')
				c = c-'A'+'a';
			temp[0]=c;
			temp[1]='\0';
			strcat(s,temp);
		}else if(s[0]>='a' && s[0]<='z'){
			p1=(Nodeptr)malloc(sizeof(Node));
			strcpy(p1->str,s);
			p1->link=NULL;
			p1->num=1;
			p=list;
			while(1)
			{
				if(list==NULL)
				{
					list=p1;
					break;
				}
				if(strcmp(p->str,p1->str)==0)
				{
					p->num++;
					free(p1);
					break;
				}else if(p->link==NULL || strcmp(p->link->str,p1->str)>0){		//将p1插入
					p1->link = p->link;
					p->link = p1;	// b d
					
//					p=list;
//					do{
//						printf("%s %d\n",p->str,p->num);
//						p=p->link;
//					}while(p!=list);
//					putchar(10);
					
					break;
				}
				p=p->link;
			}
			memset(s,'\0',99);
		}
		
	}
	p=list->link;
	do{
		printf("%s %d\n",p->str,p->num);
		p=p->link;
	}while(p!=NULL);
	
	return 0;
}

