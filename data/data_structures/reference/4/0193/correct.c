#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
typedef struct node{
	char word[1024];
	int count;
}Node;
int getword(FILE *in,char *w);
int search(Node list[],char *w);
int charu(Node list[],int pos,char *w); 
int N=0;

int main()
{
	Node wordlist[1024];
	int i;
	char words[1024];
	FILE *fp;
	fp=fopen("article.txt","r");
	while(getword(fp,words)!=EOF)
	{
		if(search(wordlist,words)==-1) return 0;
	 } 
	for(i=0;i<N;i++)
	{
		printf("%s %d\n",wordlist[i].word,wordlist[i].count);
	}
	return 0;
 } 
 
 int getword(FILE *in,char *w)
 {
 	int c;
 	while(isalpha(c=fgetc(in))==0)
 	{
 		if(c==EOF) return c;
 		else continue;
	 }
	do
	{
		*w++=tolower(c);
	}while(isalpha(c=fgetc(in)));
	*w='\0';
	return 1;
 }
 
 int charu(Node list[],int pos,char *w)
{
	int i;
	if(N==1024)
	return -1;
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
 
int search(Node list[],char *w)
{
	int low=0,high=N-1,mid=0;
	int result;
	while(low<=high)
	{
		mid=(low+high)/2;
		if(strcmp(w,list[mid].word)<0)
		{
		high=mid-1; 
	}
	else if(strcmp(w,list[mid].word)>0)
	{
		low=mid+1;
	}
	else if(strcmp(w,list[mid].word)==0)
	{
		list[mid].count++;
		return 0;
	}
}
	result=charu(list,low,w);
	return result;
}

