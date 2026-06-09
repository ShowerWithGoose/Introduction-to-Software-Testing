#include<stdio.h>
#include<string.h> 
struct shujv
{
	char word[100];
	int n;
}num[10000000],m2;
char c[10000000];
int main()
{
    FILE *in;
    in=fopen("article.txt","r");
    int i=0,j=0,k=0,wordnum=0,mark=0;
    char len;
    len=fgetc(in);
    while(len!=EOF)
    {
    	if(tolower(len)<='z'&&tolower(len)>='a')
    	{
    		c[i]=tolower(len);
    		i++;
		}
		else
		{
			if(strlen(c)!=0)
			{
				for(j=0;j<wordnum;j++)
				{
					if(strcmp(c,num[j].word)==0)
					{
						num[j].n++;
						mark=1;
					}
				}
				if(mark==0)
				{
					strcpy(num[j].word,c);
					num[j].n=1;
					wordnum++;
				}
				mark=0;
				for(j=0;j<i;j++)
				{
					c[j]=0;
				}	
		        i=0;
			}
		}
		len=fgetc(in);
	}
	for(i=0;i<wordnum-1;i++)
	{
		for(k=i+1;k<wordnum;k++)
		{
			if(strcmp(num[i].word,num[k].word)>0)
			{
				m2=num[i];
				num[i]=num[k];
				num[k]=m2;
			}
		}
	}
	for(i=0;i<wordnum;i++)
	{
		printf("%s %d\n",num[i].word,num[i].n);
	}
	return 0;
}


