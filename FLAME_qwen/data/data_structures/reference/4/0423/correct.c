#include<stdio.h>
#include<ctype.h>
#include<string.h>

struct DATA
{
	int times;
	char *Word;
};
struct DATA WORD[1000];

int i,j,k,flag=1;
int sign;//判断是否有单词输入
char letter;
char word[1000][15];

int main()
{
	FILE *in;
	in=fopen("article.txt","r");
	
	while((letter=fgetc(in))!=EOF)
	{
		if(isalpha(letter))
		{
			letter=tolower(letter);
			word[i][j++]=letter;
			sign=1;
		}
		else if(!(isalpha(letter))&&sign)
		{
			j=sign=0;
			for(k=i-1;k>=0;k--)
			{
				//如果重复，标志位清零，该词词频++，这个输入的word清零
				if(strcmp(word[i],word[k])==0)
				{
					flag=0;
					WORD[k].times++;
					memset(word[i],0,15);
					break;
				}
			}
			if(flag==0)
			{
				flag=1;
				continue;
			}
			else
			{
				WORD[i].Word=word[i];
				WORD[i].times=1;
				i++;
			}
		}
		else
		{
			continue;
		}
	}
	
	//来排序
	for(k=0;k<i-1;k++)
	{
		char *min=WORD[k].Word;
		int sign1=k;
		
		for(j=k+1;j<i;j++)
		{
			if(strcmp(min,WORD[j].Word)>0)
			{
				min=WORD[j].Word;
				sign1=j;
			}
		}
		
		struct DATA tmp;
		tmp=WORD[k];
		WORD[k]=WORD[sign1];
		WORD[sign1]=tmp;
	}
	
	for(k=0;k<i;k++)
	{
		printf("%s %d\n",WORD[k].Word,WORD[k].times);
	}
	fclose(in);
	return 0;
}
