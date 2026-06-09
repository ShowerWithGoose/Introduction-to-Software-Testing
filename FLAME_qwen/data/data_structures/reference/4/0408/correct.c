#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLINE 1024
struct node{
	char word[20];
	int cnt;
}article[1000],temp;
int main()
{
	FILE *in;
	in=fopen("article.txt","r");
	char ch,word[25]="";
	int i=0,j,len=0,flag=0;
	while((ch=fgetc(in))!=EOF)
	{
		if((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z'))//大小写转换 
		{
			word[i++]=tolower(ch);
		}
		else//读入完一个单词 
		{
			if(strcmp(word,"\0")!=0)//不是末尾 
			{
				for(j=0;j<len;j++)//查找 
				{
					if(strcmp(word,article[j].word)==0)
					{
						article[j].cnt++;
						flag=1;
						break;
					}
					else flag=0;
			    }
				if(!flag)//若没有，放入表中 
				{
					strcpy(article[j].word,word);
					len++;
					article[j].cnt=1;
				}
				memset(word,0,sizeof(word));	
			}
			i=0;
		}
	}
	//bubblesort
    for(i=0;i<len;i++)
    {
    	for(j=0;j<len-i-1;j++)
    	{
    		if(strcmp(article[j].word,article[j+1].word)>0)
    		{
    			temp=article[j];
    			article[j]=article[j+1];
    			article[j+1]=temp;
			}
		}
	}
		
	for(i=0;i<len;i++)
    {
        printf("%s %d\n",article[i].word,article[i].cnt);
    }	
		
	fclose(in);	
		
		
		
		
		
		
		
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}



