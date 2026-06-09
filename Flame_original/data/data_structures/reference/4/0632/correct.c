#include<stdio.h>
#include<string.h>
#include<stdlib.h>
FILE *in;
struct node{
	char word[51];
	int count;
	struct node* link;
	struct node* before;
}*p,*now,*wordlist,*pp;
char s[2005],c[51];
int i,j,haha;
void DatoXiao(char s[]);
struct node* search(char c[]);
struct node* ssearch(char c[]);
int main()
{
	in=fopen("article.txt","r");
	while(fgets(s,2001,in)!=NULL)
	{
		DatoXiao(s);
		i=0;j=0;
		while(s[i]!='\0')
		{
			while(!(s[i]>='a'&&s[i]<='z')&&s[i]!='\0')
			{
				i++;
				j=0;
			}
			if(s[i]=='\0') break;
			while(s[i]>='a'&&s[i]<='z'&&s[i]!='\0')
			{
				c[j]=s[i];
				j++;
				i++;
			}
			if(s[i]=='\0') break;
		   c[j]='\0';
		   pp=search(c);
		   if(pp==NULL)
		   {
		   	p=(struct node*)malloc(sizeof(struct node));
		   	strcpy(p->word,c);
		   	p->count=1;
		   	p->link=NULL;
		   	p->before=NULL;
		   	if(wordlist==NULL)
		   	{
		   		wordlist=p;
		   		now=wordlist;
		   		
			   }
			else
			{
				pp=ssearch(c);
				if(pp==wordlist)
				{
					p->link=wordlist;
					wordlist->before=p;
					wordlist=p;
				}
				else
				{
					if(pp==NULL)
					{
						p->before=now;
						now->link=p;
						now=p;
					}
					else
					{
						//printf("%s\n",pp->word);
						p->before=pp->before;
						(pp->before)->link=p;
						pp->before=p;
					    p->link=pp;
					}
					
					
				}
				
				
			}
		   	
		   }
		   else
		   {
		   	pp->count++;
		   }
		
		
		
		
		/*p=wordlist;
		printf("%d\n",haha);
		haha++;
	while(p!=NULL)
	{
		printf("%s %d\n",p->word,p->count);
		now=p;
		p=p->link;
		
	}*/
    	}	
    //printf("*****\n");
	}
	p=wordlist;
	while(p!=NULL)
	{
		printf("%s %d\n",p->word,p->count);
		now=p;
		p=p->link;
		free(now);
	}
	return 0;
 } 
 void DatoXiao(char s[])
 {
 	int i=0;
 	while(s[i]!='\0')
 	{
 		if(s[i]>='A'&&s[i]<='Z')
 		 s[i]=s[i]-'A'+'a';
 		 i++;
	  } 
	return ;
 }
 struct node* search(char c[])
 {
 	if(wordlist==NULL)
 	 return NULL;
 	struct node* pp=wordlist;
 	while(pp!=NULL)
 	{
 		if(strcmp(pp->word,c)==0)
 		 {
 		 	return pp;
		  }
		else pp=pp->link;   
	 }
	if(pp==NULL)
 	 return NULL; 
 }
 struct node* ssearch(char c[])
 {
 	struct node* pp=wordlist;
	if(strcmp(wordlist->word,c)>0)
 		 return wordlist;
 	while(pp!=NULL)
 	{
 		
 	
		if(pp->link!=NULL)
		{
			if(strcmp(pp->word,c)<0&&
		       strcmp((pp->link)->word,c)>0)
 		    {
 		     	return pp->link;
		    }
	    	else pp=pp->link; 
		
		}  
		else
		 {
		 	if(strcmp(pp->word,c)<0)
 		    {
 		     	return NULL;
		    }
		    
	    	
		 }
		
	 }
	
 }

