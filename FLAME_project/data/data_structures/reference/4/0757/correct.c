#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char words[1000][1024];
int n,i,j=0;
int times[10000];
char ch;
int comp(const void*p1,const void*p2)
{
    return strcmp((char*)p1,(char*)p2);
}
int main()
{
	FILE *in;
	in=fopen("article.txt","r");
	ch=fgetc(in);
	while(ch!=EOF)
	{
		if(ch>='a'&&ch<='z')//Ð¡Ð´×ÖÄ¸»òÕßÊý×Ö 
		{
			words[n][i]=ch;
			i++;
		}
		else if(ch>='A'&&ch<='Z')//´óÐ´×ÖÄ¸
		{
			words[n][i]=ch+32;
			i++; 
		}
		else//·ûºÅ 
		{
			words[n][i]='\0';
			i=0;
			n++; 
		}
		ch=fgetc(in);
	}
	qsort(words,n,sizeof(words[0]),comp);
	for(i=0;i<n;i++)
	{
		if(words[i][0]!='\0')
		{
			times[i]++;
			for(j=1;i+j<n;j++)
			{
				if(strcmp(words[i],words[i+j])==0)
				{
					words[i+j][0]='\0';
					times[i]++;
				}
			}
		}
    }
    for(i=0;i<n;i++)
    {
    	if(times[i]>0)
    	printf("%s %d\n",words[i],times[i]);
	}
	
	
}



