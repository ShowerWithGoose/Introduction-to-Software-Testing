#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdio.h>

struct word_num{
	char word[100];
	int num;
} putout[10000];
char wordlist[10000][100];
int rank[10000]={0}; 

int cmp(const void *a,const void *b)
{
	int aa=*((int *)a),bb=*((int * )b);
	return strcmp(wordlist[aa],wordlist[bb]);
}

int main (void)
{
	char temp[100]={'\0'},tempc;
	int i=0,j=0,total,flag=0;
	FILE *pf=fopen("article.txt","r");
	while((tempc=fgetc(pf))!=EOF)
	{
		if(tempc>='A'&&tempc<='Z')
		{
			temp[i]=tempc+'a'-'A';
			i++;
		}
		else if(tempc>='a'&&tempc<='z')
		{
			temp[i]=tempc;
			i++;			
		}
		else if((!(tempc>='A'&&tempc<='Z'))&&(!(tempc>='a'&&tempc<='z'))&&i!=0)
		{
			strcpy(wordlist[j],temp);
			memset(temp,0,i);
			i=0;
			j++;
		}
	}
	fclose(pf);
	total=j;
	for(i=0;i<total;i++)	
		rank[i]=i;
		
//	for(i=0;i<total;i++)
//		printf("%s\n",wordlist[rank[i]]);	
	qsort(rank,total,sizeof(int),cmp);
//	for(i=0;i<total;i++)
//		printf("%s\n",wordlist[rank[i]]);
			
	j=0;
	putout[0].num=1;
	strcpy(putout[0].word,wordlist[rank[0]]);	
	for(i=0;i<total;i++)
	{
		if(i==total-1&&total>=2)
		{
			if(strcmp(wordlist[rank[i]],wordlist[rank[i-1]])==0)
			{
				printf("%s %d",putout[j].word,putout[j].num);
			}
			else
			{
				printf("%s 1",wordlist[rank[i]]);
			}	
			return 0;
		}
		if(total==1)
		{
			printf("%s 1",wordlist[0]);
			return 0;
		}
		if(strcmp(wordlist[rank[i]],wordlist[rank[i+1]])==0)
		{
			putout[j].num++;
		}
		else
		{
			printf("%s %d\n",putout[j].word,putout[j].num);
			j++;
			strcpy(putout[j].word,wordlist[rank[i+1]]);
			putout[j].num=1;
		}
	}

	return 0;
}

