#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
char words[100005][10005];
int wordCnt=0;
int cmp(const void* a,const void* b)
{
	return strcmp((char*)a,(char*)b);
}
int main(void)
{
	FILE* in=fopen("article.txt","r");
	// char oneWord[10005];
	// while(~fscanf(in,"%s",oneWord))
	// {
	// 	int oneWordLen=0;
	// 	for(int i=0;i<strlen(oneWord);i++)
	// 	{
	// 		if(isalpha(oneWord[i]))
	// 		{
				
	// 			words[wordCnt][oneWordLen++]=tolower(oneWord[i]);
	// 		}
			
	// 	}
	// 	if(strlen(words[wordCnt])!=0)
	// 	{
	// 		wordCnt++;
	// 	}
	// }
	char ch;
	
	int len=0;
	while((ch=fgetc(in))!=EOF)
	{
		if(isalpha(ch))
		{
			ch=tolower(ch);
			
			if(len==0)
			{
				words[wordCnt++][0]=ch;
				len=1;
			}
			else
			{
				words[wordCnt-1][len++]=ch;
			}
		}
		else
		{
			
			len=0;
		}


	}
	qsort(words,wordCnt,sizeof(words[0]),cmp);
	int countSame=0;
	char out[10005]={'\0'};
	for(int i=0;i<wordCnt;i++)
	{
		if(countSame==0)
		{
			strcpy(out,words[i]);
			countSame=1;
		}
		else
		{
			if(strcmp(out,words[i])==0&&i!=wordCnt-1)
			{
				countSame++;
			}
			else 
			{
				if(i==wordCnt-1&&strcmp(out,words[i])==0)
				{
					countSame++;
				}
				else if(i==wordCnt-1&&strcmp(out,words[i])!=0)
				{
					printf("%s %d\n",out,countSame);
					
					printf("%s 1\n",words[i]);
					return 0;
				}
				printf("%s %d\n",out,countSame);
				countSame=1;
				strcpy(out,words[i]);
			}
		}
	}
	return 0;
}
