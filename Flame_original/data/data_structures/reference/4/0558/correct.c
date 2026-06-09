#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define maxword 500
struct wordlist{
	char word[maxword];
	int count;
}wordlist[102],tem;
int main()
{
char word[maxword],temp;
int i,j,k,len;
FILE *in,*out;
in=fopen("article.txt","r");
while(fscanf(in,"%c",&temp)!=EOF)
{
	
	if(temp>=65&&temp<=90||temp>=97&&temp<=122){
		j=0;
		if(temp>=65&&temp<=90)
		{
			word[j]=temp+32;
			j++;
		}
		if(temp>=97&&temp<=122)
		{
			word[j]=temp;
			j++;
		}
		
	while(fscanf(in,"%c",&temp)!=EOF&&(temp>=65&&temp<=90||temp>=97&&temp<=122))
	{
		
		if(temp>=65&&temp<=90)
		{
			word[j]=temp+32;
			j++;
		}
		if(temp>=97&&temp<=122)
		{
			word[j]=temp;
			j++;
		}
	}
	
	for(i=0;i<102;i++)
	{
		if(wordlist[i].count==0)
		{
			strcpy(wordlist[i].word,word);
			wordlist[i].count++;
			break;
		}
		if(strcmp(word,wordlist[i].word)==0)
		{
			wordlist[i].count++;
			break;
		}
	}
	memset(word,0,sizeof(char)*500);
	

	}	}
	for(i=0;i<102;i++)
	{
		for(j=i+1;j<102;j++)
		{
			if(strcmp(wordlist[i].word,wordlist[j].word)>0)
			{
				tem=wordlist[j];
				wordlist[j]=wordlist[i];
				wordlist[i]=tem;
				
			}
		}
	}
		for(i=0;i<102;i++)
	{
		if(wordlist[i].count!=0&&wordlist[i].word[0]!='\0')
		printf("%s %d",wordlist[i].word,wordlist[i].count);
		if(wordlist[i].count!=0&&wordlist[i+1].count!=0)
		printf("\n");
	}
		
	return 0;
}

