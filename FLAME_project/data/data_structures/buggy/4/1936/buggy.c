#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <ctype.h> 
struct link{
	char word[100];   
	int count; 
};
int main()
{
	struct link biao[1000];
	char ch;
	int flag=0,flag1=0,k1=0,k2=0;
	FILE*in;
	in=fopen("article.txt","r");
	while((ch=fgetc(in))!=EOF)
	{
		if((tolower(ch)<='z'&&tolower(ch)>='a'))
		{
			flag1=1;
			biao[k1].word[k2]=tolower(ch); 
			biao[k1].count =1;
			flag=0;
			k2++;
		}
		else if(~(tolower(ch)<='z'&&tolower(ch)>='a')&&flag1==1)
		{
			flag++;
			if(flag==1)
			{
				k1++;
			}
			k2=0;
		}
	}
	char str[100];
	for(int i=0;i<k1-1;i++)
	{
		for(int j=0;j<k1-i-1;j++)
		{
			if(strcmp(biao[j].word ,biao[j+1].word )>0)
			{
				for(int k=0;k<100;k++)
				{
					str[k]=biao[j].word[k];
				}
				for(int k=0;k<100;k++)
				{
					biao[j].word[k]=biao[j+1].word[k];
				}
				for(int k=0;k<100;k++)
				{
					biao[j+1].word[k]=str[k];
				}
			}
		}
	}
	int s=0;
	for(int i=1;i<k1;i++)
	{
		for(int j=0;j<i;j++)
		{
			for(int k=0;k<100;k++)
			{
				if(biao[i].word[k]==biao[j].word[k])
				{
					s++;
				}
			}
			if(s==100)
			{
				biao[j].count++; 
				biao[i].count =0;
				break;
			}
			s=0;
		}
	}
	
	for(int i=0;i<k1;i++)
	{
		if(biao[i].count!=0 )
		{
			printf("%s %d\n",biao[i].word ,biao[i].count );
		}
	}
	fclose(in);
}




















































