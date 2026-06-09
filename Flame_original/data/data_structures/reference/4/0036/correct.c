#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define MAXWORD 10
#define MAXSIZE 100
struct node{
	char word[MAXWORD];
	int count;
};
int N=0;
int i;
struct node wordlist[MAXSIZE];
char word[MAXWORD];
FILE *bfp;
int main(){
    if((bfp=fopen("article.txt","r"))!=NULL)
    {
	while(getword(bfp,word)!=EOF)
			if(searchword(wordlist,word)!=-1)
                continue;
    }
	for(i=0;i<=N-1;i++)
		printf("%s %d\n",wordlist[i].word,wordlist[i].count);
	return 0;
}
int getword(FILE *fp,char *w)
{
	int c;
	while(!isalpha(c=fgetc(fp)))
    {
		if(c==EOF) return -1;
	    else continue;
	}

	do
    {
		*w++=tolower(c);
	}while(isalpha(c=fgetc(fp)));
	*w='\0';
	return 1;
}


int searchword(struct node list[],char *w)
{
    int low=0,high=N-1,mid=0;
    while(low<=high)
    {
    	mid=(high+low)/2;
    	if(strcmp(w,list[mid].word)<0)
    	    high=mid-1;
        else if(strcmp(w,list[mid].word)>0)
            low=mid+1;
        else
        {
        	list[mid].count++;
        	return 0;
		}
	}
		return insertword(list,low,w);
}
int insertword(struct node list[],int pos,char *w)
{
	int i;
	for(i=N-1;i>=pos;i--)
    {
		strcpy(list[i+1].word,list[i].word);
		list[i+1].count=list[i].count;
	}
	strcpy(list[pos].word,w);
	list[pos].count=1;
	N++;
	return 1;
}






