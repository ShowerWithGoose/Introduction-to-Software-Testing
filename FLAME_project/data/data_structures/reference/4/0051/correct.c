//3_5
#include <stdio.h>
#include <string.h>

struct words
{
	char word[50];
	int times;
};

int main(int argc, char const *argv[])
{
	freopen("article.txt","r",stdin);
	char ca[50],c;
	struct words wd[10000];
	int p=0,flag=0,sum=0;
	c=getchar();
	while(c!=EOF)
	{
		if(c>='A'&&c<='Z') c+=' ';
		if(c>='a'&&c<='z') ca[p++]=c,flag=1;
		else
		{
			if(flag)
			{
				ca[p]='\0';
				int fl=0;
				for(int i=0;i<sum;i++) if(!strcmp(wd[i].word,ca)) wd[i].times++,fl=1;
				if(fl)
				{
					flag=0;
					p=0;
					c=getchar();
					continue;
				}
				strcpy(wd[sum].word,ca);
				wd[sum].times=1;
				sum++;
				p=0;
				flag=0;
			}
		}
		c=getchar();
	}
	for(int i=0;i<sum-1;i++)
	{
		for(int j=0;j<sum-1-i;j++)
		{
			if(strcmp(wd[j].word,wd[j+1].word)>0)
			{
				struct words tmp;
				tmp=wd[j];
				wd[j]=wd[j+1];
				wd[j+1]=tmp;
			}
			
		}
	}
	for(int i=0;i<sum;i++) printf("%s %d\n",wd[i].word,wd[i].times);
	return 0;
}
