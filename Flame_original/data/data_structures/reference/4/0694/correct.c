#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct node{
	char word[50];
	int times;
	struct node *link;
}data;
FILE *article;
int getword(char string[],FILE *file)
{
	int c,i=0;
	while((c=fgetc(file))!=EOF)
	{
		if(c>='a'&&c<='z')
		string[i++]=c;
		else if(c>='A'&&c<='Z')
			string[i++]=c-'A'+'a';
		else
		{
			if(strlen(string)!=0)
				string[i]='\0';
			return 0;			
		}		 
	}
	return -1;
}
int main()
{
	char WORD[50];
	data *list=NULL;
	article=fopen("article.txt","r");
	while(getword(WORD,article)!=EOF)
	{
		if(strlen(WORD)==0)
			continue;
		else
		{
			if(list==NULL)
			{
				list=(data*)malloc(sizeof(data));
				strcpy(list->word,WORD);list->times=1;list->link=NULL;
			}
			else
			{
				data *p,*p0; 
				for(p=list;p!=NULL;p0=p,p=p->link)
				{
					if(strcmp(WORD,p->word)==0)
					{
						(p->times)++;
						break;
					}
					else if(strcmp(WORD,p->word)<0)
					{
						data *q=(data*)malloc(sizeof(data));
						q->times=1;strcpy(q->word,WORD);						
						if(p!=list)
							{q->link=p;p0->link=q;}
						else
							{q->link=list;list=q;}
						break;
					}
				}
				if(p==NULL)
				{ 
					data *q=(data*)malloc(sizeof(data));
					q->times=1;strcpy(q->word,WORD);
					p0->link=q;q->link=NULL;
				}
			}				
		}		
		memset(WORD,0,sizeof(WORD));			
	}
		for(data *i=list;i!=NULL;i=i->link)
			printf("%s %d\n",i->word,i->times);	
	return 0;	
}

