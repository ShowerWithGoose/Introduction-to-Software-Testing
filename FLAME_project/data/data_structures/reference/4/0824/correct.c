#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <math.h>
#define  PR printf
typedef long long LL;
FILE *in;

struct node{
	char s[100];
	int num;
	struct node *next;
};
typedef struct node *NodePtr;
typedef struct node Node;
NodePtr head,m,t;
NodePtr p,q,r;
int flag=0;
void Addtolist(NodePtr list,char ch[]);
int judge(char s[])
{
	int i,len;
	len=strlen(s);
	for(i=0;i<len;i++)
	{
		if(s[i]>='a'&&s[i]<='z')return 1;
	}
	return 0;
}
int main()
{
	char cent[2000],word[100];
	int i,j,len;
	in = fopen("article.txt","r");
	if(in == NULL)
	{
		PR("ERROR!");
		return 0;
	}
	
	head = m = NULL; 
	while(fgets(cent,1999,in)!=NULL)
	{
		len=strlen(cent);
		for(j=i=0;i<len;i++)
		{
			if(cent[i]>='A'&&cent[i]<='Z')
			{
				word[j]=tolower(cent[i]);
				j++;
				
			}
			else if(cent[i]>='a'&&cent[i]<='z')
			{
				word[j]=cent[i];
				j++;
			}
			else 
			{
				word[j]='\0';
				if(judge(word)==1){
					j=0;
					//printf("---------%s\n",word);
					//Addtolist(head,word);
					/*if(head==NULL)
					{
						q=(NodePtr)malloc(sizeof(Node));
						strcpy(q->s,word);
						q->num=1;
						q->next=NULL;
						head = q;
						t=head;
						while(t!=NULL)
						{
							printf("%s %d\n",t->s,t->num);
							t=t->next;
						}
						j=0;
						continue;
					}
					flag=0;*/
					int w;
					if(head==NULL)
					{
						q=(NodePtr)malloc(sizeof(Node));
						strcpy(q->s,word);
						q->num = 1;
						q->next=NULL;
						head = q;
						
					}
					else{
						r=head;
						for(p=head;p!=NULL;r=p,p=p->next)
						{
							w=strcmp(word,p->s);
							if(w<=0)
							{
								break;
							}
						}
						if(w==0)
						{
							p->num++;
						}
						else if(p==head)
						{
							q=(NodePtr)malloc(sizeof(Node));
							strcpy(q->s,word);
							q->num = 1;
							q->next = head;
							head = q;
						}
						else if(p==NULL)
						{
							q=(NodePtr)malloc(sizeof(Node));
							strcpy(q->s,word);
							q->num = 1;
							q->next = NULL;
							r->next = q;
							
						}
						
						else 
						{
							q=(NodePtr)malloc(sizeof(Node));
							strcpy(q->s,word);
							q->num = 1;
							r->next = q;
							q->next = p;
						}
					}
					t=head; 
					/*while(t!=NULL)
					{
						printf("%s %d\n",t->s,t->num);
						t=t->next;
					}*/
								
								
							}
							
						}
					}
	}
	for(t=head;t!=NULL;t=t->next)
	{
		printf("%s %d\n",t->s,t->num);
	}
	return 0;
	
} 

void Addtolist(NodePtr head,char ch[])
{
	NodePtr p,q,r;
	int w;
	if(head==NULL)
	{
		q=(NodePtr)malloc(sizeof(Node));
		strcpy(q->s,ch);
		q->num = 1;
		head = q;
		return ;
	}
	r=head;
	for(p=head;p!=NULL;r=p,p=p->next)
	{
		w=strcmp(ch,p->s);
		if(w<=0)
		{
			
			break;
		}
	}
	if(p==NULL)
	{
		q=(NodePtr)malloc(sizeof(Node));
		strcpy(q->s,ch);
		q->num = 1;
		r->next = q;
		q->next = NULL;
	}
	else if(w==0)
	{
		p->num++;
	}
	else 
	{
		q=(NodePtr)malloc(sizeof(Node));
		strcpy(q->s,ch);
		q->num = 1;
		r->next = q;
		q->next = p;
	}
	for(t=head;t!=NULL;t=t->next)
	{
		printf("%s %d\n",t->s,t->num);
	}
	return ;
}

/*insertNode(Nodeptr list, ElemType elem)
{ 
    Nodeptr p,q, r;
    r = (Nodeptr)malloc(sizeof(Node)); //创建一个数据项为elem的新结点
    r->elem = elem;   r->link = NULL;
    if(list == NULL) 	  list是一个空表 
        return r;
    for(p=list; elem > p->elem && p != NULL;  q = p, p = p->link)  找到插入位置 
        ;
    if( p == list){  在头结点前插入 
        r->link = p;
        return r;
    } 
    else { 在结点q后插入一个结点 
        q->link = r;
        r->link = p;
    }
    return list;
}
*/

