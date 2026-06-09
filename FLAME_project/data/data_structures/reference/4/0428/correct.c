#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct Node
{
	char s[20];
	int cnt;
	struct Node* next;
}node;
node *r,*last,*list,*keep;
int num=0;
void search(char*);

int main()
{
	FILE* in;
	in=fopen("article.txt","r");
	char str[100],*p,*q;
	int i,len,flag;
	while(fgets(str,100,in)!=NULL)
	{
		p=str;
	    len=strlen(str);
	    flag=0;
	    for(i=0;i<len;i++)
	    {
	    	if(isupper(str[i]))
	    	str[i]+='a'-'A';
		}
		while(p-str<=len)
		{   while(!isalpha(*p))
		    {
		    	if(p-str==len)
		    	{   flag=1;
		    		break;
				}
			p++;
			}if(flag==1)
			break;
			q=p;
		    while(isalpha(*q))
		    q++;
		    *q='\0';
			if(!num)
		{   list=(node*)malloc(sizeof(node));
			strcpy(list->s,p);
			list->cnt=1;
		    list->next=NULL;
		    last=list;
			num++; 
		}	
		else 
			search(p);
		    p=q;	
		}
	}
	for(i=0,r=list;i<num;i++)
	{printf("%s %d\n",r->s,r->cnt);
	keep=r;
	r=r->next;
	free(keep);
	}
	return 0;
}
void search(char*w)
{   node*r=list,*q;	
    if(strcmp(w,r->s)<0)
    {
    	q=(node*)malloc(sizeof(node));
    	strcpy(q->s,w);
		q->cnt=1;
		q->next=list;
		list=q;
		num++;
		return;
	}
	 else if(strcmp(w,r->s)==0)
	 {
	 	r->cnt++;
	 	return ;
	 }
   	while(r->next!=NULL)
	{
		if(strcmp(r->next->s,w)<0)
	{r=r->next;
	}
	else if(strcmp(r->next->s,w)==0)
	{
		r->next->cnt++;
		return;
	}
	else 
	{
		q=(node*)malloc(sizeof(node));
		strcpy(q->s,w);
		q->cnt=1;
		q->next=r->next;
		r->next=q;
		num++;
		return ;
	}
    }
		q=(node*)malloc(sizeof(node));
		strcpy(q->s,w);
		q->cnt=1;
		q->next=NULL;
		num++;
		last->next=q;
		last=q;
		return;
}




