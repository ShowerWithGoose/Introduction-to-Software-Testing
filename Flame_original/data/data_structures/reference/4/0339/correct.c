#include<stdio.h>
#include<string.h>
#include<ctype.h>

struct words{
	char word[2000];
	int times;
}article[2000];

char tmp[2000];
char s[2000];

int cmp(const void *p1,const void *p2)
{
	struct words *a=(struct words*)p1;
	struct words *b=(struct words*)p2;
	return strcmp(a->word,b->word);
}

int main()
{
	int h=0,i=0,j=0,flag=0,g=0;
	FILE *in;
	in=fopen("article.txt","r");
	while(fgets(s,2000,in)!=NULL)
	{
		for(i=0;i<=strlen(s);i++)
		{
			flag=0;
			s[i]=tolower(s[i]);
			if(s[i]<='z'&&s[i]>='a')
			{
				tmp[g]=s[i];
				g++;
			}
			else if(s[i]>'z'||s[i]<'a')
			{
				g=0;
				if(s[i-1]<='z'&&s[i-1]>='a'&&i!=0)
				{
					for(h=0;h<j;h++)
					{
						if(strcmp(tmp,article[h].word)==0)
						{
							article[h].times++;
							memset(tmp,0,sizeof(tmp));
							flag=1;
							break;
						}
						else continue;
					}
					if(flag==0)
					{
						strcpy(article[j].word,tmp);
						article[j].times++;
						j++;
						memset(tmp,0,sizeof(tmp));
					}
				}
				else continue;
			}
		}
	}
	qsort(article,j,sizeof(struct words),cmp);
	for(i=0;i<j;i++)
	{
		printf("%s %d\n",article[i].word,article[i].times);
	}
	fclose(in);
	return 0;
}

