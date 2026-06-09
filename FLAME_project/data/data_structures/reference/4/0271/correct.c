#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>
struct Word{
	char wordlist[100];
	int cnt;
}word[1000]; 
int cmp(const void *a,const void *b)
{
	struct Word *c=(struct Word *)a;
	struct Word *d=(struct Word *)b;
	return strcmp(c->wordlist,d->wordlist);
}
int getWord(FILE *fp,char *w)
{
	int c;
	while(!isalpha(c=fgetc(fp)))
	{
		if(c==EOF) return c;
		else continue;
	}
	do{
		*w++=tolower(c);
	}while(isalpha(c=fgetc(fp)));
	*w='\0';
	return 1;
}
int n=0;
int searchWord(struct Word word[],char *w)
{
	int low=0,high=n-1,mid=0;
	while(low<=high)
	{
		mid=(low+high)/2;
		if(strcmp(w,word[mid].wordlist)<0)
		{
			high=mid-1;
		}
		else if(strcmp(w,word[mid].wordlist)>0)
		{
			low=mid+1;
		}
		else 
		{
			word[mid].cnt++;
			return 0;
		}
	}
	strcpy(word[n++].wordlist,w);
}

int main()
{
	int i;
	FILE *fp=fopen("article.txt","r");
	char fword[1000];
	while(getWord(fp,fword)!=EOF)
	{
		searchWord(word,fword);
		qsort(word,n,sizeof(word[0]),cmp);
	}
	for(i=0;i<n;i++)
	{
		printf("%s %d\n",word[i].wordlist,word[i].cnt+1);
	}
	return 0;
}



