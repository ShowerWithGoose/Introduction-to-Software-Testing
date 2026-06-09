#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#define ll long long
#define ull unsigned long long
typedef struct vocabulary{
	char word[25];
	int cnt;
}voca;
voca res[205],temp;

char article[2005];
/*
int cmp(const void*p1,const void*p2)
{
	voca *a = (voca*)p1;
	voca *b = (voca*)p2;
	return (a->word)-(b->word);
}
*/
void sort(voca res[],int num)
{
	for(int i=0;i<num;i++)
	{
		for(int j=(i+1);j<num;j++)
		{
			if(strcmp(res[i].word,res[j].word) > 0)
			{
				temp=res[i];
				res[i]=res[j];
				res[j]=temp;
			}
		}
	}
}

int main()
{
	int artlen=0,num=0;
	char ch;
	//char *p,*q;
	FILE *in;
	in = fopen("article.txt","r");
	
	do{
		ch = fgetc(in);
		article[artlen++] = ch;
	}while(ch != EOF);
	
	for(int i=0;i<artlen;i++)
	{
		if(article[i]>='A' && article[i]<='Z')
		{
			article[i] = tolower(article[i]);
		}
	}
	int k=0,j=0;
	for(int i=0;i<artlen;i++)
	{
		//p=q=&article[i];
		if(article[i]>='a' && article[i]<='z')
		{
			res[num].word[k++]=article[i];
			for(j=(i+1);j<artlen;j++)
			{
				if(article[j]>='a' && article[j]<='z')
				{
					res[num].word[k++] = article[j];
				}
				else
				{
					break;
				}
			}
			res[num].word[k]='\0';
			res[num].cnt++;
			num++;
			k=0;
			i=j;
		}	
	}
	
	for(int i=0;i<num;i++)
	{
		for(j=(i+1);j<num;j++)
		{
			if(!strcmp(res[i].word,res[j].word))
			{
				res[i].cnt++;
				res[j].word[0]='\0';
			}
		}
	}
	
	//qsort(res,num,sizeof(voca),cmp);
	sort(res,num);
	
	for(int i=0;i<num;i++)
	{
		if(res[i].word[0] == '\0')
		{
			continue;
		}
		else
		{
			printf("%s %d\n",res[i].word,res[i].cnt);
		}
	}
	
	fclose(in);
	return 0;
}



