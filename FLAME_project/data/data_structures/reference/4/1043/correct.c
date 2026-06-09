#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#define ll long long
#define ull unsigned long long
#define MAXLINE 1024
struct  article
{
	char name[20];
	int num;
}word[100];
int main()
{
	char line[100];
	FILE *in;
	char tmp[100];
	int m=0,n=0,k,i,j,a,t;
	in=fopen("article.txt","r");
	while(fgets(line,MAXLINE-1,in)!=NULL)
	{
		t=strlen(line);
		for(i=0;i<t;i++)
		{
			if(line[i]>='A'&&line[i]<='Z')
					{
						line[i]=line[i]+32;
					}//printf("%c",line[i]);
					if(line[i]>='a'&&line[i]<='z')
					{
						word[m].name[n]=line[i];
						word[m].num=1;
						n++;
					}
		else
		{
			n=0;
			for(k=0;k<m;k++)
			{
				if(strcmp(word[m].name,word[k].name)==0)
				{
					word[k].num++;
					strcpy(word[m].name,"\0");
				}
			}
			m++;
		}
		}
	/*for(i=0;i<m;i++)
	{
		printf("%s %d\n",word[i].name,word[i].num);
	}*/
	}
	for(i=0;i<m;i++)
	{
		for(j=i+1;j<m;j++)
		{
			if(strcmp(word[i].name,word[j].name)>0)
			{
				strcpy(tmp,word[i].name);
				strcpy(word[i].name,word[j].name);
				strcpy(word[j].name,tmp);
				a=word[i].num;
				word[i].num=word[j].num;
				word[j].num=a;
			}
		}
	}
	for(i=0;i<m;i++)
	{
		if(strlen(word[i].name)!=0)
		{
			printf("%s %d\n",word[i].name,word[i].num);
		}
	}
    return 0;
}

