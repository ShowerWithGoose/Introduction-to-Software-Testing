#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
#define M 1000005
#define ll long long
#define ull unsigned long long
FILE *in;
int i,j,k,o;
char s[2000];
struct node{
	char word[30];
	int sum;
	
}words[2000];
void article(FILE *in);
void setWord();
int cmp(const void*a,const void*b);
int main()
{
	in=fopen("article.txt","r");
	article(in);
//	puts(s);

	setWord();//printf("%d",k);
	qsort(words,k,sizeof(words[0]),cmp);
	for(i=0;i<k;i++)
	{
		if(strcmp(words[i].word,words[i+1].word)==0)
		{
			words[i+1].sum+=words[i].sum;
			words[i].sum=0;
		}
	}
	for(i=0;i<k;i++)
	{
		if(words[i].sum!=0)
		{
		printf("%s %d\n",words[i].word,words[i].sum);
			
		}
	}
	return 0;
}
void setWord()
{	//
	for(i=0;i<strlen(s);i++)
	{
		if(s[i]>='a'&&s[i]<='z')
		{	o=0;
			words[k].word[o]=s[i];
			o++;
			for(j=i+1;;j++)
			{if(s[j]>='a'&&s[j]<='z')
				{
				words[k].word[o]=s[j];
				o++;
				}
			else break;
			}
			i=j;
			words[k].sum=1;
			k++;
		}
	}
}
void article(FILE *in)//读取文字并转换成小写 
{
	char ch;
	i=0;
	while((ch=fgetc(in))!=EOF)
	{
		if(0<=ch&&ch<=127)
		{s[i]=ch;i++;
	
		}
	}
	for(i=0;i<strlen(s);i++)
	{
		if(s[i]>='A'&&s[i]<='Z') s[i]=tolower(s[i]);
		//	printf("%c",s[i]);
	}
}
int cmp(const void*a,const void*b)
{
	struct node*p=(struct node*)a;
	struct node*q=(struct node*)b;	
	if(strcmp(q->word,p->word)>0)
				return -1;
	else if(strcmp(q->word,p->word)<0)
				return 1;
	else return 0;
}

