#include<stdio.h>
#include<string.h>
#include<ctype.h>
struct lnode{
	char word[20];
	int num;
};
int N=0;
int getword(FILE *fp,char *letter);
int search(struct lnode list[],char *word);
int main()
{
	struct lnode wordlist[50];
	int i;
	char word[20];
	FILE *ffp=fopen("article.txt","r");
	while(~getword(ffp,word))
	{
		if(search(wordlist,word)==-1)
		{
		}
	}
	for(i=0;i<=N-1;i++)
	{
		printf("%s %d\n",wordlist[i].word,wordlist[i].num);
	}
	return 0;
}
int getword(FILE *fp,char *letter)
{
	int w;
	while(!isalpha(w=fgetc(fp)))
	{
		if(w==EOF)
		{
			return w;
		}
		else
		{
			continue;
		}
	}
	do{
		*letter=tolower(w);
		letter++;
	}while(isalpha(w=fgetc(fp)));
	*letter='\0';
	return 1;
}
int search(struct lnode list[],char *word)
{
	int low=0,high=N-1,mid=0,i;
	while(low<=high)
	{
		mid=(high+low)/2;
		if(strcmp(word,list[mid].word)==0)
		{
			list[mid].num++;
			return 0;
		}
		else if(strcmp(word,list[mid].word)<0)
		{
			high=mid-1;
		}
		else
		{
			low=mid+1;
		}
	}
	for(i=N-1;i>=low;i--)
	{
		strcpy(list[i+1].word,list[i].word);
		list[i+1].num=list[i].num;
	}
	strcpy(list[low].word,word);
	list[low].num=1;
	N++;
	return 1;
}

