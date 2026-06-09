#include<stdio.h>
#include<string.h>
#include<ctype.h>
struct node{
	char word[10000];
	int cnt;
}wordlist[1000],a;


int main()
{
	char check[1000],ch;
	int i=0,m=0,k=0,j=0,flag=0;
	FILE*in=fopen("article.txt","r");
	ch=fgetc(in);
	while(ch!=EOF)
	{
		if(isalpha(ch))
		{
			wordlist[i].word[j]=ch;
			j++;
			flag=1; 
		}//是字母就读入并存入Word里 
		else if(flag!=0)
		{
			wordlist[i].word[j]='\0';
			wordlist[i].cnt=1;
			j=0;
			i++; 
			flag=0;
		}//flag=0说明不是字母，那之前的字母就是一个单词。这一位赋为\0 

		ch=fgetc(in);		
	}


	int wordnum=i;//此时的i为所有的单词个数 
	for(i=0;i<wordnum;i++)
	{
		for(j=0;j<strlen(wordlist[i].word);j++)
		{
			if(wordlist[i].word[j]>='A'&&wordlist[i].word[j]<='Z')
				wordlist[i].word[j]=tolower(wordlist[i].word[j]);
		}
	}//大写变小写 
	
	for(i=0;i<wordnum;i++)
	{
		for(j=i+1;j<wordnum;j++)
		{
			if(strcmp(wordlist[i].word,wordlist[j].word)==0)
			{
				strcpy(wordlist[j].word,"\0");
				wordlist[i].cnt=wordlist[i].cnt+wordlist[j].cnt;
			}
			if(strcmp(wordlist[i].word,wordlist[j].word)>0)
			{
				a=wordlist[i];
				wordlist[i]=wordlist[j];
				wordlist[j]=a;
			}
		}
	}//按字典序排序 


	for(i=0;i<wordnum;i++)
	{
		if(strlen(wordlist[i].word)!=0)
			printf("%s %d\n",wordlist[i].word,wordlist[i].cnt);
	}
	
	return 0;
}

