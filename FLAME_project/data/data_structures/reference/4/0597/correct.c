#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define MAXWORD 32
#define MAXSIZE 1024
struct inode{
	char word[MAXWORD];
	int num;
} wordlist[MAXSIZE],wordlist1[MAXSIZE];
int searchword(char search[],char now[]);
void swap(int *a,int *b); 
int N=0,p[10000],flag=0;
char s[102400];
int main()
{
	int i,j,k,r=0,t=0,nub=0,y;
	char c;
	char get[MAXWORD];
	FILE *in;
	in=fopen("article.txt","r");
	while((c=fgetc(in))!=EOF)
	{
		if(c>='a'&&c<='z')
		{
			t++;
			s[t]=c;
		}
		else if(c>='A'&&c<='Z')
		{
			t++;
			s[t]=c-'A'+'a';
		}
		else
		{
			t++;
			s[t]=' ';
		}
	}
	s[0]=' ';
	for(k=0;k<=t;k++)
	{
		if(s[k]==' '&&s[k+1]<='z'&&s[k+1]>='a')
		{
			wordlist1[nub].word[r]='\0';
			r=0;
			nub++;
		}
		else if(s[k]==' ')
		continue;
		else
			wordlist1[nub].word[r++]=s[k];
	}
	for(i=1;i<=nub;i++)
	{
		y=0;
		if(i==1)
		{
		    N++;
			for(k=0;wordlist1[i].word[k]!='\0';k++)
			wordlist[1].word[y++]=wordlist1[i].word[k];
			wordlist[1].word[y]='\0';
			wordlist[1].num++;
		}
		else
		{
			flag=0;
			for(j=1;j<=N;j++)
			{
				if((searchword(wordlist1[i].word,wordlist[j].word))==1)
				{
				  wordlist[j].num++;
				  flag=1;
				  break;
				}
			}
		    if(flag==0)
		    {
		         	N++;
					for(k=0;wordlist1[i].word[k]!='\0';k++)
			        wordlist[N].word[y++]=wordlist1[i].word[k];
			        wordlist[N].word[y]='\0';
			        wordlist[N].num++;
			}
		}
    }      
	for(i=1;i<=N;i++)
	p[i]=i;
	for(i=1;i<=N;i++)
	{
		for(j=i;j<=N;j++)
		swap(&p[i],&p[j]);
	}
	fclose(in);
	for(i=1;i<=N;i++)
	{
		if(i!=N) 
		printf("%s %d\n",wordlist[p[i]].word,wordlist[p[i]].num);	
		else
		printf("%s %d",wordlist[p[i]].word,wordlist[p[i]].num);	
	}
	
}
int searchword(char search[],char now[])
{
	int i,j,k;
    for(i=0,j=0;search[i]==now[j]&&(search[i]!='\0'&&now[j]!='\0');i++,j++)
    ;
    if(search[i]=='\0'&&now[j]=='\0')
    return 1;
    else
    return -1;
}
void swap(int *a,int *b)
{
	int i,j,k,tmp;
	for(i=0;wordlist[*a].word[i]!='\0'||wordlist[*b].word[i]!='\0';i++)
	{
		if(wordlist[*a].word[i]>wordlist[*b].word[i])
		{
			tmp=*a;
			*a=*b;
			*b=tmp;
			break;
		}
		else if(wordlist[*a].word[i]==wordlist[*b].word[i])
		continue;
		else
		break;
	}
	if(wordlist[*b].word[i]=='\0')
	{
			tmp=*a;
			*a=*b;
			*b=tmp;
	}
}

