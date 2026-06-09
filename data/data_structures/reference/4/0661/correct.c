/* 本次作业由本人独立实现完成，如有抄袭行为，愿承担由此带来的一切不良后果 */
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

typedef struct node
{
	char word[20];
	int ans;
	struct node *link;
}Node,*Link;

char s[10000],*p=NULL,store[20];
int flag,flag1;
Link list=NULL,r=NULL,q,t;

int main()
{
	FILE *in,*out;
	in=fopen("article.txt","r");
	out=fopen("art.txt","w");
	
	while(fgets(s,9999,in)!=NULL)
	{
		
		int i=0;
		p=s;
		
		while(*p!='\0')
		{
			while(!isalpha(*p)&&*p!='\0')
			{
				p++;
			} 
		
			i=0;
			while(isalpha(*p)&&p!='\0')
			{
				store[i++]=(*p>='A'&&*p<='Z')?*p-'A'+'a':*p;
				p++;
			}
		
			while(!isalpha(*p)&&*p!='\0')
			{
				p++;
			}
			
			store[i]='\0';
			
			q=(Link)malloc(sizeof(Node));
			strcpy(q->word,store);
			q->ans=1;
			
			if(list==NULL)
			{
				list=q;
				//puts(list->word); 
				list->link=NULL;
				r=list;
				//printf("list=%s %d\n\n",list->word,list->ans);
			}

			//puts(list->word);

			else
			{
				t=list;
				while(t!=NULL)
				{
					if(isalpha(q->word[0])&&strcmp(q->word,list->word)<0)
					{
						q->link=list;
						//printf("q=%s %d\n\n",q->word,q->ans);
						list=q;
						//printf("list=%s %d\n\n",list->word,list->ans);
						break;
					}
					
					else if(strcmp(q->word,t->word)==0)
					{
						t->ans++;
						free(q);
						break;
					}
					
					else if(strcmp(q->word,t->word)>0&&t->link==NULL)
					{
						r=list;
						while(r->link!=NULL)
							r=r->link;
						r->link=q;
						r=r->link;
						r->link=NULL;
						break;
					}
					
					else if(strcmp(q->word,t->word)>0&&strcmp(q->word,t->link->word)<0)
					{
						q->link=t->link;
						t->link=q;
						break;
					}
					t=t->link;
				}
			}
		}
	}
	t=list;
	while(t!=NULL)
	{
		printf("%s %d\n",t->word,t->ans);
		t=t->link;
	}
	
	fclose(in); 
	fclose(out);
	
	Link poi;
	t=list,poi=list->link;
	while(poi!=NULL)
	{
		free(t);
		t=poi;
		poi=poi->link;
	}
	free(t);
	return 0;
}

