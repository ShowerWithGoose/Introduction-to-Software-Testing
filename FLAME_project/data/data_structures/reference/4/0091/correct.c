#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
typedef struct node{
	char word[20];
	int num;
	struct node*link; 
}Node,*Nodeptr;
int main()
{
	char c;
	char temp[20]; //储存当前读入的单词 
	int i;
	int fla1,fla2,k=0;
	Nodeptr list=NULL,p,q,flag,flagleft;
	FILE *in;
	in=fopen("article.txt","r");
	while((c=fgetc(in))!=EOF)
	{
		i=0;
		while(isalpha(c)==0)
		{
		    c=fgetc(in);
		    if(c==EOF)
		    {
		    	k=1;
		    	break;
			}
		}
		if(k==1)
		{
			break;
		}
		while(isalpha(c))
		{
			temp[i]=tolower(c);
			i++;
			c=fgetc(in);
		}
		temp[i]='\0';
		if(list==NULL)
		{
	        list=(Nodeptr)malloc(sizeof(Node));
	        strcpy(list->word,temp);
	        p=list;
	        list->num=1;
	        list->link=NULL;
		}
		else
		{
			fla1=1;   // 1表示插入，0表示加1 
			for(flag=list;flag!=NULL;flag=flag->link)
			{
				if(strcmp(flag->word,temp)==0)
				{
					fla1=0;
					flag->num++;
					break;
				}
			}
			if(fla1)
			{
				fla2=1; //1表示在末尾添加，0表示 在flag前插入 
				for(flag=list;flag!=NULL;flag=flag->link) 
				{
					if(strcmp(flag->word,temp)>0)
					{
						q=(Nodeptr)malloc(sizeof(Node));
						q->link=NULL;
				        strcpy(q->word,temp);
				        q->num=1;
						fla2=0;
						if(flag==list)
						{
							q->link=list;
							list=q;
							break;
						}
						else
						{
							flagleft->link=q;
							q->link=flag;
						    break;
						}	
					}
					flagleft=flag;
				}
				if(fla2)
				{
				    q=(Nodeptr)malloc(sizeof(Node));
				    q->link=NULL;
				    strcpy(q->word,temp);
				    q->num=1;
				    p->link=q;
				    p=q;
				}
				
			}
		}
	}
	for(flag=list;flag!=NULL;flag=flag->link)
	{
		for(i=0;flag->word[i]!='\0';i++)
		{
			printf("%c",flag->word[i]);
		}
		printf(" ");
		printf("%d\n",flag->num);
	}
	fclose(in);
	return 0;
}



