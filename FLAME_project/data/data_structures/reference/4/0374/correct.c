#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAXWORD 32
#define MAXSIZE 1024

struct sum 
{
	char word[MAXWORD];
	int num;
}wordlist[MAXSIZE];
int N=0; //单词表中单词的实际个数

int get(FILE *in, char *a)
{
	char c=fgetc(in);
	while(isalpha(c)==0) 
	{ 
		if(c == EOF) return c; 
		else 
		{
			c=fgetc(in);
			continue;
		}
	}
	do 
	{
		*a++ = tolower(c);
	} 
	while(isalpha(c=fgetc(in))); 
		*a='\0';
	return 1;
}
int insert(struct sum list[ ], int j, char *a)
{
	int i;
	for(i=N-1; i>=j; i--)
	{
		strcpy(list[i+1].word, list[i].word);
		list[i+1].num = list[i].num;
	}
	strcpy(list[j].word, a);
	list[j].num = 1;
	N++;
	return 1;
}
int search(struct sum list[ ], char *a){
	int low=0, high=N-1, mid=0;
	while(low <= high)
	{
		mid = (high + low) / 2;
		if(strcmp(a, list[mid].word)<0)
			high = mid -1;
		else if(strcmp(a, list[mid].word)>0)
			low = mid + 1;
		else 
		{ 
			list[mid].num++;
			return 0;
		} 
	}
	return insert(list, low, a);
}

int main()
{
	int i;
	char word[MAXWORD];
	FILE *in;
	in = fopen("article.txt", "r");
	while(get(in,word) != EOF)
	search(wordlist, word);
	for(i=0; i<= N-1; i++)
		printf("%s %d\n", wordlist[i].word, wordlist[i].num);
	return 0;
}



