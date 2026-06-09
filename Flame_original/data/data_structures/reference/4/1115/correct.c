#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
struct node{
	char a[100];
	int num;
	struct node* link;
}*list=NULL,*p,*q,*m,*n,*t;

void update(char word[100])
{
	int i,j;
	for(i=0;word[i]!=0;i++)
	{
		if(word[i]>='A'&&word[i]<='Z')
		{
			word[i]=word[i]+'a'-'A';
		} else if(word[i]<'a'||word[i]>'z')
		{
			for(j=i;word[j]!=0;j++)
			{
				word[j]=word[j+1];
			}
			i--;
		}
		
	}
}

int main()
{
	FILE *in;
	in=fopen("article.txt","r");
	char word[100]={0};
	int i=0;
	while((word[i]=fgetc(in))!=EOF)
	{
		if(isalpha(word[i]))
		{
			for(i++;i<100;i++)
			{
				if(isalpha(word[i]=fgetc(in))) ;
				else{
					word[i]=0;
					break;
					
				}
			}
		update(word);
		
		
		p=(struct node*)malloc(sizeof(struct node));
		p->link=NULL;
		p->num=1;
		strcpy(p->a,word);
		if(list==NULL)
		{
			list=q=p;
			i=0;
			continue;
			
		}
		for(m=list;m!=NULL;n=m,m=m->link)
		{
			if(strcmp(word,m->a)<0)
			{
				if(m==list)
				{
					list=p;
					list->link=m;
					break;
				}else
				{
					n->link=p;
					p->link=m;
					break;
				}
			}
			if(strcmp(word,m->a)==0)
			{
				m->num++;
				break;
			}
		}
		if(m==NULL)
		{
			n->link=p;
		}
		i=0;
		} else{
			i=0;
			continue;
		}
	}
	for(p=list;p!=NULL;p=p->link)
	{
		printf("%s %d\n",p->a,p->num);
	}
	
}










