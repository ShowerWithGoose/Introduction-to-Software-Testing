#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define maxn 200
#define maxall 1000
FILE *in;
typedef struct
{
	char word[maxn];
	int times;
}char_times;
char_times words[maxall];
int i; 
char tmp[maxn];
void clean(char s[])
{
	int l=strlen(s);
	int i;
	for(i=1;i<=l;i++)
		s[i-1]='\0';
}
int input()
{
	in=fopen("article.txt","r");
	int d;
	char c;
	int r=0,t=0;
	//int delta=1;
	while(1)
	{
		r=1;
		clean(tmp);
		while(1)
		{
			c=fgetc(in);
			if(c==EOF)
				return i;
			if((c>='a'&&c<='z')||(c>='A'&&c<='Z'))
				break;
		}
		tmp[0]=c;
		
		while(1)
		{
			c=fgetc(in);
			//printf("%c",c);
			if((c>='a'&&c<='z')||(c>='A'&&c<='Z'))
			{
				tmp[r]=c;
				r++;
			}
			else
				break;
		}
		t=0;
		//puts(tmp);
		for(r=0;r<=strlen(tmp)-1;r++)
		{
			if(tmp[r]>='A'&&tmp[r]<='Z')
			{
				words[i].word[t]=(tmp[r]-'A')+'a';
				t++;
			}
			else if(tmp[r]>='a'&&tmp[r]<='z')
			{
				words[i].word[t]=tmp[r];
				t++;
			}
		}
		
		words[i].times=1;
		//d=strlen(words[i].word)-1;
		for(r=0;r<i;r++)
		{
			if(strcmp(words[r].word,words[i].word)==0)
			{
				words[r].times++;
				words[i].times=0;
				clean(words[i].word);
				i--;				
				break;
			}
		}
		//puts(tmp);
		i++;
	}
	//return i;
}
int compare(const void *a,const void *b)
{
	char_times m=*((char_times *)a);
	char_times n=*((char_times *)b);
	int r=0;
	while(1)
	{
		if(m.word[r]<n.word[r])
			return -1;
		else if(m.word[r]>n.word[r])
			return 1;
		r++;
	}
}
int main()
{
	int d,r;
	d=input();
	qsort(words,d,sizeof(words[0]),compare);
	for(r=1;r<=d;r++)
		printf("%s %d\n",words[r-1].word,words[r-1].times);
	return 0;
}

