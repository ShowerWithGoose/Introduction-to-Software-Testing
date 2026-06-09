#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define N 60
#include<stdlib.h>
struct stru{
	char word[20];
	int fre;
}list[600]; 
int main()
{
	FILE *f1=fopen("article.txt","r");
	char ch,tmp[20]={'\0'},str[10000]={'\0'};
	int i=0,cnt=0,j,k;
	for(i=0;i<=600;i++)
	{
		list[i].fre=0;
	}
	ch=fgetc(f1);
	for(i=0;ch!=EOF;i++)
	{
		str[i]=tolower(ch);
		ch=fgetc(f1);
	}
	int n=strlen(str);
	i=0;
	for(k=0;k<n;k++)
	{
		if(str[k]>='a'&&str[k]<='z')
		{
		tmp[i]=str[k];i++;
		}
		else if((str[k]<='a'||str[k]>='z')&&tmp[0]!='\0')
		{
			for(j=0;j<=cnt;j++)
			{
				if(strcmp(tmp,list[j].word)==0)
				{
				list[j].fre++;
				i=0;
				memset(tmp,'\0',sizeof(tmp));
				break;
				}
				else if(j==cnt)
				{
					cnt++;
					strcpy(list[j].word,tmp);
					i=0;
					memset(tmp,'\0',sizeof(tmp));
				}
			 } 
		}
		
	}
		for(i = 0; i < cnt ; i++)//Ã°ÅÝÅÅÐò 
		for(j = 0; j < cnt-i; j++)
			if(strcmp(list[j].word,list[j+1].word)>0)
			{	
				char hold[60]={'\0'};
				int ex;
			    memset(hold,'\0',N)	;
				strcpy(hold,list[j].word);
				memset(list[j].word,'\0',sizeof(list[j].word));
				strcpy(list[j].word,list[j+1].word);
				memset(list[j+1].word,'\0',sizeof(list[j+1].word));
				strcpy(list[j+1].word,hold);
				ex = list[j].fre;
				list[j].fre = list[j + 1].fre;
				list[j + 1].fre = ex;
			}
			for(i = 1; i <=cnt ; i++)
			{
				if(strlen(list[i].word)==1)
				list[i].fre++;
				printf("%s %d\n",list[i].word,list[i].fre);
			}
			return 0;
}



