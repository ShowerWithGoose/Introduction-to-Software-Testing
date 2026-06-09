#include<stdio.h>
#include<ctype.h>
#include<string.h>
typedef struct
{
	char infor[20];
	int cnt;
}word;
int count(word txt[],int wordsnum)
{
	int i=1,j=1;
	for(i=1;i<=wordsnum;i++)
	{
		for(j=i+1;j<=wordsnum;j++)
		{
			if(strcmp(txt[i].infor,txt[j].infor)==0)
			{
				txt[i].cnt++;
				txt[j].infor[0]='\0';
			}
		}
	}
}
void sort(word txt[],int wordsnum)
{
	int i=1,j=1;
	for(i=1;i<=wordsnum;i++)
	{
		
		for(j=1;j<=wordsnum-i;j++)
		{
			if(strcmp(txt[j].infor,txt[j+1].infor)>0)
			{
				word tmp=txt[j];
				txt[j]=txt[j+1];
				txt[j+1]=tmp;
			}
		}
	}
}
int main()
{
	FILE *in=fopen("article.txt","r");
	char cntxt[10000];
	int i=1,j=0;
	int wordsnum=1;
	char ch=fgetc(in);
	word txt[500];
	for(i=0;i<500;i++)
	{
		txt[i].cnt=1;
	}
	i=1;
	while(ch!=EOF)
	{
		if(isalpha(ch))
		{
			ch=tolower(ch);
			txt[i].infor[j]=ch;
			j++;
		}
		else
		{
			txt[i].infor[j]='\0';
			i++;
			j=0;
			wordsnum++;
		}
		ch=fgetc(in);
	}
    count(txt,wordsnum);
    sort(txt,wordsnum);
    for(i=1;i<=wordsnum;i++)
    {
    	if(txt[i].infor[0]!='\0')
    	{
    		printf("%s %d\n",txt[i].infor,txt[i].cnt);
		}
	}
	return 0;
}
