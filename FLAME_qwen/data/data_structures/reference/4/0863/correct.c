#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <ctype.h>
typedef struct node* List;
struct node{
	char data[120];
	int num;
	List next;
};
void change(char s[])
{
	int i=0;
	int j=0;
	for(i=0;s[i]!='\0';i++)
	{
		if(s[i]>='a'&&s[i]<='z'){
			s[j++]=s[i];
		}else if(s[i]>='A'&&s[i]<='Z')
		{
			s[j++]=tolower(s[i]);
		}
	}s[j]='\0';
}
void Print(List L)
{
	if(L==NULL)
	return ;
	else
	while(L!=NULL)
	{
		printf("%s %d\n",L->data,L->num);
		L=L->next ;
	
	}
}
int main()
{
	FILE *fp;
    fp = fopen("article.txt", "r");
    char s[120];char ch;List list=NULL;List p;List tail;
    List final;List z,k,q;int flag=0;int i=0;
    while(fscanf(fp,"%c",&ch)!=EOF)
    {
    	if((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z'))
    	{
    		s[i++]=ch;
		}else
		{
			s[i]='\0';
			i=0;
			if(strlen(s)!=0)
			{
				change(s);
		    	if(list==NULL)
		    	{
		    		p=(List)malloc(sizeof(struct node));
		    		strcpy(p->data ,s);
		    		p->num =1;
		    		p->next =NULL;
		    		list=p;tail=p;
				}else
				{
					for(z=list;z!=NULL;z=z->next )
					{
						if(strcmp(z->data,s)==0)
						{
							z->num ++;
							flag=1;
							break;
						}
					}if(flag==0)
					{
						p=(List)malloc(sizeof(struct node));
			    		strcpy(p->data ,s);
			    		p->num =1;
			    		p->next =NULL;
						tail->next =p;
			    		tail=tail->next ;
					}flag=0;
				}
			}
    	
		}
			
    	
	}
	p=(List)malloc(sizeof(struct node));
	strcpy(p->data ,list->data );
	p->num =list->num ;
	p->next =NULL;
	final=p;
	flag=0;
	for(z=list->next;z!=NULL;z=z->next )
	{
		p=(List)malloc(sizeof(struct node));
		strcpy(p->data ,z->data );
		p->num =z->num ;
		p->next =NULL;
		for(k=final;k!=NULL;q=k,k=k->next )
		{
			if(strcmp(k->data ,z->data )>0)
			{
				break;
			}
		}
		if(k==final)
		{
			p->next =final;
			final=p;
		}else
		{
			q->next =p;
			p->next =k;
		}
		
	}
	Print(final);
	fclose(fp);
	return 0;
}

