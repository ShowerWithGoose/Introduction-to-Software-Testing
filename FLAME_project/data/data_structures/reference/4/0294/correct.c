#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct dictionary
{
	char word[50];
	int times;
	struct dictionary *pNext;
}*dic,DIC;
void clean(char ch[],int len)
{
	int i;
	for(i=0;i<len;i++)
	{
		ch[i]='\0';
	}
}
int main()
{
	FILE *fi=fopen("article.txt","r");
	char word[50]={},word2[1000]={'\0'},word1[50]={'\0'},*pw;
	int flag,i=0,j,k,m;
	dic pfirst=(dic)malloc(sizeof(DIC)),p=pfirst,p2,p3,p4;
	strcpy(p->word,"\0");
	p->times=0;
	p->pNext=NULL;
	p2=p;
	while(fgets(word2,1000,fi)!=NULL)
	{	
		m=strlen(word2);
		for(i=0;i<m;i++)
		{
			if(word2[i]>='A'&&word2[i]<='Z')
			{
				word2[i]+='a'-'A';
			}
			if((word2[i]<'a'||word2[i]>'z')&&word2[i]!='\0')
			{
				word2[i]=' ';
			}
		}
		for(i=m-1;i>=0;i--)
		{
			if(word2[i]!=' ')
			{
				word2[i+1]='\0';
				break;
			}
		} 
		m=strlen(word2);
		for(i=0,j=0;i<m;i++)
		{
			if(word2[i]==' ')
			{
				if(word2[i+1]==' ')
				{
					for(j=i+1;j<m+1;j++)
					{
						word2[j-1]=word2[j];
					}
					i--;
				}
			}
		}
		pw=word2;
		while(sscanf(pw,"%s",word)!=EOF)
		{
			flag=0;
			for(p=pfirst,p3=p;p!=NULL;p3=p,p=p->pNext)
			{
				if(strcmp(p->word,word)==0)
				{
					p->times++;
					flag=1;
				}
			}
			if(flag==0)
			{
				p2=(dic)malloc(sizeof(DIC));
				strcpy(p2->word,word);
				p2->times=1;
				p3->pNext=p2;
				p2->pNext=NULL;
			}
			if(pw-word2+strlen(word)<strlen(word2))
			{
				pw+=strlen(word)+1;
			}
			else
			{
				break;
			} 
		}
		clean(word2,m+1);
	}
	p=pfirst->pNext;
	free(pfirst);
	pfirst=p;
	for(p=pfirst;p->pNext!=NULL;p=p->pNext)
	{
		p3=NULL;
		strcpy(word,p->word);
		for(p2=p;p2!=NULL;p2=p2->pNext)
		{
			if(strcmp(word,p2->word)>0)
			{
				p3=p2;
				strcpy(word,p2->word);
			}
		}
		if(p3!=NULL)
		{
			flag=p->times;
			p->times=p3->times;
			p3->times=flag;
			strcpy(word,p->word);
			strcpy(p->word,p3->word);
			strcpy(p3->word,word);
		}
	}
	for(p=pfirst;p!=NULL;p=p->pNext)
	{
		printf("%s %d\n",p->word,p->times);
	}
	fclose(fi);
	for(p=pfirst;p!=NULL;)
	{
		p2=p;
		p=p->pNext;
		free(p2);
	}
	return 0;
} 


















