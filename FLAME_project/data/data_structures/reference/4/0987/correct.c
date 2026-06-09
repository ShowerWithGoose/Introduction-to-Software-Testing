#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char s[100],x[100],m[100];

struct str{
	char word[100];
	int num;
}joke[100];

int cmp(const void*a,const void*b)
{
	struct str*aa=(struct str*)a;
	struct str*bb=(struct str*)b;
	return strcmp((aa->word),(bb->word));
}

int flag(int u)
{
	for(int kl=0;kl<u;kl++)
	{
		if(strcmp(joke[kl].word,x)==0)
		{
			joke[kl].num++;
			return 1;
		}
	}
	return 0;
}

int main()
{
	FILE*in;
	in=fopen("article.txt","r");
	int u=1,mo=0,kj=0;
	
	while(fgets(s,100,in)){
		char c;
		for(int ko=0;ko<strlen(s);ko++)
		{
			c=s[ko];
			if(c>='A'&&c<='Z')
			{
				x[kj++]=c-'A'+'a';
			}
			else if(c>='a'&&c<='z')
			{
				x[kj++]=c;	
			}else{
				x[kj++]='\0';
				if(flag(u)==0)
				{
					for(int i=0;i<strlen(x);i++)
					{
						joke[u].word[i]=x[i];
					}
					u++;
				}
				memset(x,0,sizeof(x));
				kj=0;
			}
		}
		memset(s,0,sizeof(s));
	}
	
	qsort(joke,u,sizeof(joke[0]),cmp);
	for(int l=1;l<u;l++)
	{
		printf("%s %d\n",joke[l].word,joke[l].num+1);
	}
	
	return 0;
 } 

