#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
typedef struct Word
{
	int num;
	char word[15];
	struct Word *pNext;
}NODE,*PNODE;
void insert(PNODE pHead,int num,char word[]);
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
	char pf=fgetc(in);
	while(pf!=EOF)
	{
		char word[15]={0};
		if((pf>='a'&&pf<='z')||(pf>='A'&&pf<='Z'))
		{
			if(pf>='A'&&pf<='Z')
			pf+=32;
			word[0]=pf;
			int i;
			for(i=1;i<15;i++)
			{
				pf=fgetc(in);
				if((pf>='A'&&pf<='Z'))
				pf+=32;
				if(pf<'A'||pf>'z'||(pf>'Z'&&pf<'a'))
				{
					insert(pHead,1,word); 
					break;
				}
				word[i]=pf;
			}
		}
		pf=fgetc(in);
	}
	PNODE p=pHead->pNext ;
	while(p!=NULL)
	{
		printf("%s %d\n",p->word ,p->num );
		p=p->pNext;
	}
	fclose(in);
	return 0;
}
void insert (PNODE pHead,int num,char word[])
{
	PNODE p=pHead;
	while(p->pNext!=NULL&&strcmp(word,p->pNext->word)>0)
	{
		p=p->pNext ;	
	}
	if(p->pNext==NULL)
	{
		PNODE P=(PNODE)malloc(sizeof(NODE));
		strcpy(P->word,word);
		P->num =1;
		p->pNext =P;
		P->pNext =NULL;
	}
	else if(strcmp(word,p->pNext->word)==0)
	{
		p->pNext->num ++;
	}
	else if(strcmp(word,p->pNext->word)<0)
	{
		PNODE q=p->pNext ;
		PNODE pNew=(PNODE)malloc(sizeof(NODE));
		pNew->num =1;
		strcpy(pNew->word,word);
		p->pNext =pNew;
		pNew->pNext = q; 
	}
}

