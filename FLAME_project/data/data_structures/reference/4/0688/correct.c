#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
typedef struct Word{
	char content[50];
	int count;
	struct Word* next;
}*word;
word newword()
{
	word p;
	p=malloc(sizeof(struct Word));
	p->count=0;
	p->next=NULL;
	return p;
}
word insert(word k,char* a)
{
	int lp=0;
	word n;
	n=k;
	if(n->next==NULL)
	{
		n->next=newword();
		for(lp=0;a[lp]!='\0';lp++)
		{
			n->next->content[lp]=a[lp];
		}
		n->next->content[lp]='\0';
		n->next->count=1;
		
	}
	else
	{
		while(1)
		{
			n=n->next;
			if(strcmp(n->content,a)<0)
			{
				if(n->next==NULL)
				{
					n->next=newword();
					for(lp=0;a[lp]!='\0';lp++)
					{
						n->next->content[lp]=a[lp];
					}
					n->next->content[lp]='\0';
					n->next->count=1;
					break;
				}
			}
			else if(strcmp(n->content,a)==0)
			{
				n->count++;
				break;
			}
			else
			{
				word q;
				q=newword();
				for(lp=0;a[lp]!='\0';lp++)
				{
					q->content[lp]=a[lp];
				}
				q->content[lp]='\0';
				q->count=1;
				q->next=n;
				word p;
				p=k;
				while(p->next!=n)
				{
					p=p->next;
				}
				p->next=q;
				break;
			}
		}
	}
	return k;
}
void pr(word a)
{
	a=a->next;
	while(a->next!=NULL)
	{
		printf("%s %d\n",a->content,a->count);
		a=a->next;
	}
	printf("%s %d\n",a->content,a->count);	
}

int main()
{
    FILE * IN;
	char huancun[50];
	int length=0;
    IN=fopen("article.txt","r");
    char ip;
    word cptj;
    cptj=newword();
    int lp;
    cptj->content[0]='a'-1;
    cptj->content[1]='\0';
    while(fscanf(IN,"%c",&ip))
	{
		if(feof(IN))
		break;
		if(isalpha(ip))
		{
			if(isupper(ip))
			{
				ip+=32;
			}
			huancun[length]=ip;
			length++;
		}
		else
		{
			if(length>0)
			{
				huancun[length]='\0';
				insert(cptj,huancun);
			}
			for(lp=0;lp<length;lp++)
			{
				huancun[lp]=0;
			}
			length=0;
		}
	}
    pr(cptj);
    fclose(IN);
    return 0;
} 

