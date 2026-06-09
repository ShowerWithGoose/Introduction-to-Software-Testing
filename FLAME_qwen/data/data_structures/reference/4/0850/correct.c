#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
struct word{
	char wd[99];
	int time;
};
int N=0;//´ÊÊý 
typedef struct word *ptr;
typedef struct word Node;

int getWord(FILE *a,char w[])
{
	int i=0;char c;
	while(fscanf(a,"%c",&c)!=EOF)
	{
		if(c>='A'&&c<='Z')
		c=tolower(c);
		if((c<'a'||c>'z')&&i==0)
		continue;
		if((c<'a'||c>'z')&&i!=0)
		{
			w[i]='\0';return 1;
		}
		if(c<='z'&&c>='a')
		{
			w[i]=c;i++;
		}
	}
	return -1;
}
//int rise(const void *p1,const void *p2)	
	/*int i;
	if(sscanf(a,"%s",w)!=EOF)
	{
		for(i=0;w[i]!='\n';i++)
		{
			w[i]=tolower(w[i]);
		}
		return 1;
	}
	return -1;*/

int searchWord(struct word wordlst[],char *w)
{
	int i;
	if(N==0)
	return -1;
	for(i=0;i<N;i++)
	{
		if(strcmp(w,wordlst[i].wd)==0)
		{
			wordlst[i].time++;return 1;
		}
	}
	return -1;
}
void insertWord(Node wordlst[],char *w)
{
	int i,j;
	if(N==0)
	{
		N++;strcpy(wordlst[0].wd,w);wordlst[0].time=1;
	}
	else{
	
		for(i=0;i<N;i++)
		{
			if(strcmp(w,wordlst[i].wd)<0)
			{
				break;
			}
		}
		N++;
		for(j=N;j>i;j--)
		{
			strcpy(wordlst[j].wd,wordlst[j-1].wd);
			wordlst[j].time=wordlst[j-1].time;
		}
		strcpy(wordlst[i].wd,w);wordlst[i].time=1; 
	}
}


int main()
{
	FILE *in;
	int i;
	char newword[20];
	Node wordlist[100]={0};
	in = fopen("article.txt","r");
	while(getWord(in,newword)!=-1)
	{
		if(searchWord(wordlist,newword)==-1)
		{
			insertWord(wordlist,newword);	
		}
	}
//	qsort(wordlist,N,sizeof(wordlist[0]),rise);
	for(i=0;i<N;i++)
	{
		printf("%s %d\n",wordlist[i].wd,wordlist[i].time);
	}
	return 0;
}



