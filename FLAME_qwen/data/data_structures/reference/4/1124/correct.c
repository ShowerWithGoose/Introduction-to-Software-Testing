#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
typedef struct Word
{
	int cnt;
	char s[15];
	struct Word *pNext;
}NODE,*PNODE;
void insert(PNODE pHead,int cnt,char s[]);
int main()
{
	FILE *in;
	in=fopen("article.txt","r");
	PNODE pHead=(PNODE)malloc(sizeof(NODE));
	pHead->pNext =NULL; 
	if(pHead==NULL)
	{
		printf("·ÖÅäÄÚ´æÊ§°Ü");
		exit(-1); 
	}
	char c=fgetc(in);
	while(c!=EOF)
	{
		char word[15]={0};
		if((c>='a'&&c<='z')||(c>='A'&&c<='Z'))
		{
			if(c>='A'&&c<='Z')
			c+=32;
			word[0]=c;
			int i;
			for(i=1;i<15;i++)
			{
				c=fgetc(in);
				if((c>='A'&&c<='Z'))
				c+=32;
				if(c<'A'||c>'z'||(c>'Z'&&c<'a'))
				{
					insert(pHead,1,word); 
					break;
				}
				word[i]=c;
			}
		}
		c=fgetc(in);
	}
	PNODE p=pHead->pNext ;
	while(p!=NULL)
	{
		printf("%s %d\n",p->s ,p->cnt );
		p=p->pNext;
	}
	fclose(in);
	return 0;
}
void insert (PNODE pHead,int cnt,char s[])
{
	PNODE p=pHead;
	while(p->pNext!=NULL&&strcmp(s,p->pNext->s)>0)
	{
		p=p->pNext ;	
	}
	if(p->pNext==NULL)
	{
		PNODE P=(PNODE)malloc(sizeof(NODE));
		strcpy(P->s,s);
		P->cnt =1;
		p->pNext =P;
		P->pNext =NULL;
	}
	else if(strcmp(s,p->pNext->s)==0)
	{
		p->pNext->cnt ++;
	}
	else if(strcmp(s,p->pNext->s)<0)
	{
		PNODE q=p->pNext ;
		PNODE pNew=(PNODE)malloc(sizeof(NODE));
		pNew->cnt =1;
		strcpy(pNew->s,s);
		p->pNext =pNew;
		pNew->pNext = q; 
	}
}

