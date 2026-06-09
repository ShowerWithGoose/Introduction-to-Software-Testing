#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

int main()
{
	typedef struct word{
		char string[20];
		int time;
		struct word *point;
	}violet;
	
	FILE *in;
	if((in=fopen("article.txt","r"))==NULL)
	{
		printf("!!!");
		return 1;
	}
	char line[20],ch;
	violet *head;
	violet *p;
	violet *p1;
	violet *begin;
	head=p=(violet *)malloc(sizeof(violet));
	begin=p1=(violet *)malloc(sizeof(violet));
	p1->point=head;
	head->point=NULL;
	//fscanf(in,"%s",line);
	while(!isalpha(ch=fgetc(in)))
	;
	int zf=0;
	line[zf++]=tolower(ch);
	while(isalpha(ch=fgetc(in)))
	{
		line[zf++]=tolower(ch);
	}
	line[zf]='\0';
	strcpy(p->string,line);
	p->time=1;
	
	while(1)
	{
		int zf=0;
		
		if(ch==EOF) break;
		if(!isalpha(ch))
		{
			while(ch!=EOF&&!isalpha(ch=fgetc(in)))
			;
		}
		if(ch==EOF) break;
		line[zf++]=tolower(ch);
		while(isalpha(ch=fgetc(in)))
		{
			line[zf++]=tolower(ch);
		}
		line[zf]='\0';
		if(ch==EOF) break;
		//printf("%s\n",line);
		p=begin->point;
		p1=begin;
		int flag=0;
		while(strcmp(p->string,line)<0)
		{
			if(p->point!=NULL)
			{
				p=p->point;
				p1=p1->point;
			}
			else{
				p->point=(violet *)malloc(sizeof(violet));
				p->point->point=NULL;
				p->point->time=1;
				strcpy(p->point->string,line);
				flag=1;
				break;
			}
		}
		if(!flag)
		{
		
			if(!strcmp(p->string,line))
			{
				p->time++;
			}
			else 
			{
				p1->point=(violet *)malloc(sizeof(violet));
				strcpy(p1->point->string,line);
				p1->point->time=1;
				p1->point->point=p;
			}
			
		}
		
	}
	p=begin->point;
	if(p==NULL)
		return 0;
	while(p->point!=NULL)
	{
		printf("%s %d\n",p->string,p->time);
		p=p->point;
	}
	printf("%s %d\n",p->string,p->time);	
	
	
	return 0;
}

