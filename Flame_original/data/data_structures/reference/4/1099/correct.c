#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<memory.h>
#define MAXWORD  32
#define MAXSIZE  1024
typedef struct node Node;
struct node{
    char word[MAXWORD];
    int cnt;
}Txt[MAXSIZE];

int cmp(const void *p1,const void *p2);
char s[MAXSIZE];
char temp[MAXSIZE];

int main()
{	
	FILE *fp1=fopen("article.txt","r");
    int i=0,j,k,len=0,total=0;	
    char c;
   
    c=fgetc(fp1);
	while(c!=EOF)
	{	
		temp[i]=c;	
		if(isalpha(temp[i])) 
			temp[i]=tolower(temp[i]);
		i++;
		c=fgetc(fp1);
	}

	len=strlen(temp);
   
	for(i=0;i<len;i++)
	{
		if(isalpha(temp[i]))
		{
			for(j=i;j<len;j++)
			{
				if(!isalpha(temp[j]))
				break;
			}
			
			for(k=0;k<j-i;k++)
			{
				s[k]=temp[i+k];
			}
			
			memcpy(Txt[total++].word,s,j-i);
			i=j;
		}
		else continue;
	}
	
	qsort(Txt,total,sizeof(Node),cmp);
	for(i=0;i<total;i++) 
	{
		Txt[i].cnt=1;
	}

	for(i=0;i<total;i++)
	{
		if(strcmp(Txt[i].word,Txt[i+1].word)==0) //ÖØ¸´ 
		{
			Txt[i+1].cnt+=Txt[i].cnt;
			Txt[i].cnt=0;
		}
	}
	qsort(Txt,total,sizeof(Node),cmp);
	for(i=0;i<total;i++)
	{
		if(Txt[i].cnt!=0)	
			printf("%s %d\n",Txt[i].word,Txt[i].cnt);
	}
	
	fclose(fp1);

return 0;
}


int cmp(const void *p1,const void *p2)
{
	Node *q1=(struct node*)p1;
	Node *q2=(struct node*)p2;
	return strcmp(q1->word,q2->word);
}


