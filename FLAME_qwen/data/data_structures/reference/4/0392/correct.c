#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct {
	char word[15];
	int con;
}Word;
Word words[1000];
char real(char c)
{
	if(c>='A'&&c<='Z')
	{
		c=c-'A'+'a';
	}
	return c;
}
int search(Word *p,char *a,int n)
{
	int i=0;
	for(i=0;i<n;i++)
	{
		if(strcmp(p[i].word,a)==0)
		return i;
	}
	return -1;
}
int f_sort(const void *a,const void *b)
{
	int i=0;
	while(1)
	{
		if((*(Word*)a).word[i]!=(*(Word*)b).word[i])
		return (*(Word*)a).word[i]-(*(Word*)b).word[i];
		else
		i++;
	}
	return 0;
}
int main()
{
	
	FILE *in;
	in=fopen("article.txt","r");
	int i=0,j,n=0;
	char Buf[10]={0},c,zero[10]={0};
	do{
		c=fgetc(in);
		if(real(c)>='a'&&real(c)<='z')
		{
			Buf[i]=real(c);
			i++;
		}
		else if(i>0)
		{
			if(search(words,Buf,n)==-1)
			{
				strcpy(words[n].word,Buf);
				words[n].con=1;
				n++;
			}
			else
			{
				words[search(words,Buf,n)].con++;
			}
			memset(Buf,0,strlen(Buf));
			i=0;
		}
	}while(c!=EOF);
	qsort(words,n,sizeof(Word),f_sort);
	for(j=0;j<=n;j++)
	{
		if(strlen(words[j].word)>0)
		printf("%s %d\n",words[j].word,words[j].con);
	}
	fclose(in);
}

