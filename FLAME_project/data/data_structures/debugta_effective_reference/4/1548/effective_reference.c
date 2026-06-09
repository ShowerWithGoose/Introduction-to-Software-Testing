#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct node{
	char word[50];
	int times;
	struct node *link;
}data;
FILE *in;
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
	char Word[50];
	data *list=NULL;
	in=fopen("article.txt","r");
	while(getword(Word,in)!=EOF)
	{
		if(strlen(Word)==0)
			continue;
		else
		{
			if(list==NULL)
			{
				list=(data*)malloc(sizeof(data));
				strcpy(list->word,Word);list->times=1;list->link=NULL;
			}
			else
			{
				data *p,*y; 
				for(p=list;p!=NULL;y=p,p=p->link)
				{
					if(strcmp(Word,p->word)==0)
					{
						(p->times)++;
						break;
					}
					else if(strcmp(Word,p->word)<0)
					{
						data *q=(data*)malloc(sizeof(data));
						q->times=1;strcpy(q->word,Word);						
						if(p!=list)
							{q->link=p;y->link=q;}
						else
							{q->link=list;list=q;}
						break;
					}
				}
				if(p==NULL)
				{ 
					data *q=(data*)malloc(sizeof(data));
					q->times=1;strcpy(q->word,Word);
					y->link=q;q->link=NULL;
				}
			}				
		}		
		memset(Word,0,sizeof(Word));			
	}
		for(data *i=list;i!=NULL;i=i->link)
			printf("%s %d\n",i->word,i->times);	
	return 0;	
}

