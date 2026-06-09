#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXWORD 32
struct node{
	char word[MAXWORD];
	int count;
	struct node *link; 
};
struct node *list=NULL;
int getword(FILE *fp,char *w);//从文件中读入单词并且存进单词数组中（不断输入并且重置） 
int main()
{
	char word[MAXWORD];
	FILE *in;
	struct node *p,*q=NULL,*r;
	int flag=0,FLAG=0;
	int int_g;
	in=fopen("article.txt","r");
    while((int_g=getword(in,word))!=EOF) 
    {
    	FLAG++;
    	flag=0;
    	if(int_g==1)
    	{
		
       	if(FLAG==1)
       	{
       		list=(struct node *)malloc(sizeof (struct node));
       		strcpy(list->word,word);
       		list->count=0;
		}
	   for(q=p=list;p!=NULL;q=p,p=p->link)
	   {
	       if(strcmp(word,p->word)<0)//此时word的ASCII码比链中小，应该插到前面 
		    {
		    	flag=1;
		        break;
		    }
		   else if (strcmp(word,p->word)==0)
		   {
			    flag=0;
				p->count++;
			    break;
		   }
		   else if(strcmp(word,p->word)>0)
		   {
		   	    flag=1;
		   	    continue;  
		   }
	   }
	   if(flag==1)
	   {
	       r=(struct node *)malloc(sizeof (struct node));
		   strcpy(r->word,word);
		   r->count=1;
		   r->link=NULL;
	       if(q==NULL)
	       {
	       	    q=(struct node *)malloc(sizeof (struct node));
	       	    strcpy(q->word,word);
	       	    q->count=1;
	       	    q->link=NULL;
		   }
	       else if(p==list)
	       {
		        r->link=list;
		        list=r;
	       }
	       else 
	       {
	       		r->link = p;
	       		q->link= r;
	       		//q = q->link;
		   }
	   } 
	}
	}
	for(p=list;p!=NULL;p=p->link)
	printf("%s %d\n",p->word,p->count);
	return 0;
	
}
int getword(FILE *fp,char *w)
{
	int c;
	while(!isalpha(c=fgetc(fp)))
	{
	if(c==EOF)
	return c;
	else continue;
    }
	do{
		*w++=tolower(c);
	}while(isalpha(c=fgetc(fp)));
	*w='\0';
	return 1;	
}


